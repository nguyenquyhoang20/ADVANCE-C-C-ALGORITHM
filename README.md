# ADVANCE-C-C-ALGORITHM
# Pointer

**Khái niệm và các loại Pointer**
	Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số khái niệm cơ bản về con trỏ trong C:
**Cách khai báo:**
```cpp 
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float
```


**Lấy địa chỉ của một biến:**
```cpp
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
```


**Sử dụng con trỏ để truy cập giá trị:**
```cpp 
int y = *ptr_x;  // y sẽ bằng giá trị của x
```

 
Kích thước của con trỏ sẽ phụ thuộc kiến trúc máy tính và trình biên dịch. Ta có thể dùng sizeof() để kiểm tra kích thước của con trỏ:
```cpp 
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %lu bytes\n", sizeof(ptr));
    return 0;
}
```

Ví dụ:
```cpp 
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
}
```
 ## Các loại pointer:
## Void pointer:
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
```cpp
void *ptr_void;
```
Ví dụ:
```cpp 
#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));
   
    return 0;
}
```
## Pointer to Constant:
	Định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
	Ví dụ:
```cpp 
 #include <stdio.h>
 #include <stdlib.h>

int main() {
    
    int value = 5;
    int const *ptr_const = &value;

    //*ptr_const = 7; // wrong
    //ptr_const++; // right
    
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);

    return 0;
}
```


## Constant Pointer:
	Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
  ```cpp
#include <stdio.h>
#include <stdlib.h>
int main() {
    
    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    //const_ptr = &test; // wrong
    
    return 0;
}
```
## Function pointer:
Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
Ví dụ:
```cpp
#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```
	Trong ví dụ này, ptrToGreet là một con trỏ hàm có thể trỏ đến các hàm greetEnglish và greetFrench. Việc này giúp linh hoạt trong việc chọn và sử dụng hàm tương ứng tại thời điểm chạy.
	Ví dụ 2:
```cpp 
#include <stdio.h>

void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
    
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
    
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
    
}

void calculator(void (*ptr)(int a, int b), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}

int main()
{
    void (*ptrToFunc)(int,int);
    ptrToFunc = &divide;

    calculator(ptrToFunc,5,2);

    return 0;
} 
```
	Trong ví dụ này, ptrToFunc là một con trỏ hàm trỏ đến các hàm sum, subtract, multiple, divide. Hàm calculator với 3 tham số truyền vào là: con trỏ hàm, a, b, và sẽ call function mà con trỏ đang trỏ tới và truyền vào 2 tham số a và b.
## Pointer to pointer:
	Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
	Ví dụ:
```cpp
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    printf("Value: %d\n", **ptr2);

    return 0;
}
```
	Trong ví dụ này:
ptr1 là một con trỏ thường trỏ đến biến value.
ptr2 là một con trỏ đến con trỏ, trỏ đến địa chỉ của ptr1.
Khi sử dụng **ptr2, chúng ta có thể truy cập giá trị của biến value.
	Ứng dụng phổ biến trong cấp phát động mảng hai chiều:
```cpp
#include <stdio.h>
#include <stdlib.h>

void allocate2DArray(int ***arr, int rows, int columns) {
    // Cấp phát bộ nhớ cho mảng con trỏ
    *arr = (int**)malloc(rows * sizeof(int*));

    // Cấp phát bộ nhớ cho mỗi hàng
    for (int i = 0; i < rows; ++i) {
        (*arr)[i] = (int*)malloc(columns * sizeof(int));
    }
}

void initialize2DArray(int ***arr, int rows, int columns) {
    // Gán giá trị cho mảng 2D
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            (*arr)[i][j] = i * columns + j + 1;
        }
    }
}

void print2DArray(int **arr, int rows, int columns) {
    // In ra giá trị của mảng 2D
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

void free2DArray(int ***arr, int rows) {
    // Giải phóng bộ nhớ của mảng 2D
    for (int i = 0; i < rows; ++i) {
        free((*arr)[i]);
    }
    free(*arr);
}

int main() {
    int rows = 3, columns = 4;
    int **matrix;

    // Cấp phát bộ nhớ cho mảng 2D
    allocate2DArray(&matrix, rows, columns);

    // Khởi tạo giá trị cho mảng 2D
    initialize2DArray(&matrix, rows, columns);

    // In ra giá trị của mảng 2D
    printf("2D Array:\n");
    print2DArray(matrix, rows, columns);

    // Giải phóng bộ nhớ của mảng 2D
    free2DArray(&matrix, rows);

    return 0;
}
```



## NULL pointer:
	Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
	Ví dụ:
```cpp 
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    return 0;
}
```

Trong ví dụ này:
Con trỏ ptr được khai báo và được gán giá trị NULL.
Một điều kiện kiểm tra xem con trỏ có trỏ đến một đối tượng nào đó hay không.
Nếu con trỏ bằng NULL, chương trình in ra "Pointer is NULL", ngược lại nếu con trỏ không bằng NULL, chương trình in ra "Pointer is not NULL".
Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.

# Extern - Static - Volatile

## Extern
	Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
	Ví dụ:
	File main.c
 ```cpp
#include <stdio.h>

int value = 90;
extern void display();

int main()

{
	printf("hello\n");
	display();
}

```
	File other.c
 ```cpp 
#include <stdio.h>

extern int value;
void display()
{
	printf("value: %d\n", value);
}
```

***Ứng dụng:**
- Chia sẻ biến và hàm giữa các file nguồn:
Extern cho phép bạn chia sẻ biến và hàm giữa nhiều file nguồn trong một chương trình.
Điều này hữu ích khi bạn muốn tách chương trình thành các phần nhỏ để quản lý dễ dàng hơn.
- Chia sẻ biến và hàm giữa các module hoặc thư viện:
Extern có thể được sử dụng để kết nối các module hoặc thư viện trong một dự án lớn.
- Khai báo hàm trong trường hợp định nghĩa sau:
Nếu bạn muốn sử dụng một hàm trước khi nó được định nghĩa trong mã nguồn, bạn có thể sử dụng extern để khai báo hàm.
- Biến toàn cục giữa các tệp nguồn:
Khi có một biến toàn cục được sử dụng trong nhiều file nguồn, extern giúp các file nguồn biết về sự tồn tại của biến đó.
- Chia sẻ hằng số giữa các file nguồn:
Nếu bạn có một hằng số được sử dụng ở nhiều nơi, bạn có thể sử dụng extern để chia sẻ giá trị của hằng số đó giữa các file nguồn.
## Static
### Static local variables
Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.
Ví dụ:
```cpp 
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}
```
Ứng dụng:
Lưu trữ trạng thái giữa các lần gọi hàm: Sử dụng biến static để theo dõi trạng thái trạng thái giữa các lần gọi hàm mà không cần sử dụng biến toàn cục.
### Static global variables
	Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.
	Ví dụ:
	File main.c
 ```cpp 
#include <stdio.h>
extern void display();
//extern int s_g_value;
extern int g_value;
int main()
{
	printf("hello\n");
	g_value = 40;
	
	display();

	return 0;
}
```
	File other.c:
 ```cpp 
#include <stdio.h>

int g_value = 30;
static int s_g_value = 20;


void display()
{
	printf("static global value: %d\n", s_g_value);
	printf("global value: %d\n", g_value);
}
```

### Static trong class
Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.
	Ví dụ:
 ```cpp 
#include <iostream>

typedef enum
{
    red = 0,
    blue,
    green,
    purple,
    black,
    yellow
} Pen_Color;

void print_color_pen(Pen_Color color)
{
    switch (color)
    {
    case red:
        std::cout << "Red\n";
        break;
    case blue:
        std::cout << "Blue\n";
        break;
    case green:
        std::cout << "Green\n";
        break;
    
    default:
        break;
    }
}
class PEN
{
public:
    Pen_Color pen_color;
    static int pen_length;

    PEN(Pen_Color color);
    Pen_Color get_color()
    {
        return pen_color;
    }
    void set_length(int length)
    {
        pen_length = length;
    }
};

int PEN::pen_length;

PEN::PEN(Pen_Color color)
{
    pen_color = color;
    pen_length = 10;
}
int main(int argc, char const *argv[])
{
    PEN blue_pen(blue);
    PEN red_pen(red);
    PEN green_pen(green);

    blue_pen.set_length(9);

    std::cout << "Color: ";
    print_color_pen(blue_pen.get_color());
    std::cout << "Length: " << blue_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(red_pen.get_color());
    std::cout << "Length: " << red_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(green_pen.get_color());
    std::cout << "Length: " << green_pen.pen_length << '\n';

    return 0;
}
```
## Volatile
	Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
	Ví dụ:


## Register
	Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.
	Ví dụ:
 ```cpp 
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();

    // Đoạn mã của chương trình
    for (int i = 0; i < 1000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}
```
# Goto - setjmp.h

## Goto trong C
“ goto ” là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm. Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.
Ví dụ:
```cpp 
#include <stdio.h>

int main() {
    int i = 0;

    // Đặt nhãn
    start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }

        printf("%d ", i);
        i++;

        goto start;  // Chuyển control đến nhãn "start"

    // Nhãn "end"
    end:
        printf("\n");

    return 0;
}
``` 

Trong ví dụ này, goto được sử dụng để tạo một vòng lặp đơn giản. Khi i đạt đến giá trị 5, control sẽ chuyển đến nhãn "end" và kết thúc chương trình.
* Việc sử dụng goto có thể làm cho mã nguồn trở nên khó bảo trì và khó đọc. Nhiều lập trình viên và chuẩn coding conventions không khuyến khích sử dụng goto nếu có cách thức khác để thực hiện logic. Thay vào đó, sử dụng các cấu trúc kiểm soát vòng lặp (for, while, do-while) và cấu trúc điều kiện (if, else) để viết mã nguồn dễ đọc và bảo trì hơn. 
* Mặc dù sử dụng goto không được khuyến khích trong phần lớn các trường hợp vì nó có thể làm tăng khả năng phức tạp và khó bảo trì của mã nguồn, nhưng có một số tình huống cụ thể mà việc sử dụng goto có thể được coi là hợp lý:
	- Thoát khỏi nhiều cấp độ vòng lặp
	Trong một số trường hợp, việc thoát khỏi nhiều cấp độ vòng lặp có thể trở nên phức tạp nếu sử dụng cấu trúc kiểm soát vòng lặp thông thường. Trong tình huống như vậy, goto có thể được sử dụng để dễ dàng thoát khỏi nhiều cấp độ vòng lặp.
	Ví dụ:
 ```cpp 
for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
        if (some_condition(i, j)) {
            goto exit_loops;
        }
    }
}

exit_loops:
```
	- Xử lý lỗi và giải phóng bộ nhớ
	Trong trường hợp xử lý lỗi, có thể sử dụng goto để dễ dàng giải phóng bộ nhớ đã được cấp phát trước khi thoát khỏi hàm.
 ```cpp 
void process_data() {
    int *data = malloc(sizeof(int) * 100);
    if (data == NULL) {
        goto cleanup;
    }

    // Xử lý dữ liệu ở đây

    cleanup:
    free(data);
}
``` 



**Implement Finite State Machines (FSM)**
	Trong một số trường hợp, đặc biệt là khi triển khai Finite State Machines, goto có thể được sử dụng để chuyển đến các trạng thái khác nhau một cách dễ dàng.
 ```cpp 
switch (current_state) {
    case STATE_A:
        // Xử lý State A
        if (condition) {
            goto STATE_B;
        }
        break;

    case STATE_B:
        // Xử lý State B
        break;
}
```



## Thư viện setjmp.h
setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.
Ví dụ:	
```cpp 
#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

void risky_function() {
    printf("Entering risky_function\n");
    
    // Thiết lập điểm cho việc "quay lại"
    if (setjmp(buffer) != 0) {
        printf("Exiting risky_function due to longjmp\n");
        return;
    }

    // Mô phỏng một tình huống lỗi
    int error_condition = 1;
    if (error_condition) {
        printf("Error detected in risky_function\n");
        longjmp(buffer, 1);  // "Quay lại" tới điểm đã được thiết lập bởi setjmp
    }

    printf("Exiting risky_function normally\n");
}

int main() {
    printf("Starting main\n");
    risky_function();
    printf("Back in main after risky_function\n");

    return 0;
}
```
Trong ví dụ này, setjmp được sử dụng để thiết lập một điểm, và longjmp được sử dụng để "quay lại" điểm đã được thiết lập đó khi một tình huống lỗi được phát hiện trong hàm risky_function.
# Struct - Union
## Struct
Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.
	Cú pháp:
 ```cpp 
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```

Ví dụ:
 ```cpp
struct Point {
    int x;
    int y;
};
```
Thành Viên (Member): Mỗi biến trong struct được gọi là một thành viên hoặc trường. Trong ví dụ struct Point, x và y là các thành viên của Point.
**Khởi Tạo và Truy Cập Thành Viên:**
	Để khởi tạo một biến thuộc kiểu struct, bạn sử dụng cú pháp như sau:
 ```cpp 
struct Point p1 = {10, 20};
```

