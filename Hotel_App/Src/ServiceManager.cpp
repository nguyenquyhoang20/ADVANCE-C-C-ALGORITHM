#include "ServiceManager.hpp"
#include "UI.hpp"
#include <iostream>
#include <fstream>  // Thêm dòng này để sử dụng std::ofstream
#include <sstream>  // Đảm bảo bạn đã bao gồm <sstream> nếu sử dụng std::stringstream

// Thêm dịch vụ mới
void ServiceManager::addService(const std::string& name, double price) {
    services_.emplace_back(name, price);
    UI::showMessage("Dịch vụ " + name + " đã được thêm với giá " + std::to_string(price) + "k.");
}

// Hiển thị danh sách dịch vụ
void ServiceManager::listServices() const {
    if (services_.empty()) {
        UI::showMessage("Không có dịch vụ nào.");
    } else {
        UI::showMessage("Danh sách dịch vụ:");
        for (const auto& service : services_) {
            UI::showMessage("- " + service.getName() + ": " + std::to_string(service.getPrice()) + "k");
        }
    }
}

// Giao diện quản lý dịch vụ
void ServiceManager::manageServices() {
    while (true) {
        UI::showMessage("Dịch vụ\n");
        UI::showMessage("0. Quay lại\n");

        UI::showMessage("Vui lòng nhập tên dịch vụ: ");
        std::string name;
        std::getline(std::cin, name);

        if (name == "0") {
            UI::showMessage("Quay lại giao diện chính.");
            break;
        }

        UI::showMessage("Giá tiền (đơn vị 1000 VND): ");
        double price;
        std::cin >> price;
        std::cin.ignore(); // Xử lý ký tự xuống dòng còn sót lại

        addService(name, price);

        UI::showMessage("Tiếp tục nhập tên dịch vụ? (Y/N): ");
        char choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 'N' || choice == 'n') {
            UI::showMessage("Quay lại giao diện chính.");
            break;
        }
    }
}

// Lưu danh sách dịch vụ vào file CSV
void ServiceManager::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        UI::showMessage("Không thể mở file để lưu dữ liệu.");
        return;
    }

    file << "Name,Price\n"; // Tiêu đề cột
    for (const auto& service : services_) {
        file << service.getName() << "," << service.getPrice() << "\n";
    }

    file.close();
    UI::showMessage("Dữ liệu đã được lưu vào file " + filename);
}

// Tải danh sách dịch vụ từ file CSV
void ServiceManager::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Không thể mở file " + filename + " để đọc.");
    }

    services_.clear(); // Xóa dữ liệu hiện tại
    std::string line;
    std::getline(file, line); // Bỏ qua dòng tiêu đề

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        double price;

        std::getline(ss, name, ',');
        ss >> price;

        services_.emplace_back(name, price);
    }

    file.close();
    UI::showMessage("Dữ liệu đã được tải từ file " + filename);
}
