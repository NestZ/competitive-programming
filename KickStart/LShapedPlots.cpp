#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	for(int q = 1;q <= t;q++){
		int ans = 0;
		int n, m;cin >> n >> m;
		vector<vector<int>> arr(n, vector<int>(m));
		vector<vector<int>> u(n, vector<int>(m));
		vector<vector<int>> d(n, vector<int>(m));
		vector<vector<int>> l(n, vector<int>(m));
		vector<vector<int>> r(n, vector<int>(m));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				cin >> arr[i][j];
		for(int i = 0;i < n;i++){
			int cnt = 0;
			for(int j = 0;j < m;j++){
				if(arr[i][j] == 1)cnt++;
				else cnt = 0;
				l[i][j] = cnt;	
			}
			cnt = 0;
			for(int j = m - 1;j >= 0;j--){
				if(arr[i][j] == 1)cnt++;
				else cnt = 0;
				r[i][j] = cnt;
			}
		}
		for(int i = 0;i < m;i++){
			int cnt = 0;
			for(int j = 0;j < n;j++){
				if(arr[j][i] == 1)cnt++;
				else cnt = 0;
				u[j][i] = cnt;	
			}
			cnt = 0;
			for(int j = n - 1;j >= 0;j--){
				if(arr[j][i] == 1)cnt++;
				else cnt = 0;
				d[j][i] = cnt;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int cur = 0;
				int ul = u[i][j];
				int llo = l[i][j];
				int mx = ul / 2;
				int cnt = max(0, min(llo, mx) - 1);
				cur += cnt;
				mx = llo / 2;
				cnt = max(0, min(mx, ul) - 1);
				cur += cnt;

				int rl = r[i][j];
				mx = ul / 2;
				cnt = max(0, min(rl, mx) - 1);
				cur += cnt;
				mx = rl / 2;
				cnt = max(0, min(mx, ul) - 1);
				cur += cnt;

				int dl = d[i][j];
				mx = dl / 2;
				cnt = max(0, min(llo, mx) - 1);
				cur += cnt;
				mx = llo / 2;
				cnt = max(0, min(mx, dl) - 1);
				cur += cnt;

				mx = dl / 2;
				cnt = max(0, min(rl, mx) - 1);
				cur += cnt;
				mx = rl / 2;
				cnt = max(0, min(mx, dl) - 1);
				cur += cnt;

				ans += cur;
			}
		}
		cout << "Case #" << q << ": " << ans << endl;
	}
}
