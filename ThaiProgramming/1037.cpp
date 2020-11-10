#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mxN = 55;
int r, c;
vector<vector<char>> board(mxN, vector<char>(mxN));
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

bool valid(int cur_r, int cur_c){
	if(cur_r < 0 || cur_c < 0 || cur_r >= r || cur_c >= c)return false;
	if(board[cur_r][cur_c] == 'X')return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	pair<int, int> start_dir;
	vector<vector<int>> water(r, vector<int>(c, 2e9));
	vector<vector<bool>> water_vis(r, vector<bool>(c, false));
	queue<tuple<int, int, int>> water_bfs;
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			cin >> board[i][j];
			if(board[i][j] == '*'){
				water_bfs.push(make_tuple(i, j, 0));
				water_vis[i][j] = true;
			}
			else if(board[i][j] == 'S')start_dir = make_pair(i, j);
		}
	}
	while(!water_bfs.empty()){
		tuple<int, int, int> cur = water_bfs.front();
		int cur_r = get<0>(cur);
		int cur_c = get<1>(cur);
		int cur_dis = get<2>(cur);
		water_bfs.pop();
		water[cur_r][cur_c] = cur_dis;
		for(int i = 0;i < 4;i++){
			if(valid(cur_r + x[i], cur_c + y[i]) && !water_vis[cur_r + x[i]][cur_c + y[i]] && board[cur_r + x[i]][cur_c + y[i]] != 'D'){
				water_vis[cur_r + x[i]][cur_c + y[i]] = true;
				water_bfs.push(make_tuple(cur_r + x[i], cur_c + y[i], cur_dis + 1));
			}
		}
	}
	queue<tuple<int, int, int>> bfs;
	vector<vector<bool>> vis(r, vector<bool>(c, false));
	bfs.push(make_tuple(start_dir.first, start_dir.second, 0));
	vis[start_dir.first][start_dir.second] = true;
	while(!bfs.empty()){
		tuple<int, int, int> cur = bfs.front();
		int cur_r = get<0>(cur);
		int cur_c = get<1>(cur);
		int cur_dis = get<2>(cur);
		bfs.pop();
		if(board[cur_r][cur_c] == 'D')return cout << cur_dis, 0;
		for(int i = 0;i < 4;i++){
			if(valid(cur_r + x[i], cur_c + y[i]) && !vis[cur_r + x[i]][cur_c + y[i]] && cur_dis + 1 < water[cur_r + x[i]][cur_c + y[i]]){
				vis[cur_r + x[i]][cur_c + y[i]] = true;
				bfs.push(make_tuple(cur_r + x[i], cur_c + y[i], cur_dis + 1));
			}
		}
	}
	cout << "KAKTUS";
}
