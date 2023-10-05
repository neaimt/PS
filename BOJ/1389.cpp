// 유저의 친구 수를 담은 배열
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
vector<int> user[101];
int f[101], re[101], vis[101];
int N, M, x, y, cnt;
void BFS() {
    queue<pair<int, int>> Q; // 번호와 cnt

    for ( int i = 1; i <= N; i++ ) {
        for ( int k = 1; k <= N; k++ ) // 초기화
            vis[k] = 0;
        
        Q.push({i, 0});
        vis[i] = 1;
        while(!Q.empty()) {
            int nx = Q.front().X;
            int cnt = Q.front().Y;
            Q.pop();

            re[i] += cnt;

            for ( int j = 0; j < user[nx].size(); j++ ) {
                if ( vis[user[nx][j]] ) continue;

                vis[user[nx][j]] = 1;
                Q.push({user[nx][j], cnt+1});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < M; i++ ) {
        cin >> x >> y;
        user[x].push_back(y);
        user[y].push_back(x);
        f[x]++;
        f[y]++;
    }
    BFS();
    
    int min = re[1];
    int idx = 1;
    for ( int i = 2; i <= N; i++ ) {
        if ( min > re[i] ) {
            idx = i;
            min = re[i];
        }
    }

    cout << idx;
}