#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<int> s;
	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		while(t % 2 == 0)t /= 2;
		while(t % 3 == 0)t /= 3;
		s.insert(t);
	}
	if(s.size() == 1)cout << "Yes";
	else cout << "No";
}
