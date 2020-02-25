#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void dfs(ll curr, ll n, int use, int &ans){
	if(curr > n)return;
	if(use == 0b111)ans++;
	dfs(curr * 10 + 3, n, use | 0b001, ans);
	dfs(curr * 10 + 5, n, use | 0b010, ans);
	dfs(curr * 10 + 7, n, use | 0b100, ans);
}

int main(){
	ll n;cin >> n;
	int ans = 0;
	dfs(0, n, 0, ans);
	cout << ans;
}
