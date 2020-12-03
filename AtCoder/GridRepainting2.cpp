#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, m;
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
vector<vector<char>> board(51, vector<char>(51));

bool valid(int cur_i, int cur_j){
	if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m)
		return false;
	if(board[cur_i][cur_j] == '#')return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> board[i][j];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(board[i][j] != '#')continue;
			bool can = false;
			for(int k = 0;k < 4;k++){
				can = can || valid(i + x[k], j + y[k]);	
			}
			if(!can)return cout << "No" << endl, 0;
		}
	}
	cout << "Yes" << endl;
}
