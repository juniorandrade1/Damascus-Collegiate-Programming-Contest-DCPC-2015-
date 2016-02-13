#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 2000000000000000000LL
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

const int N = 102;

ll X[N], Y[N], R[N];
int n;

ll quad(ll x) {
  return x * x;
}

ll euclids(ll a, ll b, ll c, ll d) {
  return abs(b - a) + abs(d - c);
}

ll g[N][N];
ll dis[N];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
      scanf("%lld %lld %lld", X + i, Y + i, R + i);
      R[i] *= R[i];
    }

    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        ll lol = euclids(X[i], X[j], Y[i], Y[j]);
        ll dx = abs(X[i] - X[j]);
        ll dy = abs(Y[i] - Y[j]);
        dx *= dx;
        dy *= dy;
        if(i == j) g[i][j] = 0;
        else{
          g[i][j] = lol;
          if( dx + dy <= R[i] ) g[i][j] = min(lol, 2LL);
        }
      }
    }
    for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    scanf("%lld %lld %lld %lld", X + 0, Y + 0, X + n + 1, Y + n + 1);
    ll ans = euclids(X[0], X[n + 1], Y[0], Y[n + 1]);
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        ll d1 = euclids(X[0],X[i],Y[0], Y[i]);
        ll d2 = euclids(X[n + 1], X[j], Y[n + 1], Y[j]);
        ans = min( ans, d1 + g[i][j] + d2);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
