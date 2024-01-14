#include <iostream>
#include <algorithm>
using namespace std;
int N, M, n;
int arr[101][101], arr1[101][101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0 ; i < N; i++ )
        for ( int j = 0; j < M; j++ )
            cin >> arr[i][j];

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ )
            cin >> arr1[i][j];

    for ( int i = 0 ; i < N; i++ ) {
        for ( int j = 0; j < M; j++ )
            cout << arr[i][j] + arr1[i][j] << ' ';
        cout << '\n';
    }
}