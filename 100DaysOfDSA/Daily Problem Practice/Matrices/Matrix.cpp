#include "Matrix.h"

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

// Ques-1 Set Matrix Zeroes
void MatrixProblems::set_matrix_zeroes(vector<vector<int>>& matrix){
    /*
        NOTE:-
        Time complexity cannot be optimized below O(mn)
        because we need to access and check every element in the mxn matrix

        APPROACH:-
        We store the information about which row and column to make zero
        in the first row and column of the matrix itself
    */

    // first column in completely used to store the row information
    // thus one extra variable is needed to store information about the first index of column
    int col0=1;

    // if there is a 0 in the first column
    for(int i=0 ; i<matrix[0].size() ; i++){
        if( matrix[0][i] == 0 ){
            col0 = 0;
        }
    }

    // if there is a 0 in the first row
    for(int i=0 ; i<matrix.size() ; i++){
        if( matrix[i][0] == 0 ){
            matrix[0][0] = 0;
        }
    }

    // all the other elements
    for(int i=1 ; i<matrix.size(); i++){
        for(int j=1 ; j<matrix[0].size() ; j++){
            if( matrix[i][j] == 0 ){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // now we start making the rows and columns zero using the acquired information
    // start by changing only the elements in the matrix without first row and column
    for(int i=1 ; i<matrix.size() ; i++){
        if( matrix[i][0] == 0 ){
            for(int j=1 ; j<matrix[0].size() ; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=1 ; i<matrix[0].size() ; i++){
        if( matrix[0][i] == 0 ){
            for(int j=1 ; j<matrix.size() ; j++){
                matrix[j][i] = 0;
            }
        }
    }

    // now we need to change the first row and column based on values of extra variable
    if( matrix[0][0]==0 && col0==0 ){
        // both first row and column must be entirely zero
        for(int i=0 ; i<matrix.size() ; i++){
            matrix[i][0] = 0;
        }
        for(int i=0 ; i<matrix[0].size() ; i++){
            matrix[0][i] = 0;
        }
    }
    else if( matrix[0][0]==0 && col0!=0 ){
        for(int i=0 ; i<matrix.size() ; i++){
            matrix[i][0] = 0;
        }
    }
    else if( matrix[0][0]!=0 && col0==0 ){
        for(int i=0 ; i<matrix[0].size() ; i++){
            matrix[0][i] = 0;
        }
    }
}

// Ques-2 Rotate Image
void MatrixProblems::rotate_image(vector<vector<int>>& matrix){
    /*
        NOTE:-

        APPROACH:-
        first find the transpose of the matrix
        then reverse the order of columns in the matrix
    */

    // first we should transpose the matrix
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[0].size() ; j++){
            if( i<j ){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // now we want to reverse the order of columns in the matrix
    int left = 0; // first column
    int right = matrix[0].size()-1; //last column

    while( left < right ){
        for(int i=0 ; i<matrix.size() ; i++){
            swap( matrix[i][left], matrix[i][right] );
        }

        left++;
        right--;
    }

}

// Ques-3 Search in 2D matrix
bool MatrixProblems::search_matrix(vector<vector<int>>& matrix, int target){
    /*
        NOTE:-

        APPROACH:-
        Start from a corner in the matrix where the element is positioned
        as in the middle of a sorted array.
        1) if we start from bottom left corner
        => element right to it is greater
        => element above it is smaller

        -> Move in a binary search fashion in the direction by comparison
        to the corner element
    */

    // we start from the bottom left corner
    int start_row = matrix.size()-1;
    int start_col = 0;

    while( (start_row>=0) && (start_col<=matrix[0].size()-1) ){
        if( matrix[start_row][start_col] == target ){
            return true;
        }
        else if(matrix[start_row][start_col] < target){
            start_col++;
        }
        else if(matrix[start_row][start_col] > target){
            start_row--;
        }
    }

    return false;

}