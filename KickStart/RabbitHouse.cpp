#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
//up down left right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	for(int k = 1;k <= t;k++){
		ll ans = 0;
		ll n, m;cin >> n >> m;
		vector<vector<ll>> arr(n, vector<ll>(m));
		vector<vector<ll>> val(n, vector<ll>(m));
		vector<vector<bool>> vis(n, vector<bool>(m));
		priority_queue<tuple<ll, ll, ll>> q;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> arr[i][j];
				val[i][j] = arr[i][j];
				q.emplace(arr[i][j], i, j);
			}
		}
		while(!q.empty()){
			auto cur = q.top();
			q.pop();
			ll cx = get<1>(cur);
			ll cy = get<2>(cur);
			vis[cx][cy] = true;
			for(int i = 0;i < 4;i++){
				ll nx = cx + dx[i];
				ll ny = cy + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
				vis[nx][ny] = true;
				if(val[nx][ny] < val[cx][cy] - 1){
					val[nx][ny] = val[cx][cy] - 1;
					q.emplace(val[cx][cy] - 1, nx, ny);	
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				ans += val[i][j] - arr[i][j];
			}
		}
		cout << "Case #" << k << ": " << ans << endl;
	}
}
