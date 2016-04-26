#include <iostream>
#include <vector>

using namespace std;

// unsigned with this we can have more bits to consume and output the largest fibonacci
unsigned long long int iterativeFibonacci(unsigned int);

unsigned long long int recursiveFibonacci(unsigned int);

unsigned long long int problem4_1();

int main() {
    cout << "Hello, World!" << endl;
    cout << iterativeFibonacci(1000) << endl;
    problem4_1();
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
    else {
        unsigned long long int val =
                recursiveFibonacci(nth_fibonacci_index - 1) + recursiveFibonacci(nth_fibonacci_index - 2);
        cout << to_string(val) + " " + to_string(nth_fibonacci_index) << endl;
        return val;
    }
}

unsigned long long int problem4_1() {
    vector<unsigned int> findValues = {100, 500, 1000};

    for (int i = 0; i < findValues.size(); ++i) {
        cout << findValues.size() << endl;
    }

    return 0;
}