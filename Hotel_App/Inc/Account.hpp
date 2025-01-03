#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <vector>

class Account {
private:
    std::string username;  // Tên tài khoản
    std::string password;  // Mật khẩu
    std::vector<std::string> roles;  // Danh sách các vai trò

public:
    // Constructor mặc định và constructor có tham số
    Account();
    Account(const std::string& username, const std::string& password, const std::vector<std::string>& roles);

    // Getter và Setter cho các thuộc tính
    std::string getUsername() const;
    std::string getPassword() const;
    std::vector<std::string> getRoles() const;

    void setPassword(const std::string& password);
    void setRoles(const std::vector<std::string>& roles);

    // Kiểm tra nếu tài khoản đã tồn tại trong danh sách
    static bool accountExists(const std::vector<Account>& accountList, const std::string& username);

    // Phương thức static để đăng ký và đăng nhập
    static bool registerAccount(std::vector<Account>& accountList, const std::string& username, const std::string& password, const std::vector<std::string>& roles);
    static bool login(const std::vector<Account>& accountList, const std::string& username, const std::string& password, std::vector<std::string>& roles);

    // Phương thức lưu và đọc tài khoản từ file CSV
    static void saveToCSV(const std::vector<Account>& accountList, const std::string& filename);
    static void loadFromCSV(std::vector<Account>& accountList, const std::string& filename);
};

extern std::vector<Account> accountList;

#endif // ACCOUNT_HPP
