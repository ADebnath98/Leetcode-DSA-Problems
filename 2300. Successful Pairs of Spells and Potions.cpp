class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());

        for (int i=0;i<spells.size();i++)
        {
            int l = 0, h = potions.size();
            while (l < h)
            {
                int m = l + (h - l) / 2;
                if ((long long)spells[i] * potions[m] >= success)
                    h = m;
                else
                    l = m + 1;
            }
            spells[i] = potions.size() - l;
        }

        return spells;
    }
};