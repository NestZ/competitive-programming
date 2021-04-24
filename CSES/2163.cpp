#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<int> ft(200010);

void add(int k, int x){
  while(k < 200010){
    ft[k] += x;
    k += k & -k;
  }
}

int sum(int k){
  int s = 0;
  while(k >= 1){
    s += ft[k];
    k -= k & -k;
  }
  return s;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;cin >> n >> k;
  k++;
  set<int> out;
  vector<int> ans;
  int rem = n;
  int cur = 0;
  for(int i = 1;i <= n;i++)
    add(i, 1);
  while(rem > 0){
    int sum_cur = sum(cur);
    int out_num = (sum_cur + k) % rem;
    if(out_num == 0)out_num = rem;
    int l = 1;
    int r = n;
    int best = n;
    while(l <= r){
      int mid = l + (r - l) / 2;
      if(sum(mid) < out_num)
        l = mid + 1;
      else{
        best = min(mid, best);
        r = mid - 1;
      }
    }
    ans.push_back(best);
    add(best, -1);
    cur = best;
    rem--;
  }
  for(int i : ans)cout << i << ' ';
  cout << endl;
}
