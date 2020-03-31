#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	size_t f = s.find("WUB");
	while(f != string::npos){
		s.replace((int)f, 3, " ");
		f = s.find("WUB");
	}
	if(s[0] == ' ')s.replace(0, 1, "");
	f = s.find("  ");
	while(f != string::npos){
		s.replace((int)f, 2, " ");
		f = s.find("  ");
	}
	cout << s;
}
