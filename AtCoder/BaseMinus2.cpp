#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int bit = 32;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int mul = 0;
	bool minus = n < 0;
	n = abs(n);
	vector<int> ans(bit);
	if(n == 0)cout << 0;
	else{
		while(n > 0){
			ans[mul] = (n & 1);
			n >>= 1;
			mul++;
		}
		mul = 0;
		for(int i = 0;i < bit;i++, mul++){
			if(minus){
				if(mul % 2 == 0){
					if(ans[i] == 1)ans[i + 1]++;
					else if(ans[i] == 2){
						ans[i] = 0;
						ans[i + 1]++;
					}
				}
				else{
					if(ans[i] == 2){
						ans[i] = 0;
						ans[i + 1]++;
					}
				}
			}
			else{
				if(mul & 1){
					if(ans[i] == 1)ans[i + 1]++;
					else if(ans[i] == 2){
						ans[i] = 0;
						ans[i + 1]++;
					}
				}
				else{
					if(ans[i] == 2){
						ans[i] = 0;
						ans[i + 1]++;
					}
				}
			}
		}
		bool found = false;
		reverse(ans.begin(), ans.end());
		for(int i : ans){
			if(i != 0)found = true;
			if(found)cout << i;
		}
	}
	cout << endl;
}
