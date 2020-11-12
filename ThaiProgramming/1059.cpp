#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<string>> board(3, vector<string>(3));
	board[0][0] = "";
	board[0][1] = "ABC";
	board[0][2] = "DEF";
	board[1][0] = "GHI";
	board[1][1] = "JKL";
	board[1][2] = "MNO";
	board[2][0] = "PQRS";
	board[2][1] = "TUV";
	board[2][2] = "WXYZ";
	int n;cin >> n;
	string ans = "";
	int init, cnt;cin >> init >> cnt;
	int init_row = (init - 1) / 3;
	int init_col = (init - 1) % 3;
	if(init != 1){
		ans += board[init_row][init_col][(cnt - 1) % board[init_row][init_col].size()];
	}
	for(int i = 0;i < n - 1;i++){
		int dif_col, dif_row, cur_cnt;cin >> dif_col >> dif_row >> cur_cnt;
		init_col += dif_col;
		init_row += dif_row;
		if(init_row == 0 && init_col == 0){
			ans = ans.substr(0, max(0, (int)ans.size() - cur_cnt));
		}
		else{
			ans += board[init_row][init_col][(cur_cnt - 1) % board[init_row][init_col].size()];
		}
	}
	if(ans.length() == 0)cout << "null";
	else cout << ans;
	cout << endl;
}
