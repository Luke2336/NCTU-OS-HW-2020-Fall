#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "page_table_driver.h"

int fd;

// Obtain my cr3 value (a.k.a. PML4 table physical address)
uint64_t get_cr3_value()
{
	struct ioctl_arg cmd;
	int ret;
	cmd.request[0] = IO_CR3;
	ret = ioctl(fd, IOCTL_REQUEST, &cmd);
	return cmd.ret;
}

// Given a physical address, return the value
uint64_t read_physical_address(uint64_t physical_address)
{
	struct ioctl_arg cmd;
	int ret;
	cmd.request[0] = IO_READ;
	cmd.request[1] = physical_address;
	ret = ioctl(fd, IOCTL_REQUEST, &cmd);
	return cmd.ret;
}


// Write value to a physical address
void write_physical_address(uint64_t physical_address, uint64_t value)
{
	struct ioctl_arg cmd;
	int ret;
	cmd.request[0] = IO_WRITE;
	cmd.request[1] = physical_address;
	cmd.request[2] = value;
	ret = ioctl(fd, IOCTL_REQUEST, &cmd);
}

// my functions------------------------------------------
uint64_t get_entry(uint64_t x, int shift) {
	return (x >> shift) & 0x1ffllu;
}
uint64_t get_addr(uint64_t addr, uint64_t id) {
	return (addr & 0xffffffffff000llu) | (id << 3);
}
uint64_t get_pt_addr(uint64_t vir_addr)
{
	uint64_t cr3 = get_cr3_value();
	uint64_t id_pml4 = get_entry(vir_addr, 39);
	uint64_t id_pdpt = get_entry(vir_addr, 30);
	uint64_t id_pd = get_entry(vir_addr, 21);
	uint64_t id_pt = get_entry(vir_addr, 12);
	uint64_t addr_pml4 = get_addr(cr3, id_pml4);
	uint64_t cont_pml4 = read_physical_address(addr_pml4);
	uint64_t addr_pdpt = get_addr(cont_pml4, id_pdpt);
	uint64_t cont_pdpt = read_physical_address(addr_pdpt);
	uint64_t addr_pd = get_addr(cont_pdpt, id_pd);
	uint64_t cont_pd = read_physical_address(addr_pd);
	uint64_t addr_pt = get_addr(cont_pd, id_pt);
	return addr_pt;
}
// -------------------------------------------------------

int main()
{
	char *x = (char*)aligned_alloc(4096, 4096) + 0x123;
	char *y = (char*)aligned_alloc(4096, 4096) + 0x123;
	strcpy(x, "This is a simple HW.");
	strcpy(y, "You have to modify my page table.");

	fd = open("/dev/os", O_RDONLY);
	if(fd < 0) 
	{
		printf("Cannot open device!\n");
		return 0;
	}

	printf("Before\n");
	printf("x : %s\n", x);
	printf("y : %s\n", y);

	/* TODO 1 */
	// ------------------------------------------------
	// Modify page table entry of y
	// Let y point to x's physical address
	uint64_t addr_x = get_pt_addr((uint64_t)x);
	uint64_t addr_y = get_pt_addr((uint64_t)y);
	uint64_t cont_x = read_physical_address(addr_x);
	uint64_t cont_y = read_physical_address(addr_y);
	write_physical_address(addr_y, cont_x);
	//------------------------------------------------

	getchar();

	printf("After modifying page table\n");
	printf("x : %s\n", x);
	printf("y : %s\n", y);

	getchar();

	strcpy(y, "When you modify y, x is modified actually.");
	printf("After modifying string y\n");
	printf("x : %s\n", x);
	printf("y : %s\n", y);

	/* TODO 2 */
	// ------------------------------------------------
	// Recover page table entry of y
	// Let y point to its original address
	// You may need to store y's original address at previous step
	write_physical_address(addr_y, cont_y);
	// ------------------------------------------------

	getchar();

	printf("After recovering page table of y\n");
	printf("x : %s\n", x);
	printf("y : %s\n", y);

	close(fd);
}
