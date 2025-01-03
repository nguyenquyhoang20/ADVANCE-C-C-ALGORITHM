#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Menu.hpp"
#include "UI.hpp"
#include <map>
#include <functional>
#include "EmployeeManager.hpp"
#include "RoomManager.hpp"
#include "ServiceManager.hpp"

class Manager {
public:
// Hiển thị menu tùy thuộc vào loại người dùng (Quản lý/ Nhân viên)
    void showMenu(int userType);
    // Hiển thị menu quản lý chính
    void showManagementMenu();

private:
    EmployeeManager employeeManager;
    // Các phương thức để quản lý từng phần
    void manageEmployees();  // Quản lý nhân viên
    void manageRooms();      // Quản lý phòng
    void manageServices();   // Quản lý dịch vụ

    // Các phương thức cụ thể cho từng hành động
    void addEmployee();      // Thêm nhân viên
    void editEmployee();     // Sửa thông tin nhân viên
    void deleteEmployee();   // Xóa nhân viên
    void listEmployees();    // Liệt kê nhân viên
    void setWorkShift();  // Thêm phương thức để set ca làm cho nhân viên


    void addRoom();          // Thêm phòng
    void editRoom();         // Sửa thông tin phòng
    void deleteRoom();       // Xóa phòng
    void listRooms();        // Liệt kê phòng

    void addService();       // Thêm dịch vụ
    void editService();      // Sửa thông tin dịch vụ
    void deleteService();    // Xóa dịch vụ
    void listServices();     // Liệt kê dịch vụ

// === Phương thức cho Menu Nhân Viên ===
    void employeeOperations();     // Menu dành cho nhân viên
    void viewWorkSchedule();       // Xem ca làm
    void editEmployeeInfo();       // Sửa thông tin nhân viên
    void bookRoom();               // Đặt phòng cho khách
    void checkoutRoom();           // Trả phòng cho khách
   

    RoomManager roomManager;  // Thêm quản lý phòng
    ServiceManager serviceManager;  // Quản lý các dịch vụ
    
   
};

#endif // MANAGER_HPP
