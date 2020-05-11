#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	string t = "";
	if(n > 1){
		t += s[n - 2];
		t += s[n - 1];
	}
	else t = s[n - 1];
	if(stoi(t) % 4 == 0)cout << 4;
	else cout << 0;
}
