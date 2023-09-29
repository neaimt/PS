#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int vis[100001];
int N, K;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    queue<pair<int, int>> Q;
    Q.push({N, 0});
    vis[N] = 1;

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        if ( cur.X == K ) {
            cout << cur.Y;
            break;
        }

        if ( vis[cur.X*2] == 0 && cur.X*2 < 100001 ) { // x*2 이동
            Q.push({cur.X*2, cur.Y+1});
            vis[cur.X*2] = 1;
        }
        if ( vis[cur.X+1] == 0 ) { // x+1 이동
            Q.push({cur.X+1, cur.Y+1});
            vis[cur.X+1] = 1;
        }
        if ( vis[cur.X-1] == 0 ) {
            Q.push({cur.X-1, cur.Y+1}); // x-1 이동
            vis[cur.X-1] = 1;
        }
    }
}