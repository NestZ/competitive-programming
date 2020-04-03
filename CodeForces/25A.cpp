#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int e = 0,o = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i] & 1)o++;
		else e++;
	}
	for(int i  = 0;i < n;i++){
		if((arr[i] & 1) && o < e)return cout << i + 1, 0;
		else if(!(arr[i] & 1) && e <= o)return cout << i + 1, 0;
	}
}
