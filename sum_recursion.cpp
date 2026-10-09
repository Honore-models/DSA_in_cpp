#include <iostream>
using namespace std;

int sum(int n) {
    if (n <= 0) return 0;      // base case
    return n + sum(n - 1);     // recursive case
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Sum of 1 to " << n << " = " << sum(n) << endl;
    return 0;
}
