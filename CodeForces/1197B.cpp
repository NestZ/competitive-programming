#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	int l = 0;
	int r = 0;
	int curr = n - 1;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i] == n){
			l = i;
			r = i;
		}
	}
	l--;
	r++;
	while(l >= 0 || r < n){
		bool flag = false;
		if(l >= 0){
			if(arr[l] == curr){
				curr--;
				l--;
				flag = true;
			}
		}
		if(r < n){
			if(arr[r] == curr){
				curr--;
				r++;
				flag = true;
			}
		}
		if(!flag)break;
	}
	if(l < 0 && r >= n)cout << "YES";
	else cout << "NO";
}
