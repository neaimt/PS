#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> vertex[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
long weight[20001], vis[20001];
int V, E, K;
int u, v, w;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;
    for ( int i = 0; i < E; i++ ) {
        cin >> u >> v >> w;
        vertex[u].push_back({w, v}); // 비용과 도착지점
    }
    
    fill(weight, weight+V+1, 2000001);
    weight[K] = 0;
    Q.push({0, K});

    while ( !Q.empty() ) {
        K = Q.top().second; Q.pop();
        
        if ( vis[K] ) continue;
        
        vis[K] = 1; // 방문 표시
        for ( int j = 0; j < vertex[K].size(); j++ ) { // 부착 간선
            int e = vertex[K][j].second; // 도착 정점
            int c = vertex[K][j].first; // 가중치

            if ( weight[e] < weight[K] + c || vis[e] ) continue;

            weight[e] =  weight[K] + c; // 가중치 업데이트
            Q.push({weight[e], e});
        }
    }

    for ( int i = 1; i <= V; i++ ) {
        if ( vis[i] == 0 ) cout << "INF\n";
        else 
            cout << weight[i] << '\n';
    }

}