#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	for(int i = n - 1;i >= 0;i--){
		s += s[i];
	}
	cout << s;
}
