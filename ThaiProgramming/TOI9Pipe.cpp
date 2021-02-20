#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

int n, m;
unordered_set<int> su({11, 12, 21, 31});
unordered_set<int> sd({13, 14, 21, 31});
unordered_set<int> sl({11, 13, 22, 31});
unordered_set<int> sr({12, 14, 22, 31});
vector<int> ans;
vector<vector<int>> arr(310, vector<int>(310));

bool outside(int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m)return true;
	return false;
}

void dfs(int cur_i, int cur_j, char from, int dis){
	if(outside(cur_i, cur_j)){
		ans.push_back(dis - 1);
		return;
	}
	int t = arr[cur_i][cur_j];
	if(t != 31)arr[cur_i][cur_j] = 0;
	else{
		if(from == 'l' || from == 'r')arr[cur_i][cur_j] = 21;
		else if(from == 'u' || from == 'd')arr[cur_i][cur_j] = 22;
	}
	if(from == 'u'){
		if(t == 11)
			dfs(cur_i, cur_j - 1, 'r', dis + 1);
		else if(t == 12)
			dfs(cur_i, cur_j + 1, 'l', dis + 1);
		else if(t == 21 || t == 31)
			dfs(cur_i + 1, cur_j, 'u', dis + 1);
		else assert(false);
	}
	else if(from == 'd'){
		if(t == 13)
			dfs(cur_i, cur_j - 1, 'r', dis + 1);
		else if(t == 14)
			dfs(cur_i, cur_j + 1, 'l', dis + 1);
		else if(t == 21 || t == 31)
			dfs(cur_i - 1, cur_j, 'd', dis + 1);
		else assert(false);
	}
	else if(from == 'r'){
		if(t == 12)
			dfs(cur_i - 1, cur_j, 'd', dis + 1);
		else if(t == 14)
			dfs(cur_i + 1, cur_j, 'u', dis + 1);
		else if(t == 22 || t == 31)
			dfs(cur_i, cur_j - 1, 'r', dis + 1);
		else assert(false);
	}
	else if(from == 'l'){
		if(t == 11)
			dfs(cur_i - 1, cur_j, 'd', dis + 1);
		else if(t == 13)
			dfs(cur_i + 1, cur_j, 'u', dis + 1);
		else if(t == 22 || t == 31)
			dfs(cur_i, cur_j + 1, 'l', dis + 1);
		else assert(false);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	for(int i = 0;i < m;i++){
		int t = arr[0][i];
		if(su.count(t))
			dfs(0, i, 'u', 1);
	}
	for(int i = 0;i < m;i++){
		int t = arr[n - 1][i];
		if(sd.count(t))
			dfs(n - 1, i, 'd', 1);
	}
	for(int i = 0;i < n;i++){
		int t = arr[i][0];
		if(sl.count(t))
			dfs(i, 0, 'l', 1);
	}
	for(int i = 0;i < n;i++){
		int t = arr[i][m - 1];
		if(sr.count(t))
			dfs(i, m - 1, 'r', 1);
	}
	cout << ans.size() << endl;
	if(ans.size() > 0){
		for(int i : ans)cout << i << ' ';
		cout << endl;
	}
}
