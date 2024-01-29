#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, T, x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for ( long long k = 0; k < T; k++ ) {
        cin >> a >> b;

        x = 1;
        for ( int i = 1; i <= a && i <= b; i++ )
            if ( a % i == 0 && b % i == 0 )
                x = i;
                
        cout << a*b/x << '\n';
    }
}