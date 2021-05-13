/*
ID: nestz
LANG: C++14
TASK: cowsignal
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("cowsignal.out", "w", stdout);
	freopen("cowsignal.in", "r", stdin);

	int n, m, k;cin >> n >> m >> k;
	vector<vector<char>> arr(n, vector<char>(m));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	vector<vector<char>> ans;
	for(int i = 0;i < n;i++){
		vector<char> cur;
		for(int j = 0;j < m;j++){
			for(int l = 0;l < k;l++){
				cur.push_back(arr[i][j]);
			}
		}
		for(int j = 0;j < k;j++){
			ans.push_back(cur);
		}
	}
	for(auto v : ans){
		for(auto c : v)cout << c;
		cout << endl;
	}
}
