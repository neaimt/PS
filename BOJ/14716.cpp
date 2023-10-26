#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int N, M, cnt=0;
int board[251][251];
int vis[251][251];
void BFS()
{
    queue<pair<int, int>> Q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!board[i][j] || vis[i][j])
                continue;
            vis[i][j] = 1;
            Q.push({i, j});
            cnt++;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 8; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if (!board[nx][ny] || vis[nx][ny])
                        continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    BFS();
    cout << cnt;
}