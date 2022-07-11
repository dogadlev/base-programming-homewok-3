// Homework 3. Task_2.

#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

class Counter 
{
private:
    int count = 1;

public:
    Counter() {}

    Counter(int count) 
    {
        this->count = count;
    }

    void increaseCount() { ++count; }
    void reduceCount() { --count; }
    void checkCount() { std::cout << count << std::endl; }
};

bool bool_inputRequired()
{
    std::string response = "";

    while (true)
    {
        std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
        std::cin >> response;

        if (response == "да")
        {
            return true;
        }
        else if (response == "нет")
        {
            return false;
        }
        else std::cout << "Ошибка ввода! Попробуйте еще раз." << std::endl;
    }
}

int getCount() 
{
    int initCount = 0;
    
    std::cout << "Введите начальное значение счетчика (натуральное число): ";
    std::cin >> initCount;

    return initCount;
}

void userInterface(Counter OCounter) 
{
    char buf = 'NUL';
    bool exit = false;
    
    while (!exit)
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> buf;

        switch (buf)
        {
        case '+':
            OCounter.increaseCount();
            break;

        case '-':
            OCounter.reduceCount();
            break;

        case '=':
            OCounter.checkCount();
            break;

        case 'x':
            std::cout << "До свидания!";
            exit = true;
            break;

        default:
            std::cout << "Неверный ввод. Попробуйте еще раз." << std::endl;
            break;
        }
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

//User prefers to input initial value;
//bool_inputRequired() return true;
//getCount() return int value to initialize OCounter;

    if (bool_inputRequired())
    { 
        Counter OCounter(getCount());
        userInterface(OCounter);
    }
    
//User does not prefer to input initial value;
//OCounter is initialized with default initial value equals 1;

    else
    {
        Counter OCounter;
        userInterface(OCounter);
    }
   
    return 0;
}