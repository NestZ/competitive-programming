/*
ID: nestz
LANG: C++14
TASK: castle
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mxN = 50;
vector<vector<int>> arr(mxN, vector<int>(mxN));
vector<vector<bool>> vis(mxN, vector<bool>(mxN, false));
int n, m;

bool valid(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m)return false;
	return true;
}

//return each room's size
int dfs(int i, int j){
	vis[i][j] = true;
	int cnt = 1;
	//go left
	if(!(arr[i][j] & 1) && valid(i, j - 1) && !vis[i][j - 1])
		cnt += dfs(i, j - 1);
	//go up
	if(!(arr[i][j] & (1 << 1)) && valid(i - 1, j) && !vis[i - 1][j])
		cnt += dfs(i - 1, j);
	//go right
	if(!(arr[i][j] & (1 << 2)) && valid(i, j + 1) && !vis[i][j + 1])
		cnt += dfs(i, j + 1);
	//go down
	if(!(arr[i][j] & (1 << 3)) && valid(i + 1, j) && !vis[i + 1][j])
		cnt += dfs(i + 1, j);
	return cnt;
}

//return largest room's size
int find_largest(){
	int ans = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			vis[i][j] = false;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!vis[i][j])
				ans = max(ans, dfs(i, j));
		}
	}
	return ans;
}

void toggle_wall(int i, int j, int dir){
	//left
	if(dir & 1){
		arr[i][j] ^= 1;
		if(valid(i, j - 1))arr[i][j - 1] ^= (1 << 2);
	}
	//up
	else if(dir & (1 << 1)){
		arr[i][j] ^= (1 << 1);
		if(valid(i - 1, j))arr[i - 1][j] ^= (1 << 3);
	}
	//right
	else if(dir & (1 << 2)){
		arr[i][j] ^= (1 << 2);
		if(valid(i, j + 1))arr[i][j + 1] ^= 1;
	}
	//down
	else{
		arr[i][j] ^= (1 << 3);
		if(valid(i + 1, j))arr[i + 1][j] ^= (1 << 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("castle.out", "w", stdout);
	freopen("castle.in", "r", stdin);
	
	cin >> m >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	int room_cnt = 0;
	int largest_room = 0;
	int largest_room_rm = 0;
	int rm_i = 0;
	int rm_j = 0;
	char largest_room_ch;
	char dir[] = {'W', 'N', 'E', 'S'};
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!vis[i][j]){
				room_cnt++;
				dfs(i, j);
			}
		}
	}
	largest_room = find_largest();
	for(int j = 0;j < m;j++){
		for(int i = n - 1;i >= 0;i--){
			for(int sh = 0;sh < 4;sh++){
				//if have wall at sh dir
				if(arr[i][j] & (1 << sh)){
					toggle_wall(i, j, (1 << sh));
					int cur_largest = find_largest();
					if(cur_largest > largest_room_rm){
						rm_i = i + 1;
						rm_j = j + 1;
						largest_room_rm = cur_largest;
						largest_room_ch = dir[sh];
					}
					toggle_wall(i, j, (1 << sh));
				}
			}
		}
	}
	cout << room_cnt << endl;
	cout << largest_room << endl;
	cout << largest_room_rm << endl;
	cout << rm_i << ' ' << rm_j << ' ' << largest_room_ch << endl;
}
