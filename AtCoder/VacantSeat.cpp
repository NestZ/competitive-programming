#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	int n;cin >> n;
	cout << 0 << endl;
	string s;cin >> s;
	string in = "";
	int l = 0;
	int r = n - 1;
	while(l <= r){
		int mid = l + (r - l) / 2;
		cout << mid << endl;
		cin >> in;
		if(in == "Vacant")break;
		if(in == s){
			if(mid & 1 ^ 1)
				l = mid + 1;
			else r = mid - 1;
		}
		else{
			if(mid & 1 ^ 1)
				r = mid - 1;
			else l = mid + 1;
		}
	}
}
