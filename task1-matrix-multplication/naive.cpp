#include <bits/stdc++.h>
using namespace std;

/**
 * implement the naive matrix multiplication algorithm
 * 
 * @param
 *  a --> a 2d vector
 *  b --> a 2d vector
 * 
 * @return
 * the result of a*b "matrix multiplcation"
*/

vector<vector<int>> naive(vector<vector<int>>, vector<vector<int>>, int, int, int);



vector<vector<int>> naive(vector<vector<int>> a, vector<vector<int>> b, int row, int col, int c1){

    vector<vector<int>> c{ { 0, 0 },{ 0, 0} };

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
        
    }
    return c;
    
}   


int main()
{
    vector<vector<int>> A{ { 1, 1 },{ 2, 2} };
	vector<vector<int>> B{ { 3, 3 },{ 4, 4} }; 
	vector<vector<int>> C{ { 0, 0 },{ 0, 0} };
	
    int r1 = 2;
    int c1 = 2;
    int r2 = 2;
    int c2 = 2;

    naive(A, B, r1, c2, c1);
    return 0;
}
