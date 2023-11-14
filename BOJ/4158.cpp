#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
long long arr[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while ( 1 ) {
        cin >> N >> M;
        if ( N == 0 && M == 0 ) break;

        for ( int i = 0; i < N; i++ ) cin >> arr[i];

        int result=0;
        for ( int i = 0; i < M; i++ ) {
            int st = 0, en = N-1, num;
            cin >> num;

            while ( st <= en ) {
                int mid = ( st + en ) / 2;

                if ( num > arr[mid] ) 
                    st = mid + 1;
                else if ( num < arr[mid]) 
                    en = mid - 1;
                else {
                    result++;
                    break;
                }
            }
        }
        cout << result << '\n';
    }
}