#ifndef SERVICEMANAGER_HPP
#define SERVICEMANAGER_HPP

#include "Service.hpp"
#include <vector>
#include <string>

class ServiceManager {
public:
    // Thêm dịch vụ mới
    void addService(const std::string& name, double price);

    // Hiển thị thông tin dịch vụ
    void listServices() const;

    // Chạy giao diện quản lý dịch vụ
    void manageServices();

    // Lưu danh sách dịch vụ vào file CSV
    void saveToCSV(const std::string& filename) const;

    // Tải danh sách dịch vụ từ file CSV
    void loadFromCSV(const std::string& filename);

private:
    // Danh sách các dịch vụ
    std::vector<Service> services_;

    // Tìm dịch vụ theo tên (hỗ trợ nội bộ)
    Service* findServiceByName(const std::string& name);
};

#endif // SERVICEMANAGER_HPP
