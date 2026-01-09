#
# @lc app=leetcode id=14 lang=python
#
# [14] Longest Common Prefix
#


# @lc code=start
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        min_len = len(min(strs))
        for i in range(min_len):
            ch = strs[0][i]
            for w in strs:
                if ch != w[i]:
                    return strs[0][:i]
        return min(strs)


# @lc code=end
