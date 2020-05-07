#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> arr(n);
		ll sum = 0;
		bool flag = true;
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n;i++){
			sum += arr[i];
			if(sum <= 0)flag = false;
		}
		sum = 0;
		for(int i = n - 1;i >= 0;i--){
			sum += arr[i];
			if(sum <= 0)flag = false;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
