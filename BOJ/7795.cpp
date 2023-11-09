#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, T, cnt=0;
vector<int> arr0, arr1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for ( int i = 0; i < T; i++ ) {
        int num;

        cin >> N >> M;
        arr0.clear(); arr1.clear();
        arr0.resize(N); arr1.resize(M);

        for ( int& x : arr0 ) cin >> x;
        for ( int& x : arr1 ) cin >> x;

        sort(arr0.begin(), arr0.end());
        sort(arr1.begin(), arr1.end());

        cnt = 0;
        for ( int i = 0; i < N; i++ ) 
            cnt += lower_bound(arr1.begin(), arr1.end(), arr0[i]) - arr1.begin();
        cout << cnt << '\n';
    }

    
}