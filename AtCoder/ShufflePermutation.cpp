#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 998244353;

int find(int n, vector<ll> &parent){
	while(n != parent[n])n = parent[n];
	return n;
}

bool same(int a, int b, vector<ll> &parent){
	return find(a, parent) == find(b, parent);
}

void unite(int a, int b, vector<ll> &sz, vector<ll> &parent){
	a = find(a, parent);
	b = find(b, parent);
	if(sz[a] < sz[b])swap(a, b);
	sz[a] += sz[b];
	sz[b] = 0;
	parent[b] = a;
}

ll fac(ll n){
	ll res = 1;
	while(n > 0){
		res = res * n % MOD;
		n--;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;cin >> n >> k;
	ll r_perm = 1;
	ll c_perm = 1;
	vector<vector<ll>> arr(n, vector<ll>(n));
	vector<ll> r_parent(n);
	vector<ll> r_sz(n);
	vector<ll> c_parent(n);
	vector<ll> c_sz(n);
	for(int i = 0;i < n;i++){
		r_parent[i] = c_parent[i] = i;
		r_sz[i] = c_sz[i] = 1;
	}
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			int c_cnt = 0;
			int r_cnt = 0;
			for(int l = 0;l < n;l++){
				if(arr[l][i] + arr[l][j] <= k)
					c_cnt++;
				if(arr[i][l] + arr[j][l] <= k)
					r_cnt++;
			}
			if(r_cnt == n && !same(i, j, r_parent))unite(i, j, r_sz, r_parent);
			if(c_cnt == n && !same(i, j, c_parent))unite(i, j, c_sz, c_parent);
		}
	}
	for(int i = 0;i < n;i++){
		r_perm = r_perm * fac(r_sz[i]) % MOD;
		c_perm = c_perm * fac(c_sz[i]) % MOD;
	}
	cout << r_perm * c_perm % MOD << endl;
}
