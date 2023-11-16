#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
long long arr[1000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];
  sort(arr, arr+N);

  long long st = 1, en = arr[N-1], result=0; // 과자의 길이
  while ( st <= en ) {
    long long mid = ( st + en + 1 ) / 2;

    int cnt = 0;
    for ( int i = 0; i < N; i++ ) {
      if ( arr[i] >= mid ) 
        cnt += arr[i] / mid;
    }
    if ( cnt >= M ) {
      result = mid;
      st = mid + 1;
    }
    else 
      en = mid - 1;
  }
  cout << result;
}