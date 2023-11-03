#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, s, ans = 0;
int arr[100001];
bool vis[100001];
void dfs( int cur ) {
	if ( cur < 1 || cur > n)
		return;
	vis[cur] = true;

	dfs( cur + arr[cur] );
	dfs( cur - arr[cur] );
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> s;
	dfs(s);

	for (int i = 1; i <= n; i++)
		if (vis[i])
			ans++;
	cout << ans;
}