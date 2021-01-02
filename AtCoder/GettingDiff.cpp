#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	int mx = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	int gcd = arr[0];
	for(int i = 1;i < n;i++){
		gcd = __gcd(gcd, arr[i]);
	}
	if(k <= mx && k % gcd == 0)cout << "POSSIBLE";
	else cout << "IMPOSSIBLE";
	cout << endl;
}
