# advance-C/C++-algorithm
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

***Trong ví dụ này:***
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
Chia sẻ biến và hàm giữa các file nguồn:
Extern cho phép bạn chia sẻ biến và hàm giữa nhiều file nguồn trong một chương trình.
Điều này hữu ích khi bạn muốn tách chương trình thành các phần nhỏ để quản lý dễ dàng hơn.
Chia sẻ biến và hàm giữa các module hoặc thư viện:
Extern có thể được sử dụng để kết nối các module hoặc thư viện trong một dự án lớn.
Khai báo hàm trong trường hợp định nghĩa sau:
Nếu bạn muốn sử dụng một hàm trước khi nó được định nghĩa trong mã nguồn, bạn có thể sử dụng extern để khai báo hàm.
Biến toàn cục giữa các tệp nguồn:
Khi có một biến toàn cục được sử dụng trong nhiều file nguồn, extern giúp các file nguồn biết về sự tồn tại của biến đó.
Chia sẻ hằng số giữa các file nguồn:
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
	Việc sử dụng goto có thể làm cho mã nguồn trở nên khó bảo trì và khó đọc. Nhiều lập trình viên và chuẩn coding conventions không khuyến khích sử dụng goto nếu có cách thức khác để thực hiện logic. Thay vào đó, sử dụng các cấu trúc kiểm soát vòng lặp (for, while, do-while) và cấu trúc điều kiện (if, else) để viết mã nguồn dễ đọc và bảo trì hơn. 
Mặc dù sử dụng goto không được khuyến khích trong phần lớn các trường hợp vì nó có thể làm tăng khả năng phức tạp và khó bảo trì của mã nguồn, nhưng có một số tình huống cụ thể mà việc sử dụng goto có thể được coi là hợp lý:
Thoát khỏi nhiều cấp độ vòng lặp
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
Xử lý lỗi và giải phóng bộ nhớ
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



