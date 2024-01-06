#include <iostream>
using namespace std;
string str;
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    cin >> N;

    cout << str[N-1];
}