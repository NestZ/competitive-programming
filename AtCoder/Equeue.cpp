#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int INF = 1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;cin >> n >> k;
	vector<int> arr(n + 1);
	vector<vector<int>> mxl(110, vector<int>(110, -INF));
	vector<vector<int>> mxr(110, vector<int>(110, -INF));
	vector<vector<int>> dpl(110, vector<int>(110, -INF));
	vector<vector<int>> dpr(110, vector<int>(110, -INF));
	mxl[0][0] = dpl[0][0] = mxl[n + 1][0] = dpl[n + 1][0] = 0;
	mxr[0][0] = dpr[0][0] = mxr[n + 1][0] = dpr[n + 1][0] = 0;
	for(int i = 1;i <= n;i++)cin >> arr[i];
	for(int i = 1;i <= n;i++){
		priority_queue<int, vector<int>, greater<int>> q;
		int sum = 0;
		for(int j = 1;j <= i;j++){
			q.push(arr[j]);
			sum += arr[j];
		}
		mxl[i][i] = sum;
		for(int j = i + 1;j <= k;j++){
			if(q.empty())mxl[i][j] = mxl[i][j - 1];
			else{
				int cur = q.top(); q.pop();
				mxl[i][j] = mxl[i][j - 1] - cur;
			}
		}
		while(!q.empty())q.pop();
		sum = 0;
		for(int j = 1;j <= i;j++){
			q.push(arr[n - j + 1]);
			sum += arr[n - j + 1];
		}
		mxr[n - i + 1][i] = sum;
		for(int j = i + 1;j <= k;j++){
			if(q.empty())mxr[n - i + 1][j] = mxr[n - i + 1][j - 1];
			else{
				int cur = q.top(); q.pop();
				mxr[n - i + 1][j] = mxr[n - i + 1][j - 1] - cur;
			}
		}
		for(int j = 0;j <= k;j++){
			if(j == 0){
				dpl[i][j] = 0;
				dpr[n - i + 1][j] = 0;
			}
			else{
				dpl[i][j] = max({mxl[i][j], dpl[i][j - 1], dpl[i - 1][j]});
				dpr[n - i + 1][j] = max({mxr[n - i + 1][j], dpr[n - i + 1][j - 1], dpr[n - i + 2][j]});
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= k;j++){
			ans = max(ans, dpl[i][j] + dpr[i + 1][k - j]);
		}
	}
	cout << ans << endl;
}
