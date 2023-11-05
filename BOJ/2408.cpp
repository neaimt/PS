#include <iostream>
#include <algorithm>
long long N, M, st, en, mid, sum=0, Max_len=-1;
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int arr[N];

    for ( int i = 0; i < N; i++ ) cin >> arr[i];
    sort(arr, arr+N);
    
    st = 0;
    en = arr[N-1];

    while( st <= en ) {
        sum = 0;
        mid = ( st + en ) / 2;
        
        for ( int i = 0; i < N; i++ )
            if ( arr[i] - mid > 0 ) 
                sum += arr[i] - mid;
        
        if ( sum >= M ) {
            st = mid + 1;
            if ( mid > Max_len ) Max_len = mid;
        }
        else en = mid - 1;
    }

    cout << Max_len;
}