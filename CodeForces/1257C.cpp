#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		map<int, int> m;
		for(int i = 1;i <= n;i++)m[i] = -1;
		vector<int> arr(n);
		int ans = INT_MAX;
		bool flag = n >= 2;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(m[arr[i]] == -1)m[arr[i]] = i;
			else{
				ans = min(ans, i - m[arr[i]]);
				m[arr[i]] = i;
			}
		}
		if(flag && ans != INT_MAX)cout << ans + 1;
		else cout << -1;
		cout << endl;
	}
}
