#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(i<j){
            if(is_num_or_digit(s,i)){
                if(is_num_or_digit(s,j)){
                    if(s[i]==s[j]){
                        ++i;
                        --j;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    --j;
                }
            }
            else{
                ++i;
            }
        }
        return true;
    }
    bool is_num_or_digit(string s,int i){
        if((s[i]>='0'&&s[i]<='9')||(s[i] >='a' && s[i]<='z' )){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    //transform(s.begin(),s.end(),s.begin(),::tolower);
    cout <<Solution().isPalindrome(s) << endl;
    return 0;
}
