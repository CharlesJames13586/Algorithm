#include "pch.h"
#include <iostream>

using namespace std;

class Solution {
public:
	//�������㣬����ʵ�ֳ��������ǵ��������ݺܴ�ʱ����ʱ�����
	int divide_BruteForce(int dividend, int divisor) {
		if (divisor == 0) {
			//�������Ϊ0��ֱ���˳�
			exit(-1);
		}
		if (dividend == 0) {
			//�����Ϊ0��ֱ�ӷ���0
			return 0;
		}
		int quotient = 0;
		int sign = 1;    //�̵ķ��ţ�1����(+)��-1����(-)
		if (dividend > 0 && divisor < 0 || dividend < 0 && divisor>0) {
			//����������ͳ�����ţ��̵ķ���Ϊ��
			sign = -1;
		}
		//�����������
		if (dividend + 1 == -2147483647 && sign == -1) {
			//�����
			return 2147483647;
		}
		int temp;
		temp = dividend - divisor * sign;
		while (dividend > 0 && temp >= 0 || dividend < 0 && temp <= 0) {
			//cout << dividend << ' ' << temp << ' ' << quotient << endl;
			//�����������
			if ((quotient == 2147483647 && sign == 1) || (quotient +1 == -2147483647 && sign == -1)) {
				break;
			}
			quotient = quotient + sign;
			dividend = temp;
			temp = dividend - divisor * sign;
		}
		return quotient;
	}
	//��������һ������ⷨ�����±�д
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			//�������Ϊ0��ֱ���˳�
			exit(-1);
		}
		if (dividend == 0) {
			//�����Ϊ0��ֱ�ӷ���0
			return 0;
		}
		if (divisor == 1) {
			//�������Ϊ1��ֱ�ӷ��ر���������������dividend=2147483647��divisor=1ʱ�м�������������
			return dividend;
		}
		//�������
		if (divisor == -1) {
			if (dividend == INT_MIN) {
				return INT_MAX;
			}
			else {
				return -dividend;
			}
		}
		
		int quotient = 0;    //��
		int sign = 1;        //�̵ķ��ţ�1����(+)��-1����(-)
		if (dividend > 0 && divisor < 0 || dividend < 0 && divisor>0) {
			//����������ͳ�����ţ��̵ķ���Ϊ��
			sign = -1;
		}
		//һ�����
		int dividend_abs = abs(dividend), divisor_abs = abs(divisor);          //ȡ�������ͳ����ľ���ֵ����
		while (dividend_abs >= divisor_abs) {   //�����������ڳ���
			int temp = divisor_abs, m = 1;
			while (temp << 1 <= dividend_abs) {  //������2���뱻�������
				//temp <<= 1;
				//m <<= 1;
				temp = temp << 1;      //������2
				m = m << 1;  //m��2
				cout << temp << ' ' << m << endl;
			}
			dividend_abs = dividend_abs - temp;  //������������
			quotient = quotient + m;
		}

		//return quotient * sign;      ����Ҫ����ʹ�ó˷�(����leetcoe���Ⲣδ���������)
		return sign > 0 ? quotient : -quotient;  //�ж�sign�ķ��ŷ�����
	}
};

//�������Ե�������
int main() {
	
	int dividend = 0, divisor = 1, quotient = 0;
	cout << "�����뱻������";
	cin >> dividend;
	cout << endl;
	cout << "�����������";
	cin >> divisor;
	cout << endl;
	Solution solution;
	quotient = solution.divide(dividend, divisor);
	cout << "�̣�" << quotient << endl;
	
	return 0;
}