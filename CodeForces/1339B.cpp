#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		int l = 0;
		if(n & 1)l = n / 2;
		else l = n / 2 - 1;
		int r = l + 1;
		bool isl = true;
		for(int i = 0;i < n;i++){
			if(isl)cout << arr[l--];
			else cout << arr[r++];
			cout << ' ';
			isl = !isl;
		}
		cout << endl;
	}
}
