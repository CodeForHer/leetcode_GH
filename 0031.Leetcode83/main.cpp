#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Make_list(vector<int>& vec){
    int n = vec.size();
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    for(int i=0;i<n;i++){
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    cur = dummy->next;
    delete dummy;
    return cur;
}

void Show_list(ListNode* head){
    ListNode* point = head;
    while(point!=NULL){
        cout<<point->val<<"->";
        point=point->next;
    }
    cout<<"NULL";
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->next==NULL)
                break;
            ListNode* next = cur->next;
            if(cur->val==next->val){
                cur->next = next->next;
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
