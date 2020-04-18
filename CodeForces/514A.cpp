#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(i == 0 && s[i] == '9')continue;
		if(s[i] >= '5')s[i] = '9' - (s[i] - '0');
	}
	cout << s;
}
