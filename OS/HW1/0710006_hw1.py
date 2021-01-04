import time
import itertools
import hashlib
import requests
from bs4 import BeautifulSoup
from multiprocessing import Pool
import threading
import asyncio

query = []
ch = [chr(i) for i in range(33, 127)]

def getInput():
    workload = int(input(""))
    L = [int(x) for x in input("").split()] + [0]
    return workload, L[0], L[1], int(input(""))

def WebTitle(url):
    r = requests.get(url)
    while r.status_code != requests.codes.ok:
        r = requests.get(url)
    soup = BeautifulSoup(r.text, 'html.parser')
    print(soup.find('title').text)

def checkSHA(s):
    sha = hashlib.sha256()
    sha.update(s.encode('utf-8'))
    code = sha.hexdigest()
    return code[0:5] == '00000'

def PoW(s):
    for i1, i2, i3, i4, i5 in itertools.product(ch, ch, ch, ch ,ch):
        tmp = i1 + i2 + i3 + i4 + i5 + s
        if checkSHA(tmp):
            print(tmp)
            return

def work(L, R, func):
    for taskId in range(L, R):
        func(query[taskId])

async def coroutine(func, s):
    await loop.run_in_executor(None, func, s)

if __name__ == '__main__':
    workload, taskMethod, numMulti, numTask = getInput()
    for i in range(numTask):
        query.append(input(""))
    timeStart = time.time()
    func = PoW if workload == 1 else WebTitle
    if taskMethod == 1: # Multithread
        threads = []
        for i in range(numMulti):
            numThreadTask = (numTask // numMulti + 1)
            taskL = numThreadTask * i
            taskR = min(numTask, taskL + numThreadTask)
            threads.append(threading.Thread(target = work, args = (taskL, taskR, func,)))
            threads[i].start();
        for thd in threads:
            thd.join()
    elif taskMethod == 2: # Multiprocess
        with Pool(numMulti) as pool:
            pool.map(func, query)
            pool.close()
            pool.join()
    elif taskMethod == 3: # Coroutine
        tasks = []
        loop = asyncio.get_event_loop()
        for qry in query:
            tasks.append(loop.create_task(coroutine(func, qry)))
            loop.run_until_complete(asyncio.wait(tasks))
    timeEnd = time.time()
    print("Run time: {}.".format(timeEnd - timeStart))
