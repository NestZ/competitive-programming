#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	bool v = false;
	string vo = "aeiouy";
	for(int i = 0;i < n;i++){
		if(vo.find(s[i]) == string::npos){
			v = false;
			cout << s[i];
		}
		else{
			if(!v)cout << s[i];
			v = true;
		}
	}
}
