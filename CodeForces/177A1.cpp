#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans += arr[i][i];
		ans += arr[i][n - i - 1];
		ans += arr[n / 2][i];
		ans += arr[i][n / 2];
	}
	cout << ans - (3 * arr[n / 2][n / 2]);
}
