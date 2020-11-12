#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	while(n--){
		int num;cin >> num;
		int k = INT_MIN;
		for(int i = 2;;i++){
			if(pow(2, i) > num)break;
			for(int j = 2;pow(j, i) <= num;j++){
				if(pow(j, i) == num)k = max(k, i);
			}
		}
		if(k == INT_MIN)cout << "NO";
		else cout << k;
		cout << endl;
	}
}
