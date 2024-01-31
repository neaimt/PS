#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int arr[1001], cnt=0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    for ( int i = 2; i <= N; i++ ) {
        for ( int j = i; j <= N; j += i ) {
            if ( arr[j] == 0 ) {
                cnt++;
                arr[j] = 1;
            }
            if ( cnt == K ) {
                cout << j;
                return 0;
            }
        }
    }
}