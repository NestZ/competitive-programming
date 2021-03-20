#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<vector<char>> arr(410, vector<char>(410));
vector<vector<bool>> vis(410, vector<bool>(410, false));
//up down left right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;cin >> h >> w;
	ll ans = 0;
	for(int i = 0;i < h;i++)
		for(int j = 0;j < w;j++)
			cin >> arr[i][j];
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(!vis[i][j]){
				ll bc = 0;
				ll wc = 0;
				queue<pair<int, int>> q;
				q.emplace(i, j);
				vis[i][j] = true;
				while(!q.empty()){
					auto cur = q.front();
					q.pop();
					if(arr[cur.first][cur.second] == '#')bc++;
					else wc++;
					for(int k = 0;k < 4;k++){
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
						if(vis[nx][ny] || arr[nx][ny] == arr[cur.first][cur.second])continue;
						vis[nx][ny] = true;
						q.emplace(nx, ny);
					}
				}
				ans += bc * wc;
			}
		}
	}
	cout << ans << endl;
}
