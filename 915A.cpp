#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	int mx = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(k % arr[i] == 0)mx = max(mx, arr[i]);
	}
	cout << k / mx;
}
