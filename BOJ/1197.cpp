#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int V, E, A, B, C;
long long ans;
int Parent[100001];
typedef pair<int, pair<int, int>> T;
vector<T> v;
int Find_Parent(int x) {
    if ( Parent[x] == x ) return x;
    else return Parent[x] = Find_Parent(Parent[x]);
}
void Union(int x, int y) {
    x = Find_Parent(x);
    y = Find_Parent(y);
    Parent[y] = x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for ( int i = 0; i < E; i++ ) {
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }
    sort(v.begin(), v.end());
    for ( int i = 0; i < V; i++ )
        Parent[i] = i;
    
    int cnt = 0;
    for ( int i = 0; i < v.size(); i++ ) {
        T curEdge = v[i];
        int cost = curEdge.first;
        int now = curEdge.second.first;
        int next = curEdge.second.second;

        if ( Find_Parent(now) == Find_Parent(next) ) continue;

        Union(now, next);
        ans += cost;

        if ( cnt++ == V-1 ) break;
    }
    cout << ans << '\n';
}
