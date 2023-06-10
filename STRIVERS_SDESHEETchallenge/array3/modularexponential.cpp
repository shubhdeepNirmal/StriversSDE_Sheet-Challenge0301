#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
    long long result = 1;
	long long xx=  x;
    while (n > 0) {
        if (n % 2 == 1) {
            result = ((result%m) *(xx%m)) % m;
            n--;
        } else {
            xx = ((xx%m)* (xx%m)) % m;
            n = n / 2;
        }
    }
    return (int)(result % m);
}
