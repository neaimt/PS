#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int N, M, R, u, v, cnt=0;
vector<int> arr[100001];
int vis[100001];
void BFS() {
    queue<int> Q;
    vis[R] = cnt++;
    Q.push(R);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        vis[cur] = cnt++;

        for ( int i = 0; i < arr[cur].size(); i++ ) {
            if ( vis[arr[cur][i]] ) continue;
            vis[arr[cur][i]] = 1;
            Q.push(arr[cur][i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    for ( int i = 1; i <= M; i++ ) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for ( int i = 1; i <= N; i++ )
        sort(arr[i].begin(), arr[i].end(), greater<>());

    BFS();
    for ( int i = 1; i <= N; i++ ) 
        cout << vis[i] << "\n";
}