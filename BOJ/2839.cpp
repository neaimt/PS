#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[5001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[3] = dp[5] = 1;
    for ( int i = 6; i <= N; i++ ) {
        if ( dp[i-3] ) dp[i] = dp[i-3] + 1;
        if ( dp[i-5] ) dp[i] = dp[i] ? min(dp[i], dp[i-5]+1) : dp[i-5]+1;
    }
    if ( dp[N] == 0 )
        cout << -1;
    else 
     cout << dp[N];
}