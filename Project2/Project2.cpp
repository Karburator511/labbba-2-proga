#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <locale>

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limit = static_cast<int>(sqrt(n));
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(int argc, char* argv[]) {
    std::setlocale(LC_ALL, "Russian");

    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
        isHuman = true;
    }

    int N;
    if (isHuman) {
        std::cout << "Введите количество чисел (N): ";
    }
    std::cin >> N;

    int sum = 0, maxNum = 0, minNum = INT_MAX, countMultiplesOfFive = 0, countPowersOfTwo = 0, countExceedSumOfTwoPrev = 0;
    int prev1 = 0, prev2 = 0;

    for (int i = 0; i < N; ++i) {
        int num;
        if (isHuman) {
            std::cout << "Введите число: ";
        }
        std::cin >> num;

        if (isPrime(num)) {
            std::cout << num << std::endl;
        }

        sum += num;
        if (num > maxNum) maxNum = num;
        if (num < minNum) minNum = num;
        if (num % 5 == 0) ++countMultiplesOfFive;
        if (isPowerOfTwo(num)) ++countPowersOfTwo;
        if (i >= 2 && num > (prev1 + prev2)) ++countExceedSumOfTwoPrev;

        prev2 = prev1;
        prev1 = num;
    }

    if (isHuman) {
        std::cout << "Среднее арифметическое: ";
    }
    std::cout << std::fixed << std::setprecision(2) << (static_cast<double>(sum) / N) << std::endl;

    if (isHuman) {
        std::cout << "Разница между максимумом и минимумом: ";
    }
    std::cout << maxNum - minNum << std::endl;

    if (isHuman) {
        std::cout << "Количество чисел, кратных 5: ";
    }
    std::cout << countMultiplesOfFive << std::endl;

    if (isHuman) {
        std::cout << "Количество чисел, являющихся степенью двойки: ";
    }
    std::cout << countPowersOfTwo << std::endl;

    if (isHuman) {
        std::cout << "Количество чисел, превышающих сумму двух предыдущих: ";
    }
    std::cout << countExceedSumOfTwoPrev << std::endl;

    return 0;
}