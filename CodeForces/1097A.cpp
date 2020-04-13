#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string h;cin >> h;
	bool mn = false;
	bool mr = false;
	for(int i = 0;i < 5;i++){
		string s;cin >> s;
		if(s[1] == h[1])mr = true;
		if(s[0] == h[0])mn = true;
	}
	if(mn || mr)cout << "YES";
	else cout << "NO";
}
