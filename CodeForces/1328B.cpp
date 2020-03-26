#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int k;cin >> k;
		vector<char> arr(n);
		for(int i = 0;i < n;i++)arr[i] = 'a';
		int cnt = 0;
		int i = 1;
		for(i = 1;i < n;i++){
			if(cnt + i >= k)break;
			cnt += i;
		}
		arr[n - i - 1] = 'b';
		arr[n - (k - cnt)] = 'b';
		for(char c : arr)cout << c;
		cout << endl;
	}
	
}
