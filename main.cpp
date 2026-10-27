#include <iostream>
#include "NumberArray.h"
#include <random>

int main()
{
    NumberArray numbers(5);

    numbers.setNumber(0, 15.0);
    numbers.setNumber(1, 8.0);
    numbers.setNumber(2, 24.0);
    numbers.setNumber(3, 3.0);
    numbers.setNumber(4, 19.0);

    numbers.print();

    std::cout << "Minimum: " << numbers.getMin() << std::endl;
    std::cout << "Maximum: " << numbers.getMax() << std::endl;
    std::cout << "Average: " << numbers.getAverage() << std::endl;

    std::cout << "\nTesting invalid indexes:" << std::endl;

    numbers.setNumber(-1, 99.0);
    numbers.setNumber(5, 99.0);

    numbers.print();

    std::cout << "Index -1: " << numbers.getNumber(-1) << std::endl;

    std::cout << "Index 5: " << numbers.getNumber(5) << std::endl;

    // TEST 1: Default constructor and zero initialization
    std::cout << "\nTEST: Default constructor" << std::endl;
    {
        NumberArray defaultArray;
        defaultArray.print();
        // Expected: 10 elements, all 0
    }

    // TEST 2: Parameterized constructor initialization
    std::cout << "\nTEST: Parameterized initialization" << std::endl;
    {
        NumberArray initialArray(3);
        initialArray.print();
        // Expected: 0 0 0
    }

    // TEST 3: Valid first, middle, and last indexes
    std::cout << "\nTEST: Valid indexes" << std::endl;

    std::cout << "First: " << numbers.getNumber(0) << std::endl;
    std::cout << "Middle: " << numbers.getNumber(2) << std::endl;
    std::cout << "Last: " << numbers.getNumber(4) << std::endl;

    // Expected: 15, 24, 19

    // TEST 4: One-element array and negative decimal
    std::cout << "\nTEST: One-element array" << std::endl;
    {
        NumberArray single(1);

        std::cout << "Initial: " << single.getNumber(0) << std::endl;

        single.setNumber(0, -2.5);
        single.print();

        std::cout << "Minimum: " << single.getMin() << std::endl;
        std::cout << "Maximum: " << single.getMax() << std::endl;
        std::cout << "Average: " << single.getAverage() << std::endl;
    }

    // TEST 5: Random numbers and statistical consistency
    std::cout << "\nTEST: Random values" << std::endl;
    {
        NumberArray randomArray(8);

        std::mt19937 generator(222);
        std::uniform_real_distribution<double> distribution(-20.0, 20.0);

        for (int i = 0; i < 8; i++)
        {
            randomArray.setNumber(i, distribution(generator));
        }

        randomArray.print();

        double minimum = randomArray.getMin();
        double maximum = randomArray.getMax();
        double average = randomArray.getAverage();

        std::cout << "Minimum: " << minimum << std::endl;
        std::cout << "Maximum: " << maximum << std::endl;
        std::cout << "Average: " << average << std::endl;

        std::cout << "Min <= Average <= Max: " << (minimum <= average && average <= maximum) << std::endl;
    }

    return 0;
}