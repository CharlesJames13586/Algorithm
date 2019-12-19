#include "pch.h"
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
	ListNode* swapPairs(ListNode* head) {
		//��ͷ�����һ�����ӿսڵ㣬ʹ��Ԫ�ڵ��ɾ��������Ԫ�ڵ�ǰ����һ���ڵ�������ڵ�Ĳ���һ�£�
		ListNode header = ListNode(0);
		header.next = head;
		head = &header;
		ListNode * pre = head;         //ָ�򸽼ӿսڵ㣬��Ԫ�ڵ��ǰһ��
		ListNode * cur = head->next;   //ָ����Ԫ�ڵ�
		//�� ��ǰ�ڵ� ���ڲ����� ��̽ڵ� ʱ
		while (cur!=NULL && cur->next != NULL) {
			pre->next = cur->next;     //����ǰ�ڵ�������жϿ�
			cur->next = pre->next->next;         //����ǰ�ڵ��ԭ��̽ڵ�ĺ�̽ڵ㸳����ǰ�ڵ�
			pre->next->next = cur;     //����ǰ�ڵ��ٷ��û�����
			//pre��ǰ��������cur��ǰ��һ��
			pre = cur;       //����preָ��
			cur = cur->next; //����curָ��
		}
		//����ʱע��ȥ�����ӿսڵ�
		return head->next;
	}
};

//���ڲ��Ե�������
int main() {
	//����һ������
	ListNode * head = &ListNode(0);
	ListNode * temp = head;
	int l = 0;
	cout << "����������ĳ��ȣ�";
	cin >> l;
	cout << endl;
	int nodeVal = 0;
	for (int i = 0; i < l; i++) {
		cin >> nodeVal;
		temp->val = nodeVal;
		if (i != l - 1) {
			temp->next = new ListNode(0);
			temp = temp->next;
		}
	}
	printList(head);
	//�����������ڽڵ�
	Solution solution;
	head = solution.swapPairs(head);
	printList(head);         //��������������
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