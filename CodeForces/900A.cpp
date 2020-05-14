#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cntu = 0;
	int cntd = 0;
	int n;cin >> n;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		if(a < 0)cntd++;
		else cntu++;
	}
	if(cntd == 0 || cntd == 1 || cntu == 0 || cntu == 1)cout << "Yes";
	else cout << "No";
}
