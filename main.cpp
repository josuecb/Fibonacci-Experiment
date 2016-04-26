#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "CurrentTime.h"

using namespace std;

// unsigned with this we can have more bits to consume and output the largest fibonacci
unsigned long long int iterativeFibonacci(unsigned int);

unsigned long long int recursiveFibonacci(unsigned int);

vector<string> calculateTimeForEachFunction(bool, CurrentTime *);

bool isPrime(unsigned long long int);

void findSmallestFibonacci(vector<int>);

vector<unsigned long long int> findFibonacciPrimes();

int main() {
    CurrentTime *startTime = new CurrentTime();
    const vector<int> value = {1000000, 1000000000};
    double millisecond = startTime->getMilliseconds();
    cout << "Welcome to my Fibonacci Program Experiment!" << endl;

    cout << to_string(startTime->getCurrentTime()) + " and " + to_string(millisecond) << endl;
//    Sleep(3000);
    calculateTimeForEachFunction(true, startTime);
    findSmallestFibonacci(value);
    findFibonacciPrimes();
    return 0;
}

// Non-Negative integers aren't allowed
unsigned long long int iterativeFibonacci(unsigned int nth_fibonacci_index) {
    unsigned long long int first = 0, second = 1, nth_number = 0;

    for (unsigned int n = 0; n < nth_fibonacci_index; n++) {
        nth_number = first + second;
        first = second;
        second = nth_number;
    }
    return nth_number;
}

// The recursive version is not very efficient because will loop too much and will consume too much memory
// that sometimes makes the application crash
unsigned long long int recursiveFibonacci(unsigned int nth_fibonacci_index) {
    if (nth_fibonacci_index == 0) return 0;
    else if (nth_fibonacci_index == 1) return 1;
    else return recursiveFibonacci(nth_fibonacci_index - 1) + recursiveFibonacci(nth_fibonacci_index - 2);
}

vector<string> calculateTimeForEachFunction(bool isIterative, CurrentTime *startTime) {
    vector<string> timeElapsedTime;
    vector<unsigned int> findValues = {100, 500, 1000};

    for (int i = 0; i < findValues.size(); ++i) {
        if (isIterative) {
            cout << "Fibonacci(" + to_string(findValues[i]) + ") = " + to_string(iterativeFibonacci(findValues[i])) <<
            endl;
//            cout << to_string(endingTime->getTimeElapsed(*startTime)) + " and " + to_string(endingTime->getMilliseconds()) << endl;
            CurrentTime *endingTime = new CurrentTime();
            timeElapsedTime.push_back(to_string(endingTime->getTimeElapsed(*startTime)));
            cout << "Time elapsed = " + timeElapsedTime[i] << endl;
        }
        else {
            cout << "Fibonacci(" + to_string(findValues[i]) + ") = " + to_string(recursiveFibonacci(findValues[i])) <<
            endl;
            CurrentTime *endingTime = new CurrentTime();
//            cout << to_string(endingTime->getTimeElapsed(*startTime)) + " and " + to_string(endingTime->getMilliseconds()) << endl;
            timeElapsedTime.push_back(to_string(endingTime->getTimeElapsed(*startTime)));
            cout << "Time elapsed = " + timeElapsedTime[i] << endl;
        }

    }
    return timeElapsedTime;
}

bool isPrime(unsigned long long int number) {
    for (int i = 2; i < sqrt(number); ++i) {
        if ((number % i == 0)) {
            return false;
        }
    }
    return true;
}

void findSmallestFibonacci(vector<int> value) {
    unsigned int fibonacciIndex = 1;
    for (int i = 0; i < value.size(); ++i) {
        unsigned long long int fibo;
        while (true) {
            fibo = iterativeFibonacci(fibonacciIndex);
            if (fibo > value[i]) {
                cout << to_string(fibo) << endl;
                break;
            }
            fibonacciIndex++;
        }
    }
}

vector<unsigned long long int> findFibonacciPrimes(){
    vector<unsigned long long int> listOfFibonacciPrimes;
    unsigned int infinityCount = 0;
    while (infinityCount < 201){
        unsigned long long int fibonacci = iterativeFibonacci(infinityCount);
        if(isPrime(fibonacci)){
            cout << to_string(fibonacci) << endl;
            listOfFibonacciPrimes.push_back(fibonacci);
        }
        cout << infinityCount << endl;
        infinityCount++;
    }
    return listOfFibonacciPrimes;
}