#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> last(n + 1, -1);
		vector<int> arr(n);
		vector<int> ans(n + 1, INT_MAX);
		vector<int> mxdif(n + 1);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			int mxd;
			if(last[arr[i]] == -1)mxd = i + 1;
			else mxd = i - last[arr[i]];
			mxdif[arr[i]] = max(mxdif[arr[i]], mxd);
			last[arr[i]] = i;
		}
		for(int i = 1;i <= n;i++){
			mxdif[i] = max(mxdif[i], n - last[i]);
		}
		for(int i = 1;i <= n;i++){
			if(mxdif[i] <= n && mxdif[i] >= 0)
				ans[mxdif[i]] = min(i, ans[mxdif[i]]);
		}
		for(int i = 1;i <= n;i++){
			ans[i] = min(ans[i], ans[i - 1]);
			cout << (ans[i] == INT_MAX ? -1 : ans[i]) << ' ';
		}
		cout << endl;
	}
}
