#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(!((s[i] - '0') & 1))ans += i + 1;
	}
	cout << ans;
}
