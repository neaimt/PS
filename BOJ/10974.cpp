#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[10];
int isused[10];
void func(int cnt) {
  if ( cnt == N ) {
    for ( int i = 0; i < N; i++ )
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for ( int i = 1; i <= N; i++ ) {
    if ( !isused[i] ) {
      isused[i] = 1;
      arr[cnt] = i;
      func(cnt+1);
      isused[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  func(0);
}