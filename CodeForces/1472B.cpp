#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int sum = 0;
		int cnt1 = 0;
		int cnt2 = 0;
		bool ans = true;
		vector<int> arr(n);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			sum += arr[i];
			if(arr[i] == 2)cnt2++;
			else cnt1++;
		}
		if(sum & 1)ans = false;
		else{
			int w = sum / 2;	
			if(w % 2 != 0 && cnt2 == n)ans = false;
			else{
				while(cnt2 > 0){
					cnt2--;
					w -= 2;
				}
				if(w > cnt1)ans = false;
			}
		}
		if(ans)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
