#include <iostream>
#include <algorithm>
#include "my_pq.h"

My_PQ PQ_Heap;

int main()
{
	int n;
	int o;
	std::cin >> n;
	std::cin >> o;
	for (int j = 0; j < n; j++) {
		int insert_an_element;
		std::cin >> insert_an_element;
		PQ_Heap.add(insert_an_element);
	}
	for (int i = 0; i < o; i++) {
		int x;
		std::cin >> x;
		switch (x)
		{
		case 1:
			int insert_an_element;
			std::cin >> insert_an_element;
			PQ_Heap.add(insert_an_element);
			break;
		case 2:
			int find_an_element;
			std::cin >> find_an_element;
			int priority;
			std::cin >> priority;
			PQ_Heap.change_priority(find_an_element, priority);
			break;
		case 3:
			int rem;
			std::cin >> rem;
			PQ_Heap.deleteE(rem);
			break;
		case 4:
			PQ_Heap.extract_max();
			break;
		case 5:
			cout << PQ_Heap.peek() << ' ' << endl;
			break;
		case 6:
			for (int cnt = PQ_Heap.get_size(); cnt > 0; cnt--) {
				cout << PQ_Heap.extract_max() << ' ';
			}
			cout << endl;
			break;
		case 7:
			cout << PQ_Heap.get_size() << ' ' << endl;
			break;
		}
	}
	return 0;
}

