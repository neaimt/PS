#include <iostream>
#include <algorithm>
using namespace std;
int N, M, num;
vector<int> arr;
int res[10];
void func(int cnt) {
  if ( cnt == M ) {
    for ( int i = 0; i < M; i++ )
      cout << res[i] << ' ';
    cout << '\n';
    return;
  }

  for ( int i = 0; i < N; i++ ) {
    if ( (res[cnt-1] <= arr[i] && cnt != 0) || (cnt == 0) ) {
      res[cnt] = arr[i];
      func(cnt+1);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for ( int i = 0; i < N; i++ ) {
    cin >> num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  N = arr.size();
  func(0);
}