#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode;
void printList(ListNode *head);
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //��һ���սڵ㣬����ɾ����һ���ڵ�������ڵ�Ĳ�����һ����
        ListNode header = ListNode(0);
        header.next = head;
        head = &header;
        //����˫ָ�뷨
        ListNode * temp = head;
        ListNode * last = head;
        //�Ƚ�last��ǰ��n��
        for (int i = 0; i < n+1; i++) {
            last = last->next;
        }
        //Ȼ��temp��lastһ�������ߣ�֪��last�ߵ������ʱtempָ������n���ڵ�
        while (last != NULL) {
            temp = temp->next;
            last = last->next;
        }
        ListNode *del = temp->next;
        temp->next = temp->next->next;   //ɾ��������n���ڵ�
        delete del;          //�ͷ��ڴ�ռ�
        return head->next;
    }
};
//���ڲ��Ե�������
int main() {
    ListNode head = ListNode(0);
    ListNode * temp = &head;
    int l = 0;
    cout << "����������ĳ��ȣ�";
    cin >> l;
    cout << endl;
    int nodeVal = 0;
    for (int i = 0; i < l; i++) {
        cin >> nodeVal;
        temp->val = nodeVal;
        if (i != l-1) {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
    }
    printList(&head);
    int n = 0;
    cout << "������Ҫɾ��������n���ڵ��n��ֵ��";
    cin >> n;
    cout << endl;
    Solution solution;
    temp = solution.removeNthFromEnd(&head, n);
    printList(temp);
    return 0;
}

//�������
void printList(ListNode *head) {
    ListNode * temp = head;
    while (temp != NULL) {
        cout << temp->val;
        temp = temp->next;
        if (temp != NULL) {
            cout << "->";
        }
        else {
            cout << endl;
        }
    }
}