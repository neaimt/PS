#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
string board[1001];
int Jvis[1001][1001], Fvis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;

    for ( int i = 0; i < R; i++ ) {
        fill(Fvis[i],Fvis[i]+C, -1);
        fill(Jvis[i],Jvis[i]+C, -1);
    }

    for ( int i = 0; i < R; i++ ) 
        cin >> board[i];
    
    queue<pair<int, int>> JQ, FQ;

    // 불이 나는 시간 구하기
    for ( int i = 0; i < R; i++ )
        for ( int j = 0; j < C; j++ ) {
            if ( board[i][j] == 'F' ) {
                FQ.push({i, j});
                Fvis[i][j] = 0;
            }
            else if ( board[i][j] == 'J') {
                JQ.push({i, j});
                Jvis[i][j] = 0;
            }
        }

    while ( !FQ.empty() ) {
        pair<int, int> cur = FQ.front(); FQ.pop();
        for ( int dir = 0; dir < 4; dir ++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;
            if ( board[nx][ny] == '#' || Fvis[nx][ny] >= 0 ) continue;
            
            Fvis[nx][ny] = Fvis[cur.X][cur.Y] + 1;
            FQ.push({nx, ny});
        }
    }
    //지훈이가 탈출하는 시간 구하기
    while ( !JQ.empty() ) {
        pair<int, int> cur = JQ.front(); JQ.pop();
        for ( int dir = 0; dir < 4; dir ++ ) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if ( nx < 0 || nx >= R || ny < 0 || ny >= C ) {
                cout << Jvis[cur.X][cur.Y] + 1;
                return 0;
            }

            if ( board[nx][ny] == '#' || Jvis[nx][ny] >= 0 ) continue;
            if ( Fvis[nx][ny] != -1 && Fvis[nx][ny] <=  Jvis[cur.X][cur.Y] + 1 ) continue;
             Jvis[nx][ny] = Jvis[cur.X][cur.Y] + 1;
            JQ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    

   
}

/*
4 5
#####
#JF.#
#...#
#F..#
*/