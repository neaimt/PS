#include <iostream>
#include <algorithm>
using namespace std;
int N, max_N=0, min_N=100000;
long long M, result=0;
int arr[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        cin >> arr[i];
        max_N = max(max_N, arr[i]);
        min_N = min(min_N, arr[i]);
    }

    sort(arr, arr+N);
    result = min_N;

    long long st = min_N, en = max_N*M;
    while( st <= en ) {
        long long mid = ( st + en ) / 2;

        long long cnt = 0;
        int ck = 0;
        for ( int i = 0; i < N; i++ ) {
            cnt += mid / arr[i]; // 사람 수
        
            if ( cnt > M ) {
                ck = 1;
                break;
            }
        }

        if ( ck || cnt >= M ) {
            en = mid - 1;
            result = mid;
        }

        else if ( cnt < M )
            st = mid + 1;
    }

    cout << result;
}