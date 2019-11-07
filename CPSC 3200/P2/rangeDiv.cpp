/*
*Author:Shaun Lee
*Date:11/03/2019
*Version:v1.2
*Platform:Clion C++11
*/

#include "rangeDiv.h"
#include "intDiv.h"


rangeDiv::rangeDiv(int input) {
    if (input <= 0) input = 1;
    active = true;
    arr = new intDiv[input];
    divisibleCount = 0;
    remainderCount = 0;
    testCount = 0;
    range = input;
    primecount = 2;
    for (int i = 0; i < range; i++) {
        arr[i] = intDiv(PrimeNumGen());
    }

}

int rangeDiv::getdivisibleCount() {
    return divisibleCount;
}

int rangeDiv::getremainderCount() {
    return remainderCount;
}

int rangeDiv::gettestCount() {
    return testCount;
}

void rangeDiv::switchstate() {
    if (active) {
        active = false;
    } else {
        active = true;
    }

}

void rangeDiv::test(int num) {
    if (num <= 0) num = 1;
    if (!active) return;
    testCount++;
    for (int i = 0; i < range; i++) {
        if (arr[i].test(num) == 0) {
            divisibleCount++;
        } else {
            remainderCount++;
        }
    }
}

rangeDiv::~rangeDiv() {
    delete[] arr;
}


unsigned int rangeDiv::PrimeNumGen() {
    while (!isPrime(primecount)) {
        primecount++;
    }
    int temp = primecount;
    primecount++;
    return temp;
}

bool rangeDiv::isPrime(int num) {

    if (num <= 1)
        return false;

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}

rangeDiv::rangeDiv(const rangeDiv &obj) {
    range = obj.range;
    divisibleCount = obj.divisibleCount;
    testCount = obj.testCount;
    remainderCount = obj.remainderCount;
    primecount = obj.primecount;
    arr = new intDiv[range];
    for (int i = 0; i < range; i++) {
        arr[i] = obj.arr[i];
    }
}

rangeDiv &rangeDiv::operator=(const rangeDiv &obj) {
    if (this == &obj) {
        return *this;
    }
    delete[] arr;
    range = obj.range;
    divisibleCount = obj.divisibleCount;
    testCount = obj.testCount;
    remainderCount = obj.remainderCount;
    primecount = obj.primecount;
    arr = new intDiv[range];
    for (int i = 0; i < range; i++) {
        arr[i] = obj.arr[i];
    }
    return *this;
}

rangeDiv::rangeDiv(rangeDiv &&obj) {
    range = obj.range;
    divisibleCount = obj.divisibleCount;
    testCount = obj.testCount;
    remainderCount = obj.remainderCount;
    primecount = obj.primecount;
    arr = obj.arr;
    obj.range = 0;
    obj.divisibleCount = 0;
    obj.testCount = 0;
    obj.remainderCount = 0;
    obj.primecount = 2;
    obj.arr = nullptr;
}

rangeDiv &rangeDiv::operator=(rangeDiv &&obj) {
    delete[] arr;
    range = obj.range;
    divisibleCount = obj.divisibleCount;
    testCount = obj.testCount;
    remainderCount = obj.remainderCount;
    primecount = obj.primecount;
    arr = obj.arr;
    obj.range = 0;
    obj.divisibleCount = 0;
    obj.testCount = 0;
    obj.remainderCount = 0;
    obj.primecount = 2;
    obj.arr = nullptr;
    return *this;

}

/**Implementation invariant:Prime number generator uses a seperate function to return a incrementing prime number example is 3,5,7,11
 *                          Prime number generator uses the isPrime to check if the number is primew
 *                          if input for constructor is negative or 0 then it is 1
 *                          if input for test() is negative or 0 then its 1
**/