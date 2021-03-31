#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int cnt4 = 0;
	int cnt2 = 0;
	int cnt14 = 0;
	int cnt24 = 0;
	int cnt74 = 0;
	vector<int> fac(n);
	for(int i = 1;i <= n;i++){
		int num = i;
		for(int j = 2;j * j <= n;j++){
			while(num % j == 0){
				fac[j]++;
				num /= j;
			}
		}
		if(num > 1)fac[num]++;
	}
	for(int i = 0;i < n;i++){
		if(fac[i] >= 74)cnt74++;
		if(fac[i] >= 24)cnt24++;
		if(fac[i] >= 14)cnt14++;
		if(fac[i] >= 4)cnt4++;
		if(fac[i] >= 2)cnt2++;
	}
	int cnt442 = cnt4 * (cnt4 - 1) / 2 * (cnt2 - 2);
	int cnt242 = cnt24 * (cnt2 - 1);
	int cnt144 = cnt14 * (cnt4 - 1);
	cout << cnt442 + cnt242 + cnt144 + cnt74 << endl;
}
