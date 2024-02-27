#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int N, M, W, H, Sr, Sc, Fr, Fc;
int board[1005][1005], vis[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int BFS() {
    queue<tuple<int, int, int>> Q;
    Q.push({Sr, Sc, 0});
    for ( int i = Sr; i <= Sr+H-1; i++ )
        for ( int j = Sc; j <= Sc+W-1; j++ )
            vis[i][j] = 1;

    while ( !Q.empty() ) {
        pair<int, int> Scur; // 왼쪽위 좌표만 푸쉬, 팝함
        Scur.X = get<0>(Q.front());
        Scur.Y = get<1>(Q.front());
        int cnt = get<2>(Q.front());
        Q.pop();

        if ( Scur.X == Fr && Scur.Y == Fc )
            return cnt;

        for ( int dir = 0; dir < 4; dir++ ) {   
            pair<pair<int, int>, pair<int, int>> cur; // 왼쪽 오른쪽 or 위 아래

            if ( dir == 0 ) { // 위로 이동
                cur.X.X = Scur.X + dx[dir]; // 왼쪽위 좌표
                cur.X.Y = Scur.Y + dy[dir];
                cur.Y.X = Scur.X + dx[dir]; // 오른쪽위 좌표
                cur.Y.Y = Scur.Y+W-1 + dy[dir];
            }
            else if ( dir == 1 ) { // 오른쪽 이동
                cur.X.X = Scur.X + dx[dir]; // 오른쪽위 좌표
                cur.X.Y = Scur.Y+W-1 + dy[dir];
                cur.Y.X = Scur.X+H-1 + dx[dir]; // 오른쪽아래 좌표
                cur.Y.Y = Scur.Y+W-1 + dy[dir];
            }
            else if ( dir == 2 ) { // 아래로 이동
                cur.X.X = Scur.X+H-1 + dx[dir]; // 왼쪽아래 좌표
                cur.X.Y = Scur.Y + dy[dir];
                cur.Y.X = Scur.X+H-1 + dx[dir]; // 오른쪽아래 좌표
                cur.Y.Y = Scur.Y+W-1 + dy[dir];
            }
            else { // 왼쪽으로 이동
                cur.X.X = Scur.X + dx[dir]; // 왼쪽위 좌표
                cur.X.Y = Scur.Y + dy[dir];
                cur.Y.X = Scur.X + dx[dir]; // 왼쪽아래 좌표
                cur.Y.Y = Scur.Y+W-1 + dy[dir];
            }
            
            
            if ( cur.X.X < 1 || cur.X.X > N || cur.Y.X < 1 || cur.Y.X > N || cur.X.Y < 1 || cur.X.Y > M || cur.Y.Y < 1 || cur.Y.Y > M ) continue;

            int ck = 0;
            if ( dir == 0 || dir == 2 ) { // 위, 아래
                for ( int i = cur.X.Y; i <= cur.Y.Y; i++ )
                    if ( board[cur.X.X][i] == 1 || vis[cur.X.X][i] == 1 )
                        ck = 1;

                if ( ck == 0 ) {
                    Q.push({Scur.X+dx[dir], Scur.Y+dy[dir], cnt+1});
                    for ( int i = cur.X.Y; i <= cur.Y.Y; i++ )
                        vis[cur.X.X][i] = 1;
                }
            }

            else if ( dir == 1 || dir == 3 ){
                for ( int i = cur.X.X; i <= cur.Y.X; i++ ) // 왼쪽, 오른쪽
                    if ( board[i][cur.X.Y] == 1 || vis[i][cur.X.Y] == 1 )
                        ck = 1;

                if ( ck == 0 ) {
                    Q.push({Scur.X+dx[dir], Scur.Y+dy[dir], cnt+1});
                    for ( int i = cur.X.X; i <= cur.Y.X; i++ )
                        vis[i][cur.X.Y] = 1;
                }
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= M; j++ )
            cin >> board[i][j];

    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    cout << BFS();
}
