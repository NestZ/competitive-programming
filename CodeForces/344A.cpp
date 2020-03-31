#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	string curr;cin >> curr;
	t--;
	int ans = 1;
	while(t--){
		string s;cin >> s;
		if(s[0] == curr[1])ans++;
		curr = s;
	}
	cout << ans;
}
