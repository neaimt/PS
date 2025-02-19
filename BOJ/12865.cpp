#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int dp[105][100005];
pair<int, int> B[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for ( int i = 1; i <= n; i++ ) {
        cin >> B[i].first >> B[i].second;
    }
    
    for ( int i = 1; i <= n; i++ ) {
        int w = B[i].first, v = B[i].second;
        for ( int j = 0; j <= k; j++ ) {
            dp[i][j] = dp[i-1][j];
            if ( j - w >= 0 ) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w] + v);
            }
        }
    }
    
    cout << dp[n][k];
}
