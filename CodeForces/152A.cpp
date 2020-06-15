#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;cin >> c;
			arr[i][j] = c - '0';
		}
	}
	set<int> ans;
	vector<int> mxr(m, 0);
	for(int i = 0;i < m;i++){
		int mx = 0;
		for(int j = 0;j < n;j++){
			if(arr[j][i] > arr[mx][i])mx = j;
		}
		mxr[i] = arr[mx][i];
	}
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(arr[j][i] == mxr[i])ans.insert(j);
		}
	}
	cout << ans.size();
}
