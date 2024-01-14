#include <iostream>
#include <algorithm>
using namespace std;
int T;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    getchar();

    for ( int i = 0; i < T; i++ ) {
        string arr;

        cin >> arr;
        cout << (int)(arr[0]-'0') + (int)(arr[2]-'0') << '\n';
    }
}