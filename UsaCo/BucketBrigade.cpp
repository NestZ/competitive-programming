/*
ID: nestz
LANG: C++14
TASK: buckets
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("buckets.out", "w", stdout);
	freopen("buckets.in", "r", stdin);

	vector<vector<char>> arr(10, vector<char>(10));
	queue<pair<pair<int, int>, int>> q;
	vector<vector<bool>> vis(10, vector<bool>(10, false));
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'B'){
				q.push({{i, j}, 0});
				vis[i][j] = true;
			}
			else if(arr[i][j] == 'R')vis[i][j] = true;
		}
	}
	auto valid = [](int x, int y) -> bool {
		if(x < 0 || y < 0 || x >= 10 || y >= 10)return false;
		return true;
	};
	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(arr[cx][cy] == 'L'){
			cout << d - 1 << endl;
			return 0;
		}
		for(int i = 0;i < 4;i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(!valid(nx, ny) || vis[nx][ny])continue;
			vis[nx][ny] = true;
			q.push({{nx, ny}, d + 1});
		}
	}
}
