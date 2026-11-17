#include <iostream>
#include <Windows.h>
#include <cmath>


int kal = 0;

double f(double x)
{
	kal++;
	return std::log(x) - std::cos(x);
}

double df(double x)
{
	return (1.0 / x) + std::sin(x);
}



int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8); //		1251
	srand(time(NULL));

    double a = 0.5;
    double limit = 3.0;
    double h = 0.1;
    double b = a;
    bool found = false;

    std::cout << "Метод сканирования\n";
    while (a < limit) 
    {
        b = a + h;
        if (f(a) * f(b) < 0) 
        {
            std::cout << "Найден отрезок локализациий:" << a << ", " << b << "\n\n";
            found = true;
            break;
        }
        a = b;
    }

    if (!found) 
    {
        std::cout << "Корень на заданном интервале не найден\n";
        return 0;
    }

   
    std::cout << "Метод половинного деления три итерации\n";
    double c = 0.0;
    for (int i = 1; i <= 3; i++) 
    {
        c = (a + b) / 2.0;
        std::cout << "Итерация " << i << ":c = " << c << "\n";

        if (f(a) * f(c) < 0) 
        {
            b = c;
        }
        else 
        {
            a = c;
        }
    }

    double x0 = (a + b) / 2.0;
    std::cout << "Начальное приближение для метода Ньютона: x0 = " << x0 << "\n\n";


    std::cout << "Метод Ньютона\n";
    double eps = 1e-6;
    double x1 = x0;
    int iter = 0;

    while (true) 
    {
        iter++;
        double d = df(x0);

        
        if (std::abs(d) < 1e-10) 
        {
            std::cout << "Предупреждение: производная близка к нулю. Остановка во избежание деления на ноль.\n";
            return 1;
        }

        double fx0 = f(x0);
        x1 = x0 - fx0 / d;
        double fx1 = f(x1);

        std::cout << "Итерация " << iter << ":x = " << x1 << "f(x) = " << fx1 << "\n";

        if (std::abs(x1 - x0) < eps) 
        {
            x0 = x1;
            break;
        }
        x0 = x1;
    }

    std::cout << "\n";

    std::cout.precision(8);
    std::cout << "Корень найден: x = " << x0 << ", f(x) = " << f(x0) << "\n";


    std::cout << "\nВычислений функции f(x): " << kal << "\n";





}