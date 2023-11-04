#include <iostream>
#include <algorithm>
using namespace std;
int N, cnt=0;
int a[1000000];
int sub[1];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
    for ( int i = 0; i < N; i++ ) cin >> a[i];

    sub[0] = a[0]; // 부분 수열의 첫번째 값 초기화
    for ( int i = 1; i < N; i++ ) {
        if ( sub[cnt] < a[i] ) { // 증가할 경우
            sub[++cnt] = a[i];
        }
        else { // 감소할 경우
            int idx = lower_bound(sub, sub+cnt, a[i]) - sub;
            sub[idx] = a[i];
        }
    }
    
    cout << cnt+1;
}
