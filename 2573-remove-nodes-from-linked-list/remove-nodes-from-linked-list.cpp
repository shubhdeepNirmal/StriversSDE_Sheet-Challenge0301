/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        temp=st.top();
        st.pop();
        int maxi= temp->val;
        head = new ListNode(maxi);
        while(!st.empty()){
            temp=st.top();
            st.pop();
            if(temp->val<maxi){
                continue;
            }
            else{
                ListNode* newhead= new ListNode(temp->val);
                newhead->next=head;
                head=newhead;
                maxi=temp->val;
            }
        }
        return head;
    }
};