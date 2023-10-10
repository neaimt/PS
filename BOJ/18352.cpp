#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
int N, M, K, X;
int A, B;
int vis[300001];
vector<int> arr[300001], ans;
void BFS() {
    queue<pair<int, int>> Q;
    vis[X] = 1;
    Q.push({X, 0});

    while(!Q.empty()) {
        int nx = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();

        if ( cnt == K )
            ans.push_back(nx);
            
        for ( int i = 0; i < arr[nx].size(); i++ ) {
            if ( vis[arr[nx][i]] ) continue;

            vis[arr[nx][i]] = 1;
            Q.push({arr[nx][i], cnt+1});
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> X;
    for ( int i = 0; i < M; i++ ) {
        cin >> A >> B;
        arr[A].push_back(B);
    }

    BFS();
    if ( ans.size() == 0 )
        cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for ( auto a: ans )
            cout << a << '\n';
    }
}