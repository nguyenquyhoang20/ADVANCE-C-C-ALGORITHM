#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include "UI.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <fstream> // Thư viện cho file

// Tạo ID tự động cho nhân viên mới
std::string EmployeeManager::generateEmployeeId(const std::string& position) {
    employeeCounter_++;
    std::stringstream ss;

    // Tạo tiền tố ID theo chức vụ
    if (position == "TV") {
        ss << "TV";
    } else if (position == "Bảo vệ") {
        ss << "BV";
    } else if (position == "Đầu bếp") {
        ss << "DV";
    } else if (position == "Lễ Tân") {
        ss << "LT";
    } else {
        ss << "NV"; // Mặc định nếu không có chức vụ đặc biệt
    }

    // Tạo số thứ tự cho ID và đảm bảo có 3 chữ số
    ss << std::setw(3) << std::setfill('0') << employeeCounter_;
    return ss.str();
}

// Thêm nhân viên mới với ID tự động
void EmployeeManager::addEmployee(std::vector<Account>& accountList, const std::string& name, const std::string& phoneNumber, const std::string& position) {
    if (Account::accountExists(accountList, phoneNumber)) {
        UI::showMessage("Số điện thoại này đã được đăng ký.");
        return;
    }

    std::string id = generateEmployeeId(position);
    employees_.emplace_back(id, name, phoneNumber, position);
    UI::showMessage("Nhân viên " + name + " với ID " + id + " đã được thêm thành công.");

    std::vector<std::string> roles = {"Employee"};
    Account::registerAccount(accountList, phoneNumber, "123456", roles);
    UI::showMessage("Tài khoản cho nhân viên đã được đăng ký với mật khẩu mặc định '123456'.");

    saveToCSV("employees.csv");
}

// Tìm nhân viên theo ID (public getter)
Employee* EmployeeManager::getEmployeeById(const std::string& id) {
    for (auto& employee : employees_) {
        if (employee.getId() == id) {
            return &employee;
        }
    }
    return nullptr;
}

// Sửa thông tin nhân viên theo ID
void EmployeeManager::editEmployeeById(const std::string& id, const std::string& newName, const std::string& newPosition) {
    Employee* employee = getEmployeeById(id);
    if (employee) {
        employee->setName(newName);
        employee->setPosition(newPosition);
        UI::showMessage("Thông tin nhân viên đã được cập nhật.");
        saveToCSV("employees.csv");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID này.");
    }
}

// Xóa nhân viên theo ID
void EmployeeManager::deleteEmployeeById(const std::string& id) {
    auto it = std::remove_if(employees_.begin(), employees_.end(), [&id](const Employee& emp) {
        return emp.getId() == id;
    });

    if (it != employees_.end()) {
        employees_.erase(it, employees_.end());
        UI::showMessage("Nhân viên với ID " + id + " đã được xóa.");
        saveToCSV("employees.csv");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID này.");
    }
}

// Đặt ca làm việc cho nhân viên
void EmployeeManager::setWorkShift(const std::string& id, const std::string& shift) {
    Employee* employee = getEmployeeById(id);
    if (employee) {
        employee->setWorkShift(shift);
        UI::showMessage("Ca làm việc của nhân viên " + employee->getName() + " đã được cập nhật thành công thành: " + shift);
        saveToCSV("employees.csv");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID: " + id);
    }
}

// Hiển thị danh sách nhân viên
void EmployeeManager::listEmployees() const {
    if (employees_.empty()) {
        UI::showMessage("Không có nhân viên nào.");
    } else {
        for (const auto& employee : employees_) {
            UI::showMessage("ID: " + employee.getId() +
                            ", Tên: " + employee.getName() +
                            ", Số điện thoại: " + employee.getPhoneNumber() +
                            ", Chức vụ: " + employee.getPosition() +
                            ", Ca làm: " + employee.getWorkShift());
        }
    }
}



// Hiển thị lịch làm việc
void EmployeeManager::displayWorkSchedule() const {
    if (employees_.empty()) {
        UI::showMessage("Không có lịch làm việc nào được đặt.");
    } else {
        bool hasSchedule = false;
        for (const auto& employee : employees_) {
            if (!employee.getWorkShift().empty() && employee.getWorkShift() != "Chưa được set") {
                UI::showMessage("Nhân viên: " + employee.getName() +
                                ", ID: " + employee.getId() +
                                ", Ca làm: " + employee.getWorkShift());
                hasSchedule = true;
            }
        }
        if (!hasSchedule) {
            UI::showMessage("Không có lịch làm việc nào được đặt.");
        }
    }
}

// Trả về danh sách tất cả nhân viên (runtime)
const std::vector<Employee>& EmployeeManager::getEmployees() const {
    return employees_; // Trả về tham chiếu hằng đến danh sách nhân viên
}

// Kiểm tra sự tồn tại của nhân viên
bool EmployeeManager::doesEmployeeExist(const std::string& id) const {
    return std::any_of(employees_.begin(), employees_.end(), [&id](const Employee& emp) {
        return emp.getId() == id;
    });
}

// Lưu danh sách nhân viên vào CSV
void EmployeeManager::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        UI::showMessage("Không thể mở tệp để lưu dữ liệu.");
        return;
    }

    file << "ID,Tên,Số điện thoại,Chức vụ,Ca làm\n";
    for (const auto& employee : employees_) {
        file << employee.getId() << ","
             << employee.getName() << ","
             << employee.getPhoneNumber() << ","
             << employee.getPosition() << ","
             << employee.getWorkShift() << "\n";
    }
    file.close();
}
