#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	string t = "aeiou";
	for(int i = 0;i < n - 1;i++){
		if(s[i] <= 'z' && s[i] >= 'a'){
			if(s[i] != 'n' && t.find(s[i]) == string::npos){
				if(t.find(s[i + 1]) == string::npos)return cout << "NO", 0;
			}
		}
	}
	if(t.find(s[n - 1]) == string::npos && s[n - 1] != 'n')cout << "NO";
	else cout << "YES";
}
