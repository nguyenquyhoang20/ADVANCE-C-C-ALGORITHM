#ifndef UI_HPP
#define UI_HPP

#include <string>

class UI {
public:
    // Phương thức hiển thị và lấy dữ liệu đầu vào
    static int getUserChoice(const std::string& prompt);        // Lấy lựa chọn từ người dùng
    static void showMessage(const std::string& message);        // Hiển thị thông báo
    static std::string getInputString(const std::string& prompt); // Lấy chuỗi nhập từ người dùng

    static int getInputInt(const std::string& prompt);           // Lấy số nguyên nhập từ người dùng
    static double getInputDouble(const std::string& prompt);    // Lấy số thực nhập từ người dùng

    
};

#endif // UI_HPP