**Để truy cập các thành viên, bạn sử dụng toán tử ( . ):**
```cpp 
printf("X coordinate: %d\n", p1.x);
```
**Sử Dụng Tham Số Trong Hàm:**
Bạn có thể truyền một biến thuộc kiểu struct như một tham số cho một hàm.
```cpp 
void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}
```
**Truyền Con Trỏ đến Struct:**
Bạn có thể truyền con trỏ đến struct như một tham số cho một hàm, cho phép thay đổi giá trị của struct bên trong hàm.
```cpp
void updatePoint(struct Point* p, int newX, int newY) {
    p->x = newX;
    p->y = newY;
}
```

**Sử Dụng typedef để Tạo Bí Danh:**
Bạn có thể sử dụng typedef để tạo bí danh cho struct, giúp rút ngắn cú pháp khi khai báo biến.
```cpp
typedef struct Point {
    int x;
    int y;
} Point;
```
Sau đó, bạn có thể khai báo biến như sau:
```cpp
Point p1 = {10, 20};
```
struct giúp tổ chức dữ liệu một cách hiệu quả và làm cho mã nguồn trở nên dễ đọc và bảo trì hơn.

## Union	
Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào một cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng.
Cú pháp định nghĩa union trong C như sau:
```cpp 
union TenUnion {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```
Ví dụ:
```cpp 
union Data {
    int i;
    float f;
    char str[20];
};
```
Trong đoạn mã trên, union Data định nghĩa một kiểu dữ liệu mới có ba thành viên là i (kiểu int), f (kiểu float), và str (mảng kiểu char).
Các khái niệm chính của union trong C bao gồm:
**Tiết kiệm bộ nhớ:**
union tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên. Kích thước của union là kích thước của thành viên lớn nhất.
Truy cập thành viên:
Bạn truy cập các thành viên của union bằng cách sử dụng toán tử . như struct.
```cpp 
union Data data;
data.i = 10;
printf("Value of i: %d\n", data.i);
```
**Sử dụng trong các tình huống đặc biệt**
	union thường được sử dụng khi bạn có một biến có thể chứa một trong các kiểu dữ liệu khác nhau và bạn chỉ cần sử dụng một kiểu dữ liệu tại một thời điểm.
 ```cpp 
union Value {
    int intValue;
    float floatValue;
    char stringValue[20];
};
```
**Biểu diễn dữ liệu tương đồng**
	Khi bạn có các dữ liệu có ý nghĩa tương đồng nhưng có kiểu dữ liệu khác nhau, union giúp bạn biểu diễn chúng một cách hiệu quả.
 ```cpp
union Measurement {
    int height;
    float depth;
    double distance;
};
```
**Lưu trữ dữ liệu tạm thời**
	union có thể được sử dụng để lưu trữ dữ liệu tạm thời khi bạn cần một biến có thể chứa một trong các kiểu dữ liệu khác nhau tùy thuộc vào tình huống.
 ```cpp 
union TemporaryData {
    int intValue;
    float floatValue;
    char stringValue[20];
};
```
Lưu ý rằng khi sử dụng union, cần phải kiểm soát rất cẩn thận để tránh những lỗi gây ra bởi việc truy cập vào thành viên không hợp lệ, vì bạn chỉ nên đọc giá trị của thành viên bạn đã ghi vào gần đây nhất.

# Memory layout
**Khái niệm**
Trong ngôn ngữ lập trình C, bộ nhớ của chương trình thường được phân chia thành các phân vùng khác nhau, mỗi phân vùng có mục đích và quy tắc sử dụng riêng. Dưới đây là một số phân vùng nhớ quan trọng trong C:
## Text Segment
Text Segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ mã máy của chương trình. Cụ thể, Text Segment chứa mã máy đã được biên dịch từ mã nguồn của chương trình và được CPU thực thi để thực hiện các hành động quy định trong chương trình.
Một số đặc điểm:
- Mã máy:
 	- Chứa mã máy, tức là tập hợp các lệnh thực thi được CPU hiểu được.
 	- Mã máy được tạo ra thông qua quá trình biên dịch từ mã nguồn của chương trình.
- Quyền truy cập:
	 - Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. điều này ngăn chặn chương trình việc tự sửa đổi mã máy của nó.
- Kích thước cố định:
	 - Kích thước của Text Segment thường là cố định khi chương trình được biên dịch.
Điều này giúp hệ điều hành và CPU dễ dàng quản lý vùng nhớ này.
- Lưu Trữ Code và Hằng Số:
	 - Bao gồm cả mã máy của các hàm và các hằng số.
	 - Các hàm được gọi từ các phần khác của chương trình sẽ có địa chỉ trong Text Segment.

## Data Segment
Data Segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ dữ liệu tĩnh của chương trình. Dữ liệu tĩnh bao gồm biến toàn cục và biến tĩnh (static), tức là các biến mà không phụ thuộc vào thời gian chạy của chương trình. 
1. Một số đặc điểm:
	- Biến Toàn Cục (Global Variables):
		- Chứa giá trị của các biến toàn cục được khai báo trong chương trình.
 		- Các biến này có thể được truy cập từ bất kỳ hàm nào trong chương trình.
	 - Biến Tĩnh (Static Variables):
		- Chứa giá trị của các biến tĩnh, nghĩa là biến được khai báo với từ khóa static.
        	- Có thể được truy cập chỉ trong phạm vi của hàm mà chúng được khai báo.
	- Initialized Data Segment (Dữ liệu Đã Khởi Tạo):
		- Chứa giá trị của các biến toàn cục và biến tĩnh được khởi tạo với giá trị ban đầu.
 		- Dữ liệu này được sao chép từ bộ nhớ của chương trình thực thi.
	- Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):
		- Chứa giá trị mặc định của các biến toàn cục và biến tĩnh mà không cần khởi tạo giá trị ban đầu.
		- Dữ liệu trong phân vùng này thường được xác định bởi giá trị 0.
- Quyền truy cập: Data Segment thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong quá trình thực thi của chương trình.
- Kích thước cố định: Kích thước của Data Segment có thể thay đổi trong quá trình thực thi của chương trình khi các biến được khởi tạo hoặc giải phóng.
## Heap
Heap là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để cấp phát bộ nhớ động. Các biến được cấp phát trên heap không có kích thước xác định tại thời điểm biên dịch và có thể được quản lý động trong quá trình thực thi của chương trình.
Một số đặc điểm:
- Cấp phát động:
	- Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
- Quyền truy cập: Bộ nhớ trên heap thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong suốt thời gian chương trình chạy.
	- Cấp Phát và Giải Phóng Bộ Nhớ: Các hàm như malloc(), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.
- Kích Thước Thay Đổi: Kích thước của heap có thể thay đổi trong quá trình thực thi của chương trình, tùy thuộc vào các thao tác cấp phát và giải phóng bộ nhớ.
- Không Giữ Giá Trị Mặc Định: Bộ nhớ trên heap không giữ giá trị mặc định như trong Data Segment. Nếu không được khởi tạo, giá trị của biến trên heap sẽ không xác định.
	Ví dụ cấp phát động:
 ```cpp 
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Cấp phát bộ nhớ động cho một biến kiểu int
    int *dynamicVar = (int *)malloc(sizeof(int));

    if (dynamicVar != NULL) {
        // Gán giá trị cho biến trên heap
        *dynamicVar = 42;

        // In giá trị
        printf("Value on heap: %d\n", *dynamicVar);

        // Giải phóng bộ nhớ trên heap
        free(dynamicVar);
    }

    return 0;
}
```
## Stack
Stack là một phần quan trọng của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính. Nó được sử dụng để lưu trữ các biến cục bộ, các giá trị trả về từ hàm, địa chỉ trả về và một số thông tin khác liên quan đến thực thi của chương trình. 
Một số đặc điểm:
- LIFO: Stack hoạt động theo nguyên tắc LIFO, nghĩa là phần tử cuối cùng được thêm vào sẽ là phần tử đầu tiên được lấy ra.
- Các biến cục bộ: Chứa các biến cục bộ, tức là các biến được khai báo trong các hàm và chỉ có giá trị trong phạm vi của hàm đó.
- Kích thước cố định: Tùy thuộc vào hệ điều hành khác nhau
- Địa chỉ trả về: Khi một hàm được gọi, địa chỉ trả về (return address) được đẩy vào ngăn xếp để theo dõi nơi chương trình sẽ tiếp tục sau khi hàm kết thúc thực thi.
- Thực hiện gọi hàm và trả về: Khi một hàm được gọi, các giá trị và địa chỉ quan trọng liên quan đến hàm đó được đẩy vào ngăn xếp. Sau khi hàm kết thúc, những giá trị này được lấy ra để quay trở lại thực thi chương trình.
- Khối lệnh ( Frame): Mỗi hàm khi được gọi tạo ra một khối lệnh (frame) trên ngăn xếp, chứa các biến cục bộ và các giá trị khác liên quan đến hàm.
- Stack pointer: Con trỏ ngăn xếp (stack pointer) giữ địa chỉ hiện tại của stack và được cập nhật liên tục khi dữ liệu được đẩy vào hoặc lấy ra.
	Stack là một cơ chế quan trọng trong quá trình thực thi chương trình và thường được sử dụng để quản lý luồng thực thi, gọi hàm, và theo dõi các biến cục bộ. Các ngôn ngữ lập trình thường sử dụng ngăn xếp để triển khai thực thi hàm và quản lý các biến cục bộ.
### Memory - mapped Segment
Memory-mapped segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để tương tác với các thiết bị ngoại vi thông qua các địa chỉ bộ nhớ. Thông thường, các thiết bị ngoại vi như cổng vào/ra (I/O ports) và thanh ghi của các thiết bị được ánh xạ trực tiếp vào không gian địa chỉ bộ nhớ của chương trình.
Một số đặc điểm:
- Tương tác với thiết bị ngoại vi: Memory-mapped segment cho phép chương trình tương tác với các thiết bị ngoại vi bằng cách truy cập địa chỉ bộ nhớ tương ứng với các thanh ghi và cổng I/O của các thiết bị đó.
- Địa chỉ bộ nhớ ánh xạ: Các địa chỉ bộ nhớ của các thanh ghi và cổng I/O của các thiết bị ngoại vi được ánh xạ vào không gian địa chỉ bộ nhớ của chương trình.
- Quyền truy cập: Memory-mapped segment thường có thể có quyền đọc và ghi để cho phép chương trình gửi dữ liệu đến thiết bị và đọc dữ liệu từ thiết bị.
- Giao tiếp với thiết bị ngoại vi: Thông qua Memory-mapped segment, chương trình có thể gửi lệnh và nhận dữ liệu từ các thiết bị ngoại vi, như cổng COM, bàn phím, màn hình và các thiết bị khác.
- Sử dụng trong ngôn ngữ mã máy và assembly: Memory-mapped segment thường được sử dụng nhiều trong ngôn ngữ máy và ngôn ngữ gần với phần cứng để thực hiện các thao tác gần với phần cứng của hệ thống.
- Điều khiển thiết bị: Ánh xạ địa chỉ bộ nhớ của các thanh ghi và cổng I/O của thiết bị ngoại vi cho phép chương trình kiểm soát và điều khiển các thiết bị ngoại vi.
Lưu ý rằng sử dụng Memory-mapped segment đôi khi yêu cầu quyền hệ điều hành và có thể chỉ có sẵn trong môi trường thực thi nào đó (ví dụ như hệ điều hành Unix-like).

# Stack và Heap
	- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
	- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
	- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).

	Kích thước vùng nhớ:
### Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
### Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.

**Đặc điểm vùng nhớ:**
### Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
### Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

**Vấn đề lỗi xảy ra với vùng nhớ:**
**Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...**
	Ví dụ tràn bộ nhớ stack khi gọi hàm đệ quy vô hạn:
 ```cpp 
int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
}
```

**Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.**
	Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
 ```cpp
int *A = (int *)malloc(18446744073709551615);
```
# JSON
Khái niệm
	JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp khóa-giá trị, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.
Ví dụ:
```cpp
{
  "name": "John Doe",
  "age": 30,
  "city": "New York",
  "isStudent": false,
  "grades": [85, 90, 78]
}
```



**Định dạng của JSON**
**Kiểu dữ liệu:**
Null (Giá trị rỗng): null
```cpp 
null
```
Boolean (Luận lý): true hoặc false.
```cpp 
true
false
```
Number (Số): Có thể là số nguyên hoặc số thập phân. Số không được bao bọc bởi dấu ngoặc.
```cpp 
42
3.14
```
String (Chuỗi): Chuỗi ký tự, được bao bọc bởi dấu nháy đơn ('') hoặc dấu nháy kép ("").
```cpp 
"Hello, World!"
```
Array (Mảng): Một danh sách các giá trị, giữa mỗi giá trị sử dụng dấu phẩy. Mảng được bao bọc bởi dấu ngoặc vuông ([]).
```cpp
[1, 2, 3, 4, 5]
```
Object (Đối tượng): Một tập hợp các cặp key - value, giữa mỗi cặp sử dụng dấu hai chấm (:). Đối tượng được bao bọc bởi dấu ngoặc nhọn ({}).
```cpp
{
  "name": "John",
  "age": 30,
  "city": "New York"
}
``` 

