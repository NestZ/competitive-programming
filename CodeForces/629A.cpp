#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	int ans = 0;
	for(int i = 0;i < n;i++){
		int cnt = 0;
		for(int j = 0;j < n;j++){
			if(arr[i][j] == 'C')cnt++;
		}
		ans += cnt * (cnt - 1) / 2;
	}
	for(int i = 0;i < n;i++){
		int cnt = 0;
		for(int j = 0;j < n;j++){
			if(arr[j][i] == 'C')cnt++;
		}
		ans += cnt * (cnt - 1) / 2;
	}
	cout << ans;
}
