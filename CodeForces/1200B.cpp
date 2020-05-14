#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m, k;cin >> n >> m >> k;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		bool flag = true;
		for(int i = 0;i < n - 1;i++){
			if(arr[i] > arr[i + 1] - k){
				if(arr[i + 1] - k <= 0)m += arr[i];
				else m += arr[i] - (arr[i + 1] - k);
			}
			else m -= arr[i + 1] - k - arr[i];
			if(m < 0)flag = false;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
