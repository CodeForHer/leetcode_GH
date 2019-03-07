#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = make_words(str);
        unordered_map<char,string> ch_to_str;
        unordered_map<string,char> str_to_ch;
        if(pattern.size()!=words.size()){
            return false;
        }
        for(int i=0;i<pattern.size();++i){
            if(ch_to_str[pattern[i]]==""){
                ch_to_str[pattern[i]]=words[i];
            }
            else{
                if(ch_to_str[pattern[i]]!=words[i]){
                    return false;
                }
            }
            if(str_to_ch[words[i]]=='\0'){
                str_to_ch[words[i]]=pattern[i];
            }
            else{
                if(str_to_ch[words[i]]!=pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> make_words(string &str){
        vector<string> res;
        string temp;
        for(int i=0;i<str.size();++i){
            if(i!=str.size()-1){
                if(str[i]!=' ')
                    temp.push_back(str[i]);

                else{
                    res.push_back(temp);
                    temp = "";
                }
            }
            else
            {
                temp.push_back(str[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
    void show_vec(vector<string>& vec){
        for(int i=0;i<vec.size();++i){
            cout<<vec[i]<<"";
        }
    }
};

int main()
{
    string pattern = "abba", str = "dog dog dog dog";
    cout<<Solution().wordPattern(pattern,str);
    return 0;
}
