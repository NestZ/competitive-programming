#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, r;cin >> n >> l >> r;
	int mn = (n - l);
	int c = 1;
	for(int i = 0;i < l;i++){
		mn += c;
		c <<= 1;
	}
	int mx = 0;
	int curr = 1;
	int cnt = 0;
	bool flag = false;
	for(int i = 0;i < n;i++){
		if(cnt < r){
			mx += curr;
			curr <<= 1;
		}
		else if(!flag){
			curr >>= 1;
			flag = true;
			mx += curr;
		}
		else mx += curr;
		cnt++;
	}
	cout << mn << ' ' <<  mx;
}
