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
	string clean(string s) {
		string ans = "";
		for (char c : s) {
			if (c >= 'a' && c <= 'z') ans += c;
		}
		return ans;
	}

	ll sq(ll x) {
		ll s = sqrt(x);
		if (s * s == x) return s;
		return -1;
	}

	ll good(string s) {
		ll n = sq(s.length());
		if (n <= 0) {
			return 0;
		}

		REP(i,0,s.length()) {
			if (s[i] != s[s.length() - 1 - i]) return 0;
		}

		ll itr = 0;
		REP(i,0,s.length()) {
			if (s[i] != s[itr]) return 0;
			itr += n;
			if (itr >= n*n) {
				itr %= n;
				itr++;
			}
		}
		return 1;
	}

	ll test = 1;
	void main() {
		string s;
		getline(cin, s);
		s = clean(s);

		printf("Case #%lld:\n", test++);
		if (!good(s)) printf("No magic :(\n");
		else printf("%lld\n", sq(s.length()));

	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	string s;
	getline(cin, s);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
