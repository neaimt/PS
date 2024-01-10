#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if ( N % 2 != 0 )
        cout << "SK";
    else 
        cout << "CY";
}