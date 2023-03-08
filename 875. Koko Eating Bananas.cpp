class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // initial binary search range
        int mink, maxk = piles[0], midk, midh;
        long tmp = 0;
        for (int i : piles) {
            if (i > maxk) { // maxk: all piles eaten in one step
                maxk = i;
            }
            tmp += i; // mink: one big pile which must be eaten in h hours
        }
        mink = ceil(double(tmp) / h);

        // binary search loop
        while (mink != maxk) {
            midk = (mink + maxk) / 2;

            // break if infinite loop
            if (midk == mink or midk == maxk) {
                break;
            }

            // check how many hours to eat all piles
            midh = 0;
            for (int i = 0; i < piles.size(); i++) {
                midh += ceil(double(piles[i]) / midk);
            }

            // update binary search range
            if (midh > h) { // k too low
                mink = midk;
            }
            else { // k can be minimised
                maxk = midk;
            }
        }

        // check in mink satisifes the condition
        midh = 0;
        for (int i = 0; i < piles.size(); i++) {
            midh += ceil(double(piles[i]) / mink);
        }

        if (midh <= h) {
			return mink;
		}
        else {
            return maxk;
        }
    }
};