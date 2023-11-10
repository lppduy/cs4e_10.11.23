#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isSuperPrime(int num) {
    std::string str = std::to_string(num);
    for (int i = 0; i < str.length(); ++i) {
        std::string sub = str.substr(0, i + 1);
        if (!isPrime(std::stoi(sub))) {
            return false;
        }
    }
    return true;
}

std::vector<int> superPrimeNumbers(int n) {
    std::vector<int> result;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    std::cout << "Nhap gia tri n: ";
    std::cin >> n;

    std::vector<int> superPrimes = superPrimeNumbers(n);

    std::cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la: ";
    for (int prime : superPrimes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
