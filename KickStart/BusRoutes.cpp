#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	for(int j = 0;j < t;j++){
		ll n, d;cin >> n >> d;
		vector<ll> arr(n);
		for(ll i = 0;i < n;i++){
			cin >> arr[i];
		}
		arr[n - 1] = d - (d % arr[n - 1]);
		for(ll i = n - 2;i >= 0;i--){
			arr[i] = arr[i + 1] - (arr[i + 1] % arr[i]);
		}
		cout << "Case #" << j + 1 << ": " << arr[0] << endl;
	}
}
