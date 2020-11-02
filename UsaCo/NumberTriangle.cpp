/*
ID: nestz
LANG: C++14
TASK: numtri
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
vector<vector<int>> arr(1000, vector<int>(1000));
vector<vector<int>> dp(1000, vector<int>(1000, -1));

int dfs(int i, int j){
	if(i == n - 1)return dp[i][j] = arr[i][j];
	if(dp[i][j] != -1)return dp[i][j];
	return dp[i][j] = arr[i][j] + max(dfs(i + 1, j), dfs(i + 1, j + 1));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("numtri.out", "w", stdout);
	freopen("numtri.in", "r", stdin);
	
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= i;j++){
			cin >> arr[i][j];
		}
	}
	cout << dfs(0, 0) << endl;
}
