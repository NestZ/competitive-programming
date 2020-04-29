#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		bool flag = true;
		int mn = *min_element(arr.begin(), arr.end()) + k;
		for(int i = 0;i < n;i++){
			if(abs(arr[i] - mn) > k)flag = false;
		}
		if(flag)cout << mn;
		else cout << -1;
		cout << endl;
	}
}
