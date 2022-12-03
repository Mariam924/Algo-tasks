#include "naive.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> search_pattern_naive(string Text, string patten) {
	vector<int> myvector;
	int M = patten.size();
	int N = Text.size();
	int i = 0;

	while (i <= N - M)
	{
		int j;

		for (j = 0; j < M; j++)
			if (Text[i + j] != patten[j])
				break;

		if (j == M)
		{
			myvector.push_back(i);
			i = i + M;
		}
		else if (j == 0)
			i = i + 1;
		else
			i = i + j;
	}
	return myvector;
}
