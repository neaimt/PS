#include <iostream>
#include <algorithm>
using namespace std;
int N, num;
long long res=1;
int arr[1000001]={0};
vector<int> A;
void func() {
    for ( int i = 2; i <= 1000000; i++ )
        arr[i] = i;
    
    for ( int i = 2; i * i <= 1000000; i++ ) {
        if ( arr[i] == 0 ) continue;

        for ( int j = i * i; j <= 1000000; j += i )
            arr[j] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    func();

    cin >> N;
    for ( int i = 0; i < N; i++ ) {
        cin >> num;
        A.push_back(num);
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    N = A.size(); 

    for ( int i = 0; i < N; i++ )
        if ( arr[A[i]] != 0 )
            res *= A[i];

    if ( res == 1 )
        cout << -1;
    else 
        cout << res;
}