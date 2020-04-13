#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	string ans;cin >> ans;
	int cnt = 0;
	for(int i = 0;i < n;i++){
		int numcurr = s[i] - '0';
		int numans = ans[i] - '0';
		if(numcurr < numans){
			cnt += min(numans - numcurr, numcurr + 10 - numans);
		}
		else{
			cnt += min(numcurr - numans, numans + 10 - numcurr);
		}
	}
	cout << cnt;
}
