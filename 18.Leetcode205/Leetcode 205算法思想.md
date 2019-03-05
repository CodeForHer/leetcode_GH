# Leetcode 205(Isomorphic Strings)

## 题目链接
[Isomorphic Strings](https://leetcode-cn.com/problems/isomorphic-strings/description/)

## 算法思想

### 方法1：

- 首先判断两个字符串的长度是否相同，不相同直接返回false
- 设置一个哈希表hashmap，用来存放字符的对应关系。以s字符串为基准（以s字符串为基准的意思是hashmap的键值为s[i]，key值为t[i]），遍历两个字符串s和t，如果hashmap[s[i]]没有对应值，则将hashmap[s[i]]设置为t[i]；如果hashmap[s[i]]有对应值，则看他的值是否与t[i]相同，不相同则返回false
- 注意，以上方法只遍历一遍是不够的，因为要保证s->t和t->s均为一一映射。例如s="ab",t="aa"，只遍历一遍的话，hashmap['a']='a',hashmap['b']='a'，程序返回true，但是对于t字符串来说，'a'字符即映射到'a',同时映射到'b'，不符合条件。因此，还需要以t字符串为基准，再遍历一遍

### 方法1代码：
```

	bool isIsomorphic(string s, string t) {
        return isIsomorphic_sub(s,t)&&isIsomorphic_sub(t,s);
    }

    bool isIsomorphic_sub(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char> map_char;
        for(int i=0;i<s.size();++i){
            if(map_char[s[i]]=='\0'){
                map_char[s[i]]=t[i];
            }
            else{
                if(map_char[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }


```
