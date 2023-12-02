#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char arr[16], res[16];
int isused[16];
void func(int cnt, int cur, int ck1, int ck2) {
  if ( cnt == L ) {
    if ( ck1 >= 1 && ck2 >= 2 ) {
      for ( int i = 0; i < cnt; i++ )
        cout << res[i];
      cout << '\n';
    }
    return;
  }

  for ( int i = cur; i < C; i++ ) {
    if ( !isused[i] ) {
      isused[i] = 1;
      res[cnt] = arr[i];
      if ( res[cnt] == 'a' || res[cnt] == 'e' || res[cnt] == 'i' || res[cnt] == 'o' || res[cnt] == 'u')
        func(cnt+1, i, ck1+1, cnt-ck1);
      else 
        func(cnt+1, i, ck1, ck2+1);
      isused[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;
  getchar();
  for ( int i = 0; i < C; i++ ) cin >> arr[i];
  sort(arr, arr+C);

  func(0, 0, 0, 0);
}