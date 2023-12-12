#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;
char arr[10];
vector<string> r;
string num;
int isused[10], res[11];
void func(int arr_cnt, int res_cnt) {
  if ( res_cnt == N+1 ) {
    num = "\0";
    for ( int i = 0; i < N+1; i++ )
      num += to_string(res[i]);
    r.push_back(num);
    return;
  }

  for ( int i = 0; i < 10; i++ ) {
    if ( !isused[i] && res_cnt == 0 ) {
      isused[i] = 1;
      res[res_cnt] = i;
      func(arr_cnt, res_cnt+1);
      isused[i] = 0;
    }

    else if ( !isused[i] && res_cnt != 0 ) {
      if ( ((arr[arr_cnt] == '<') && (res[res_cnt-1] < i)) || ((arr[arr_cnt] == '>') && (res[res_cnt-1] > i)) ) {
        res[res_cnt] = i;
        isused[i] = 1;
        func(arr_cnt+1, res_cnt+1);
        isused[i] = 0;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  
  for ( int i = 0; i < N; i++ ) cin >> arr[i];
  func(0, 0);
  sort(r.begin(), r.end());
  cout << r[r.size()-1] << '\n' << r[0];
}