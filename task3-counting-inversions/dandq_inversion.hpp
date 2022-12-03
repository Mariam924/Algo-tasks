#include <iostream>
#include <vector>
using namespace std;


int _mergeSort(vector<int>& a, vector<int>& temp, int left, int right);
int merge(vector<int>& a, vector<int>& temp, int left, int mid,
	int right);


int dandq_counting_inversions(vector<int>& a)
{
	int vector_size = a.size();
	std::vector<int> temp(vector_size);
	return _mergeSort(a, temp, 0, vector_size - 1);
}


int _mergeSort(vector<int>& a, vector<int>& temp, int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {

		mid = (right + left) / 2;
		inv_count += _mergeSort(a, temp, left, mid);
		inv_count += _mergeSort(a, temp, mid + 1, right);


		inv_count += merge(a, temp, left, mid + 1, right);
	}
	return inv_count;
}


int merge(vector<int>& a, vector<int>& temp, int left, int mid,
	int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];

			inv_count = inv_count + (mid - i);
		}
	}


	while (i <= mid - 1)
		temp[k++] = a[i++];

	while (j <= right)
		temp[k++] = a[j++];


	for (i = left; i <= right; i++)
		a[i] = temp[i];

	return inv_count;
}


// #if DEBUG_dandq_inversion
// int main()
// {
// 	std::vector<int> a{ 1, 20, 6, 4, 5 };
// 	int ans = dandq_counting_inversions(a);
// 	cout << " Number of inversions are " << ans;
// 	return 0;
// }
// #endif
