#include <iostream>
#include <algorithm>
using namespace std;
int N, M, st, en, sub_total=0, cnt, ck, result, max_r=0;
long long total=0;
int arr[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for ( int i = 0; i < N; i++ ) {
        cin >> arr[i];
        total += arr[i];
        max_r = max( max_r, arr[i] );
    }

    st = 1;
    en = total;
    while ( st <= en ) {
        int mid = ( st + en ) / 2;

        ck = 0;
        cnt = 1;
        sub_total = 0;
        for ( int i = 0; i < N; i++ ) {
            if ( mid > total ) {
                ck = 1;
                break;
            }

            if ( sub_total + arr[i] <= mid )
                sub_total += arr[i];
            else {
                sub_total = arr[i];
                cnt++;
            }

            if ( cnt > M ) 
                break;
        }

        if ( ck || cnt > M )
            st = mid + 1;

        else if ( cnt <= M ) {
            result = mid;
            en = mid - 1;
        }
    }
    if ( result < max_r )
        cout << max_r;
    else
        cout << result;
}