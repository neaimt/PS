#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[100001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for ( int i = 0; i < M; i++ ) cin >> arr[i];
  
  int st=1, en=100000, result=0;
  while ( st <= en ) {
    int mid = ( st + en ) / 2;
    
    int proper_distance = mid, cnt=0;
    for ( int i = 0; i < M; i++ ) {
      if ( arr[i] <= proper_distance ){ 
        proper_distance = arr[i] + mid;
        cnt++;

        if ( cnt == M ) break;
        else proper_distance += mid;
      }
    }
    
    if ( proper_distance < N )
      st = mid + 1;
    
    else {
      if ( cnt == M )
        result = mid;
      en = mid - 1;
    }
  }
  
  cout << result;
}
