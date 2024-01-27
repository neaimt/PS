#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, M, hour=0;
long long stress, work;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C >> M;

    while ( hour < 24 ) {
        if ( stress + A > M ) { // 피로도가 최대치를 넘길 때
            stress -= C; // 쉬어야 함

            if ( stress < 0 )
                stress = 0;
        }
        else { // 일을 한다면
            stress += A;
            work += B;
        }

        hour++;
    }
    
    cout << work;
}