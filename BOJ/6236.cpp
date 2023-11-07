#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, K, cnt=0, st=1, en = 0, total=0, ck=0, result=0;
int money[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        cin >> money[i];
        en += money[i];
    }

    while( st <= en ) {
        int mid = ( st + en ) / 2;

        total = mid;
        cnt = 1;
        ck = 0;
       
        for ( int i = 0; i < N; i++ ) {
            if ( money[i] > mid ) {
                ck = 1;
                break;
            }
            if ( money[i] > total ) {
                total = mid;
                cnt++;
            }
            total -= money[i];
        }
        if ( ck || cnt > M )
            st = mid + 1;
        else {
            result = mid;
            en = mid - 1;
        }
    }
    cout << result;
}