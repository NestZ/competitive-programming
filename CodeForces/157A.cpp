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
		for(int j = 0;j < n;j++){
			int scol = 0;
			int srow = 0;
			for(int k = 0;k < n;k++)srow += arr[i][k];
			for(int k = 0;k < n;k++)scol += arr[k][j];
			if(scol > srow)ans++;
		}
	}
	cout << ans;
}
