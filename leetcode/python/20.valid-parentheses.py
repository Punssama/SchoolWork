#
# @lc app=leetcode id=20 lang=python
#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses/description/
#
# algorithms
# Easy (42.28%)
# Likes:    25847
# Dislikes: 1884
# Total Accepted:    6.1M
# Total Submissions: 14.4M
# Testcase Example:  '"()"'
#
# Given a string s containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
#
# An input string is valid if:
#
#
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
#
#
#
# Example 1:
#
#
# Input: s = "()"
#
# Output: true
#
#
# Example 2:
#
#
# Input: s = "()[]{}"
#
# Output: true
#
#
# Example 3:
#
#
# Input: s = "(]"
#
# Output: false
#
#
# Example 4:
#
#
# Input: s = "([])"
#
# Output: true
#
#
#
# Constraints:
#
#
# 1 <= s.length <= 10^4
# s consists of parentheses only '()[]{}'.
#
#
#


# @lc code=start
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        bracket_map = {")": "(", "}": "{", "]": "["}
        stack = []
        for ch in s:
            if ch in bracket_map.values():
                stack.append(ch)
            elif ch in bracket_map:
                if not stack or stack[-1] != bracket_map[ch]:
                    return False
                stack.pop()
        return not stack


# @lc code=end
