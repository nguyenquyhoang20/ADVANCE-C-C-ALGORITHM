#include "Account.hpp"
#include "Manager.hpp"
#include "EmployeeManager.hpp"
#include "RoomManager.hpp"
#include <iostream>
#include <vector>

// int main() {

//     // EmployeeManager employeeManager;

//     // // Thêm nhân viên mới
//     // employeeManager.addEmployee(accountList, "Trung", "123456789", "Tạp vụ");
//     // employeeManager.addEmployee(accountList, "Thái", "567891237", "Bảo vệ");
//     // employeeManager.addEmployee(accountList, "Sơn", "123897519", "Đầu bếp");
//     // employeeManager.addEmployee(accountList, "Nam", "987654321", "Lễ Tân");

//     // // Hiển thị danh sách nhân viên
//     // employeeManager.listEmployees();

//     // // Sửa thông tin nhân viên theo tên
//     // employeeManager.editEmployeeByName("Trung", "Trung Nguyen", "Quản lý Tạp vụ");

//     // // Xóa nhân viên theo ID (số điện thoại)
//     // employeeManager.deleteEmployeeById("567891237");

//     // // Hiển thị lại danh sách nhân viên
//     // employeeManager.listEmployees();


//     // Thêm tài khoản mẫu để kiểm tra
//     Account adminAccount("admin", "123456");  // Tài khoản admin
//     Account employeeAccount("user", "123456"); // Tài khoản người dùng
//     accountList.push_back(adminAccount);
//     accountList.push_back(employeeAccount);

//     std::string account, password;

//     std::cout << "\n---- Thông tin đăng nhập ----" << std::endl;
    
//     // Nhập tài khoản (có thể là số điện thoại hoặc account)
//     std::cout << "Nhập tài khoản (account/sđt): ";
//     std::cin >> account;

//     // Nhập mật khẩu
//     std::cout << "Nhập mật khẩu: ";
//     std::cin >> password;

//     // Kiểm tra đăng nhập
//     if (Account::login(accountList, account, password)) {
//         std::cout << "Đăng nhập thành công!" << std::endl;

//         // Kiểm tra nếu tài khoản là "admin"
//         if (account == "admin") {
//             std::cout << "Xin chào Quản lý!" << std::endl;
//             Manager manager;
//             manager.showManagementMenu();  // Hiển thị menu quản lý
//         } else {
//             std::cout << "Xin chào người dùng!" << std::endl;
//             // Gọi menu người dùng (nếu cần thêm chức năng cho người dùng bình thường)
//         }

//     } else {
//         std::cout << "Đăng nhập thất bại! Tài khoản hoặc mật khẩu không đúng." << std::endl;
//     }

//     return 0;
//    RoomManager roomManager;

//     while (true) {
//         int choice = UI::getUserChoice("\nQuản lý phòng:\n"
//                                        "1. Thêm phòng\n"
//                                        "2. Xóa phòng\n"
//                                        "3. Xem trạng thái phòng\n"
//                                        "4. Xem thông tin phòng\n"
//                                        "0. Quay lại\n"
//                                        "Lựa chọn: ");

//         switch (choice) {
//         case 1: {
//             int number = UI::getUserChoice("Nhập số phòng: ");
//             roomManager.addRoom(number);
//             break;
//         }
//         case 2: {
//             int number = UI::getUserChoice("Nhập số phòng muốn xóa: ");
//             roomManager.deleteRoom(number);
//             break;
//         }
//         case 3:
//             roomManager.viewRoomStatus();
//             break;
//         case 4: {
//             int number = UI::getUserChoice("Nhập số phòng: ");
//             roomManager.viewRoomDetails(number);
//             break;
//         }
//         case 0:
//             return 0;
//         default:
//             UI::showMessage("Lựa chọn không hợp lệ!");
//         }
//     }

//     return 0;

    
// }

int main() {
    std::vector<Account> accountList;

    // Tạo tài khoản mẫu
    accountList.emplace_back("admin", "123456", std::vector<std::string>{"manager"});
    accountList.emplace_back("user", "123456", std::vector<std::string>{"employee"});

    std::string account, password;
    std::vector<std::string> roles;
    std::cout << "\n---- Thông tin đăng nhập ----" << std::endl;

    // Nhập tài khoản
    std::cout << "Nhập tài khoản (account/sđt): ";
    std::cin >> account;

    // Nhập mật khẩu
    std::cout << "Nhập mật khẩu: ";
    std::cin >> password;

    // Kiểm tra đăng nhập
    if (Account::login(accountList, account, password, roles)) {
        std::cout << "Đăng nhập thành công!" << std::endl;

        Manager manager;

        // Kiểm tra vai trò đầu tiên trong danh sách vai trò của người dùng
        if (!roles.empty()) {
            if (roles[0] == "manager") {
                std::cout << "Xin chào Quản lý!" << std::endl;
                manager.showMenu(1);  // Hiển thị menu quản lý
            } else if (roles[0] == "employee") {
                std::cout << "Xin chào Nhân viên!" << std::endl;
                manager.showMenu(2);  // Hiển thị menu cho nhân viên
            } else {
                std::cout << "Vai trò không hợp lệ!" << std::endl;
            }
        } else {
            std::cout << "Không có vai trò cho tài khoản này!" << std::endl;
        }
    } else {
        std::cout << "Đăng nhập thất bại! Tài khoản hoặc mật khẩu không đúng." << std::endl;
    }

    return 0;
}