#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int N, K;
int vis[100001];
int BFS() {
    queue<pair<int, int>> Q;
    vis[N] = 1;
    Q.push({N, 0});

    while(!Q.empty()) {
        int nx = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();

        if ( nx == K ) 
            return cnt;

        //순간이동 하는 경우
        if ( nx*2 <= 100001 ) {
            if (!vis[nx*2] ) {
                vis[nx*2] = 1;
                Q.push({nx*2, cnt});
            }
        }
        
        //걷는 경우
        if ( nx-1 >= 0 ) {
            if ( !vis[nx-1] ) {
                vis[nx-1] = 1;
                Q.push({nx-1, cnt+1});
            }
        }
        
        if ( nx+1 <= K ) {
            if ( !vis[nx+1] ){
                vis[nx+1] = 1;
                Q.push({nx+1, cnt+1});
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    cout << BFS();
}