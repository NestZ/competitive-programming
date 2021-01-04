#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n, r;cin >> n >> r;
		int offset = 0;
		int ans = 0;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.rbegin(), arr.rend());
		for(int i = 0;i < n;i++){
			if(i > 0 && arr[i] == arr[i - 1])continue;
			if(arr[i] - offset <= 0)break;
			offset += r;
			ans++;
		}
		cout << ans << endl;
	}
}
