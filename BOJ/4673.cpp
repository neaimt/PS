#include <iostream>
using namespace std;
int arr[10001];
int No_self_num(int i) {
    int sum;
    sum = i;

    if ( i < 10 )
        sum += i;
    else if ( i < 100 )
        sum = sum + i / 10 % 10 + i % 10;
    else if ( i < 1000 )
        sum = sum + i / 100 % 10 + i / 10 % 10 + i % 10;
    else if ( i < 10000 )
        sum = sum + i / 1000 % 10 + i / 100 % 10 + i / 10 % 10 + i % 10;
    else if ( i == 10000 )
        sum += 1;
    
    if ( sum <= 10000 ) return sum;
    else return -1;
}     
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int res;

    for ( int i = 1; i <= 10000; i++ ) {
        res = No_self_num(i);
        if ( res != -1 )
            arr[res] = 1;
    } 

    for ( int i = 1; i <= 10000; i++ ){
        if ( !arr[i] )
            cout << i << '\n';
    }
}