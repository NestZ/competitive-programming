#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	int c = 1;
	for(int i = 1;i <= n;){
		cout << s[i - 1];
		i += c;
		c++;
	}
}
