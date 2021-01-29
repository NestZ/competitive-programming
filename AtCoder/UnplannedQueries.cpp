#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	vector<int> deg(100010);
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	bool ans = true;
	for(int i = 1;i <= n;i++){
		if(deg[i] & 1)ans = false;
	}
	if(ans)cout << "YES";
	else cout << "NO";
	cout << endl;
}
