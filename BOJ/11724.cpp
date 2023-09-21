#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M, u, v, cnt=0;
vector<int> graph[1001];
int vis[1001];
void BFS(int i) {
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for ( int j = 0; j < graph[cur].size(); j++ ) {
            if ( vis[graph[cur][j]] ) continue;
            vis[graph[cur][j]] = 1;
            q.push(graph[cur][j]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for ( int i = 0; i < M; i++ ) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for( int i = 1; i <= N; i++ ) {
        if ( vis[i] ) continue; // 만약 방문했다면 
        BFS(i);
        cnt++;
    }
    cout << cnt;
}