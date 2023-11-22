#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
long long arr[10001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];

  long long st=1, en=1000000000000, result=1;
  while ( st <= en ) {
    long long mid = ( st + en ) / 2;

    int cnt=0;
    for ( int i = 0; i < N; i++ ) {
      if ( arr[i] >= mid )
        cnt += arr[i] / mid;
    }
    
    if ( cnt >= K ){
      result = mid;
      st = mid + 1;
    }
    else 
      en = mid - 1;
  }

  cout << result;
}