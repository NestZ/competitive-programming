#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		map<int, int> last;
		map<int, int> cnt;
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n;i++)last[arr[i]] = -1;
		for(int i = 0;i < n;i++){
			if(last[arr[i]] != i - 1)
				cnt[arr[i]]++;
			last[arr[i]] = i;
		}
		for(auto p : last){
			if(arr[n - 1] != p.first)cnt[p.first]++;
		}
		int ans = INT_MAX;
		for(int i = 0;i < n;i++){
			ans = min(ans, cnt[arr[i]]);
		}
		cout << ans << endl;
	}
}
