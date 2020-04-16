#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b;cin >> a >> b;
	int ans = 1;
	for(int i = 2;i <= min(a, b);i++){
		ans *= i;
	}
	cout << ans;
}
