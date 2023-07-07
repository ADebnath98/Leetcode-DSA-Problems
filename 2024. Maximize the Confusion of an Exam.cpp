class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int i = 0, j = 0, trueCount = 0, falseCount = 0, maxConsecutive = INT_MIN;

        for(int j=0; j<answerKey.size(); j++)
        {
            if(answerKey[j] == 'T')
                trueCount++;
            else
                falseCount++;

            while(trueCount > k && falseCount > k)
            {
                if (answerKey[i++] == 'T')
                    trueCount--;
                else
                    falseCount--;
            }

            maxConsecutive = max(maxConsecutive, j-i+1);
        }

        return maxConsecutive;
    }
};