Intuition
Traverse the haystack string with a sliding window of the size of the needle.

Approach
Traverse the haystack string with a sliding window of the size of the needle.
Using a temporary string, append the first n characters (size of needle) to the temporary variable
If the temporary variable matches the needle, return the (CurrentIndex−sizeofneedle)(Current Index - size of needle)(CurrentIndex−sizeofneedle) as the answer, else keep iterating
Return -1 as we did not find any string matching to the given parameters
Complexity
Time complexity:
O(n)O(n)O(n)

Space complexity:
O(needle.size)O(needle.size)O(needle.size)

class Solution {
public:
    int strStr(string haystack, string needle) {
    int needleSize = needle.size();
    string traverse(needleSize, 'a');
    int ans = -1;

    for (int i = 0; i < needleSize; i++)
    {
        traverse[i] = haystack[i];
    }

    for (int i = needleSize; i <= haystack.size(); i++)
    {
        if (traverse == needle)
            return i - needleSize;
        traverse.erase(0, 1);
        traverse += haystack[i];
    }
    return ans;

    }
};