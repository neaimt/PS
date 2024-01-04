#include <iostream>
#include <algorithm>
using namespace std;
int T, N, K, cnt;
int arr[20][20];
void make() {
    for (int i = 1; i <= 14; i++ )
        for ( int j = 1; j <= 14; j++ ) {
           for ( int k = 1; k <= j; k++ ) {
            arr[i][j] += arr[i-1][k];
           }
        }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for ( int i = 1; i <= 14; i++ )
        arr[0][i] = i;

    make();

    for ( int i = 0; i < T; i++ ) {
        cin >> N;
        cin >> K;

        cout << arr[N][K] <<'\n';
    }

}


