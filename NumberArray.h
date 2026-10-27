#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

/*
    NumberArray Abstract Data Type (ADT)

    Purpose:
    Manage a dynamically allocated array of double values.

    Class Invariant:
    1. size must be greater than 0.
    2. data must point to an allocated array of size elements.
    3. Valid indexes range from 0 to size - 1.
    4. The NumberArray object owns its allocated memory.

*/

class NumberArray
{
private:
    static const int MAX_SIZE = 10;

    int size;
    double* data;

public:
    NumberArray(int size = MAX_SIZE);
    ~NumberArray();

    void setNumber(int index, double value);
    double getNumber(int index) const;

    double getMin() const;
    double getMax() const;
    double getAverage() const;

    void print() const;
};

#endif