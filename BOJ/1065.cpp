#include <iostream>
#include <algorithm>
using namespace std;
int N, cnt=0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if ( N == 1000 ) {
        cout << 144;
        return 0;
    }

    for ( int i = 1; i <= N; i++ ) {
        if ( i < 100 )
            cnt++;

        else {
            int arr[3];
            arr[0] = i / 100 % 10;
            arr[1] = i / 10 % 10;
            arr[2] = i % 10;

            if ( arr[0] - arr[1] == arr[1] - arr[2] )
                cnt++;
        }
    }

    cout << cnt;
}