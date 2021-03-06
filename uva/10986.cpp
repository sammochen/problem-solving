/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

const ll inf = 1e9+7;

namespace SOLVE {	
	struct edge {
		ll to, d;
	};

	struct todo {
		ll v, d;
	};

	bool operator<(const todo & a, const todo & b) {
		return a.d > b.d;
	};

	VLL dijkstra(vector<vector<edge>> & E, ll s) {
		VLL d(E.size(), inf);
		d[s] = 0;
		priority_queue<todo> pq;

		pq.push({s, 0});
		while (pq.size()) {
			todo t = pq.top();
			pq.pop();

			for (edge e : E[t.v]) {
				if (d[t.v] + e.d < d[e.to]) {
					pq.push({e.to, d[t.v] + e.d});
					d[e.to] = d[t.v] + e.d;
				}
			}
		}

		return d;
	}


	ll test = 1;
	void main() {
		ll n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<vector<edge>> E(n);
		REP(i,0,m) {
			ll a, b, c;
			cin >> a >> b >> c;
			E[a].push_back({b,c});
			E[b].push_back({a,c});
		}

		VLL d = dijkstra(E, s);
		string ans = d[t] == inf ? "unreachable" : to_string(d[t]);
		cout << "Case #" << test++ << ": " << ans << endl;
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
