#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int m, s;cin >> m >> s;
	string ss(m, '0');
	int i = 0;
	if((s == 0 && m > 1) || s > m * 9)return cout << -1 << ' ' << -1, 0;
	int lst = m - 1;
	while(s > 0){
		if(s > 9){
			ss[i] = '9';
			s -= 9;
		}
		else{
			ss[i] = '0' + s;
			s = 0;
			lst = i;
		}
		i++;
	}
	string mn = ss;
	if(mn[m - 1] == '0'){
		if(mn[lst] > '0'){
			mn[lst] -= 1;
			mn[m - 1] = '1';
		}
	}
	reverse(mn.begin(), mn.end());
	cout << mn << ' ' << ss;
}
