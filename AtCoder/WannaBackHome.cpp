#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string st;cin >> st;
	int n = 0, s = 0;
	int w = 0, e = 0;
	int len = st.length();
	for(int i = 0;i < len;i++){
		if(st[i] == 'N')n = 1;
		else if(st[i] == 'S')s = 1;
		else if(st[i] == 'W')w = 1;
		else e = 1;
	}
	if(n - s == 0 && w - e == 0)cout << "Yes";
	else cout << "No";
	cout << endl;
}
