# Leetcode 242(Valid Anagram）

## 题目链接
[Valid Anagram](https://leetcode-cn.com/problems/valid-anagram/description/)

## 算法思想

### 方法1：

- 设置一个哈希表hashmap用来统计字符串s每个字符的频率，之后遍历字符串t。若遍历的时候hashmap[t[i]]不为0，则对hashmap[t[i]]做减一操作；若hashmap[t[i]]为0，则说明s字符串和t字符串对于字符t[i]的频率不等。
- 之后再对哈希表进行一次遍历，做此时哈希表仍存在不为0的key值，说明s字符串和t字符串字符频率不等

### 方法1代码：
```

	bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();++i){
            freq[s[i]]++;
        }
        for(int i=0;i<t.size();++i){
            if(freq[t[i]]==0){
                return false;
            }
            freq[t[i]]--;
        }
        for(unordered_map<char,int>::iterator iter=freq.begin();iter!=freq.end();++iter){
            if(iter->second!=0){
                return false;
            }
        }
        return true;
    }


```
