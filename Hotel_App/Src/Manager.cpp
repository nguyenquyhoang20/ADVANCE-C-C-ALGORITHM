#include "Manager.hpp"
#include "UI.hpp"
#include <iostream>
#include "EmployeeManager.hpp" 
#include "RoomManager.hpp"
#include "ServiceManager.hpp"



// Hiển thị menu tùy thuộc vào loại người dùng
void Manager::showMenu(int userType) {
    if (userType == 1) {  // Quản lý
        showManagementMenu();
    } else if (userType == 2) {  // Nhân viên
        employeeOperations();
    }
}

// Hiển thị menu quản lý chính
void Manager::showManagementMenu() {
    Menu mainMenu("Quản lý khách sạn", {
        {1, "Quản lý nhân viên", [this]() { manageEmployees(); }},
        {2, "Quản lý phòng", [this]() { manageRooms(); }},
        {3, "Dịch vụ", [this]() { manageServices(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu chính..."); }}
    });

    mainMenu.showMenu();  // Hiển thị menu quản lý chính
}

// Quản lý nhân viên
void Manager::manageEmployees() {
    Menu employeeMenu("Quản lý nhân viên", {
        {1, "Thêm nhân viên", [this]() { addEmployee(); }},
        {2, "Sửa thông tin nhân viên", [this]() { editEmployee(); }},
        {3, "Xóa nhân viên", [this]() { deleteEmployee(); }},
        {4, "Set ca làm cho nhân viên", [this]() { setWorkShift(); }},
        {5, "Xem danh sách nhân viên", [this]() { listEmployees(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    employeeMenu.showMenu();  // Hiển thị menu quản lý nhân viên
}

// void Manager::addEmployee() {
   
//     while (true) {
//         UI::showMessage("=== Thêm Nhân Viên ===");

//         // Nhập thông tin từ người dùng
//         std::string name = UI::getInputString("Nhập tên nhân viên: ");
//         std::string phoneNumber = UI::getInputString("Nhập số điện thoại (ID): ");
//         std::string position = UI::getInputString("Nhập vị trí công việc (Tạp vụ/Bảo vệ/Đầu bếp/Lễ Tân): ");

//         // Thêm nhân viên mới vào danh sách
//         employeeManager.addEmployee(accountList, name, phoneNumber, position);

//         // Thêm nhân viên mới vào danh sách
//         UI::showMessage("Thêm thành công nhân viên " + name);

//         // Tự động đăng ký tài khoản cho nhân viên với mật khẩu mặc định
//         UI::showMessage("Tài khoản cho nhân viên đã được đăng ký với mật khẩu mặc định '123456'.");

//         // Hiển thị tùy chọn để thêm nhân viên khác
//         int choice = UI::getUserChoice("Thêm nhân viên khác (1) hoặc quay lại (0): ");
        
//         if (choice == 0) {
//             break;  // Quay lại nếu người dùng chọn 0
//         }
//     }
    
// }
void Manager::addEmployee() {
    while (true) {
        UI::showMessage("=== Thêm Nhân Viên ===");

        // Nhập thông tin từ người dùng
        std::string name = UI::getInputString("Nhập tên nhân viên: ");
        std::string phoneNumber = UI::getInputString("Nhập số điện thoại (ID): ");
        std::string position = UI::getInputString("Nhập vị trí công việc (Tạp vụ/Bảo vệ/Đầu bếp/Lễ Tân): ");
        
        // Thêm nhân viên mới vào danh sách
        employeeManager.addEmployee(accountList, name, phoneNumber, position );

        UI::showMessage("Thêm thành công nhân viên " + name);
        UI::showMessage("Tài khoản cho nhân viên đã được đăng ký với mật khẩu mặc định '123456'.");

        // Hiển thị tùy chọn để thêm nhân viên khác
        int choice = UI::getUserChoice("Thêm nhân viên khác (1) hoặc quay lại (0): ");
        if (choice == 0) {
            break;
        }
    }
}


// void Manager::editEmployee() {
//     UI::showMessage("Sửa thông tin nhân viên...");
//     // Danh sách nhân viên
//     employeeManager.listEmployees();

//     UI::showMessage("Vui lòng nhập tên của nhân viên muốn sửa thông tin:");

//     std::string id = UI::getInputString("Nhập ID: ");

//     // employeeManager.findEmployeeById(id);

// }
void Manager::editEmployee() {
    UI::showMessage("Sửa thông tin nhân viên...");
    
    // Hiển thị danh sách nhân viên
    employeeManager.listEmployees();
    
    std::string id = UI::getInputString("Nhập ID của nhân viên muốn sửa: ");
    
    // Kiểm tra xem nhân viên có tồn tại hay không
    Employee* employee = employeeManager.getEmployeeById(id);  // Sử dụng getEmployeeById thay cho findEmployeeById
    if (employee != nullptr) {
        // Nhập thông tin mới từ người dùng
        std::string name = UI::getInputString("Nhập tên mới của nhân viên (Enter để giữ nguyên): ");
        if (!name.empty()) employee->setName(name);

        std::string position = UI::getInputString("Nhập vị trí công việc mới: ");
        if (!position.empty()) employee->setPosition(position);

        std::string workShift = UI::getInputString("Nhập ca làm việc mới (Enter để giữ nguyên): ");
        if (!workShift.empty()) employee->setWorkShift(workShift);

        UI::showMessage("Cập nhật thông tin thành công.");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID: " + id);
    }
}



// void Manager::deleteEmployee() {
//     UI::showMessage("Xóa nhân viên...");
//     // Thêm logic xóa nhân viên ở đây
// }
void Manager::deleteEmployee() {
    UI::showMessage("Xóa nhân viên...");
    
    // Hiển thị danh sách nhân viên
    employeeManager.listEmployees();

    std::string id = UI::getInputString("Nhập ID của nhân viên muốn xóa: ");

    // Tìm nhân viên theo ID
    Employee* employee = employeeManager.getEmployeeById(id);  // Sử dụng getEmployeeById thay cho findEmployeeById
    if (employee != nullptr) {
        // Xóa nhân viên
        employeeManager.deleteEmployeeById(id);
        UI::showMessage("Xóa nhân viên thành công.");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID: " + id);
    }
}



void Manager::setWorkShift() {
    UI::showMessage("Set ca làm cho nhân viên...");
    
    // Hiển thị danh sách nhân viên
    employeeManager.listEmployees();

    std::string id = UI::getInputString("Vui lòng nhập ID của nhân viên muốn set ca làm: ");
    
    // Tìm nhân viên theo ID
    Employee* employee = employeeManager.getEmployeeById(id);  // Sử dụng getEmployeeById thay cho findEmployeeById
    
    if (employee != nullptr) {
        std::string workShift = UI::getInputString("Nhập ca làm việc cho nhân viên (Thứ - Buổi, ví dụ: 2-S, 2-C, 3-C): ");
        employee->setWorkShift(workShift);
        UI::showMessage("Set ca làm thành công.");
    } else {
        UI::showMessage("Không tìm thấy nhân viên với ID: " + id);
    }
}



void Manager::listEmployees() {
    UI::showMessage("=== Danh Sách Nhân Viên ===");

    employeeManager.listEmployees();

    UI::showMessage("------------------");
}


// Quản lý phòng (dành cho Quản lý)
void Manager::manageRooms() {
    roomManager.loadFromCSV("rooms.csv");  // Load dữ liệu phòng từ file CSV

    Menu roomMenu("Quản lý phòng", {
        {1, "Thêm phòng", [this]() { addRoom(); }},
        {2, "Xóa phòng", [this]() { deleteRoom(); }},
        {3, "Xem danh sách phòng", [this]() { listRooms(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    roomMenu.showMenu();  // Hiển thị menu quản lý phòng

    roomManager.saveToCSV("rooms.csv");  // Lưu lại dữ liệu sau khi thay đổi
}

// Thêm phòng
void Manager::addRoom() {
    UI::showMessage("=== Thêm Phòng ===");
    int roomNumber = UI::getInputInt("Nhập số phòng: ");
    int floor = UI::getInputInt("Nhập tầng của phòng: ");
    roomManager.addRoom(roomNumber, floor);  // Gọi phương thức từ RoomManager
}

// Xóa phòng
void Manager::deleteRoom() {
    UI::showMessage("=== Xóa Phòng ===");
    int roomNumber = UI::getInputInt("Nhập số phòng cần xóa: ");
    roomManager.deleteRoom(roomNumber);  // Gọi phương thức từ RoomManager
}

// Xem danh sách trạng thái phòng
void Manager::listRooms() {
    UI::showMessage("=== Danh Sách Phòng ===");
    roomManager.viewRoomStatus();  // Gọi phương thức từ RoomManager
}
// Quản lý dịch vụ
// void Manager::manageServices() {
//     Menu serviceMenu("Quản lý dịch vụ", {
//         {1, "Thêm dịch vụ", [this]() { addService(); }},
//         {2, "Sửa thông tin dịch vụ", [this]() { editService(); }},
//         {3, "Xóa dịch vụ", [this]() { deleteService(); }},
//         {4, "Xem danh sách dịch vụ", [this]() { listServices(); }},
//         {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
//     });

//     serviceMenu.showMenu();  // Hiển thị menu quản lý dịch vụ
// }

// void Manager::addService() {
//     UI::showMessage("Thêm dịch vụ...");
//     // Thêm logic thêm dịch vụ ở đây
// }

// void Manager::editService() {
//     UI::showMessage("Sửa thông tin dịch vụ...");
//     // Thêm logic sửa dịch vụ ở đây
// }

// void Manager::deleteService() {
//     UI::showMessage("Xóa dịch vụ...");
//     // Thêm logic xóa dịch vụ ở đây
// }

// void Manager::listServices() {
//     UI::showMessage("Danh sách dịch vụ...");
//     // Thêm logic liệt kê dịch vụ ở đây
// }

void Manager::manageServices() {
    bool continueAdding = true;

    while (continueAdding) {
        UI::showMessage("Dịch vụ");
        addService(); // Gọi hàm thêm dịch vụ

        // Hỏi người dùng có tiếp tục không
        UI::showMessage("\nTiếp tục nhập tên dịch vụ?");
        UI::showMessage("1. Có");
        UI::showMessage("0. Quay lại giao diện chính");

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            UI::showMessage("Quay lại giao diện chính...");
            continueAdding = false;
        }
    }
}

void Manager::addService() {
    // Nhập tên dịch vụ
    UI::showMessage("Vui lòng nhập tên dịch vụ: ");
    std::string name;
    std::cin.ignore(); // Loại bỏ ký tự xuống dòng thừa
    std::getline(std::cin, name);

    // Nhập giá tiền
    UI::showMessage("Giá tiền (đơn vị 1000VND): ");
    double price;
    std::cin >> price;

    // Thêm dịch vụ
    serviceManager.addService(name, price);
}

// Menu và các chức năng cho nhân viên
void Manager::employeeOperations() {
    Menu employeeMenu("Chức năng nhân viên", {
        {1, "Xem ca làm", [this]() { viewWorkSchedule(); }},
        {2, "Sửa thông tin", [this]() { editEmployeeInfo(); }},
        {3, "Đặt phòng cho khách", [this]() { bookRoom(); }},
        {4, "Trả phòng cho khách", [this]() { checkoutRoom(); }},
        {5, "Danh sách phòng", [this]() { listRooms(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu chính..."); }}
    });

    employeeMenu.showMenu();  // Hiển thị menu cho nhân viên
}

// kiểm tra lịch 
void Manager::viewWorkSchedule() {
    bool hasSchedule = false; // Kiểm tra xem có lịch nào đã được đặt hay chưa

    // Kiểm tra danh sách nhân viên trong EmployeeManager
    const auto& employees = employeeManager.getEmployees();

    for (const auto& employee : employees) {
        if (!employee.getWorkShift().empty()) { // Chỉ hiển thị nếu đã setWorkShift
            UI::showMessage("Nhân viên: " + employee.getName() +
                            ", ID: " + employee.getId() +
                            ", Ca làm: " + employee.getWorkShift());
            hasSchedule = true;
        }
    }

    if (!hasSchedule) { // Nếu không có lịch làm nào
        UI::showMessage("Không có lịch làm việc nào được đặt.");
    }
}


// Trong Manager.cpp

void Manager::editEmployeeInfo() {
    while (true) {
        UI::showMessage("=== Sửa Thông Tin Số Điện Thoại ===");

        // Nhập ID nhân viên
        std::string id = UI::getInputString("Nhập ID của bạn: ");
        Employee* employee = employeeManager.getEmployeeById(id);  // Lấy nhân viên từ EmployeeManager

        if (employee) {
            // Hiển thị thông tin nhân viên
            UI::showMessage("Tên: " + employee->getName());
            UI::showMessage("Chức vụ: " + employee->getPosition());
            UI::showMessage("Số điện thoại hiện tại: " + employee->getPhoneNumber());

            // Xác nhận số điện thoại cũ
            std::string oldPhone = UI::getInputString("Vui lòng nhập số điện thoại cũ: ");
            if (employee->getPhoneNumber() == oldPhone) {  // Xác nhận số điện thoại cũ đúng
                // Nhập số điện thoại mới
                std::string newPhone = UI::getInputString("Vui lòng nhập số điện thoại mới: ");
                if (!newPhone.empty() && newPhone != oldPhone) {  // Kiểm tra hợp lệ
                    employee->setPhoneNumber(newPhone);  // Cập nhật số điện thoại
                    employeeManager.saveToCSV("employees.csv");  // Đồng bộ thay đổi vào file CSV

                    UI::showMessage("Thay đổi số điện thoại thành công.");
                } else {
                    UI::showMessage("Số điện thoại mới không hợp lệ hoặc trùng với số cũ.");
                }
            } else {
                UI::showMessage("Số điện thoại cũ không đúng.");
            }
        } else {
            UI::showMessage("Không tìm thấy thông tin nhân viên với ID: " + id);
        }

        // Hiển thị menu tiếp tục hoặc quay lại
        UI::showMessage("---");
        UI::showMessage("1. Tiếp tục sửa số điện thoại");
        UI::showMessage("0. Quay lại");
        int choice = UI::getInputInt("Vui lòng chọn tính năng: ");
        if (choice == 0) {
            break;  // Thoát khỏi vòng lặp và quay lại
        } else if (choice != 1) {
            UI::showMessage("Lựa chọn không hợp lệ. Vui lòng thử lại.");
        }
    }
}

// Đặt phòng cho khách (dành cho Nhân viên)
void Manager::bookRoom() {
    roomManager.loadFromCSV("rooms.csv");  // Load dữ liệu phòng từ file CSV

    UI::showMessage("=== Đặt Phòng ===");
    roomManager.viewRoomStatus();  // Hiển thị danh sách trạng thái phòng

    int roomNumber = UI::getInputInt("Nhập số phòng cần đặt: ");
    std::string guestName = UI::getInputString("Nhập tên khách: ");
    std::string guestPhone = UI::getInputString("Nhập số điện thoại khách: ");
    std::string checkInTime = UI::getInputString("Nhập ngày giờ check-in (VD: 10h30 - 28/1/2023): ");

    if (roomManager.bookRoom(roomNumber, guestName, guestPhone, checkInTime)) {
        UI::showMessage("Đặt phòng cho khách thành công.");
    } else {
        UI::showMessage("Phòng không khả dụng hoặc đã được đặt.");
    }

    roomManager.saveToCSV("rooms.csv");  // Lưu lại dữ liệu sau khi thay đổi
}

// Trả phòng cho khách (dành cho Nhân viên)
void Manager::checkoutRoom() {
    UI::showMessage("=== Trả Phòng ===");

    // Nhập số phòng muốn trả
    int roomNumber = UI::getInputInt("Vui lòng nhập số phòng muốn trả: ");

    // Lấy phòng từ RoomManager
    Room* room = roomManager.getRoomByNumber(roomNumber);
    if (!room || room->getStatus() != "U") {
        UI::showMessage("Phòng không tồn tại hoặc chưa được đặt.");
        return;
    }

    // Hiển thị thông tin khách
    UI::showMessage("Thông tin khách:\n"
                    "Tên: " + room->getGuestName() + "\n"
                    "SĐT: " + room->getGuestPhone() + "\n");

    // Nhập ngày checkout
    std::string checkOutDate = UI::getInputString("Vui lòng nhập ngày checkout: ");

    // Tính toán chi phí dịch vụ
    double serviceCost = room->getServiceCost();
    double vat = serviceCost * 0.1;
    double totalCost = serviceCost + vat;

    // Hiển thị dịch vụ và chi phí
    UI::showMessage("Tổng chi phí dịch vụ: " + std::to_string(serviceCost) + "\n"
                    "Thuế VAT: 10%\n"
                    "Thành tiền: " + std::to_string(totalCost) + "\n");

    // Nhập phản hồi của khách
    std::string feedback = UI::getInputString("Vui lòng nhập phản hồi về dịch vụ: ");

    // Trả phòng
    if (roomManager.checkoutRoom(roomNumber, checkOutDate, totalCost, feedback)) {
        UI::showMessage("Trả phòng thành công.");
    } else {
        UI::showMessage("Có lỗi xảy ra khi trả phòng.");
    }
}
