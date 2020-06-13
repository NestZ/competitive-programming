#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> s;
	for(int i = 1;i <= 500;i++){
		s.insert(i * (i + 1) / 2);
	}
	if(s.count(n) != 0)cout << "YES";
	else cout << "NO";
}
