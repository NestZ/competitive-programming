#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	int curr = 0;
	int ans = 0;
	string v = "AEIOUY";
	for(int i = 0;i < n;i++){
		if(v.find(s[i]) == string::npos){
			curr++;
			ans = max(ans, curr);
		}
		else curr = 0;
	}
	cout << ans + 1;
}
