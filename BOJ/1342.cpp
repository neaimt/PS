#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string str;
int N, Res;
int isused[11];
string res;
vector<string> V;
void func(int cnt) {
  if ( cnt == N ) {
    string result = "\0";
    for ( int i = 0; i < N; i++ )
      result += res[i];
      
    V.push_back(result);
    Res++;
    return;
  }

  for ( int i = 0; i < N; i++ ) {
    if ( !isused[i] && res[cnt-1] != str[i] ) {
      res[cnt] = str[i];
      isused[i] = 1;
      func(cnt+1);
      isused[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> str;
  N = str.size();
  func(0);

  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());

  cout << V.size();
}