#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
//down right
int dx[] = {1, 0};
int dy[] = {0, 1};
int h, w, a, b;
int ans = 0;
vector<vector<int>> arr(20, vector<int>(20, -1));

pair<int, int> next_valid(int x, int y){
	for(int i = x;i < h;i++){
		for(int j = y;j < w;j++){
			if(arr[i][j] != -1)continue;
			return make_pair(i, j);
		}
		y = 0;
	}
	return make_pair(-1, -1);
}

bool valid(int x, int y){
	if(x >= h || y >= w || arr[x][y] != -1)return false;
	return true;
}

void fill(int x, int y, int cnt){
	if(cnt == a)ans++;
	else if(x == -1)return;
	else{
		for(int i = 0;i < 2;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(valid(nx, ny)){
				arr[x][y] = arr[nx][ny] = 1;
				auto p = next_valid(x, y);
				fill(p.first, p.second, cnt + 1);
				arr[x][y] = arr[nx][ny] = -1;
			}
		}
		auto p = next_valid(x, y + 1);
		fill(p.first, p.second, cnt);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w >> a >> b;
	fill(0, 0, 0);
	cout << ans << endl;
}
