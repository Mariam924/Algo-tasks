#include <iostream>
#include <vector>
using namespace std;


int naive_counting_inversions(vector<int> a){
	int n = a.size();
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				inv_count++;

	return inv_count;
}


//int main()
//{
//	std::vector<int> a{ 8, 4, 2, 1 };
//	cout << " Number of inversions are "
//		<< naive_counting_inversions(a); 
//	return 0;
//}