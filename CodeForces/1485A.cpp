#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		int ans = INT_MAX;
		int div = 0;
		if(b == 1){
			b++;
			div++;
		}
		int ta = a;
		int t_div = div;
		while(ta > 0){
			ta /= b;
			t_div++;
		}
		for(int i = 0;i <= t_div;i++){
			int plus = i + div;
			int d = 0;
			int ra = a;
			int rb = b;
			rb += i;
			while(ra > 0){
				ra /= rb;
				d++;
			}
			ans = min(ans, d + plus);
		}
		cout << ans << endl;
	}
}
