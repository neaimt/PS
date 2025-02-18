// 야매 연결리스트
#include <iostream>

using namespace std;

const int MX = 6000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused=1, M, cursor=0;
string str;

void insert(int addr, char ch);
void erase(int addr);
void traversal();

int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    cin >> str;
    for ( auto c : str ) {
        insert(cursor, c);
        cursor++;
    }

    cin >> M;
    for ( int i = 0; i < M; i++ ) {
        char cmd;
        cin >> cmd;

        if ( cmd == 'L' ) {
            if ( pre[cursor] != -1 ) 
                cursor = pre[cursor];
        } else if ( cmd == 'D' ) {
            if ( nxt[cursor] != -1 ) 
                cursor = nxt[cursor];
        } else if ( cmd == 'B' ) {
            if ( cursor != 0 ) { 
                erase(cursor);
                cursor = pre[cursor];
            }
        } else if ( cmd == 'P' ) {
            char c_ch;
            cin >> c_ch;
            insert(cursor, c_ch);
            cursor = nxt[cursor];
        }
    }

    traversal();
}

void insert(int addr, char ch) {
    dat[unused] = ch;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    if ( nxt[addr] != -1 ) pre[nxt[addr]] = unused;
    nxt[addr] = unused;

    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if ( nxt[addr] != -1 ) pre[nxt[addr]] = pre[addr];
}

void traversal() {
    int cur = nxt[0];
    while( cur != -1 ) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

// STL 리스트 사용
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;
    string init;

    cin >> init;
    for ( auto c : init ) L.push_back(c);
    auto cursor = L.end();

    int M;
    cin >> M;
    while(M--) {
        char cmd;
        cin >> cmd;

        if ( cmd == 'L' ) {
            if ( cursor != L.begin() ) cursor--; 
        } else if ( cmd == 'D' ) {
            if ( cursor != L.end() ) cursor++;
        } else if ( cmd == 'B' ) {
            if ( cursor != L.begin() ) {
                cursor--;
                cursor = L.erase(cursor);
            }
        } else if ( cmd == 'P' ) {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
    }

    for ( auto c : L )
        cout << c;
}