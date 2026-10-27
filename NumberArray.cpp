#include "NumberArray.h"
#include <iostream>

NumberArray::NumberArray(int requestedSize)
{
    size = requestedSize;
    data = new double[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = 0.0;
    }
}

NumberArray::~NumberArray()
{
    delete[] data;
    std::cout << "NumberArray memory released." << std::endl;
}

double NumberArray::getNumber(int index) const
{
    static const double SafeValue = 0.0;

    if (index >= 0 && index < size)
    {
        return data[index];
    }
    else
    {
        std::cerr << "Error: Index " << index << " is out of bounds." << std::endl;
        return SafeValue;
    }
}

double NumberArray::getMin() const
{
    double minimum = data[0];

    for (int i = 1; i < size; i++)
    {
        if (data[i] < minimum)
        {
            minimum = data[i];
        }
    }

    return minimum;
}

double NumberArray::getMax() const
{
    double maximum = data[0];

    for (int i = 1; i < size; i++)
    {
        if (data[i] > maximum)
        {
            maximum = data[i];
        }
    }

    return maximum;
}

double NumberArray::getAverage() const
{
    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }

    return sum / size;
}

void NumberArray::setNumber(int index, double value)
{
    if (index >= 0 && index < size)
    {
        data[index] = value;
    }
}

void NumberArray::print() const
{
    std::cout << "NumberArray contents: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}