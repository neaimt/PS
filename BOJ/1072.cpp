#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000
long long  X, Y, Z, st, en, mid, Z_, min_mid;
int ck = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y;
    Z =  (long double)Y / X  * 100; // 처음 승률

    st = 0;
    en = MAX;
    min_mid = MAX;
    while ( st <= en ) {
        mid = ( st + en ) / 2;
        Z_ = (long double)( Y + mid ) / ( X + mid ) * 100;

        if ( Z_ <= Z )
            st = mid + 1;

        else {
            en = mid - 1;
            if ( mid <= min_mid ) {
                min_mid = mid;
                ck = 1;
            }
        }
    }
    if ( ck == 1 )
        cout << min_mid;
    else 
        cout << -1;
}