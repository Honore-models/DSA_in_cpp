#include<iostream>

using namespace std;

class Student{

    private: 
        int code;
        string name;
        string school;

    public:
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


        int set_code(int cd) {
            code = cd; 
        }
        int get_code() {
            return code; 
        }
        string set_name(string nm) {
            name = nm;
        }
        string get_name() {
            return name;
        }
        string set_school(string scl) {
            school = scl;
        }
        string get_school() {
            return school;
        }
};

int main(){

    Student S1(101, "John Doe", "RCA");

    S1.display();

    Student S2;

    S2.set_code(103);
    S2.set_name("Jane Smith");
    S2.set_school("RCA");
    S2.display();

    Student S3(104, "Alice Johnson", "RCA");
    S3.display();

    Student * S4 = new Student(105, "Bob Brown", "RCA");
    S4->display();

    Student S5{106, "Charlie Davis", "RCA"};
    S5.display();


    return 0;
}