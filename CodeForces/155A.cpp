#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int cmax = 0;
	int cmin = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(i == 0){
			cmax = t;
			cmin = t;
		}
		else{
			if(t > cmax){
				ans++;
				cmax = t;
			}
			else if(t < cmin){
				ans++;
				cmin = t;
			}
		}
	}
	cout << ans;
}
