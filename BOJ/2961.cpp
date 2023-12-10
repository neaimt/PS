#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long ingredient[11][3], isused[11];
int result=1000000000;
void func(int cur, int sour, int bitter) {
  if ( sour && bitter )
    result = min(result, abs(sour-bitter));

  for ( int i = 0; i < N; i++ ) {
    if ( cur != i && !isused[i] ) {
      isused[i] = 1;
      func(i, sour*ingredient[i][0], bitter+ingredient[i][1]);
      isused[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> ingredient[i][0] >> ingredient[i][1];
  func(-1, 1, 0);
  cout << result;
}