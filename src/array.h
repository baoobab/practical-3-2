#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"


class TArray {
private:
    unsigned size;
    number* arr;

    void quickSortHelper(int low, int high);
    void quickSortReverseHelper(int low, int high);
    bool checkIndex(unsigned int index);
public:
    TArray();
    ~TArray();
    unsigned getSize();
    void appendElement(number el);
    void print();
    void resizeArray(unsigned newSize);
    number mediumValue();
    number standardDeviation();
    number test(number n); // TODO: убрать епта
    void sort();
    void reverseSort();
    void flushMemory();
    void replaceElement(unsigned int index, number value);
    void removeElementByIndex(unsigned int index);
    void fillArray(unsigned newSize, number el = 0);
};

#endif // ARRAY_H
