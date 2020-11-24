#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int buy = n / 100;
	int rem = n % 100;
	int want = 0;
	for(int i = 5;i >= 1;i--){
		while(rem >= i){
			want++;
			rem -= i;
		}
	}
	if(want > buy)cout << 0;
	else cout << 1;
	cout << endl;
}
