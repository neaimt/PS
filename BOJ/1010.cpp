#include <iostream>
#include <algorithm>
using namespace std;
int T, N, M;
long long dp[32][32];
void func(int n) {
    for ( int k = 1; k <= 30; k++ ) {
        if ( n == 1 )
            dp[n][k] = k;

        else if ( n == k )
            dp[n][k] = 1;

        else
            for ( int i = n; i <= k; i++ ) 
                dp[n][k] += dp[n-1][i-1];
    }

    if ( n == 30 )
        return;

    func(n+1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    func(1);
    
    cin >> T;
    for ( int i = 0; i < T; i++ ) {
        cin >> N >> M;
        cout << dp[N][M] << '\n';
    }
}

