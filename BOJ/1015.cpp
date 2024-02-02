#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1001], res[1001];
int isused[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for ( int i = 0; i < N; i++ ) {
        cin >> arr[i];
        res[i] = arr[i];
    }

    sort(arr, arr+N);
    
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ )
            if ( res[i] == arr[j] && isused[j] == 0 ) {
                isused[j] = 1;
                cout << j << ' ';
                break;
            }
    }
}