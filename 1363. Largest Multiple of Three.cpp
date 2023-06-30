class Solution {
public:
    void findIndices(vector<int>&digits,int& first,int& second,int rem){
            for(int i=0;i<digits.size();i++){
                if(digits[i] % 3 == rem){
                    if(first == -1) first = i;
                    else{
                        second = i;
                        break;
                    }
                }
            }
    }

    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        sort(digits.begin(),digits.end());
        int sum = accumulate(digits.begin(),digits.end(),0);
        
        string ans = "";
        if(sum % 3 != 0){
            int same = (sum % 3);
            int other = (same == 1 ? 2 : 1);

            bool isIdealFound = false;
            int first = -1,second = -1;

            findIndices(digits,first,second,same);
            if(first != -1){
                //if minimum elements with same remender found just remove this
                isIdealFound = true;
                digits[first] = -1;
            }

            if(!isIdealFound){
                //if same remainder element not found look for two with other rem and remove
                findIndices(digits,first,second,other);
                if(second == -1) return "";
                digits[first] = -1;
                digits[second] = -1;
            }
        }
        
        //calculating answer
        for(int i=n-1;i>=0;i--){
            if(digits[i] != -1) ans.push_back(digits[i] + '0');
        }
        
        if(ans.size() == 0) return "";
        else if(ans[0] == '0') return "0";

        return ans;
    }
};