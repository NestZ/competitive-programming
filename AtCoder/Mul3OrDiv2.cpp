#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		while(num % 2 == 0 && num != 0){
			num >>= 1;
			ans++;
		}
	}
	cout << ans << endl;
}
