#include <iostream>
#include <string>

// Базовый класс для всех фигур
class Figure {
protected:
    std::string name;

public:
    Figure(const std::string& name) : name(name) {}
    virtual void print_info() const = 0; // Чисто виртуальный метод для вывода информации о фигуре
    virtual ~Figure() = default; // Виртуальный деструктор
};

// Класс для треугольников
class Triangle : public Figure {
protected:
    int a, b, c; // Стороны
    int A, B, C; // Углы

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        std::cout << name << ":\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

// Класс для четырёхугольников
class Quadrangle : public Figure {
protected:
    int a, b, c, d; // Стороны
    int A, B, C, D; // Углы

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure("Четырёхугольник"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        std::cout << name << ":\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

// Класс для прямоугольного треугольника
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
};

// Класс для равнобедренного треугольника
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
};

// Класс для равностороннего треугольника
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};

// Класс для прямоугольника
class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};

// Класс для квадрата
class Square : public Quadrangle {
public:
    Square(int a)
        : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        name = "Квадрат";
    }
};

// Класс для параллелограмма
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
};

// Класс для ромба
class Rhombus : public Quadrangle {
public:
    Rhombus(int a, int A, int B)
        : Quadrangle(a, a, a, a, A, B, A, B) {
        name = "Ромб";
    }
};

// Функция для вывода информации о фигуре
void print_info(const Figure* figure) {
    figure->print_info();
    std::cout << std::endl;
}

int main() {
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}