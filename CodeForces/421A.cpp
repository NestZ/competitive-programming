#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;cin >> n >> a >> b;
	set<int> sa;
	for(int i = 0;i < a;i++){
		int t;cin >> t;
		sa.insert(t);
	}
	set<int> sb;
	for(int i = 0;i < b;i++){
		int t;cin >> t;
		if(sa.count(t) == 0)sb.insert(t);
	}
	for(int i = 1;i <= n;i++){
		if(sa.count(i) != 0)cout << 1;
		else if(sb.count(i) != 0)cout << 2;
		cout << ' ';
	}
}
