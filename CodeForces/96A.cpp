#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	int curr = 1;
	for(int i = 1;i < n;i++){
		if(s[i] == s[i - 1]){
			curr++;
			if(curr == 7)return cout << "YES", 0;
		}
		else curr = 1;
	}
	cout << "NO";
}
