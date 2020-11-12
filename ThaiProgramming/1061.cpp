#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mxN = 25;
int n;
vector<vector<int>> board(mxN, vector<int>(mxN));
vector<vector<bool>> vis(mxN, vector<bool>(mxN, false));
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

bool valid(int row, int col){
	if(row < 0 || col < 0 || row >= n || col >= n)return false;
	if(board[row][col] == 100)return false;
	return true;
}

int dfs(int row, int col){
	vis[row][col] = true;
	int mx = board[row][col];
	for(int i = 0;i < 4;i++){
		if(valid(row + x[i], col + y[i]) &&
				board[row][col] < board[row + x[i]][col + y[i]] &&
				!vis[row + x[i]][col + y[i]])
			mx = max(mx, dfs(row + x[i], col + y[i]));
	}
	return mx;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int scol, srow;cin >> scol >> srow;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> board[i][j];
	cout << dfs(srow - 1, scol - 1) << endl;
}
