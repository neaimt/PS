#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[100001];
int vis[100001], ans[100001];
int N, x, y;
void BFS() {
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;

    while(!Q.empty()) {
        int parent = Q.front(); Q.pop();

        for(int i = 0; i < graph[parent].size(); i++ ) {
            int child = graph[parent][i];
            if ( vis[child] ) continue;
            vis[child] = 1;
            ans[child] = parent;
            Q.push(child);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N-1; i++ ) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    BFS();
    
    for ( int i = 2; i <= N; i++ ) {
        cout << ans[i] << "\n";
    }
}