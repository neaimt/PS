#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w;
    int arr[1001];
    cin >> t >> w;
    for ( int i = 1; i <= t; i++ ) cin >> arr[i];
}

// 현재 위치에 자두
// 1. 이동 -------
// 2.가만히 --> 위치, 횟수, 시간+1 = ( 위치, 횟수, 시간 )+1

// 다른 위치에 자두
// 1.이동 --> 위치변경, 횟수+1, 시간+1 = ( 위치변경, 횟수, 시간 + 1,  )
// 2.가만히 --> 위치, 횟수, 시간+1 = ( 위치, 횟수, 시간 )

// 현재 위치, 남은 이동횟수, 초 = 자두개수


