#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
//up down left right
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
int n, m;

bool valid(int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int ans = 0;
	vector<vector<char>> arr(n, vector<char>(m));
	vector<vector<bool>> vis(n, vector<bool>(m,false));
	queue<tuple<int, int, int>> q;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
			if(arr[i][j] == '#'){
				q.emplace(i, j, 0);
				vis[i][j] = true;
			}
		}
	}
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		int cur_i = get<0>(p);
		int cur_j = get<1>(p);
		int cur_d = get<2>(p);
		ans = max(ans, cur_d);
		for(int i = 0;i < 4;i++){
			if(valid(cur_i + x[i], cur_j + y[i]) &&
					!vis[cur_i + x[i]][cur_j + y[i]]){
				vis[cur_i + x[i]][cur_j + y[i]] = true;
				q.emplace(cur_i + x[i], cur_j + y[i], cur_d + 1);
			}
		}
	}
	cout << ans << endl;
}
