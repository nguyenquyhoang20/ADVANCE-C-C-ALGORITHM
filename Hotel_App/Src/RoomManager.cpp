#include "RoomManager.hpp"
#include "UI.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept> // Để sử dụng std::invalid_argument

// Thêm phòng
void RoomManager::addRoom(int roomNumber, int floor) {
    if (rooms_.find(roomNumber) != rooms_.end()) {
        UI::showMessage("Phòng đã tồn tại!");
        return;
    }
    rooms_.emplace(roomNumber, Room(roomNumber, floor));
    UI::showMessage("Thêm phòng " + std::to_string(roomNumber) + " thành công.");
}

// Xóa phòng
void RoomManager::deleteRoom(int roomNumber) {
    auto it = rooms_.find(roomNumber);
    if (it != rooms_.end() && it->second.getStatus() == "A") { // Chỉ xóa nếu phòng đang trống
        rooms_.erase(it);
        UI::showMessage("Phòng " + std::to_string(roomNumber) + " đã được xóa.");
    } else {
        UI::showMessage("Không thể xóa phòng " + std::to_string(roomNumber) + ", vì phòng không tồn tại hoặc đang sử dụng.");
    }
}

// Xem trạng thái phòng
void RoomManager::viewRoomStatus() const {
    if (rooms_.empty()) {
        UI::showMessage("Không có phòng nào!");
        return;
    }
    for (const auto& [roomNumber, room] : rooms_) {
        std::cout << "Phòng " << roomNumber << " - Trạng thái: " << room.getStatus() << std::endl;
    }
}

// Xem thông tin chi tiết phòng
void RoomManager::viewRoomDetails(int roomNumber) const {
    auto it = rooms_.find(roomNumber);
    if (it == rooms_.end()) {
        UI::showMessage("Không tìm thấy phòng " + std::to_string(roomNumber) + ".");
        return;
    }

    const Room& room = it->second;
    UI::showMessage("Phòng " + std::to_string(roomNumber) + ":\n"
                    "Tầng: " + std::to_string(room.getFloor()) + "\n"
                    "Trạng thái: " + room.getStatus() + "\n"
                    "Tên khách: " + room.getGuestName() + "\n"
                    "SĐT: " + room.getGuestPhone() + "\n"
                    "Lịch sử:\n" + room.getHistory());
}

// Lấy thông tin phòng
Room* RoomManager::getRoomByNumber(int roomNumber) {
    auto it = rooms_.find(roomNumber);
    if (it != rooms_.end()) {
        return &it->second;
    }
    return nullptr;
}

// Lưu thông tin phòng vào file CSV
void RoomManager::saveToCSV(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        UI::showMessage("Không thể mở file " + filename);
        return;
    }

    outFile << "RoomNumber,Floor,Status,GuestName,GuestPhone,History\n";

    for (const auto& [roomNumber, room] : rooms_) {
        outFile << roomNumber << ","
                << room.getFloor() << ","
                << room.getStatus() << ","
                << room.getGuestName() << ","
                << room.getGuestPhone() << ","
                << room.getHistory() << "\n";
    }

    outFile.close();
    UI::showMessage("Lưu thông tin phòng vào file " + filename + " thành công.");
}

// Tải thông tin phòng từ file CSV
void RoomManager::loadFromCSV(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        UI::showMessage("Không thể mở file " + filename);
        return;
    }

    rooms_.clear();
    std::string line, header;
    std::getline(inFile, header); // Bỏ qua tiêu đề

    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string roomNumberStr, floorStr, status, guestName, guestPhone, history;

        std::getline(ss, roomNumberStr, ',');
        std::getline(ss, floorStr, ',');
        std::getline(ss, status, ',');
        std::getline(ss, guestName, ',');
        std::getline(ss, guestPhone, ',');
        std::getline(ss, history, ',');

        int roomNumber = std::stoi(roomNumberStr);
        int floor = std::stoi(floorStr);
        rooms_.emplace(roomNumber, Room(roomNumber, floor, status, guestName, guestPhone, history));
    }

    inFile.close();
    UI::showMessage("Tải thông tin phòng từ file " + filename + " thành công.");
}

// Đặt phòng
bool RoomManager::bookRoom(int roomNumber, const std::string& guestName, const std::string& guestPhone, const std::string& checkInTime) {
    Room* room = getRoomByNumber(roomNumber);
    if (room && room->getStatus() == "A") { // Phòng phải trống để đặt
        room->setStatus("U");
        room->setGuest(guestName, guestPhone);
        room->addHistory("Check-in: " + checkInTime);
        return true;
    }
    return false; // Không thể đặt phòng
}

// Trả phòng
bool RoomManager::checkoutRoom(int roomNumber, const std::string& checkOutDate, double totalCost, const std::string& feedback) {
    Room* room = getRoomByNumber(roomNumber);
    if (room && room->getStatus() == "U") { // Phòng phải đang được sử dụng
        room->setStatus("A");
        room->addHistory("Check-out: " + checkOutDate + " | Total cost: " + std::to_string(totalCost) + " | Feedback: " + feedback);
        room->clearGuest(); // Xóa thông tin khách
        return true;
    }
    return false; // Không thể trả phòng
}
