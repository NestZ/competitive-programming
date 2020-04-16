#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> a(n);
	vector<int> p(n);
	for(int i = 0;i < n;i++)cin >> a[i] >> p[i];
	int curr = 0;
	int mn = INT_MAX;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(p[i] >= mn)curr += a[i];
		else{
			ans += curr * mn;
			mn = p[i];
			curr = a[i];
		}
	}
	ans += curr * mn;
	cout << ans;
}
