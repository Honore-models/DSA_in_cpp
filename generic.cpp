#include<iostream>

using namespace std;

template<typename T, typename K>

K addition( T a, K b){
    return a + b;
}

int main(){

    // cout<<"Adding two integers: "<<addition<int>(10, 20)<<endl;
    // cout<<"Adding two doubles: "<<addition<double>(5.6, 2.9)<<endl;
    // cout<<"Adding two float: "<<addition<float>(10.4f, 20.7f)<<endl;
    // cout<<"Adding two strings: "<<addition<string>("Hello", "World")<<endl;
    cout<<"Adding an integer and a double: "<<addition<int, double>(10, 20.3)<<endl;

    return 0;
}
