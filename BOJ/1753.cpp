#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[105][105];
vector<int> vertex[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; 
    for ( int i = 1; i <= N; i++ )
        for ( int j = 1; j <= N; j++ ) {
            cin >> arr[i][j];
            if ( arr[i][j] == 1 )
                vertex[i].push_back(j);
        }
    
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < vertex[i].size(); j++ ) {
            
        }
    }

}