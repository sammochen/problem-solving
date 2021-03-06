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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll test = 1;
	void main() {
		ll n;
		while (in(n), n) {
			printf("Case %lld:\n", test++);
			
			VLL A(n);
			REP(i,0,n) in(A[i]);
			set<ll> pos;
			REP(i,0,n) {
				REP(j,i+1,n) {
					pos.insert(A[i] + A[j]);
				}
			}

			ll q;
			in(q);
			REP(i,0,q) {
				ll x;
				in(x);
				set<ll>::iterator u = --pos.upper_bound(x);
				set<ll>::iterator l = pos.lower_bound(x);
				ll U = u == pos.end() ? inf : *u;
				ll L = l == pos.end() ? inf : *l;
				
				if (abs(L - x) <= abs(U - x)) {
					printf("Closest sum to %lld is %lld.\n", x, L);
				} else {
					printf("Closest sum to %lld is %lld.\n", x, U);
				}
				

			}
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
