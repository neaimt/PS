#include <iostream>
#include <algorithm>
using namespace std;
long long arr[91];
int N;
void Fibo(int n) {
    if ( n == N+1 )
        return;
    
    if ( n == 0 )
        arr[n]= 0;

    else if ( n == 1 || n == 2 )
        arr[n] = 1;

    else 
        arr[n] = arr[n-1] + arr[n-2];
    
    Fibo(n+1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    Fibo(0);
    cout << arr[N];
}