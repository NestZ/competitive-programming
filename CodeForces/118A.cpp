#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	string v = "AEIOUYaeiouy";
	for(int i = 0;i < n;i++){
		if(v.find(s[i]) == string::npos)cout << '.' << (char)tolower(s[i]);
	}
}
