#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	ll k;cin >> k;
	k--;
	ll fst = -1;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] != '1'){
			fst = i;
			break;
		}
	}
	if(fst == -1)cout << s[k];
	else{
		if(k <= fst)cout << s[k];
		else cout << s[fst];
	}
	cout << endl;
}
