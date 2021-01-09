#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void plusb(string &s, int ind){
	if(ind == 0){
		if(s[ind] == '9')s[ind] = '0';
		else s[0] = char(s[0] + 1);
	}
	else{
		if(s[ind] == '9' || (s[ind] + 1) - s[ind - 1] > 1){
			plusb(s, ind - 1);
			if(s[ind - 1] != '0')
				s[ind] = char(s[ind - 1] - 1);
			else s[ind] = '0';
		}
		else s[ind] = char(s[ind] + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	string cur = "0";
	for(int i = 0;i < n;i++){
		plusb(cur, cur.length() - 1);
		if(cur[0] == '0')cur = "1" + cur;
	}
	cout << cur << endl;
}
