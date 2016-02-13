#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

/*
  Author: Junior Andrade
*/ 

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = 1000000 + 10;

ll n, m;
ll cnt[N];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%lld %lld", &n, &m);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; ++i) {
      int x; scanf("%d", &x); cnt[x]++;
    }
    pq<ii>q;
    for(ll i = 0; i < 1000000; ++i) if(cnt[i]) q.push(mp(cnt[i] * i, i));
    vi ans;
    while(!q.empty()) {
      ii foo = q.top(); q.pop();
      m -= foo.F;
      ans.pb(foo.S);
      if(m <= 0) break;
    }
    if(m > 0) puts("Impossible");
    else {
      sort(ans.begin(), ans.end());
      for(int i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);
      printf("\n");
    }
  }
  return 0;
}
