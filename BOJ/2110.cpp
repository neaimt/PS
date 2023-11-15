#include <iostream>
#include <algorithm>
using namespace std;
int N, C;
long long arr[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for ( int i = 0; i < N; i++ ) cin >> arr[i];

    sort(arr, arr+N);
    long long st = 0, en = arr[N-1]-arr[0], result=arr[1]-arr[0];
    while ( st <= en ) {
        long long mid = ( st + en ) / 2;

        long long cnt=1;
        int install = 0, ck=0;
        for ( int i = 1; i < N; i++ ) {
          if ( arr[i] >= arr[install] + mid ) {
            cnt++;
            install = i;
          }

          if ( cnt > C ) {
            ck = 1;
            break;
          }
        }

        if ( ck == 1 || cnt >= C ) {
          result = mid;
          st = mid + 1;
        }
        else
          en = mid - 1;
    }
    cout << result;
}