#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	int a = 0;
	int b = 0;
	for(int i = 1;i < n;i++){
		if(s[i] == 'F' && s[i - 1] == 'S')b++;
		else if(s[i] == 'S' && s[i - 1] == 'F')a++;
	}
	cout << (a >= b ? "NO" : "YES");
}
