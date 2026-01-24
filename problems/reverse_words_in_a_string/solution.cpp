class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(),s.end());
        int p=0; int q=n-1;
        string news = "";
        while(p<q && s[p]==' '){
            p++;
        }
        while(p<q && s[q]==' '){
            q--;
        }
        for(int i=p;i<=q;i++) news+=s[i];
        string word = "";
        string ans = "";
        vector<string> words;
        // cout<<"|"<<news<<"|"<<endl;
        news+=" ";
        for(int i=0;i<news.size();i++){
            if(word!="" && news[i]==' '){
                reverse(word.begin(),word.end());
                words.push_back(word);
                word = "";
            }
            else if(news[i]!=' ') word+=news[i];
            else continue;
        }
        for(string str:words) {ans+=str+" ";}
        ans.pop_back();
        return ans;
    }
};