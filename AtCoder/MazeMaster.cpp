#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
int h, w;

bool valid(int i, int j){
	if(i < 0 || j < 0 || i >= h || j >= w)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;
	vector<vector<char>> arr(h, vector<char>(w));
	for(int i = 0;i < h;i++)
		for(int j = 0;j < w;j++)
			cin >> arr[i][j];
	int ans = 0;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(arr[i][j] == '#')continue;
			queue<tuple<int, int, int>> q;
			vector<vector<bool>> vis(h, vector<bool>(w, false));
			q.emplace(i, j, 0);
			vis[i][j] = true;
			while(!q.empty()){
				auto cur = q.front();q.pop();
				int dis = get<2>(cur);
				int cur_i = get<0>(cur);
				int cur_j = get<1>(cur);
				ans = max(ans, dis);
				for(int k = 0;k < 4;k++){
					if(valid(cur_i + x[k], cur_j + y[k]) && arr[cur_i + x[k]][cur_j + y[k]] != '#' && !vis[cur_i + x[k]][cur_j + y[k]]){
						vis[cur_i + x[k]][cur_j + y[k]] = true;
						q.emplace(cur_i + x[k], cur_j + y[k], dis + 1);
					}
				}
			}
		}
	}
	cout << ans << endl;
}
