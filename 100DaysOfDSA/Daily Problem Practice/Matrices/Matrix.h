#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

class MatrixProblems{
    /*
        Ques-1 Set Matrix Zeroes

        LeetCode -> https://leetcode.com/problems/set-matrix-zeroes/
        CodingNinjas -> https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    */
    static void set_matrix_zeroes(vector<vector<int>>& matrix);
    
    /*
        Ques-2 Rotate Image

        LeetCode -> https://leetcode.com/problems/rotate-image/
    */
    static void rotate_image(vector<vector<int>>& matrix);

    /*
        Ques-3 Search in 2D matrix

        LeetCode -> https://leetcode.com/problems/search-a-2d-matrix/
    */
    static bool search_matrix(vector<vector<int>>& matrix, int target);
};