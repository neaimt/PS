#include <iostream>
#include <algorithm>
using namespace std;
string str;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while ( 1 ) {
        getline(cin, str);
        if ( str[0] == '#' )
            return 0;

        int i = str.length();
        int cnt = 0;
        for ( int j = 0; j < i; j++ )
            if ( str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U')
                cnt++;

        cout << cnt << '\n';
    }
}