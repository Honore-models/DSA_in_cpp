#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    int age;
    int year;
    string gender;
    string fname;
    string lname;
    string funFact;

    cout<<"Enter your first and last names: ";
    cin>>fname>>lname;

    cout<<"Enter your age: ";
    cin>>age;

    cout << "Enter your birth year: ";
    cin >> year;

    cout << "Your gender: ";
    cin>>gender;

    cout<<"Enter a fun fact on you: ";
    cin.ignore();
    getline(cin,funFact);

    cout <<fname<<" "<<lname<<" you are "<<gender<<" and you were born in " <<year<<" you are "<<age<<" years old"<<endl;
    cout <<"Fun fact: "<<funFact;
    // << insertion operator >> extraction operator

    return 0;
}
