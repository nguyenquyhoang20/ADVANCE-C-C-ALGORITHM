#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Room {
public:
    Room(int number, int floor, const std::string& status = "A", 
         const std::string& guestName = "", const std::string& guestPhone = "", 
         const std::string& history = "")
        : number_(number), floor_(floor), status_(status), guestName_(guestName), 
          guestPhone_(guestPhone), history_(history), serviceCostPerDay_(200000), stayDays_(1) {}

    // Getters
    int getNumber() const { return number_; }
    int getFloor() const { return floor_; }
    std::string getStatus() const { return status_; }
    std::string getGuestName() const { return guestName_; }
    std::string getGuestPhone() const { return guestPhone_; }
    std::string getHistory() const { return history_; }

    // Setters
    void setStatus(const std::string& status) { status_ = status; }
    void setGuest(const std::string& name, const std::string& phone) {
        guestName_ = name;
        guestPhone_ = phone;
    }
    void clearGuest() {
        guestName_.clear();
        guestPhone_.clear();
    }
    void addHistory(const std::string& record) {
        if (!history_.empty()) history_ += "|";
        history_ += record;
    }

    // Phương thức tính chi phí dịch vụ
    double getServiceCost() const {
        return serviceCostPerDay_ * stayDays_;
    }

    // Setter và getter cho số ngày lưu trú
    void setStayDays(int days) { stayDays_ = days; }
    int getStayDays() const { return stayDays_; }

private:
    int number_;  // Số phòng
    int floor_;   // Tầng
    std::string status_;      // Trạng thái phòng (A - trống, U - đã đặt)
    std::string guestName_;   // Tên khách
    std::string guestPhone_;  // Số điện thoại khách
    std::string history_;     // Lịch sử phòng

    double serviceCostPerDay_; // Giá dịch vụ mỗi ngày
    int stayDays_;             // Số ngày lưu trú
};

#endif // ROOM_HPP
