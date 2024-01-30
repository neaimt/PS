#include <iostream>
#include <algorithm>
using namespace std;
long long T, N;
bool is_prime(long long N) {
    if ( N <= 1 )
        return false;
    if ( N == 2 || N == 3 )
        return true;
    if ( N % 2 == 0 || N % 3 == 0 )
        return false;
    for ( long long i = 5; i * i <= N; i++ ) {
        if ( N % i == 0 || N % ( i + 2 ) == 0 )
            return false;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    for ( long long i = 0; i < T; i++ ) {
        cin >> N;
        while ( !is_prime(N) )
            N++;
        cout << N << '\n';
    }
}