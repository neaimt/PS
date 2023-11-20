#include <iostream>
#include <algorithm>
using namespace std;
int N, M, L;
int arr[52];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> L;
  for ( int i = 0; i < N; i++ ) cin >> arr[i];
  sort(arr, arr+N);
  arr[N] = L;
  int st = 1, en = L-1, result=0;
  while ( st <= en ) {
    int mid = ( st + en ) / 2;

    int cnt = 0, proper_distance = mid;
    for ( int i = 0; i <= N; i++ ) {
      if ( arr[i] > proper_distance ) {
        int num = ( arr[i]-proper_distance ) / mid;
        
        if ( num*mid < arr[i]-proper_distance )
          num++;

        proper_distance += mid*num;
        cnt += num;
  
        if ( proper_distance >= L ) break;
      }
      
      proper_distance = arr[i] + mid;
    }
    
    if ( cnt <= M ) {
      result = mid;
      en = mid - 1;
    }
    else 
      st = mid + 1;
  }
  cout << result;
}

/*
배열 오름차순 정리
휴게소가 없는 구간을 이분탐색함
구간에서 mid*2 만큼 이동 후 휴게소 없으면 짓음
*/