#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t != 0)s.insert(t);
	}
	cout << s.size();
}
