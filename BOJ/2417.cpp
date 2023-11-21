#include <iostream>
#include <cmath>
using namespace std;
long long N;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  long long q = sqrt(N);
  if ( (q*q) < N )
    q++;
  
  cout << q;

}