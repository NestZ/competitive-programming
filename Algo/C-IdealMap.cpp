#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, m;
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
vector<vector<char>> board(110, vector<char>(110));
vector<vector<bool>> vis(110, vector<bool>(110, false));

bool valid(int cur_i, int cur_j){
	if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m)return false;
	if(board[cur_i][cur_j] == '-')return false;
	return true;
}

bool valid_build(int cur_i, int cur_j, char cur){
	if(!valid(cur_i, cur_j))return false;
	for(int i = 0;i < 4;i++){
		int new_i = cur_i + x[i];
		int new_j = cur_j + y[i];
		if(!valid(new_i, new_j))continue;
		if(board[new_i][new_j] == cur)return false;
	}
	return true;
}

void dfs(int cur_i, int cur_j){
	vis[cur_i][cur_j] = true;
	if(valid_build(cur_i, cur_j, 'B'))
		board[cur_i][cur_j] = 'B';
	else if(valid_build(cur_i, cur_j, 'W'))
		board[cur_i][cur_j] = 'W';
	for(int i = 0;i < 4;i++){
		int new_i = cur_i + x[i];
		int new_j = cur_j + y[i];
		if(valid(new_i, new_j) && !vis[new_i][new_j])
			dfs(new_i, new_j);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!vis[i][j])
				dfs(i, j);
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}
