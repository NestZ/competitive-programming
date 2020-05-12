#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, m;
vector<vector<int>> a(50, vector<int>(50));
vector<vector<int>> b(50, vector<int>(50, 0));

bool con(int r, int c){
	if(a[r][c] == 0)return false;
	if(c + 1 < m){
		if(a[r][c + 1] == 0)return false;
	}
	else return false;
	if(r + 1 < n){
		if(a[r + 1][c] == 0)return false;
	}
	else return false;
	if(r + 1 < n && c + 1 < m){
		if(a[r + 1][c + 1] == 0)return false;
	}
	else return false;
	b[r][c] = 1;
	b[r + 1][c] = 1;
	b[r][c + 1] = 1;
	b[r + 1][c + 1] = 1;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> a[i][j];
	vector<pair<int, int>> ans;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(con(i, j)){
				ans.push_back({i + 1, j + 1});
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(a[i][j] != b[i][j])return cout << -1, 0;
			//cout << b[i][j];
		}
		//cout << endl;
	}
	cout << ans.size() << endl;
	for(pair<int, int> p : ans)cout << p.first << ' ' << p.second << endl;
}
