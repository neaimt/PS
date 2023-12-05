#include <iostream>
#include <algorithm>
using namespace std;
int N;
long res=100000000;
int arr[11][11];
int isused[11], r[11];
void func(int cnt, int S, int st, long sum) {
  if ( cnt == N ) {
    if ( arr[st][S] != 0 )
      res = min(res, sum+arr[st][S]);
    return;
  }

  for ( int en = 0; en < N; en++ ) {
    if ( st == en || arr[st][en] == 0 ) continue;

    if ( !isused[en] ) {
      r[cnt] = en;
      isused[en] = 1;
      func(cnt+1, S, en, sum+arr[st][en]);
      isused[en] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++ )
    for (int j = 0; j < N; j++ )
      cin >> arr[i][j];
  
  for ( int i = 0; i < N; i++ ) {
    isused[i] = 1;
    func(1, i, i, 0);
    isused[i] = 0;
  }

  cout << res;
}