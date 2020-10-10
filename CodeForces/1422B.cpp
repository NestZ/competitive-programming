#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		vector<vector<ll>> arr(n, vector<ll>(m));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				cin >> arr[i][j];
		ll ans = 0;
		for(int i = 0;i < n / 2;i++){
			for(int j = 0;j < m / 2;j++){
				vector<int> temp;
				temp.push_back(arr[n - i - 1][j]);
				temp.push_back(arr[i][m - j - 1]);
				temp.push_back(arr[i][j]);
				temp.push_back(arr[n - i - 1][m - j - 1]);
				sort(temp.begin(), temp.end());
				int med = (temp[1] + temp[2]) / 2;
				ans += abs(arr[i][j] - med) + abs(arr[n - i - 1][j] - med) + abs(arr[i][m - j - 1] - med) + abs(arr[n - i - 1][m - j - 1] - med);
			}
		}
		if(n & 1){
			int r = n / 2;
			for(int i = 0;i < m / 2;i++){
				ans += abs(arr[r][i] - arr[r][m - i - 1]);
			}
		}
		if(m & 1){
			int c = m / 2;
			for(int i = 0;i < n / 2;i++){
				ans += abs(arr[i][c] - arr[n - i - 1][c]);
			}
		}
		cout << ans << endl;
	}
}
