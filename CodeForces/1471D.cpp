#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		map<int, int> m;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			int new_v = 1;
			for(int j = 2;j * j <= arr[i];j++){
				bool flag = false;
				while(arr[i] % j == 0){
					arr[i] /= j;
					flag = !flag;
				}
				if(flag)new_v *= j;
			}
			new_v *= arr[i];
			m[new_v]++;
		}
		int a = 0, b = 0;
		for(auto p : m){
			a = max(a, p.second);
			if((p.second > 1 && p.second % 2 == 0) || p.first == 1)
				b += p.second;
		}
		int q;cin >> q;
		for(ll i = 0;i < q;i++){
			ll time;cin >> time;
			if(time == 0)printf("%d\n", a);
			else printf("%d\n", max(a, b));
		}
	}
}
