Intuition
Proposed Solutions
1. Recursive Approach (Top-Down)
Approach
Complexity
Time complexity: O(N∗M)O(N * M)O(N∗M)
Since we are iterating over all the N words and in each word we try all possible predecessor by removing one character a time then the timE complexity is O(N * M).
remember that we eleminated redundant calls by using DP;`
Space complexity: O(N)O(N)O(N)
We store two HashMaps each of size N then the space we are storing is 2 * N then the space complexity it O(N).

2. Iterative Approach (Bottom-Up)
Approach
Complexity
Time complexity: O(N∗M)O(N * M)O(N∗M)
Since we are iterating over all the N words and in each word we try all possible predecessor by removing one character a time then the timE complexity is O(N * M).
remember that we eleminated redundant calls by using DP;`
Space complexity: O(N)O(N)O(N)
We store one HashMaps of size N then the space we are storing is N then the space complexity it O(N).



1. Recursive Approach (Top-Down)

class Solution {
private:
    unordered_map<string, int> chain_lengths;
    unordered_map<string, bool> word_set;

    int calculateChainLength(const string &word) {
        // If the word doesn't exist in the set
        if (word_set.find(word) == word_set.end())
            return 0;

        // If chain length for the word is already calculated
        if (chain_lengths.find(word) != chain_lengths.end())
            return chain_lengths[word];

        int chain_length = 1;

        // Try removing one character at a time from the word and calculate chain length
        for (int i = 0; i < word.size(); i++) {
            string new_word = word.substr(0, i) + word.substr(i + 1);
            chain_length = max(chain_length, 1 + calculateChainLength(new_word));
        }

        chain_lengths[word] = chain_length;
        return chain_length;
    }

public:
    int longestStrChain(vector<string> &words) {
        for (const auto &word : words) {
            word_set[word] = true;
        }

        int max_chain_length = -1;

        // Calculate the maximum chain length for each word
        for (const auto &word : words) {
            max_chain_length = max(max_chain_length, calculateChainLength(word));
        }

        return max_chain_length;
    }
};

2. Iterative Approach (Bottom-Up)


class Solution {
public:

    int longestStrChain(vector<string>& words) {
        // Sort the words by their lengths
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        // Map to store the longest chain length for each word
        unordered_map<string, int> longestChainLength;

        // Initialize the answer
        int maxChainLength = -1;

        for(auto &word: words){
            // Initialize the chain length for the current word
            longestChainLength[word] = 1;

            // Try removing one character at a time from the word and check if the resulting word exists
            for(int i = 0 ; i < word.size() ; i++){
                string reducedWord = word.substr(0, i) + word.substr(i + 1) ;

                // If the reduced word exists in the map
                if(longestChainLength.find(reducedWord) != longestChainLength.end())
                    // Update the chain length for the current word
                    longestChainLength[word] = max(longestChainLength[word], longestChainLength[reducedWord] + 1) ;
            }

            // Update the maximum chain length seen so far
            maxChainLength = max(maxChainLength, longestChainLength[word]) ;
        }

        return maxChainLength;
    }
};


