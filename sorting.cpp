#include<iostream>

using namespace std;

int value = 100;

namespace mySpace{
    int value = 25;
}

int main(){

    // :: scope resolution operator
    // Name spaces are used to organize variables to avoid naming conflicts

    double value = 20.15;

    cout<<value<<endl;
    cout<<::value<<endl;
    cout<<mySpace::value<<endl;


}