***Implement Finite State Machines (FSM)**
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
```cpp 
Ví dụ:	
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
Sử dụng trong các tình huống đặc biệt
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
Mã máy:
Chứa mã máy, tức là tập hợp các lệnh thực thi được CPU hiểu được.
Mã máy được tạo ra thông qua quá trình biên dịch từ mã nguồn của chương trình.
Quyền truy cập:
Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. điều này ngăn chặn chương trình việc tự sửa đổi mã máy của nó.
Kích thước cố định:
Kích thước của Text Segment thường là cố định khi chương trình được biên dịch.
Điều này giúp hệ điều hành và CPU dễ dàng quản lý vùng nhớ này.
Lưu Trữ Code và Hằng Số:
Bao gồm cả mã máy của các hàm và các hằng số.
Các hàm được gọi từ các phần khác của chương trình sẽ có địa chỉ trong Text Segment.

## Data Segment
Data Segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ dữ liệu tĩnh của chương trình. Dữ liệu tĩnh bao gồm biến toàn cục và biến tĩnh (static), tức là các biến mà không phụ thuộc vào thời gian chạy của chương trình. 
	Một số đặc điểm:
Biến Toàn Cục (Global Variables):
Chứa giá trị của các biến toàn cục được khai báo trong chương trình.
Các biến này có thể được truy cập từ bất kỳ hàm nào trong chương trình.
Biến Tĩnh (Static Variables):
Chứa giá trị của các biến tĩnh, nghĩa là biến được khai báo với từ khóa static.
Có thể được truy cập chỉ trong phạm vi của hàm mà chúng được khai báo.
Initialized Data Segment (Dữ liệu Đã Khởi Tạo):
Chứa giá trị của các biến toàn cục và biến tĩnh được khởi tạo với giá trị ban đầu.
Dữ liệu này được sao chép từ bộ nhớ của chương trình thực thi.
Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):
Chứa giá trị mặc định của các biến toàn cục và biến tĩnh mà không cần khởi tạo giá trị ban đầu.
Dữ liệu trong phân vùng này thường được xác định bởi giá trị 0.
Quyền truy cập: Data Segment thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong quá trình thực thi của chương trình.
Kích thước cố định: Kích thước của Data Segment có thể thay đổi trong quá trình thực thi của chương trình khi các biến được khởi tạo hoặc giải phóng.
## Heap
Heap là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để cấp phát bộ nhớ động. Các biến được cấp phát trên heap không có kích thước xác định tại thời điểm biên dịch và có thể được quản lý động trong quá trình thực thi của chương trình.
Một số đặc điểm:
Cấp phát động:
Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
Quyền truy cập: Bộ nhớ trên heap thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong suốt thời gian chương trình chạy.
Cấp Phát và Giải Phóng Bộ Nhớ: Các hàm như malloc(), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.
Kích Thước Thay Đổi: Kích thước của heap có thể thay đổi trong quá trình thực thi của chương trình, tùy thuộc vào các thao tác cấp phát và giải phóng bộ nhớ.
Không Giữ Giá Trị Mặc Định: Bộ nhớ trên heap không giữ giá trị mặc định như trong Data Segment. Nếu không được khởi tạo, giá trị của biến trên heap sẽ không xác định.
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
LIFO: Stack hoạt động theo nguyên tắc LIFO, nghĩa là phần tử cuối cùng được thêm vào sẽ là phần tử đầu tiên được lấy ra.
Các biến cục bộ: Chứa các biến cục bộ, tức là các biến được khai báo trong các hàm và chỉ có giá trị trong phạm vi của hàm đó.
Kích thước cố định: Tùy thuộc vào hệ điều hành khác nhau
Địa chỉ trả về: Khi một hàm được gọi, địa chỉ trả về (return address) được đẩy vào ngăn xếp để theo dõi nơi chương trình sẽ tiếp tục sau khi hàm kết thúc thực thi.
Thực hiện gọi hàm và trả về: Khi một hàm được gọi, các giá trị và địa chỉ quan trọng liên quan đến hàm đó được đẩy vào ngăn xếp. Sau khi hàm kết thúc, những giá trị này được lấy ra để quay trở lại thực thi chương trình.
Khối lệnh ( Frame): Mỗi hàm khi được gọi tạo ra một khối lệnh (frame) trên ngăn xếp, chứa các biến cục bộ và các giá trị khác liên quan đến hàm.
Stack pointer: Con trỏ ngăn xếp (stack pointer) giữ địa chỉ hiện tại của stack và được cập nhật liên tục khi dữ liệu được đẩy vào hoặc lấy ra.
	Stack là một cơ chế quan trọng trong quá trình thực thi chương trình và thường được sử dụng để quản lý luồng thực thi, gọi hàm, và theo dõi các biến cục bộ. Các ngôn ngữ lập trình thường sử dụng ngăn xếp để triển khai thực thi hàm và quản lý các biến cục bộ.
Memory - mapped Segment
Memory-mapped segment là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để tương tác với các thiết bị ngoại vi thông qua các địa chỉ bộ nhớ. Thông thường, các thiết bị ngoại vi như cổng vào/ra (I/O ports) và thanh ghi của các thiết bị được ánh xạ trực tiếp vào không gian địa chỉ bộ nhớ của chương trình.
Một số đặc điểm:
Tương tác với thiết bị ngoại vi: Memory-mapped segment cho phép chương trình tương tác với các thiết bị ngoại vi bằng cách truy cập địa chỉ bộ nhớ tương ứng với các thanh ghi và cổng I/O của các thiết bị đó.
Địa chỉ bộ nhớ ánh xạ: Các địa chỉ bộ nhớ của các thanh ghi và cổng I/O của các thiết bị ngoại vi được ánh xạ vào không gian địa chỉ bộ nhớ của chương trình.
Quyền truy cập: Memory-mapped segment thường có thể có quyền đọc và ghi để cho phép chương trình gửi dữ liệu đến thiết bị và đọc dữ liệu từ thiết bị.
Giao tiếp với thiết bị ngoại vi: Thông qua Memory-mapped segment, chương trình có thể gửi lệnh và nhận dữ liệu từ các thiết bị ngoại vi, như cổng COM, bàn phím, màn hình và các thiết bị khác.
Sử dụng trong ngôn ngữ mã máy và assembly: Memory-mapped segment thường được sử dụng nhiều trong ngôn ngữ máy và ngôn ngữ gần với phần cứng để thực hiện các thao tác gần với phần cứng của hệ thống.
Điều khiển thiết bị: Ánh xạ địa chỉ bộ nhớ của các thanh ghi và cổng I/O của thiết bị ngoại vi cho phép chương trình kiểm soát và điều khiển các thiết bị ngoại vi.
Lưu ý rằng sử dụng Memory-mapped segment đôi khi yêu cầu quyền hệ điều hành và có thể chỉ có sẵn trong môi trường thực thi nào đó (ví dụ như hệ điều hành Unix-like).

# Stack và Heap
	Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
	Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
	Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).

	Kích thước vùng nhớ:
### Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
### Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.

**Đặc điểm vùng nhớ:**
### Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
### Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

**Vấn đề lỗi xảy ra với vùng nhớ:**
### Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
	Ví dụ tràn bộ nhớ stack khi gọi hàm đệ quy vô hạn:
 ```cpp 
