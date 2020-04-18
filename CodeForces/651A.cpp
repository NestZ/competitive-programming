#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int a, b;cin >> a >> b;
	bool t = a < b;
	int ans = 0;
	while(a > 0 && b > 0){
		if(a < 2 && b < 2)break;
		if(a <= 2 && !t){
			t = true;
		}
		else if(b <= 2 && t){
			t = false;
		}
		if(t){
			a++;
			b -= 2;
		}
		else{
			b++;
			a -= 2;
		}
		ans++;
	}
	cout << ans;
}
