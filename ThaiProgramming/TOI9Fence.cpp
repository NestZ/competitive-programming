#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int q = 0;q < 2;q++){
		int n, m, t;cin >> n >> m >> t;
		int mx = 0;
		vector<vector<int>> arr(n, vector<int>(m, 0));
		vector<vector<int>> con_u(n, vector<int>(m));
		vector<vector<int>> con_l(n, vector<int>(m));
		for(int i = 0;i < t;i++){
			int r, c;cin >> r >> c;
			arr[r][c] = 1;
		}
		for(int i = 0;i < m;i++){
			int cnt = 0;
			for(int j = 0;j < n;j++){
				if(arr[j][i] == 0)cnt++;
				else cnt = 0;
				con_u[j][i] = cnt;
			}
		}
		for(int i = 0;i < n;i++){
			int cnt = 0;
			for(int j = 0;j < m;j++){
				if(arr[i][j] == 0)cnt++;
				else cnt = 0;
				con_l[i][j] = cnt;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(int k = 1;i + k < n && j + k < m;k++){
					if(con_u[i + k][j] >= k && con_l[i][j + k] >= k &&
							con_u[i + k][j + k] >= k && con_l[i + k][j + k] >= k)
						mx = max(mx, k + 1);
				}
			}
		}
		cout << mx << endl;
	}
}
