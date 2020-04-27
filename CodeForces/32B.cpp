#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] == '.')cout << 0;
		else if(s.substr(i, 2) == "-."){
			cout << 1;
			i++;
		}
		else if(s.substr(i, 2) == "--"){
			cout << 2;
			i++;
		}
	}
}
