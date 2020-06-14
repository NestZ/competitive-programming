#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool l = false;
	bool la = false;
	bool sm = false;
	bool d = false;
	string s;cin >> s;
	int n = s.length();
	if(n >= 5)l = true;
	for(int i = 0;i < n;i++){
		if(isupper(s[i]))la = true;
		if(islower(s[i]))sm = true;
		if(s[i] <= '9' && s[i] >= '0')d = true;
	}
	if(l && la && sm && d)cout << "Correct";
	else cout << "Too weak";
}
