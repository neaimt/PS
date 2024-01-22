#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[10];
int N, res=0;
void func(int cur) {
    if ( cur == N  ) {
        int cnt = 0;
        for ( int i = 0; i < N; i++ )
            if ( arr[i].first <= 0 )
                cnt++;
                
        res = max(res, cnt);
        return;
    }
    if ( arr[cur].first <= 0 ) {
        func(cur+1);
        return;
    }

    int flag = 0;
    for ( int x = 0; x < N; x++ ) {
        if ( x == cur || arr[x].first <= 0 )
            continue;

        flag = 1;
        arr[cur].first -= arr[x].second;
        arr[x].first -= arr[cur].second;
        func(cur+1);
        arr[cur].first += arr[x].second;
        arr[x].first += arr[cur].second;
    }

    if ( !flag )
        func(cur+1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ )
        cin >> arr[i].first >> arr[i].second;

    func(0);
    cout << res;
}