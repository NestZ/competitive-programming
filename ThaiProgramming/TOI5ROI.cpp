#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int stable_cost;cin >> stable_cost;
	double min_profit = 0;
	int ans_sell = 0;
	int ans_price = 0;
	for(int sell = 1000;sell <= 15000;sell += 500){
		int cost = 100 - (sell - 1000) / 500;
		int sum_cost = stable_cost + (cost * sell);
		for(int price = 74;price <= 144;price++){
			double sell_cnt = ((100 - (0.8569 * exp(0.09 * (price - 100)))) * sell) / 100.0;
			double income = sell_cnt * price;
			double profit = income - sum_cost;
			if(profit > 0){
				if(min_profit == 0.0 || profit < min_profit){
					min_profit = profit;
					ans_sell = sell;
					ans_price = price;
				}
			}
		}
	}
	printf("%d\n%d\n%.2f\n", ans_sell, ans_price, min_profit);
}
