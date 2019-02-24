# Leetcode 345(Reverse vowels of a string)

## 题目链接
[Reverse vowels of a string](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 对撞指针的思想，找到元音互换即可

```

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
```