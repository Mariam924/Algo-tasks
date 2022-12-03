#include "RUNNING.h"
#include "sorting.h"

void quicksort(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end){
    if(std::distance(start, end) > 0){
        auto splitPosition = partition(start, end);
        quicksort(arr, start, splitPosition);
        quicksort(arr, splitPosition+1, end);
    }
}

vector<int>::iterator partition(vector<int>::iterator start, vector<int>::iterator end){
    auto pivot = end-1;
    for(auto CurrentNumber = start; CurrentNumber != pivot; CurrentNumber++){
        if(*CurrentNumber < *pivot ){
            std::iter_swap(start, CurrentNumber);
            (start-1) ++;
        }
    }
    iter_swap(pivot, start);
    pivot = start;
    return pivot;
}

