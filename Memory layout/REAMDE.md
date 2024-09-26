 # calloc()
Trong C, hàm calloc() được sử dụng để cấp phát bộ nhớ động cho một mảng và khởi tạo tất cả các phần tử của nó về giá trị 0. Cú pháp của calloc()
**cú pháp** 
#void* calloc(size_t num, size_t size);

**ví dụ** 
'''c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    
    // Cấp phát bộ nhớ cho mảng 5 phần tử kiểu int và khởi tạo chúng về 0
    int* arr = (int*) calloc(n, sizeof(int));
    
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        return 1;
    }

    // In các giá trị trong mảng (tất cả đều sẽ là 0)
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Giải phóng bộ nhớ sau khi sử dụng
    free(arr);
    
    return 0;
}

**Tác dụng:**
Cấp phát bộ nhớ: calloc() sẽ cấp phát một khối bộ nhớ có kích thước bằng num * size byte.
Khởi tạo giá trị 0: Không giống như malloc(), calloc() sẽ khởi tạo toàn bộ khối bộ nhớ vừa cấp phát về giá trị 0. Điều này có ích khi muốn 
đảm bảo tất cả các phần tử trong mảng bắt đầu với giá trị 0.

|Tiêu chí |        malloc()                           |             calloc()         |
|--------------                                      |-------                        |  ------
| Khởi tạo giá trị | Không khởi tạo, chứa giá trị rác | Khởi tạo tất cả phần tử về 0 |
| Cú pháp          | Cấp phát một khối bộ nhớ duy nhất | Cấp phát bộ nhớ cho nhiều phần tử với kích thước cố định | 
| Hiệu suất  | Nhanh hơn vì không cần khởi tạo giá trị | Chậm hơn do cần khởi tạo giá trị về 0 |

**sử dụng**
 Khi cần bộ nhớ đã khởi tạo về 0, như trong trường hợp xử lý mảng hoặc các cấu trúc dữ liệu có giá trị mặc định ban đầu.
 
 # realloc()
 Hàm realloc() trong C được sử dụng để thay đổi kích thước của bộ nhớ đã cấp phát trước đó bằng malloc(), calloc(), hoặc realloc()
 **cú pháp**
 void* realloc(void* ptr, size_t new_size);
 
 **ví dụ**
 '''c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Cấp phát bộ nhớ cho mảng 5 phần tử
    arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        return 1;
    }

    // Khởi tạo giá trị cho mảng
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // In mảng ban đầu
    printf("Mảng ban đầu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Thay đổi kích thước mảng lên 10 phần tử
    n = 10;
    arr = (int*) realloc(arr, n * sizeof(int));

    if (arr == NULL) {
        printf("Lỗi cấp phát lại bộ nhớ!\n");
        return 1;
    }

    // Khởi tạo thêm phần tử mới
    for (int i = 5; i < n; i++) {
        arr[i] = i + 1;
    }

    // In mảng sau khi realloc
    printf("\nMảng sau khi cấp phát lại: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Giải phóng bộ nhớ sau khi sử dụng
    free(arr);

    return 0;
}
**tác dụng**
Mở rộng: Nếu kích thước mới lớn hơn, realloc() sẽ cấp phát thêm bộ nhớ và giữ nguyên dữ liệu cũ.
Thu nhỏ: Nếu kích thước mới nhỏ hơn, dữ liệu ngoài phạm vi kích thước mới sẽ bị cắt bỏ.Nếu không có đủ bộ nhớ để mở rộng, realloc() trả về con trỏ NULL,
và bộ nhớ ban đầu vẫn không bị thay đổi.

**So sánh malloc(), calloc(), và realloc():**

| Hàm | Tác dụng |Khởi tạo giá trị ban đầu| Khi nào dùng |
|--------------                                        |-------                   |------                            |-------|
| malloc()| Cấp phát bộ nhớ mới với kích thước cố định |          Không           | Khi cần cấp phát bộ nhớ mới      | 
| calloc() |Cấp phát bộ nhớ mới và khởi tạo về 0       |           Có             | Khi cần cấp phát và khởi tạo giá trị| 
|realloc() | Thay đổi kích thước vùng nhớ đã cấp phát  | Không (giữ nguyên dữ liệu cũ) | Khi cần thay đổi kích thước vùng nhớ ban đầu| 

# free()
Hàm free() trong C được sử dụng để giải phóng bộ nhớ đã được cấp phát trước đó bởi các hàm như malloc(), calloc(), hoặc realloc()
**cú pháp**
void free(void* ptr);

**ví dụ**
'''c
#include <stdio.h>  
#include <stdlib.h>  

int main() {  
    int *arr;  
    int n = 5;  

    // Cấp phát bộ nhớ cho mảng 5 phần tử  
    arr = (int*) malloc(n * sizeof(int));  

    if (arr == NULL) {  
        printf("Lỗi cấp phát bộ nhớ!\n");  
        return 1;  
    }  

    // Khởi tạo giá trị cho mảng  
    for (int i = 0; i < n; i++) {  
        arr[i] = i + 1;  
    }  

    // In giá trị của mảng  
    printf("Mảng: ");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  

    // Giải phóng bộ nhớ sau khi sử dụng  
    free(arr);  

    // Sau khi giải phóng, không nên sử dụng lại con trỏ arr  
    // printf("%d", arr[0]); // Truy cập sau khi free có thể gây ra lỗi  

    return 0;  
}

**tác dụng**
Giải phóng vùng nhớ được cấp phát trước đó. Sau khi gọi free(), vùng nhớ đó sẽ trở thành không hợp lệ và không thể truy cập được nữa. không sử dụng 
con trỏ trỏ đến vùng nhớ này sau khi đã gọi free().








