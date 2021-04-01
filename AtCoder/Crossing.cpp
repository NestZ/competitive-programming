#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int k = 0, m = 0;
	for(int i = 2;i <= 2 * n;i++){
		if(i * (i - 1) == 2 * n){
			k = i; m = i - 1;
			break;
		}
		else if(i * (i - 1) > 2 * n){
			cout << "No\n";
			return 0;
		}
	}
	vector<set<int>> arr(k);
	int ptr = 0;
	int inptr = 1;
	for(int i = 1;i <= n;i++){
		if((int)arr[ptr].size() == m){
			ptr++;
			inptr = ptr + 1;
		}
		arr[ptr].insert(i);	
		arr[inptr++].insert(i);
	}
	cout << "Yes\n" << k << endl;
	for(int i = 0;i < k;i++){
		cout << arr[i].size() << ' ';
		for(int e : arr[i])cout << e << ' ';
		cout << endl;
	}
}
