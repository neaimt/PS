#include <iostream>
#include <algorithm>
using namespace std;
long long T, s, n, q, p;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for ( int i = 0; i < T; i++ ) {
        cin >> s;
        cin >> n;
        for ( int j = 0; j < n; j++ ) {
            cin >> p >> q;
            s += (p * q);
        }
        cout << s << '\n';
    }
}