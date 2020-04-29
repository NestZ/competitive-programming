#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	bool isl = true;
	string ans = "";
	int i = 0;
	if(n & 1){
		i++;
		ans += s[0];
	}
	for(;i < n;i++){
		if(isl)ans.insert(ans.begin(), s[i]);
		else ans.insert(ans.end(), s[i]);
		isl = !isl;
	}
	cout << ans;
}
