#ifndef ROOMMANAGER_HPP
#define ROOMMANAGER_HPP

#include "Room.hpp"
#include <vector>
#include <map>
#include <string>

class RoomManager {
public:
    // Quản lý phòng
    void addRoom(int roomNumber, int floor); // Thêm phòng mới
    void deleteRoom(int roomNumber);        // Xóa phòng nếu không được đặt
    void viewRoomStatus() const;            // Xem trạng thái phòng (A/U)
    void viewRoomDetails(int roomNumber) const; // Xem chi tiết phòng

    // Đặt và trả phòng
    bool bookRoom(int roomNumber, const std::string& guestName, const std::string& guestPhone, const std::string& checkInTime);
    bool checkoutRoom(int roomNumber, const std::string& checkOutDate, double totalCost, const std::string& feedback);

    // Lưu và tải dữ liệu từ CSV
    void saveToCSV(const std::string& filename) const;
    void loadFromCSV(const std::string& filename);

    // Lấy phòng dựa trên số phòng
    Room* getRoomByNumber(int roomNumber);

private:
    std::map<int, Room> rooms_; // Danh sách phòng (số phòng -> đối tượng Room)
};

#endif // ROOMMANAGER_HPP
