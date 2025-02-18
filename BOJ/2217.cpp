#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[100002];

    cin >> n;

    for ( int i = 0; i < n; i++ )
        cin >> arr[i];

    sort(arr, arr+n);
    
    int w=arr[0];
    for ( int i = 0; i < n; i++ ) {
        if ( w < arr[i] * (n-i) )
            w = arr[i] * (n-i);
    }

    cout << w;
}

// 정렬해서 로프 개수 * 숫자 가 제일 큰 거 선택