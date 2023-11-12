#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, cnt=0;
long long arr[2001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for ( int i = 0; i < N; i++ ) cin >> arr[i];
    sort(arr, arr+N);

    for ( int i = 0; i < N; i++ ) {
        int st = 0, en = N - 1;
        long long sum;

        while ( st < en ) {
            sum = arr[st] + arr[en];
            if ( sum == arr[i] ) {
                if ( st != i && en != i ) {
                    cnt++;
                    break;
                }
                else if ( st == i ) st++;
                else if ( en == i ) en--;
            }

            else if ( sum < arr[i] ) st++;
            else en--;
        }
    }
    cout << cnt;
}