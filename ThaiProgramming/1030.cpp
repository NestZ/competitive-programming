#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;cin >> k;
	vector<pair<double, int>> price;
	for(int i = 0;i < k;i++){
		int p, q;cin >> p >> q;
		price.push_back(make_pair((double)p / q, q));
	}
	sort(price.begin(), price.end());
	int cur_rice = 0;
	int m;cin >> m;
	vector<double> price_for(m, 0.0);
	for(int i = 0;i < m;i++){
		int want;cin >> want;
		//sufficient
		if(want <= price[cur_rice].second){
			price[cur_rice].second -= want;	
			price_for[i] += want * price[cur_rice].first;
			if(price[cur_rice].second == 0)cur_rice++;
		}
		//insufficient
		else{
			while(want > 0){
				int can = min(want, price[cur_rice].second);
				price[cur_rice].second -= can;	
				price_for[i] += can * price[cur_rice].first;
				if(price[cur_rice].second == 0)cur_rice++;
				want -= can;
			}
		}
	}
	for(double d : price_for)printf("%.3lf\n", d);
}
