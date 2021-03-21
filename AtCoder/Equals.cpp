#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<int> p(100010);
vector<int> sz(100010, 1);

int find(int n){
	while(n != p[n])n = p[n];
	return n;
}

bool same(int a, int b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(sz[a] < sz[b])swap(a, b);
	sz[a] += sz[b];
	sz[b] = 0;
	p[b] = a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int ans = 0;
	vector<int> arr(n + 1);
	vector<set<int>> pop(n + 1);
	for(int i = 1;i <= n;i++)cin >> arr[i];
	for(int i = 1;i <= n;i++)p[i] = i;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		if(!same(a, b))
			unite(a, b);
	}
	for(int i = 1;i <= n;i++){
		pop[find(arr[i])].insert(arr[i]);
	}
	for(int i = 1;i <= n;i++){
		if(pop[find(arr[i])].count(i))ans++;
	}
	cout << ans << endl;
}
