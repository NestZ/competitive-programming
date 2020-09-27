#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		vector<vector<char>> arr(n, vector<char>(m));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for(int i = 0;i < m - 1;i++){
			if(arr[n - 1][i] == 'D')ans++;
		}
		for(int i = 0;i < n - 1;i++){
			if(arr[i][m - 1] == 'R')ans++;
		}
		cout << ans << endl;
	}
}
