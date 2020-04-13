#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		int mn = *min_element(arr.begin(), arr.end());
		int cnt = 1;
		set<int> s;
		for(int i = 0;i < n;i++){
			if(arr[i] > mn && s.count(arr[i]) == 0){
				cnt++;
				s.insert(arr[i]);
			}
		}
		cout << cnt << endl;
	}
}
