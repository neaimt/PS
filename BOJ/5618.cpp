#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[4];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> arr[i];
        
    sort(arr, arr+n);

    for ( int i = 1; i <= arr[0]; i++ ) {
        if ( arr[0] % i == 0 ) {
            int ck = 0;
            for ( int j = 1; j < n; j++ )
                if ( arr[j] % i == 0 )
                    ck++;
            
            if ( ck == n-1 )
                cout << i << '\n';
        }
    }
}