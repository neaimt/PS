#include <iostream>
#include <algorithm>
using namespace std;
string N, res, Res;
int isused[10];
int res_int, Res_int=999999;
void func(int cnt) {
    if ( cnt == N.length() ) {
        res_int = stoi(res);

        if ( res_int > stoi(N) && res_int < Res_int )
            Res_int = res_int;

        return;
    }

    for ( int i = 0; i < N.length(); i++ ) {
        if ( !isused[i] ) {
            isused[i] = 1;
            res[cnt] = N[i];
            func(cnt+1);
            res[cnt] = '\n';
            isused[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    res_int = stoi(N);
    func(0);
    if ( Res_int == 999999 )
        cout << 0;
    else 
        cout << Res_int;
}