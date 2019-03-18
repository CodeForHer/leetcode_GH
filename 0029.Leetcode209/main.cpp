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
            ListNode* next = cur->next;//���д��������ܲ���bug����curΪ�յ�ʱ��
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
