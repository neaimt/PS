#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int res1=1, res2= 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int k = K;
    for ( int i = 0; i < k; i++ ) {
        res1 *= N--;
        res2 *= K--;
    }

    cout << res1/res2;

}