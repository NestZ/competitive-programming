#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		int curmx = 0;
		int mxin = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] > arr[mxin])mxin = i;
		}
		vector<int> ans;
		ans.push_back(arr[mxin]);
		int curgcd = arr[mxin];
		arr[mxin] = 0;
		for(int i = 0;i < n - 1;i++){
			curmx = 0;
			int mxi = 0;
			for(int j = 0;j < n;j++){
				if(arr[j] != 0){
					if(__gcd(curgcd, arr[j]) > curmx){
						curmx = __gcd(curgcd, arr[j]);
						mxi = j;
					}
				}
			}
			curgcd = __gcd(curgcd, arr[mxi]);
			ans.push_back(arr[mxi]);
			arr[mxi] = 0;
		}
		for(int i : ans)cout << i << ' ';
		cout << endl;
	}
}
