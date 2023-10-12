#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int N;
int A[1001];
int vis[1001];
int BFS() {
    queue<pair<int, int>> Q;
    vis[0] = 1;
    Q.push({0, 0});

    while(!Q.empty()) {
        int nx = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();

        if ( nx == N-1 )
            return cnt;

        for ( int i = 1; i <= A[nx]; i++ ) {
            if ( nx + i > N ) break;
            if ( vis[nx+i] ) continue;

            vis[nx+i] = 1;
            Q.push({nx+i, cnt+1});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ )
        cin >> A[i];

    cout << BFS();
}