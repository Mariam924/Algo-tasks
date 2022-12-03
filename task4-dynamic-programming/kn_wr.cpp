// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
#include<cstring>
#include<iostream>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n,
					int val[], int wt[])
{
	// dp[i] is going to store maximum value
	// with knapsack capacity i.
	int dp[W+1];
	memset(dp, 0, sizeof dp);

	// Fill dp[] using above recursive formula
	for (int i=0; i<=W; i++)
	for (int j=0; j<n; j++)
		if (wt[j] <= i)
			dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

	return dp[W];
}

int main(int argc, char** argv)

{
	int number_of_items, max_weight_knapsack;
    cin >> number_of_items >> max_weight_knapsack;

    int* wt = new int(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
    cin >> wt[i];
    }

    int* val = new int(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
    cin >> val[i];
    }

    cout << unboundedKnapsack(max_weight_knapsack, number_of_items, val, wt );
    return 0;

}

