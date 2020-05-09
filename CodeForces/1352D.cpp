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
		for(int i = 0;i < n;i++)cin >> arr[i];
		int cnt = 1;
		int l = 0;
		int r = n;
		int suml = arr[0];
		int sumr = 0;
		int lastl = arr[0];
		int lastr = 0;
		bool lt = false;
		if(n == 1){
			cout << cnt << ' ' << suml << ' ' << sumr << endl;
			continue;
		}
		while(l < r){
			cnt++;
			if(lt){
				if(l + 1 < r){
					l++;
					while(1){
						suml += arr[l];
						lastl += arr[l];
						if(l + 1 < r && lastl <= lastr)l++;
						else break;
					}
					lastr = 0;
				}
			}
			else{
				if(r - 1 > l){
					r--;
					while(1){
						sumr += arr[r];
						lastr += arr[r];
						if(r - 1 > l && lastr <= lastl)r--;
						else break;
					}
					lastl = 0;
				}
			}
			if(r - 1 == l || r <= l)break;
			lt = !lt;
		}
		cout << cnt << ' ' << suml << ' ' << sumr << endl;
	}
}
