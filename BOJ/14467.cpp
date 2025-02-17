#include <iostream>

using namespace std;

int cow[11];
int N, c, l, cnt=0;

int main() {
    for ( int i = 1; i <= 10; i++ ) {
        cow[i] = -1;
    }

    cin >> N;
    for ( int i = 0; i < N; i++ ) {
        cin >> c >> l;

        if ( cow[c] == 0 || cow[c] == 1 )
            if ( cow[c] != l )
                cnt++;
        
        cow[c] = l;
    }

    cout << cnt;
}

// 소 N번 관찰 (소의 번호, 위치) 총 10마리 위치 0, 1
// 배열 만들어서 소의 번호, 현재 위치 비교