#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		vector<vector<char>> board(n, vector<char>(m));
		vector<vector<int>> mx_left(n, vector<int>(m));
		vector<vector<int>> mx_right(n, vector<int>(m));
		vector<vector<int>> mx_up(n, vector<int>(m));
		vector<vector<int>> mx_down(n, vector<int>(m));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				cin >> board[i][j];
		//fill mx left, mx right
		for(int i = 0;i < n;i++){
			int cur = 0;
			for(int j = 0;j < m;j++){
				if(board[i][j] == '0')cur = 0;
				else mx_left[i][j] = cur++;
			}
			cur = 0;
			for(int j = m - 1;j >= 0;j--){
				if(board[i][j] == '0')cur = 0;
				else mx_right[i][j] = cur++;
			}
		}
		//fill mx up, mx down
		for(int i = 0;i < m;i++){
			int cur = 0;
			for(int j = 0;j < n;j++){
				if(board[j][i] == '0')cur = 0;
				else mx_up[j][i] = cur++;
			}
			cur = 0;
			for(int j = n - 1;j >= 0;j--){
				if(board[j][i] == '0')cur = 0;
				else mx_down[j][i] = cur++;
			}
		}
		//calculate answer
		int ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(board[i][j] == '0')continue;
				int vertical = 1 + mx_left[i][j] + mx_right[i][j];
				int horizon = 1 + mx_up[i][j] + mx_down[i][j];
				int up_left = 1 + mx_up[i][j] + mx_left[i][j];
				int up_right = 1 + mx_up[i][j] + mx_right[i][j];
				int down_left = 1 + mx_down[i][j] + mx_left[i][j];
				int down_right = 1 + mx_down[i][j] + mx_right[i][j];
				int cur_mx = max(vertical, max(horizon, max(up_left, max(up_right, max(down_left, down_right)))));
				ans = max(ans, cur_mx);
			}
		}
		cout << ans << endl;
	}
}
