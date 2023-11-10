#include <iostream>
#include <stack>
#include <string>

std::string encodeString(const std::string& s) {
    std::stack<char> charStack;
    std::string encodedString;

    int count = 1;
    for (size_t i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
        } else {
            encodedString += s[i];
            encodedString += std::to_string(count);
            count = 1;
        }
    }

    return encodedString;
}

int main() {
    std::string input;
    std::cout << "Nhap chuoi can ma hoa: ";
    std::cin >> input;

    std::string encoded = encodeString(input);

    std::cout << "Chuoi ban dau: " << input << std::endl;
    std::cout << "Chuoi ma hoa: " << encoded << std::endl;

    return 0;
}
