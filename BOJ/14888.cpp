#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long arr[12];
long long min_r=1000000000000, max_r=-1000000000000;
int op[4];
void func(int cur, long long result, int p, int m, int mul, int d) {
  if ( cur == N ) {
    min_r = min(min_r, result);
    max_r = max(max_r, result);
    return;
  }

  if ( p ) func(cur+1, result+arr[cur], p-1, m, mul, d);
  if ( m ) func(cur+1, result-arr[cur], p, m-1, mul, d);
  if ( mul ) func(cur+1, result*arr[cur], p, m, mul-1, d);
  if ( d ) func(cur+1, result/arr[cur], p, m, mul, d-1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for( int i = 0; i < N; i++ ) cin >> arr[i];
  for( int i = 0; i < 4; i++ ) cin >> op[i];

  func(1, arr[0], op[0], op[1], op[2], op[3]);
  
  cout << max_r << '\n';
  cout << min_r;
}