#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee {
public:
    // Constructor để khởi tạo nhân viên với các thông tin cơ bản
    Employee(const std::string& id, const std::string& name, const std::string& phoneNumber, 
             const std::string& position, const std::string& workShift = "Chưa được set", 
             const std::string& workingHours = "")
        : id_(id), name_(name), phoneNumber_(phoneNumber), position_(position), 
          workShift_(workShift), workingHours_(workingHours) {}

    // Getters
    std::string getId() const { return id_; }
    std::string getName() const { return name_; }
    std::string getPhoneNumber() const { return phoneNumber_; }
    std::string getPosition() const { return position_; }
    std::string getWorkShift() const { return workShift_; }
    std::string getWorkingHours() const { return workingHours_; }

    // Setters
    void setName(const std::string& name) { name_ = name; }
    void setPosition(const std::string& position) { position_ = position; }
    void setWorkShift(const std::string& shift) { workShift_ = shift; }
    void setWorkingHours(const std::string& hours) { workingHours_ = hours; }
    void setPhoneNumber(const std::string& newPhone) { phoneNumber_ = newPhone; }

private:
    std::string id_;           // ID của nhân viên (tự động tạo)
    std::string name_;         // Tên của nhân viên
    std::string phoneNumber_;  // Số điện thoại của nhân viên
    std::string position_;     // Chức vụ của nhân viên
    std::string workShift_;    // Ca làm việc của nhân viên
    std::string workingHours_; // Giờ làm việc chi tiết của nhân viên
};

#endif // EMPLOYEE_HPP
