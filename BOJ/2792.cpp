#include <iostream>
#include <algorithm>
using namespace std;
long long N;
int M, max_M=0;
int color[300001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < M; i++ ) {
        cin >> color[i];
        max_M = max(max_M, color[i]);
    }

    int st = 1, en = max_M;
    while ( st <= en ) {
        int cnt = 0;
        int mid = ( st + en ) / 2;
        
        for ( int i = 0; i < M; i++ ) {
            if ( color[i] > mid ) {
                cnt += color[i] / mid;
                if ( mid * (color[i] / mid) < color[i] )
                    cnt++;
            }
            else 
                cnt++;
        }

        if ( cnt > N )
            st = mid + 1;
        else
            en = mid - 1;
    }

    cout << st;
}