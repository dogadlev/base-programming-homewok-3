// Homework 3. Task 1. Calculator.

#include <iostream>
#include <clocale>

class Calculator 
{
private:
    double num1 = 0;
    double num2 = 0;

    double add() {return num1 + num2;}
    double multiply() {return num1 * num2;}
    double subtract_1_2() {return num2 - num1;}
    double subtract_2_1() {return num1 - num2;}
    double divide_1_2() {return num1 / num2;}
    double divide_2_1() {return num2 / num1;}

public:
    Calculator() {}
    
    bool set_num1(double num1) 
    {
        std::cout << "Введите первое число num1: ";
        std::cin >> num1;

        if (num1 != 0.0) 
        {
            this->num1 = num1;
            return true;
        }
        std::cout << "Неверный ввод! Введите число отличное от нуля." << std::endl;
        return false;
    }

    bool set_num2(double num2)
    {
        std::cout << "Введите второе число num2: ";
        std::cin >> num2;

        if (num2 != 0.0)
        {
            this->num2 = num2;
            return true;
        }
        std::cout << "Неверный ввод! Введите число отличное от нуля." << std::endl;
        return false;
    }

    void printResults()
    {
        std::cout << "num1 + num2 = " << add() << std::endl;
        std::cout << "num1 - num2 = " << subtract_2_1() << std::endl;
        std::cout << "num2 - num1 = " << subtract_1_2() << std::endl;
        std::cout << "num1 * num2 = " << multiply() << std::endl;
        std::cout << "num1 / num2 =" << divide_1_2() << std::endl;
        std::cout << "num2 / num1 =" << divide_2_1() << std::endl;
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    double num1 = 0, num2 = 0;

    Calculator calc;

    do 
    {
        while (!calc.set_num1(num1)) {}

        while (!calc.set_num2(num2)) {}

        calc.printResults();
        
    } while (true);

    return 0;
}