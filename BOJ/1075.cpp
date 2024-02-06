#include <iostream>
#include <algorithm>
using namespace std;
int N, F;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> F;
    N = N - N % 100;

    for ( int i = N;; i++ ) {
        if ( i % F == 0 ) {
            if ( i % 100 < 10 )
                cout << 0;
            
            cout << i % 100;
            break;
        }
    }
}