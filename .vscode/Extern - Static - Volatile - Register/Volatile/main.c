#include <stdio.h>
#include "sensor.h"


// Khai báo biến volatile để ngừng tối ưu hóa
volatile int sensorState = 0;  // 0 = OFF, 1 = ON

// Hàm giả lập thay đổi trạng thái cảm biến
void simulateSensorChange() {
    // Cảm biến thay đổi trạng thái sau mỗi giây
    sensorState = (sensorState == 0) ? 1 : 0;
}

// Hàm kiểm tra trạng thái của cảm biến
void checkSensorState() {
    // Giả lập thay đổi trạng thái cảm biến
    simulateSensorChange();

    // In ra trạng thái cảm biến
    if (sensorState == 1) {
        printf("Sensor is ON\n");
    } else {
        printf("Sensor is OFF\n");
    }
}


int main() {
    // Bắt đầu giám sát trạng thái cảm biến
    while (1) {
        checkSensorState();
    }

    return 0;
}