int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
}
```

### Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
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
Dấu ngoặc nhọn ({}) được sử dụng để bao bọc đối tượng.
Dấu ngoặc vuông ([]) được sử dụng để bao bọc mảng.
Dấu phẩy
	Dấu phẩy được sử dụng để phân tách giữa các thành phần trong mảng hoặc các cặp khóa-giá trị trong đối tượng.
Khoảng trắng
	Khoảng trắng, dấu xuống dòng và tab không ảnh hưởng đến tính chính xác của JSON và thường được sử dụng để làm cho JSON dễ đọc hơn.
Nhận xét
JSON không hỗ trợ cú pháp nhận xét nội dung. Bất kỳ văn bản nào sau dấu nhận xét (// hoặc /* */) không được hiểu là hợp lệ trong JSON.
# Linked List
Khái niệm
Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
Có hai loại linked list chính:
Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.
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
items: Một con trỏ tới một mảng lưu trữ các phần tử ngăn xếp một cách động.
size: Sức chứa tối đa của ngăn xếp.
top: Theo dõi chỉ mục của phần tử trên cùng trong ngăn xếp ( -1 khi ngăn xếp trống).

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
Các member public của class cha vẫn sẽ là public trong class con.
Các member protected của class cha vẫn sẽ là protected trong class con.
Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha
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
Các member public, protected của class cha sẽ là protected trong class con.
Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
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
Các member public, protected của class cha sẽ trở thành private trong class con.
Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
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
Khi một hàm là virtual, nó có thể được ghi đè (override) trong class con để cung cấp cách triển khai riêng.
Khi gọi một hàm ảo thông qua một con trỏ hoặc tham chiếu đến lớp con, hàm sẽ được quyết định dựa trên đối tượng thực tế mà con trỏ hoặc tham chiếu đang trỏ tới chứ không dựa vào kiểu của con trỏ.
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
Khi một hàm ảo được ghi đè, hành vi của nó sẽ phụ thuộc vào kiểu của đối tượng thực tế, chứ không phải kiểu của con trỏ hay tham chiếu.
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
Đa kế thừa trong C++ cho phép một class kế thừa từ nhiều class khác.
Đa kế thừa thường dùng để kết hợp các chức năng từ nhiều class.
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
Khi nhiều lớp cha có các phương thức hoặc thuộc tính trùng tên, việc gọi chúng từ lớp con có thể gây ra sự nhầm lẫn.
Khi một lớp con kế thừa từ hai lớp cha, mà hai lớp cha này đều cùng kế thừa từ cùng một lớp khác. Tình huống này tạo ra cấu trúc hình thoi (diamond), do đó được gọi là vấn đề "Diamond".
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
Kế thừa ảo giúp tránh vấn đề diamond problem trong đa kế thừa.
Chỉ có một bản sao duy nhất của lớp cơ sở chung được kế thừa.
Kế thừa ảo giúp quản lý các lớp liên quan đến phần cứng và giao tiếp. Điều này giúp tránh trùng lặp tài nguyên và quản lý hiệu quả trong hệ thống nhúng.
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











































































