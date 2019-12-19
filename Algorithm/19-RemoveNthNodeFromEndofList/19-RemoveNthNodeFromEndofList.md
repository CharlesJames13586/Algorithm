### 19.Remove Nth Node From End of List
* Given a linked list, remove the n-th node from the end of list and return its head.

  ��һ������ɾ��������n���ڵ�Ȼ�󷵻������ͷ��
* **Example:**
  >Given linked list: 1->2->3->4->5, and n = 2.<br>
  After removing the second node from the end, the linked list becomes 1->2->3->5.<br>

  >��һ������1->2->3->4->5���ͱ���n = 2��<br>
  >Ȼ��ɾ�������ڶ����ڵ㣬ԭ���������Ϊ��1->2->3->5��<br>
  
* **Note:**

  Given n will always be valid.

  �����ı���n���ǺϷ��ġ�

* **Follow up:**

  Could you do this in one pass?

  ����һ��ͨ����

* **����˼·**

  &emsp;&emsp;����˫ָ�뷨��ʹ��last(��������Ƿ�ɨ�赽��������)��temp����ָ�롣�ڸտ�ʼ��ʱ��
  ����lastɨ��n+1���ڵ㣬Ȼ��temp��lastһ�����ɨ�裬��lastɨ�����һ���ڵ㣬temp�ڵ�
  ָ���˵���n+1���ڵ㣬Ȼ��ɾ��temp��̽ڵ㡣Ϊ����ɾ����Ԫ�ڵ�������ڵ������ͬ����
  ��������ǰ�����һ�����ӿսڵ㡣

  &emsp;&emsp;���㷨����ֻɨ��һ���ɾ���˵�����n���ڵ㣬������ʵ����������Ϊͬʱ���������ڵ㣬��
  ��ɨ��һ�������������С����ɨ��һ��ɾ��������n���ķ���ʵ������ʱ���ࡣ���Ǹ÷�
  ����Զ��ԱȽ���ӱһ�㡣