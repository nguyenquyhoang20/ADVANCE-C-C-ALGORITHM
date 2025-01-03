// #include "UI.hpp"
// #include <string>
// #include <iostream>

// int UI::getUserChoice(const std::string& prompt) {
//     int choice;
//     std::cout << prompt;
//     std::cin >> choice;
//     return choice;
// }

// void UI::showMessage(const std::string& message) {
//     std::cout << message << std::endl;
// }

// std::string UI::getInputString(const std::string& prompt) {
//     std::string input;
//     std::cout << prompt;
//     std::cin >> input;
//     return input;
// }

// // Phương thức lấy số nguyên từ người dùng
// int UI::getInputInt(const std::string& prompt) {
//     int input;
//     std::cout << prompt;    // Hiển thị thông báo yêu cầu nhập
//     std::cin >> input;      // Đọc đầu vào số nguyên
//     return input;           // Trả về giá trị người dùng nhập
// }

#include "UI.hpp"
#include <iostream>
#include <limits>
#include <string>

// Lấy lựa chọn từ người dùng (int)
int UI::getUserChoice(const std::string& prompt) {
    int choice;
    while (true) {
        std::cout << prompt;
        std::cin >> choice;
        if (std::cin.fail()) { // Kiểm tra nhập liệu sai
            std::cin.clear(); // Xóa trạng thái lỗi
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua đầu vào sai
            std::cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa ký tự thừa
            return choice;
        }
    }
}

// Hiển thị thông báo
void UI::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

// Lấy chuỗi nhập từ người dùng
std::string UI::getInputString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input); // Sử dụng getline để hỗ trợ khoảng trắng
    return input;
}

// Lấy số nguyên từ người dùng
int UI::getInputInt(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail()) { // Kiểm tra lỗi nhập sai
            std::cin.clear(); // Xóa trạng thái lỗi
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua đầu vào sai
            std::cout << "Vui lòng nhập một số nguyên hợp lệ.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa ký tự thừa
            return input;
        }
    }
}

// Lấy số thực từ người dùng (nếu cần)
double UI::getInputDouble(const std::string& prompt) {
    double input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail()) { // Kiểm tra lỗi nhập sai
            std::cin.clear(); // Xóa trạng thái lỗi
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua đầu vào sai
            std::cout << "Vui lòng nhập một số thực hợp lệ.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xóa ký tự thừa
            return input;
        }
    }
}
