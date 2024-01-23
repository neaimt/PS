#include <iostream>
#include <algorithm>
using namespace std;
int N, A[51], B[51], sum;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ ) 
        cin >> A[i];
    for ( int i = 0; i < N; i++ ) 
        cin >> B[i];

    sort(A, A+N);
    sort(B, B+N);

    for ( int i = 0; i < N; i++ )
        sum += (A[i]*B[N-i-1]);
    
    cout << sum;
}