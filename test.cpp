class student {
private:
    string name;
public:
    int id;
    // constructer
    student() {}
    student(int _id, string _name) {
        id = _id, name = _name;
    }
    // method
    string getName() {return name;}
    int getId() {return id;}
};
