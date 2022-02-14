#include <iostream>
#include <cmath>
#include <cstdint>

const int SIZE = 10;

//TASK_1
//������� ����� Power, ������� �������� ��� ������������ �����. 
//���� ����� ������ ����� ��� ����������-����� ��� �������� ���� ������������ �����. 
//��� ������� ��� ������: 
//���� � ������ set, ������� �������� ����������� �������� ����������� � ������ ����������, 
//������ � calculate, ������� ����� �������� ��������� ���������� ������� ����� � ������� ������� �����. 
//������ �������� ���� ���� ����� �� ���������.
class Power {
private:
	float a = 2.3;
	float b = 1.2;
public:
	void set(float x, float y) {
		a = x;
		b = y;
	}
	void calculate() {
		std::cout << pow(a, b) << std::endl;
	}
};

//TASK_2
//�������� ����� � ������ RGBA, 
//������� �������� 4 ���������� - ����� ���� std::uint8_t: 
//m_red, m_green, m_blue � m_alpha(#include cstdint ��� ������� � ����� ����).
//������ 0 � �������� �������� �� ��������� ��� m_red, m_green, m_blue � 255 ��� m_alpha.
//������� ����������� �� ������� ������������� ������, 
//������� �������� ������������ ���������� �������� ��� m_red, m_blue, m_green � m_alpha.
//�������� ������� print(), ������� ����� �������� �������� ���������� - ������.
class RGBA {
private:
	std::uint8_t m_red = 0;
	std::uint8_t m_green = 0;
	std::uint8_t m_blue = 0;
	std::uint8_t m_alpha = 255;
public:
	RGBA(std::uint8_t a, std::uint8_t d, std::uint8_t b, std::uint8_t x) : m_red(a), m_green(d), m_blue(b), m_alpha(x) {};
	void print() {
		std::cout << m_red << m_green << m_blue << m_alpha << std::endl;
	}
};

//TASK_3
//�������� �����, ������� ��������� ���������������� �����. ����� Stack ������ �����:
//� private - ������ ����� ����� ������ 10;
//� private ������������� �������� ��� ������������ ����� �����;
//� public - ����� � ������ reset(), ������� ����� ���������� ����� � ��� �������� ��������� �� 0;
//� public - ����� � ������ push(), ������� ����� ��������� �������� � ����.push() ������ ���������� �������� false, ���� ������ ��� ��������, � true � ��������� ������;
//� public - ����� � ������ pop() ��� ����������� � �������� �������� �� �����.���� � ����� ��� ��������, �� ������ ���������� ��������������;
//� public - ����� � ������ print(), ������� ����� �������� ��� �������� �����.

class Stack {
private:
	
	int array[SIZE];
	int value = SIZE;
public:

	void reset() {
		for (int i = 0; i < value - 1; i++)
			array[i] = 0;
	}

	int push(int x) {
		for (int i = 0; i < value - 1; i++)
		{
			if (array[i] == 0) {
				array[i] = x;
				return true;
			}	
		}
		return false;
	}


	int pop() {
		for (int i = 0;  i < value - 1; i++)
		{
			if (array[i] == 0) {
				array[i-1] = 0;
				return true;
			}
		}
		
	}

	void print() {
		for (int i = 0; i < value - 1; i++)
			if(array[i] != 0)std::cout << array[i];
		std::cout << std::endl;
	}
};

int main() {
	//TASK_1
	Power a;
	a.set(4.2, 3.2);
	a.calculate();

	
	//TASK_2
	RGBA b(0,0,0,255);
	b.print();

	//TASK_3
	
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;

}