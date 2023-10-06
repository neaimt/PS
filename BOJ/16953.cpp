#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
long long A, B;
long long BFS() {
    queue<pair<long long, long long>> Q;
    Q.push({A, 1}); // A와 cnt = 1
    while (!Q.empty()) {
        pair<long long, long long> cur = Q.front(); Q.pop();

        if ( cur.X == B ) 
            return cur.Y;
        if (cur.X * 2 <= B )
            Q.push({cur.X*2, cur.Y+1});
        if ( cur.X*10 + 1 <= B )
            Q.push({cur.X*10+1, cur.Y+1});
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    cout << BFS();
}
