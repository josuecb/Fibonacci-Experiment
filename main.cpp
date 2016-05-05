#include <iostream>
#include <vector>
#include <cmath>
#include "CurrentTime.h"

using namespace std;

// unsigned with this we can have more bits to consume and output the largest fibonacci
unsigned long long int iterativeFibonacci(unsigned int);

unsigned long long int recursiveFibonacci(unsigned int);

vector <string> calculateTimeForEachFunction(bool, CurrentTime *);

bool isPrime(unsigned long long int);

void findSmallestFibonacci();

void era();

vector<int> removeIndex(vector<int>&);

void find_primes(vector<bool>&, unsigned long long int);

int main() {
    CurrentTime *startTime = new CurrentTime();
    const vector<int> value = {1000000, 1000000000};
    double millisecond = startTime->getMilliseconds();
    cout << "Welcome to my Fibonacci Program Experiment!" << endl;

    cout << to_string(startTime->getCurrentTime()) + " and " + to_string(millisecond) << endl;
//    Sleep(3000);
    calculateTimeForEachFunction(true, startTime);
//    findSmallestFibonacci(value);
    era();
    return 0;
}

vector<int> removeIndex(vector<int> &list, int index){
    vector<int> list2 = list;
    list2.erase(list2.begin() + index);
    return list2;
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

vector <string> calculateTimeForEachFunction(bool isIterative, CurrentTime *startTime) {
    vector <string> timeElapsedTime;
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

/*
    Function: find_primes()
    Use: find_primes(bool_array, size_of_array);

    It marks all the prime numbers till the
    number: size_of_array, in the form of the
    indexes of the array with value: true.

    It implemenets the Sieve of Eratosthenes,
    consisted of:

    a loop through the first "sqrt(size_of_array)"
    numbers starting from the first prime (2).

    a loop through all the indexes < size_of_array,
    marking the ones satisfying the relation i^2 + n * i
    as false, i.e. composite numbers, where i - known prime
    number starting from 2.
*/
void find_primes(vector<bool>& sieve0, unsigned long long int size) {
    vector<bool> sieve = sieve0;
    // by definition 0 and 1 are not prime numbers
    sieve[0] = false;
    sieve[1] = false;

    // all numbers <= max are potential candidates for primes
    for (unsigned long long int i = 2; i <= size; ++i) {
        sieve[i] = true;
    }

    // loop through the first prime numbers < sqrt(max) (suggested by the algorithm)
    unsigned long long int first_prime = 2;

    unsigned long long int totalSize = size;
    for (unsigned long long int i = first_prime; i <= std::sqrt(double(size)); ++i) {
        // find multiples of primes till < max
        if (sieve[i]) {
            // mark as composite: i^2 + n * i
            for (unsigned long long int j = i * i; j <= size; j += i) {
//                sieve[j] = false;
                sieve.erase(sieve.begin() + j);
                totalSize--;
            }
        }

        if(sieve[i]){
            cout << i << " ";
        }

        if(i >= sqrt(totalSize)){
            cout << "ENDING LOOP" << endl;
            break;
        }
    }
}

/*
    Function: print_primes()
    Use: print_primes(bool_array, size_of_array);

    It prints all the prime numbers,
    i.e. the indexes with value: true.
*/
void print_primes(bool sieve[], unsigned int size) {
    // all the indexes of the array marked as true are primes
    for (unsigned int i = 0; i <= size; ++i) {
        if (sieve[i]) {
            std::cout << i << " ";
        }
    }
}

void era() {
    vector<unsigned long long int> fibonacciNumbers;

    cout << "First 200 fibonacci Numbers: " << endl;

    // we skip 0 and 1 due to they are not primes
    for (unsigned int j = 2; j < 20; j++) {
        cout << j << ", " << to_string(iterativeFibonacci(j)) << endl;
        fibonacciNumbers.push_back(iterativeFibonacci(j));
    }
    unsigned long long int max = fibonacciNumbers[fibonacciNumbers.size() - 1];
    vector<bool> sieve;
    find_primes(sieve, max);
//    print_primes(sieve, max);
    cout << endl << "SIZE " << fibonacciNumbers.size() << endl;
}

//=========================================================================

