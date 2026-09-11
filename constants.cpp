#include<iostream>
#define PI 3.1415265

using namespace std;

double area(double radius){

    return PI * (radius * radius);
}

int main(){

    double radius;

    cout<<"Enter the radius ";
    cin>>radius;

    cout<<"The area is: "<<area(radius);
}
