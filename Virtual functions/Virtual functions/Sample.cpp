#include <iostream>
#include <locale.h>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.1415;

class Figure {
public:
	virtual double getSquare() = 0;
	virtual double getLength() = 0;
	virtual void showFigureType() = 0;
	virtual pair<double, double> Parametrs() = 0;
};

class Rectangle : public Figure {
private:
	double width;
	double height;
public:
	Rectangle(double a, double b) : width(a), height(b) {}
	double getSquare() { return width * height; }
	double getLength() { return 2 * (width + height); }
	void showFigureType() {
		cout << "Rectangle" << endl;
	}
	pair<double, double> Parametrs() {
		return make_pair(width, height);
	}
};

class Circle : public Figure {
private:
	double radius;
public:
	Circle(double r) : radius(r) {}
	double getSquare() { return PI * radius * radius; }
	double getLength() { return 2 * PI * radius; }
	void setRadius(double val) { radius = val; }
	void showFigureType() {
		cout << "Circle" << endl;
	}
	pair<double, double> Parametrs() {
		return make_pair(radius, 0);
	}
};

class Ellipse : public Figure {
private:
	double a, b;
public:
	Ellipse(double _a, double _b) : a(_a), b(_b) { }
	double getSquare() { return PI * a * b; }
	double getLength() {
		double c = sqrt((a * a + b * b) / 2);
		return 2 * PI * c;
	}
	void showFigureType() {
		cout << "Ellipse" << endl;
	}

	pair<double, double> Parametrs() {
		return make_pair(a, b);
	}
};


int main(){
	setlocale(LC_ALL, "Russian");
	Rectangle rect(3, 5);
	Circle circle(3);
	Ellipse ellipse(5, 7);
	Figure* fig[3];

	fig[0] = &rect;
	fig[1] = &circle;
	fig[2] = &ellipse;
	
	for (size_t i = 0; i < 3; i++) {
		fig[i]->showFigureType();
		cout << "(a, b) = " << fig[i]->Parametrs().first << " " << fig[i]->Parametrs().second << endl
			<< "S = " << fig[i]->getSquare()<< "\tP = " << fig[i]->getLength() << endl;
	}
	return 0;
}