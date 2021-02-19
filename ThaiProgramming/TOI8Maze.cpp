#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int n, m;
//up down left right
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

bool valid(int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int si, sj;cin >> si >> sj;
	int ei, ej;cin >> ei >> ej;
	si--;sj--;ei--;ej--;
	int mnd = INT_MAX;
	int cnt = 0;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<pair<int, int>> wall;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
		}
	}
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	queue<tuple<int, int, int>> q;
	q.emplace(si, sj, 1);
	vis[si][sj] = true;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int cur_i = get<0>(cur);
		int cur_j = get<1>(cur);
		int cur_d = get<2>(cur);
		for(int i = 0;i < 4;i++){
			if(!valid(cur_i + x[i], cur_j + y[i]))continue;
			if(vis[cur_i + x[i]][cur_j + y[i]])continue;
			vis[cur_i + x[i]][cur_j + y[i]] = true;
			if(arr[cur_i + x[i]][cur_j + y[i]] == 0)
				wall.emplace_back(cur_i + x[i], cur_j + y[i]);
			else q.emplace(cur_i + x[i], cur_j + y[i], cur_d + 1);
		}
	}
	for(auto p : wall){
		fill(vis.begin(), vis.end(), vector<bool>(m, false));
		q = queue<tuple<int, int, int>>();
		q.emplace(si, sj, 1);
		vis[si][sj] = true;
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			int cur_i = get<0>(cur);
			int cur_j = get<1>(cur);
			int cur_d = get<2>(cur);
			if(cur_i == ei && cur_j == ej){
				mnd = min(mnd, cur_d);
				cnt++;
				break;
			}
			for(int i = 0;i < 4;i++){
				if(!valid(cur_i + x[i], cur_j + y[i]))continue;
				if(vis[cur_i + x[i]][cur_j + y[i]])continue;
				if(arr[cur_i + x[i]][cur_j + y[i]] == 1 ||
						(cur_i + x[i] == p.first && cur_j + y[i] == p.second)){
					vis[cur_i + x[i]][cur_j + y[i]] = true;
					q.emplace(cur_i + x[i], cur_j + y[i], cur_d + 1);
				}
			}
		}
	}
	cout << cnt << endl << mnd << endl;
}
