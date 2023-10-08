#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first 
#define Y second
int vis[1000001];
int F, S, G, U, D;
int BFS() {
    queue<pair<int, int>> Q; //현재 엘리베이터 층수와 cnt 
    Q.push({S, 0});
    vis[S] = 1;

    while(!Q.empty()) {
        int fl = Q.front().X;
        int cnt = Q.front().Y;
        Q.pop();

        if ( fl == G ) return cnt; 

        if ( fl < 1 || fl > F ) continue;
       
        if ( fl+U <= F && vis[fl+U] == 0 ) {
            Q.push({fl+U, cnt+1});
            vis[fl+U] = 1;
        }
        if ( fl-D >= 1 && vis[fl-D] == 0) {
            Q.push({fl-D, cnt+1});
            vis[fl-D] = 1;
        }   
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    int ans = BFS();

    if ( ans == -1 )
        cout << "use the stairs";
    else 
        cout << ans;
}