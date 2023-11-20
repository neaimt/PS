#include <iostream>
#include <algorithm>
using namespace std;
int arr[3][123456];
long long curH, maxH, atkH1, atkH, result=0;
long long a, h, t, N;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> atkH1;
  for ( long long i = 0; i < N; i++ ) cin >> arr[0][i] >> arr[1][i] >> arr[2][i];

  long long st = 1, en = 123456000000000000LL, c1;
  while ( st <= en ) {
    long long mid = ( st + en ) / 2;

    maxH = curH = mid, atkH = atkH1;
    int ck=0;
    for ( long long i = 0; i < N; i++ ) {
      if ( arr[0][i] == 1 ) {
        if ( arr[2][i] % atkH ) curH -= ( arr[2][i] / atkH ) * arr[1][i];
        else curH -= ( arr[2][i] / atkH - 1 ) * arr[1][i]; // 용사가 먼저 공격해서 몬스터를 잡기 떄문에 N-1번의 데미지를 입음
        
        if ( curH <= 0 ) {
          ck = 1;
          break;
        }
      }
      else if ( arr[0][i] == 2 ) {
        atkH += arr[1][i];
        if ( curH + arr[2][i] >= maxH )
          curH = maxH;
        else 
          curH += arr[2][i];
      }
    }

    if ( ck == 1 )
      st = mid + 1;
    else {
      result = mid;
      en = mid - 1;
    }
  }
  cout << result;
}
/*
용사의 최대 체력
용사의 현재 체력
용사의 공격력

몬스터의 공격력만큼 용사의 생명력을 깎음

포션 생명력이 회복, 공격력도 증가
수련 최대 생명력을 늘릴 수 있음
공주를 구하기 위한 최소 생명력을 구하는 문제

1인 경우, 공격력이 a이고 생명력이 h인 몬스터
2인 경우, 용사의 공격력을 a만큼 증가, 생명력을 h만큼 회복
*/