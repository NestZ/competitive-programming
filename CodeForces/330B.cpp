#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	set<int> s;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		s.insert(a);
		s.insert(b);
	}
	int c = 0;
	for(int i = 1;i <= n;i++){
		if(s.count(i) == 0){
			c = i;
			break;
		}
	}
	cout << n - 1 << endl;
	for(int i = 1;i <= n;i++){
		if(i != c)cout << c << ' ' << i << endl;
	}
}
