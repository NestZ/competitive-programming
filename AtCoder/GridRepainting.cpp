#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int h, w;
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

bool valid(int cur_i, int cur_j){
	if(cur_i < 0 || cur_j < 0 || cur_i >= h || cur_j >= w)
		return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;
	int cnt_w = 0;
	int sp = INT_MAX;
	vector<vector<char>> arr(h, vector<char>(w));
	vector<vector<bool>> vis(h, vector<bool>(w, false));
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cin >> arr[i][j];
			if(arr[i][j] == '.')cnt_w++;
		}
	}
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 1);
	while(!q.empty()){
		auto cur = q.front();q.pop();
		int cur_d = get<2>(cur);
		int cur_i = get<0>(cur);
		int cur_j = get<1>(cur);
		if(cur_i == h - 1 && cur_j == w - 1){
			sp = cur_d;
			break;
		}
		for(int i = 0;i < 4;i++){
			if(valid(cur_i + x[i], cur_j + y[i]) &&
					!vis[cur_i + x[i]][cur_j + y[i]] &&
					arr[cur_i + x[i]][cur_j + y[i]] == '.'){
				vis[cur_i + x[i]][cur_j + y[i]] = true;
				q.emplace(cur_i + x[i], cur_j + y[i], cur_d + 1);
			}
		}
	}
	if(sp == INT_MAX)cout << -1;
	else cout << cnt_w - sp;
	cout << endl;
}
