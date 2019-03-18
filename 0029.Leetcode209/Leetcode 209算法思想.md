# Leetcode 209(Reverse Linked List)

## 题目链接
[Reverse Linked List](https://leetcode-cn.com/classic/problems/reverse-linked-list/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 就地反转链表，需要设置三个临时指针，cur,pre,next。cur指向当前处理的节点，next指向当前节点的后一个节点，pre指向当前节点的前一个节点。
- 在反转的过程中，首先要更新next指针，将其设置为当前节点的next指针，之后当前节点的next指针要指向pre，之后更新pre，pre更新为当前节点，当前节点更新为next。

### 方法1代码：
```
	
	class Solution {
	public:
	    ListNode* reverseList(ListNode* head) {
	        ListNode* pre = NULL;
	        ListNode* cur = head;
	        while(cur!=NULL){
	            ListNode* next = cur->next;//这句写在外面可能产生bug，当cur为空的时候
	            cur->next = pre;
	            pre = cur;
	            cur = next;
	        }
	        return pre;
	    }
	};


```


