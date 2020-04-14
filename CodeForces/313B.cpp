#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n;cin >> n;
	int l = s.length();
	vector<int> arr(l, 0);
	for(int i = 0;i < l - 1;i++){
		if(i > 0)arr[i] = arr[i - 1];
		if(s[i] == s[i + 1])arr[i]++;
	}
	arr[l - 1] = arr[l - 2];
	while(n--){
		int i, j;cin >> i >> j;
		i--;j--;
		if(i == 0)cout << arr[j - 1] << endl;
		else cout << arr[j - 1] - arr[i - 1] << endl;
	}
}
