#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	for(int i = n - 1;i >= 0;i--){
		int t = s[i] - '0';
		if(t < 5)cout << "O-|";
		else cout << "-O|";
		for(int j = 0;j < t % 5;j++)cout << 'O';
		cout << '-';
		for(int j = 0;j < 4 - (t % 5);j++)cout << 'O';
		cout << endl;
	}
}
