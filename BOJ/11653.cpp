#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
 
    if (N == 1) return 0;
 
    for (int i = 2; i <= N; i++) {
        while (N % i == 0) {
            cout << i << endl;
            N /= i;
        }
    }
    
}