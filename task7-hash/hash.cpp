#include "hash.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

#define d 255

vector<int> search_pattern_hash(string Text, string patten) {
    int q = 101;
    vector<int> myvector;
    int m = patten.size();
    int n = Text.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // calculate hash value for pattern and text
    for (i = 0; i < m; i++) {
        p = (d * p + patten[i]) % q;
        t = (d * t + Text[i]) % q;
    }

    // find the match
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (Text[i + j] != patten[j])
                    break;
            }

            if (j == m)
                myvector.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - Text[i] * h) + Text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
    return myvector;

}

