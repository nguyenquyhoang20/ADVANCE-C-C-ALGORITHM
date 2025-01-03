#ifndef EMPLOYEEMANAGER_HPP
#define EMPLOYEEMANAGER_HPP

#include "Employee.hpp"
#include "Account.hpp"
#include <vector>
#include <string>
#include <algorithm> // Để sử dụng std::remove_if
#include <iostream>  // Để sử dụng std::cout, std::endl

class EmployeeManager {
public:
    // Thêm nhân viên mới với ID tự động
    void addEmployee(std::vector<Account>& accountList, const std::string& name, const std::string& phoneNumber, const std::string& position);

    // Sửa thông tin nhân viên dựa theo ID
    void editEmployeeById(const std::string& id, const std::string& newName, const std::string& newPosition);
    
    // Xóa nhân viên dựa trên ID
    void deleteEmployeeById(const std::string& id);
    
    // Đặt ca làm việc cho nhân viên
    void setWorkShift(const std::string& id, const std::string& shift);
    
    // Lấy danh sách tất cả nhân viên (runtime)
    const std::vector<Employee>& getEmployees() const;

    // Hiển thị danh sách nhân viên và thông tin chi tiết
    void listEmployees() const;

    // Hiển thị lịch làm việc của nhân viên
    void displayWorkSchedule() const;

    // Lưu và tải dữ liệu từ CSV
    void saveToCSV(const std::string& filename) const;
    void loadFromCSV(const std::string& filename);

    // Kiểm tra nhân viên có tồn tại không theo ID
    bool doesEmployeeExist(const std::string& id) const;

    // Tìm và trả về nhân viên theo ID (public getter)
    Employee* getEmployeeById(const std::string& id);

private:
    std::vector<Employee> employees_; // Danh sách nhân viên trong runtime
    int employeeCounter_ = 0;         // Biến đếm để tạo ID tự động

    // Tạo ID tự động cho nhân viên mới dựa trên chức vụ
    std::string generateEmployeeId(const std::string& position);

    // Tìm nhân viên theo ID (private helper)
    Employee* findEmployeeById(const std::string& id);
};

#endif // EMPLOYEEMANAGER_HPP