**Key - Value**
	Mỗi cặp key - value được phân tách bằng dấu hai chấm (:).
Các cặp khóa-giá trị trong đối tượng được phân tách bằng dấu phẩy ({ "key1": "value1", "key2": "value2" }).
**Dấu ngoặc**
- Dấu ngoặc nhọn ({}) được sử dụng để bao bọc đối tượng.
- Dấu ngoặc vuông ([]) được sử dụng để bao bọc mảng.
**Dấu phẩy**
	- Dấu phẩy được sử dụng để phân tách giữa các thành phần trong mảng hoặc các cặp khóa-giá trị trong đối tượng.
**Khoảng trắng**
	- Khoảng trắng, dấu xuống dòng và tab không ảnh hưởng đến tính chính xác của JSON và thường được sử dụng để làm cho JSON dễ đọc hơn.
Nhận xét
JSON không hỗ trợ cú pháp nhận xét nội dung. Bất kỳ văn bản nào sau dấu nhận xét (// hoặc /* */) không được hiểu là hợp lệ trong JSON.
# Linked List
Khái niệm
Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
Có hai loại linked list chính:
- Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
- Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.
Một linked list cung cấp một cách linh hoạt để thêm, xóa và chèn các phần tử mà không cần phải di chuyển toàn bộ dãy số như mảng. Tuy nhiên, nó cũng có một số nhược điểm, như việc cần thêm một con trỏ cho mỗi nút, tăng độ phức tạp của bộ nhớ và có thể dẫn đến hiệu suất kém hơn trong một số trường hợp so với mảng.
Dưới đây là định nghĩa 1 node trong singly linked list:
```cpp 
struct Node {
    int data;         // Dữ liệu của nút
    Node* next;       // Con trỏ đến nút tiếp theo trong danh sách
};
```


**Một số thao tác trong list:**
**Khởi tạo một node:**
```cpp 
node *createNode(int value)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
```

**Chèn một node vào cuối list:**
```cpp 
void push_back(node** array, int value)
{
    node *temp, *p;
    temp = createNode(value);
    
    p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist

    if (*array == NULL)   // if array doesn't have any node yet
    {
        
        *array = temp;
    }
    else                // if array has some node
    {      
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
            
        }
        
        p->next = temp;     // change it next member point to address of new node have just create
    }
}
```

**Xóa node cuối cùng của list:**
```cpp 
void pop_back(node **array)
{
    node *p, *temp;
    p = *array;
    int i = 0; // to 

    while (p->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    free(p);

    temp = *array;
    int j;
    for ( j = 0; j < i - 1 ; j++)    // change the next member of the node at the (last - 1) position to NULL
    {
        temp = temp->next;
    }
    
    temp->next = NULL;
}
```
# Stack - Queue
## Stack
Stack (ngăn xếp) là một cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra. 
**Các thao tác cơ bản trên stack bao gồm:
“ push” (đẩy) để thêm một phần tử vào đỉnh của stack.
“ pop” để xóa một phần tử ở đỉnh stack.
“ top” để lấy giá trị của phần tử ở đỉnh stack.**
```cpp 
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty( Stack stack) {
    return stack.top == -1;
}

int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    return 0;
}
```
giải thích code:
Định nghĩa cấu trúc
```cpp
typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;
```
Mục đích : Điều này struct định nghĩa một ngăn xếp có ba thành phần:
- items: Một con trỏ tới một mảng lưu trữ các phần tử ngăn xếp một cách động.
- size: Sức chứa tối đa của ngăn xếp.
- top: Theo dõi chỉ mục của phần tử trên cùng trong ngăn xếp ( -1 khi ngăn xếp trống).

## Queue
Queue là một cấu trúc dữ liệu tuân theo nguyên tắc "First In, First Out" (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra. 
Các thao tác cơ bản trên hàng đợi bao gồm:
**“enqueue” (thêm phần tử vào cuối hàng đợi)
“dequeue” (lấy phần tử từ đầu hàng đợi). 
“front” để lấy giá trị của phần tử đứng đầu hàng đợi.**
```cpp 
#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));

    return 0;
}
```
# Class
Khái niệm
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 
Cú pháp:
```cpp 
class ClassName {
private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...

protected:
    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa

public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...

};
```
	Ví dụ:
 ```cpp
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
};
int main()
{
    HinhChuNhat hinh1;
    hinh1.chieuDai = 10.0;
    hinh1.chieuRong = 5.0;

    std::cout << "Chieu dai: " << hinh1.chieuDai << '\n';


    return 0;
}
```
Trong class cho phép khai báo các function như member. 
	Ví dụ:
 ```cpp 
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
    void display();
};

void HinhChuNhat::display()
{
   std::cout << " Hello " << '\n';
}
int main()
{
    HinhChuNhat hinh1;
    hinh1.chieuDai = 10.0;
    hinh1.chieuRong = 5.0;

    hinh1.display();

    std::cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';


    return 0;
}
```

## Constructor và Destructor
### Constructor
Constructor trong C++ là một function sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.
Ví dụ:
```cpp 
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }

    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
   
};
int main()
{
    HinhChuNhat hinh1;


    std::cout << "Chieu dai: " << hinh1.chieuDai << '\n';


    return 0;
}
```
### Destructor
Destructor trong C++ là một function sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
	Ví dụ:
 ```cpp 
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }
    ~HinhChuNhat(){
        std::cout << "Destructor " << '\n';
    }


    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
   
};

int main()
{
    HinhChuNhat hinh1;
    std::cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';


    return 0;
}
``` 



## Biến static trong class
Khi một biến trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của biến này.
Ví dụ:
```cpp 
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    
    static int var;
};


int HinhChuNhat::var;

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    cout << "address of chieu dai: " << &hinh1.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh2.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh3.chieuDai << '\n'; 

    cout << "address of var: " << &hinh1.var << '\n'; 
    cout << "address of var: " << &hinh2.var << '\n'; 
    cout << "address of var: " << &hinh3.var << '\n'; 


    return 0;
}
``` 
# OOP
## Tính đóng gói
Tính đóng gói (Encapsulation) là ẩn đi các property “mật” khỏi người dùng. Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private (tức là không thể truy cập trực tiếp tới các property này thông qua object). 
Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta sẽ truy cập gián tiếp thông qua các method ở quyền truy cập public.
```cpp 
#include <iostream>
#include <string>
using namespace std;

class SinhVien{
    private:
        string name;
        int id;
   
    public:
        SinhVien(){
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string newName){   // setter method
            // kiểm tra điều kiện
            name = newName;
        }

        string getName(){   // getter method
            return name;
        }

        int getID(){
            return id;
        }

        void display(){
            cout << "Ten: " << getName() << endl;
            cout << "ID: " << getID() << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1, sv2;

    sv1.setName("Trung");
    sv1.display();

    sv2.setName("Tuan");
    sv2.display();
    return 0;
}
``` 
## Tính kế thừa
Tính kế thừa ( Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác. Ta chia chúng làm 2 loại là class cha và class con. Để kế thừa từ class khác, ta dùng ký tự ":".
Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.
### Kế thừa public
- Các member public của class cha vẫn sẽ là public trong class con.
- Các member protected của class cha vẫn sẽ là protected trong class con.
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha
```cpp 
#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    // private:
    //    string ten;
    //    int id;

    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};

int main(int argc, char const *argv[])
{
    // SinhVien sv1;

    // sv1.ten = "Hoang";
    // sv1.id = 1;
    // sv1.chuyenNganh = "DTVT";

    // cout << "ID: " << sv1.id << endl;
    // cout << "Ten: " << sv1.ten << endl;
    // cout << "Chuyen nganh: " << sv1.chuyenNganh << endl;

    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");
    sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");
    hs1.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");
    gv1.display();
    return 0;
}
```
### Kế thừa protected
- Các member public, protected của class cha sẽ là protected trong class con.
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
```cpp 
#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : protected DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void setNameSV(string _ten){
            ten = _ten;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setNameSV("Trung");
    sv1.setChuyenNganh("TDH");
    sv1.display();
    return 0;
}
```
### Kế thừa private
- Các member public, protected của class cha sẽ trở thành private trong class con.
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
```cpp 
#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : private DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void setNameSV(string _ten){
            ten = _ten;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setNameSV("Trung");
    sv1.setChuyenNganh("TDH");
    sv1.display();
    return 0;
}
```
## Tính đa hình
Tính đa hình ( Polymorphism) có nghĩa là "nhiều dạng" và nó xảy ra khi chúng ta có nhiều class có liên quan với nhau thông qua tính kế thừa.
Function overloading cung cấp nhiều định nghĩa cho 1 function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.
Tính đa hình có thể được chia thành hai loại chính:
**Đa hình tại thời điểm biên dịch (Compile-time Polymorphism).
Đa hình tại thời điểm chạy (Run-time Polymorphism).**
```cpp 
#include <iostream>
#include <string>

using namespace std;

// 1 method có thể có nhiều input parameter, return type khác nhau
class TinhToan{
    private:
        int a;
        int b;
    public:
        int tong(int a, int b){
            return a+b;
        }
        double tong(int a, int b, int c, double d){
            return (double)a+b+c+d;
        }
        double tong(int a, double b){
            return (double)a+b;
        }
};

int main(int argc, char const *argv[]){

    TinhToan th, th1, th2;
    cout << th.tong(2, 5) << endl;
    cout << th1.tong(2, 5, 7, 6.7) << endl;
    cout << th2.tong(2, 3.5) << endl;

    return 0;
}
```
## Tính trừu tượng
Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.
```cpp 
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GiaiPhuongTrinh{
    private:	// a,b,c,x1,x2,delta: tính đóng gói
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;
        void tinhNghiem(){	// tính trừu tượng
            delta = b*b - 4*a*c;
            if (delta < 0){
                delta = -1;
            }
            else if (delta == 0){
                x1 = x2 = -b/ (2*a);
            }
            else if (delta > 0){
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);
            }
        }
       
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();

};

void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c){
    a = num_a;
    b = num_b;
    c = num_c;
}

void GiaiPhuongTrinh::printResult(){
    tinhNghiem();
    if (delta == -1){
        cout << "PT vo nghiem" << endl;
    }
    else if (delta == 0){
        cout << "PT co nghiem chung: " << x1 << endl;
    }
    else if (delta > 0){
        cout << "PT co 2 nghiem: \n";
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }
}
int main()
{
  GiaiPhuongTrinh phuongtrinh1;
  phuongtrinh1.enterNumber(1,5,4);
  phuongtrinh1.printResult();
  return 0;
}
```
# Virtual Function

Hàm ảo là một hàm thành viên được khai báo trong class cha với từ khóa virtual.
- Khi một hàm là virtual, nó có thể được ghi đè (override) trong class con để cung cấp cách triển khai riêng.
- Khi gọi một hàm ảo thông qua một con trỏ hoặc tham chiếu đến lớp con, hàm sẽ được quyết định dựa trên đối tượng thực tế mà con trỏ hoặc tham chiếu đang trỏ tới chứ không dựa vào kiểu của con trỏ.
```cpp
class Base{
    public:
        virtual void display(){
            cout << "Display from Base class" << endl;
        }
};
```
## Override và tính đa hình Run - time
### Override
Override là việc ghi đè hàm ảo ở class con bằng cách định nghĩa lại nó. 
- Khi một hàm ảo được ghi đè, hành vi của nó sẽ phụ thuộc vào kiểu của đối tượng thực tế, chứ không phải kiểu của con trỏ hay tham chiếu.
Tính đa hình Run-time xảy ra khi quyết định gọi hàm nào (phiên bản của class cha hay class con) được đưa ra tại thời điểm chạy, không phải lúc biên dịch, giúp mở rộng chức năng. Điều này giúp chương trình linh hoạt hơn, cho phép việc mở rộng chức năng mà không cần sửa đổi mã nguồn hiện tại.
Cú pháp:
```cpp 
#include <iostream>
using namespace std;

class cha{
    public:
        virtual void display(){                            // Hàm ảo
            cout << "display from class cha" << endl;
        }
};

class con : public cha{
    public:
        void display() override{                           // Ghi đè hàm ảo
            cout << "display from class con" << endl;
        }
};

int main(){
    cha *ptr;
    con obj;

    // trỏ con trỏ class cha đến đối tượng class con
    ptr = &obj;

    // Gọi hàm ảo
    ptr->display();
}
```
ví dụ:
```cpp  
#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        virtual void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display() override {
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display() override {
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display() override {
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");

    DoiTuong *dt;

    dt = &sv1;
    dt->display();

    dt = &hs1;
    dt->display();

    dt = &gv1;
    dt->display();


    // DoiTuong *ptr[] = {&sv1, &hs1, &gv1};

    // ptr[0]->display();
    // ptr[1]->display();
    // ptr[2]->display();

    return 0;
}
```
## Pure Virtual Function
Hàm ảo thuần túy là một hàm ảo không có phần định nghĩa trong class cha, được khai báo với cú pháp = 0 và khiến class cha trở thành class trừu tượng, nghĩa là không thể tạo đối tượng từ class này.
cú pháp:
``cpp
#include <iostream>
using namespace std;

class cha{
    public:
        virtual void display() = 0; // Hàm ảo thuần túy
};

class con : public cha{
    public:
        void display() override{   // Ghi đè hàm ảo thuần túy
            cout << "display from class con" << endl;
        }
};

int main(){
    // cha ptr; // wrong
    cha *ptr;
    con obj;

    ptr = &obj;
    ptr->display();

    return 0;
}
```
ví dụ:
```cpp 
#include <iostream>
#include <string>

using namespace std;

class Xe{
    public:
        virtual void hienThiThongTin() = 0;
};

class Toyota : public Xe{
    private:
        string model;
        int namSanXuat;
        string dongCo;

    public:
        Toyota(string m, int nam, string dongCo): model(m), namSanXuat(nam), dongCo(dongCo){}

        void hienThiThongTin() override {
            cout << "Hang xe: Toyota\n";
            cout << "Model: " << model << "\n";
            cout << "Nam san xuat: " << namSanXuat << "\n";
            cout << "Dong co: " << dongCo << "\n";
        }
};

class Honda : public Xe{
    private:
        string model;
        int namSanXuat;
        string mauSac;

    public:
        Honda(string m, int nam, string mau): model(m), namSanXuat(nam), mauSac(mau){}

        void hienThiThongTin() override {
            cout << "Hang xe: Honda\n";
            cout << "Model: " << model << "\n";
            cout << "Nam san xuat: " << namSanXuat << "\n";
            cout << "Mau sac: " << mauSac << "\n";
        }
};

class Mazda : public Xe{
    private:
        string model;
        int namSanXuat;
        string loaiDanDong;

    public:
        Mazda(string m, int nam, string loaiDanDong): model(m), namSanXuat(nam), loaiDanDong(loaiDanDong){}

        void hienThiThongTin() override {
            cout << "Hang xe: Mazda\n";
            cout << "Model: " << model << "\n";
            cout << "Nam san xuat: " << namSanXuat << "\n";
            cout << "Loai dan dong: " << loaiDanDong << "\n";
        }
};

int main() {
    // Toyota to;
    // Honda ho;
    // Mazda mz;
    // Xe *xe;

    // xe = &to;
    // xe->hienThiThongTin();
   
    Mazda cx3("CX-3", 2019, "Dan dong 4 banh");

    Xe *ptr[] = {new Toyota("campry", 2020, "V6"),
                 new Honda("civic", 2019, "do"),
                 new Mazda("CX-5", 2021, "Dan dong 4 banh"),
                 new Toyota("corolla", 2018, "I4 1.8L"),
                 new Honda("accord", 2020, "den"),
                 &cx3};
   
    for (int i=0; i<6; i++){
        ptr[i]->hienThiThongTin();
        cout << "--------------" << endl;
        delete ptr[i];
    }

    return 0;
}
``` 
## Đa kế thừa
- Đa kế thừa trong C++ cho phép một class kế thừa từ nhiều class khác.
- Đa kế thừa thường dùng để kết hợp các chức năng từ nhiều class.
```cpp 
#include <iostream>

using namespace std;

class Sensor{
    public:
        void initialize(){
            cout << "Initializing sensor" << endl;
            // code khởi tạo cảm biến
        }

        int readData(){
            cout << "Reading sensor data" << endl;
            // code đọc dữ liệu cảm biến
            return 30;
        }
};

class Communication{
    public:
        void setupCommunication() {
            cout << "Setting up communication protocol" << endl;
            // code thiết lập giao thức truyền thông (SPI, I2C, UART,...)
        }

        void sendData(int data) {
            cout << "Sending data: " << data << endl;
            // code gửi dữ liệu qua các giao thức
        }
};

class Control : public Sensor, public Communication{
    public:
        Control(){
            setupCommunication();

            initialize();

            int data = readData();

            sendData(data);
        }
};

int main(int argc, char const *argv[])
{
    Control sensorControl;
    return 0;
}
```
- Khi nhiều lớp cha có các phương thức hoặc thuộc tính trùng tên, việc gọi chúng từ lớp con có thể gây ra sự nhầm lẫn.
- Khi một lớp con kế thừa từ hai lớp cha, mà hai lớp cha này đều cùng kế thừa từ cùng một lớp khác. Tình huống này tạo ra cấu trúc hình thoi (diamond), do đó được gọi là vấn đề "Diamond".
```cpp 
#include <iostream>

using namespace std;

class A{
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : public A{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    // d.hienThiA(); // wrong

    // Gọi phương thức từ lớp A qua B và C
    d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B
    d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    // d.hienThiB();
    // d.hienThiC();
    // d.hienThiD();

    return 0;
}
``` 

## Kế thừa ảo
- Kế thừa ảo giúp tránh vấn đề diamond problem trong đa kế thừa.
- Chỉ có một bản sao duy nhất của lớp cơ sở chung được kế thừa.
- Kế thừa ảo giúp quản lý các lớp liên quan đến phần cứng và giao tiếp. Điều này giúp tránh trùng lặp tài nguyên và quản lý hiệu quả trong hệ thống nhúng.
```cpp 
#include <iostream>

using namespace std;

class A {
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : virtual public A{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : virtual public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    d.hienThiA();

    // Gọi phương thức từ lớp A qua B và C
    // d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B
    // d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    // d.hienThiB();
    // d.hienThiC();
    // d.hienThiD();

    return 0;
}
``` 

# Generic Programming
## Function template
Trong C++, function templates là một tính năng mạnh mẽ giúp viết các function hoặc class chung có thể được sử dụng cho nhiều kiểu dữ liệu khác nhau mà không cần phải triển khai nhiều phiên bản của cùng một function hoặc class. 
```cpp
template <typename T>
T myFunction(T a, T b) {
    return a + b;
}
int result1 = myFunction(5, 10);       // Tự động suy luận T là int
double result2 = myFunction(3.14, 2.71);  // Tự động suy luận T là double
```
## Class template
Class templates trong C++ là một khái niệm tương tự như function templates, nhưng được áp dụng cho class thay vì function. Class templates cho phép bạn viết một lớp chung mà có thể được sử dụng với nhiều kiểu dữ liệu khác nhau.
```
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class MyContainer {
private:
    T element;
public:
    MyContainer(T val) : element(val) {}

    T getValue() const {
        return element;
    }
};

int main()
{
    MyContainer<int> intContainer(42);
    MyContainer<double> doubleContainer(3.14);
    MyContainer<string> stringContainer("Trung");

    int intValue = intContainer.getValue();
    double doubleValue = doubleContainer.getValue();
    string stringValue = stringContainer.getValue();

    cout << "int value: " << intValue << endl;
    cout << "double value: " << doubleValue << endl;
    cout << "string value: " << stringValue << endl;

    return 0;
}
```
## Advanced template techniques
### Metaprogramming
Mục đích: Tính toán giai thừa tại thời điểm biên dịch.
```cpp
#include <iostream>
using namespace std;

template <unsigned int n>
struct Factorial {
 enum 
{ 
value = n * Factorial<n - 1>::value 
};
};
template <>
struct Factorial<0> {
 enum { value = 1 };
};
int main() {
 cout << "Factorial of 5 is " << Factorial<5>::value << endl;
 return 0;
}
```
### Expression Templates
Mục đích:Thực hiện một phép cộng đơn giản giữa hai số nguyên
ví dụ: Thực hiện một phép cộng đơn giản giữa hai số nguyên
```cpp 
#include <iostream>
using namespace std;

template <typename A, typename B>
class AddExpr {
private:
	const A& a;
	const B& b;

public:
	AddExpr(const A& a, const B& b) : a(a), b(b) {}
	int eval() const {
		return a + b;
	}
};
template <typename A, typename B>
AddExpr<A, B> add(const A& a, const B& b) {
	return AddExpr<A, B>(a, b);
}

int main() {
	int x = 5,	y = 3;
	auto expr = add(x, y);
	cout << "Result: " << expr.eval() << endl; // Output: 8
	return 0;
}
```
### Variadic Templates
Mục đích: Tạo một hàm có thể chấp nhận số lượng tham số đầu vào không xác định.
```cpp 
#include <iostream>
using namespace std;

void print1()
{
    cout << endl;
}

template<typename T, typename... Rest>
void print1(T first, Rest... rest) {
    cout << first << endl;
    print1(rest...);
}
template <typename... Args>
void print(Args... args) {
 (cout << ... << args) << '\n';
}
int main() {
 print(1, 2, 3, "hello", 4.5, "Trung", 55);
 return 0;
}
```
# Namespace
Khái niệm: Namespace là cách nhóm các định danh như tên biến, hàm, class,... vào một không gian tách biệt.
Namespace được sử dụng để tránh xung đột tên khi có các định danh giống nhau được khai báo trong các phần của chương trình hoặc các thư viện khác nhau.
```cpp
#include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";

    void display(){
        cout << "Name: " << name << endl;
    }
}

namespace B{
    char *name = (char*)"Trung 21";

    void display(){
        cout << "Name: " << name << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;

    A::display();
    B::display();
    return 0;
}
```
## Từ khóa using trong Namespace
Từ khóa using cho phép bạn sử dụng các phần tử trong namespace mà không cần phải sử dụng toán tử '::' mỗi khi truy cập.
Chỉ sử dụng ***using namespace*** khi member muốn truy cập đến là duy nhất.
```cpp
#include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";
}

namespace B{
    char *name = (char*)"Trung 21";
}

using namespace A;

// using namespace B; // error: tham chiếu không rõ ràng

int main(int argc, char const *argv[])
{
    cout << "Name: " << name << endl;
    cout << "Name: " << B::name << endl;
    return 0;
}
```
## Namespace lồng nhau
C++ cho phép tạo các namespace lồng nhau, nghĩa là một namespace có thể chứa một namespace khác bên trong nó.
```cpp 
#include <iostream>
using namespace std;

namespace A{
    char *name = (char*)"Trung 20";

    namespace C{
        char *str = (char*)"Nguyen Hoang";
    }
}

namespace B{
    char *name = (char*)"Trung 21";
}

using namespace A::C;

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;
    cout << "Name: " << A::C::str << endl;

    str = (char*)"Hello World";
    cout << "Name: " << str << endl;
    return 0;
}
```
## Namespace mở rộng
Namespace có thể được mở rộng bằng cách khai báo nhiều lần cùng một tên namespace trong các phần khác nhau của chương trình. Các khai báo này sẽ được ghép lại thành một namespace duy nhất.
ví dụ:
file lcd1.hpp
```cpp
#ifndef _LCD1_HPP
#define _LCD1_HPP

namespace LCD{
    int temp;
    class lcd{
        public:
            lcd(/* args */);
            ~lcd();
    };
    lcd::lcd(){}
    lcd::~lcd(){}
}
#endif
```
file lcd2.hpp
```cpp
#ifndef _LCD2_HPP
#define _LCD2_HPP

namespace LCD{
    char *text;
}
#endif
```

file lcd.cpp
```cpp 
#include <iostream>
#include "lcd1.hpp"
#include "lcd2.hpp"

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";
}

namespace A{
    namespace C{
        char *str = (char*)"Nguyen Hoang";
    }
}

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << A::C::str << endl;

    LCD::lcd;
    LCD::temp;
    LCD::text;
    return 0;
}
``` 
## Namespace trong C++ tiêu chuẩn (std)
Một trong những namespace quan trọng và phổ biến nhất trong C++ là std. Tất cả các thành phần của thư viện chuẩn C++ (như cout, cin, vector, string) đều được định nghĩa bên trong namespace std.
ví dụ:
```cpp 
#include <iostream>
using namespace std;

namespace std{
    struct{
        int x;
        int y;
    } point;

    void display(){
        cout << "x = " << point.x << endl;
        cout << "y = " << point.y << endl;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "Hello world!" << std::endl;

    cout << "Hello world!" << endl;
   
    std::point.x = 10;
    std::point.y = 20;
    std::display();

    return 0;
}
``` 

# Standard template library (STL)
## Overview
Standard Template Library ( STL) là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến. STL đã trở thành một phần quan trọng của ngôn ngữ C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.

Một số thành phần chính của STL:
- Container
- Iterator
- Algorithms
- Functor
## Container
Một container là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể. STL (Standard Template Library) cung cấp một số container tiêu biểu giúp lưu trữ và quản lý dữ liệu. 
- Container được học:
	- Vector
	- List
	- Map
	- Array
### Vector
Vector là một trong những container quan trọng nhất trong STL của C++. Nó cung cấp một mảng động với khả năng thay đổi kích thước một cách linh hoạt. 
- Một số đặc điểm chính của vector:
	- vector là một mảng động, tức là có khả năng thay đổi kích thước một cách linh hoạt.
	- Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.
	- Hiệu suất chèn và xóa: Chèn và xóa phần tử ở cuối vector có hiệu suất tốt. Tuy nhiên, chèn và xóa ở vị trí bất kỳ có thể đòi hỏi di chuyển một số phần tử.
- Một số method của vector:
	- at(): Truy cập vào phần tử của vector
	- size(): Trả về kích thước của vector
	- resize(): Thay đổi kích thước của vector
	- begin(): Địa chỉ của phần tử đầu tiên của vector
	- end(): Địa chỉ của phần tử cuối cùng của vector
	- push_back(): Thêm phần tử vào vị trí cuối của vector
 ví dụ:
```cpp 
#include <iostream>
#include <vector>

using namespace std;


int main()
{
  
    vector <int> arr1 = {2,5,7,4,9};

    arr1.at(0) = 3;
    arr1.resize(7);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    
    arr1.push_back(10);

    cout << "-----------" << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    return 0;
}
```
**- Sử dụng vector khi:
	- Cần truy cập ngẫu nhiên đến các phần tử.
	- Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách.
	- Dung lượng có thể biết trước hoặc thay đổi ít.**
### List
List là một container trong STL của C++, triển khai dưới dạng danh sách liên kết hai chiều. Dưới đây là một số đặc điểm quan trọng của list:
- Truy cập tuần tự: Truy cập các phần tử của list chỉ có thể thực hiện tuần tự, không hỗ trợ truy cập ngẫu nhiên.
- Hiệu suất chèn và xóa: Chèn và xóa ở bất kỳ vị trí nào trong danh sách có hiệu suất tốt hơn so với vector. Điều này đặc biệt đúng khi thêm/xóa ở giữa danh sách.
Một số method của list:
- push_back():
- pop_back():
- insert(): Chèn một node vào list
- erase(): Xóa một node của list
- size(): Trả về kích thước của list
ví dụ:
```cpp 
#include <iostream>
#include <list>

using namespace std;
int main()
{  
    list <int> arr1 = {2,5,7,4,9};
    list <int> :: iterator it;

    int i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
    {
        if (i == 2)
        {
            arr1.insert(it,10);
            break;
        }
        i++;
    }

    i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
    {
        if (i == 4)
        {
            arr1.erase(it);
            break;
        }
        i++;
    }
    for (auto const var : arr1)
    {
        cout << "Value: " << var << endl;
    }
    return 0;
}
```
**- Sử dụng list khi:
	- Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
	- Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.
	- Dung lượng không quan trọng hoặc thay đổi thường xuyên.**

 **sử dung:**  
- Sử dụng vector khi:
	- Cần truy cập ngẫu nhiên đến các phần tử.
	- Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách.
	- Dung lượng có thể biết trước hoặc thay đổi ít.
- Sử dụng list khi:
	- Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
	- Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.
	- Dung lượng không quan trọng hoặc thay đổi thường xuyên.
**Tùy thuộc vào yêu cầu cụ thể của vấn đề, bạn có thể chọn sử dụng std::vector hoặc std::list.**
### Map
Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value
- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử của map
ví dụ:
```cpp
#include <map>
#include <iostream>
#include <string>

using namespace std;
int main() {
    map<string, int> myMap;

    map<string,int> ::iterator it;

    // Thêm phần tử vào map
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;
    myMap.insert(make_pair("four", 4));
    myMap.erase("one");
    for (auto const var : myMap)
    {
        cout << "Key: " << var.first << " , " << "Value: " << var.second << endl;
    }
    for (it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << "Key: " << (*it).first << " , " << "Value: " << (*it).second << endl;
    }
    return 0;
}
```
### Array
Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)
- array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []
ví dụ:
```cpp
#include <iostream>
#include <array>

using namespace std;
int main()
{
    array <int, 5> arr = {2,3,1,7,6};

    if (arr.empty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        cout << "Array it not empty" << endl;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Value: " << arr.at(i) << endl;
    }
    return 0;
}
```
## Iterator
Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.
## Algorithm
Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 
ví dụ:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{

    vector <int> arr = {3,5,7,4,1};

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end());
    
    cout << "vector after sort ascending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << "vector after sort descending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }
    return 0;
}
```
ví dụ 2:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
  
    vector <int> arr1 = {2,5,7,4,9};
    
    auto it = find(arr1.begin(), arr1.end(), 3);
    
    if (it != arr1.end())
    {
        cout << "Da tim thay" << endl;
    }
    else
    {
        cout << "Khong tim thay" << endl;
    }
    
    return 0;
}
```
# Design Patterns
Design Patterns là các giải pháp tổng quát cho các vấn đề phổ biến trong phát triển phần mềm. Chúng là một dạng "công thức" giúp các lập trình viên xử lý các tình huống thường gặp trong quá trình thiết kế.
-Design Patterns thường được chia thành các loại sau:
	- Creational Patterns (Mẫu khởi tạo): Quản lý việc khởi tạo đối tượng (VD: **Singleton, Factory**).
	- Structural Patterns (Mẫu cấu trúc): Tổ chức cấu trúc của các lớp và đối tượng (VD: **Decorator**, Adapter, Composite).
	- Behavioral Patterns (Mẫu hành vi): Xác định cách các đối tượng tương tác với nhau (VD: **Observer, MVP,** Strategy).
## Singleton Factory
- Singleton là một mẫu thiết kế thuộc nhóm Creational (mẫu khởi tạo), nó đảm bảo rằng một lớp chỉ có một đối tượng duy nhất được tạo ra, và cung cấp một phương thức để truy cập đến đối tượng đó từ bất kỳ đâu trong chương trình.
- Singleton thường sử dụng cho những hệ thống chỉ cần một phiên bản duy nhất như: kết nối cơ sở dữ liệu, bộ nhớ đệm (cache), logger để ghi log, hoặc cấu hình hệ thống.
Đặc điểm chính của Singleton:
-  Private Constructor: Đảm bảo rằng không ai có thể khởi tạo đối tượng từ bên ngoài lớp.
- Static Instance: Đây là đối tượng tĩnh duy nhất của lớp đó. Không thể tạo ra nhiều hơn một đối tượng của lớp Singleton.
- Static Method: Phương thức để truy cập đến đối tượng Singleton duy nhất từ mọi nơi trong chương trình.
ví dụ:
```cpp 
#include <iostream>

void gpioInit();

void gpioSetPin(int pin, bool value);

void gpioReadPin(int pin);

class GpioManager{
    private:
        GpioManager();
        static GpioManager* instance;
        void init(){
            gpioInit();
        }
    public:
        static GpioManager *getInstace(){
            if(!instance){
                instance = new GpioManager(); // 0xc8
                instance->init();
                // bổ sung thêm tính năng
            }
            return instance;
        }
        void setPin(int pin, bool value){
            gpioSetPin(pin, value);
        }
        void readPin(int pin){
            gpioReadPin(pin);
        }
};

class PORTx{
    private:
        PORTx();
        static PORTx* instance;
        void init(){
            //gpioInit();
        }
    public:
        static PORTx *getInstace(){
            if(!instance){
                instance = new PORTx();
                instance->init();
            }
            return instance;
        }
};

GpioManager* GpioManager::instance = nullptr; // 0xc8 : địa chỉ cố định

int main(int argc, char const *argv[])
{
    GpioManager* gpioManager = GpioManager::getInstace();

    gpioManager->setPin();

    gpioManager->readPin();

    GpioManager* gpioManager2 = GpioManager::getInstace();

    return 0;
}
```
ví dụ 2 stm32f10x.h:
```cpp
#include <iostream>
#include "stm32f10x.h"  

class UART{
    private:
        static UART* instance;  
        UART(){
            initUART();
        }

        void initUART(){
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
            USART_InitTypeDef USART_InitStructure;

            USART_InitStructure.USART_BaudRate = 9600;
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

            USART_Init(USART1, &USART_InitStructure);
            USART_Cmd(USART1, ENABLE);
        }

    public:
        static UART* getInstance(){
            if (instance == nullptr){
                instance = new UART();  // Tạo instance nếu chưa có
            }
            return instance;
        }

        void sendData(uint8_t data){
            while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
            USART_SendData(USART1, data);
        }

        uint8_t receiveData(){
            while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
            return USART_ReceiveData(USART1);
        }
};

UART* UART::instance = nullptr;

int main()
{
    UART* uart = UART::getInstance();

    // Gửi một ký tự qua UART
    uart->sendData('H');

    // Nhận một ký tự từ UART
    uint8_t received = uart->receiveData();

    while (1) {
        // Thực hiện công việc liên quan khác
    }
}
```
## Observer Pattern
Observer là một mẫu thiết kế thuộc nhóm Behavioral (mẫu hành vi), nó định nghĩa một mối quan hệ phụ thuộc one-to-many giữa các đối tượng, nghĩa là khi một đối tượng thay đổi trạng thái, tất cả các đối tượng phụ thuộc vào nó sẽ được tự động thông báo và cập nhật.
- Subject: đối tượng chịu trách nhiệm quản lý và thông báo các thay đổi.
- Observer: đối tượng sẽ đăng ký theo dõi Subject.
Đặc điểm chính của Observer Pattern:
1. Mối quan hệ giữa Subject và Observer:
Subject giữ một danh sách các Observer. Các Observer đăng ký nhận thông báo từ Subject khi có sự thay đổi trạng thái. Observer có thể thêm, xóa hoặc cập nhật trong danh sách này.
2. Tự động thông báo (Push Notification):
Khi trạng thái của Subject thay đổi, nó sẽ tự động thông báo cho tất cả các Observer đã đăng ký. Các Observer không cần chủ động kiểm tra trạng thái của Subject mà sẽ nhận thông báo ngay khi có thay đổi.
3. Tính linh hoạt và mở rộng:
Observer Pattern cho phép dễ dàng thêm hoặc xóa các Observer mà không cần thay đổi Subject hoặc Observer có thể dễ dàng ngừng nhận thông báo từ Subject bằng cách hủy đăng ký, giúp kiểm soát tốt hơn việc quản lý tài nguyên và sự kiện trong hệ thống.
4. Giảm sự phụ thuộc chặt chẽ:
Subject không cần biết chính xác về các Observer mà nó quản lý, chỉ cần biết rằng chúng tuân theo một giao diện chung để nhận thông báo. Điều này giúp giảm sự phụ thuộc chặt chẽ giữa các đối tượng và làm cho mã dễ bảo trì hơn.
5. Nhiều Observer có thể theo dõi một hoặc nhiều Subject:
* Nhiều Observer có thể cùng theo dõi một Subject. Điều này cho phép cùng một sự kiện trong Subject có thể ảnh hưởng đến nhiều đối tượng khác nhau.
* Một Observer có thể đăng ký để nhận thông báo từ nhiều Subject khác nhau, và mỗi Subject sẽ thông báo cho Observer khi có sự thay đổi liên quan.
ví dụ:
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Interface for observers (display, logger, etc.)
class Observer {
public:
    virtual void update(float temperature, float humidity, float light) = 0;
};

// Subject (SensorManager) holds the state and notifies observers
class SensorManager {
    float temperature;
    float humidity;
    float light;
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(temperature, humidity, light);
        }
    }

    void setMeasurements(float temp, float hum, float lightLvl) {
        temperature = temp;
        humidity = hum;
        light = lightLvl;
        notifyObservers();
    }
};

// Display component (an observer)
class Display : public Observer {
public:
    void update(float temperature, float humidity, float light) override {
        std::cout << "Display: Temperature: " << temperature
                  << ", Humidity: " << humidity
                  << ", Light: " << light << std::endl;
    }
};

// Logger component (an observer)
class Logger : public Observer {
public:
    void update(float temperature, float humidity, float light) override {
        std::cout << "Logging data... Temp: " << temperature
                  << ", Humidity: " << humidity
                  << ", Light: " << light << std::endl;
    }
};

int main() {
    SensorManager sensorManager;

    Display display;
    Logger logger;

    sensorManager.registerObserver(&display);
    sensorManager.registerObserver(&logger);

    sensorManager.setMeasurements(25.0, 60.0, 700.0); // Simulate sensor data update
    sensorManager.setMeasurements(26.0, 65.0, 800.0); // Another sensor update

    return 0;
}
```
## Factory Pattern
Factory Pattern là một mẫu thiết kế (design pattern) thuộc nhóm creational patterns, cung cấp một cơ chế để tạo ra các đối tượng mà không cần chỉ rõ lớp cụ thể của các đối tượng đó. Thay vì khởi tạo trực tiếp các đối tượng, Factory Pattern sử dụng một phương thức hoặc một lớp trung gian (Factory) để quyết định loại đối tượng nào sẽ được khởi tạo dựa trên tham số đầu vào hoặc logic cụ thể.
- Đặc điểm của Factory Pattern:
	+ **Tính trừu tượng:** Factory Pattern ẩn đi chi tiết về cách các đối tượng được tạo ra, giúp chương trình tách biệt giữa việc khởi tạo đối tượng và việc sử dụng đối tượng đó.
	+ **Tính mở rộng:** Factory Pattern giúp hệ thống dễ dàng mở rộng khi cần thêm các lớp con mới mà không làm ảnh hưởng đến mã nguồn hiện có.
	+ **Tính linh hoạt:** Khi hệ thống cần thay đổi hoặc thêm mới các đối tượng cụ thể, chúng ta chỉ cần cập nhật factory mà không cần sửa đổi mã nguồn chính.
	+ **Giảm sự phụ thuộc:** Factory Pattern giúp mã nguồn giảm sự phụ thuộc vào các lớp cụ thể, từ đó tăng tính module và khả năng tái sử dụng.
ví dụ:
```cpp 
#include <iostream>
#include <string>

using namespace std;

// Abstract class
class Sensor{
    public:
        virtual void readData() = 0;
};

// Temperature class
class TemperatureSensor : public Sensor{
    public:
        void readData() override {
            cout<<"reading temp data: "<<endl;
        }
};

// Humidity class
class HumiditySensor : public Sensor{
    public:
        void readData() override {
            cout<<"reading humidity data: "<<endl;
        }
};

// Factory class (Creator)
class SensorFactory{
    public:
        static Sensor* createSensor(const string& sensorType){
            if(sensorType == "temp"){
                return new TemperatureSensor();     // trả về đối tượng TemperatureSensor
            }
            else if (sensorType == "humi"){
                return new HumiditySensor();        // trả về đối tượng PressureSensor
            }
            else{
                return nullptr;                     // trả về con trỏ null
            }
        }
};
int main(int argc, char const *argv[])
{
    Sensor* sensor = SensorFactory::createSensor("humi");
    sensor->readData();
    return 0;
}
```
## Decorator Pattern
Khi làm việc với thiết bị ngoại vi, ví dụ như cảm biến nhiệt độ, đôi khi bạn sẽ cần thêm tính năng mới vào cảm biến này mà không muốn thay đổi mã nguồn gốc hoặc cấu trúc của nó. Chẳng hạn, cảm biến nhiệt độ ban đầu chỉ trả về giá trị nhiệt độ, nhưng bạn lại muốn:
- Ghi lại dữ liệu nhiệt độ vào log để có thể xem lại sau này.
- Kiểm tra xem nhiệt độ có vượt ngưỡng an toàn không.
- Hiệu chỉnh nhiệt độ nếu cảm biến không chính xác hoàn toàn.
Một cách phổ biến để thêm tính năng là tạo các lớp con kế thừa từ lớp cảm biến gốc, sau đó viết lại hoặc thêm tính năng mới vào từng lớp con. Tuy nhiên, nếu làm vậy, bạn sẽ phải tạo rất nhiều lớp kế thừa khác nhau, dẫn đến mã nguồn phức tạp, khó kiểm soát và bảo trì.

	 Decorator Pattern là một mẫu thiết kế thuộc nhóm **structural patterns**, cho phép thêm các chức năng hoặc hành vi mới cho một đối tượng mà không cần thay đổi cấu trúc của lớp đối tượng đó. Mẫu này giúp mở rộng tính năng của các đối tượng bằng cách bao bọc (wrapping) chúng trong các lớp decorator đặc biệt.
- Đặc điểm của Decorator Pattern:
	+ Tính linh hoạt: Decorator Pattern cho phép thêm hành vi mới vào đối tượng một cách linh hoạt mà không làm thay đổi các đối tượng khác.
	+ Tính mở rộng: Decorator Pattern cho phép mở rộng tính năng mà không cần thay đổi mã gốc.
	+ Dễ bảo trì: Bạn có thể dễ dàng bổ sung hoặc thay thế các tính năng bằng cách thay đổi các decorator mà không ảnh hưởng đến các lớp khác.
	+ Giảm sự phức tạp của kế thừa: Thay vì tạo ra nhiều lớp con để mở rộng hành vi, Decorator Pattern cho phép kết hợp các hành vi một cách linh hoạt bằng cách xếp chồng các decorator.
ví dụ:
```cpp 
#include <iostream>

using namespace std;

class Sensor{
    public:
        virtual void readData() = 0;
};

// Cảm biến nhiệt độ
class TemperatureSensor : public Sensor{
    public:
        void readData() override {
            cout<<"reading temperature data: "<<endl;
        }
};

// Cảm biến độ ẩm
class HumiditySensor : public Sensor{
    public:
        void readData() override {
            cout<<"reading humidity data: "<<endl;
        }
};

// Decorator Pattern
class SensorDecorator : public Sensor{
    protected:
        Sensor* wrappedSensor;

    public:
        SensorDecorator(Sensor* sensor) : wrappedSensor(sensor){}

        virtual void readData() override {
            wrappedSensor->readData();
        }
};

// Thêm tính năng Log
class LoggingSensor : public SensorDecorator{
    public:
        LoggingSensor(Sensor* sensor) : SensorDecorator(sensor){}

        void readData() override{
            cout<<"LOG: sensor data"<<endl;
            SensorDecorator::readData();
        }
};
int main(int argc, char const *argv[])
{
    Sensor* tempSensor = new TemperatureSensor();
    Sensor* log = new LoggingSensor(tempSensor);
    log->readData();
    return 0;
}
```
## MVP Pattern
**MVP (Model - View - Presenter)** là một mẫu thiết kế thuộc nhóm Behavioral, phổ biến trong lập trình giao diện người dùng (UI) và phát triển ứng dụng. MVP tách biệt các thành phần của ứng dụng thành ba phần chính: Model, View, và Presenter. Cấu trúc này giúp dễ dàng quản lý, kiểm thử, và bảo trì mã nguồn.
- **Model:** Chứa logic liên quan đến dữ liệu của ứng dụng, bao gồm các đối tượng, cơ sở dữ liệu, và giao tiếp với các API khác.
- **View:** Hiển thị giao diện (Interface) và nhận tương tác từ người dùng (như nhập liệu, bấm nút). 
- **Presenter:** Là cầu nối giữa Model và View, chịu trách nhiệm xử lý logic, điều phối dữ liệu từ Model đến View và ngược lại.
Đặc điểm của MVP Pattern:
- Tách biệt logic và giao diện: Presenter chứa logic của ứng dụng, giúp View chỉ tập trung vào hiển thị.
- Presenter không biết đến giao diện cụ thể: Presenter chỉ tương tác với View thông qua một interface, giúp việc kiểm thử và thay đổi giao diện trở nên dễ dàng.
- Thích hợp cho ứng dụng có giao diện phức tạp: MVP rất hữu ích khi giao diện cần tương tác với nhiều dữ liệu và các thành phần phức tạp.

**Luồng hoạt động của MVP Pattern:**
1. Người dùng tương tác với giao diện người dùng (View).
2. View chuyển sự kiện này cho Presenter.
3. Presenter xử lý yêu cầu bằng cách lấy dữ liệu từ Model.
4. Model xử lý dữ liệu và trả về kết quả cho Presenter.
5. Presenter tiếp tục cập nhật View với dữ liệu đã xử lý từ Model.
ví dụ
```cpp
#include <iostream>
#include <string>

using namespace std;

class SinhVienModel{
    private:
        string name;
        int age;
        string studentId;

    public:
        SinhVienModel(const string& name, int age, const string& studentId): name(name), age(age), studentId(studentId){}

        // setter method
        void setName(const string& newName){
            name = newName;
        }

        void setAge(int newAge){
            age = newAge;
        }

        void setStudentId(const string& newStudentId){
            studentId = newStudentId;
        }

        // getter method
        string getName() const{
            return name;
        }

        int getAge() const{
            return age;
        }

        string getStudentId() const{
            return studentId;
        }
};
class SinhVienView{
    public:
        void displayStudentInfo(const string& name, int age, const string& studentId){
            cout << "Thông tin sinh viên:" << endl;
            cout << "Tên: " << name << endl;
            cout << "Tuổi: " << age << endl;
            cout << "Mã số sinh viên: " << studentId << endl;
        }

        void inputStudentInfo(string& name, int& age, string& studentId){
            cout << "Nhập thông tin sinh viên:" << endl;

            cout << "Tên: ";
            getline(cin, name);

            cout << "Tuổi: ";
            cin >> age;
            cin.ignore();  // Bỏ qua ký tự newline trong buffer

            cout << "Mã số sinh viên: ";
            getline(cin, studentId);
        }
};

class SinhVienPresenter{
    private:
        SinhVienModel& model;
        SinhVienView&  view;

    public:
        SinhVienPresenter(SinhVienModel& m, SinhVienView& v): model(m), view(v){}

        void updateStudentInfo(){
            string name;
            int age;
            string studentId;
           
            view.inputStudentInfo(name, age, studentId);
            model.setName(name);
            model.setAge(age);
            model.setStudentId(studentId);
        }

        void showStudentInfo(){
            view.displayStudentInfo(model.getName(), model.getAge(), model.getStudentId());
        }
};

int main()
{
    // Tạo model, view và presenter
    SinhVienModel model("Tuấn", 20, "HTN123");
    SinhVienView view;
    SinhVienPresenter presenter(model, view);

    int choice;
    do{
        cout << "\n1. Hiển thị thông tin sinh viên" << std::endl;
        cout << "2. Cập nhật thông tin sinh viên" << std::endl;
        cout << "3. Thoát" << std::endl;
        cout << "Nhập lựa chọn: ";
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự newline trong buffer
       
        switch (choice){
            case 1:
                presenter.showStudentInfo();
                break;
               
            case 2:
                presenter.updateStudentInfo();
                break;

            case 3:
                cout << "Thoát chương trình." << endl;
                break;

            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }
       
    } while (choice != 3);

    return 0;
}
```
ví dụ 2:
```cpp 
#include <iostream>

using namespace std;

class ClimateControlModel{
    private:
        int temperature;    // Nhiệt độ hiện tại trong xe
        bool isAirOn;       // Trạng thái của điều hòa (bật/tắt)

    public:
        ClimateControlModel(int temp = 24, bool air = true): temperature(temp), isAirOn(air){}

        int getTemperature() const{
            return temperature;
        }

        bool getAirStatus() const{
            return isAirOn;
        }

        void setTemperature(int newTemperature){
            temperature = newTemperature;
        }

        void setAirStatus(bool status){
            isAirOn = status;
        }
};

class ClimateControlView{
    public:
        void displayCurrentSettings(int temperature, bool isAirOn){
            cout << "---- Thông tin điều hòa xe hơi ----" << endl;
            cout << "Nhiệt độ hiện tại: " << temperature << "°C" << endl;
            cout << "Trạng thái điều hòa: " << (isAirOn ? "Bật" : "Tắt") << endl;
        }

        int getUserTemperatureInput() {
            int temp;
            cout << "Nhập nhiệt độ mong muốn: ";
            cin >> temp;
            return temp;
        }

        bool getUserAirStatusInput() {
            int choice;
            cout << "Bật/Tắt điều hòa (1: Bật, 0: Tắt): ";
            cin >> choice;
            return (choice == 1);
        }
};

class ClimateControlPresenter{
    private:
        ClimateControlModel& model;
        ClimateControlView&  view;

    public:
        ClimateControlPresenter(ClimateControlModel& m, ClimateControlView& v): model(m), view(v){}

        void showCurrentSettings(){
            view.displayCurrentSettings(model.getTemperature(), model.getAirStatus());
        }

        void updateTemperature(){
            int newTemperature = view.getUserTemperatureInput();
            model.setTemperature(newTemperature);
        }

        void updateAirStatus(){
            bool newAirStatus = view.getUserAirStatusInput();
            model.setAirStatus(newAirStatus);
        }
};

int main()
{
    ClimateControlModel model;
    ClimateControlView view;
    ClimateControlPresenter presenter(model, view);

    int choice;
    do{
        cout << "\n1. Hiển thị thông tin điều hòa" << endl;
        cout << "2. Điều chỉnh nhiệt độ" << endl;
        cout << "3. Bật/Tắt điều hòa" << endl;
        cout << "4. Thoát" << endl;
        cout << "Nhập lựa chọn: ";
        cin >> choice;

        switch (choice){
            case 1:
                presenter.showCurrentSettings();
                break;

            case 2:
                presenter.updateTemperature();
                break;

            case 3:
                presenter.updateAirStatus();
                break;

            case 4:
                cout << "Thoát chương trình." << endl;
                break;

            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }

    } while (choice != 4);

    return 0;
}
```
# Multithreading
## 1. Process
Process (tiến trình) là một đơn vị thực thi độc lập, 1 chương trình đang chạy trên hệ thống, có không gian địa chỉ bộ nhớ riêng. Mỗi process chạy trong một không gian bộ nhớ tách biệt, và việc giao tiếp giữa các process thường khó khăn và yêu cầu các phương thức như IPC (Inter-Process Communication).
- Mỗi process có thể sử dụng những phần cứng bên dưới (bàn phím, chuột, ...).
- Mỗi tiến trình có thể bao gồm một hoặc nhiều luồng (thread) của việc thực hiện công việc.
## 2. Thread
### Khái niệm: 
- Thread là đơn vị nhỏ hơn của một process, còn được gọi là "luồng". Một process có thể chứa nhiều thread, và các thread này chia sẻ cùng không gian địa chỉ bộ nhớ của process đó.
- Các luồng trong cùng một tiến trình có thể chia sẻ cùng một không gian bộ nhớ và các tài nguyên khác của tiến trình, bao gồm cả biến toàn cục và biến cục bộ.
  ### Tạo và khởi chạy một thread
  ```cpp
  thread task1(test1, 1000);     // task1: đại diện cho luồng 1
  thread task2(test2, 3000);     // task2: đại diện cho luồng 2
```
task1, task2: là các object thuộc class thread. Mỗi object sẽ tương ứng với một luồng được tạo ra và mỗi một luồng sẽ thực thi một hàm hay tác vụ nào đó.
Tham số 1: địa chỉ hàm muốn thực thi trong luồng.
Tham số 2, 3, …: tham số truyền vào của hàm.
ví dụ:
```cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

void test1(uint32_t time){
    int i = 0;
    while (1){
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}

void test2(uint32_t time){
    int i = 0;
    while (1){
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    thread task1(test1, 1);     // t1: đại diện cho luồng 1
    thread task2(test2, 2);     // t2: đại diện cho luồng 2

    /* luồng chính giúp chương trình chạy liên tục */
    while(1){
        cout << "This is main\n";
        delay(1);
    }
    return 0;
}
```
### Quản lý thread

#### join()
```cpp
task1.join();
task2.join();
```
Phương thức join() được sử dụng để chờ cho một luồng kết thúc. Khi gọi join() trên một luồng, nó đảm bảo rằng luồng hiện tại sẽ không tiếp tục thực hiện cho đến khi luồng được join() hoàn tất. Điều này hữu ích khi bạn cần chắc chắn rằng một luồng đã hoàn thành công việc trước khi tiếp tục với luồng chính.
- Mỗi luồng chỉ có thể gọi **method join()** duy nhất 1 lần. Nếu gọi nhiều lần sẽ gây ra lỗi.
- Nếu một luồng đã **được join(),** nó không còn khả năng tham gia **(joinable)** nữa.
Ví dụ:
```cpp 
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

void test1(uint32_t time){
    int i = 0;
    for (int j = 0; j < 10; j++){
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}

void test2(uint32_t time){
    int i = 0;
    for (int j = 0; j < 10; j++){
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    thread task1(test1, 1);     // t1: đại diện cho luồng 1
    thread task2(test2, 2);     // t2: đại diện cho luồng 2

    task1.join();
    task2.join();

    /* luồng chính giúp chương trình chạy liên tục */
    while(1){
        cout << "This is main\n";
        delay(1);
    }
    return 0;
}
```
#### joinable()
Kiểm tra xem một thread đã kết thúc hoặc đã gọi **join()** hay chưa. Nếu chưa thì trả về **true,** khi này ta có thể bắt đầu khởi chạy thread. Ngược lại, nếu thread đã kết thúc rồi thì trả về **false.**
Ví dụ:
```cpp
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}
void test1(uint32_t time){
    int i = 0;
    for (int j = 0; j < 5; j++){
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}
void test2(uint32_t time){
    int i = 0;
    for (int j = 0; j < 5; j++){
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}
int main(int argc, char const *argv[])
{
    thread task1(test1, 1);     // t1: đại diện cho luồng 1
    thread task2(test2, 2);     // t2: đại diện cho luồng 2


    if (task1.joinable()){
        cout << "Thread 1 chưa kết thúc\n";
        task1.join();
    }
    else{
        cout << "Thread 1 đã kết thúc\n";
    }
   
    if (task2.joinable()){
        cout << "Thread 2 chưa kết thúc\n";
        task2.join();
    }
    else{
        cout << "Thread 2 đã kết thúc\n";
    }    
    /* luồng chính giúp chương trình chạy liên tục */
    while(1){
        cout << "This is main\n";
        delay(1);
    }
    return 0;
}
```
#### detach()
- Phương thức detach() tách luồng khỏi luồng chính và cho phép nó chạy độc lập. Khi một luồng được tách ra, luồng chính không chờ luồng đó kết thúc nữa.
- Sau khi gọi detach(), khi luồng chính kết thúc, những luồng khác cũng sẽ kết thúc theo.
- Không thể join() một luồng đã được detach(). Nếu một luồng đã được tách ra, nó không còn khả năng tham gia (joinable) nữa.
  Ví dụ 1:
  ```cpp
  #include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}
void test1(uint32_t time){
    int i = 0;
    for (int j = 0; j < 5; j++){
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}
void test2(uint32_t time){
    int i = 0;
    for (int j = 0; j < 5; j++){
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}
int main(int argc, char const *argv[])
{
    thread task1(test1, 1);     // t1: đại diện cho luồng 1
    thread task2(test2, 2);     // t2: đại diện cho luồng 2
    task1.detach();
    task2.detach();
    /* luồng chính giúp chương trình chạy liên tục */
    int i = 0;
    while(1){
        cout << "This is main, i = " << i++ << endl;
        delay(1);
    }
    return 0;
}
```
Ví dụ 2:
```cpp
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}


void test1(uint32_t time){
    int i = 0;
    for (int j = 0; j < 5; j++){
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}


void test2(uint32_t time){
    int i = 0;
    for (int j = 0; j < 5; j++){
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    thread task1(test1, 1);     // t1: đại diện cho luồng 1
    thread task2(test2, 2);     // t2: đại diện cho luồng 2

    task1.detach();
    task2.detach();

    /* luồng chính giúp chương trình chạy liên tục */
    int i = 0;
    for (i=0; i<3; i++){
        cout << "This is main, i = " << i++ << endl;
        delay(1);
    }

    return 0;
}
```
## 3. Thread Synchronization (Đồng bộ hóa các luồng)
### Mutex
**Mutex (Mutual Exclusion):** Là một đối tượng đồng bộ hóa cung cấp cơ chế để giới hạn truy cập tài nguyên chỉ cho một luồng tại một thời điểm. Khi một luồng khóa (lock) mutex, các luồng khác phải chờ cho đến khi mutex được mở khóa (unlock) mới có thể tiếp tục truy cập tài nguyên.
	**Trạng thái của mutex:** Một mutex có hai trạng thái chính:
- **Khóa (locked):** Khi một luồng đã chiếm giữ mutex.
- **Mở khóa (unlocked):** Khi không có luồng nào chiếm giữ mutex, các luồng khác có thể tiếp tục khóa nó.
**std::mutex** được định nghĩa trong **thư viện <mutex>.** Các phương thức cơ bản bao gồm:
- **lock():** Khóa mutex. Nếu mutex đã bị khóa bởi một luồng khác, luồng hiện tại sẽ bị chặn (block) cho đến khi mutex được mở khóa.
- **unlock():** Mở khóa mutex. Điều này cho phép các luồng khác có thể tiếp tục khóa mutex.
- **try_lock():** Thử khóa mutex. Nếu mutex chưa bị khóa, nó sẽ khóa mutex và trả về true. Nếu đã bị khóa bởi một luồng khác, nó sẽ không chặn luồng hiện tại mà trả về false.
  Ví dụ:
```cpp
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increment(int num_iterations) {
    for (int i = 0; i < num_iterations; ++i) {
        mtx.lock();     // Khóa mutex trước khi truy cập biến chia sẻ
        ++counter;      // Thao tác trên biến chia sẻ
        mtx.unlock();   // Mở khóa mutex sau khi truy cập
    }
}

int main() {
    const int num_iterations = 10;

    thread t1(increment, num_iterations);
    thread t2(increment, num_iterations);

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << endl;

    return 0;
}
```
#### std::lock_guard
  **std::lock_guard** là một lớp RAII (Resource Acquisition Is Initialization) tự động khóa mutex khi được tạo và tự động mở khóa khi đối tượng bị hủy (ra khỏi phạm vi).
  Ví dụ:
  ```cpp 
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}


void display(int id){
    while (1){
        lock_guard<mutex> lock(mtx);
        cout << "This is task display: " << id << endl;
        delay(1);
    }
}


int main(int argc, char const *argv[])
{
    thread t1(display, 1);
    thread t2(display, 2);
    thread t3(display, 3);

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
```
#### std::unique_lock
**std::unique_lock** tự động khóa mutex khi được tạo nhưng cung cấp tính linh hoạt hơn **std::lock_guard,** cho phép mở khóa thủ công hoặc tự động mở khóa khi ra khỏi phạm vi, hoặc thử khóa với thời gian chờ.
ví dụ 1:
```cpp 
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

bool lock_test = false;

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

void display(int id){
    while (1){
        unique_lock<mutex> lock(mtx);   
        cout << "This is task display: " << id << endl;
        delay(1);
        lock.unlock();
    }
}

int main(int argc, char const *argv[])
{
    thread t1(display, 1);
    thread t2(display, 2);
    thread t3(display, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
```
Ví dụ 2:
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

mutex mtx;

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

void display(int id){
    while (1){
        unique_lock<mutex> lock(mtx);   
        cout << "This is task display: " << id << endl;
        lock.unlock();
        delay(1);

        lock.lock();
        cout << "Mutex unlocked by thread: " << id << endl;
        lock.unlock();
        delay(2);
        
        lock.lock();
        cout << "Mutex locked again by thread: " << id << endl;
        delay(3);
    }
}

int main(int argc, char const *argv[])
{
    thread t1(display, 1);
    thread t2(display, 2);
    thread t3(display, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
```
#### Atomic operator
 Giả sử có một chương trình đo nhiệt độ từ cảm biến và cập nhật giá trị vào một biến **(biến toàn cục)** chia sẻ:
- **Luồng 1 (luồng đọc cảm biến):** Liên tục đọc dữ liệu từ cảm biến và cập nhật vào biến nhiệt độ.
- **Luồng 2 (luồng ghi dữ liệu):** Đọc giá trị từ biến nhiệt độ để thực hiện các thao tác khác, ví dụ như lưu vào file hoặc hiển thị trên giao diện.
  Nếu sử dụng **std::lock_guard** hoặc **std::unique_lock,** mỗi khi luồng đọc cảm biến muốn ghi giá trị mới vào biến nhiệt độ, nó sẽ phải khóa mutex, và khi luồng ghi muốn đọc giá trị từ biến, nó cũng phải khóa mutex. Khi cả hai luồng cần truy cập biến cùng lúc, sẽ xảy ra hiện tượng chờ đợi (blocking), làm chậm chương trình.
  Trong trường hợp này, việc sử dụng **std::atomic** có thể là giải pháp tốt hơn so với sử dụng **mutex. std::atomic** cho phép các thao tác đọc và ghi được thực hiện mà không bị gián đoạn,  đảm bảo an toàn khi truy cập dữ liệu chia sẻ mà không cần khóa mutex. Điều này giúp giảm thiểu độ trễ và cải thiện hiệu suất.
  **std::atomic** là một **struct template** trong C++ được thiết kế để thực hiện các thao tác trên các biến mà các thao tác này không thể bị gián đoạn bởi các luồng khác. Điều này giúp đảm bảo tính nhất quán của dữ liệu và tránh tình trạng xung đột khi nhiều luồng cùng truy cập và thay đổi dữ liệu chia sẻ.
  Các thao tác atomic:
- **Gán và đọc giá trị (store và load):** Ghi và đọc giá trị của biến atomic.
- **Tăng và giảm giá trị (++, --):** Tăng hoặc giảm giá trị của biến atomic.
- **Cộng và trừ giá trị (+=, -=):** Thực hiện phép cộng, trừ giá trị nguyên tử.
- **Đổi giá trị (exchange):** Đổi giá trị hiện tại với giá trị mới và trả về giá trị cũ.
  Ví dụ:
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>


using namespace std;

mutex mtx;
bool lock_test = false;

atomic<int> counter(0);

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

void display(int id){
    while (1){
        unique_lock<mutex> lock(mtx);   //lock_test = true;
        cout << "This is task display: " << id << endl;
        delay(1);
        lock.unlock();

        lock_guard<mutex> lock1(mtx);
        cout << "Counter: " << ++counter << endl;
        delay(1);
    }

}

/********************************************
 * atomic: dùng cho biến toàn cục
 * lock_guard, unique_lock: dùng cho ngoại vi
 *******************************************/

int main(int argc, char const *argv[])
{
    thread t1(display, 1);
    thread t2(display, 2);
    thread t3(display, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
```
Mỗi đối tượng **std::atomic<T>** chỉ bảo vệ một biến duy nhất thuộc kiểu T, chẳng hạn **std::atomic<int>, std::atomic<double>,  std::atomic<bool>, std::atomic<void*>,...** đảm bảo rằng các thao tác trên biến đó sẽ không bị gián đoạn và sẽ hoàn thành hoàn toàn trước khi bất kỳ luồng nào khác có thể thực hiện thao tác trên cùng biến đó.

	3.3. Condition variable
 Khi hai hoặc nhiều luồng cần giao tiếp và đồng bộ hóa với nhau, condition variable là một lựa chọn thích hợp trong C++. 
	**std::condition_variable** cho phép một luồng chờ cho đến khi một điều kiện cụ thể được đáp ứng, và một luồng khác có thể thông báo khi điều kiện đó được thỏa mãn. Điều này rất hữu ích trong việc giao tiếp và đồng bộ hóa dữ liệu giữa các luồng.
 **Cách hoạt động của std::condition_variable:**
1. **Một luồng chờ (wait) cho đến khi có tín hiệu từ một luồng khác:**
	- Luồng này sẽ chờ trong trạng thái chờ điều kiện, tránh lãng phí tài nguyên CPU.
	- Để sử dụng **wait(),** cần có một **std::unique_lock<std::mutex>** và một đối tượng **std::condition_variable,** vì nó phải tạm thời mở khóa **mutex** để các luồng khác có thể truy cập vào **mutex** và thay đổi điều kiện. Sau khi điều kiện được thỏa mãn và luồng được đánh thức, **std::unique_lock** sẽ tự động khóa lại **mutex** để đảm bảo tính nhất quán trước khi tiếp tục.
	- Lưu ý: **std::lock_guard** không hỗ trợ mở khóa và khóa lại mutex như vậy. Khi một **std::lock_guard** được tạo, nó sẽ giữ mutex cho đến khi đối tượng bị hủy (khi ra khỏi phạm vi), do đó không phù hợp để sử dụng với wait.
2. **Một luồng khác thông báo (notify_one() hoặc notify_all()) rằng điều kiện đã được đáp ứng:**
   	- **notify_one():** Chỉ đánh thức một luồng đang chờ.
	- **notify_all():** Đánh thức tất cả các luồng đang chờ.

Ví dụ 1: hai luồng cùng giao tiếp dữ liệu cảm biến, sử dụng notify_one
```cpp
#include <iostream>
#include <thread>               // tạo ra các luồng
#include <mutex>                // khóa dữ liệu khi có nhiều luồng cùng truy cập
#include <condition_variable>   // sử dụng biến điều kiện giúp đồng bộ hóa giữa các luồng
#include <chrono>               // quản lý thời gian

using namespace std;

void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

int sensor_data = 0;

bool check_data = false;

mutex mtx;

condition_variable cv;

void sensor_read(){
    while (1){
        delay(2);
        unique_lock<mutex> lock(mtx);
        sensor_data = rand() % 100;
        check_data = true;
        cout << "Read data done!\n";
        lock.unlock();
        cv.notify_one();
    }
}

void process_data(){
    while (1){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return check_data;});
        cout << "Data: " << sensor_data << endl;
        lock.unlock();
        check_data = false; 
    }
}

int main(int argc, char const *argv[])
{
    thread task1(sensor_read);
    thread task2(process_data);

    task1.join();
    task2.join();

    return 0;
}
```
Ví dụ 2: ba luồng cùng giao tiếp dữ liệu cảm biến, sử dụng notify_all
```cpp
#include <iostream>
#include <thread>               // tạo ra các luồng
#include <mutex>                // khóa dữ liệu khi có nhiều luồng cùng truy cập
#include <condition_variable>   // sử dụng biến điều kiện giúp đồng bộ hóa giữa các luồng
#include <chrono>               // quản lý thời gian


using namespace std;
void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

int sensor_data = 0;

bool check_data = false;

mutex mtx;

condition_variable cv;

void sensor_read(){
    while (1){
        delay(2);
        sensor_data = rand() % 100;
        check_data = true;
        unique_lock<mutex> lock(mtx);    // có thể ko cần
        cout << "Read data done!\n";
        lock.unlock();
        cv.notify_all();
    }
}
void process_data_1(){
    while (1){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()->bool{return check_data;}); // trả về true -> break
        cout << "Process Data 1: " << sensor_data << endl;
        lock.unlock();
        check_data = false;  
    }
}

void process_data_2(){
    while (1){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()->bool{return check_data;}); // trả về true -> break
        cout << "Process Data 2: " << sensor_data << endl;
        lock.unlock();  // giảm độ nghẽn
        check_data = false;       
    }
}

int main(int argc, char const *argv[])
{
    thread task1(sensor_read);
    thread task2(process_data_1);
    thread task3(process_data_2);

    task1.join();
    task2.join();
    task3.join();

    return 0;
}
```
## 4. Asynchronous (Bất đồng bộ)
### Khái niệm:
	Bất đồng bộ (asynchronous programming) là một kỹ thuật lập trình cho phép thực hiện các tác vụ mà không cần chờ chúng hoàn thành trước khi tiếp tục thực hiện các tác vụ khác. Bằng cách này, chương trình có thể tận dụng tối đa tài nguyên hệ thống và cải thiện hiệu suất.
	Trong C++, lập trình bất đồng bộ cho phép chạy các tác vụ trong các luồng riêng biệt, xử lý các tác vụ mất thời gian (như I/O, tính toán nặng) mà không làm gián đoạn luồng chính. Các thành phần chính để hỗ trợ lập trình bất đồng bộ trong C++ bao gồm:
- **std::async:** Khởi chạy một tác vụ bất đồng bộ, trả về đối tượng .
- **std::future:** Được sử dụng để lưu trữ kết quả của một tác vụ sẽ hoàn thành trong tương lai
- **std::shared_future:** Cho phép nhiều luồng cùng truy cập kết quả của một tác vụ bất đồng bộ.
### Tạo và khởi chạy luồng bất đồng bộ
**std::async** là một hàm trong C++ (từ C++11 trở đi) tạo ra một luồng để thực thi một công việc (task) có thể chạy bất đồng bộ, dựa trên một hàm hoặc biểu thức lambda mà bạn cung cấp. Kết quả của công việc này được trả về dưới dạng std::future, kiểu dữ liệu cho phép truy xuất giá trị của tác vụ sau khi nó hoàn tất.
	Cú pháp:
 ```cpp
 #include <iostream>
#include <future>
std::future<T> std::async(std::launch policy, Callable&& func, Args&&... args);
```
giải thích:
- policy: chế độ chạy:
	- std::launch::async: hàm sẽ chạy ngay lập tức trên một luồng mới.
	- std::launch::deferred: hàm chỉ chạy khi kết quả của std::future được yêu cầu (lazy evaluation), nghĩa là khi bạn gọi future.get().
- func:  Hàm hoặc biểu thức lambda cần thực hiện bất đồng bộ.
- args: Các tham số truyền vào func (nếu có).
### Truy cập kết quả của luồng bất đồng bộ
- Khi **std::async** được gọi, một tác vụ bất đồng bộ được tạo ra và vùng bộ nhớ cho kết quả sẽ được cấp phát động (trên heap).
- **std::future hoặc std::shared_future** sẽ nắm quyền quản lý kết quả này và giữ một con trỏ đến vùng nhớ chứa kết quả.
- Khi **get()được gọi**, giá trị được trả về từ bộ nhớ này. Nếu là **std::future, get()** sẽ chỉ có thể gọi một lần. Nếu là **std::shared_future, get()** có thể gọi nhiều lần.
#### Sự khác nhau giữa std::future và std::shared_future
- **std::future:** Đại diện cho một giá trị sẽ có trong tương lai và chỉ cho phép một luồng duy nhất lấy giá trị đó. Sau khi **phương thức get()** được gọi, giá trị sẽ được "di chuyển" và không thể lấy lại từ **std::future** lần nữa. **Nếu có nhiều thread cố gắng gọi get() trên cùng một **std::future,** chương trình sẽ bị lỗi.**
- **std::shared_future:** Cho phép nhiều luồng cùng chia sẻ và truy cập kết quả của một tác vụ bất đồng bộ. **Đối tượng shared_future** có thể được sao chép và chia sẻ giữa các thread, mỗi thread có thể gọi **get()** mà không làm mất kết quả.
- **Khi khởi tạo bằng std::async, std::future là lựa chọn mặc định. Nếu cần chia sẻ kết quả giữa nhiều thread, bạn phải chuyển std::future sang std::shared_future.**
Ví dụ 1: future và async
```cpp
#include <iostream>
#include <thread>
#include <future>
#include <mutex>

using namespace std;

int sensor_data = 0;

mutex mtx;


void delay(uint32_t time){
    this_thread::sleep_for(chrono::seconds(time));
}

int sensor_read(){
    for (int i=0; i<7; i++){
        unique_lock<mutex> ulock(mtx);
        cout << "sensor read, i = " << i << endl;
        ulock.unlock();
        delay(1);
    }
    sensor_data = rand() % 100;
    cout << "Read data done!\n";
    return sensor_data;
}

void task1(uint32_t time){
    int i = 0;
    while(1){
        unique_lock<mutex> ulock(mtx);
        cout << "task 1, i = " << i++ << endl;
        ulock.unlock();
        delay(time);
    }
}

void task2(uint32_t time){
    int i = 0;
    while(1){
        unique_lock<mutex> ulock(mtx);
        cout << "task 2, i = " << i++ << endl;
        ulock.unlock();
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    future<int> sensor_future = async(launch::async, sensor_read);

    thread t1(task1, 1);     // t1: đại diện cho luồng 1
    thread t2(task2, 3);     // t2: đại diện cho luồng 2

    int i = 0;
    while (i<10){
        unique_lock<mutex> ulock(mtx);
        cout << "This is main, i = " << i++ << endl;
        ulock.unlock();
        delay(1);
    }

    cout << "Data đã hoàn thành 1: " << sensor_future.get() << endl;// delete
    // cout << "Data đã hoàn thành 2: " << sensor_future.get() << endl;
    t1.join();
    t2.join();
    return 0;
}
```
Ví dụ 2: sử dụng std::shared_future để chia sẻ kết quả giữa nhiều thread:
```cpp
#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <chrono>
using namespace std;
mutex mtx;
int asyncTask(){
    this_thread::sleep_for(chrono::seconds(3));
    return 100;
}
void processResult(int id, shared_future<int> f){
    unique_lock<mutex> lock(mtx);
    cout << "Task " << id << ": " << f.get() << endl;
    lock.unlock();
}
int main(int argc, char const *argv[])
{
    shared_future<int> shared_ft = async(launch::async, asyncTask).share();
   
    thread t1(processResult, 1, shared_ft);
    thread t2(processResult, 2, shared_ft);

    t1.join();
    t2.join();

    return 0;
}
```
#### Kiểm tra luồng bất đồng bộ đã kết thúc hay chưa
**1. std::future::wait()**
- **wait()** sẽ tạm dừng luồng hiện tại cho đến khi giá trị trong **std::future** sẵn sàng, tức là tác vụ bất đồng bộ đã hoàn thành.
- **wait()** không nhận tham số thời gian chờ và cũng không trả về **std::future_status.** Nó chỉ đơn giản là chờ cho đến khi tác vụ hoàn tất.
  Sử dụng wait():
- Khi bạn muốn chờ đợi cho một tác vụ bất đồng bộ hoàn thành mà không cần quan tâm đến thời gian chờ cụ thể.
- Khi bạn muốn đảm bảo rằng tác vụ bất đồng bộ đã hoàn thành trước khi thực hiện các bước tiếp theo trong chương trình.
ví dụ:
```cpp
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;


int asyncTask(){
    this_thread::sleep_for(chrono::seconds(3));
    return 100;
}

// Hàm cho luồng 1, in thông báo sau mỗi giây trong 6 giây
void thread1Task() {
    for (int i = 1; i <= 6; ++i) {
        cout << "Thread 1 - second " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// Hàm cho luồng 2, in thông báo sau mỗi 2 giây trong 6 giây
void thread2Task() {
    for (int i = 1; i <= 3; ++i) {
        cout << "Thread 2 - second " << (i * 2) << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main(int argc, char const *argv[])
{
    future<int> ft = async(launch::async, asyncTask);
    thread t1(thread1Task);
    thread t2(thread2Task);
     // Luồng chính chờ đợi tác vụ bất đồng bộ hoàn thành
    cout << "Waiting for the task to complete...\n";
    ft.wait();
    cout << "Task completed! Result: " << ft.get() << endl;
    // Chờ hai luồng phụ hoàn thành
    t1.join();
    t2.join();
    cout << "Main thread finished.\n";
    return 0;
}
```
**2. std::future::wait_for()**
**wait_for()** chờ đợi một khoảng thời gian cụ thể (rel_time) để kiểm tra xem tác vụ bất đồng bộ đã hoàn thành hay chưa. Thời gian này được chỉ định bằng một đối tượng **"std::chrono::duration" hoặc "std::chrono::sleep".**
	Giá trị trả về: Trả về một giá trị thuộc kiểu **"std::future_status",** có thể là:
 + **"std::future_status::ready":** Tác vụ đã hoàn thành trong khoảng thời gian chỉ định.
 + **"std::future_status::timeout":** Tác vụ chưa hoàn thành trong khoảng thời gian chỉ định.
 + **"std::future_status::deferred":** Tác vụ được khởi chạy ở chế độ trì hoãn (launch::deferred) và sẽ chỉ được thực thi khi có lệnh gọi đến get() hoặc wait().
	ví dụ:
```cpp 
#include <iostream>
#include <thread>
#include <future>
#include <chrono>


using namespace std;

int asyncTask(){
    this_thread::sleep_for(chrono::seconds(3));
    return 100;
}

int main(int argc, char const *argv[])
{
    future<int> ft = async(launch::async, asyncTask);


    cout << "LOG 1" << endl;

    if (ft.wait_for(chrono::seconds(1)) == future_status::ready){
        cout << "Task completed!\n";
    }
    else{
        cout << "Task is still running...\n";
    }
    cout << "Result: " << ft.get() << endl;    
    return 0;
}
```































 



































































































































































