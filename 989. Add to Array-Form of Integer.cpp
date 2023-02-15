Here is the full line by line explaination for the approach used.

Intuituion :
1. Store the last elements in the last index of the vector until the loop iterates the entire array.
2. Store the value of k and check if 0 or not.
3. If not zero store each element of k in the beginning of the vector until k is zero.
4. Return the ans vector.

Complexity :

  Time : O(N)+O(logN)
  Space : O(1)



class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
       //iterating from the back so that the digits gets individually added backwards of the ith digit of the array
        
       for(int i=num.size()-1;i>=0;i--)
       {
           num[i]+=k;  // taking the number k and adding into the number[i]
           k=num[i]/10; // taking the number k and storing only the remaining digitd of them
           num[i]=num[i]%10; //taking the num[i] and storing only the last remaining portion of the num[i]
       }
        
       // now if the k number has digits greater than the size of the array then we can just check and individually iterate by putting the last element of of k in the beginning of the vector as carries 
        
       while(k)
       {
           num.insert(num.begin(),k%10); // inserting the individual carries at the begining
           k/=10; // reducing the k's used digit in the num
       }
        
       return num; // ultimately returning the num
        
    }
    
};