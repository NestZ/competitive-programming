#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int INF = 1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	vector<vector<char>> sewer(n, vector<char>(m));
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<vector<int>> dis(n, vector<int>(m, INF));
	queue<tuple<int, int, int>> q;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> sewer[i][j];
	q.emplace(0, 0, 0);
	vis[0][0] = true;
	dis[0][0] = 0;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int cur_dis = get<2>(cur);
		int cur_i = get<0>(cur);
		int cur_j = get<1>(cur);
		if(cur_j + 1 < m && (sewer[cur_i][cur_j] == 'B' || sewer[cur_i][cur_j] == 'R')){
			if(!vis[cur_i][cur_j + 1]){
				q.emplace(cur_i, cur_j + 1, cur_dis + 1);
				vis[cur_i][cur_j + 1] = true;
				dis[cur_i][cur_j + 1] = cur_dis + 1;
			}
			else if(dis[cur_i][cur_j + 1] == cur_dis + 1){
				return cout << cur_dis + 2 << endl << cur_i + 1 << ' ' << cur_j + 2 << endl, 0;
			}
		}
		if(cur_i + 1 < n && (sewer[cur_i][cur_j] == 'B' || sewer[cur_i][cur_j] == 'D')){
			if(!vis[cur_i + 1][cur_j]){
				q.emplace(cur_i + 1, cur_j, cur_dis + 1);
				vis[cur_i + 1][cur_j] = true;
				dis[cur_i + 1][cur_j] = cur_dis + 1;
			}
			else if(dis[cur_i + 1][cur_j] == cur_dis + 1){
				return cout << cur_dis + 2 << endl << cur_i + 2 << ' ' << cur_j + 1 << endl, 0;
			}
		}
		if(cur_i - 1 >= 0 && (sewer[cur_i - 1][cur_j] == 'B' || sewer[cur_i - 1][cur_j] == 'D')){
			if(!vis[cur_i - 1][cur_j]){
				q.emplace(cur_i - 1, cur_j, cur_dis + 1);
				vis[cur_i - 1][cur_j] = true;
				dis[cur_i - 1][cur_j] = cur_dis + 1;
			}
			else if(dis[cur_i - 1][cur_j] == cur_dis + 1){
				return cout << cur_dis + 2 << endl << cur_i << ' ' << cur_j + 1 << endl, 0;
			}
		}
		if(cur_j - 1 >= 0 && (sewer[cur_i][cur_j - 1] == 'B' || sewer[cur_i][cur_j - 1] == 'R')){
			if(!vis[cur_i][cur_j - 1]){
				q.emplace(cur_i, cur_j - 1, cur_dis + 1);
				vis[cur_i][cur_j - 1] = true;
				dis[cur_i][cur_j - 1] = cur_dis + 1;
			}
			else if(dis[cur_i][cur_j - 1] == cur_dis + 1){
				return cout << cur_dis + 2 << endl << cur_i + 1 << ' ' << cur_j << endl, 0;
			}
		}
	}
}
