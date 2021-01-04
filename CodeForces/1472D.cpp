#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<ll> arr(n);
		ll a = 0;
		ll b = 0;
		bool at = true;
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.rbegin(), arr.rend());
		for(int i = 0;i < n;i++, at = !at){
			if(at){
				if(arr[i] % 2 == 0)a += arr[i];
			}
			else{
				if(arr[i] & 1)b += arr[i];
			}
		}
		if(a == b)cout << "Tie";
		else if(a > b)cout << "Alice";
		else cout << "Bob";
		cout << endl;
	}
}
