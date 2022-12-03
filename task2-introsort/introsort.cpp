#include "RUNNING.h"
#include "sorting.h"

void heapsort(vector<int>::iterator start, vector<int>::iterator end) {
    std::make_heap(start, end);
    std::sort_heap(start, end);
}

void introsort(vector<int>& array, vector<int>::iterator start, vector<int>::iterator end, int max_depth){
    if(array.size() <= 1) return;
    else if (max_depth == 0) heapsort(start, end);
    else if(std::distance(start, end) > 0){
        auto splitPosition = partition(start, end);
        introsort(array, start, splitPosition, max_depth-1);
        introsort(array, splitPosition+1, end, max_depth-1);
    }
    
}

