#include <iostream>
#include <algorithm>
using namespace std;
int N, M=1, r_c=-1;
int res[1000001];
void func(int cnt, int cur) {
  if ( cnt == M ) {
    r_c++;
    if ( r_c == N ) {
        for ( int i = 0; i < M; i++ )
          cout << res[i];
    }
    return;
  }

  for( int i = 0; i < 10; i++ ) {
    if ( ( (res[cnt-1] > i) && cnt != 0 ) || ( cnt == 0 ) ) {
      res[cnt] = i;
      func(cnt+1, i);
    }
  }

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for ( M = 1; M <= 10; M++ ) {
    func(0, 0);
    if ( r_c >= N )
      return 0;
    fill(res, res+M, 0);
  }
  cout << -1;
}
