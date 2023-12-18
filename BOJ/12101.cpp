#include <iostream>
#include <algorithm>
using namespace std;
int N, K, cnt, ck;
int res[11];
void func(int sum, int l) {
  if ( sum == N )
    cnt++;
  else if ( sum > N )
    return;

  if ( cnt == K ) {
    for ( int i = 0; i < l-1; i++ )
      cout << res[i] << '+';
    cout << res[l-1];
    ck = 1;
    exit(0);
  }

  for ( int i = 1; i <= 3; i++ ) {
    res[l] = i;
    func(sum+i, l+1);
    // res[len] = 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  func(0, 0);
  if ( ck == 0 )
    cout << -1;
}