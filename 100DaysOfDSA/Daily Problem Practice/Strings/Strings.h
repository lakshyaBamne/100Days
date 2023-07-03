#include<string>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

class StringProblems{
public:
    /*
        Ques-1 Reverse Words

        LeetCode -> https://leetcode.com/problems/reverse-words-in-a-string/
    */
    static string trim_string(string s);
    static string reverse(string s);
    static string reverse_words(string s);

    /*
        Ques-2 Valid Palindrome

        LeetCode -> https://leetcode.com/problems/valid-palindrome/
    */
    static bool valid_palindrome(string s);

    /*
        Ques-3 Check if all A's appear before B's

        LeetCode -> https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
    */
    static bool check_A_before_B(string s);
};