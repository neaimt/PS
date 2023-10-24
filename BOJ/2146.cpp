#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, num = 0, cnt = 0;
int map[101][101];
int vis[101][101];
int result = 10001, Re = 10001;
void resetvis()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            vis[i][j] = -1;
    }
}
void Group()
{
    queue<pair<int, int>> Q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!map[i][j] || vis[i][j])
                continue;
            num++;

            vis[i][j] = num;
            Q.push({i, j});

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        continue;
                    if (!map[nx][ny] || vis[nx][ny])
                        continue;

                    vis[nx][ny] = num;
                    Q.push({nx, ny});
                }
            }
        }
    }
}
void BFS()
{
    queue<pair<int, int>> Q;

    for (int n = 1; n <= num; n++)
    {
        resetvis();
        result = 10001;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] != n || vis[i][j] != -1)
                    continue;
                vis[i][j] = 0;
                Q.push({i, j});
            }

        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;

                if (map[nx][ny] == n && vis[nx][ny] == -1) {
                    vis[nx][ny] = 0;
                    Q.push({nx, ny});
                }

                if (map[nx][ny] == 0 && vis[nx][ny] == -1) {
                    vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                }
                
                if (map[nx][ny] != n && map[nx][ny] != 0 && vis[nx][ny] == -1) {
                    if (result > vis[cur.X][cur.Y])
                        result = vis[cur.X][cur.Y];

                    vis[nx][ny] = 1;
                }
            }
        }

        if (Re > result)
            Re = result;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    Group();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[i][j] = vis[i][j];
        }
    }
    BFS();
    cout << Re;
}
