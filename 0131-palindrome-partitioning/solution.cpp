class Solution {
public:
    bool ispal(string s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    void parts(string s,vector<vector<string>> &ans,vector<string> &config){
        int n = s.length();
        if(s.empty()){
            ans.push_back(config);
            return;
        }
        for(int i=0;i<n;i++){ //loop over the string
            string firsthalf = s.substr(0,i+1); //split 
            if(ispal(firsthalf)){ //if the first half is palndrome. 
                config.push_back(firsthalf); //save it
                parts(s.substr(i+1),ans,config); //look for palindrome in 2nd half
                config.pop_back(); //backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //aab -> {{a a b} {aa b}}  what if a config is made when base case is reached?
        //so we are suppose to partition it? whats partition. its when i slice the array and have its 2 parts, firt half, second half.
        //when should i split the string?. lets go greedy. we split right when we find a palindrome.
        //so we split when first half becomes a palindrome. what about second half?
        //well, second half aint palindrome. but remeber, we goin greedy? 
        //so we look for palindrome again, this time in the 2nd half. split when we find, then 
        //repeat same process for all second halfs (non palindromes).
        //since we are doin same process again and again, find palindrome, save, find more palindrome for 2nd halves, save, repeat.  we use reccursion. 
        vector<vector<string>> ans;
        vector<string> config;
        int n = s.length();
        parts(s,ans,config);
        return ans;
    }
};
