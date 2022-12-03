
#include<cstring>
#include<iostream>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
	// making and initializing dp array
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				// finding the maximum value
				dp[w] = max(dp[w],
							dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W]; // returning the maximum value of knapsack
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

    cout << knapSack(max_weight_knapsack,wt, val, number_of_items );
    return 0;

}




