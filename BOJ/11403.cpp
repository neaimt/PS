#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9
int N;
int arr[101][101], dist[101][101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 1; i <= N; i++ ) 
        for ( int j = 1; j <= N; j++ )
            cin >> dist[i][j];
    
    // 플로이드 워셜
    for ( int m = 1; m <= N; m++ ) {
        for ( int s = 1; s <= N; s++ ) {
            for ( int e = 1; e <= N; e++ ) {
                if ( dist[s][m] && dist[m][e] )
                    dist[s][e] = 1;
            }
        }
    }

    for ( int i = 1; i <= N; i++ ) {
        for ( int j = 1; j <= N; j++ )
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
}