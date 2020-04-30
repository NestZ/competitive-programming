#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a;cin >> n >> a;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = 0;
	if(arr[a - 1] == 1)ans++;
	int l = a - 2;
	int r = a;
	while(l >= 0 && r <= n - 1){
		if(arr[r] == 1 && arr[l] == 1)ans += 2;
		l--;
		r++;
	}
	if(l < 0){
		for(int i = r;i < n;i++)if(arr[i] == 1)ans++;
	}
	else{
		for(int i = l;i >= 0;i--)if(arr[i] == 1)ans++;
	}
	cout << ans;
}
