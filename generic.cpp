#include<iostream>

using namespace std;

template<typename T>

T addition( T a, T b){
    return a + b;
}

int main(){

    cout<<"Adding two integers: "<<addition<int>(10, 20)<<endl;
    cout<<"Adding two doubles: "<<addition<double>(5.6, 2.9)<<endl;
    cout<<"Adding two float: "<<addition<float>(10.4f, 20.7f)<<endl;
    cout<<"Adding two strings: "<<addition<string>("Hello", "World")<<endl;

    return 0;
}
