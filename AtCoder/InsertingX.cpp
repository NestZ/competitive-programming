#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	bool valid = true;
	int n = s.length();
	int l = 0;
	int r = n - 1;
	int ans = 0;
	while(l < r){
		if(s[l] == 'x' && s[r] == 'x'){
			l++;
			r--;
		}
		else if(s[l] == 'x'){
			ans++;
			l++;
		}
		else if(s[r] == 'x'){
			ans++;
			r--;
		}
		else{
			if(s[l] != s[r])valid = false;
			l++;
			r--;
		}
	}
	if(valid)cout << ans;
	else cout << -1;
	cout << endl;
}
