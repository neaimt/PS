#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int dy[2] = { 1, -1 }; // 오른쪽 왼쪽
int vis[1001]; // 회전 유무 + 방향 표시

int T, K, num, d, res=0;
string status;
deque<int> Dq[1001];
deque<int> Q;

void direction(int cur, int dir) {
    if ( dir == -1 ) { // 반시계 방향
        Dq[cur].push_back(Dq[cur].front());
        Dq[cur].pop_front(); // 회전
    } else { // 시계 방향
        Dq[cur].push_front(Dq[cur].back());
        Dq[cur].pop_back();
    }
}
void moveWheel(int num, int d) {
    memset(vis, 0, sizeof(vis));
    deque<int> moveQ;

    moveQ.push_back(num); // 동시에 회전할 톱니바퀴 번호

    Q.push_back(num); // 첫번째로 회전하는 톱니바퀴
    vis[num] = d; // 회전 방향

    int cnt=0;
    while( !Q.empty() ) {
        int cur = Q.back(); Q.pop_back();
        cnt++;
        for ( int dir = 0; dir < 2; dir++ ) {
            int ny = cur + dy[dir];

            if ( ny <= 0 || ny > T || vis[ny] != 0 ) continue;
    
            if ( ( dy[dir] == 1 && Dq[cur][2] != Dq[ny][6] ) || ( dy[dir] == -1 && Dq[cur][6] != Dq[ny][2] ) ) {
                vis[ny] = vis[cur] * -1; // 반대 방향 표시
                Q.push_back(ny);
                moveQ.push_back(ny);
            }
            else if ( ( dy[dir] == 1 && Dq[cur][2] == Dq[ny][6] ) || ( dy[dir] == -1 && Dq[cur][6] == Dq[ny][2] ) ) {
                vis[ny] = 0; // 방문 표시
            }
        }
    }

    while(!moveQ.empty()) {
        int m_cur = moveQ.front(); moveQ.pop_front();
        direction(m_cur, vis[m_cur]); 
    }
}
int main() {
    cin >> T;

    for ( int i = 1; i <= T; i++ ) {
        cin >> status;
        for ( int j = 0; j < 8; j++ )
            Dq[i].push_back(status[j] - '0');
    }

    cin >> K;

    for ( int i = 0; i < K; i++ ) {
        cin >> num >> d;
        moveWheel(num, d);
    }

    for ( int i = 1; i <= T; i++ )
        if ( Dq[i][0] == 1 ) res++;
    
    cout << res << '\n';
}

// 원형 배열
// 2, 6이 연결되는 부분 
// 회전할 톱니바퀴의 2, 6과 연결된 극 확인 
// 만약 다를 경우
// 시계방향 회전 시, 다른 톱니바퀴 반시계 방향 회전
// 반시계방향 회전 시, 다른 톱니바퀴 시계 방향 회전
// 즉 반대로 회전하게 됨.