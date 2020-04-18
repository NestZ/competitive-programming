#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		bool flag = false;
		if(i + 2 < n && s.substr(i, 3) == "144"){
			flag = true;
			i += 2;
		}
		else if(i + 1 < n && s.substr(i, 2) == "14"){
			flag = true;
			i++;
		}
		else if(s[i] == '1')flag = true;
		if(!flag)return cout << "NO", 0;
	}
	cout << "YES";
}
