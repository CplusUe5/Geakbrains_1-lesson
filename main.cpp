#include <iostream>
#include <cmath>
#include <cstdint>

const int SIZE = 10;

//TASK_1
//Создать класс Power, который содержит два вещественных числа. 
//Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
//Еще создать два метода: 
//один с именем set, который позволит присваивать значения объявленным в классе переменным, 
//второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
//Задать значения этих двух чисел по умолчанию.
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
//Написать класс с именем RGBA, 
//который содержит 4 переменные - члена типа std::uint8_t: 
//m_red, m_green, m_blue и m_alpha(#include cstdint для доступа к этому типу).
//Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
//Создать конструктор со списком инициализации членов, 
//который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
//Написать функцию print(), которая будет выводить значения переменных - членов.
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
//Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
//• private - массив целых чисел длиной 10;
//• private целочисленное значение для отслеживания длины стека;
//• public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//• public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
//• public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;
//• public - метод с именем print(), который будет выводить все значения стека.

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