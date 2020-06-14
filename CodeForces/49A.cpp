#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	int n = s.length();
	char lst = 'a';
	for(char c : s){
		char curr = tolower(c);
		if(curr >= 'a' && curr <= 'z')lst = curr;
	}
	string v = "aeiouy";
	if(v.find(tolower(lst)) == string::npos)cout << "NO";
	else cout << "YES";
}
