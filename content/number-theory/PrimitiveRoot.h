/**
 * Author: Yvens Porto
 * Date: 2026-08-25
 * License: CC0
 * Source: https://cp-algorithms.com/algebra/primitive-root.html
 * Description: Finds the Primitive Root of a prime number.
 * Guaranteed to work for numbers up to $10^{18}$.
 * Time: O(p^{1/4}) expected time
 * Status: Tested on Yusupo "Primitive Root"
 */
#pragma once

#include "PollardRho.h"

ll prim_root(ll p) {
    if (p == 2) return 1;
    auto facts = fact(p - 1);
    
    sort(facts.begin(), facts.end());
    facts.erase(unique(facts.begin(), facts.end()), facts.end());

    // if p is not prime (4, p^k, 2*p^k)
    // update phi and grant gcd(res, n) = 1
    ll phi = p - 1;
    for (ll res = 2; res < p; ++res) {
        bool ok = true;
        for (ll f : facts) {
            if (modpow(res, phi / f, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}