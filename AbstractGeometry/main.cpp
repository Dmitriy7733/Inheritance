#include<Windows.h>
#include<iostream>
//using std::endl;
//using std::cin;
//using std::cout;
using namespace std;

#define delimiter "\n--------------------------------------\n"

namespace Geometry
{
	static const double pi = 3.14;
	class Shape
	{
	public:
		virtual double get_area()const = 0;
		virtual double get_perimiter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimiter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side)
		{
			this->side = side;
		}
		~Square() {}
		double get_side()const
		{
			return side;
		}
		double get_diagonal()const
		{
			return side * sqrt(2);
		}
		double get_area()const
		{
			return side * side;
		}
		double get_perimiter()const
		{
			return side * 4;
		}
		void draw()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			cout << "Диагональ: " << get_diagonal() << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		Rectangle(double width, double length)
		{
			this->width = width;
			this->length = length;
		}
		~Rectangle() {}
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		double get_area()const
		{
			return width * length;
		}
		double get_perimiter()const
		{
			return (width + length) * 2;
		}
		double get_diagonal()const
		{
			return sqrt(width * width + length*length);
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));

			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, 100, 100, 300, 200);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);

		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника: " << get_width() << endl;
			cout << "Длина прямоугольника: " << get_length() << endl;
			cout << "Диагональ прямоугольника: " << get_diagonal() << endl;
			Shape::info();
		}
	};
	class Circle :public Shape
	{
		double radius;
		int x;
		int y;
		//double pi = 3.14;
	public:
		Circle(double radius, int x, int y)
		{
			this->radius = radius;
			this->x = x;
			this->y = y;
		}
		~Circle() {}
		double get_radius()const
		{
			return radius;
		}
		double get_area()const
		{
			return pi * radius * radius;
		}
		double get_perimiter()const
		{
			return 2 * pi * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));

			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);

		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус окружности: " << get_radius() << endl;
			cout << "Длина окружности: " << get_perimiter() << endl;
			cout << "Площадь круга: " << get_area() << endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{
		int x1;
		int y1;
		int x2;
		int y2;
		int x3;
		int y3;
	public:
		Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
		{
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->x3 = x3;
			this->y3 = y3;
		}
		~Triangle() {}
		double distance(int x1, int y1, int x2, int y2)const
		{
			int dx = x2 - x1;
			int dy = y2 - y1;
			return sqrt(dx * dx + dy * dy);
		}
		
		double get_perimeter()const
		{
			double a = distance(x1, y1, x2, y2);
			double b = distance(x2, y2, x3, y3);
			double c = distance(x3, y3, x1, y1);
			return a + b + c;
		}
		double get_area()const
		{
			double a = distance(x1, y1, x2, y2);
			double b = distance(x2, y2, x3, y3);
			double c = distance(x3, y3, x1, y1);
			double e = (a + b + c) / 2;
			return sqrt(e*(e-a)*(e-b)*(e-c));
		}

		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Площадь треугольника: " << get_area() << endl;
			cout << "Периметр треугольника: " << get_perimiter() << endl;
			Shape::info();
		}
	};
}


void main()
{
		setlocale(LC_ALL, "");
		
		Geometry::Square square(5);
		cout << "Длина стороны квадрата: " << square.get_side() << endl;
		cout << "Площадь квадрата: " << square.get_area() << endl;
		cout << "Периметр квадрата: " << square.get_perimiter() << endl;
		cout << "Диагональ квадрата: " << square.get_diagonal() << endl;
		square.draw();
		cout << delimiter << endl;
		square.info();

		Geometry::Rectangle rect(25, 15);
		rect.info();

		cout << delimiter << endl;

		Geometry::Circle circle(50, 500, 500);
		circle.info();
		
		cout << delimiter << endl;

		Geometry::Triangle triangle(10, 10, 100, 100, 10, 10);
		triangle.info();
}
