#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
int arr[11], r[5], isused[11];
vector<int> res;
void func(int cnt, int cur) {
  if ( cnt == K ) {
    int num = 0;
    for ( int i = 0; i < K; i++ ) {
      if ( r[i] > 9 )
        num = num*10;
      num = num*10 + r[i];
    }
    res.push_back(num);
    return;
  }

  for ( int i = 0; i < N; i++ ) {
    if ( !isused[i] ) {
      isused[i] = 1;
      r[cnt] = arr[i];
      func(cnt+1, i);
      isused[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  cin >> K;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];
  func(0, 0);

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  cout << res.size();
}