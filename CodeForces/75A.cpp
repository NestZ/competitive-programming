#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;cin >> a >> b;
	ll c = a + b;
	string sa = to_string(a);
	string sb = to_string(b);
	string sc = to_string(c);
	string na = "";
	string nb = "";
	string nc = "";
	for(int i = 0;i < sa.length();i++){
		if(sa[i] != '0')na += sa[i];
	}
	for(int i = 0;i < sb.length();i++){
		if(sb[i] != '0')nb += sb[i];
	}
	for(int i = 0;i < sc.length();i++){
		if(sc[i] != '0')nc += sc[i];
	}
	ll ta = stoll(na);
	ll tb = stoll(nb);
	ll tc = stoll(nc);
	if(tc == ta + tb)cout << "YES";
	else cout << "NO";
}
