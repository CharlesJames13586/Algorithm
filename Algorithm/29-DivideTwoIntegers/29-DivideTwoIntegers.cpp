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
		int sign = 1;        //�̵ķ��ţ�1����(+)��-1����(-)
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
	//��������һ������ⷨ�����±�д��
	int divide(int dividend, int divisor) {
		if (dividend == 0) {
			//�����Ϊ0��ֱ�ӷ���0
			return 0;
		}
		switch (divisor){
		    case 0:
			    //�������Ϊ0��ֱ���˳�
			    exit(-1);
		    case 1:
		        //�������Ϊ1��ֱ�ӷ��ر���������������dividend=-2147483648��divisor=1ʱ�����
			    return dividend;
	        case -1:
		        //����Ϊ-1�����
			    if (dividend == INT32_MIN) {
				    return INT32_MAX; 
			    } else {
				    return -dividend;
			    }
		}
		
		long long quotient = 0;        //�̣�ʹ��long���ͱ�����������е��������
		int sign = 1;        //�̵ķ��ţ�1����(+)��-1����(-)
		if (dividend > 0 && divisor < 0 || dividend < 0 && divisor>0) {
			//����������ͳ�����ţ��̵ķ���Ϊ��
			sign = -1;
		}
		//һ�����
		long long dividend_abs = abs((long long)dividend), divisor_abs = abs((long long)divisor);          //ȡ�������ͳ����ľ���ֵ����
		while (dividend_abs >= divisor_abs) {    //�����������ڵ��ڳ���
			long long temp = divisor_abs, m = 1; //temp�ݴ�����ľ���ֵ��m�ݴ��̵Ĳ���ֵ
			while (temp << 1 <= dividend_abs) {  //������2(����һλ)��С�ڵ��ڱ�����ʱ
				//temp <<= 1;
				//m <<= 1;
				temp = temp << 1;      //������2
				m = m << 1;  //m��2
				//cout << temp << ' ' << m << endl;
			}
			dividend_abs = dividend_abs - temp;  //������������
			quotient = quotient + m;   //�̼����ݴ����
		}
		if (quotient > INT32_MAX) {
			quotient = INT32_MAX;
			//ע����=INT32_MIN��������ڳ���Ϊ1ʱ���أ���˴˴���������������
		}

		//return quotient * sign;      ����Ҫ����ʹ�ó˷�(����leetcoe���Ⲣδ���������)
		return sign > 0 ? quotient : -quotient;  //�ж�sign�ķ��ŷ�����
	}
};

//�������Ե�������
int main() {
	
	int dividend = 0, divisor = 1, quotient = 0;
	//gdb����ʱ�޷�������ģ����Խ���ʾ��Ϣ��Ϊ����
	//cout<<"�����뱻������";
	cout<<"Please enter the dividend:";
	cin >> dividend;
	cout << endl;
	//cout << "�����������";
	cout<<"Please enter the divisor:";
	cin >> divisor;
	cout << endl;
	Solution solution;
	quotient = solution.divide(dividend, divisor);
	//cout << "�̣�" << quotient << endl;
	cout<<"The quotient is "<< quotient << endl;
	
	return 0;
}