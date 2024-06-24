#include <iostream>
#include <string>
#include "Number.hpp"



class Point {
public:
	double x{};
	double y{};
	
	Point(double oX, double oY) : x{ oX }, y{ oY } {
		std::cout << "!\n";
	}
	Point(double oC) : Point(oC, oC){}
	
	Point() : Point(0., 0.){}

	Point( const Point& other) {
		std::cout << "COPY\n";
		this->x = other.x;
		this->y = other.y;
	}

	void print() {
		std::cout << '(' << x << ", " << y <<")\n";
	}

	double distanceTo(Point other) {
		return sqrt(
			pow(other.x - x, 2) +
			pow(other.y - y, 2)
		);
	}

	void printMemory() {
		std::cout << this << std::endl;
	}
	void setPos(double x, double y) {
		this->x = x;
		this->y = y;
	}

};




int main() {
	setlocale(LC_ALL, "russian");
	int n;

	//Класс Point

	int a = 10; //Копирующая инициализация
	int b = a;
	int x(10); //Прямая инициализция
	int y(x);
	int m{ 10 };//Унифицированая инициализация

	Point p1(5.5, 7.7);
	Point p2(10.0);
	Point p3;
	p1.print();
	p2.print();
	p3.print();

	Point p4(p2);
	p4.print();

	std::cout << p1.distanceTo(p4) << std::endl;
	std::cout << p1.distanceTo((1., 1.)) << std::endl;

	std::cout << "-------------------------------\n";

	std::cout << &p1 << std::endl;
	p1.printMemory();

	p4.setPos(7., 15.);
	p4.print();


	Number n1(7), n2(15), n3(3), n4(33);
	Number n5 = n1.sum(n2);
	std::cout << n5.getValue() << std::endl;
	std::cout << n1.sum(n2).mult(n3).div(n4).diff(Number(5)).getValue() << std::endl;


	return 0;
}