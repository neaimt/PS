#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, d[12];
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for ( int i = 4; i < 11; i++ )
        d[i] = d[i-1] + d[i-2] + d[i-3];

    cin >> t;
    for( int i = 0; i < t; i++ ) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}

// D[i]는 1, 2, 3의 합으로 나타내는 방법의 수
// D[1] = 1
// D[2] = 2 / 1+1, 2
// D[3] = 4 / 1+1+1, 1+2, 2+1, 3
// D[4] = D[3] + D[2] + D[1]
// 1+1+1+1
// 1+1+2
// 1+2+1
// 1+3
// 2+1+1
// 2+2
// 3+1