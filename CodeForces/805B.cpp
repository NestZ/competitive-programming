#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string ans = "";
	while(ans.length() < n){
		ans += "aabbaabbaabb";
	}
	cout << ans.substr(0, n);
}
