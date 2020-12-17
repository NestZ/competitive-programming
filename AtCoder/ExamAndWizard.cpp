#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> m;
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	ll less = 0;
	ll more = 0;
	ll cnt = 0;
	ll cur_m = 0;
	ll less_cnt = 0;
	for(int i = 0;i < n;i++){
		if(a[i] < b[i]){
			less += b[i] - a[i];
			less_cnt++;
		}
		else if(a[i] > b[i]){
			more += a[i] - b[i];
			m.push_back(a[i] - b[i]);
		}
	}
	sort(m.rbegin(), m.rend());
	if(more < less)cout << -1;
	else{
		while(less > 0){
			cnt++;
			less -= m[cur_m++];
		}
		cout << cnt + less_cnt;
	}
	cout << endl;
}
