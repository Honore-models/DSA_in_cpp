#include<iostream>

using namespace std;

class Student{

    public: int code;
    public: string name;
    public: string school;

    Student(int cd, string nm, string scl){
        code = cd;
        name = nm;
        school = scl;
    }

    void display(){
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "School: " << school << endl;
    }

    Student(){}
};

int main(){

    Student S1(101, "John Doe", "RCA");

    S1.display();

    Student S2;

    S2.code = 103;
    S2.name = "Jane Smith";
    S2.school = "RCA"; 
    S2.display();

    Student S3(104, "Alice Johnson", "RCA");
    S3.display();

    Student * S4 = new Student(105, "Bob Brown", "RCA");
    S4->display();

    Student S5{106, "Charlie Davis", "RCA"};
    S5.display();


    return 0;
}

// A structure is like a cpp class where members are public by default. It is used to group different data types together.
// In C++, structures can have member functions, constructors, and destructors, similar to classes. The main difference 
//between a class and a structure is that the default access specifier for members of a class is private, while for a structure it is public.