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
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		bool ans = true;
		for(int i = 1;i < n;i++){
			if(arr[i] - arr[i - 1] > 1)ans = false;
		}
		if(ans)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
