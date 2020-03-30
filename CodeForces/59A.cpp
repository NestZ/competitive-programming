#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int low = 0;
	int up = 0;
	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] >= 'A' && s[i] <= 'Z')up++;
		else low++;
	}
	for(int i = 0;i < n;i++){
		if(low >= up)s[i] = tolower(s[i]);
		else s[i] = toupper(s[i]);
	}
	cout << s;
}
