#include "Strings.h"

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

// function to trim all the whitespaces from a string from the left and right
// this happend in O(n) time complexity and O(n) space complexity
string StringProblems::trim_string(string s){
    string output = "";
    
    // first trimming from the left
    int left = 0;

    while( ((int)s[left] == 32) && (left < s.size()) ){
        left++;
    }

    int right = s.size()-1;
 
    while( ((int)s[right] == 32) && (right >= 0) ){
        right--;
    }

    for(int i=left ; i<=right ; i++){
        output.push_back(s[i]);
    }

    return output;


}

// method to reverse a stringt that is trimmed from both sides of white spaces
string StringProblems::reverse(string s){
    string output = "";

    int right = s.size()-1;
    int left;

    while( right > 0 ){
        while( (int)s[right] == 32 ){
            right--;
        }

        left = right;

        while( (left > 0) && (int)s[left]!=32 ){
            left--;
        }

        if( left != 0 ){
            for(int i=left+1 ; i<=right ; i++){
                output.push_back(s[i]);
            }
            output.push_back(32);
        }
        else{
            for(int i=left ; i<=right ; i++){
                output.push_back(s[i]);
            }
        }

        right = left;

    }

    return output;
}

// Ques-1 Reverse Words
string StringProblems::reverse_words(string s){
    string output;

    // first let us trim the string from the left and right for white spaces
    output = trim_string(s);

    output = reverse(output);

    return output;
}


// Ques-2 Valid Palindrome
bool StringProblems::valid_palindrome(string s){
    return true;
}

// Ques-3 Check if all A's appear before B's
bool StringProblems::check_A_before_B(string s){
    int left=0;
    int right=s.size()-1;

    while( (s[left] == 'a') && (left <s.size()) ){
        left++;
    }
    while( (s[right] == 'b') && (right >= 0) ){
        right--;
    }

    if( left < right ){
        return false;
    }
    else{
        return true;
    }

}

