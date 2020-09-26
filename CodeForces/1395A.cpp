#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool ch(int a, int b, int c, int d){
	int cnto = 0;
	if(a & 1)cnto++;
	if(b & 1)cnto++;
	if(c & 1)cnto++;
	if(d & 1)cnto++;
	if(cnto <= 1)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b, c, d;cin >> a >> b >> c >> d;
		bool ans = false;
		if(ch(a, b, c, d))ans = true;
		for(int i = 0;i < 2;i++){
			if(a == 0 || b == 0 || c == 0)break;
			a--;b--;c--;
			d += 3;
			if(ch(a, b, c, d))ans = true;
		}
		if(ans)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
