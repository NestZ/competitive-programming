#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int mn = INT_MAX;
		int ans = 0;
		vector<int> arr(n);
		map<int, int> cnt;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			cnt[arr[i]]++;
		}
		for(int i = 0;i < n;i++){
			if(cnt[arr[i]] == 1){
				if(arr[i] < mn){
					mn = arr[i];
					ans = i + 1;
				}
			}
		}
		if(mn == INT_MAX)cout << -1;
		else cout << ans;
		cout << endl;
	}
}
