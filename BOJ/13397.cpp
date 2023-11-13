#include <iostream>
#include <algorithm>
using namespace std;
int N, M, min_N=10000, max_N=0;
int arr[5001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        cin >> arr[i];
        min_N = min(min_N, arr[i]);
        max_N = max(max_N, arr[i]);
    }

    int st = 0, en = max_N, result=en;
    while ( st <= en ) {
        int mid = ( st + en ) / 2;
        
        int cnt = 1, ck=0;
        int i_s=arr[0], i_e=arr[0];
        for ( int i = 1; i < N; i++ ) {
            i_e = max(i_e, arr[i]);
            i_s = min(i_s, arr[i]);
        
            if ( i_e - i_s > mid ) {
                i_s = arr[i];
                i_e = arr[i];
                cnt++;
            }

            if ( cnt > M ) {
                ck = 1;
                break;
            }
        }

        if ( cnt > M || ck == 1 )
            st = mid + 1;

        else {
            result = mid;
            en = mid - 1;
        }
    }
    cout << result;
}