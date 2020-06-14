#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s[3];
	string v = "aeiou";
	for(int i = 0;i < 3;i++){
		getline(cin, s[i]);
		string t = s[i];
		int n = t.length();
		int cnt = 0;
		for(int j = 0;j < n;j++){
			if(v.find(t[j]) != string::npos)cnt++;
		}
		if((i == 0 || i == 2) && cnt != 5)return cout << "NO", 0;
		if(i == 1 && cnt != 7)return cout << "NO", 0;
	}
	cout << "YES";
}
