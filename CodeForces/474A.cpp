#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	char c;cin >> c;
	string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string t;cin >> t;
	int n = t.length();
	for(int i = 0;i < n;i++){
		if(c == 'R')cout << s[s.find(t[i]) - 1];
		else cout << s[s.find(t[i]) + 1];
	}
}
