#include <stdio.h>
#include "student.h"


// Khai báo các biến static
static int totalScore = 0;  // Tổng điểm của tất cả sinh viên
static int studentCount = 0; // Số lượng sinh viên đã được nhập

// Hàm thêm điểm cho một sinh viên
void addStudent(int score) {
    totalScore += score;  // Cộng điểm của sinh viên vào tổng điểm
    studentCount++;       // Tăng số lượng sinh viên
}

// Hàm trả về tổng điểm của tất cả sinh viên
int getTotalScore() {
    return totalScore;
}

// Hàm trả về số lượng sinh viên đã được nhập
int getStudentCount() {
    return studentCount;
}

int main() {
    // Khởi tạo ba sinh viên với điểm số khác nhau
    addStudent(85);
    addStudent(90);
    addStudent(95);

    // Hiển thị tổng điểm của tất cả sinh viên
    printf("Total score of all students: %d\n", getTotalScore());

    // Hiển thị tổng số sinh viên đã được nhập
    printf("Total number of students: %d\n", getStudentCount());

    return 0;
}
