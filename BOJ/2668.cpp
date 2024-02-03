#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, arr[101];
int isused[101];
vector<int> res;
void DFS(int st) {
    queue<int> Q;

    isused[st] = 1; // 방문 표시
    Q.push(st);

    queue<int> q;
    while ( !Q.empty() ) {
        int cur = Q.front(); Q.pop();
        q.push(cur);

        if ( arr[cur] == st ) {
            while ( !q.empty() ) {
                res.push_back(q.front());
                q.pop();
            }
        }

        if ( isused[arr[cur]] == 0 ) {
            Q.push(arr[cur]);
            isused[arr[cur]] = 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 1; i <= N; i++ )
        cin >> arr[i];

    for ( int i = 1; i <= N; i++ ) {
        DFS(i);
        fill(isused, isused+N, 0);
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout << res.size() << '\n';
    for ( int i = 0; i < res.size(); i++ )
        cout << res[i] << '\n';

}