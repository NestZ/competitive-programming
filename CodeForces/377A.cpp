#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<char>> arr(505, vector<char>(505));
vector<vector<bool>> b(505, vector<bool>(505, true));
int n, m, k;
int lim;
int cnt = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int curr = 0;

void dfs(int i, int j){
	curr++;
	if(curr > lim)return;
	b[i][j] = false;
	for(int l = 0;l < 4;l++){
		int r = i + dy[l];
		int c = j + dx[l];
		if(r >= n || r < 0 || c >= m || c < 0 || arr[r][c] == '#' || !b[r][c])continue;
		dfs(r, c);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
			if(arr[i][j] == '.')cnt++;
		}
	}
	lim = cnt - k;
	bool flag = true;
	for(int i = 0;i < n;i++){
		if(!flag)break;
		for(int j = 0;j < m;j++){
			if(arr[i][j] == '.'){
				dfs(i, j);
				flag = false;
				break;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j] == '.' && b[i][j])cout << 'X';
			else cout << arr[i][j];
		}
		cout << endl;
	}
}
