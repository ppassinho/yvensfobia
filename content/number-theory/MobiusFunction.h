/**
 * Author: Yvens Porto
 * Date: 2026-08-25
 * License: CC0
 * Source: https://github.com/brunomaletta/biblioteca/blob/master/Codigo/Matematica/crivo.cpp
 * Description: Finds the mobius function
 * Time: O(nlog(log(n)))
 * Status: Tested
 */
#pragma once

char meb[MAX];

void calculateMobius(int lim) {
	for (int i = 2; i <= lim; i++) meb[i] = 2;
	meb[1] = 1;
	for (int i = 2; i <= lim; i++) if (meb[i] == 2)
		for (int j = i; j <= lim; j += i) if (meb[j]) {
			if (meb[j] == 2) meb[j] = 1;
			meb[j] *= j/i%i ? -1 : 0;
		}
}