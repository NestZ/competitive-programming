#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
vector<pair<int, int>> pos(4);
bool valid(int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= n)return false;
	for(int p = 0;p < 4;p++){
		if(i == pos[p].first && j == pos[p].second)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;cin >> n >> k;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<vector<char>> move(4);
	vector<int> cnt(4, 0);
	arr[0][n - 1] = 1;
	arr[n - 1][n - 1] = 2;
	arr[n - 1][0] = 3;
	arr[0][0] = 4;
	pos[0] = make_pair(0, n - 1);
	pos[1] = make_pair(n - 1, n - 1);
	pos[2] = make_pair(n - 1, 0);
	pos[3] = make_pair(0, 0);
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < k;j++){
			char c;cin >> c;
			move[i].push_back(c);
		}
	}
	for(int i = 0;i < k;i++){
		for(int j = 0;j < 4;j++){
			char cur_move = move[j][i];
			pair<int, int> cur_pos = pos[j];
			if(cur_move == 'N'){
				if(valid(cur_pos.first - 1, cur_pos.second)){
					pos[j] = make_pair(cur_pos.first - 1, cur_pos.second);
					arr[cur_pos.first - 1][cur_pos.second] = j + 1;
				}
			}
			else if(cur_move == 'S'){
				if(valid(cur_pos.first + 1, cur_pos.second)){
					pos[j] = make_pair(cur_pos.first + 1, cur_pos.second);
					arr[cur_pos.first + 1][cur_pos.second] = j + 1;
				}
			}
			else if(cur_move == 'W'){
				if(valid(cur_pos.first, cur_pos.second - 1)){
					pos[j] = make_pair(cur_pos.first, cur_pos.second - 1);
					arr[cur_pos.first][cur_pos.second - 1] = j + 1;
				}
			}
			else{
				if(valid(cur_pos.first, cur_pos.second + 1)){
					pos[j] = make_pair(cur_pos.first, cur_pos.second + 1);
					arr[cur_pos.first][cur_pos.second + 1] = j + 1;
				}
			}
		}
	}
	bool h_win = true;
	int mx = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[i][j] == 0){
				h_win = false;
				continue;
			}
			cnt[arr[i][j] - 1]++;
			mx = max(mx, cnt[arr[i][j] - 1]);
		}
	}
	vector<int> win;
	for(int i = 0;i < 4;i++){
		if(cnt[i] == mx)win.push_back(i + 1);
	}
	if(h_win){
		cout << win.size() << ' ' << mx << endl;
		for(int w : win)cout << w << endl;
	}
	else cout << "No" << endl;
}
