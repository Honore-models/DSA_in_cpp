#include<iostream>
#define numberOfDistrict 30

using namespace std;

namespace userDefined{
    int insideNamespace = 100;

    int cout(){
        return insideNamespace;
    }
}

int myGlobal = 200;

int cout(){
    return myGlobal * myGlobal;
}

int main(){

    int cout = 300;

    std::cout<<"The local variable cout in main is "<<cout<<endl;
    std::cout<<"The variable in userDefined namespace is "<<userDefined::insideNamespace<<endl;
    std::cout<<"The output of cout() in userDefined is "<<userDefined::cout()<<endl;
    std::cout<<"The value of myGlobal is "<<::myGlobal<<endl;
    std::cout<<"The output of global cout() is "<<::cout()<<endl;

}


