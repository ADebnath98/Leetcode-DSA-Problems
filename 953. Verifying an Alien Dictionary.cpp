class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
    //CREATED A MAP TO STORE DICTIONARY ORDER
    // IF 'Z' COMES FIRST IN ALIEN DICTIONARY THEN
    // WE ASSIGN A VALUE '0' TO IT IN THE MAP AND SO ON
        unordered_map<char,int> ump;
        for(int i=0;i<order.length();i++){

            char ch=order[i];
            ump[ch]=i;
        }
    
    

        for(int i=0;i<words.size()-1;i++){
        
        //TRAVERSE IN THE WORDS ARRAY AND COMPARE TWO ADJACENT WORDS 

            string word1=words[i];
            string word2=words[i+1];
             int l1=word1.length();
            int l2=word2.length();
         
            
           
            int j=0,k=0;
            while(j<l1 && k<l2){
            
        //IF word1[i]==word2[i], then we do nothing and continue
  
                if(ump[word1[j]]>ump[word2[j]]){
                    return false;
                }
                else if(ump[word1[j]]<ump[word2[j]]){
                    break;;
                }
                j++;
                k++;
            }
          
        //if word2 gets over and word1 doesn't it means
        // in dictionary word2 should come first 
        //therefore we return false
            if(j!=l1 && k==l2){
                return false;
            }
           

        }

        return true;
    }
};