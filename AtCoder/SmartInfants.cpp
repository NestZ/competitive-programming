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

int mxN = 200010;
//segment tree for range min querie
vector<int> st(mxN * 2 + 10, INT_MAX);

int mn(int a, int b){
  a += mxN; b += mxN;
  int mn = INT_MAX;
  while(a <= b){
    if(a % 2 == 1)mn = min(mn, st[a++]);
    if(b % 2 == 0)mn = min(mn, st[b--]);
    a >>= 1; b >>= 1;
  }
  return mn;
}

void update(int k, int x){
  k += mxN;
  st[k] = x;
  for(k >>= 1;k >= 1;k >>= 1){
    st[k] = min(st[2 * k], st[2 * k + 1]);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;cin >> n >> q;
  //store rating of each child
  vector<int> rating(n + 1);
  //store id of kid in each kindergarten
  vector<set<int>> cid(mxN);
  //store id of kindergarten that each child belong to
  vector<int> kid(n + 1);
  //store tuple {rating, id} for each kindergarten
  vector<priority_queue<pair<int, int>>> pq(mxN);
  for(int i = 1;i <= n;i++){
    int a, b;cin >> a >> b;
    rating[i] = a;
    pq[b].push({a, i});
    kid[i] = b;
    cid[b].insert(i);
    update(b, pq[b].top().first);
  }
  for(int i = 1;i <= q;i++){
    int id, des;cin >> id >> des;
    int kinder_id = kid[id];
    int cur_rating = rating[id];
    //remove child
    cid[kinder_id].erase(id);
    while(!pq[kinder_id].empty() && !cid[kinder_id].count(pq[kinder_id].top().second))
      pq[kinder_id].pop();
    //insert child in new kindergarten
    kid[id] = des;
    cid[des].insert(id);
    pq[des].push({cur_rating, id});
    //update segment tree
    update(kinder_id, (pq[kinder_id].empty() ? INT_MAX : pq[kinder_id].top().first));
    update(des, pq[des].top().first);
    //querie for min value
    cout << mn(1, mxN - 1) << endl;
  }
}
