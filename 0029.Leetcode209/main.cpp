#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
