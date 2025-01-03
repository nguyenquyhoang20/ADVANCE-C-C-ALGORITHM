#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Định nghĩa biến accountList toàn cục
std::vector<Account> accountList;  // Chỉ định biến toàn cục ở đây

// Constructor mặc định
Account::Account() : username(""), password(""), roles() {}

// Constructor có tham số
Account::Account(const std::string& username, const std::string& password, const std::vector<std::string>& roles)
    : username(username), password(password), roles(roles) {}

// Getter cho từng thuộc tính
std::string Account::getUsername() const {
    return username;
}

std::string Account::getPassword() const {
    return password;
}

std::vector<std::string> Account::getRoles() const {
    return roles;
}

// Setter cho từng thuộc tính
void Account::setPassword(const std::string& password) {
    this->password = password;
}

void Account::setRoles(const std::vector<std::string>& roles) {
    this->roles = roles;
}

// Kiểm tra nếu tài khoản đã tồn tại trong danh sách
bool Account::accountExists(const std::vector<Account>& accountList, const std::string& username) {
    for (const auto& account : accountList) {
        if (account.getUsername() == username) {
            return true; // Tài khoản đã tồn tại
        }
    }
    return false; // Tài khoản không tồn tại
}

// Đăng ký tài khoản mới
bool Account::registerAccount(std::vector<Account>& accountList, const std::string& username, const std::string& password, const std::vector<std::string>& roles) {
    if (accountExists(accountList, username)) {
        return false; // Tên tài khoản đã tồn tại
    }
    Account newAccount(username, password, roles);
    accountList.push_back(newAccount);

    // Lưu thông tin vào file CSV
    saveToCSV(accountList, "accounts.csv");
    return true; // Đăng ký thành công
}

// Đăng nhập
bool Account::login(const std::vector<Account>& accountList, const std::string& username, const std::string& password, std::vector<std::string>& roles) {
    for (const auto& acc : accountList) {
        if (acc.getUsername() == username && acc.getPassword() == password) {
            roles = acc.getRoles(); // Lưu tất cả các vai trò của người dùng vào biến roles
            return true; // Đăng nhập thành công
        }
    }
    return false; // Đăng nhập thất bại
}

// Lưu thông tin vào file CSV
void Account::saveToCSV(const std::vector<Account>& accountList, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Không thể mở file: " << filename << "\n";
        return;
    }

    file << "Username,Password,Role\n";  // Ghi header
    for (const auto& account : accountList) {
        file << account.getUsername() << "," << account.getPassword();
        
        // Ghi các vai trò (nếu có nhiều vai trò, dùng dấu phẩy phân cách)
        for (size_t i = 0; i < account.getRoles().size(); ++i) {
            if (i != 0) {
                file << ",";  // Dấu phẩy phân cách giữa các vai trò
            }
            file << account.getRoles()[i];
        }
        file << "\n";
    }

    file.close();
}

// Đọc tài khoản từ CSV
void Account::loadFromCSV(std::vector<Account>& accountList, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Không thể mở file: " << filename << "\n";
        return;
    }

    std::string line;
    std::getline(file, line);  // Bỏ qua header

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password, role;
        std::vector<std::string> roles;
        
        // Đọc username và password
        std::getline(iss, username, ',');
        std::getline(iss, password, ',');

        // Đọc các vai trò (nếu có nhiều vai trò, sẽ tách theo dấu phẩy)
        while (std::getline(iss, role, ',')) {
            roles.push_back(role);
        }

        // Tạo đối tượng Account và thêm vào danh sách
        accountList.push_back(Account(username, password, roles));
    }

    file.close();
}
