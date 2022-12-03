#include "RUNNING.h"
#define ARRAY_SIZE 1e3

#include <iostream>
#include <chrono>
#include <cmath>
#include "sorting.h"

using std::cout;
using std::endl;
using std::log;


vector<int> generate_random_vector()
{
    int size = 128;  //required size of the vector
    vector<int> random_vector(size);
    generate(random_vector.begin(), random_vector.end(), rand);
    return random_vector;
}

int main(int argc, char **argv)
{

    while (true)
    {
        vector<int> a = generate_random_vector();
        vector<int> b(a); 
        vector<int> sorted_array(a);
        sort(sorted_array.begin(), sorted_array.end());
        
        auto quick_start = std::chrono::high_resolution_clock::now();
        quicksort(a, a.begin(), a.end());
        auto quick_finish = std::chrono::high_resolution_clock::now();

        auto intro_start = std::chrono::high_resolution_clock::now();


        int max_depth = floor(log(b.size()));
        introsort(b, b.begin(), b.end(), max_depth);
        auto intro_finish = std::chrono::high_resolution_clock::now();

        auto quick_time = (quick_finish - quick_start).count();
        auto intro_time = (intro_finish - intro_start).count();

        if (a == sorted_array && b==sorted_array)
        {
            cout << "equivalent result ";
            cout << "quick_time ==> " << quick_time << " *** ";
            cout << "intro_time ==> " << intro_time << " *** ";
            cout << "performance enhancement ==>" << quick_time / intro_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algorithms " << endl;
            break;
        }
    }
    return 0;
}
