#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m, k;cin >> n >> m >> k;
	vector<int> arr(m);
	for(int i = 0;i < m;i++)cin >> arr[i];
	int f;cin >> f;
	int ans = 0;
	for(int i = 0;i < m;i++){
		int cnt = __builtin_popcount(f ^ arr[i]);
		if(cnt <= k)ans++;
	}
	cout << ans;
}
