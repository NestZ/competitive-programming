#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;getline(cin,s);
	int n = s.length();
	set<char> se;
	for(int i = 0;i < n;i++){
		if(s[i] <= 'z' && s[i] >= 'a')se.insert(s[i]);
	}
	cout << se.size();
}
