#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll sum = 0;
	for(int i = 0;i < n - 1;i++){
		ll num;cin >> num;
		sum += num;
	}
	cout << n * (n + 1) / 2 - sum << endl;
}
