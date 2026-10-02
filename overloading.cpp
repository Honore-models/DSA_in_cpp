#include<iostream>

using namespace std;

int addition (int a, int b){
    return a + b;
}

double addition (double a, double b){
    return a + b;
}

float addition (float a, float b){
    return a + b;
}

string addition (string a, string b){
    return a + b;
}

int main(){

    cout<<"Adding two integers: "<<addition(10, 20)<<endl;
    cout<<"Adding two doubles: "<<addition(5.6, 2.9)<<endl;
    cout<<"Adding two float: "<<addition(10.4f, 20.7f)<<endl;
    cout<<"Adding two strings: "<<addition("Hello", "World")<<endl;

    return 0;
}