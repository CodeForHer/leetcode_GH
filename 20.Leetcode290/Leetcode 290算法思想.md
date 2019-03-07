# Leetcode 290(Word Pattern）

## 题目链接
[Word Pattern](https://leetcode-cn.com/problems/word-pattern/)

## 算法思想

### 方法1：

- 首先要把被匹配的字符串拆解为一个个的单词（函数：make_words），将其放在一个vector中
- 为了防止做前面几道类似题目出现的错误，我们设置两个哈希表，分别表示字符->单词、单词->字符，这样在一次遍历中即可判断

### 方法1代码：
```

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


```
