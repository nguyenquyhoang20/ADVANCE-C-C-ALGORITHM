# advance-C/C++-algorithm
# Pointer
1.void pointer
ví dụ

#include <stdio.h>

int main() { int a = 10; float b = 5.5;

// Khai báo con trỏ kiểu void
void *ptr;

// Gán địa chỉ của biến 'a' (kiểu int) cho con trỏ void
ptr = &a;

// Ép kiểu con trỏ void thành con trỏ int để lấy giá trị
printf("Giá trị của a: %d\n", *(int *)ptr);

// Gán địa chỉ của biến 'b' (kiểu float) cho con trỏ void
ptr = &b;

// Ép kiểu con trỏ void thành con trỏ float để lấy giá trị
printf("Giá trị của b: %.2f\n", *(float *)ptr);

return 0;
} Giải thích:

void *ptr; khai báo một con trỏ kiểu void, có thể trỏ đến bất kỳ loại dữ liệu nào. ptr = &a; gán địa chỉ của biến a (kiểu int) cho con trỏ ptr. Khi muốn truy xuất giá trị của a từ con trỏ ptr, ta phải ép kiểu con trỏ từ void * về kiểu int , sau đó mới dereference ((int *)ptr) để lấy giá trị. Tương tự, với biến b (kiểu float), ta phải ép kiểu từ void * về float * trước khi truy xuất giá trị.

pointer to function)
ví dụ #include <stdio.h>

// Hàm cộng hai số int add(int a, int b) { return a + b; }

// Hàm trừ hai số int subtract(int a, int b) { return a - b; }

int main() { // Khai báo con trỏ hàm int (*operation)(int, int);

// Gán hàm add vào con trỏ hàm
operation = &add;
printf("Kết quả của phép cộng: %d\n", operation(5, 3));

// Gán hàm subtract vào con trỏ hàm
operation = &subtract;
printf("Kết quả của phép trừ: %d\n", operation(5, 3));

return 0;
} giải thích Con trỏ operation có thể trỏ tới một hàm nhận 2 tham số kiểu int và trả về kiểu int.

Gán hàm vào con trỏ:

operation = &add; gán địa chỉ của hàm add vào con trỏ operation. Sau đó, có thể gọi hàm add thông qua con trỏ: operation(5, 3). Tương tự với hàm subtract:

operation = &subtract; gán địa chỉ của hàm subtract vào con trỏ operation và gọi hàm.

Pointer to Constant
ví dụ **#include <stdio.h>

int main() { int a = 10; int b = 20;

// Khai báo con trỏ tới hằng
const int *ptr = &a;

// Đọc giá trị mà con trỏ trỏ tới
printf("Giá trị của a: %d\n", *ptr);

// Không được phép thay đổi giá trị của a thông qua con trỏ
// *ptr = 15; // Lỗi: không thể gán giá trị thông qua con trỏ tới hằng

// Con trỏ vẫn có thể trỏ tới địa chỉ khác
ptr = &b;
printf("Giá trị của b: %d\n", *ptr);

return 0;
}

giải thích Khai báo con trỏ tới hằng:

c Sao chép mã const int *ptr = &a; Ở đây, ptr là con trỏ tới const int, nghĩa là không thể thay đổi giá trị của a thông qua con trỏ ptr Không thể thay đổi giá trị thông qua con trỏ: Nếu bạn cố gắng gán giá trị mới thông qua con trỏ:

*ptr = 15; // Lỗi: Không thể thay đổi giá trị mà con trỏ trỏ tới Điều này sẽ gây ra lỗi vì giá trị mà con trỏ trỏ tới là hằng số.

Thay đổi địa chỉ mà con trỏ trỏ tới: Mặc dù không thể thay đổi giá trị mà con trỏ trỏ tới, nhung vẫn có thể thay đổi địa chỉ trỏ tới

ptr = &b; Bây giờ con trỏ ptr sẽ trỏ tới b.

Constant Pointer
ví dụ #include <stdio.h>

int main() { int a = 10; int b = 20;

// Khai báo hằng con trỏ trỏ tới biến a
int *const ptr = &a;

// Thay đổi giá trị của a thông qua con trỏ
*ptr = 15;
printf("Giá trị của a sau khi thay đổi: %d\n", a);

// Không thể thay đổi địa chỉ mà con trỏ trỏ tới
// ptr = &b;  // Lỗi: Không thể thay đổi địa chỉ mà hằng con trỏ trỏ tới

return 0;
} giải thích không thể thay đổi địa chỉ của con trỏ Thay đổi giá trị qua con trỏ: Mặc dù không thể thay đổi địa chỉ mà ptr trỏ tới, nhưng có thể thay đổi giá trị của thông qua con trỏ

Pointer to Pointer
ví dụ #include <stdio.h>

int main() { int a = 10; int *ptr; // Con trỏ trỏ tới biến a int **ptr2ptr; // Con trỏ trỏ tới con trỏ ptr

// Gán địa chỉ của a cho ptr
ptr = &a;

// Gán địa chỉ của ptr cho ptr2ptr
ptr2ptr = &ptr;

// In giá trị của a thông qua con trỏ ptr
printf("Giá trị của a thông qua ptr: %d\n", *ptr);

// In giá trị của a thông qua con trỏ tới con trỏ ptr2ptr
printf("Giá trị của a thông qua ptr2ptr: %d\n", **ptr2ptr);

return 0;
} giải thích Khai báo con trỏ:

int *ptr: ptr là con trỏ trỏ tới biến a. int **ptr2ptr: ptr2ptr là con trỏ trỏ tới con trỏ ptr.

Gán địa chỉ: ptr = &a;: Gán địa chỉ của biến a cho con trỏ ptr. ptr2ptr = &ptr;: Gán địa chỉ của con trỏ ptr cho con trỏ ptr2ptr.

Truy xuất giá trị: *ptr: Lấy giá trị của a thông qua con trỏ ptr. **ptr2ptr: Lấy giá trị của a thông qua con trỏ tới con trỏ ptr2ptr.

NULL Pointer
ví dụ #include <stdio.h>

int main() { int *ptr = NULL; // Khai báo con trỏ NULL

// Kiểm tra con trỏ có trỏ tới địa chỉ hợp lệ hay không
if (ptr == NULL) {
    printf("Con trỏ ptr là NULL và không trỏ tới địa chỉ hợp lệ.\n");
} else {
    printf("Con trỏ ptr trỏ tới một địa chỉ hợp lệ.\n");
}

return 0;
}

giải thích Ở đây, ptr là một con trỏ có giá trị NULL, nghĩa là nó không trỏ tới bất kỳ đối tượng hay địa chỉ hợp lệ nào trong bộ nhớ.

