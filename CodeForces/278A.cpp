#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int a, b;cin >> a >> b;
	a--;b--;
	if(a == b)return cout << 0, 0;
	int ans = 0;
	int currd = 0;
	int currp = a;
	if(a > b){
		for(int i = a;i < n;i++)currd += arr[i];
		currp = 0;
	}
	for(int i = currp;i < b;i++)currd += arr[i];
	ans = currd;
	currd = 0;
	currp = a;
	if(a < b){
		for(int i = a;i > 0;i--)currd += arr[i - 1];
		currd += arr[n - 1];
		currp = n - 1;
	}
	for(int i = currp;i > b;i--)currd += arr[i - 1];
	ans = min(ans, currd);
	cout << ans;
}
