#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, result=0;
int arr[4]={1, 5, 10, 50};
int isused[1001];
void func(int cnt, int cur, int num) {
  if ( cnt == N ) {
      if ( !isused[num] ) {
        isused[num] = 1;
        result++;
      }
    return;
  }

  for ( int i = cur; i < 4; i++ )
    func(cnt+1, i, num+arr[i]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  func(0, 0, 0);

  cout << result;
}