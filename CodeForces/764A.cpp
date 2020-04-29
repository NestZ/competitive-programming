#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, z;cin >> n >> m >> z;
	int ans = 0;
	map<int, int> ma;
	int nn = n;
	int mm = m;
	while(nn <= z){
		ma[nn]++;
		nn += n;
	}
	while(mm <= z){
		if(ma[mm] == 1)ans++;
		mm += m;
	}
	cout << ans;
}
