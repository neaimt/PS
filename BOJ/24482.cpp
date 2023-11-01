#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> arr[100001];
int vis[100001], result[100001];
int N, M, R, u, v, cnt=0;
void DFS(int R, int cnt) {
    if ( vis[R] == 1 )
        return;
    
    vis[R] = 1;
    result[R] = cnt;
    sort(arr[R].begin(), arr[R].end(), greater<int>());
    for ( int i = 0; i < arr[R].size(); i++ ) {
        DFS(arr[R][i], cnt+1); 
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    for ( int i = 0; i < M; i++ ) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    DFS(R, 0);
    for ( int i = 1; i <= N; i++ ) {
        if ( vis[i] == 0 )
            cout << -1 << "\n";
        else 
            cout << result[i] << "\n";
    }
}