#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[101], isused[101];
long long res, Res;
void func(int cnt) {
    if ( cnt == 3 ) {
        if ( res <= M )
        Res = max(res, Res);
        return;
    }

    for ( int i = 0; i < N; i++ ) {
        if ( isused[i] == 0 ) {
            res += arr[i];
            isused[i] = 1;
            func(cnt+1);
            isused[i] = 0;
            res -= arr[i];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for ( int i = 0; i < N; i++ )
        cin >> arr[i];
    
    func(0);
    cout << Res;

}