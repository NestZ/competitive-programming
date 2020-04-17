#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	while(n--){
		int t;cin >> t;
		if(t == 1)cout << -1 << endl;
		else{
			string s = "2";
			string temp = string(t - 1, '3');
			s += temp;
			cout << s << endl;
		}
	}
}
