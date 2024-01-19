#include <iostream>
#include <algorithm>
using namespace std;
int arr[1005], A, B, sum=0, cur=1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    for ( int i = 1; i <= 1000; i++ ) {
        for ( int j = 0; j < i; j++ )
        if ( cur + j <= 1000 )
            arr[cur+j] = i;
        
        cur = cur + i;
    }

    for ( int i = A; i <= B; i++ ) 
        sum += arr[i];
    
    cout << sum;
}