// search in 2D arrays
/*You are given an m x n integer matrix matrix with the following two 
properties: Each row is sorted in non-decreasing order.
            The first integer of each row is greater than the last 
            integer of the previous row.
Given an integer target, return true if target is in matrix or false 
otherwise. You must write a solution in O(log(m * n)) time complexity.
 */
//write c++ code

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = matrix[mid / n][mid % n];
        if(midVal == target) return true;
        if(midVal < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
};

int main() {
    vector<vector<int>> matrix = {{1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}};
    cout << searchMatrix(matrix, 3) << endl; // true
    cout << searchMatrix(matrix, 15) << endl; // false
    return 0;
}