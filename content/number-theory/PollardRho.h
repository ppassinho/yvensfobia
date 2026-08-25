/**
 * Author: Yvens Porto
 * Date: 2026-08-25
 * License: CC0
 * Source: https://github.com/yosupo06/library-checker-problems/blob/master/number_theory/factorize/sol/rho_with_difference_of_square.cpp
 * Description: Factorization algorithm, not necessarily ordered.
 * Guaranteed to work for numbers up to $10^{18}$.
 * Time: rho is O(n^(1/4)) in worst case,
 * fact is O(n^(1/4) log(n)) in worst case
 * Status: Tested on Yusupo "Factorize"
 */
#pragma once

#include "MillerRabin.h"

ll difference_of_square(ll n) {
    ll sqrt_n = ll(sqrt(n));
    for (ll i = 0; i < 300; ++i) {
        ll t = (sqrt_n + i) * (sqrt_n + i) - n;
        ll sqrt_t = ll(sqrt(t));
        if (sqrt_t * sqrt_t == t) return sqrt_n + i - sqrt_t;
    }
    return 0;
}

ll rho(ll n) {
    if (isPrime(n)) return n;
    if (n % 2 == 0) return 2;
    ll ds = difference_of_square(n);
    if (ds > 1) return ds;
    ll st = 0;
    auto f = [&](ll x) { return (__int128_t(x) * x + st) % n; };
    while (true) {
        st++;
        ll x = st, y = f(x);
        while (true) {
            ll p = __gcd((y - x + n), n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	ll d = rho(n);
    if (d == n) return {d};
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}