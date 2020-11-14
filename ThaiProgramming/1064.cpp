#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mxN = 70;
int n, m;
vector<vector<char>> area(mxN, vector<char>(mxN));
vector<vector<int>> mark(mxN, vector<int>(mxN));
vector<vector<bool>> vis(mxN, vector<bool>(mxN, false));
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

bool valid(int cur_x, int cur_y){
	if(cur_x < 0 || cur_y < 0 || cur_x >= n || cur_y >= m)return false;
	if(area[cur_x][cur_y] == 'T' || area[cur_x][cur_y] == 'S')return false;
	return true;
}

void dfs(int cur_x, int cur_y, int cnt){
	vis[cur_x][cur_y] = true;
	mark[cur_x][cur_y] = cnt;
	for(int i = 0;i < 4;i++){
		if(valid(cur_x + x[i], cur_y + y[i]) && !vis[cur_x + x[i]][cur_y + y[i]])
			dfs(cur_x + x[i], cur_y + y[i], cnt);
	}
}

bool valid_build(int cur_i, int cur_j, int cur_k){
	for(int i = cur_i;i < cur_i + cur_k;i++){
		for(int j = cur_j;j < cur_j + cur_k;j++){
			if(i >= n || j >= m)return false;
			if(area[i][j] == 'T')return false;
		}
	}
	return true;
}

int cnt_fill(int cur_i, int cur_j, int cur_k){
	set<int> cnt;
	for(int i = cur_i;i < cur_i + cur_k;i++){
		for(int j = cur_j;j < cur_j + cur_k;j++){
			if(mark[i][j] != 0)cnt.insert(mark[i][j]);
		}
	}
	return cnt.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> area[i][j];
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(valid(i, j) && !vis[i][j])
				dfs(i, j, ++cnt);
		}
	}
	int ans = 0;
	int fill = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			for(int k = 1;k <= min(n, m);k++){
				int cur_area = k * k;
				if(valid_build(i, j, k)){
					if(cur_area > ans || (cur_area == ans && cnt_fill(i, j, k) < fill)){
						ans = cur_area;
						fill = cnt_fill(i, j, k);
					}
				}
			}
		}
	}
	cout << ans << ' ' << fill << endl;
}
