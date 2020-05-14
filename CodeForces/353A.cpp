#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int sum1 = 0;
	int sum2 = 0;
	bool flag = false;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		if((a & 1) != (b & 1))flag = true;
		sum1 += a;
		sum2 += b;
	}
	if(sum1 % 2 == 0 && sum2 % 2 == 0)cout << 0;
	else if(flag && n > 1 && (sum1 & 1) && (sum2 & 1))cout << 1;
	else cout << -1;
}
