#include<bits/stdc++.h>

using namespace std;

int power(int x, int n){
    // Base case
    if(n==0) return 1;

    // Recursive 
    int smallOutput = power(x, n-1);
    // calculation
    return x * smallOutput;
}

int main(){

    cout<<power(5,3)<<endl;
    return 0;
}

