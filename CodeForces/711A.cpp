#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	bool flag = false;
	vector<string> arr;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		if(!flag){
			if(s[0] == 'O' && s[1] == 'O'){
				s[0] = '+';
				s[1] = '+';
				flag = true;
			}
			else if(s[3] == 'O' && s[4] == 'O'){
				s[3] = '+';
				s[4] = '+';
				flag = true;
			}
		}
		arr.push_back(s);
	}
	if(flag){
		cout << "YES" << endl;
		for(string s : arr)cout << s << endl;
	}
	else cout << "NO";
}
