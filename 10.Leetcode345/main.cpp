#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(isVowels(s,i)){
                if(isVowels(s,j)){
                    swap(s[i],s[j]);
                    ++i;
                    --j;
                }
                else{
                    --j;
                }
            }
            else{
                ++i;
            }
        }
        return s;
    }
    bool isVowels(string s,int num){
        string vowels ="aeiouAEIOU";
        for(int i=0;i<vowels.size();++i){
            if(s[num]==vowels[i])
                return true;
        }
        return false;
    }
};

int main()
{
    string s = "hello";
    cout<<Solution().reverseVowels(s);
    return 0;
}
