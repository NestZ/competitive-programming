#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(s[i] <= 'Z' && s[i] >= 'A')cnt++;
	}
	if(cnt == n || (cnt == n - 1 && tolower(s[0]) == s[0])){
		for(int i = 0;i < n;i++){
			if(i == 0 && cnt == n - 1)s[i] = toupper(s[i]);
			else s[i] = tolower(s[i]);
		}
	}
	cout << s;
}
