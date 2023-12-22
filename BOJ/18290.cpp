#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int arr[10][10];
bool check[10][10];
int ans = -100000000;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void func(int cnt, int sum) {
    if (cnt == k) {
        if (ans < sum) ans = sum;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j]) continue;
            int ck = 1;
            for (int z = 0; z < 4; z++) {
                int nx = i + dx[z];
                int ny = j + dy[z];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    if (check[nx][ny]) 
                        ck = 0;
            }
            if ( ck ) {
                check[i][j] = true;
                func(cnt + 1, sum+arr[i][j]);
                check[i][j] = false;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    func(0, 0);
    cout << ans;
}