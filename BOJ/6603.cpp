#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
int K, T=1;
int res[15], isused[15];
void del() {
    while( !arr.empty() )
        arr.pop_back();
    
}
void func(int cnt, int cur) {
    if ( cnt == 6 ) {
        for ( int i = 0; i < 6; i++ )
            cout << res[i] << ' ';
        cout << '\n';
    }

    for ( int i = cur; i < T; i++ ) {
        if ( !isused[i] ) {
            isused[i] = 1;
            res[cnt] = arr[i];
            func(cnt+1, i);
            isused[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while ( T != 0 ) {
        cin >> T;
        if ( T == 0 )
            return 0;
        
        for ( int i = 0; i < T; i++ ) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        T = arr.size();

        func(0, 0);
        cout << '\n';

        del();
        fill(res, res+14, 0);
        fill(isused, isused+14, 0);
    }

}