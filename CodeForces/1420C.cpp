#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, q;cin >> n >> q;
		vector<ll> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		int fst = 0;
		for(int i = 0;i < n - 1;i++){
			if(arr[i] > arr[i + 1]){
				fst = i;
				break;
			}
		}
		vector<ll> ans;
		ans.push_back(arr[fst]);
		bool m = false;
		for(int i = fst;i < n - 1;i++){
			if(m){
				if(arr[i] > arr[i + 1]){
					ans.push_back(arr[i]);
					m = !m;
				}
			}
			else{
				if(arr[i] < arr[i + 1]){
					ans.push_back(arr[i]);
					m = !m;
				}
			}
		}
		ll sum = 0;
		if(arr[n - 1] > arr[n - 2])ans.push_back(arr[n - 1]);
		for(int i = 0;i < int(ans.size());i++){
			if(i & 1){
				sum -= ans[i];
			}
			else{
				sum += ans[i];
			}
		}
		cout << sum << endl;
	}
}
