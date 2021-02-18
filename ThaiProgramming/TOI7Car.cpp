#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
int m, n, t;
vector<int> ans;
vector<vector<bool>> vis(101, vector<bool>(41, false));

bool dfs(int cur_i, int cur_j){
	if(int(ans.size()) == t)return true;
	if(cur_i >= 0)vis[cur_i][cur_j] = true;
	//down 3
	if(!vis[cur_i + 1][cur_j]){
		ans.push_back(3);
		if(dfs(cur_i + 1, cur_j))return true;
		ans.pop_back();
	}
	//left 1
	if(cur_j - 1 >= 0 && !vis[cur_i + 1][cur_j - 1]){
		ans.push_back(1);
		if(dfs(cur_i + 1, cur_j - 1))return true;
		ans.pop_back();
	}
	//right 2
	if(cur_j + 1 < m && !vis[cur_i + 1][cur_j + 1]){
		ans.push_back(2);
		if(dfs(cur_i + 1, cur_j + 1))return true;
		ans.pop_back();
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> t;
	for(int i = 0;i < t;i++){
		for(int j = 0;j < m;j++){
			int b;cin >> b;
			b == 1 ? vis[i][j] = true : vis[i][j] = false;
		}
	}
	dfs(-1, n - 1);
	assert(int(ans.size()) != 0);
	for(int i : ans)
		cout << i << endl;
}
