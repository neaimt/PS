#include <iostream>
using namespace std;
long long X, N, money, n, sum;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X;
    cin >> N;
    for ( int i = 0; i < N; i++ ) {
        cin >> money >> n;
        sum += money*n;
    }

    if ( sum == X )
        cout << "Yes";
    else 
        cout << "No";
}