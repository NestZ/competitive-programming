#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
vector<ll> arr(300010);
ll get(ll i){
	if(i < 0 || i > n)return 0;
	return max(0ll, arr[i] - arr[i + 1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int q;cin >> n >> q;
		for(int i = 0;i < n;i++)cin >> arr[i];
		ll sum = 0;
		for(int i = 0;i < n;i++)sum += get(i);
		cout << sum << endl;
		for(int i = 0;i < q;i++){
			int l, r;cin >> l >> r;
			l--;r--;
			if(l < r){
				sum -= get(l);
				sum -= get(l - 1);
				sum -= get(r);
				if(r - 1 != l)sum -= get(r - 1);
				swap(arr[l], arr[r]);
				sum += get(l);
				sum += get(l - 1);
				sum += get(r);
				if(r - 1 != l)sum += get(r - 1);
			}
			cout << sum << endl;
		}
		vector<ll> new_arr(300010);
		swap(arr, new_arr);
	}
}
