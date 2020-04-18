#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	map<pair<int,int>, int> m;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		m[make_pair(a, b)]++;
		ans = max(ans, m[{a, b}]);
	}
	cout << ans;
}
