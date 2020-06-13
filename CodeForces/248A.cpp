#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int r0 = 0;
	int r1 = 0;
	int l0 = 0;
	int l1 = 0;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		if(a == 0)l0++;
		else l1++;
		if(b == 0)r0++;
		else r1++;
	}
	cout << min(l0, l1) + min(r0, r1);
}
