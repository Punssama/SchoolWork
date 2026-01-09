/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (56.25%)
 * Likes:    6088
 * Dislikes: 342
 * Total Accepted:    3.1M
 * Total Submissions: 5.3M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of words and spaces, return the length of the
 * last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */

// @lc code=start
class Solution
#include <string>
#include <iostream>
#include <cctype>
{
    bool isWord(string s)
    {
        bool flag = false;
        int letterCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (letterCount == 2)
            {
                flag = true;
                break;
            }
            if (isalpha(s[i]))
                letterCount += 1;
        }
        return flag;
    }

public:
    int lengthOfLastWord(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
        }
    }
};
// @lc code=end
