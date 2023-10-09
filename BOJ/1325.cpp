#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> arr[10001], ans[10001];
int vis[10001];
int N, M, A, B, m=-1;
int BFS(int i) {
    int cnt = 0;
    queue<int> Q;
    vis[i] = 1;
    Q.push(i);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for ( int j = 0; j < arr[cur].size(); j++ ) {
            if ( vis[arr[cur][j]] ) continue;
            vis[arr[cur][j]] = 1;
            Q.push(arr[cur][j]);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < M; i++ ) {
        cin >> A >> B;
        arr[B].push_back(A);
    }

    for ( int i = 1; i <= N; i++ ) {
        for ( int j = 1; j <= N; j++ )
            vis[j] = 0;
        ans[i].push_back(BFS(i));

        if ( m < ans[i][0] )
            m = ans[i][0];
    }

    for ( int i = 1; i <= N; i++ ) {
        if ( m == ans[i][0] )
            cout << i << " ";
    }
}