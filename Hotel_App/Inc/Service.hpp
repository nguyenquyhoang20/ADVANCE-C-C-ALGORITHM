#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>

class Service {
public:
    Service(const std::string& name, double price)
        : name_(name), price_(price) {}

    // Getters và setters
    std::string getName() const { return name_; }
    double getPrice() const { return price_; }

    void setName(const std::string& name) { name_ = name; }
    void setPrice(double price) { price_ = price; }

private:
    std::string name_;  // Tên dịch vụ
    double price_;      // Giá dịch vụ
};

#endif // SERVICE_HPP
