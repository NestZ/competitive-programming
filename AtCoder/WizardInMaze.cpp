#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
int n, m;
//up down left right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<char>> arr(1001, vector<char>(1001));
vector<vector<bool>> vis(1001, vector<bool>(1001, false));
vector<vector<int>> cmp(1001, vector<int>(1001, -1));

bool valid(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= m)return false;
	if(vis[x][y])return false;
	if(arr[x][y] == '#')return false;
	return true;
}

void fl(int x, int y, int num){
	vis[x][y] = true;
	cmp[x][y] = num;
	for(int i = 0;i < 4;i++){
		if(valid(x + dx[i], y + dy[i]))
			fl(x + dx[i], y + dy[i], num);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int sn, sm;cin >> sn >> sm;
	sn--;sm--;
	int tn, tm;cin >> tn >> tm;
	tn--;tm--;
	int cnt = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(valid(i, j)){
				fl(i, j, cnt);
				cnt++;
			}
		}
	}
	vector<unordered_set<int>> g(cnt);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j] == '#')continue;
			for(int k = i - 2;k <= i + 2;k++){
				for(int l = j - 2;l <= j + 2;l++){
					if(k == i && l == j)continue;
					if(k < 0 || l < 0 || k >= n || l >= m)continue;
					if(arr[k][l] == '#' || cmp[i][j] == cmp[k][l])continue;
					g[cmp[i][j]].insert(cmp[k][l]);
				}
			}
		}
	}
	int start = cmp[sn][sm];
	int end = cmp[tn][tm];
	if(start == end)cout << 0 << endl;
	else{
		queue<pair<int, int>> q;
		vector<bool> vis2(cnt, false);
		vis2[start] = true;
		q.push({start, 0});
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			if(cur.first == end){
				cout << cur.second << endl;
				return 0;
			}
			for(auto adj : g[cur.first]){
				if(!vis2[adj]){
					q.push({adj, cur.second + 1});
					vis2[adj] = true;
				}
			}
		}
		cout << -1 << endl;
	}
}
