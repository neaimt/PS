// 배열 A, B를 정렬한 후, 곱한 값
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, A[55], B[55];

    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> A[i];
    for ( int i = 0; i < n; i++ ) cin >> B[i];

    sort(A, A+n);
    sort(B, B+n, greater<int>());

    int res = 0;
    for ( int i = 0; i < n; i++ ) res += A[i]*B[i];

    cout << res;
}