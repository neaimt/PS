#include <iostream>
#include <algorithm>
using namespace std;
int arr[8], sum=0, ck=0, res=101;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for ( int i = 0; i < 7; i++ ) {
        cin >> arr[i];
        if ( arr[i] % 2 != 0 ) {
            sum += arr[i];
            ck = 1;
            res = min(res, arr[i]);
        }
    }
    if ( ck == 1 )
        cout << sum << '\n' << res;
    else 
        cout << -1;
    
}