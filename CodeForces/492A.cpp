#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int ans = 0;
	int curr = 0;
	for(int i = 1;;i++){
		curr += i;
		if(n - curr < 0)break;
		ans++;
		n -= curr;
	}
	cout << ans;
}
