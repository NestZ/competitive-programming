#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int x;cin >> x;
	int gcd = 0;
	vector<int> arr(n);
	vector<int> dif;
	for(int i = 0;i < n;i++)cin >> arr[i];
	arr.push_back(x);
	sort(arr.begin(), arr.end());
	for(int i = 1;i <= n;i++){
		dif.push_back(arr[i] - arr[i - 1]);
	}
	for(int i : dif)gcd = __gcd(gcd, i);
	cout << gcd << endl;
}
