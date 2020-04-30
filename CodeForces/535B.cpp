#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> arr;

void dfs(ll n){
	if(n > 1e9)return;
	n *= 10;
	n += 4;
	arr.push_back(n);
	dfs(n);
	n += 3;
	arr.push_back(n);
	dfs(n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	dfs(0);
	sort(arr.begin(), arr.end());
	int k = arr.size();
	for(int i = 0;i < k;i++)if(arr[i] == n)cout << i + 1;
}
