#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include<algorithm>
#include "naive_inversion.hpp"
#include "dandq_inversion.hpp"

#define ARRAY_SIZE 1e6
using namespace std;

vector<int> generate_random_vector()
{
    int size = 128;  
    vector<int> random_vector(ARRAY_SIZE);
    generate(random_vector.begin(), random_vector.end(), rand);
    return random_vector;
}

int main(int argc, char **argv)
{

    while (true)
    {
        vector<int> a = generate_random_vector();
        int naive_result, dandq_result;

        auto naive_start = std::chrono::high_resolution_clock::now();
        naive_result = naive_counting_inversions(a);
        auto naive_finish = std::chrono::high_resolution_clock::now();

        auto dandq_start = std::chrono::high_resolution_clock::now();
        dandq_result = dandq_counting_inversions(a);
        auto dandq_finish = std::chrono::high_resolution_clock::now();

        auto naive_time = (naive_finish - naive_start).count();
        auto dandq_time = (dandq_finish - dandq_start).count();

        if (dandq_result == naive_result)
        {
            cout << "equivalent ";
            cout << "naive_time ==> " << naive_time;
            cout << "dandq_time ==> " << dandq_time;
            cout << "performance enhancment ==> " << float(naive_time) / dandq_time << endl;
        }
        else
        {
            cout << "error, check your inputs and algortihms " << endl;
            break;
        }
    }
    return 0;
}