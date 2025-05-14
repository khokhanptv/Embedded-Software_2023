<details>
<summary><h1><img src="https://gcs.tripi.vn/public-tripi/tripi-feed/img/474015QSt/anh-gai-xinh-1.jpg" width="90px"  >   Kiến thức tổng hơp </h1></summary>


| **Tiêu chí**           | **Multi-Process**                                                             | **Multi-Thread**                                                           |
|------------------------|-------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| **Là gì?**              | Là một **chương trình độc lập** đang chạy (có vùng nhớ và tài nguyên riêng biệt). | Là **đơn vị nhỏ hơn của process**, chạy song song bên trong process.         |
| **Khái niệm**           | Tạo ra nhiều tiến trình (process) độc lập                                     | Tạo nhiều luồng (thread) trong cùng một tiến trình                         |
| **✅ Mục đích tổng quát** | Cần cách ly bộ nhớ, tăng độ an toàn & ổn định khi crash                      | Cần tốc độ xử lý song song, chia sẻ dữ liệu nhanh giữa các task nhỏ         |
| **Bộ nhớ**              | Mỗi process có bộ nhớ riêng biệt                                               | Các thread chia sẻ bộ nhớ chung                                            |
| **Tốc độ giao tiếp**    | Chậm hơn vì phải dùng IPC                                                     | Nhanh vì dùng chung bộ nhớ                                                 |
| **Tính ổn định**        | An toàn hơn: crash 1 process không làm hỏng process khác                      | Nếu 1 thread lỗi, có thể làm treo toàn bộ process                          |
| **Tốn tài nguyên**      | Tốn bộ nhớ hơn do không gian riêng                                             | Tốn ít tài nguyên hơn                                                      |
| **Giao tiếp (IPC)**     | Cần dùng Pipe, Socket, Shared Memory                                          | Không cần IPC, vì dùng chung biến                                          |
| **Ví dụ API**           | fork(), CreateProcess(), Boost.Process                                        | std::thread, pthread (POSIX), std::async                                   |


# Inter-Process Communication (IPC)

## IPC là gì?
- IPC là các cơ chế giúp các process giao tiếp với nhau vì chúng **không chia sẻ bộ nhớ**.
- Dùng cho **Multi-Process** (không cần thiết với Multi-Thread).

## Các loại IPC phổ biến:

| IPC Loại          | Giải thích                                                     | Đặc điểm                                              |
|-------------------|---------------------------------------------------------------|------------------------------------------------------|
| **Pipe**          | 1 chiều: truyền dữ liệu từ process cha -> con hoặc ngược lại    | Đơn giản, giống ống dẫn                              |
| **Named Pipe (FIFO)** | Giống pipe nhưng có tên, nhiều process truy cập được            | Giao tiếp giữa 2 process không cùng cha-con          |
| **Shared Memory** | Nhiều process truy cập vùng nhớ chung                          | Rất nhanh, nhưng cần cơ chế đồng bộ (semaphore)       |
| **Message Queue** | Hàng đợi lưu thông điệp giữa process                           | Có thứ tự, quản lý message tốt                       |
| **Socket**        | Giao tiếp qua TCP/UDP, kể cả qua mạng                          | Mạnh mẽ, dùng cho client-server                     |
| **Semaphore**     | Cơ chế đồng bộ để quản lý tài nguyên dùng chung                | Hay dùng với Shared Memory                           |
| **Signals**       | Gửi tín hiệu tới process khác (kill, stop, user-defined signals)| Đơn giản, không truyền dữ liệu                      |

# So sánh: Semaphore vs Mutex

| Tiêu chí            | Semaphore                                                         | Mutex                                                          |
|---------------------|--------------------------------------------------------------------|----------------------------------------------------------------|
| **Khái niệm**        | Biến đếm, quản lý số lượng truy cập vào tài nguyên dùng chung , ví dụ:n=0 >> 1 process truy cập ,1 >>1 truy cập     | Khóa nhị phân, chỉ cho phép 1 thread truy cập tại 1 thời điểm   |
| **Giá trị**          | Có thể >1 (Counting Semaphore) hoặc 0/1 (Binary Semaphore)          | Chỉ có 2 trạng thái: Locked (1) hoặc Unlocked (0)              |
| **Use case**         | Quản lý nhiều tài nguyên cùng loại (pool connection, buffer slot)  | Đảm bảo chỉ 1 thread vào vùng critical section                  |
| **Sở hữu (Ownership)**| Không có khái niệm sở hữu, ai cũng có thể Signal (V)                | Chỉ thread lock mới có thể unlock (đảm bảo tính sở hữu)         |
| **Tốc độ**           | Thường chậm hơn mutex do hay dùng cho nhiều resource               | Nhanh hơn khi chỉ cần bảo vệ độc quyền                          |
| **Khả năng đồng bộ**  | Đồng bộ nhiều thread/process truy cập đồng thời (nhiều resource)   | Đồng bộ truy cập độc quyền (1 resource duy nhất)                |
| **Ứng dụng phổ biến** | Shared Memory, giới hạn resource pool                             | Bảo vệ vùng critical section, bảo vệ dữ liệu đơn lẻ              |

## Tóm tắt:
- **Mutex** = Bảo vệ độc quyền (1 thread tại 1 thời điểm).
- **Semaphore** = Quản lý nhiều tài nguyên hoặc kiểm soát luồng truy cập đồng thời.

# Tóm tắt: Khi nào dùng loại IPC nào?

| Nhu cầu                                          | Nên dùng                                   |
|--------------------------------------------------|--------------------------------------------|
| **Truyền dữ liệu đơn giản cha <-> con**          | Pipe                                       |
| **Giao tiếp giữa process khác cha mẹ**           | Named Pipe, Socket                         |
| **Cần hiệu suất cao (shared data)**              | Shared Memory + Semaphore                  |
| **Truyền thông điệp dạng hàng đợi**              | Message Queue                              |
| **Dịch vụ Client-Server**                        | Socket                                     |
| **Báo hiệu trạng thái (simple signal)**          | Signals              

# Cha (Parent Process) và Con (Child Process)

| Parent Process (Tiến trình Cha)                           | Child Process (Tiến trình Con)                                      |
|-----------------------------------------------------------|---------------------------------------------------------------------|
| Là tiến trình gốc, đang chạy trước                        | Là tiến trình được tạo ra bởi tiến trình cha                        |
| Dùng `fork()` (Linux) hoặc `CreateProcess()` (Windows) để tạo con | Con là bản sao hoặc chương trình mới sinh ra từ cha                  |
| Có thể tạo nhiều tiến trình con                           | Mỗi con có thể tiếp tục tạo ra các tiến trình con khác               |
| Có thể giao tiếp với con qua Pipe, Shared Memory, Signal, Socket | Con có thể trả kết quả về cho cha qua các phương pháp IPC            |
                      |
# Windows Message là gì?

**Windows Message** là cơ chế giao tiếp giữa hệ điều hành Windows và ứng dụng (hoặc giữa các cửa sổ).

## Chức năng:
- Cho phép **Hệ điều hành gửi thông điệp** tới ứng dụng khi có sự kiện xảy ra.
- Các **cửa sổ trong ứng dụng** cũng có thể gửi message cho nhau.
- Là nền tảng của **Windows GUI Programming**.

## Ví dụ về các loại message:
| Hành động               | Message tương ứng                     |
|-------------------------|---------------------------------------|
| Click chuột              | `WM_LBUTTONDOWN`, `WM_LBUTTONUP`      |
| Nhấn phím                | `WM_KEYDOWN`, `WM_KEYUP`              |
| Di chuyển/Resize cửa sổ  | `WM_MOVE`, `WM_SIZE`                  |
| Timer                   | `WM_TIMER`                            |
| Đóng cửa sổ              | `WM_CLOSE`, `WM_DESTROY`              |

## Cơ chế xử lý:
- Mỗi cửa sổ có một **message queue**.
- Khi có sự kiện, message sẽ được **gửi vào queue**.
- Hàm **`GetMessage()` / `PeekMessage()`** lấy message ra xử lý.
- Hàm **`DispatchMessage()`** sẽ chuyển message tới hàm **WindowProc()** để xử lý thực tế.

## Code minh hoạ:
```cpp
MSG msg;
while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```
Tóm tắt:
Windows Message = Thông điệp sự kiện.

Làm cầu nối giữa Hệ điều hành ↔ Ứng dụng.

Ứng dụng phải có vòng lặp xử lý message để tương tác với người dùng.


# Phát hiện Memory Leak khi dùng Smart Pointer (shared_ptr, unique_ptr)

| Công cụ                            | Môi trường        | Dùng để                                      | Ưu điểm                                      |
|------------------------------------|------------------|----------------------------------------------|---------------------------------------------|
| **Valgrind (memcheck)**            | Linux            | Phát hiện leak vùng heap                     | Chuẩn, mạnh mẽ                              |
| **AddressSanitizer (ASAN)**        | Linux & Windows  | Runtime detect leak & Undefined Behavior     | Nhanh, dễ dùng                              |
| **Visual Studio Diagnostic Tools** | Windows (VS IDE) | Xem live memory usage, detect leaks          | Tích hợp dễ dùng                            |
| **leak sanitizer (-fsanitize=leak)**| Linux            | Phát hiện leak khi build                     | Cực nhanh, nhẹ                              |
| **Clang Static Analyzer**          | Linux, macOS     | Phân tích code tĩnh, tìm lỗi leak             | Không cần chạy app                          |
| **Instruments (Leaks tool)**       | macOS            | GUI kiểm tra leak trên app                   | Đẹp, dễ nhìn                                |
| **shared_ptr::use_count()**        | Tất cả           | Kiểm tra tham chiếu thủ công                 | Dùng cho vòng tham chiếu debug              |

## Ghi chú:
- Với **shared_ptr**, memory leak thường do **vòng tham chiếu (circular reference)** → cần dùng **weak_ptr**.
- **unique_ptr** sẽ tự huỷ khi ra khỏi scope, leak chủ yếu do misuse (gián tiếp).

shared_ptr::use_count() là một phương thức thành viên của smart pointer std::shared_ptr 
✅ Ý nghĩa:
use_count() giúp kiểm tra có bao nhiêu shared_ptr đang cùng giữ quyền sở hữu đối tượng.

Dùng để debug vòng tham chiếu (circular reference) hoặc kiểm tra số lượng tham chiếu còn lại.


# 📦 So sánh Process vs Thread & Câu hỏi Phỏng vấn

## 🔹 1. Sự khác biệt giữa Process và Thread
- **Process**: Chương trình đang chạy, vùng nhớ & tài nguyên riêng biệt.
- **Thread**: Luồng nhỏ hơn, chung vùng nhớ trong cùng 1 process.

## 🔹 2. Ưu nhược điểm của Multi-Process và Multi-Thread

| **Multi-Process**                        | **Multi-Thread**                              |
|------------------------------------------|-----------------------------------------------|
| An toàn, cách ly vùng nhớ                | Tốn ít tài nguyên, giao tiếp dễ dàng          |
| Khó chia sẻ dữ liệu, tốn nhiều tài nguyên | Dễ bị race condition, deadlock               |

## 🔹 3. Khi nào dùng Multi-Process, khi nào dùng Multi-Thread?
- **Process**: Cần cách ly, an toàn (ex: browser tab).
- **Thread**: Cần tốc độ, chia sẻ dữ liệu nhanh (ex: web server).

## 🔹 4. Vì sao Multi-Thread dễ bị race condition hơn Process?
- Thread dùng chung vùng nhớ → dễ xung đột dữ liệu.
- Process tách biệt vùng nhớ → không bị tranh chấp.

## 🔹 5. Context Switch Process vs Thread?
- **Process switch**: Tốn nhiều tài nguyên hơn (vì đổi vùng nhớ).
- **Thread switch**: Nhanh hơn (vì cùng vùng nhớ).

## 🔹 6. Giao tiếp giữa Process và Thread khác nhau thế nào?
- **Process**: IPC (socket, pipe, shared memory...).
- **Thread**: Giao tiếp dễ qua biến chung, chỉ cần đồng bộ hóa.

## 🔹 7. Deadlock là gì? Cách phòng tránh?
- **Deadlock**: 2 hoặc nhiều thread/process cùng chờ tài nguyên → kẹt.
- **Phòng tránh**: Cố định thứ tự lock, dùng timeout, lock-free structures.

## 🔹 8. Vì sao browser dùng Multi-Process cho mỗi tab?
- Cách ly lỗi: Tab crash không ảnh hưởng tab khác.
- Bảo mật: Cô lập sandbox từng tab.
- Tối ưu đa nhân CPU.

## 🔹 9. Vì sao Multi-Thread dễ lỗi segmentation fault hơn Process?
- Thread: Cùng vùng nhớ, dễ ghi sai địa chỉ, thiếu đồng bộ → lỗi.
- Process: Vùng nhớ riêng → lỗi không lan sang process khác.

## 🔹 10. Ưu nhược điểm của Shared Memory trong Multi-Thread?
- **Ưu điểm**: Truyền dữ liệu nhanh, dùng chung biến.
- **Nhược điểm**: Dễ race condition, deadlock → cần đồng bộ tốt.

## 🔹 11. Fork() & exec() là gì?
- `fork()`: Tạo process con (copy từ cha).
- `exec()`: Nạp code chương trình mới vào process hiện tại.

## 🔹 12. Mô hình Master-Worker?
- **Master**: Quản lý, chia task.
- **Worker**: Thread/Process xử lý task song song.

## 🔹 13. Debug race condition, deadlock thực tế?
- Dùng log, tool (Valgrind, ThreadSanitizer).
- Kiểm tra thứ tự lock, đồng bộ hóa lại.

## 🔹 14. Multi-core CPU: Multi-Thread vs Multi-Process?
- **Multi-Thread**: Tận dụng đa nhân tốt, nhẹ hơn.
- **Multi-Process**: Cách ly an toàn hơn nhưng nặng hơn.

## 🔹 15. GIL trong Python là gì?
- Global Interpreter Lock: Chỉ 1 thread Python chạy tại 1 thời điểm → hạn chế CPU-bound multi-thread.
- Dùng Multi-Process để tận dụng đa nhân.

## 🔹 16. Xử lý ảnh hàng loạt: Process hay Thread?
- Ảnh lớn, nặng: Dùng Multi-Process.
- Ảnh nhỏ, nhẹ, cần tốc độ: Dùng Multi-Thread.

## 🔹 17. Debug khi ứng dụng bị crash do multi-thread?
- Xem log, core dump, dùng AddressSanitizer.
- Kiểm tra race condition, vùng nhớ sai.
- Đồng bộ hóa lại.

## 🔹 18. Server 10,000 request/s: Process hay Thread?
- **Thread**: Xử lý nhanh, nhẹ, số lượng lớn request.
- **Process**: Dùng khi cần cách ly an toàn.
- Thực tế: Hybrid (Process + Thread pool).

## 🔹 19. Công cụ debug lỗi đồng bộ (race condition, deadlock)?
- **GDB + rr**: Debug "time-travel", cực hay với lỗi khó tái hiện.
- **Visual Studio**: Dành cho Windows dev.













## 1 số BT liên quan con trỏ
<details>
<summary>Pointer</summary>

**Tính độ dài mảng tĩnh**
<details>
<summary>CODE:</summary>

```C
#include <stdio.h>
int main() {
    int arr[4] = {1, 2, 3, 4};
    int *ptr = arr;
    int length = 0;

    while (*ptr != '\0') {
        ptr++;
        length++;
    }
    printf("Do dai mang arr la: %d\n", length);

    return 0;
}
1111
```
</details>

**Tính độ dài mảng động**
<details>
<summary>CODE:</summary>

```C
 #include "stdio.h"
 #include"stdlib.h"
 
 int main(){
    int n=0;
    int length=0;
    printf("nhap n\n");
    scanf("%d",&n);
    int *arr= (int*)malloc(n*sizeof(int));//cấp phát động cho mảng
    if(arr==NULL){
        printf("loi \n");
        return 1;
    }
    int *ptr =arr;
    printf("nhap cac phan tu\n");
    for(int i =0;i<n;i++){
        scanf("%d",ptr+i);
    }
    printf("cac phan tu da nhap la\n");
    for(int i =0;i<n;i++){
        printf("%d ",*(ptr+i));
    }
	free(arr);
	return 0;
 }
```  
</details>

**Sắp xếp(thuật toán bubble sort) và tìm kiếm**
<details>
<summary>CODE:</summary>

```C
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=0;
    int temp;
    int a;
    int found =0;
    printf("nhap n\n");
    scanf("%d",&n);

    int *arr=(int*)malloc(n*sizeof(int));
    int *ptr  =arr;
    printf("nhap cac phan tu\n");
    for(int i =0;i<n;i++){
    scanf("%d",(ptr+i));
    }  
    printf("cac phan tu da nhap la n\n"); 
    for(int i =0;i<n;i++){
        printf("%d \n",*(ptr+i));
    }
    printf("sap xep cac phan tu tu be toi lon\n");
    for(int i =0;i<n;i++){
        for(int j=i+1; j<n;j++){
            if (*(ptr+i)>*(ptr+j)){
            temp =*(ptr+i);
            *(ptr+i)  =*(ptr+j);
            *(ptr+j) =temp;
         }
        }
    }
    printf("cac phan tu da sap xep n\n"); 
        for(int i =0;i<n;i++){
        printf("%d \n",*(ptr+i));
    }
    printf("nhap so can tim\n"); 
    scanf("%d",&a);
    for(int i =0;i<n;i++){
        if(a == *(ptr+i)){
            printf("da tim thay %d o vi tri %d \n ",*(ptr+i),i);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("khong tim thay\n");
        }
    


    free(arr);
    return 0;
}
```

</details>

**Sắp xếp mảng**
<details>
<summary>CODE:</summary>

```C
#include <stdio.h>

int main(void) {
    char arr1[] = "dbca 1d13";
    char *ptr1;
    ptr1 = arr1;
 printf("Chuoi s: %s \n", ptr1);
    // Sắp xếp chuỗi arr1 theo yêu cầu
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (ptr1[i] > ptr1[j]) {
                char temp = ptr1[i];
                ptr1[i] = ptr1[j];
                ptr1[j] = temp;
            }
        }
    }

    printf("Chuoi sau khi sap xep: %s \n", ptr1);

    return 0;
}
```
</details>

**So sánh 2 mảng bất kỳ( 1 chiều , 2 chiều)**
<details>
<summary>CODE:</summary>

```c
 #include <stdio.h>

int compareArrays(const char *arr1, const char *arr2, int size) ;
   

int main()
{
    char str[5] = {1, 2, 3, 0, 5};
    char serNum[2][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 0, 5}};
     
    
    // Lưu kết quả của hàm compareArrays
    int s1 = compareArrays(str, serNum[0], 5); // So sánh với hàng đầu tiên của serNum
    printf("s1 bang %d \n", s1);
    
    int s2 = compareArrays(str, serNum[1], 5); // So sánh với hàng thứ hai của serNum
    printf("s2 bang %d \n", s2);
    
    //1 cach tong hop hon, dung vòng for
    for (int j = 0; j < 5; ++j) {
                if (compareArrays(str, serNum[j], 5)) {
                 
                    printf("ID the khop tai vi tri %d\n", j);
                    break; 
                }
            }


    return 0;
}


int compareArrays(const char *arr1, const char *arr2, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr1[i] != arr2[i]) {
            return 0; 
        }
    }
    return 1; 
}

```

</details>

</details>

## Struct_union

<details>
<summary>CODE:</summary>

```C
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(void){
    struct ex{
       
        uint8_t  arr1[5]   ;
        uint16_t  arr2[4]   ;
        uint32_t  arr3[2]   ;
    };
    union ex1{
       
        uint8_t  arr1[5]   ;
        uint16_t  arr2[4]   ;
        uint32_t  arr3[2]   ;
    };
    printf("%zu",sizeof(struct ex));
    printf("%zu",sizeof(union ex1));
    return 0;
}


```

</details>











</details>
</details>
<details>
<summary><h1>▶ ⭐C_BASIC</h1></summary>

<details>
  <summary><h3>Lệnh điều kiện trong C</h3></summary>

  **_Câu lệnh If_**
  - Nếu điều kiện được thỏa mãn thì sẽ thực thi đoạn code bên trong nó.
  `if (điều kiện){
    Khối lệnh sẽ được thực hiện nếu <điều kiện> đúng.
}`

<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
int main(){
   int a;
   printf(“Nhap a = “); scanf(“%d”, &a);
 
   if (a % 2 == 0) // a chia hết cho 2
   {
       printf(“%d la so chan”, a);
   }
   printf(“\nXong!”);
} 
```
 - Câu lệnh If else
 ```C
 if (condition)
 {
   // statement1
   // khối lệnh sẽ thực hiện nếu điều kiện đúng
}else
{
   // statement2
   // khối lệnh sẽ thực hiện nếu điều kiện sai
}
```
- Ví dụ

```C
#include <stdio.h>
 
int main(){
   int a;
   printf(“Nhap a = “); scanf(“%d”, &a);
   if (a % 2 == 0) // a chia hết cho 2
   {
       printf(“%d la so chan”, a);
   }else{
       printf(« %d la so le », a) ;
   }
} 
```

 - Câu lệnh if … else if … else:

```C
	if (test expression1) 
	{
	// statement(1)
	}
	else if(test expression2) 
	{
	// statement(2)
	}
	else if (test expression3) 
	{
	// statement(3)
	}
	…
	else 
	{
	// statement(n)
	}
```
</details>

**_switch case_**

 - Lệnh switch case là một cấu trúc điều khiển & rẽ nhánh hoàn toàn có thể được thay thế bằng cấu trúc if else. Tuy nhiên, việc sử dụng switch case sẽ giúp code của chúng ta dễ viết và dễ đọc hơn.
```C
switch (expression)// tham số đầu vào 
​{
   case constant1:// điều kiện
     // statements(khối lệnh)
     break;
   case constant2:
     // statements
     break;
   default:
     // default statements
}
```
 - Case default sẽ được thực hiện nếu không có case nào khớp giá trị  

 <details>
<summary>Ví dụ</summary>

```C
#include <stdio.h>

int main(void) {
int thang =1 ;
switch ( thang){
case 1:
	printf("30 ngay\n");
	break;
case 12:
	printf("28 ngay\n");
	break;
	default:
	printf("khong hop le\n");
	}
return 0;
}
	//Tổng bằng 8
```
 - Nếu không break ở cuối mỗi case thì chương trình sẽ chạy tiếp xuống các case ngay bên dưới dẫn đến chương trình có thể sai ý đồ.
 - Nhưng cố ý không break,có thể hiển thị nhiều điện kiện với 1 nội dung

```C
int main(void) {
day = Mon; 
switch (day) {
case Mon:
case Tue:
case Wed:
case Thu:
case Fri:
 	printf("Ngày trong tuần\n");
 break;
case Sat:
case Sun:
 	printf("Ngày lễ\n");
 break;
default:
 	printf("Không tồn tại\n");
}
return 0;
}
```

</details>



**_if và switch :_**
 - if dùng để kiểm tra các điều kiện là toán tử so sánh (<, >, ==, !=, vv.) hoặc các toán tử logic (&&, ||, vv.).
 - switch dùng để so sánh một biểu thức với các giá trị khác nhau. Nó sẽ kiểm tra giá trị và thực hiện các hành động tương ứng với giá trị đó.
 - Switch sẽ so sánh các tính năng khác nhau,mã sạch sẽ hơn và dễ đọc.
 - Nên sử dụng switch case trong bài toán mul-ti choice, biểu thức điều kiện tính toán phức tạp nhưng phải có giá trị nguyên.

</details>
<details>
  <summary><h3>Vòng lặp</h3></summary>

**Vòng lặp for:** 
- Cú pháp:
```C
for ( giá trị ban đầu; điều kiện lặp; thuật toán   )
{
   // các lệnh cần lặp
}
```

 <details>
<summary>Ví dụ</summary>

```C
for (int i =0; i<100; i=i+2 )
{
   printf("test:%d\n",i);
   if(i==50){
	break;// i chạy tới 50 sẽ thoát ra khỏi vòng for
   }
}
```
```C
for (int i =0; i<100; i=i+2 )
{
   
   if(i==50){
	continue;// khi i tới 50 , sẽ bỏ qua 50 , chạy tới giá trị i=52
   }
   printf("test:%d\n",i);
}
```
- Vòng lặp for vô hạn:
```C
int i=0;
for (;; )
{
   i++;
   printf("test:%d\n",i);
   if(i==50){
	beak;// nếu không có break thì vòng lặp chạy vô hạn
   }
   
}
```
 </details>


**Vòng lặp while:**
- Cú pháp:
```C
while ( điều kiện lặp đúng )
{
   // các lệnh cần lặp
}
```
- Ví dụ:
```C
int i =0;
while ( i <10 )
{
   printf("test:%d\n",i);
   i++;   
}
```
- While được sử dụng khi
**Vòng lặp do-while:**
- Cú pháp:
```C
do{
	// các lệnh cần lặp
}
while ( điều kiện lặp đúng );
 
```
 
- do-while :Lệnh làm trước sau đó mới so sánh điều kiện 

  

</details>
<details>
  <summary><h3>Kiểu dữ liệu</h3></summary>

**Biến không đổi (Constant Variables):** 
- Lưu trữ giá trị không thay đổi trong suốt thời gian chương trình chạy.Biến này sẽ lưu vào vùng nhớ TEXT
    ```const int MAX_VALUE = 100;```

**Biến Extern:**
- Từ khóa extern được sử dụng để khai báo một biến mà đã được định nghĩa bên ngoài chương trình hoặc tệp tin.
- Biến extern không tạo ra bộ nhớ mới cho biến.Biến được tham chiếu phải được khai báo toàn cục. 
- Lưu ý: khi sử dụng extern, không được khai báo giá trị ban đầu cho biến

 <details>
<summary>Ví dụ</summary>
- File 1 ta khai báo
```C
int GlobalVariable = 0; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}
```
- File 2, chúng ta extern biến đó để sử dụng

```C
extern int GlobalVariable; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}; 
```
 </details>


**Biến register:**
- Trong các yêu cầu tính toán quan trọng.  Từ khóa register để báo cho chương trình biết một biến sẽ đc lưu trữ trong thanh ghi (register) của CPU để tối ưu hiệu suất, giảm thời gian xử lý.
    `register int counter = 0;`
- Giải thích :Nếu khai báo biến thông thường để tính toán không có từ khóa register , thực hiện một phép tính thì cần có 3 bước.
	- Ví dụ: `int a = 6.Ví dụ :a có địa chỉ là 0X01,  a=a+4`
	- B1:Lưu địa chỉ và giá trị của biến vào bộ nhớ RAM : `0X01=6;` 
	- B2:Sau đó chuyển từ Ram qua thanh ghi(register)
	- B3:Từ register chuyển qua ALU (Arithmetic Logic Unit) ,để tính toán.Sau khi tính toán xong thì lại chuyển ngược về register>> về RAM

- Khi thêm từ khóa register để khai báo biến, biến sẽ được lưu vào register thay vào RAM >> tốc độ xử lý sẽ nhanh hơn
- Hạn chế dùng register vì thanh ghi có giới hạn (32 bit là 4 byte , 64 bit là 8 byte ) >> chỉ lưu những biến quan trọng , cần tính toán nhanh

**Biến volatile:** Thông báo cho trình biên dịch rằng giá trị của biến này không tối ưu , nếu tối ưu thì sẽ không đúng kết quả của người code
- Ví dụ:
```C
   	int main() {
    volatile int sensorValue;

    while (1) {
        // Đọc giá trị từ cảm biến (sensor)
        sensorValue = readSensor();

        // Xử lý giá trị cảm biến
        processSensorValue(sensorValue);
    }

    return 0;
}
```
- Cảm biến thay đổi liên tục, giá trị có thể giống nhau. Tuy nhiên,nếu không có volatile tính năng tối ưu code của compiler, nó sẽ hiểu rằng các biến như vậy dường như không thay đổi giá trị nên compiler có xu hướng loại bỏ để có thể tối ưu kích cỡ file code .
 
**Biến kiểu định danh (Typedef Variables):** Tạo ra một tên mới cho một kiểu dữ liệu đã tồn tại để sử dụng dễ dàng hơn.
```C
    typedef int Integer;
    Integer number = 42;
```



**Biến liệt kê (Enum Variables):** Lưu trữ một trong các giá trị được xác định trước từ một tập hợp các giá trị có tên.
- Thông thường enum đi chung với typedef và switch-case
- Cú pháp:
```C
	typedef enum {
        RED, 
        GREEN,
        BLUE
    } color;
	void hienthi(color mau)
	{
		switch (mau){
			case RED:
			printf("mau do");
			break;
			case BLUE:
			printf("mau xanh");
			break;


		}

	}
		
	int main(){
		color mau;
		mau = red;
		hienthi(mau);
	 
		return 0;
	}

```



**Biến cấu trúc (Structure Variables):** 
- Lưu trữ các thành phần có liên quan vào một biến:

```C
	typedef struct {
    	float x1;
    	float x2;
	} nghiem;// chỗ này định danh lại 
	 
	nghiem ptbac2(int a , int b , int c){
		nghiem test;//nghiem là kiểu dữ liệu , test là biến
		test.x1 =20.3;
		test.x2 =14.2;
		return test;

	}
	int main(){
		nghiem phuongtrinh = ptbac2(2,3,4);
		printf("x1:%f",phuongtrinh.x1);
		printf("x2:%f",phuongtrinh.x2);
	 
		return 0;
	}
```
</details>
<details>
  <summary><h3>Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động</h3></summary>
	
### Phân vùng bộ nhớ trên RAM(Memory layout)
- Chương trình main.exe trên window  hoặc main.hex với VĐK (lưu ở bộ nhớ SSD hoặc FLASH). 
- Khi nhấn run chương trình trên window hoặc cấp nguồn cho vi điều khiển thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.


| Stack |
|:-----:|
|   ↓   |
|   ↑   |	
|  Heap |
|  Bss(Uninitialized data)  |
|  Data(Initialized data)   |
|  Text |
- ***Text:*** Quyền truy cập chỉ có thể Read( không thay đổi)
	- Lưu các hằng số :`const int x =2` 
	- Kích thước là cố định
	- Nó chưa lệnh thực thi :Mã assembly...
- ***Data:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục đã dc khởi tạo hoặc biến static khác 0:`int a=1, int b=2;`
	- Được giải phóng khi kết thúc chương trình
	- Kích thước có thể thay đổi
- ***Bss:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục chưa khởi tạo, hoặc bằng 0:`int a=0, int b;`
	- Các biến static bằng 0 hoặc chưa khởi tạo
	- Được giải phóng khi kết thúc chương trình
	- Kích thước có thể thay đổi
- ***Stack:*** Quyền truy cập là Read-Write.
	- lưu trữ các biến cục bộ.
	- Các tham số truyền vào và các giá trị trả về từ hàm.
	- Hàm main cũng ở vùng stack
	- Sẽ được giải phóng khi ra khỏi hàm
	- Kích thước cố định: phụ thuộc vào hệ điều hành, đối với Windows thường là 1MB, Linux là 8MB.
- ***Heap:*** Quyền truy cập là Read-Write.
	- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,...
	- Kích thước không cố định.
	- Sẽ được giải phóng khi gọi hàm free,...
	### So sánh Stack và Heap?
	- Bộ nhớ: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
		- Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
		- Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
	- Kích thước vùng nhớ:
		- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
		- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
	### Các cách sử dụng malloc, calloc, realloc, free:
	- ***Malloc:*** Cấp phát bộ nhớ động mỗi phần tử, không khởi tạo giá trị, trả về con trỏ NULL khi cấp phát thành công.
	- ***Calloc:*** Cấp phát bộ nhớ động và khởi tạo cho các phần tử là 0, trả về con trỏ NULL khi cấp phát thành công.
	- ***Realloc:*** Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ NULL khi thay đổi thành công.
	- Vậy `Malloc` sẽ nhanh hơn `Calloc`
	- Ví dụ:

	```C
	int main() {
    int *arr_malloc, *arr_calloc;
    size_t size = 5;

    // Sử dụng malloc
    arr_malloc = (int*)malloc(size * sizeof(int));

    // Sử dụng calloc
    arr_calloc = (int*)calloc(size, sizeof(int));

    // Sử dụng Realloc
	arr_malloc = (int*)realloc(arr_malloc, sizeof(int) * 7); // size arr_malloc lúc này là 7


    // Giải phóng bộ nhớ
    free(arr_malloc);
    free(arr_calloc);

    return 0;
	}
	```
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;
    char* ten = (char*) malloc(sizeof(char) * soluongkytu)
    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);
        printf("Hello %s\n", ten);
    }

}

```

</details>


- Đặc điểm vùng nhớ
	- Stack: 
		- vùng nhớ Stack được quản lý bởi hệ điều hành, 
		- Dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
	- Heap: k
		- Kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu ,
		- Dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
### Lưu ý: 
- Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
- Vấn đề lỗi xảy ra đối với vùng nhớ Stack: Bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,..
	- Ví dụ về tràn bộ nhớ stack với hàm đệ quy vô hạn:
	```C
	int foo(int x){
		printf("De quy khong gioi han\n");
		return foo(x);
	}
	```
- Vấn đề lỗi xảy ra đối với vùng nhớ Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
	- Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
	```C 
	int *A = (int *)malloc(18446744073709551615); 
	```

- ***Realloc:*** Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ NULL khi thay đổi thành công
```C
void* realloc(void* ptr, size_t size);
```
- ***Free:*** Giải phóng bộ nhớ đã được cấp phát bằng Malloc, Calloc, Realloc sau khi sử dụng xong, không có trả về
```C
void free(void* ptr);
```
### Khác nhau của static cục bộ và static toàn cục:

- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.Biến static sẽ lưu vào vùng nhớ Data/ Bss, được giải phóng khi kết thúc chương trình.

- Ví dụ:

```C
 	#include <stdio.h>
	void printMessage() {
    static int count = 0;
    // Tăng giá trị biến mỗi lần hàm được gọi
    count++;
    printf("Count: %d\n", count);
	}

	int main() {
    // Gọi hàm có sử dụng biến static
    printMessage();//
    printMessage();

    return 0;
	}// KQ:Count: 1,Count: 2

```

- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.
- Ví dụ:globalStaticVar được khai báo là static và nằm trong file "File1.c". Do đó, bạn không thể trực tiếp truy cập nó từ file "File2.c", bằng extern int globalStaticVar; trong File2.c, chương trình sẽ không biên dịch được và thông báo lỗi.
- Biến cục bộ: Biến cục bộ sẽ được lưu vào vùng nhớ stack, thu hồi khi kết thúc hàm cục bộ. 

</details>
<details>
  <summary><h3>Struct và Union</h3></summary>

**Struct và Union là 2 cấu trúc dữ liệu do lập trình viên định nghĩa bao gồm các biến với kiểu dữ liệu khác nhau.Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:**
**struct:** Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
- Ví dụ:
  ```C 
  #include <stdio.h>
  #include <conio.h>
  struct date
	{
		int d;
		int m;
		long y;
	};
  void main()
	{
		date dat = {4, 4, 2016};
		printf("\nSize of struct: %d", sizeof(date));//size 12
	
		printf("\ndate = %d", dat.d);//date=4
		printf("\nmonth = %d", dat.m);//month =4
		printf("\nyear = %d", dat.y);//year=2016
	
		getch();
	
	} 
	```

**Tại cùng 1 thời điểm run-time, có thể truy cập vào tất cả các thành phần của struct**
**Struct padding :** Chèn thêm các vùng nhớ trống giữa các member để đảm bảo việc dữ liệu trong struct được natually aligned(các thao tác đọc ghi trong bộ nhớ nhanh hơn )
> Ví dụ:
![Struct_Padding](./Struct_Padding.PNG)
![Struct_Padding](./Struct_Padding(2).PNG)
- Như vậy đối với struct B kích thước của nó sẽ là 16 bytes, trong đó có 14 bytes được sử dụng và 2 bytes bị padding. Chúng ta thấy rằng việc sắp xếp thứ tự các phần tử của struct có thể giúp cho việc xử dụng tài nguyên RAM trở lên hiệu quả hơn, tránh bị tốn quá nhiều bytes cho quá trình padding.

	**Sử dụng Struct khi bạn muốn lưu trữ nhiều thông tin có liên quan với nhau:**

	- Ví dụ: Một hồ sơ người dùng có tên, tuổi, địa chỉ, v.v.

	**Khi bạn muốn lưu trữ dữ liệu với các loại dữ liệu khác nhau:**
	- Ví dụ: Một khối dữ liệu đại diện cho một ngày gồm ngày, tháng, năm là các kiểu dữ liệu khác nhau.

	**Khi bạn muốn có một cấu trúc dữ liệu linh hoạt, mà mỗi thành phần có thể được truy cập một cách dễ dàng:**
	- Ví dụ: Các thành phần của một hình học như điểm, đường, v.v.

	**Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là size lớn nhất của kiểu dữ liệu trong union.**
	- cho phép lưu trữ các biến khác nhau trong cùng một vị trí bộ nhớ. Khi một giá trị mới được gán cho union, giá trị trước đó được ghi đè. Điều này có nghĩa là union chỉ lưu trữ một giá trị duy nhất tại một thời điểm.
	 
	- ví dụ 1:
	```C
	#include <stdio.h>
	#include <conio.h>
 
	union date
	{
		int d;
		int m;
		int y;
	};
 
	void main()
	{
		date dat;
	
		printf("\nSize of union: %d", sizeof(date));//4
		dat.d = 24;
		dat.m = 9;
		dat.y = 2014;
	
		printf("\ndate = %d", dat.d);//2014
		printf("\nmonth = %d", dat.m);//2014
		printf("\nyear = %d", dat.y);/2014
	
		getch();
	}
	```
 - Vùng nhớ dành cho union date là 4 byte. Vùng nhớ này sẽ chứa giá trị 24 khi dat.d = 24 được thực hiện. Tiếp đó, 9 sẽ được copy đè vào vùng nhớ này khi dat.m = 9 được thực hiện. Cuối cùng, 2014 được copy đè vào vùng nhớ khi dat.y = 2014 được thực hiện.
 **Tại cùng 1 thời điểm run-time, chỉ có thể truy cập 1 thành phần của union**

- ví dụ 2:

  ```C
  #include <stdio.h>
  #include <conio.h>
  union date
  {
    int d;
    int m;
    int y;
  };
 
  void main()
  {
		date dat;
	
		printf("\nSize of union: %d", sizeof(date));//4
		
		dat.d = 24;
		printf("\ndate = %d", dat.d);//24
	
		dat.m = 9;
		printf("\nmonth = %d", dat.m);//9
	
		dat.y = 2014;
		printf("\nyear = %d", dat.y);//2014
	
		getch();
  }
  ```
- Khác với VD1 ,các giá trị được gọi lần lượt , cứ mỗi lần kết thúc giá trị sẽ có 1 giá trị mới được ghi đè vào

**Sử dụng Union khi bạn muốn tiết kiệm bộ nhớ và chỉ lưu trữ một giá trị tại một thời điểm:**
- Khi bạn gán một thành viên, các giá trị của các thành viên khác sẽ thay đổi.

</details>
<details>
  <summary><h3>Macro,Function</h3></summary>

 **Macro là gì?**

 - Marco là 1 tên bất kì trỏ tới 1 khối lệnh thực hiện một chức năng nào đó.

 - Được xử lý bởi preprocessor(tiền xử lý)

 - Định nghĩa macro bằng lệnh #define

 - VD: Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng
 	```C
    #define SUM(a,b)     (a+b)
	int main(){
		printf("tong a,b la %d\n",sum(1,2));
		return 0;
	}
    ```

**Hàm là gì?**
 - Function là 1 khối lệnh thực hiện một chức năng nào đó.
   ```C
   int SUM(int a,int b) {//0xc1 >>0XC7
		return a+b;
   }
	     
   int main(){
		//OX00>>0X04
		printf("tong a,b la %d\n",sum(1,2));//OXO5  //stack pointer:0X05
		printf("tong a,b la %d\n",sum(2,2));//0XO7  //program counter 0xc1
		return 0;
   }
   ```
    

### So sánh Macro, Function:
**Giống nhau** : Cả hai được sử dụng để thực hiện một chức năng nào đó và có thể nhận tham số đầu vào
**Khác nhau**:
- Macro không cần quan tâm kiểu dữ liệu của tham số đầu vào
- Function phải chỉ rõ kiểu dữ liệu của tham số đầu vào
- Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch .Giả sử 1 macro là 1 byte được gọi 20 lần >> 20 byte trong hàm main ,20 dòng code sẽ được chèn vào trong quá trình tiền xử lí. Điều này làm tốn kich thước nhưng time xử lý ngắn hơn( chỉ copy -paste vào chương trình) .

- khi khởi tạo hàm ,RAM chỉ tốn 1 bộ nhớ cố định để lưu , Giả sử hàm được gọi 20 lần, cũng sẽ chỉ tốn 1 bộ nhớ như vậy. Nhưng khi gọi hàm có thể tốn thêm thời gian do quá trình gọi hàm và quay lại vị trí ban đầu.



</details>
<details>
  <summary><h3>Con trỏ(pointer)</h3></summary>

**Con trỏ là gì** 
- Là 1 biến ,không lưu giá trị bình thường, nó lưu địa chỉ.
- Cách khai báo con trỏ:<kiểu dữ liệu> * <tên biến>
- kiểu dữ liệu con trỏ phải trùng kiểu dữ liệu biến nó trỏ tới.
- Ví dụ:
```C
 int main(){
	int a =10;
	int *ptr =&a;//&lấy địa chỉ
	return 0;
 }

```



- Nếu không dùng con trỏ thì giá trị a,btrong hàm cục bộ sẽ bị thu hồi ,
và giá trị x,y không thay đổi được.
- Ví dụ bài toán hoán vị:
```C
	int swap(int *a, int *b) {
		int temp;
		temp=*a;
		*a=*b;
		*b=temp;
		printf("dia chi cua a la : %p\n",a);
		printf("gia tri cua a la : %d\n",*a);
	}
	int subtract(int a, int b) {
		return a - b;
	}

	int main() {
	
		int x,y;
		x=20;y=15;
		swap(&x,&y);
		printf("%d,%d",x,y);

		return 0;
	}
```


- Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
- Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
		- `Môi trường Windows 32 bit: 4 bytes`
        - `Môi trường Windows 64 bit: 8 bytes`

### Các loại con trỏ:

- ***Con trỏ hàm (Function Pointers):*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.
	```c
	void tong (int a, int b){
		printf("tong %d va %d = %d\n",a,b,a+b);
	}
	void hieu (int a, int b){
		printf("tong %d va %d = %d\n",a,b,a-b);
	}

	 

	int main() {
		void (*ptr)(int, int);
		ptr =&tong;
		ptr(8,6);
	 

		return 0;
	}

	```
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
	int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p4 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int x = 10;
    int *p1 = &x;     // Con trỏ p1 trỏ đến biến x và giá trị của p1 chỉnh là địa chỉ của biến x
    int **p2 = &p1;	 // Con trỏ p2 trỏ đến con trỏ p1 và lưu địa chỉ của con trỏ p1 vào p2  

    printf("Giá trị của x: %d\n", *p1); //Giá trị của x: 10
    printf("Địa chỉ của x: %p\n", p1); //Địa chỉ của x: 0x7ffee2a697a8 
    printf("Giá trị của x: %d\n", **p2); //Giá trị của x: 10
    printf("Địa chỉ của p1: %p\n", p2); //Địa chỉ của p1: 0x7ffee2a697a0
	```
- ***Con trỏ hằng (Constant Pointers):*** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.
	```c
	int num = 10; 
	const int *ptr = &num; //thay đổi được địa chỉ của num nhưng không thay đổi được giá trị '10' của num
	```
- ***Con trỏ void (Void Pointers):*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.


	```c
	int num = 10;
	float f = 3.14;
	void *ptr;
	ptr = &num;
	printf("num = %d\n",(int*)ptr);
	ptr = &f;
	printf("f = %f\n",(float*)ptr);
	```

- ***Con trỏ vào hàm (Pointers to Functions):*** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.
	```C
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	void performOperation(int a, int b, int (*operation)(int, int)) {
		int result = operation(a, b);
		printf("Result: %d\n", result);
	}

	int main() {
		int a = 5, b = 3;

		performOperation(a, b, add);
		performOperation(a, b, subtract);

		return 0;
	}

	```
- ***Con trỏ hàm parameter (Function Pointer Parameters):*** Truyền một hàm như một tham số cho một hàm khác.
	```C
	void greet() {
		printf("Hello, World!\n");
	}

	void performAction(void (*action)()) {
		action();
	}

	int main() {
		performAction(greet);

		return 0;
	}

	```
### Lưu ý khi sử dụng con trỏ
- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.

### Tác dụng của con trỏ

- Chúng ta có thể sử dụng con trỏ để thay đổi giá trị vùng con trỏ trỏ đến.
- Giả sử mình khởi tạo 1 biến số c.
```c
int c = 22; // khởi tạo giá trị ban đầu của c = 22
```
- Vậy chúng ta có bao nhiêu cách để thay đổi giá trị biến c.
- Cách 1: thay đổi trực tiếp
`c = 11;`
- Cách 2: thay đổi gián tiếp qua 1 con trỏ
```c
int *pc = &c;    // trỏ con trỏ pc tới vùng nhớ của biến c
*pc = 11;        // *pc tương đương với giá trị của biến c 
```
</details>
 
<details>
  <summary><h3>Mảng</h3></summary>

**Mảng:**

- Mảng (array) là các phần tử có kiểu dữ liệu đồng nhất. Các phần tử của mảng được lưu trong các vùng nhớ liên tiếp
- Một mảng thực sự là một con trỏ hằng (constant pointer) trỏ tới địa chỉ của phần tử đầu tiên trong mảng.
- Khai báo:
```- Kiểu dữ liệu tên mảng[]={};```
- Ví dụ :

 ```C
	 uint8_t mang[]={1,2,3,4,5};// kieu du lieu 8 bit >> 1 byte ,2 phan tu cach nhau 1 byte, mảng là 1 dãy địa chỉ 

	int main() {
		uint8_t *ptr=mang;// địa chỉ ô nhớ đầu tiên
		printf("gia tri:%d\n",*ptr);// in ra =1
		uint8_t *ptr=mang +1;
		printf("gia tri:%d\n",*ptr);// in ra =2
		
	
		 for(int i=0;i<5;i++){
			printf("Dia chi cua mang[%d]=%p, gia tri:%d",i,&mang[i],*i);
		 }
		// Thông qua con trỏ để biểu diễn mảng
		 for(int i=0;i<5;i++){
			printf("Dia chi cua mang[%d]=%p, gia tri:%d",i,ptr+i,*(ptr+i);
		 }
		return 0;
	}
```
**Chuỗi:**

- Chuỗi là một tập hợp các ký tự (char) được lưu trữ trên các ô nhớ liên tiếp và luôn luôn có 1 ký tự null là \0 báo hiệu kết thúc chuỗi.
- Chú ý : Khi khai báo không để số trong[] , hãy để compiler tự làm
```C
char c[5] = "abcde"; // sai
```

- ví dụ:
 ```C
 	char arr[]="hello word"; 
	void doc_mang(char text[]){
		text[0]='a';
		text[1]='b';
	}
// vì chuỗi là 1 dãy địa chỉ , nếu ta làm như trên, nó sẽ thay đôi 
	

	int main() {
		doc_mang(arr);
		 for(int i=0;i<16;i++){
			printf("ky tu :%c, ma hex :0x%x, ",arr[i],arr[i] );
		 }

	// in ra la "abllo word"
		 
		return 0;
	}
```




</details>
</details>



<details>
  <summary><h1>▶ ⭐C Advance </h1></summary>


<details>
  <summary><h2>Quá trình biên dịch</h2></summary>
	
Quy trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang  ngôn ngữ máy , để máy tính có thể hiểu và thực thi.
### Quá trình biên dịch bao gồm 4 giai đoạn:
- Giai đoàn tiền xử lý (Pre-processor)
- Giai đoạn dịch NNBC sang Asembly (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
- Giai đoạn liên kết (Linker)
![compiler](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/439abd04-d8d2-4f2c-97a5-be7f5074fe39)

	
**_Pre-processor (Giai đoạn tiền xử lý):_**
- 1 Project có nhiều file:`a.h, b.h, a.c, b.c `và file `main.c` sau quá trình tiền xử lý thành 1 file duy nhất là file `main.i`.
- Lệnh trong CMD là: `gcc -E main.c -o main.i`

**3 việc xảy ra trong quá trình tiền xử lý:**
- Nhận mã nguồn
- Xóa bỏ cmt,ghi chú.
- Chỉ thị tiền xử lý (bắt đầu bằng #) được xử lý.
	- Chỉ thị tiền xử lý dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý ( Preprocessor). Chia làm 3 nhóm chính:
	- `#include`:Chỉ thị `#include` dùng để chèn nội dung của một file vào mã nguồn chương trình
	- `#define, #undef`:Macro được định nghĩa bằng cách dùng `#define` .Macro là từ dùng để chỉ những thông tin được xử lý ở tiền xử lý
	
		- ví dụ:
		```C
		#define display_sum(a,b) \ // xuống dòng
			printf("this is macro to sum 2 number \n");\
			printf("result is:%d \n",a+b);// dòng cuối cùn không cần\

		int main(){
			display_sum(5,6);
			return 0;
		}
		```
	
	- `#undef`:
		- Dùng để hủy định nghĩa 1 macro đã dc định nghĩa trước đó bằng `#define`.
		- Nếu hai hoặc nhiều tệp tiêu đề có cùng tên macro, chúng có thể xung đột với nhau. Việc sử dụng các chỉ thị này giúp ngăn chặn các xung đột này.

		- ví dụ:
		```C
		#include <stdio.h>
		#include "nhietdo.c"
		#include "doam.c"
		// trong 2 file đều có macro lần lượt là:
		//#define cam_bien 10(nhietdo.c)
		//#define cam_bien 20(doam.c)

		int main(){
			#undef cam_bien
			#define cam_bien 40
			return 0;
		}
		```
	- `#if, #elif, #else, #ifdef, #ifndef`
	- `#if`: Sử dụng để bắt đầu 1 điều kiện tiền xử lý.Nếu đúng thì các dòng lệnh sau `#if` sẽ được biên dịch , sai sẽ bỏ qua đến khi gặp`#endif`.
	- `#elif`: Để thêm 1 ĐK mới khi `#if` hoặc `#elif` sai.
	- `#else`: Dùng khi không có ĐK nào đúng
	- `#ifdef` : Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu định nghĩa rồi thì mã sau ifdef sẽ được biên dịch.
	- `#ifndef`: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu chưa định nghĩa thì mã sau ifndef sẽ được biên dịch.Thường dùng để kiểm tra macro đó đã dc định nghĩa trong file nào chưa, kết thúc thì `#endif`
	- ví dụ:
		```C

		#define max 6
		#if max ==20
		int a =10;
		#elif max <20
		int a =6;
		#endif
		#include <stdio.h>
		int main()
		{
			printf("a bang %d",a);// a bằng 10
			return 0;
		}

		```

	**Mục đích để tránh Định Nghĩa Nhiều Lần và Xung Đột**
	- Ví dụm trong 1 file `main.h`
	```C
	#ifndef __MAIN_H__
	#define __MAIN_H__
	#include<stdio.h>
	#endif 
	```
	- 1 số toán tử trong Macro: 
		- #define STRINGSIZE(x) #x
		- Ví dụ:
			```C
			#define STRINGSIZE(x) #x
			#define DATA 40

			int main(){
				prinf("the value: %s\n",STRINGSIZE(DATA));
				return 0;
			// sẽ in ra the value: DATA
			}
			```
		- Variadic Macro: Là 1 macro cho phép nhận 1 số lượng biến tham số có thể thay đổi
		<details>
		<summary>Ví dụ:</summary>
		
		```C

			#include <stdio.h>

			#define print_menu_item(...) \
				do { \
					const char *items[] = {__VA_ARGS__}; \
					int n = sizeof(items) / sizeof(items[0]); \
					for (int i = 0; i < n; i++) { \
						print_menu_item(i + 1, items[i]); \
					} \
				} while (0)

			#define case_option(number, function) \
				case number: \
					function(); \
					break;

			#define handle_option(option, ...) \
				switch (option) { \
					__VA_ARGS__ \
					default: \
						printf("Invalid option!\n"); \
				}

			void print_menu_item(int number, const char *item) {
					printf("%d. %s\n", number, item);
				}

			void feature1() { printf("Feature 1 selected\n"); }
			void feature2() { printf("Feature 2 selected\n"); }
			void feature3() { printf("Feature 3 selected\n"); }
			void feature4() { printf("Feature 4 selected\n"); }

			int main() {
				print_menu_item("Option 1", "Option 2", "Option 3", "Option 4", "Exit");

				int option;
				scanf("%d", &option);

				handle_option(option,
							case_option(1, feature1)
							case_option(2, feature2)
							case_option(3, feature3)
							case_option(4, feature4)
				)

				return 0;
		```
		</details>

- **_Compiler (Giai đoạn dịch NNBC sang ngôn ngữ Assembly):_** 
	-  Quá trình này compiler sẽ biên dịch từ file `.i` sang file ngôn ngữ assembly là file `.s`.
	-  Dùng lệnh `gcc -S main.i -o main.s`.
- **_Assembler (Giai đoạn dịch ngôn ngữ Assembly sang ngôn ngữ máy):_** compiler sẽ Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o` 
	-  Dùng lệnh `gcc -c main.s -o main.o` để tạo ra file ".o" 
- có thể tạo thành file.hex từ file.o  
`objcopy -O ihex main.o main.hex `
- objcopy: là công cụ được sử dụng để thực hiện việc chuyển đổi.
- File hex chứa thông tin về mã máy, địa chỉ bắt đầu dữ liệu, kích thước và dữ liệu của chương trình, và thường được sử dụng để nạp chương trình vào bộ nhớ của thiết bị nhúng.


- **_Linker (Giải đoạn liên kết):_** 
	- 1 hoặc nhiều file.o sẽ được compiler liên kết lại 1 File  `.exe`.
	- File này để hệ điều hành chạy
	- Dùng lệnh `gcc  main.o -o filename` để tạo ra tệp thực thi .

</details>
<details>
  <summary><h2>Stdargt - Assert</h2></summary>

- **Stdargt:** 
- Cú pháp: `#include<stdarg.h>`
- Cung cấp các macros để xử lý các hàm có số lượng đối số biến đổi. 
- Đối số biến đổi (variadic arguments) là các đối số mà một hàm có thể nhận với số lượng không xác định.

- va_list  để khai báo một biến sẽ trỏ tới các đối số không xác định.
	+ Ví dụ: va_list args;
- va_start:  Khởi tạo danh sách các đối số biến đổi.
 	+ Nó nhận hai tham số: biến va_list và tên của đối số cuối cùng có kiểu xác định
	+ Ví dụ: va_start(args, last_arg);
- va_arg:  Truy xuất từng đối số từ danh sách các đối số biến đổi.
	+ Nó nhận hai tham số: va_list và kiểu dữ liệu của đối số cần lấy
	+ Nó trả về giá trị của đối số và di chuyển va_list đến đối số tiếp theo
	+ Ví dụ: double val = va_arg(args, double);
- va_end: Kết thúc việc sử dụng danh sách các đối số biến đổi
	+ Ví dụ: va_end(args);

<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdarg.h>

void example(int count, ...) {
    va_list args;
    va_start(args, count);
    
    // Lấy giá trị của đối số biến đổi thứ nhất
    int value1 = va_arg(args, int);
    printf("Value 1: %d\n", value1);
    
    // Lấy giá trị của đối số biến đổi thứ hai
    int value2 = va_arg(args, int);
    printf("Value 2: %d\n", value2);

    // Lấy giá trị của đối số biến đổi thứ ba
    int value3 = va_arg(args, int);
    printf("Value 3: %d\n", value3);

    // Lấy giá trị của đối số biến đổi thứ tư
    int value4 = va_arg(args, int);
    printf("Value 4: %d\n", value4);

    va_end(args);
}

int main() {
    example(4, 1, 2, 3, 4);
    return 0;
}


```

</details>

<details>
<summary>Ví dụ 2:</summary>

```C++
#include <stdio.h>
#include <stdarg.h>


typedef struct Data
{
    int x;
    double y;
} Data;

void display(int count, ...) {

    va_list args;

    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; i++)
    {
        Data tmp = va_arg(args,Data);
        printf("Data.x at %d is: %d\n", i,tmp.x);
        printf("Data.y at %d is: %f\n", i,tmp.y);
    }
   

    va_end(args);


}

int main() {


    display(3, (Data){2,5.0} , (Data){10,57.0}, (Data){29,36.0});
    return 0;
}

```
</details>
<details>
<summary>Ví dụ 3:</summary>

- Bài toán thực tế, làm sao viết 1 hàm chung , để phù hợp với bất kỳ số lượng tham số đầu vào.
- cảm biến độ ẩm 2 tham số , nhiệt độ 3 tham số >> cần 1 hàm phù hợp 

```C
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR
} SensorType;// đầu tiên định nghĩa 1 enum

void processSensorData(SensorType type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
        case TEMPERATURE_SENSOR: {// khi có bài toán lựa chọn thì dùng switch..case
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            float temperature = va_arg(args, double); // float được promote thành double
            printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* additionalInfo = va_arg(args, char*);
                printf("Additional Info: %s\n", additionalInfo);
            }
            break;
        }
        case PRESSURE_SENSOR: {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            int pressure = va_arg(args, int);
            printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* unit = va_arg(args, char*);
                printf("Unit: %s\n", unit);
            }
            break;
        }
    }

    va_end(args);
}

int main() {
    processSensorData(TEMPERATURE_SENSOR, 3, 1, 36.5, "Room Temperature");
    processSensorData(PRESSURE_SENSOR, 2, 2, 101325);
    return 0;
}

```
</details>

- **assert:** 
	- Cung cấp macro assert. 
	- Macro này được sử dụng để kiểm tra một điều kiện. 
	- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
	- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
	- Dùng trong debug, dùng #define NDEBUG để tắt debug
	- Tóm lại, assert thường được sử dụng để kiểm tra điều kiện và kết thúc chương trình khi có lỗi 
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <assert.h>
int main() {   
	int x = 5;    
	assert(x == 5);    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
	printf("X is: %d", x);  
	return 0;
}

```
</details>

-Thông thường trong thực tế sẽ code:
<details>
<summary>Ví dụ:</summary>

```C
#define LOG(condition, cmd) assert(condition && #cmd);
int main{
	int x=0;
	LOG(x>5,x phai lon hon 5);
}
```

Hoặc

```C
#include <assert.h>
#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level) {
    ASSERT_IN_RANGE(level, 1, 31);
    // Thiết lập cấp độ
}
int main(){
	int x=45;
	int day =5;
	ASSERT_IN_RANGE	(day,0,31);// day <31 thì sẽ thực hiện code tiếp theo
	//sai thì thông báo 
	printf("day bang %d\n",day);

}

```
</details>

</details>
<details>
  <summary><h2>Pointer</h2></summary>

- Con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.
- Thông qua con trỏ có thể thay đổi giá trị tại biến mà nó trỏ tới

- Cách khai báo:

```C
int x = 10;
int *ptr = &x;  // ptr giờ đây chứa địa chỉ của x
*ptr =5;
>> x bằng5
```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch.
- `Môi trường Windows 32 bit: 4 bytes`
- `Môi trường Windows 64 bit: 8 bytes`

```C
int main()
{
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));    
    return 0;

}

```
- Ứng dụng để truyền tham trị .
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

// Hàm swap: Đổi giá trị của hai biến sử dụng con trỏ
void swap(int *a, int *b)
{
    int tmp = *a;   // Lưu giá trị của biến a vào biến tạm thời tmp
    *a = *b;        // Gán giá trị của biến b cho biến a
    *b = tmp;       // Gán giá trị của biến tạm thời tmp (ban đầu là giá trị của a) cho biến b
}

// Hàm main: Hàm chính của chương trình
int main()
{
    int a = 10, b = 20; // Khai báo và khởi tạo hai biến a và b

    swap(&a, &b);       // Gọi hàm swap để đổi giá trị của a và b

    // In ra giá trị của a và b sau khi đã đổi giá trị
    printf("value a is: %d\n", a);
    printf("value b is: %d\n", b);

    return 0; // Kết thúc chương trình
}

```
</details>

**Các loại con trỏ**
- Con trỏ hàm(Hàm con trỏ)
- Con trỏ void.
- Con trỏ hằng.
- Hằng Con trỏ .
- Con trỏ trỏ tới con trỏ.
- Con trỏ NULL.

**Con trỏ hàm**
- Hàm (function) bản chất là 1 địa chỉ vùng nhớ
- Con trỏ hàm lưu trữ địa chỉ của một hàm, tương tự như cách mà con trỏ thông thường lưu trữ địa chỉ của biến.
- Bạn có thể sử dụng con trỏ hàm để gọi hàm hoặc chuyển nó như một tham số cho hàm khác.

**Chức năng**
- Gọi hàm thông qua con trỏ: Thay vì gọi hàm trực tiếp,có thể gọi thông qua con trỏ hàm.
- Chuyển hàm làm tham số: Một hàm có thể nhận con trỏ hàm làm tham số để quyết định hàm nào sẽ được gọi trong quá trình thực thi.
 <details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

// Hàm mẫu
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Khai báo con trỏ hàm với cú pháp: <kiểu dữ liệu trả về> (*<tên con trỏ>)(<kiểu dữ liệu đối số 1>, <kiểu dữ liệu đối số 2>, ...)
    int (*operation)(int, int);

    // Gán địa chỉ của hàm add cho con trỏ hàm
    operation = add;

    // Sử dụng con trỏ hàm để gọi hàm add
    printf("Result: %d\n", operation(5, 3)); // In ra: Result: 8

    // Gán địa chỉ của hàm subtract cho con trỏ hàm
    operation = subtract;

    // Sử dụng con trỏ hàm để gọi hàm subtract
    printf("Result: %d\n", operation(5, 3)); // In ra: Result: 2

    return 0;
}

```
</details>

**Hàm con trỏ**
- Hàm con trỏ là một hàm mà tham số của nó là một con trỏ hàm.
- Điều này cho phép bạn truyền một hàm cụ thể vào một hàm khác để thực hiện các tác vụ động linh hoạt
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
// Hàm con trỏ làm tham số cho một hàm khác
void processNumbers(int (*operation)(int, int), int a, int b) {
    int result = operation(a, b);
    printf("Result: %d\n", result);
}

// Hàm mẫu 1
int add(int a, int b) {z
    return a + b;
}

int main() {
    int a = 10, b = 5;
    processNumbers(add, a, b);
    

    return 0;
}
```
</details>

**Con trỏ void**
- Void Pointer có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
- Vì nó không có thông tin về loại dữ liệu mà nó trỏ tới
- Cách ép kiểu dữ liệu từ con trỏ Void:`(int*)(ptr)` đang ép về kiểu int.
- Dùng trong bài toán , nhiều kiểu dữ liệu mà không muốn dùng nhiều loại con trỏ trỏ tới chúng .
- Trong ví dụ bên dưới, con trỏ ptr trỏ tới tất cả các biến.
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a+b;
}

int main() {
   
    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

    void *ptr1[] = {&value, &test, &letter , sum, array};

    printf("value: %d\n", *(int*)ptr1[0]);

    printf("value: %c\n", *((char*)ptr1[4]+1));

    return 0;
}

```
</details>

**Con trỏ hằng- Pointer to Constant**
- không thể thay đổi giá trị tại biến mà nó đang trỏ đến.
- Thường  dùng khi làm việc với các vùng nhớ không được phép thay đổi
- Dùng để truyền tham số vào hàm mà không muốn hàm đó thay đổi giá trị  tham số.
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

// Hàm in mảng sử dụng con trỏ đến hằng
void printArray(const int *array, int size) {
	//array[0]=2;// lỗi
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {10, 20, 30, 40, 50};
    int size = sizeof(values) / sizeof(values[0]);

    // Gọi hàm printArray với con trỏ đến mảng values
    printArray(values, size);

    return 0;
}
// nếu không dùng con trỏ hằng thì có thể thay đổi được dữ liệu từ hàm

```
</details>


- So sánh:

| Con trỏ thường | Con trỏ hằng|
|-------|-------|
| Có thể thay đổi giá trị | không thể thay đổi giá trị |

```C
 int *ptr;// con trỏ thường
 const int *ptr1;//con trỏ hằng
 x=5;
 ptr=&x;
 *ptr=10;
 printf("x la %d",x);//x =10
 *ptr1 =10;//lỗi , vì nó làm thay đổi giá trị biến
```
**Hằng con trỏ- Constant Pointer**
- Khai báo:`int *const const_ptr = &value;`
- Đặc điểm:
	- muốn con trỏ luôn trỏ đến một đối tượng cụ thể trong suốt vòng đời của nó.
	- Khi hằng con trỏ đã trỏ đến 1 địa chỉ nào rồi,nó không thể trỏ tới bất kỳ 1 địa chỉ nào khác.
	- Có thể thay đổi được giá trị tại địa chỉ đã khởi gán ban đầu.

<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdlib.h>
int main() {    
	int value = 5;    
	int test = 15;    
	int *const const_ptr = &value;   
	printf("value: %d\n", *const_ptr);    
	*const_ptr = 7   
	printf("value: %d\n", *const_ptr);   
	const_ptr = &test; // LỖI vì đã cố định vào value
	return 0;
}
```

</details>


**Pointer to Pointer**
- là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 
- Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. 
- Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.

<details>
<summary>Ví dụ:</summary>

```C
int test = 5;	//Address: 0x01
			 	//Value:	5
int *ptr = &test;//Address: 0x02
			 	//Value:	0x01
int **ptr1=&ptr;//Address: 0x03
			 	//Value:	0x01

#include <stdio.h>

int main() {
    int x = 10;
    int *ptr1 = &x;  // Con trỏ ptr1 trỏ đến biến x
    int **ptr2 = &ptr1;  // Con trỏ ptr2 trỏ đến con trỏ ptr1

    printf("Địa chỉ x: %p\n", &x);   //Địa chỉ x: 0x7ffe88cb3ab4
    printf("gia tri ptr1: %p\n", ptr1);//gia tri ptr1: 0x7ffe88cb3ab4
    printf("Địa chỉ con trỏ ptr1: %p\n", &ptr1);//Địa chỉ con trỏ ptr1: 0x7ffe88cb3ab8
    printf("Giá trị của ptr2 (địa chỉ của ptr1): %p\n", ptr2)//Giá trị của ptr2 (địa chỉ của ptr1): 0x7ffe88cb3ab8

    return 0;
}

```
</details>

**NULL Pointer**
- Khai báo:`int *ptr = NULL; `
- NULL pointer là một con trỏ không trỏ đến bất kỳ vùng nhớ cụ thể nào.
- Trong vđk khởi tạo con trỏ phải gán NULL
- Trước khi xài thì phải kiểm tra nó là NULL hay không.
- Lý do nếu kiểm tra không phải là NULL thì con trỏ đang trỏ tới 1 giá trị nào đó ,Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) làm sai chương trình.
- Khi xài xong 1 pointer thì phải gán nó bằng Null, để tránh sử dụng giá trị cũ của con trỏ.

<details>
<summary>Ví dụ:</summary>

```C

#include <stdio.h>
int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    int score_game = 5;
    if (ptr == NULL)
    {
        ptr = &score_game;
        *ptr = 30;
        ptr = NULL;
    }
}

```
</details>


</details>
<details>
  <summary><h2>Từ khóa đặc biệt trong C </h2></summary>

- Biến cục bộ là biến tồn tại trong các hàm :Hàm main() , hàm con.Biến cục bộ sẽ được lưu vào vùng nhớ stack, thu hồi khi kết thúc hàm. 
- Biến toàn cục là các biến được khai báo ở bên ngoài tất cả các hàm , Biến toàn cục tồn tại cho tới khi chương trình kết thúc.


### Khác nhau của static cục bộ và static toàn cục:

**Biến static cục bộ:** 
- Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. 
- Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm
- Biến static sẽ lưu vào vùng nhớ Data/ Bss, được giải phóng khi kết thúc chương trình.

- Ví dụ:

```C
		#include <stdio.h>
		void printMessage() {
		static int count = 0;
		// Tăng giá trị biến mỗi lần hàm được gọi
		count++;
		printf("Count: %d\n", count);
		}

		int main() {
		// Gọi hàm có sử dụng biến static
		printMessage();//
		printMessage();

		return 0;
		}// KQ:Count: 1,Count: 2

```

**Biến static toàn cục:**  
- Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File định nghĩa nó, các File khác không có cách nào truy cập được.Nghĩa là `extern` không dùng được
- Ví dụ:globalStaticVar được khai báo là static và nằm trong file "File1.c". Do đó, bạn không thể trực tiếp truy cập nó từ file "File2.c", bằng extern int globalStaticVar; trong File2.c, chương trình sẽ không biên dịch được và thông báo lỗi.
- Hạn chế phạm vi của biến chỉ trong một file, tránh xung đột tên biến giữa các file khác nhau.
**Biến Extern:**
- Từ khóa extern được sử dụng để khai báo một biến mà đã được định nghĩa bên ngoài chương trình hoặc tệp tin.
- Biến extern không tạo ra bộ nhớ mới cho biến , tiết kiệm dung lượng chương trình
- Biến được tham chiếu phải được khai báo toàn cục.
- Lưu ý: khi sử dụng extern, không được khai báo giá trị ban đầu cho biến

 <details>
<summary>Ví dụ</summary>

- File 1 ta khai báo

```C
int GlobalVariable = 0; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}
```
- File 2, chúng ta extern biến đó để sử dụng

```C
extern int GlobalVariable; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}; 
```
 </details>



**Biến register:**
- Từ khóa register trước 1 biến để thông báo biến này sẽ lưu thanh ghi của CPU, chứ không phải vào RAM. 
- Do lưu trong thanh ghi nên tốc độ xử lý sẽ nhanh hơn.
    `register int counter = 0;`
- Hạn chế dùng register vì thanh ghi có giới hạn (32 bit là 4 byte , 64 bit là 8 byte ) >> chỉ lưu những biến quan trọng , cần tính toán nhanh
- Giải thích :Nếu khai báo biến thông thường để tính toán không có từ khóa register , thực hiện một phép tính thì cần có 3 bước.
	- Ví dụ: `int a = 6.Ví dụ :a có địa chỉ là 0X01,  a=a+4`
	- B1:Lưu địa chỉ và giá trị của biến vào bộ nhớ RAM : `0X01=6;` 
	- B2:Sau đó chuyển từ Ram qua thanh ghi(register)
	- B3:Từ register chuyển qua ALU (Arithmetic Logic Unit) ,để tính toán.Sau khi tính toán xong thì lại chuyển ngược về register>> về RAM



**volatile:** Thông báo cho trình biên dịch không tối ưu biến này,nếu tối ưu thì sẽ không đúng kết quả của người code.
- Sử dụng volatile với biến có giá trị thay đổi từ bên ngoài , liên tục và giống nhau.Nếu không có volatile, compiler sẽ hiểu rằng các biến như vậy dường như không thay đổi giá trị nên compiler có xu hướng loại bỏ để có thể tối ưu kích cỡ file code .
- Ví dụ:
```C
   	int main() {
    volatile int sensorValue;

    while (1) {
        // Đọc giá trị từ cảm biến (sensor)
        sensorValue = readSensor();

        // Xử lý giá trị cảm biến
        processSensorValue(sensorValue);
    }

    return 0;
}
```

</details>
 
<details>
  <summary><h2>Goto_setjmp</h2></summary>

**Goto:**
- goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm.

 <details>
<summary>Ví dụ</summary>

```C
#include <stdio.h>
int main() {    
	int i = 0;   // Đặt nhãn    start        
	if (i >= 5) {           
		goto end;  // Chuyển control đến nhãn "end"       
		}       
		printf("%d ", i);        
		i++;        
		goto start;  // Chuyển control đến nhãn "start"    		 
		end: // Nhãn "end"       
		printf("\n");
		return 0;
	}
```

</details>

**Setjmp.h:**
- `setjmp.h` là một thư viện trong ngôn ngữ lập trình C, chứa các hàm setjmp và longjmp được sử dụng để xử lý các tình huống ngoại lệ.
- Khi điều kiện là sai, chúng không dừng chương trình lại như assert, mà thay vào đó chúng tạo ra một cơ hội để nhảy đến một điểm nhảy trước đó đã được đánh dấu bởi setjmp
- `setjmp` sẽ lưu điểm đánh dấu chương trình ngoại lệ .
- `longjmp` được sử dụng để nhảy đến một điểm  đã được đánh dấu bởi setjmp.

 <details>
<summary>Ví dụ</summary>

```C

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;//jmp_buf là kiểu dữ liệu trong thư viện Setjmp.h
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1); // Mã lỗi 1 
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }


    // Các xử lý khác của chương trình
    return 0;
}


```

</details>

</details>

<details>
  <summary><h2>Bitmask </h2></summary>

**Khái niệm**:
- Bitmask là một kỹ thuật dùng để kiểm tra, đặt, hoặc xóa bit cụ thể hoặc (flags)
- khi muốn Set 1 bit tại ví trí chỉ cần dịch bit 1 tới vị trí Cần SET và OR với iá trị hiện tại
- Khi muốn Clear bit tai vị tri chỉ cần dịch bit 1 tới vị trí cần Clear , đảo ngược hết bit đó  và AND với giá trị hiện tại
- Ví dụ:

```C
	uint8_t x = 0;/0X0000 0000
	// Muốn set tại vị tri 1 
	x = x | (1 << 1);//0x0000 0010
	x = x & ~(1 << 1);0x0000 0000
	1<<1:dịch bit 1 tới vị trí số 1:0000 0010
	1<<2:dịch bit 1 tới vị trí số 2:0000 0100


```
<details>
<summary>Ví dụ 1 </summary>

```C

#include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm 5 tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}

void removeFeatures(uint8_t *features, uint8_t unwantedFeatures) {
    *features &= ~unwantedFeatures;
}


int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    removeFeatures(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}

```

</details>

<details>
<summary>Ví dụ 2 </summary>

```	C
#include <stdio.h>

#define LED1 1 << 0 // 0001
#define LED2 1 << 1 // 0010
#define LED3 1 << 2 // 0100
#define LED4 1 << 3 // 1000


void enableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT |= LED;
}

void disableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT &= ~LED;
}


int main() {
    unsigned int GPIO_PORT = 0; // Giả sử là biến điều khiển cổng GPIO

    // Bật LED1 và LED3
    enableLED(&GPIO_PORT, LED1 | LED3);
    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }
    
    // Tắt LED1 và bật LED2
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }

    // Cập nhật trạng thái của GPIO_PORT tương ứng với hardware

    return 0;
}
```
</details>


</details>
<details>
  <summary><h2>Struct - Union </h2></summary>


**Struct:**
- Struct là một kiểu dữ liệu chứa nhiều kiểu dữ liệu khác trong nó , kích thước của struct bằng kích thước các thành viên bên trong + phần padding.
- Gom  các biến liên quan dễ quản lý.
- struct: Khi cần  truy cập nhiều thành viên đồng thời.
- Struct padding :
	+ Data alignment:Việc thao tác các biến có địa chỉ liền kề là 1 số lẻ là phức tạp , nên CPU luôn thao tác các địa chỉ là số chẵn >> Data alignment là việc 	sắp xếp data sao cho địa chỉ của các biến luôn là số chẵn và phù hợp với hệ thống.
	+ Data padding: là thêm các vùng nhớ đệm để có địa chỉ chẵn
- Ví dụ:
![Struct](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/e28efacc-bb79-4e85-b16f-4e2645df8ff8)
- Tổng Example là 8 byte , 7 byte dữ liệu + 1 byte trống 
![Struct1](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/59f459ad-bbcb-42d3-a8e3-2cc0f222594d)
- Tổng Example là 12 byte ,  7 byte dữ liệu + 5 byte trống
![Struct2](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/1ae3cbe1-4c82-40dd-b57e-7d2eec545f3f)
- Tổng Example là 24 byte ,cơ bản là tốn time tính

##Và mục đích tính toán struct,để tối ưu bộ nhớ,nếu sắp xếp các phần tử không hợp lý sẽ tốn bộ nhớ.


**Union:**
- Union là một kiểu dữ liệu chứa nhiều kiểu dữ liệu khác trong nó ,kích thước của struct bằng kích thước thành viên lớn nhất và cùng 1 vùng nhớ.
- cho phép lưu trữ các biến khác nhau trong cùng một vị trí bộ nhớ. Khi một giá trị mới được gán cho union, giá trị trước đó được ghi đè. Điều này có nghĩa là union chỉ lưu trữ một giá trị duy nhất tại một thời điểm.

<details>
<summary>Ví dụ </summary>

```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;  // Gán giá trị cho thành viên int
    printf("data.i: %d\n", data.i);  // In ra giá trị của thành viên int

    data.f = 220.5;  // Gán giá trị cho thành viên float
    printf("data.f: %f\n", data.f);  // In ra giá trị của thành viên float

    // Truy cập thành viên int sau khi đã gán giá trị cho thành viên float
    printf("data.i: %d\n", data.i);  // Giá trị này không còn chính xác do đã bị thay đổi

    return 0;
}







```


</details>


![Union](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/fbd619c6-cf4b-42f4-9882-7595480d67a9)
![union1](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/e70b509c-8c6e-4664-a79d-ed245e97125e)
- Tổng Example là 20 byte , thằng nào lớn nhất thì lấy thằng đó

##Mục đích sử dụng  Union ,để tiết kiệm bộ nhớ ,vì 1 thời điểm chỉ có thể sử dụng 1 member. 
- Ứng dụng đọc 1 cảm biến trong nhiều cảm biến.
- Nếu cùng 1 mục đích mà sử dụng struct sẽ tốn nhiều dung lượng hơn.
![Union2](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/7c8f5f9b-0325-4e04-bb81-5bfd96144b57)
- Ví dụ trên nếu dùng struct thì 8 byte , trong khi union chỉ 4 byte

</details>
<details>
  <summary><h2>Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động</h2></summary>
	
### Phân vùng bộ nhớ trên RAM(Memory layout)
- Chương trình main.exe trên window  hoặc main.hex với VĐK (lưu ở bộ nhớ SSD hoặc FLASH). 
- Khi nhấn run chương trình trên window hoặc cấp nguồn cho vi điều khiển thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.


| Stack |
|:-----:|
|   ↓   |
|   ↑   |	
|  Heap |
|  Bss(Uninitialized data)  |
|  Data(Initialized data)   |
|  Text |
- ***Text:*** Quyền truy cập chỉ có thể Read( không thay đổi)
	- Lưu các hằng số :`const int x =2` 
	- con trỏ kiểu char
	- Kích thước là cố định
	- Nó chưa lệnh thực thi :Mã assembly...
- ***Data:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục đã dc khởi tạo hoặc biến static khác 0:`int a=1, int b=2;`
	- Được giải phóng khi kết thúc chương trình
	- Kích thước có thể thay đổi
- ***Bss:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục chưa khởi tạo, hoặc bằng 0:`int a=0, int b;`
	- Các biến static bằng 0 hoặc chưa khởi tạo
	- Được giải phóng khi kết thúc chương trình
	- Kích thước có thể thay đổi
- ***Stack:*** Quyền truy cập là Read-Write.
	- lưu trữ các biến cục bộ.
	- Các tham số truyền vào và các giá trị trả về từ hàm.
	- Hàm main cũng ở vùng stack
	- Sẽ được giải phóng khi ra khỏi hàm
	- Kích thước cố định: phụ thuộc vào hệ điều hành, đối với Windows thường là 1MB, Linux là 8MB.
	- Stack: bởi vì bộ nhớ Stack cố định nêú sử dụng quá nhiều bộ nhớ vượt quá khả năng của Stack sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như  khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
	
- ***Heap:*** Quyền truy cập là Read-Write.
	- Heap sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình
	- Heap được dùng để lưu trữ vùng nhớ cho những biến được cấp phát động bởi các hàm malloc - calloc - realloc 
	- Nếu liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). 
	- Nếu khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
	- Kích thước không cố định.
	- Sẽ được giải phóng khi gọi hàm free,...
	### So sánh Stack và Heap?
	- Bộ nhớ: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
		- Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
		- Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
	- Kích thước vùng nhớ:
		- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
		- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
	- vùng nhớ Stack được quản lý bởi hệ điều hành,tự động giải phóng khi hàm thực hiện xong 
	- Vùng nhớ Heap được quản lý bởi lập trình viên ,tự  giải phóng vùng nhớ bằng câu lệnh free (trong C) hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ 
	### Các cách sử dụng malloc, calloc, realloc, free:
	- ***Malloc:*** Cấp phát bộ nhớ động mỗi phần tử, không khởi tạo giá trị, trả về con trỏ void khi cấp phát thành công.
	- ***Calloc:*** Cấp phát bộ nhớ động và khởi tạo cho các phần tử là 0, trả về con trỏ void khi cấp phát thành công.
	- ***Realloc:*** Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ void khi thay đổi thành công.
	- Vậy `Malloc` sẽ nhanh hơn `Calloc`
	- Ví dụ:

	```C
	int main() {
    int *arr_malloc, *arr_calloc;
    size_t size = 5;

    // Sử dụng malloc
    arr_malloc = (int*)malloc(size * sizeof(int));

    // Sử dụng calloc
    arr_calloc = (int*)calloc(size, sizeof(int));

    // Sử dụng Realloc
	arr_malloc = (int*)realloc(arr_malloc, sizeof(int) * 7); // size arr_malloc lúc này là 7


    // Giải phóng bộ nhớ
    free(arr_malloc);
    free(arr_calloc);

    return 0;
	}
	```
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;
    char* ten = (char*) malloc(sizeof(char) * soluongkytu)
    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);
        printf("Hello %s\n", ten);
    }

}

```

</details>


- Đặc điểm vùng nhớ
	- Stack: 
		- vùng nhớ Stack được quản lý bởi hệ điều hành, 
		- Dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
	- Heap: k
		- Kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu ,
		- Dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
### Lưu ý: 
- Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
- Vấn đề lỗi xảy ra đối với vùng nhớ Stack: Bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,..
	- Ví dụ về tràn bộ nhớ stack với hàm đệ quy vô hạn:
	```C
	int foo(int x){
		printf("De quy khong gioi han\n");
		return foo(x);
	}
	```
- Vấn đề lỗi xảy ra đối với vùng nhớ Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
	- Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
	```C 
	int *A = (int *)malloc(18446744073709551615); 
	```

- ***Realloc:*** Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ NULL khi thay đổi thành công
```C
void* realloc(void* ptr, size_t size);
```
- ***Free:*** Giải phóng bộ nhớ đã được cấp phát bằng Malloc, Calloc, Realloc sau khi sử dụng xong, không có trả về
```C
void free(void* ptr);
```
### Khác nhau của static cục bộ và static toàn cục:

- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.Biến static sẽ lưu vào vùng nhớ Data/ Bss, được giải phóng khi kết thúc chương trình.

- Ví dụ:

```C
 	#include <stdio.h>
	void printMessage() {
    static int count = 0;
    // Tăng giá trị biến mỗi lần hàm được gọi
    count++;
    printf("Count: %d\n", count);
	}

	int main() {
    // Gọi hàm có sử dụng biến static
    printMessage();//
    printMessage();

    return 0;
	}// KQ:Count: 1,Count: 2

```

- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.
- Ví dụ:globalStaticVar được khai báo là static và nằm trong file "File1.c". Do đó, bạn không thể trực tiếp truy cập nó từ file "File2.c", bằng extern int globalStaticVar; trong File2.c, chương trình sẽ không biên dịch được và thông báo lỗi.
- Biến cục bộ: Biến cục bộ sẽ được lưu vào vùng nhớ stack, thu hồi khi kết thúc hàm cục bộ. 

</details>
<details>
  <summary><h2> JSON</h2></summary>

> https://www.w3schools.com/js/js_json_intro.asp
>
> https://www.geeksforgeeks.org/cjson-json-file-write-read-modify-in-c/

- JSON là viết tắt của "JavaScript Object Notation" (Định dạng đối tượng JavaScript).
- JSON là một định dạng văn bản được sử dụng để lưu trữ và truyền dữ liệu; nó được sử dụng để trao đổi dữ liệu giữa các ứng dụng và dịch vụ web.
- JSON là "tự mô tả", dễ đọc và viết cho cả con người và máy tính.

**Trong JSON, giá trị phải thuộc một trong các loại dữ liệu sau:**

- Một chuỗi (phải được viết trong dấu ngoặc kép) -> Ví dụ: {"name":"John"}
- Một số (phải là số nguyên hoặc số thực) -> Ví dụ: {"age":30}
- Một đối tượng (Các giá trị trong JSON có thể là đối tượng) -> Ví dụ: { "employee":{"name":"John", "age":30, "city":"New York"} }
- Một mảng -> Ví dụ: { "employees":["John", "Anna", "Peter"] }
- Một giá trị boolean -> Ví dụ: {"sale":true}
null -> Ví dụ: {"middlename":null}
- Giá trị JSON không thể là một trong các loại dữ liệu sau:
Một hàm,Một ngày,undefined.

```C
	{ "name": "Bob Johnson", "age": 35, "city": "Chicago" },
	{ "name": "John Doe", "age": 30, "city": "New York", "occupation": "Software Engineer", "isStudent": false },
	{
	    "name": "Jane Smith",
	    "age": null,
	    "city": "Los Angeles",
	    "contact": { "email": "jane.smith@example.com", "phone": "555-1234" }
	}

```

<details>
<summary>Ví dụ:</summary>

```C
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stddef.h>
	#include <ctype.h>
	#include <stdbool.h>
	
	typedef enum {
	    JSON_NULL,
	    JSON_BOOLEAN,
	    JSON_NUMBER,
	    JSON_STRING,
	    JSON_ARRAY,
	    JSON_OBJECT
	} JsonType;
	
	typedef struct JsonValue {
	    JsonType type;
	    union {
	        int boolean; double number; char *string;
	        struct {
	            struct JsonValue *values;
	            size_t count; // số lượng element
	        } array;
	        struct {
	            char **keys;
	            struct JsonValue *values;
	            size_t count; // số cặp key-value
	        } object;
	    } value;
	} JsonValue;
	
	JsonValue *parse_json(const char **json);
	
	void free_json_value(JsonValue *json_value);
	
	static void skip_whitespace(const char **json) {
	    while (isspace(**json)) {
	        (*json)++;
	    }
	}
	
	JsonValue *parse_null(const char **json) {
	    skip_whitespace(json);
	    if (strncmp(*json, "null", 4) == 0) { // khi bắt gặp đc chữ n -> nó lấy thêm 3 phần tử tiếp theo -> so sánh với null
	        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	        value->type = JSON_NULL; 
	        *json += 4;
	        return value;
	    }
	    return NULL;
	}
	
	JsonValue *parse_boolean(const char **json) {
	    skip_whitespace(json);
	    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	    if (strncmp(*json, "true", 4) == 0) {
	        value->type = JSON_BOOLEAN;
	        value->value.boolean = true;
	        *json += 4;
	    } else if (strncmp(*json, "false", 5) == 0) {
	        value->type = JSON_BOOLEAN;
	        value->value.boolean = false;
	        *json += 5;
	    } else {
	        free(value);
	        return NULL;
	    }
	    return value;
	}
	
	JsonValue *parse_number(const char **json) {
	    skip_whitespace(json);
	    char *end; //:') 
	
	    double num = strtod(*json, &end);
	    if (end != *json) {
	        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	        value->type = JSON_NUMBER;
	        value->value.number = num;
	        *json = end;
	        return value;
	    }
	    return NULL;
	}
	
	JsonValue *parse_string(const char **json) {
	    skip_whitespace(json);
	
	    if (**json == '\"') {
	        (*json)++;
	        const char *start = *json;
	        while (**json != '\"' && **json != '\0') {
	            (*json)++;
	        }
	        if (**json == '\"') {
	            size_t length = *json - start; // 3
	            char *str = (char *) malloc((length + 1) * sizeof(char));
	            strncpy(str, start, length);
	            str[length] = '\0';
	
	            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
	            value->type = JSON_STRING;
	            value->value.string = str;
	            (*json)++;
	            return value;
	        }
	    }
	    return NULL;
	}
	
	JsonValue *parse_array(const char **json) {
	    skip_whitespace(json);
	    if (**json == '[') {
	        (*json)++;
	        skip_whitespace(json);
	
	        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
	        array_value->type = JSON_ARRAY;
	        array_value->value.array.count = 0;
	        array_value->value.array.values = NULL;
	
	        /*
	        double arr[2] = {};
	        arr[0] = 30;
	        arr[1] = 70;
	        */
	
	        while (**json != ']' && **json != '\0') {
	            JsonValue *element = parse_json(json); // 70
	            if (element) {
	                array_value->value.array.count++;
	                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
	                array_value->value.array.values[array_value->value.array.count - 1] = *element;
	                free(element);
	            } else {
	                break;
	            }
	            skip_whitespace(json);
	            if (**json == ',') {
	                (*json)++;
	            }
	        }
	        if (**json == ']') {
	            (*json)++;
	            return array_value;
	        } else {
	            free_json_value(array_value);
	            return NULL;
	        }
	    }
	    return NULL;
	}
	
	JsonValue *parse_object(const char **json) {
	    skip_whitespace(json);
	    if (**json == '{') {
	        (*json)++;
	        skip_whitespace(json);
	
	        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
	        object_value->type = JSON_OBJECT;
	        object_value->value.object.count = 0;
	        object_value->value.object.keys = NULL;
	        object_value->value.object.values = NULL;
	
	        while (**json != '}' && **json != '\0') {
	            JsonValue *key = parse_string(json);
	            if (key) {
	                skip_whitespace(json);
	                if (**json == ':') {
	                    (*json)++;
	                    JsonValue *value = parse_json(json);
	                    if (value) {
	                        object_value->value.object.count++;
	                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
	                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;
	
	                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
	                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
	                        free(value);
	                    } else {
	                        free_json_value(key);
	                        break;
	                    }
	                } else {
	                    free_json_value(key);
	                    break;
	                }
	            } else {
	                break;
	            }
	            skip_whitespace(json);
	            if (**json == ',') {
	                (*json)++;
	            }
	        }
	        if (**json == '}') {
	            (*json)++;
	            return object_value;
	        } else {
	            free_json_value(object_value);
	            return NULL;
	        }
	    }
	    return NULL;
	}
	
	JsonValue *parse_json(const char **json) { // làm việc với giá trị json_str_value 
	    while (isspace(**json)) {
	        (*json)++;
	    }
	
	    switch (**json) {
	        case 'n':
	            return parse_null(json);
	        case 't':
	        case 'f':
	            return parse_boolean(json);
	        case '\"':
	            return parse_string(json);
	        case '[':
	            return parse_array(json);
	        case '{':
	            return parse_object(json);
	        default:
	            if (isdigit(**json) || **json == '-') return parse_number(json);
	            else return NULL; // Lỗi phân tích cú pháp
	    }
	}
	
	void free_json_value(JsonValue *json_value) {
	    if (json_value == NULL) return;
	    
	    switch (json_value->type) {
	        case JSON_STRING:
	            free(json_value->value.string);
	            break;
	        case JSON_ARRAY:
	            for (size_t i = 0; i < json_value->value.array.count; i++) {
	                free_json_value(&json_value->value.array.values[i]);
	            }
	            free(json_value->value.array.values);
	            break;
	        case JSON_OBJECT:
	            for (size_t i = 0; i < json_value->value.object.count; i++) {
	                free(json_value->value.object.keys[i]);
	                free_json_value(&json_value->value.object.values[i]);
	            }
	            free(json_value->value.object.keys);
	            free(json_value->value.object.values);
	            break;
	        default:
	            break;
	    }
	}
	
	void test(JsonValue* json_value){
	    if (json_value != NULL && json_value->type == JSON_OBJECT) {
	        // Truy cập giá trị của các trường trong đối tượng JSON
	        size_t num_fields = json_value->value.object.count;
	        size_t num_fields2 = json_value->value.object.values->value.object.count;
	        for (size_t i = 0; i < num_fields; ++i) {
	
	            char* key = json_value->value.object.keys[i];
	            JsonValue* value = &json_value->value.object.values[i];
	
	            JsonType type = (int)(json_value->value.object.values[i].type);
	
	            if(type == JSON_STRING) printf("%s: %s\n", key, value->value.string);
	        
	            if(type == JSON_NUMBER) printf("%s: %f\n", key, value->value.number);
	        
	            if(type == JSON_BOOLEAN) printf("%s: %s\n", key, value->value.boolean ? "True":"False");
	
	            if(type == JSON_OBJECT){
	                printf("%s: \n", key);
	                test(value);
	            }
	
	            if(type == JSON_ARRAY){
	                printf("%s: ", key);
	                for (int i = 0; i < value->value.array.count; i++) {
	                   test(value->value.array.values + i);
	                } 
	                printf("\n");
	            }
	        }
	    } else {
		    if(json_value->type == JSON_STRING) printf("%s ", json_value->value.string);
		    
		    if(json_value->type == JSON_NUMBER) printf("%f ", json_value->value.number);
		
		    if(json_value->type == JSON_BOOLEAN) printf("%s ", json_value->value.boolean ? "True":"False");
		
		    if(json_value->type == JSON_OBJECT){
			printf("%s: \n", json_value->value.object.keys);
			test(json_value->value.object.values);          
	            }
	      }
	}
	
	int main(int argc, char const *argv[]) {
	     
	     // Chuỗi JSON đầu vào
	    const char* json_str = "{"
	                        "\"1001\":{"
	                          "\"SoPhong\":3,"
	                          "\"NguoiThue\":{"
	                            "\"Ten\":\"Nguyen Van A\","
	                            "\"CCCD\":\"1920517781\","
	                            "\"Tuoi\":26,"
	                            "\"ThuongTru\":{"
	                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
	                              "\"Phuong_Xa\":\"Phuong 6\","
	                              "\"Tinh_TP\":\"Ho Chi Minh\""
	                            "}"
	                          "},"
	                          "\"SoNguoiO\":{"
	                            "\"1\":\"Nguyen Van A\","
	                            "\"2\":\"Nguyen Van B\","
	                            "\"3\":\"Nguyen Van C\""
	                          "},"
	                          "\"TienDien\": [24, 56, 98],"
	                          "\"TienNuoc\":30.000"
	                        "},"
	                        "\"1002\":{"
	                          "\"SoPhong\":5,"
	                          "\"NguoiThue\":{"
	                            "\"Ten\":\"Phan Hoang Trung\","
	                            "\"CCCD\":\"012345678912\","
	                            "\"Tuoi\":24,"
	                            "\"ThuongTru\":{"
	                              "\"Duong\":\"53 Le Dai Hanh\","
	                              "\"Phuong_Xa\":\"Phuong 11\","
	                              "\"Tinh_TP\":\"Ho Chi Minh\""
	                            "}"
	                          "},"
	                          "\"SoNguoiO\":{"
	                            "\"1\":\"Phan Van Nhat\","
	                            "\"2\":\"Phan Van Nhi\","
	                            "\"2\":\"Phan Van Tam\","
	                            "\"3\":\"Phan Van Tu\""
	                          "},"
	                          "\"TienDien\":23.000,"
	                          "\"TienNuoc\":40.000"
	                        "}"
	                      "}";
	    
	
	    // Phân tích cú pháp chuỗi JSON
	    JsonValue* json_value = parse_json(&json_str);
	
	   test(json_value);
	
	    // Kiểm tra kết quả phân tích cú pháp
	
	       // Giải phóng bộ nhớ được cấp phát cho JsonValue
	    free_json_value(json_value);
	    
	        //printf("test = %x", '\"');
	
	       // hienthi(5);
	    
	    return 0;
	}






```
</details>

</details>
<details>
  <summary><h2> Linked List</h2></summary>

- Linked List trong C là một cấu trúc dữ liệu cho phép lưu trữ dữ liệu  không liên tục trong bộ nhớ
- Mỗi nút (node) trong Linked List chứa dữ liệu và một con trỏ đến nút tiếp theo trong danh sách.
- Linked List cho phép cấp phát bộ nhớ động dễ dàng, do đó có thể mở rộng hoặc thu nhỏ kích thước của danh sách tùy theo nhu cầu.
- Chèn/Xóa hiệu quả: Thao tác chèn hoặc xóa một phần tử ở vị trí bất kỳ có thể thực hiện mà không cần phải di chuyển các phần tử khác như mảng.
- Duyệt dữ liệu: Duyệt dữ liệu từ đầu đến cuối hoặc ngược lại cũng dễ dàng nhờ vào con trỏ next.
- khi thêm node bất kì trong linked lish thì điều chỉnh con trỏ của nút trước đó để trỏ đến `nút mới` , và con trỏ  của` nút mới` trỏ đến nút tiếp theo.
- Ví dụ:Chèn nút có giá trị 8 vào giữa nút 7 và 9
```C
#include <stdio.h>

int main()
{
// Đầu tiên, bạn cần khởi tạo một nút mới và gán giá trị cho nút này là 8.

Node* new_node = new Node(8);
//Đặt con trỏ nút 7  trỏ đến nút 8.
//Đặt con trỏ nút 8  trỏ đến nút 9.

// Tìm nút có giá trị 7 trong danh sách
Node* current = head;
while (current->data != 7) {
    current = current->next;
}

// current hiện đang trỏ đến nút có giá trị là 7
// Điều chỉnh con trỏ next để chèn nút mới
new_node->next = current->next;   // new_node sẽ trỏ đến nút có giá trị là 9
current->next = new_node;         // Nút có giá trị là 7 sẽ trỏ đến new_node


    return 0;
}


```

- khi xóa 1 node bất kì trong linked lish điều chỉnh con trỏ  của nút trước nút bị xóa để trỏ đến nút sau nó, sau đó giải phóng bộ nhớ của nút bị xóa
	+ Ví du: 5>7>9
	+ điều chỉnh con trỏ next của nút 5 để trỏ tới nút 9, bỏ qua nút 7.
	+ Sau đó, giải phóng bộ nhớ của nút 7.
- Mảng và nhược điểm của thao tác chèn/xóa:
	+ Trong mảng, khi chèn hoặc xóa một phần tử ở vị trí bất kỳ, các phần tử khác phía sau nó phải được di chuyển.

 <details>
<summary>Ví dụ</summary>

```C
#include <stdio.h>
#include <stdlib.h>
// Định nghĩa cấu trúc Node của Linked List
struct Node {
    int data;
    struct Node* next;
};

// Hàm chèn một nút mới vào vị trí bất kỳ trong danh sách liên kết
void insertNode(struct Node** head_ref, int position, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 1) {
        // Chèn vào đầu danh sách
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        // Tìm vị trí chèn
        struct Node* temp = *head_ref;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Không thể chèn vào vị trí đã cho.\n");
            return;
        }
        // Chèn vào vị trí position
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Hàm để in danh sách liên kết
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Chèn các phần tử ban đầu vào danh sách liên kết
    insertNode(&head, 1, 5);
    insertNode(&head, 2, 7);
    insertNode(&head, 3, 9);

    printf("Linked List ban đầu: ");
    printList(head);

    // Chèn phần tử 10 vào vị trí thứ 2
    insertNode(&head, 2, 10);

    printf("Linked List sau khi chèn: ");
    printList(head);

    return 0;
}


```
</details>
</details>


<details>
  <summary><h2> Stack - Queue </h2></summary>

> https://www.programiz.com/dsa/stack
>
> https://medium.com/@noransaber685/understanding-the-stack-data-structure-in-c-introduction-implementation-and-examples-8d3fb03de809

**Khái niệm:**
- Stack là một cấu trúc dữ liệu trong đó việc chèn một phần tử mới và loại bỏ một phần tử hiện tại xảy ra ở cùng một đầu, được biểu diễn là đỉnh của ngăn xếp.
Nó tuân theo nguyên tắc LIFO (Last In First Out) - Điều này có nghĩa là phần tử được chèn cuối cùng vào ngăn xếp sẽ được loại bỏ đầu tiên.
- Stack là một trường hợp đặc biệt của danh sách liên kết, chỉ thêm và xóa phần tử ở đầu danh sách
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/08f2360c-a79d-4c79-8478-474bd695a274)

**Các Phép Toán Cơ Bản trên Ngăn Xếp**

- push(): Chèn một phần tử vào ngăn xếp.
- pop(): Loại bỏ một phần tử khỏi ngăn xếp.
- peek(): Lấy giá trị của phần tử ở đỉnh mà không loại bỏ nó.
- isempty(): Kiểm tra xem ngăn xếp có trống không.
- isfull(): Kiểm tra xem ngăn xếp có đầy không.
- size(): Trả về kích thước của ngăn xếp.

 

**Các phép toán hoạt động như sau:**
- Sử dụng một con trỏ được gọi là TOP để theo dõi phần tử đỉnh trong ngăn xếp.
- Khi khởi tạo ngăn xếp, ta đặt giá trị của nó là -1 để kiểm tra xem ngăn xếp có trống không bằng cách so sánh TOP == -1.
- Khi đẩy một phần tử, ta tăng giá trị của TOP và đặt phần tử mới vào vị trí mà TOP đang chỉ đến.
- Khi lấy ra một phần tử, ta trả về phần tử mà TOP đang chỉ đến và giảm giá trị của nó.
- Trước khi đẩy, ta kiểm tra xem ngăn xếp đã đầy chưa.
- Trước khi lấy ra, ta kiểm tra xem ngăn xếp đã trống không chưa.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/3b829f3d-20ea-4bcf-9a2f-646e580989ce)


 <details>
<summary>giải thích hàm</summary>

**1, peek()**

```C
		int peek() {
		   return stack[top];
		}
```  
**2, isempty() and isfull()**

```C
		bool isempty() {
		   if(top == -1)
		      return true;
		   else
		      return false;
		}
		
		bool isfull() {
		   if(top == MAXSIZE)
		      return true;
		   else
		      return false;
		}
``` 

**3, push()**
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/0e1e6417-1fc2-423c-90f9-da35ea7f6fe5)

```C

		void push(int data) {
		   if(!isFull()) {
		      top = top + 1;   
		      stack[top] = data;
		   } else {
		      printf("Stack overflow\n");
		   }
		}
```

**4, pop()**
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/2ce94763-fa9e-4982-bf5a-adf4a68aa1cd)

```C
int pop(int data) {
		   if(!isempty()) {
		      data = stack[top];
		      top = top - 1;   
		      return data;
		   } else {
		      printf("Stack underflow\n");
		   }
		}
```

</details>



 <details>
<summary>Ví dụ1:</summary>

```C
	#include <stdio.h>
	#include <stdlib.h>
	
	typedef struct Stack {
	    int* items; // mảng để lưu giá trị của từng ô
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
	
	    printf("Top element: %d\n", top(stack1)); // 50
	
	    printf("Pop element: %d\n", pop(&stack1)); // 50
	    printf("Pop element: %d\n", pop(&stack1)); // 40
	
	    printf("Top element: %d\n", top(stack1)); // 30
	
	    return 0;
	}

```
</details>

 <details>
<summary>Ví dụ 2:</summary>

```c
	#include <stdio.h>
	#include <stdlib.h>

	void push();
	void pop();
	void display();

	struct node {
	    int data;
	    struct node* next;
	};
	
	struct node* temp; // Variable to store the top of the stack
	
	int main() {
	    printf("LINKED LIST IMPLEMENTATION USING STACKS\n\n");
	    do {
	        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
	        printf("Enter your choice:");
	        int choice; scanf("%d", &choice);
	        
	        switch (choice) {
	            case 1:
	                push();
	                break;
	            case 2:
	                pop();
	                break;
	            case 3:
	                display();
	                break;
	            case 4:
	                exit(0);
	                break;
	            default:
	                printf("Please re-enter!\n");
	                break;
	        }
	    } while (choice != 4);
	    return 0;
	}
	
	void push() {
	    int data;
	    struct node* pointer = (struct node*)malloc(sizeof(struct node));
	    
	    if (pointer == NULL) printf("Stack overflow\n");
	    else {
	        printf("Enter the element to be inserted: ");
	        scanf("%d", &data);
	        
	        if (temp == NULL) {
	            pointer->data = data;
	            pointer->next = NULL;
	            temp = pointer;
	        } else {
	            pointer->data = data;
	            pointer->next = temp;
	            temp = pointer;
	        }
	    }
	}
	
	void pop() {
	    int item;
	    struct node* pointer;
	    
	    if (temp == NULL) {
	        printf("Stack underflow\n");
	    }
	    else {
	        item = temp->data;
	        pointer = temp;
	        temp = temp->next;
	        free(pointer);
	        printf("The deleted item is %d\n", item);
	    }
	}
	
	void display() {
	    struct node* pointer;
	    pointer = temp;
	    
	    if (pointer == NULL) {
	        printf("Stack underflow\n");
	    }
	    else {
	        printf("The elements of the stack are:\n");
	        
	        while (pointer != NULL) {
	            printf("%d\n", pointer->data);
	            pointer = pointer->next;
	        }
	    }
	}

```
</details>

**Queue**
> https://www.programiz.com/dsa/queue
>
> https://www.scaler.com/topics/data-structures/queue-in-data-structure/

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/54dffe7b-d9d8-4693-b68f-49f3797f6560)

- Queue tuân theo nguyên tắc "Đầu Tiên Vào, Đầu Tiên Ra (FIFO)" - phần tử vào hàng đợi đầu tiên là phần tử ra khỏi hàng đợi đầu tiên.
- Queue cũng có thể được triển khai bằng Linked List (danh sách liên kết đơn hoặc đôi), nhưng nó chỉ thực hiện các thao tác enqueue/dequeue ở hai đầu của danh sách.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/84c5b5de-2ee0-42c3-8f95-2c95cf81c682)

**Các Phép Toán Cơ Bản trên Hàng Đợi**

- Enqueue: Thêm một phần tử vào cuối hàng đợi.
- Dequeue: Loại bỏ một phần tử từ đầu hàng đợi.
- front : Lấy giá trị ở đầu hàng đợi mà không loại bỏ nó.
- rear :Xem giá trị của phần tử ở cuối hàng đợi mà không xóa nó

**Các phép toán trên hàng đợi hoạt động như sau:**

  + Hai con trỏ FRONT và REAR
  + FRONT theo dõi phần tử đầu tiên của hàng đợi
  + REAR theo dõi phần tử cuối cùng của hàng đợi
  + Ban đầu, đặt giá trị của FRONT và REAR là -1

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/35414b78-0871-445c-bd26-1e09ec383acf)
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/83f8839e-ed51-4f95-8c2a-ffd0b42a6dd2)

<details>
<summary>Ví dụ:</summary>

```C
	#include <stdio.h>
	#include <stdlib.h>
	
	
	typedef struct Queue {
	    int* items; // mảng để lưu giá trị của từng ô
	    int size;
	    int front, rear; // để xác định phần tử nào đứng đầu, phần tử nào đứng cuối hàng
	} Queue;
	
	void initialize(Queue *queue, int size) {
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
</details>


</details>
<details>
  <summary><h2> File operations </h2></summary>

**Những thứ liên quan đến file.csv**
- File CSV (Comma-Separated Values) là một loại file văn bản  để lưu trữ  dữ liệu dưới dạng bảng.
- Ví dụ 1 file example.csv có nội dung

	+ UID	Room	Name
	+	1	A 101	John Doe
	+	2	B202	Jane Smith
	+	3	C303	Bob Johnson4

- Các hàm để thao tác file:
	+ fprintf():Ghi chuỗi vào File, và có thể thêm danh sách các đối số 
	+ fputs() :Ghi chuỗi vào File
	+ fputc() :Ghi một ký tự vào File
	+ fwrite() :Ghi một số byte được chỉ định vào File .bin
	+ fclose(): Đóng File đã mở
	+ feof(): Để kiểm tra địa chỉ hiện tại có phải ký tự cuối cùng của File hay chưa

- Ví dụ thêm dữ liệu vào file example.csv.		

```c
#include <stdio.h>
void addRow(const char* filename, const char* uid, const char* room, const char* name) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Không thể mở file %s để ghi dữ liệu.\n", filename);
        return;
    }
    fprintf(file, "%s,%s,%s\n", uid, room, name);

    fclose(file);
}
int main() {
    addRow("example.csv", "4", "D404", "A Johson");
    addRow("example.csv", "5", "D424", "Ale ");
    addRow("example.csv", "6", "D425", "Alice ");
    return 0;
}
```




 

</details>
<details>
  <summary><h2>Binary Search</h2></summary>

- Tìm kiếm nhị phân (Binary Search) là một thuật toán tìm kiếm trên m mảng đã được sắp xếp. Ý tưởng  là so sánh giá trị cần tìm với giá trị ở giữa của mảng, và dựa vào kết quả của so sánh để xác định xem giá trị cần tìm có thể nằm ở nửa trên hay nửa dưới của mảng
<details>
<summary>Ví dụ:</summary>

```C
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Kiểm tra xem giá trị ở giữa có bằng giá trị cần tìm không
        if (arr[mid] == target)
            return mid;

        // Nếu giá trị ở giữa lớn hơn target, tìm ở nửa trái của mảng
        if (arr[mid] > target)
            high = mid - 1;

        // Nếu giá trị ở giữa nhỏ hơn target, tìm ở nửa phải của mảng
        else
            low = mid + 1;
    }

    // Trả về -1 nếu không tìm thấy giá trị cần tìm
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("nhap gia tri can tim\n");
    scanf("%d",&target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Giá trị %d được tìm thấy tại vị trí %d.\n", target, result);
    else
        printf("Giá trị %d không tồn tại trong mảng.\n", target);

    return 0;
}

```
</details>
</details>






</details>


</details>
</details>

</details>


<details>
  <summary><h1>▶ ⭐C++ programming language</h1></summary>

<details>
  <summary><h2>Class</h2></summary>
	
### Class là gì?
- Class là một cấu trúc dữ liệu , nó bao gồm thuộc tính và hành vi của đối tượng
- Object là 1 đối tượng có thuộc tính và hành vi được tạo ra từ class
- Biến trong class gọi là `PROPERTY`.
- Hàm trong class gọi là `METHOD`.
- Ví dụ:

```C++
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
	// ..
};

```
 # 🚀 Constructor, Destructor, Copy Constructor trong C++

## 🔧 Constructor
- Constructor là một phương thức đặc biệt trong class, dùng để khởi tạo đối tượng.
- Tên giống với tên class, **không có kiểu trả về**.
- Được gọi tự động khi đối tượng được tạo ra.

### 🔸 Đặc điểm:
- Nếu không khai báo, trình biên dịch sẽ tạo **constructor mặc định**.
- Có thể **overload** để tạo nhiều constructor.
- Có thể có **tham số** để truyền dữ liệu lúc khởi tạo.

### 🔸 Các loại constructor:
| Loại                  | Mô tả                                                        |
|-----------------------|---------------------------------------------------------------|
| Mặc định              | Không tham số, hệ thống tự tạo nếu không khai báo            |
| Có tham số            | Truyền giá trị vào lúc khởi tạo đối tượng                    |
| Constructor sao chép | Tạo đối tượng mới từ một đối tượng có sẵn                    |

<details>
<summary>🔍 Ví dụ Constructor có tham số:</summary>

```cpp
#include <iostream>
class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;

    // Constructor có tham số và mặc định giá trị
    HinhChuNhat(int dai = 5, int rong = 3) {
        chieuDai = dai;
        chieuRong = rong;
    }

    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};

int main() {
    HinhChuNhat hinh1;           // Dùng giá trị mặc định
    HinhChuNhat hinh2(7, 4);     // Truyền tham số
    std::cout << hinh1.tinhDienTich() << std::endl;
    std::cout << hinh2.tinhDienTich() << std::endl;
    return 0;
}
```
</details>

---

## 🧹 Destructor
- Destructor là phương thức đặc biệt **được gọi khi đối tượng bị hủy**.
- Có cùng tên với class, nhưng có thêm `~` ở đầu.
- Không có tham số, không overload được.

### 🔸 Đặc điểm:
- Dùng để **giải phóng bộ nhớ/tài nguyên**.
- Gọi tự động khi:
  - Kết thúc hàm
  - `delete` đối tượng
  - Kết thúc chương trình

<details>
<summary>🔍 Ví dụ Destructor:</summary>

```cpp
#include <iostream>  
using namespace std;  
class NhanVien  {  
public:  
    NhanVien() {
        cout << "Ham xay dung duoc goi" << endl;    
    }
    ~NhanVien() {
        cout << "Ham huy duoc goi" << endl;    
    }  
};

int main() {
    NhanVien* n0 = new NhanVien();
    delete n0;              // Gọi destructor thủ công
    NhanVien n1;            // Gọi destructor khi kết thúc hàm
    NhanVien n2;
    return 0;
}
```
</details>

---

## 📋 Copy Constructor (Shallow vs Deep Copy)
- Dùng để **tạo bản sao của một đối tượng có sẵn**.
- Có 2 loại:

| Loại         | Mô tả                                                                 |
|--------------|------------------------------------------------------------------------|
| Shallow copy | Sao chép địa chỉ con trỏ → dễ gây lỗi giải phóng bộ nhớ trùng        |
| Deep copy    | Cấp phát vùng nhớ mới và sao chép dữ liệu → an toàn hơn              |

<details>
<summary>🔍 Ví dụ Deep Copy:</summary>

```cpp
#include <iostream>
using namespace std;

class Test {
    int a, b;
    int *p;
public:
    Test() {
        p = new int;
    }
    Test(const Test &t) {
        a = t.a;
        b = t.b;
        p = new int;
        *p = *(t.p);
    }
    ~Test() {
        delete p;
    }
    void TaoDuLieu(int x, int y, int z) {
        a = x; b = y; *p = z;
    }
    void HienThi() {
        cout << a << ", " << b << ", *p = " << *p << endl;
    }
};

int main() {
    Test t1;
    t1.TaoDuLieu(2, 6, 8);
    Test t2 = t1;
    t1.HienThi();
    t2.HienThi();
    return 0;
}
```
</details>

---

## 🧬 Virtual Destructor
- Dùng khi **xóa đối tượng thông qua con trỏ của lớp cha**.
- Đảm bảo destructor của **lớp con và lớp cha đều được gọi** đúng thứ tự.

### 📌 Khi nào dùng?
- Khi sử dụng **đa hình (polymorphism)** trong lập trình hướng đối tượng.

<details>
<summary>🔍 Ví dụ Virtual Destructor:</summary>

```cpp
#include <iostream>
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Gọi cả destructor của Derived và Base
    return 0;
}
```
</details>

## 📌 Static Keyword: Property
- `static` data member là một biến thành viên được chia sẻ giữa **tất cả các đối tượng** của lớp.
- Chỉ có **một bản sao duy nhất** trong bộ nhớ.
- Được khai báo trong lớp, nhưng **khởi tạo ngoài lớp**.
- Truy cập thông qua tên lớp hoặc đối tượng.
-  Ví dụ Đếm số lượng đối tượng được tạo từ một lớp
<details>
<summary>🔍 Ví dụ: Static Property dùng chung:</summary>

```cpp
#include <iostream>
class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;
    static int var;
};

int HinhChuNhat::var;

int main() {
    HinhChuNhat hinh1, hinh2;
    hinh1.var = 10;
    std::cout << hinh2.var << std::endl; // cũng in ra 10
    return 0;
}
```
</details>

<details>
<summary>🔍 Ví dụ: Static Property đếm đối tượng:</summary>

```cpp
#include <iostream>
class ObjectCounter {
public:
    static int count;
    ObjectCounter() {
        count++;
    }
};

int ObjectCounter::count = 0;

int main() {
    ObjectCounter obj1, obj2;
    std::cout << "Number of objects: " << ObjectCounter::count << std::endl;
    return 0;
}
```
</details>

---

## 📌 Static Keyword: Method
- `static` method có thể gọi **mà không cần tạo đối tượng**.
- Chỉ có thể truy cập các thành phần `static` khác trong class.

<details>
<summary>🔍 Ví dụ: Static Method:</summary>

```cpp
#include <iostream>
class MathUtils {
public:
    static int square(int x) {
        return x * x;
    }
};

int main() {
    int result = MathUtils::square(5);
    std::cout << "Square of 5: " << result << std::endl;
    return 0;
}
```
</details>




**Con trỏ this trong C++**
- This là một con trỏ đặc biệt dùng để trỏ đến địa chỉ của đối tượng hiện tại
- Khi nào nên dùng con trỏ this:
	+ Khi một đối tượng gọi một hàm thành viên, this trỏ đến đối tượng đó.
	+ phân biệt giữa biến thành viên và tham số(Nếu trùng tên)
	+ Static method không thể sử dụng con trỏ this vì static method không gắn với bất kỳ đối tượng nào.

```c++
void setData(int msnv, string ten, int tuoi) {  
    this->msnv = msnv;    
    this->ten = ten;    
    this->tuoi = tuoi; 
}
```


<details>
<summary>Ví dụ:</summary>

```c++
#include <iostream>  
using namespace std;  
class NhanVien { 
    int msnv;    
    string ten;
    int tuoi;
    public:  
       void setData(int msnv, string ten, int tuoi) {  
            this->msnv = msnv;    
            this->ten = ten;    
            this->tuoi = tuoi; 
       }    
       void showData() {
            cout << "Ten nhan vien: " << this->ten << endl;
            cout << "Ma so nhan vien: " << this->msnv << endl;
            cout << "Tuoi: " << this->tuoi << endl;
       }    
};

int main() { 
    // Nhan vien 1
    NhanVien n1;
    n1.setData(111231, "Nguyen Van A", 24);
    n1.showData();    
     
    // Nhan vien 2
    NhanVien n2 =  NhanVien();
    n2.setData(111232, "Nguyen Van B", 25);
    n2.showData();
    return 0;  
}

```

</details>



<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>

class MyClass {
public:
    void printAddress() {
        std::cout << "Address of current object: " << this << std::endl;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2;
    obj1.printAddress(); // In địa chỉ của đối tượng obj1
    obj2.printAddress(); // In địa chỉ của đối tượng obj2
    return 0;
}



```

</details>




<details>
<summary>Ví dụ:</summary>

```C++
class sinhvien {
	puplic:// phạm vi truy cập
	string ten;//PROPERTY
	int tuoi;
	int mssv;
	void display(){//METHOD
	count<<"ten:"<<ten<<endl;
	count<<"tuoi:"<<tuoi<<endl;
	count<<"mssv:"<<mssv<<endl;

}
};

int main(){
	sinhvien sv1;
	sv1.ten ="hoang";//OBJECT thuộc class sinh viên
	sv1.tuoi=19;
	sv1.mssv =123123;
	sv1.display();// in ra 0.
	return 0;

}

```
- Class có thể khởi tạo giá trị ban đầu:
```C++
class sinhvien {
	puplic:// phạm vi truy cập
	sinhvien(string l_ten , int l_tuoi,string l_lop, int l_ngay){// gia tri ban đầu có tham số đầu vào
		static int  s_mssv;
		mssv=s_mssv;
		s_mssv ++;
		tuoi =l_tuoi;
		ten=l_ten;
		lop=l_lop;
		ngay =l_ngay;
	}
	string ten;//PROPERTY
	stactic int ngay; // static trong class phải khởi tạo giá trị ban đầu 
	int tuoi;
	int mssv;
	string lop;
	string ten;
	void display();//METHOD
	
	//director là 1 cơ chế tự động 
	~sinhvien(){
		count<<"Huy object co ten:"<<ten>>endl;
	}
};

int sinhvien::ngay;// khởi tạo gia trị ban đầu cho static

void sinhvien::display{
	count<<"ten:"<<ten<<endl;
	count<<"tuoi:"<<tuoi<<endl;
	count<<"mssv:"<<mssv<<endl;
	ount<<"lop:"<<mssv<<endl;

}
void test1(){
	sinhvien sv1("thai",19,"CDEE"),sv2("tha",20,"fhsjd",14);//sv1 là OBJECT thuộc class sinhvien
	printf("dia chi sv1.mssv: %p\n",&(sv1.mssv));//khác địa chỉ
	printf("dia chi sv2.mssv: %p\n",&(sv2.mssv));//khác địa chỉ
	printf("--------------");
	printf("dia chi sv1.ngay: %p\n",&(sv1.ngay));//cung  địa chỉ
	printf("dia chi sv2.ngay: %p\n",&(sv2.ngay));//cung địa chỉ
	// Khi khởi tạo thì địa chỉ của nó tồn tại trong suốt chương trình nên member static này của các object sẽ đều có cùng 1 địa chỉ.
	sv1.display();
	sv2.display();	
}

int main(){
	test1();
	return 0;
	// sẽ in ra là ten,tuoi,mssv,lop,Huy object co ten thai
}
```

</details>
</details>














<details>
  <summary><h2>Smart Pointer</h2></summary>

**Cấp phát động trong C++**
- new và delete là hai toán tử quan trọng trong C++ được sử dụng để cấp phát và giải phóng bộ nhớ động, tương ứng

```C++
int *ptr = new int; // cấp phát bộ nhớ cho một biến kiểu int
int *arr = new int[5]; // cấp phát bộ nhớ cho một mảng kiểu int với 5 phần tử

delete ptr; // giải phóng bộ nhớ của biến động
delete[] arr; // giải phóng bộ nhớ của mảng động


```
**Smart Pointer C++**
- smart pointers là một cơ chế quản lý bộ nhớ tự động.
- Memory Leak: là hiện tượng xảy ra khi một chương trình không thể giải phóng bộ nhớ đã cấp phát dẫn đến sự chậm trễ và giảm hiệu suất của chương trình 
	+ Quên giải phóng bộ nhớ
	+ Mất điều kiện để giải phóng: Các tham chiếu vòng (circular references)

**Unique Pointer**
- Chỉ có một smart pointer duy nhất được sở hữu tài nguyên tại một thời điểm.
- Không thể sao chép (copy), chỉ có thể chuyển nhượng quyền sở hữu bằng cách dùng std::move.
```C++
#include <iostream>
#include <memory>

void func() {
    std::unique_ptr<int> uniquePtr(new int(42));
    // uniquePtr sẽ tự động giải phóng vùng nhớ khi ra khỏi hàm func()
}

int main() {
    func();
    // uniquePtr đã bị giải phóng khi ra khỏi hàm func()
    return 0;
}

```
**shared_ptr**
- Chia sẻ quyền sở hữu của một tài nguyên giữa nhiều shared_ptr.
- Bộ đếm tham chiếu (reference count) được duy trì để theo dõi số lượng shared_ptr sở hữu tài nguyên.
- Tài nguyên được giải phóng khi bộ đếm tham chiếu bằng 0 (không còn shared_ptr nào sở hữu).


```C++
#include <iostream>
#include <memory>

int main() {
    // Khởi tạo một biến int x với giá trị 42
    int x = 42;

    // Tạo ba shared_ptr để trỏ đến biến int x
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(x);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::shared_ptr<int> sharedPtr3 = sharedPtr1;

    // In ra địa chỉ của x và số lượng tham chiếu của mỗi shared_ptr
    std::cout << "Địa chỉ của x: " << &x << std::endl;
    std::cout << "sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    std::cout << "sharedPtr2: " << sharedPtr2.use_count() << std::endl;
    std::cout << "sharedPtr3: " << sharedPtr3.use_count() << std::endl;

    return 0;
}


```

**weak_ptr**
- weak_ptr không sở hữu đối tượng, chỉ giám sát đối tượng do shared_ptr quản lý.
- Muốn sd weak_ptr phải chuyển weak_ptr thành shared_ptr bằng lock, bạm thời tăng ref count của đối tượng.
- lock() sẽ trả về nullptr.Nếu đối tượng bị hủy
- Trước khi sử dụng tài nguyên, cần chuyển weak_ptr thành shared_ptr bằng lock().
- Tránh vòng tham chiếu (`circular reference`).- 

**Lặp tham chiếu**
- xảy ra khi hai hoặc nhiều đối tượng trỏ qua lại lẫn nhau bằng shared_ptr
- bộ đếm tham chiếu của chúng sẽ luôn lớn hơn 0 .Do đó, tài nguyên sẽ không bao giờ được giải phóng.
- Object A có một shared_ptr quản lý để đảm bảo sự tồn tại của nó.
- Object A có một shared_ptr trỏ đến Object B, làm tăng ref count của Object B.
- Object B giữ một weak_ptr trỏ ngược lại Object A, giúp tránh vòng lặp tham chiếu.

<details>
<summary>Ví dụ:</summary>

```C++
#include <memory>
#include <iostream>
class B; // Forward declaration to use in A
class A {
public:
    std::shared_ptr<B> ptrB; // A uses shared_ptr to reference B
};
class A; // Forward declaration to use in B
class B {
public:
    std::weak_ptr<A> ptrA; // B uses weak_ptr to reference A
};

class A;
class B;
int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->ptrB = b; // A references B using shared_ptr
    b->ptrA = a; // B references A using weak_ptr
    // When main ends, a and b will be automatically released safely
    return 0;
}


```
 

</details>

<details>
<summary>Ví dụ:</summary>

```C++
std::shared_ptr<A> a_shared = ptrA.lock();
if (a_shared) {
    // Thực hiện các thao tác với a_shared ở đây
    std::cout << "Process A successful!" << std::endl;
} else {
    std::cout << "A is no longer available." << std::endl;
}

```
 

-  lock() trên một std::weak_ptr, nếu đối tượng mà weak_ptr đang theo dõi vẫn tồn tại , lock() sẽ trả về một std::shared_ptr hợp lệ trỏ đến đối tượng đó. Điều này có nghĩa là bạn có thể sử dụng shared_ptr này để truy cập và thao tác với đối tượng an toàn.
- Nếu A vẫn tồn tại, ptrA.lock() sẽ trả về một shared_ptr<A> hợp lệ (a_shared), và bạn có thể sử dụng a_shared để thực hiện các thao tác như thông báo "Process A successful!". Ngược lại, nếu A đã bị hủy, ptrA.lock() sẽ trả về một shared_ptr<A> rỗng, và bạn sẽ nhận được thông báo "A is no longer available."
- lock():Giúp đảm bảo rằng bạn chỉ truy cập vào đối tượng khi nó vẫn còn tồn tại, tránh gây ra lỗi truy cập vào bộ nhớ đã giải phóng.

 
</details>















</details>
<details>
  <summary><h2>namespace</h2></summary>

- Namespace:là từ khóa trong C++ được sử dụng để phân biệt các hàm, lớp, biến cùng tên trong các file khác nhau.
 tạo những vùng nhớ khác nhau ,mỗi namespace là 1 chương trình riêng ,Nhưng trong 1 namespace không thể có 2 biến cùng tên
- using namespace std ,cho phép sử dụng các thành phần trong namespace std, mà không cần phải ghi rõ std::cout,cin 
<details>
<summary>Ví dụ:</summary>

```C++
//fileB.hpp

#include <iostream>

using namespace std;

namespace fileB{
    void function(() { cout << “function in fileB running.” << endl; }
}
//fileC.hpp
#include <iostream>

using namespace std;

namespace fileC{
    void function(() { cout << “function in fileC running.” endl; }
}


# 

```
**Dùng using namespace tên, có thể rút gọn code**
- Ví dụ:
```C++
using namespace onga;
int main(){
	cout<<"con ong a: teo"<<teo<<endl;
	return 0;
	
}

// FILE MAIN.CPP
#include <iostream>
#incldue “fileB.hpp”
#include “fileC.hpp”

using namespace std;

int main() {
    fileB::function();
    fileC::function();
    
    return 0;
}

 

```

</details>
</details>
<details>
  <summary><h2>Lambda,templates</h2></summary>

 
## ⚡ Lambda Expression trong C++

### 🔸 Lambda là gì?
- Lambda là hàm **vô danh** (không tên), khai báo ngay tại chỗ, giúp viết code **ngắn gọn và linh hoạt**.
- Dạng tổng quát:

```cpp
[capture clause] (parameter list) -> return type { body }
```

### 🔸 Thành phần:
| Thành phần        | Mô tả                                                                 |
|-------------------|----------------------------------------------------------------------|
| `capture clause`  | Cách truy cập biến bên ngoài: `[]`, `[=]`, `[&]`                      |
| `parameter list`  | Danh sách tham số (giống hàm thông thường)                           |
| `return type`     | (Tùy chọn) Kiểu trả về. Có thể bỏ qua nếu trình biên dịch tự suy luận |
| `body`            | Phần thân của hàm                                                    |

### 🔸 Capture kiểu:
| Cách capture     | Ý nghĩa                                                                 |
|------------------|-------------------------------------------------------------------------|
| `[]`             | Không capture biến nào                                                 |
| `[=]`            | Capture tất cả biến xung quanh **bằng giá trị**                       |
| `[&]`            | Capture tất cả biến xung quanh **bằng tham chiếu**                    |
| `[a, &b]`        | Capture cụ thể biến `a` bằng giá trị, `b` bằng tham chiếu              |

### 🔸 Ví dụ minh họa:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int x = 10, y = 20;

    auto add = [=]() { return x + y; };     // capture by value
    auto modify = [&]() { x += 5; };        // capture by reference

    std::cout << "Add: " << add() << std::endl; // 30
    modify();
    std::cout << "x after modify: " << x << std::endl; // 15

    std::vector<int> nums = {1, 2, 3};
    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << n * n << " ";
    }); // In ra bình phương
    return 0;
}
```

### ✅ Lợi ích
- Giúp **tránh tạo hàm rườm rà**.
- Dễ truyền làm đối số cho hàm (`std::sort`, `std::for_each`...)
- Thường dùng trong các thư viện STL và lập trình hàm.

 📦 Templates trong C++

## ✅ 1. Khái niệm

Template là một **kỹ thuật tổng quát hóa** trong C++, cho phép viết mã có thể áp dụng cho nhiều kiểu dữ liệu khác nhau (int, float, string, v.v.) mà **không cần viết lại logic**.

> Templates giúp viết mã ngắn gọn, tái sử dụng và giảm lỗi.

---

## 🧱 2. Các loại Template

### 🔹 2.1 Function Template

Cho phép định nghĩa các hàm làm việc với nhiều kiểu dữ liệu.

```cpp
template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(3, 4);       // int
    cout << add(3.5, 2.1);   // double
}
```

---

### 🔹 2.2 Class Template

Dùng để tạo các lớp tổng quát hóa, áp dụng cho nhiều kiểu dữ liệu.

```cpp
template<typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    void show() { cout << value; }
};

int main() {
    Box<int> b1(100);
    Box<string> b2("hello");
}
```

---

### 🔹 2.3 Variadic Template (C++11 trở lên)

Cho phép định nghĩa hàm hoặc lớp với **số lượng tham số không xác định**.

```cpp
template<typename T>
void print(T t) {
    cout << t << endl;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << ", ";
    print(args...);  // Đệ quy
}

int main() {
    print(1, 2.5, "abc", true);
}
```

---

## 📌 3. Lưu ý

- Có thể dùng `template<typename T>` hoặc `template<class T>` — cả hai đều hợp lệ.
- Khi biên dịch, compiler sẽ **tự tạo ra các phiên bản** tương ứng với từng kiểu dữ liệu được dùng.
- Templates có thể kết hợp với các tính năng khác như `constexpr`, `auto`, `concepts` (C++20).

---

## ✅ 4. Tổng kết

Templates là một công cụ mạnh mẽ trong C++ để viết **mã tổng quát**, **giảm trùng lặp**, và **cải thiện khả năng bảo trì**. Cần hiểu rõ cách hoạt động và khi nào nên áp dụng để tránh lỗi phức tạp khi biên dịch.
	

**Virtual Function**
- Hàm ảo , cho phép hàm của lớp con ghi đè lên hàm lớp cha






</details>
<details>
<summary><h3>Hướng đối tượng </h3></summary>

### hướng đối tượng là gi?
- OOP là một phương pháp lập trình dưới dạng các "đối tượng," mỗi đối tượng có chứa dữ liệu và các phương thức để thao tác dữ liệu đó.
- Các khái niệm quan trọng trong OOP bao gồm:
	+ Class: để tạo ra các đối tượng , nó mô tả dữ liệu và phương thức của đối tượng đó
	+ Đối tượng (Object) : Một đối tượng cụ thể được tạo ra từ class, có 
**Phạm vi truy cập:**
- Public:Member nào trong Public thì có thể truy cập từ mọi nơi trong chương trình , bao gồm object của lớp và từ các lớp khác thông qua method của lớp đó, có thể truy cập được
- protected:Member trong protected thì method của Class con và method trong class có thể truy cập
- private: Chỉ có method  trong class có thể truy cập .

```c++
#include <iostream>

class ClassA {
public:
    int publicVarA;

    ClassA() : publicVarA(0) {}
};

class ClassB {
public:
    void accessPublicVar(ClassA &objA) {
        std::cout << "Value of publicVarA from ClassB: " << objA.publicVarA << std::endl;
    }
};

int main() {
    ClassA objA;
    ClassB objB;

    objA.publicVarA = 42; // Gán giá trị cho thành viên publicVarA của đối tượng objA

    objB.accessPublicVar(objA); // Truy cập thành viên publicVarA của đối tượng objA từ đối tượng objB

    return 0;
}






```

**1/Encapsulation (Tính đóng gói):**
- PROPERTY phải nằm ở private hoặc protected.
- Lý do để bảo vệ dữ liệu của một đối tượng khỏi sự xâm phạm từ bên ngoài.

<details>
<summary>Ví dụ:</summary>

```C++
#include<iostream>
#include<string>
using namespace std;
class doituong{
	private:
	int tuoi;//PROPERTY
	string ten;

	public:
	void hienthi(){//hienthi() method
	    cout<<"ten: "<<ten<<endl;
		cout<<"tuoi: "<<tuoi<<endl;
	}
	void setten(int name){
		ten=name;
	}
	void settuoi(int old){
		tuoi=old;
	}
	int gettuoi(){
		return tuoi;

	}
	string getten(){
		return ten;

	}
	

}
int main(){
	doituong dt;//dt là object thuộc class doituong
	dt.hienthi();
	return 0;
 }
```
</details>

**2/Inheritance (Tính kế thừa ):**
- 1 class được kế thừa property và method của một class khác
- Class con có thể kế thừa property và method của class cha trong phạm vi public và protected  
- Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.
- Nên dùng: Khi một lớp B được miêu tả là "B là một A". Ví dụ: một lớp hình tròn có thể kế thừa từ một lớp hình học.
- Không nên:Mối quan hệ "has-a" (có một) diễn ra khi một lớp chứa một đối tượng của một lớp khác. ví dụ: danhsachSV chứa một đối tượng sinhvien, do đó chúng ta có thể nói danhsachSV "có" hoặc "bao gồm" danh sách các sinh viên.

<details>
<summary>Ví dụ:</summary>

```C++
using namespace std;

class doituong{

	protected:
	int namsinh;
	string ten;
	int tuoi;
	public:
	void nhapthongtin(string name,int old,int year){ 
	    	ten=name;
			tuoi=old;
			namsinh=year;
	}
	void hienthi(){//hienthi() method cha
	    	cout<<"ten: "<<ten<<endl;
			cout<<"tuoi: "<<tuoi<<endl;
			cout<<"namsinh: "<<namsinh<<endl;
	}

};

class sinhvien : public doituong{
    protected:
	int MSSV;
	public:
	void setMSSV(int mssv){
		MSSV=mssv;
	}
	void hienthi(){// là method con từ cha và sửa nó thì được gọi là override(ghi đè)
		cout<<"MSSV: "<<MSSV<<endl;
		cout<<"ten: "<<ten<<endl;
		cout<<"tuoi: "<<tuoi<<endl;
		cout<<"namsinh: "<<namsinh<<endl;
		

	}

};


class HS : public sinhvien{
    private:
	int HS;
	public:
	void setHS(int hs){
		HS=hs;
	}
	void hienthi();

};
//thằng HS sẽ kế thừa thằng gần nhất >> hienthi(), sẽ kế thừa hienthi() của sinhvien chứ không phải doituong
int main(void){
    doituong dt;
	sinhvien sv;
	dt.nhapthongtin("hung",24,1883);
	dt.hienthi();
	printf("-----------\n");
	sv.nhapthongtin("thai",25,1992);
	sv.hienthi();

    return 0;
}
//ten: hung
//tuoi: 24
//namsinh: 1883
-----------
//MSSV: 0
//ten: thai
//tuoi: 25
//namsinh: 1992

```
</details>


<details>
<summary>Ví dụ:</summary>

```C++
class doituong{
	protected:
	int namsinh;
	string ten;
	int tuoi;
	public:
	void nhapthongtin(string name,int old,int year){ 
	    	ten=name;
			tuoi=old;
			namsinh=year;
	}

};

class sinhvien : private doituong{	
	// tất cả property  của doituong sẽ chuyển vào private của sinhvien
 

};

class hs : private sinhvien{
 // lỗi vì thằng private không kế thừa và sử dụng được từ class con
};

```

</details>

**3/Polymorphism (Tính đa hình):**

- Function overloading :Các method có thể trùng tên với nhau , nhưng phải khác các input parameter
- Function overoverriding : Lớp con Ghi đè lên hàm của lớp cha.
- Để ghi đè đúng cách, hàm trong lớp cơ sở nên được khai báo với từ khóa virtual.
<details>
<summary>Ví dụ:</summary>

```C++
using namespace std;

class ToanHoc {
public:
    void tong(int a, int b) {
        cout << "Tong a + b: " << a + b << endl;
    }

    void hienthi(int a, int b, int c) {
        cout << "Tong a + b + c: " << a + b + c << endl;
    }

    void hienthi(int a, double b) {
        cout << "Tong a + b : " << a + b << endl;
    }
};

int main() {
    ToanHoc th;
    th.tong(7, 4);
    th.hienthi(1,2,3);
    th.hienthi(1,1.1);
     

    return 0;
}
```
</details>

**4/Abstraction (Tính trừu tượng ):**

- Chỉ cung cấp giao diện, ẩn đi chi tiết triển khai.
- Ví dụ tính phương trình bậc 2 , để tính nghiệm x1,x2 thì ta có hàm tính detal = b * b - 4 * a * c .delta là 1 trong những thành phần tạo ra kết quả.Vậy thì hàm tính delta này phải được ẩn đi bằng cách để nó vào phạm vi private


# 🔒 Abstraction (Tính trừu tượng) trong C++

## ✅ 1. Khái niệm

- **Abstraction** là quá trình **ẩn đi chi tiết hiện thực** và chỉ **hiển thị những gì cần thiết** với người dùng.
- Giúp giảm sự phức tạp và tăng tính bảo trì trong chương trình.
- Trong C++, abstraction được thực hiện thông qua:
  - **Lớp trừu tượng (abstract class)**
  - **Hàm ảo thuần túy (pure virtual function)**

---

## 🧱 2. Lớp trừu tượng (Abstract Class)

- Là lớp có ít nhất **một hàm ảo thuần túy** (`= 0`).
- Không thể tạo đối tượng trực tiếp từ lớp trừu tượng.
- Chỉ dùng để **kế thừa và triển khai các hành vi cụ thể** ở lớp con.

```cpp
class Animal {
public:
    virtual void speak() = 0;  // Hàm thuần ảo
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!
";
    }
};
```

---

## 🧠 3. Mục tiêu của abstraction

| Mục tiêu                 | Ý nghĩa |
|--------------------------|--------|
| Ẩn chi tiết triển khai   | Người dùng không cần biết cách lớp hoạt động nội bộ |
| Tăng tính mô-đun         | Tách giao diện và thực thi giúp dễ bảo trì, nâng cấp |
| Hỗ trợ thiết kế hướng đối tượng | Là một trong bốn trụ cột OOP: Encapsulation, Inheritance, Polymorphism, Abstraction |

---

## 📌 4. Sự khác biệt giữa Abstraction và Encapsulation

| Đặc điểm        | Abstraction                       | Encapsulation                  |
|-----------------|------------------------------------|--------------------------------|
| Mục tiêu chính  | Ẩn chi tiết logic không cần thiết | Giấu dữ liệu để bảo vệ thông tin |
| Triển khai      | Lớp trừu tượng, hàm ảo thuần túy   | Access modifiers (private, protected) |
| Người dùng thấy | Giao diện hoặc hành vi cần thiết  | Không thấy dữ liệu nội bộ     |

---

## ✅ 5. Tổng kết

- Abstraction giúp **tập trung vào cái "gì" hệ thống làm**, thay vì "làm như thế nào".
- Là công cụ mạnh để thiết kế hệ thống linh hoạt, có thể mở rộng.
- Sử dụng qua abstract class là cách phổ biến trong C++ để đạt tính trừu tượng.



</details>

**Hàm Bạn,Lớp Bạn?**
- Là các khái niệm cho phép một hàm hoặc một lớp khác có thể truy cập các thành viên private hoặc protected của một lớp.

**Template trong C++ là gì?**

- Là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- Có 2 loại  Templates:
	+ Class Templates: cho phép proberti và method trong Class có kiểu dữ liệu template
	+ Function templates:cho phép viết một hàm với kiểu dữ liêu template , kiểu template sẽ tổng quát hóa nhiều kiểu dữ liệu khác, làm mã ngắn gọn hơn mà không cần triển khai lại hàm với kiểu dữ liệu cụ thể
		- Ví dụ 1 hàm có tham số truyền vào là int , int thì ta phải viết 1 hàm có cùng kiểu dữ liệu đó , nhưng nếu viết hàm dùng kiểu dữ liêu template, thì không cần quan tâm đến thông số truyền vào là kiểu dữ liệu gì

<details>
<summary>Ví dụ</summary>

```C++	
void hienthi(int a,int b ,int c){ 
		printf("tong a+b+c :%d\n",a+b+c);
}
int hienthi(int a,double b){ 		
		return a +(int)b;
}
//thay vì dài như vậy ta có thể dùng Template do C++ hỗ trợ
//Code viết lại:
template <typename test>
test tong(test a,test b){
	return test(a +b);
}
int main(void){
	tong("tong a va b: %d\n",tong(6,4));
	tong("tong a va b: %f\n",tong(6.5,4.4));
} 
```
</details>


**Virtual funtion trong C++ là gì?**
- Được sử dụng để tạo hàm ảo. Hàm ảo cho phép lớp con ghi đè hàm của lớp cha  .



</details>
</details>
<details>
  <summary><h2>Standard template library </h2></summary>
STL là thư viện mạnh mẽ trong C++ giúp xử lý dữ liệu hiệu quả với ba thành phần chính:

### 🔹 1. Containers (Bộ chứa)
- Dùng để lưu trữ dữ liệu.
- Các loại phổ biến:

| Container             | Đặc điểm chính                                                                 | Ứng dụng tiêu biểu                                       |
|-----------------------|--------------------------------------------------------------------------------|----------------------------------------------------------|
| `vector`              | Mảng động, truy cập ngẫu nhiên, thêm/xóa cuối hiệu quả                       | Danh sách điểm, mảng kết quả, tập hợp dữ liệu biến đổi   |
| `list`                | Danh sách liên kết đôi, chèn/xóa ở bất kỳ đâu, không truy cập ngẫu nhiên     | Hàng đợi xử lý công việc cần xóa/chèn linh hoạt          |
| `deque`               | Hàng đôi, thêm/xóa ở đầu/cuối, truy cập nhanh                                 | Trình duyệt lịch sử, undo/redo                          |
| `set`                 | Tập hợp phần tử không trùng, tự sắp xếp                                               | Lọc trùng, lưu danh sách ID duy nhất                     |
| `multiset`            | Cho phép phần tử trùng, vẫn sắp xếp                                           | Thống kê dữ liệu, đa số phiếu                           |
| `unordered_set`       | Không trùng, không sắp xếp                                                     | Kiểm tra tồn tại nhanh (lookup)                         |
| `unordered_multiset`  | Trùng lặp, không sắp xếp                                                      | Lưu trữ dữ liệu phân bố không quan trọng thứ tự         |
| `map`                 | Cặp key-value, key duy nhất, tự sắp xếp                                       | Từ điển, bảng cấu hình theo ID                          |
| `multimap`            | Cho phép nhiều value cho cùng 1 key                                           | Lưu danh sách học sinh theo lớp, từ đa nghĩa            |
| `unordered_map`       | Key duy nhất, không sắp xếp                                                    | Hash table, cache                                       |
| `unordered_multimap`  | Key trùng, không sắp xếp                                                      | Lưu log theo ID, group data nhanh                       |
| `stack`               | Cấu trúc LIFO, thêm/xóa trên đỉnh                                             | Gọi hàm, undo hành động                                |
| `queue`               | Cấu trúc FIFO, thêm cuối - xóa đầu                                            | Hệ thống hàng đợi, xử lý yêu cầu tuần tự                |

---

### 🔹 2. Iterators
- Cho phép duyệt phần tử trong container một cách tổng quát.
- Kết hợp với `algorithm` để duyệt, sắp xếp, lọc...

| Loại Iterator     | Mô tả                                                   |
|-------------------|----------------------------------------------------------|
| `Input Iterator`  | Đọc dữ liệu, không thay đổi                             |
| `Output Iterator` | Ghi dữ liệu                                              |
| `Forward Iterator`| Duyệt tiến, đọc và ghi                                   |
| `Bidirectional`   | Duyệt tiến/lùi                                           |
| `Random Access`   | Duyệt mọi vị trí như con trỏ                             |

---

### 🔹 3. Algorithms
STL cung cấp nhiều thuật toán dùng chung cho mọi container:

| Thuật toán         | Mô tả                                     |
|--------------------|--------------------------------------------|
| `std::sort`        | Sắp xếp                                   |
| `std::find`        | Tìm phần tử                               |
| `std::for_each`    | Áp dụng hàm lên mỗi phần tử               |
| `std::count`       | Đếm số lần xuất hiện                      |
| `std::binary_search` | Tìm kiếm nhị phân (dãy đã sắp xếp)     |

---

### ✅ Khi nào dùng gì?
- `vector`: Truy cập nhanh, thêm cuối danh sách.
- `list`: Chèn/xóa giữa danh sách thường xuyên.
- `deque`: Chèn/xóa hai đầu hiệu quả.
- `map`: Tra cứu theo key, cần sắp xếp.
- `unordered_map`: Tra cứu nhanh, không cần sắp xếp.
- `set`: Dữ liệu duy nhất, tự sắp xếp.
- `stack/queue`: Cần cấu trúc dữ liệu chuẩn LIFO/FIFO.

---











</details>
<details>
  <summary><h2>Multithreading</h2></summary>


# 🧵 Lập trình đa luồng (Multithreading) trong C++

## 📌 Khái niệm cơ bản

- **Process (Tiến trình)**: Là một chương trình đang được thực thi.
- **Thread (Luồng)**: Là một đơn vị thực thi độc lập trong một process.
- **Multithreading**: Là kỹ thuật sử dụng nhiều luồng đồng thời để tăng hiệu suất và tận dụng tài nguyên hệ thống.
- Để sử dụng multithreading:
  ```cpp
  #include <thread>
  ```

---

## ❗️Các vấn đề thường gặp trong đa luồng

### 1. Data Race (Tranh chấp dữ liệu)

- Xảy ra khi nhiều luồng cùng lúc truy cập và thay đổi một biến dùng chung mà không có đồng bộ.
- **Cách khắc phục**:
  - Dùng `std::mutex`, `std::lock_guard`, `std::atomic`.

---

### 2. Deadlock (Chết cứng)

- Khi các luồng chờ nhau giải phóng tài nguyên, dẫn đến vòng lặp chờ vô hạn.
- **Cách phòng tránh**:
  - Khóa theo cùng thứ tự (Hierarchical Locking).
  - Dùng `try_lock` hoặc `std::unique_lock` với timeout.
  - Hạn chế giữ nhiều mutex cùng lúc nếu không cần thiết.

---

### 3. Race Condition (Điều kiện tranh chấp)

- Khi kết quả phụ thuộc vào thứ tự thực hiện của các luồng.
- **Cách xử lý**:
  - Sử dụng biến cờ đồng bộ hoặc `std::condition_variable`.

---

### 4. Starvation (Đói tài nguyên)

- Một số luồng không thể truy cập tài nguyên vì bị các luồng khác liên tục chiếm dụng.
- **Cách giảm thiểu**:
  - Dùng `condition_variable` để điều phối.
  - Đặt timeout cho việc truy cập tài nguyên.

---

## 🔒 Cơ chế đồng bộ hóa (Synchronization Mechanisms)

### 📘 Khái niệm

- **Đồng bộ hóa**: Giúp các luồng phối hợp an toàn khi truy cập dữ liệu dùng chung.
- Thư viện cần dùng:
  ```cpp
  #include <mutex>
  #include <shared_mutex> // (C++17 trở lên)
  ```

### 🔧 Các cơ chế

| Cơ chế               | Mô tả |
|----------------------|-------|
| `std::mutex`         | Khóa tài nguyên, chỉ một luồng được phép truy cập |
| `lock()` / `unlock()`| Khóa và mở khóa mutex thủ công |
| `std::lock_guard`    | Tự động lock và unlock khi ra khỏi scope |
| `std::unique_lock`   | Linh hoạt hơn, hỗ trợ unlock tạm thời |
| `std::shared_lock`   | Cho phép nhiều luồng đọc đồng thời (C++17) |

---

## 🧱 Cấu trúc dữ liệu đồng thời (Concurrent Data Structures)

### 📌 `std::condition_variable`

- Dùng để **chờ đợi và thông báo** giữa các luồng.
- Hữu ích khi một luồng cần đợi điều kiện từ luồng khác.

### Các hàm chính:

- `wait()`: Chờ đến khi điều kiện đúng.
- `notify_one()`: Đánh thức một luồng đang chờ.
- `notify_all()`: Đánh thức tất cả các luồng đang chờ.

> `wait()` sẽ **tự unlock mutex** khi chờ và **lock lại** khi tiếp tục.

---

## ⚡ Bất đồng bộ (Asynchronous)

### 📘 Khái niệm

- Thực hiện tác vụ mà **không cần chờ kết quả ngay**.
- Ví dụ:
  - Thread 1 thực hiện công việc xong và gọi `notify_one()`.
  - Thread 2 đang `wait()` sẽ được đánh thức để tiếp tục chạy.

> Cơ chế bất đồng bộ giúp tiết kiệm thời gian và tăng hiệu suất chương trình.

---

## ✅ Tổng kết

Multithreading giúp cải thiện hiệu năng chương trình, nhưng cũng đi kèm nhiều thách thức như race condition, deadlock, starvation. Việc sử dụng đúng các cơ chế đồng bộ hóa như mutex, condition_variable và các kỹ thuật thiết kế giúp đảm bảo chương trình chạy an toàn và hiệu quả.

</details>

</details>

</details>

</details>

</details>
<details>
  <summary><h1>▶ ⭐Embedded</h1></summary>

<details>
  <summary><h2>1 Số câu hỏi 2025</h2></summary

 
![image](https://github.com/user-attachments/assets/3a28a482-0162-432c-8e95-92e0fc8d669d)





 




**Trình tự hoạt động của ngắt**
- Peripheral: Gửi tín hiệu ngắt (ví dụ: Timer, UART, GPIO).
- NVIC: bộ điều khiển ngắt
	- Kích hoạt hoặc vô hiệu hóa ngắt.
	- Quyết định mức độ ưu tiên (priority) của các ngắt.
- Kiểm tra trạng thái ngắt (đã kích hoạt hay chưa).
- Kiểm tra mức độ ưu tiên.
- Vector Ngắt: NVIC tra bảng Vector Ngắt để lấy địa chỉ ISR tương ứng.
- ISR: CPU chuyển quyền điều khiển tới ISR để xử lý ngắt.
- Trở về: Sau khi ISR hoàn thành, CPU quay lại thực hiện tác vụ trước đó






**Variadic Functions, Assert là gì**
- Variadic Functions hàm có thể nhận số lượng tham số đầu vào không xác định( dùng thư viện <stdarg.h>)
- Hạn chế vì cần phải biết rõ kiểu dữ liệu truyền vào, vì va_list không lưu các kiểu dữ liệu của tham số 
- Xác định các tham số tại thời điểm chạy
- Trong C++,  dùng template để tránh rủi ro này.
- Assert là một câu lệnh dùng để debug , nếu điều kiện là sai sẽ dừng chương trình





**ARM Cortex**
- ARM Cortex là một kiến trúc vi xử lý được thiết kế bởi arm
- ARM Cortex được xây dựng trên kiến trúc RISC 
	- kiến trúc RISC tập trung vào:
		- Tập lệnh đơn giản  
		- Tiêu thụ năng lượng thấp.
- Các công ty như STM, NXP, Qualcomm.. mua bản quyền thiết kế để phát triển vi xử lý cụ thể  của họ
- ARM Cortex được chia thành ba nhóm chính;
	- Cortex-M:
		- Dành cho thiết bị nhúng, IoT yêu cầu tiết kiệm năng lượng, chi phí thấp.
		- Như thiết bị thông minh.
	- Cortex-A:
		- Dành cho thiết bị yêu cầu hiệu năng cao
		- Thường dùng trong điện thoại thông minh
	- Cortex-R:
		- Dành cho hệ thống thời gian thực , đòi hỏi độ tin cậy như phanh ABS,thiết bị y tế
- So sánh ARM Cortex-M0, M3, M4, và M7:
	- Cortex-M0/M0+:  tiết kiệm năng lượng, hiệu suất thấp,rẻ
	- Cortex-M3: Hiệu năng trung bình, ứng dụng nhúng phổ biến.
	- Cortex-M4: hỗ trợ xử lý tín hiệu số và dấu phẩy động.(FPU )
		- dấu phẩy động :Biểu diễn số rất lớn hoặc rất nhỏ dấu phẩy động
	- Cortex-M7: Mạnh nhất, phù hợp các hệ thống yêu cầu hiệu năng cao, tốn năng lượng , giá thành cao

- NVIC 
	- Bảng ưu tiên ngắt (Interrupt Priority Table):

		- Lưu trữ mức ưu tiên  .
		- Ngắt có ưu tiên cao hơn sẽ được xử lý trước.
  	-  Bảng địa chỉ vector ngắt:
		-  Mỗi ngắt ứng với 1 địa chỉ 
		-  Đảm bảo CPU nhảy tới đúng hàm xử lý khi ngắt xảy ra.
- bảng điều chỉnh ưu tiên (Priority Grouping):
	- Chia thành (group priority) và  (sub-priority), để linh hoạt hơn trong xử lý ngắt.
	- Group  xác định ngắt nào được xử lý trước.
	- Sub :Chỉ được xét khi các ngắt có cùng Group Priority.


- là bộ điều khiển ngắt cho phép nhiều nguồn ngắt được xử lý dựa trên mức ưu tiên
- đảm bảo các ngắt quan trọng được thực thi trước


- Cách cấu hình ngắt ngoại vi trên ARM Cortex-M4 (đơn giản):
	- Bật clock cho ngoại vi và GPIO
	- Cấu hình chân GPIO:
		- SET GPIO làm input và  interrupt
	-  Cấu hình EXTI (External Interrupt)(ngắt ngoài):
		- Liên kết chân GPIO với EXTI Line tương ứng.
		- Chọn chế độ kích hoạt ngắt: Rising edge, Falling edge, hoặc Both edges.
	- Thiết lập NVIC:
		-  Đặt mức ưu tiên và bật ngắt trong NVIC.
    - Viết ISR (Interrupt Service Routine):
		- Viết hàm xử lý ngắt để thực hiện hành động khi ngắt xảy ra.
- Cách cấu hình clock system trên ARM Cortex-M4
	-  Chọn HSE/hsi làm nguồn clock (ví dụ: thạch anh 8 MHz).
	- Sử dụng PLL để nhân tần số lên 168 MHz.
	- Đặt PLL làm clock chính (System Clock).
    - Chia tần số cho các bus và ngoại vi (ví dụ: AHB, APB1, APB2).
- Làm thế nào để giảm mức tiêu thụ năng lượng của hệ thống?
	- Sử dụng chế độ Sleep hoặc Stop 
	- Tắt các ngoại vi không sử dụng.




**C/C++/MISRA C**
- Thường dùng C11,C++11, MISRA 12 
- MISRA  là 1 tiểu chuẩn để phát triển mã nguồn
	- Giảm thiểu lỗi và tăng tính ổn định 
	- Tăng khả năng tái sử dụng của mã nguồn

**khó khăn khi làm việc nhóm**
- Khi tôi mới vào công ty, tôi gặp không ít khó khăn khi làm việc nhóm, từ việc chưa quen với quy trình cho đến thiếu kinh nghiệm. 
- Tuy nhiên, nhờ sự lắng nghe,chủ động học hỏi từ những người đi trước và không ngại hỏi khi có điều chưa rõ. 
- Qua thời gian, tôi không chỉ cải thiện kỹ năng làm việc nhóm mà còn đóng góp hiệu quả hơn vào các dự án chung

**OT**
- Với 1 sự trách nhiệm , tôi luôn sẵn sàng OT để hoàn thành nhiệm vụ.

**Khi leader giao task,cần**
- tôi lắng nghe kỹ để hiểu rõ yêu cầu
- Hỏi điều thắc mắc để tránh sai só
-  lập kế hoạch chi tiết để đảm bảo hoàn thành
- Cập nhật tiến độ với leader , để đảm bảo đúng Hướng

**Linux Embedded là gì?**

- Linux Embedded là hệ điều hành được tối ưu hóa để chạy trên các thiết bị nhúng (embedded devices).
- Thường có tài nguyên hạn chế (RAM, CPU, bộ nhớ) có thể được sử dụng cho các ứng dụng phức tạp như router, modem, hoặc IoT.
- Không phải RTOS vì:
	- Linux không đảm bảo thời gian thực (real-time deadlines).
	- Hệ thống lập lịch của Linux được tối ưu hóa cho đa nhiệm và công bằng hơn là độ trễ thấp.
-  RTOS (Real-Time Operating System) là một hệ điều hành được thiết kế để Đảm bảo thời gian thực, 
phù hợp với các ứng dụng yêu cầu độ trễ thấp và tính chính xác cao.
- Bao gồm nhiều hệ điều hành thời gian thực khác nhau như VxWorks, QNX, RTEMS, uC/OS, và FreeRTOS.


**TCP/IP,UDP**
- TCP /UDP là giao thứ để truyền, nhận dữ liệu giữa các thiết bị thông qua mạng máy tính.mạng nội bộ.
- TCP giao thức  truyền nhận đảm bảo dữ liệu được truyền đầy đủ và theo thứ tự.(Web , Email , hoặc truyền file (FTP).)
- IP là giao thức lớp thấp hơn, chịu trách nhiệm định tuyến và chuyển tiếp dữ liệu qua các mạng.
- UDP không đảm bảo dữ liệu đến đầy đủ hoặc theo thứ tự.Gửi dữ liệu nhanh chóng(Streaming , chơi game online.)

- Router FPT:
	- Sử dụng giao thức TCP/IP   kết nối giữa client và server.
	- UDP dùng trong các ứng dụng cần tốc độ cao như truyền video qua Wi-Fi.game online.
- Tạo socket:
	- Lập trình mạng thường sử dụng sockets – giao diện để giao tiếp qua mạng.
	- Trong TCP, socket sẽ thiết lập kết nối giữa client và server.
	- Trong UDP, socket gửi dữ liệu ngay lập tức mà không cần thiết lập kết nối.

**ESP32**
- Dự án thử nghiệm khả năng đọc dữ liệu cảm biến, điều khiển thiết bị qua Wi-Fi.

**scanf**
- Hàm scanf yêu cầu một địa chỉ của biến để lưu giá trị mà người dùng nhập vào.
- Không cung cấp địa chỉ (mà chỉ cung cấp giá trị), scanf không biết vị trí trong bộ nhớ để lưu giá trị, dẫn đến lỗi.
- Trường hợp ngoại lệ (không cần &)
1. Mảng char :(không cần &) mảng kiểu khác vẫn dùng `&`
	- tên mảng đã đại diện cho địa chỉ của phần tử đầu tiên:
		`char str[100];`
		`scanf("%s", str); // Không cần & vì tên mảng là địa chỉ`
2. Con trỏ: một con trỏ trỏ đến vùng nhớ hợp lệ,  không cần & vì con trỏ đã chứa địa chỉ:

```C

int x;
int *ptr = &x;
scanf("%d", ptr); // Không cần & vì ptr đã là địa chỉ


```

**while và do-while**
- while kiểm tra điều kiện trước và có khả năng vòng lặp không chạy lần nào.
- do-while nếu bạn cần đảm bảo rằng khối lệnh chạy ít nhất một lần, bất kể điều kiện ban đầu.




**Khó khăn khi lập trình C/C++ với vi điều khiển**
1. Phải Hiểu về phần cứng , hiểu cách cấu hình thanh ghi ngoại vi
	+ Ví dụ:Khi sử dụng ADC, bạn cần cấu hình đúng nguồn tham chiếu, độ phân giải, và các kênh phù hợp.
2. Phải quản lý tốt bộ nhớ vì thiết bị thường có bộ nhớ hạn chế(vài KB>MB)
3. Tối ưu hóa hiệu suất:
	+ Vi điều khiển thường có tốc độ xử lý thấp (ví dụ: từ vài MHz đến vài trăm MHz), 
	+ nên chương trình cần được tối ưu hóa để chạy mượt.
4. Thiếu thư viện, công cụ hỗ trợ
	+ Không phải thiết bị nào cũng có sẵn thư viện
	+ Phải viết driver từ đầu để giao tiếp phần cứng
5. Tính đồng bộ
	+ Xử lý vấn đề Trong các hệ thống đa nhiệm 





2. Cách trả lời khéo léo
Nếu bạn từng biết nhưng quên do lâu không sử dụng
Trả lời:
"Thú thật là trước đây tôi đã từng làm việc với vấn đề này, nhưng vì thời gian gần đây tôi tập trung vào quản lý dự án nên chưa có cơ hội cập nhật lại kiến thức. 
Tuy nhiên, tôi tin rằng với kinh nghiệm trước đây, tôi có thể nhanh chóng nắm bắt và áp dụng lại khi cần thiết."









**vi điều khiển 8-bit, 16-bit, hay 32-bit**
![image](https://github.com/user-attachments/assets/39dc2403-ce78-4e20-838c-ece6be6578e5)


**kinh nghiệm làm việc của mình với các hệ điều hành nhúng không**
- FreeRTOS: là hệ điều hành đảm bảo các tác vụ diễn ra đúng lúc, không bị trễ.
	-  Kích thước nhỏ (vài KB đến vài chục KB) (FreeRTOS Kernel)
	-  FreeRTOS phù hợp cho các hệ thống nhúng nhỏ
	- FreeRTOS được thiết kế để chạy trên các thiết bị có tài nguyên rất nhỏ:  điều khiển, đo sk
		- CPU:vài mhz> chục MHZ
		- Vài KB - vài chục KB
- linux là hệ điều hành nhng hướng tới thiết bị phức tạp , có tài nguyên lớn, hỗ trợ đa nhiệm tốt hơn
	- Thiết bị công nghiệp, router, camera IP, Smart TV, các hệ thống phức tạp.
	- Kernel lớn
- FreeRTOS trong dự án
	- Quản lý đa nhiệm (Multitasking):
		- FreeRTOS sử dụng cơ chế lập lịch để chuyển đổi nhanh chóng giữa các tác vụ 
		- CPU chuyển đổi nhanh giữa các tác vụ, tạo cảm giác như tất cả chúng đang chạy đồng thời.
		- FreeRTOS cho phép chạy nhiều tác vụ đồng thời, ví dụ:
			- Tác vụ đọc dữ liệu từ RFID.
			- Tác vụ kiểm tra dữ liệu trên SDCARD.
			- Tác vụ điều khiển servo motor.
			- Tác vụ gửi thông báo qua Blynk IoT.
	- FreeRTOS đảm bảo tác vụ quan trọng được ưu tiên, và không tác vụ nào làm "treo" toàn bộ hệ thống.
	- Đảm bảo các tác vụ quan trọng (như kiểm tra RFID và điều khiển servo) được thực thi đúng thời điểm.	
	- Với các công cụ như semaphore, mutex đảm bảo rằng tài nguyên dùng chung được quản lý tốt mà không gây xung đột

- Nếu không dùng Free RTOS thì sao
	- các tác vụ sẽ thực hiện tuần tự
	- Nếu 1 tác vụ chậm sẽ làm chậm cả hệ thống
		- check card 500ms , cả hệ thống sẽ chờ 
	- Ngắt không phải lúc nào cũng hiệu quả
		- Ngắt quá nhiều sẽ làm hệ thống bị treo
	- Không có cách nào để đảm bảo tác vụ quan trọng (như điều khiển servo) được thực thi đúng lúc khi cần.
		- Nếu RFID đọc dữ liệu đúng lúc cần mở khóa cửa, nhưng hệ thống đang bận gửi thông báo qua Blynk, tác vụ quan trọng sẽ bị trễ.
	- Nếu dùng Free RTOS thì sẽ gán ưu tiên cho từng tác vụ
		- tác vụ mở cửa là ưu tiên cao nhất
		- tác vụ gửi thông báo qua blink ít hơn
		- thì ServoTask  được thực thì ngay ,FreeRTOS tạm dừng blink task , sẽ tiếp tục khi ServoTask hoàn thành
- Dữ liệu lưu trong file CSV	







- Cách tích hợp FreeRTOS vào ESP32
	- ESP32 tích hợp sẵn FreeRTOS trong ESP IDF
- STM32 không tích hợp FreeRTOS 
	- Dùng STM32cubeMX thêm FreeRTOS vào dự án


- 

**làm thế nào bạn đảm bảo hệ thống không bị treo hoặc mất dữ liệu khi xử lý nhiều ngắt cùng lúc?**
1. Ưu tiên ngắt (Interrupt Priority): Tôi cấu hình mức ưu tiên (priority) cho các ngắt, đảm bảo rằng các ngắt quan trọng nhất (ví dụ: Timer hoặc UART) được xử lý trước.
2. Quản lý đồng bộ: Sử dụng  mutex để đảm bảo không xảy ra xung đột dữ liệu giữa ISR và các phần còn lại của hệ thống
3. Ngắt quan trọng
	+ Ngắt thời gian:timer
	+ Ngắt hệ thống:watch dog timer
	+ Ngắt truyền thông:adc, spi

**Khi làm việc với một sơ đồ mạch mới**
1. Nguồn cấp (Power Supply): Đảm bảo nguồn điện ổn định và đủ cho tất cả các thành phần. Kiểm tra mạch ổn áp (voltage regulator) và điện áp cấp cho vi điều khiển.
2. Kết nối chân (Pinout): Xác định các chân GPIO, chân giao tiếp (I2C, SPI, UART), và chân chức năng đặc biệt (ADC, PWM).
3. Mạch ngoại vi: Kiểm tra sơ đồ kết nối với các linh kiện như cảm biến, màn hình, hoặc động cơ, đảm bảo chúng được kết nối chính xác và tuân theo thông số kỹ thuật.
4. Đường mạch giao tiếp: Xác định tốc độ truyền thông và tương thích giữa vi điều khiển và thiết bị ngoại vi.
5. Mạch bảo vệ: Kiểm tra các mạch bảo vệ như diode chống ngược dòng hoặc mạch hạn dòng cho các chân giao tiếp."

**Bạn đã từng đọc sơ đồ mạch vi điều khiển chưa? Mức độ hiểu biết của bạn về việc tích hợp firmware với phần cứng là như thế nào?**
- tôi đã sử dụng sơ đồ mạch để xác định chân PWM và kết nối của driver động cơ, sau đó cấu hình firmware tương ứng để điều chỉnh tốc độ và hướng quay.
- Mức độ hiểu biết về tích hợp firmware:
	+ Đảm bảo rằng các thông số như xung clock, điện áp, và tốc độ giao tiếp được điều chỉnh phù hợp với thiết bị ngoại vi.
	+ Trong trường hợp phát hiện lỗi phần cứng, tôi thường phối hợp với kỹ sư thiết kế mạch để xác định nguyên nhân và sửa đổi firmware hoặc mạch


**Lợi ích con trỏ**
1. Truy cập và thao tác trực tiếp với bộ nhớ
	+ Con trỏ trong C cho phép truy cập trực tiếp vào địa chỉ ánh xạ của thanh ghi phần cứng thông qua cơ chế Memory-Mapped I/O,
	giúp thao tác với thanh ghi nhanh chóng,
	  không cần thông qua các thư viện hoặc lớp trừu tượng trung gian
	+ Mọi thao tác như đọc/ghi giá trị sẽ diễn ra ngay lập tức trên phần cứng.
2. Quản lý bộ nhớ động
	- (malloc, calloc, realloc, free).
	- cấp phát, quản lý, và giải phóng bộ nhớ một cách linh hoạt trong thời gian chạy.
3. Truyền tham chiếu vào hàm, giúp tiết kiệm bộ Nhớ
	+ Khi truyền giá trị, một bản sao của biến được tạo ra và truyền vào hàm.Việc này tốn thêm bộ nhớ để lưu trữ bản sao
	+ Khi truyền tham chiếu, chỉ địa chỉ của biến được truyền vào hàm, không tạo ra bản sao của giá trị.
	+ Điều này tiết kiệm bộ nhớ, vì địa chỉ của biến (thường chiếm 4 hoặc 8 byte) nhỏ hơn nhiều so với việc sao chép toàn bộ dữ liệu.
4. Khi con trỏ truy cập vượt ngoài phạm vi của một mảng
	+ Hành vi không xác định
	+ Hỏng dữ liệu : Ghi đè lên dữ liệu quan trọng khác
5. Trong lập trình firmware, con trỏ thường được sử dụng để truy cập các thanh ghi phần cứng (hardware registers) hoặc điều khiển thiết bị ngoại vi. Các thanh ghi phần cứng thường được ánh xạ tới các địa chỉ cụ thể trong bộ nhớ (Memory-Mapped I/O). 
	+ Con trỏ được sử dụng để trỏ đến các địa chỉ này và thao tác trực tiếp với thanh ghi.
6. Sự khác biệt giữa truyền tham số bằng giá trị và bằng tham chiếu 
	+ Truyền tham số bằng giá trị (Pass by Value)
		+ Khi truyền tham số bằng giá trị, một bản sao của giá trị biến được truyền vào hàm.
		+ Hàm chỉ thao tác trên bản sao này, không ảnh hưởng đến biến gốc. giảm nguy cơ lỗi không mong muốn.
		+ Tốn bộ nhớ nếu kiểu dữ liệu lớn do tạo bản sao.
	+ bằng tham chiếu (Pass by Reference)
		+ Trong C, truyền tham số bằng tham chiếu thực hiện thông qua con trỏ.
		+ Thay vì truyền giá trị, địa chỉ của biến được truyền vào hàm.
		+ Hàm có thể thao tác trực tiếp trên địa chỉ đó, làm thay đổi giá trị của biến gốc.
		+ Tiết kiệm bộ nhớ vì không tạo bản sao.

**chuỗi (string) trong C**
- Trong ngôn ngữ C, không có kiểu dữ liệu string. 
- Thay vào đó, chuỗi được biểu diễn như một mảng (char[]) hoặc một con trỏ tới ký tự (char *), với ký tự null (\0) được sử dụng để đánh dấu kết thúc chuỗi.
char str1[] = "Hello";
char *str2 = "Hello";

- Để xử lý chuỗi, C cung cấp các hàm trong thư viện <string.h>
- Sự khác biệt giữa mảng ký tự (char arr[]) và con trỏ ký tự (char *ptr)
	+ mảng ký tự :
		+ Là một mảng các ký tự được lưu trữ liên tiếp trong bộ nhớ.	
		+ Có thể thay đổi nội dung mảng
		+ Kích thước Được cố định khi khai báo
	+ con trỏ ký tự 
		+ Trỏ tới địa chỉ của một chuỗi ký tự.
		+ không thể thay đổi  nội dung mảng (text)
		+ Kích thước không cố định khi khai báo(4 byte hoặc 8 byte)

**Khai báo biến struct**
1. Cách khai báo trực tiếp:
`struct Student s1, s2;`
2. Sử dụng từ khóa typedef:
```c
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

Student s1, s2; // Không cần viết "struct" nữa
```
- Quản lý bộ nhớ: Nếu một struct chứa con trỏ (ví dụ, con trỏ chuỗi),  cấp phát và giải phóng bộ nhớ cẩn thận.
- sử dụng con trỏ để thao tác trên một cấu trúc.
1. Khai báo struct và con trỏ
2. Dùng toán tử -> để truy cập thành phần của struct.
3. Thay đổi giá trị của struct qua con trỏ
- Lợi ích khi dùng con trỏ với struct:
1. Tiết kiệm bộ nhớ:
	+ Khi truyền dữ liệu vào hàm bằng cách truyền giá trị, một bản sao của toàn bộ dữ liệu được tạo ra trong bộ nhớ.
	+ Nếu dữ liệu lớn (ví dụ: một struct hoặc mảng lớn), việc sao chép toàn bộ dữ liệu này sẽ tiêu tốn rất nhiều bộ nhớ.
	+ Sử dụng con trỏ thay vì truyền giá trị cho phép hàm nhận địa chỉ của dữ liệu. Địa chỉ chỉ chiếm một vài byte>> tiết Kiệm
2. tăng Hiệu suất 
	+ Khi truyền tham chiếu, hàm thao tác trực tiếp trên biến gốc , thay vì làm việc trên một bản sao của dữ liệu.
	+ Điều này giúp tránh chi phí xử lý dư thừa>> tăng hiệu suất









**Ngay cả khi nhà sản xuất Trung Quốc cung cấp một hệ điều hành Linux sẵn, FPT có thể cần:**

+ Tùy chỉnh Firmware:
	+ Thêm các tính năng riêng của FPT (ví dụ: giao diện người dùng, chức năng quản lý khách hàng).
	+ Đảm bảo hệ điều hành tuân thủ các yêu cầu bảo mật hoặc luật pháp tại Việt Nam.
+ Kiểm tra bảo mật:
	+ Đảm bảo hệ điều hành Linux từ nhà sản xuất không chứa mã độc g.
	+ Loại bỏ các thành phần không cần thiết hoặc thay thế bằng các phần mềm mã nguồn mở được kiểm chứng.
+ Cập nhật hoặc sửa lỗi:
	+ Cần có đội ngũ kỹ thuật để bảo trì hệ điều hành Linux, cập nhật kernel, hoặc vá các lỗ hổng bảo mật trong firmware.







**typedef và #define**

1. typedef:
+ Là một từ khóa được xử lý bởi trình biên dịch.
+ Dùng để định nghĩa kiểu dữ liệu mới.
+ Có phạm vi  nơi nó được khai báo.
+ Trình biên dịch có thể kiểm tra lỗi cú pháp.
2. #define:
+ Là một chỉ thị tiền xử lý (preprocessor directive).
+ Thay thế văn bản trong mã nguồn trước khi biên dịch
+ Thay thế toàn bộ mã nguồn trước khi biên dịch.
+ Trình biên dịch không  kiểm tra lỗi cú pháp.
+ #ifdef là chỉ thị tiền xử lý cho phép kiểm tra xem một macro có được định nghĩa hay không.


**Function pointer là gì và khi nào nên sử dụng nó**
- Thông thường, trong C, hàm được gọi trực tiếp bằng tên của nó, 
- và tên hàm này phải được quyết định tại thời gian biên dịch (compile time).
- Function pointer cho phép chọn hàm cần gọi tại runtime, 
- Chọn hàm dựa trên điều kiện hoặc tham số.
- Ví dụ : bấm 1,2,3,4 bằng swich - case ,Dựa vào lựa chọn  (choice), chương trình gán địa chỉ hàm tương ứng cho con trỏ  .


**Sự khác biệt giữa fgets() và gets() trong C**
- fgets() và gets() đều được sử dụng để nhập chuỗi từ đầu vào
- gets():Không an toàn, dễ gây lỗi tràn bộ nhớ.F
- fgets() :An toàn hơn do kiểm soát được số ký tự nhập.
- fgets() kích thước bằng  kích thước mảng
- gets() đã bị loại bỏ trong tiêu chuẩn C11 

**Dịch bit**
1. Set bit tại vị trí n
-  Dịch bit 1 sang trái n vị trí,OR bit 1 đó tại vị trí n với giá trị ban đầu
2. clear bit tại vị trí n
- Dịch bit 1 sang trái n đơn vị , đảo bit 1 đó tại ví trí  n và And với giá trị ban đầu
3. check bit 0/1
- Dịch bit 1 sang vị trí cần check và and với bit đó
	+ kẾT quả bằng 1 >> SET
	+ 0 >> CLEAR



**Watchdog Timer là gì?**
- WDT là một bộ đếm thời gian độc lập trong vi điều khiển.
- Nó được thiết kế để phát hiện và khắc phục các lỗi phần mềm, như:
	- Lỗi treo hệ thống (system hang): Khi chương trình dừng hoạt động hoặc rơi vào vòng lặp vô hạn.
	- Lỗi thời gian thực (real-time deadline miss): Khi một tác vụ không hoàn thành trong thời gian yêu cầu.
- Cách hoạt động của Watchdog Timer
- Khởi tạo WDT:
	- Bạn cấu hình thời gian chờ của WDT (timeout). Ví dụ: 5 giây.
- Làm mới WDT (Feed/Kick the Dog):
	- Trong chương trình chính, bạn phải "làm mới" WDT thường xuyên trước khi hết thời gian chờ. Nếu không, WDT sẽ reset hệ thống.
- Reset khi không làm mới:
	- Nếu WDT không được làm mới, hệ thống sẽ bị reset.
- Tích hợp trong phần cứng của vi điều khiển.

**bảo mật cho các modem/router**
- FPT Telecom đã phát triển và tích hợp tính năng bảo mật F-Safe trực tiếp trên các modem/router


**Project Manager (PM)**
- Trong 7 năm tại FPT Telecom, tôi đã quản lý các dự án phát triển thiết bị của FPT
- Đảm bảo tiến độ , chất lượng các dự án
- Phân công nhiệm vụ cho các thành viên trong team Dev, test 
- làm việc với nhà sản xuất để tích hợp các tính năng mới và tối ưu hóa hiệu suất thiết bị
- Làm việc với các team khác để đảm bảo sản phẩm đáp ứng đúng nhu cầu của khách hàng.
- đồng thời xử lý các sự cố kỹ thuật sau khi triển khai. 

**Trong vai trò Project Manager tại FPT Telecom, bạn đã làm thế nào để quản lý đội nhóm hiệu quả**
1. Lập kế hoạch
- tôi tham gia các buổi họp với ban giám đốc, các phòng ban liên quan để thống nhất về mục tiêu sản phẩm, timeline,yêu cầu kỹ thuật và tính khả thi.
- làm việc với nhà cung cấp Trung Quốc để nhập modem test và nhận tài liệu kỹ thuật.

2. Kiểm thử
- Tôi phân công công việc thông qua các Team Leader để đảm bảo hiệu quả quản lý.
- Với đội dev:
	- Tập trung kiểm tra mã nguồn từ nhà sản xuất và phát triển thêm các tính năng mới theo yêu cầu
	- Vd:
		+ Xác định các tính năng có đúng với yêu cầu của dự án hay không.
		+ Đảm bảo không có lỗ hổng bảo mật tiềm ẩn 
		+ Đảm bảo tích hợp với hệ thống nội bộ (như app quản lý của FPT).
	- Các bài test của dev:
		+ Kiểm thử đơn vị (Unit Test):Đảm bảo  module hoạt động đúng như mong đợi.
			+ Ví dụ: Kiểm tra hàm xử lý dữ liệu từ cổng WAN, đảm bảo dữ liệu được định dạng và truyền tải chính xác.
		+  Kiểm thử tích hợp (Integration Test):Đảm bảo các module hoạt động hài hòa khi kết hợp.
			+ Ví dụ: Kiểm tra sự tương tác giữa module quản lý kết nối Wi-Fi và module cấp phát địa chỉ IP (DHCP), đảm bảo thiết bị kết nối nhận được IP hợp lệ.
	- Tín năng nội bộ dev phát triển
		+  Hệ thống thu thập và phân tích lỗi:
			+  log kết nối, log bảo mật, lỗi hệ thống
			+  Gửi log về server quản lý trung tâm để phân tích và xử lý sự cố từ xa.
		+  Hệ thống điều khiển từ xa :
			+  Cho phép quản lý modem từ xa qua giao diện web hoặc ứng dụng di động.
		+  Giao diện người dùng tùy chỉnh
			+  Tùy chỉnh giao diện quản lý modem trên web
			+  Tích hợp thêm các tính năng như hiển thị trạng thái kết nối, số lượng thiết bị đang kết nối, tốc độ mạng thực tế.
		+ Tích hợp với hệ thống của công ty , app, website
		+ Chặn các trang web không phù hợp
- Với đội test: 
	- kiểm tra các phần cứng từ đối tác Trung Quốc 
		- Mục tiêu: Đảm bảo phần cứng modem hoạt động đúng như thiết kế.
		- Đánh giá độ ổn định khi modem hoạt động liên tục trong nhiều giờ hoặc nhiều ngày.
		- Kiểm tra các cổng kết nối như Ethernet, USB, hoặc nguồn điện.
	- các tính năng do đội dev phát triển.
	- Các bài test của dev:
		- Kiểm thử chức năng (Functional Test): Đảm bảo các tính năng hoạt động theo yêu cầu.
			- Ví dụ: Kiểm tra khả năng thay đổi mật khẩu Wi-Fi thông qua web, đảm bảo client thực hiện dễ dàng.
		- Kiểm thử hệ thống (System Test): Đánh giá hoạt động của toàn bộ hệ thống trong môi trường thực tế.
			- Ví dụ:nhiều thiết bị kết nối, khả năng ổn định
		- Kiểm thử hiệu năng (Performance Test):Đánh giá hiệu suất của modem dưới các điều kiện tải khác nhau.
			-  Ví dụ : Đo lường tốc độ truyền tải dữ liệu qua Wi-Fi ở các khoảng cách khác nhau,

3. thiết bị thử nghiệm 
	- Sau khi đảm bảo phần cứng , phần mềm ok thì TK 1 số chi nhánh
	- Thu thập log lỗi và phản hồi từ khách hàng.
	- Đội Dev/QA/Test tinh chỉnh sản phẩm dựa trên kết quả thử nghiệm	
4. Triển khai (Deployment Phase)
- Mục tiêu:
	-  triển khai trên diện rộng.
- Vai trò của các team:
	- Phối hợp với phòng kinh doanh và các đại lý (nếu có) để đưa sản phẩm ra thị trường.
	- Hướng dẫn khách hàng sử dụng thông qua tài liệu, video, hoặc bộ phận chăm sóc khách hàng.
	- Team Dev:
		- Sửa lỗi nếu phát sinh vấn đề trong giai đoạn triển khai.
	- Team QA/Test:
		- Xác nhận rằng firmware đạt chất lượng ở môi trường thực tế.
	- Team Vận hành:
		- Theo dõi trạng thái thiết bị trong quá trình triển khai.
		- Xử lý các vấn đề phát sinh (downtime, lỗi kết nối).
Kết quả:
- Firmware được triển khai thành công, hoạt động ổn định trên thiết bị thực.
5. Vận hành và Bảo trì (Operations and Maintenance Phase)
- Mục tiêu:
	- Đảm bảo hệ thống modem hoạt động ổn định và được cập nhật định kỳ.
- Vai trò của các team:
	- Team Dev:
		- Phát hành các bản vá lỗi hoặc tính năng mới dựa trên phản hồi từ vận hành.
	- Team QA/Test:
		- Chạy lại các bài kiểm thử khi có bản cập nhật để đảm bảo tính tương thích.
	- Team Vận hành:
		- Giám sát hoạt động thực tế của thiết bị.
		- Thu thập log và báo cáo các vấn đề thực tế để phản hồi cho Dev và QA.
- Kết quả:
	- Modem hoạt động ổn định, các bản cập nhật được phát hành nhanh chóng.







**Phong cách quản lý của tôi tập trung vào sự phối hợp và trao quyền**

1. Phân công công việc rõ ràng: Xác định vai trò và trách nhiệm của từng thành viên trong nhóm để đảm bảo họ hiểu rõ công việc của mình.
2. Hỗ trợ và phát triển: Tôi luôn sẵn sàng hỗ trợ khi nhóm gặp khó khăn và khuyến khích họ nâng cao kỹ năng cá nhân.
3. Khuyến khích giao tiếp: Tôi tạo môi trường mở để các thành viên có thể chia sẻ ý kiến và đóng góp ý tưởng. Điều này giúp xây dựng sự gắn kết và sáng tạo trong nhóm."



**đảm bảo đội nhóm của mình duy trì sự sáng tạo và năng suất khi phát triển phần mềm nhúng?**
- Tôi thường tổ chức các buổi họp cùng Team Leader để đánh giá ý tưởng và đề xuất cải tiến từ đội nhóm. 
- Tôi cũng khuyến khích Team Leader dành thời gian hỗ trợ các thành viên thử nghiệm những giải pháp mới.
- Ngoài ra, tôi tạo điều kiện để mọi người tham gia các khóa đào tạo kỹ thuật chuyên sâu và chia sẻ kinh nghiệm nội bộ. 
- Quan trọng hơn, tôi luôn công nhận và khen thưởng các ý tưởng có giá trị, giúp thúc đẩy tinh thần sáng tạo trong nhóm

**Khi gặp xung đột trong nhóm, bạn thường giải quyết như thế nào để đảm bảo tiến độ dự án không bị ảnh hưởng?**

- Tôi thường để Team Leader xử lý các vấn đề nhỏ trong đội nhóm trước, nhưng nếu xung đột phức tạp hoặc kéo dài, tôi sẽ trực tiếp tham gia.
- Nếu xung đột mang tính cá nhân, tôi gặp riêng các thành viên để tìm hiểu nguyên nhân và đưa ra giải pháp phù hợp, đồng thời hỗ trợ Team Leader trong việc xây dựng lại môi trường làm việc tích cực.
- Nếu xung đột liên quan đến công việc, tôi tổ chức cuộc họp nhóm để làm rõ vấn đề, xác định nguyên nhân và cùng nhau thảo luận giải pháp. 
- Điều quan trọng là tôi luôn giữ không khí cuộc họp tích cực, tập trung vào giải quyết vấn đề thay vì đổ lỗi.”





**Cân bằng giữa các yêu cầu từ khách hàng và giới hạn về thời gian hoặc tài nguyên trong dự án** 
- Làm việc với phòng kinh doanh và khách hàng để phân loại các yêu cầu theo mức độ ưu tiên.
- ưu tiên phát triển những tính năng cần thiết nhất trước và lên kế hoạch bổ sung các tính năng ít quan trọng hơn trong các bản cập nhật sau
- báo cáo với ban giám đốc về những giới hạn tài nguyên, từ đó đề xuất thêm nhân sự hoặc thời gian nếu cần thiết


**Khi xảy ra lỗi, cách xử lý**
1. Xác định và thu thập thông tin lỗi:
Tôi yêu cầu đội test ghi lại chi tiết vấn đề, bao gồm điều kiện tái hiện lỗi, nhật ký hệ thống (logs), và tác động cụ thể lên sản phẩm.
Nếu lỗi xảy ra ở khách hàng, tôi làm việc với đội hỗ trợ kỹ thuật để thu thập thông tin thực tế từ môi trường sử dụng.
nhân chính.
3. Triển khai biện pháp khắc phục:
Với lỗi phần cứng: Báo cáo trực tiếp với nhà sản xuất, yêu cầu sửa đổi thiết kế hoặc cung cấp bản cập nhật firmware.
Với lỗi phần mềm: Yêu cầu đội dev sửa lỗi và triển khai kiểm thử lại để đảm bảo lỗi không tái xuất hiện.
4. Ngăn chặn lỗi tương tự trong tương lai:
Cập nhật kịch bản kiểm thử để bao gồm các trường hợp gây ra lỗi.
Thiết lập các bài kiểm tra bổ sung, chẳng hạn stress test, để phát hiện các vấn đề tiềm tàng sớm hơn.
Tạo tài liệu ghi nhận lỗi và giải pháp khắc phục, đồng thời chia sẻ với các phòng ban liên quan để nâng cao kiến thức chung.
5. Báo cáo và cải tiến:
Sau khi lỗi được xử lý, tôi báo cáo chi tiết cho các bên liên quan, bao gồm đội ngũ quản lý và nhà sản xuất.
Đồng thời, tổ chức buổi rút kinh nghiệm với đội nhóm để cải thiện quy trình phát triển và kiểm thử sản phẩm trong tương lai.”



**Khó khăn**
- Một lần, tôi phải làm việc với nhà sản xuất để giải quyết vấn đề chậm tiến độ trong việc cập nhật firmware cho thiết bị WiFi. 
- Nhà sản xuất gặp khó khăn trong việc điều chỉnh mã nguồn để phù hợp với điều kiện mạng tại Việt Nam
Xác định nguyên nhân gốc rễ: Tôi tổ chức một cuộc họp với đội kỹ thuật của nhà sản xuất để tìm hiểu nguyên nhân chính, phát hiện rằng vấn đề đến từ việc thiếu thông tin về môi trường mạng tại Việt Nam.
Cung cấp thông tin hỗ trợ: Tôi phối hợp với đội kỹ thuật FPT để cung cấp các thông tin chi tiết như cấu trúc mạng, phổ tần số, và yêu cầu phần mềm đặc thù tại Việt Nam.
Thiết lập thời hạn cụ thể: Tôi thương lượng với nhà sản xuất để đặt ra các mốc thời gian cụ thể cho từng giai đoạn sửa lỗi và cập nhật. Đồng thời, tôi yêu cầu họ cung cấp báo cáo tiến độ định kỳ.
Tăng cường liên lạc: Tôi duy trì liên lạc chặt chẽ qua email và họp trực tuyến hàng tuần để đảm bảo không có thông tin nào bị bỏ sót và các vấn đề phát sinh được giải quyết ngay lập tức.



**phương pháp nào để đánh giá hiệu suất**
1. Đánh giá định lượng:
	+ Dùng các công cụ quản lý dự án như Jira hoặc phần mềm nội bộ của FPT để theo dõi tiến độ từng nhiệm vụ.
	+ Các chỉ số chính (KPIs) như số lượng task hoàn thành, thời gian hoàn thành, và chất lượng công việc được dùng làm tiêu chí đánh giá.
2. Đánh giá định tính:
	+ Thường xuyên thảo luận với Team Leader để thu thập ý kiến về năng lực, thái độ, và sự hợp tác của từng thành viên.
	+ Quan sát trực tiếp cách các thành viên làm việc, đặc biệt trong các buổi họp nhóm hoặc xử lý các tình huống khẩn cấp.

**thành viên không đạt yêu cầu không?**
1. Tìm hiểu nguyên nhân
2. Hỗ trợ và đào tạo
3. Điều chỉnh nhiệm vụ
4. Theo dõi tiến độ

**Thách thức**

1. Phần mềm gốc từ nhà sản xuất không tương thích hoàn toàn với hạ tầng mạng tại Việt Nam, dẫn đến hiệu suất kém và lỗi kết nối.
2. Tiến độ bị áp lực vì thời hạn ra mắt đã được công bố trước với khách hàng.

Cách tôi giải quyết:
1. Phối hợp với nhà sản xuất: Tôi làm việc trực tiếp với nhà sản xuất để yêu cầu sửa đổi phần mềm và cung cấp bản vá lỗi.
2. Phát triển nội bộ: Đội Dev của tôi đã xây dựng các module bổ sung để tối ưu hiệu suất và tương thích với hạ tầng mạng tại Việt Nam.
3. Kiểm thử toàn diện: Đội Test thực hiện các kịch bản kiểm thử trong nhiều môi trường khác nhau để đảm bảo chất lượng sản phẩm.
4. Điều chỉnh kế hoạch: Tôi tái phân bổ nguồn lực để giảm thời gian phát triển các tính năng không quan trọng, tập trung vào các tính năng cốt lõi.

**sự thay đổi yêu cầu từ phía khách hàng hoặc nhà sản xuất**
- Điều chỉnh kế hoạch: Tùy mức độ thay đổi, tôi có thể lùi thời hạn ra mắt hoặc đề xuất cắt giảm những tính năng không quan trọng để tập trung vào yêu cầu mới.
- Thông báo và đồng thuận: Tôi luôn thông báo rõ ràng cho ban giám đốc và các phòng ban liên quan về thay đổi và lý do điều chỉnh. Đồng thời, cập nhật khách hàng để đảm bảo sự hài lòng của họ.”



**tùy chỉnh kernel Linux**
- Có, tôi đã từng cấu hình và tùy chỉnh kernel Linux trong modem/router 
	+ Sử dụng menuconfig để kích hoạt các module liên quan đến network stack và file system.
	+ Tích hợp driver của đối tác Trung Quốc để đảm bảo modem có thể hoạt động đúng với phần cứng



**lập trình firmware& soft ware**
- Firmware: Là phần mềm được lập trình và cài đặt trực tiếp lên phần cứng (như vi điều khiển, vi xử lý), thường được lưu trong bộ nhớ ROM, Flash hoặc EEPROM.
- Software: Là ứng dụng hoặc chương trình chạy trên hệ điều hành của máy tính hoặc thiết bị, thường được lưu trữ trong bộ nhớ RAM hoặc ổ đĩa.
![image](https://github.com/user-attachments/assets/ba3c0f7f-4da6-4a94-9364-32bae01ce170)


**tình huống vi điều khiển chạy chậm hoặc bị treo? Bạn đã xử lý thế nào?**
- 1 số nguyên nhân 
	+ cấu hình Xung nhịp không đúng
	+ Chương trình bị kẹt trong vòng lặp vô hạn,Sử dụng Watchdog Timer (WDT) để tự động reset vi điều khiển khi treo.
	+ Chương trình chứa nhiều tác vụ nặng (tính toán, xử lý dữ liệu) dẫn đến thời gian đáp ứng chậm: Tối ưu mã nguồn
	+ Giao tiếp ngoại vi bị lỗi
		+ check kết nối vật lý
	+ Nguồn điện không ổn định
		+ check nguồn , thêm  tụ lọc (capacitor) để giảm nhiễu.
	+ Stack Overflow hoặc Memory Leak: hạn chế cấp phát động


**Trong một sản phẩm đa chức năng, làm thế nào bạn đảm bảo các chức năng hoạt động ổn định mà không ảnh hưởng đến nhau?**
1. Phân chia rõ ràng các chức năng
2. Quản lý tài nguyên dùng chung tránh cac vấn đề đa luồng
3. Sử dụng hệ điều hành thời gian thực
4. Kiểm tra và giám sát hệ thống dùng Cơ chế giám sát Watchdog Timer (WDT)
5. Tối ưu hóa hiệu suất và bộ nhớ
	+ Quản lý bộ nhớ hiệu quả:
		+ Sử dụng bộ nhớ stack và heap một cách hợp lý, tránh tràn stack hoặc lãng phí bộ nhớ.
	+ Tối ưu hóa mã:
		+ Giảm thiểu độ phức tạp trong mã nguồn, đảm bảo các chức năng chỉ làm đúng nhiệm vụ của chúng.






**Khi làm việc với một dự án firmware, bạn phát hiện rằng thiết bị hoạt động không đúng như dự kiến. Bạn sẽ làm gì để xác định và khắc phục lỗi?**
1. Xác định nguyên nhân Lỗi
	- Phần cứng:
		- Đảm bảo rằng phần cứng hoạt động đúng (nguồn điện, giao tiếp ngoại vi, thạch anh).
		- Kiểm tra kết nối vật lý như cáp, chân cắm IC, hoặc cảm biến.
	- Phần mềm:
		- Kiểm tra logic chương trình và các điều kiện biên, đặc biệt ở các module liên quan.
		- Đảm bảo rằng cấu hình hệ thống (clock, bộ nhớ) phù hợp với thiết kế.
2. Sử dụng cụ hỗ trợ gỡ lỗi
	- Sử dụng debugger (ví dụ: JTAG, SWD) để theo dõi trạng thái vi điều khiển, xem giá trị biến và bước thực thi mã.
	- Oscilloscope hoặc Logic Analyzer:
		- Kiểm tra tín hiệu ngoại vi (SPI, I2C, UART) để xác định lỗi giao tiếp hoặc tín hiệu không ổn định.
3.  Kiểm tra từng module riêng lẻ
	- Nếu thiết bị có nhiều chức năng, thử ngắt từng module để tìm xem lỗi phát sinh từ đâu.
4. Kiểm tra với các phiên bản firmware khác nhau

**một tình huống mà bạn phải tối ưu hóa firmware để cải thiện hiệu năng hoặc giảm tiêu thụ năng lượng.**
- Trong một dự án phát triển thiết bị IoT  sử dụng vi điều khiển để thu thập dữ liệu từ cảm biến và truyền qua mạng không dây (Wi-Fi), 
tôi nhận thấy :
- Tiêu thụ năng lượng cao: Thiết bị không đáp ứng được thời lượng pin kỳ vọng, đặc biệt trong các chế độ nhàn rỗi.
- Tôi cấu hình vi điều khiển và các module ngoại vi (như cảm biến và module Wi-Fi) vào chế độ Deep Sleep khi không cần hoạt động.
- Tối ưu thời gian hoạt động của module Wi-Fi::
	- Module Wi-Fi ban đầu luôn bật, gây tiêu thụ năng lượng không cần thiết.
	-  Tôi chỉnh sửa firmware để chỉ bật module khi cần truyền dữ liệu, sau đó đưa nó vào chế độ tiết kiệm năng lượng.


**firmware  an toàn trước các cuộc tấn công bên ngoài**
- Mã hóa và bảo vệ dữ liệu truyền tải
	+ Thuật toán mạnh như AES-256.
- Bảo vệ chống sửa đổi firmware
	+ Triển khai cơ chế xác minh tính toàn vẹn của firmware tại thời điểm khởi động hoặc định kỳ trong quá trình hoạt động.
- Cập nhật OTA an toàn 
	+ Mã hóa toàn bộ dữ liệu cập nhật để ngăn chặn việc bị thay đổi trong quá trình truyền tải.
	+ Thực hiện xác minh checksum hoặc hash của firmware mới trước khi cài đặt.
- Quản lý quyền truy cập:
	+ Triển khai cơ chế xác thực (authentication) và phân quyền (authorization) cho các giao tiếp từ bên ngoài.
    + Sử dụng mã hóa giao tiếp giữa thiết bị và hệ thống quản lý để ngăn chặn truy cập trái phép.
- Các giao diện JTAG hoặc SWD bị vô hiệu hóa trong các phiên bản firmware cuối cùng để ngăn chặn việc truy cập trái phép.
- Nếu cần mở lại, phải qua cơ chế xác thực (ví dụ: nhập mật khẩu hoặc sử dụng khóa phần cứng).
- Sử dụng WDT để phát hiện các hoạt động bất thường, như chương trình bị treo do mã độc tấn công.



**Phối hợp với các thành viên trong nhóm phát triển nhúng**
1. Với team dev:
	+ Đảm bảo hiểu rõ thiết kế phần cứng (datasheet, sơ đồ mạch) để tích hợp phần mềm nhúng tương ứng.
    + Phối hợp để kiểm tra khả năng tương thích giữa firmware và phần cứng, như giao tiếp I2C, SPI, UART.
2. Với nhóm QA 
	+ Lên kế hoạch để test các tính năng của sản phẩm
3. Xử lý vấn đề chưa từng làm trước đó
	+ Tự học, nghiên cứu vấn đề đó và không ngại tìm kiếm sự trợ giúp.
**FreeRTOS,RTOS**
![image](https://github.com/user-attachments/assets/e2b58085-b9ef-4a43-983d-d6e4ee2bd1c7)

- FreeRTOS là một hệ điều hành thời gian thực (Real-Time Operating System - RTOS) mã nguồn mở, được thiết kế đặc biệt cho các thiết bị nhúng (embedded systems). Nó cung cấp môi trường để phát triển các ứng dụng nhúng có yêu cầu về xử lý thời gian thực.
- Đặc điểm chính của FreeRTOS:
Nhẹ và tối ưu hóa:FreeRTOS có kích thước nhỏ, phù hợp cho các vi điều khiển với tài nguyên hạn chế.
- Quản lý đa nhiệm (Multitasking):Hỗ trợ chạy nhiều tác vụ (task) đồng thời bằng cách sử dụng lập lịch ưu tiên (priority scheduling).
- Thời gian thực:Đảm bảo đáp ứng các yêu cầu thời gian khắt khe, như xử lý sự kiện trong khoảng thời gian cố định.
-  ESP32 muốn dùng FreeRTOS thì cài framework  ESP-IDF
- Framework là một công cụ mạnh mẽ giúp lập trình viên phát triển phần mềm nhanh chóng, dễ bảo trì và có chất lượng cao
- Khác biệt lớn giữa FreeRTOS và Windows:
	- Thời gian thực vs Không thời gian thực:
		- FreeRTOS: Hỗ trợ thời gian thực, đảm bảo phản hồi nhanh và chính xác trong khoảng thời gian xác định. Điều này rất quan trọng trong các hệ thống nhúng, nơi thời gian xử lý phải được kiểm soát nghiêm ngặt.
		- Windows: Không được thiết kế cho thời gian thực. Nó ưu tiên trải nghiệm người dùng và chạy các ứng dụng không đòi hỏi sự đáp ứng chính xác theo thời gian.
	- Tài nguyên phần cứng:
		- FreeRTOS;Hạn chế
		- Windows: Yêu cầu tài nguyên cao,
		- FreeRTOS: Hỗ trợ thời gian thực, đảm bảo phản hồi nhanh và chính xác trong khoảng thời gian xác định. Điều này rất quan trọng trong các hệ thống nhúng, nơi thời gian xử lý phải được kiểm soát nghiêm ngặt.
		- Windows: Không được thiết kế cho thời gian thực. Nó ưu tiên trải nghiệm người dùng và chạy các ứng dụng không đòi hỏi sự đáp ứng chính xác theo thời gian.
	- lập trình ESP32 bằng VS CODE tích hợp extencion PlatformIO IDE	
**Yocto Project là gì?**
- Yocto Project là một công cụ Cho phép tạo ra một hệ điều hành Linux tùy chỉnh và tối ưu theo nhu cầu phần cứng cụ thể.
![image](https://github.com/user-attachments/assets/4063075b-9890-4464-8e71-b15adb58e380)
- Yocto Project hỗ trợ toàn bộ quá trình phát triển hệ điều hành nhúng, bao gồm:
	+ Xây dựng kernel Linux: Yocto cho phép bạn tùy chỉnh và biên dịch kernel dựa trên nhu cầu cụ thể của thiết bị.
	+ Xây dựng root filesystem: Tạo hệ điều hành Linux đầy đủ (gồm kernel, file system, driver, các ứng dụng).
	+ Tích hợp các layer: Dễ dàng thêm hoặc bớt các tính năng, driver, hoặc ứng dụng thông qua các layer cấu hình.



**JTAG/SWD là gì?**
- Khi nào sử dụng JTAG hoặc SWD Debugger?
	- Sửa lỗi mã nguồn nhúng (debug):
		- Khi cần kiểm tra mã nguồn chạy trên vi điều khiển.
	- Lập trình firmware:
		- Nạp chương trình hoặc cập nhật firmware trực tiếp.
	- Phân tích hiệu năng và tài nguyên:
		- Theo dõi sử dụng CPU, bộ nhớ.
	- Kiểm tra phần cứng:
		- JTAG có thể kiểm tra kết nối phần cứng và phát hiện lỗi vật lý trên bo mạch.
	- Easy JTAG không hỗ trợ debug 
		- Sửa lỗi firmware: Khi cần khôi phục hoặc sửa chữa firmware trên thiết bị.
		- Khôi phục dữ liệu: Khi cần lấy lại dữ liệu từ các thiết bị bị hỏng. 

**Những điểm cần chú ý khi đọc Datasheet và Reference Manual của vi điều khiển**
1. Datasheet:
+ Là tài liệu cung cấp các thông số kỹ thuật chính của vi điều khiển và các ngoại vi.
+ Mục đích: Giúp bạn hiểu về tính năng, đặc điểm kỹ thuật và khả năng của vi điều khiển.
+ Tính năng chính : Số lượng và loại GPIO, ADC, DAC, Timers, UART, SPI, I2C.
+ Thông số kỹ thuật :
	+ Nguồn điện,nhiệt độ, clk
+ Chức năng của từng chân:
+ Kích thước bộ nhớ
2. Reference Manual:
+ Là tài liệu chi tiết hơn, cung cấp hướng dẫn sử dụng từng khối ngoại vi, cách cấu hình các thanh ghi, và cách tương tác với phần cứng.
+ Mục đích: Dành cho việc lập trình và cấu hình chi tiết.
+ Tổng quan về cấu trúc bộ nhớ
	+  địa chỉ bắt đầu các thanh ghi ngoại vi.
+ Cách sử dụng các khối ngoại vi 
	+ VD: Hướng dẫn cấu hình timer cho PWM,GPIO
+ Cấu hình và quản lý ngắt

**Tối ưu hóa lập trình C/C++ cho vi điều khiển**

1. Tối ưu hóa kích thước 
	+ Sử dụng các kiểu dữ liệu phù hợp
	+ Sử dụng các thư viện chuẩn thay vì tự viết những hàm phức tạp.
	+ Xóa các đoạn mã hoặc biến không được sử dụng.
	+ Viết code ngắn gọn và dễ đọc
	+ Hạn chế sử dụng biến cục bộ có kích thước lớn trong hàm, chuyển sang dùng biến toàn cục nếu cần.
		+ Vi vùng stack nhỏ hơn vùng data/bss >> dễ tràn vùng nhớ stack
		+ vùng data/bss có kích thước lớn hơn
		+ Biến toàn cục không bị giải phóng khi hàm kết thúc, nên không tốn thời gian cấp phát và giải phóng
	+ Không đùng đệ quy
2. Tối ưu hóa tốc độ xử lý
	+ Tránh các phép tính phức tạp
		+ VD: Thay vì dùng phép nhân thì dùng dịch bit
	+ Tránh cấp phát động vì nó gây phân mảnh bộ nhớ và tăng thời gian thực thi.
	+ Giảm số lần lặp,điều kiện kiểm tra trong vòng lặp
		+ Hiệu suất: Mỗi lần lặp là CPU phải thực thi,càng ít lần lặp thì thời gian thực thi càng ngắn.
		+ 2 vòng for >> 1 vòng for
	+ Sử dụng hàm (inline) để giảm thời gian gọi hàm.
	+ Sử dụng tùy chọn tối ưu của trình biên dịch 
		+ -O1: Tối ưu cơ bản, cân bằng giữa tốc độ và kích thước.
		+ -O2: Tối ưu cao hơn, tăng tốc độ chương trình.
		+ -O3: Tối ưu hóa mạnh nhất, nhưng có thể làm tăng kích thước mã.
		+ -Os: Tối ưu để giảm kích thước mã.
	

**Makefile**
1. Make file là một script , Nó chứa các quy tắc để tự động hóa quy trình build chương trình
- mối quan hệ giữa các file trong dự án
- Các command line dùng để tạo-hủy file.
2. Chương trình make sẽ đọc nội dung trong Makefile và thực thi nó.
3. Trong Makefile, dependency cho biết một tệp đầu ra cần dựa vào những tệp nào để được xây dựng.
	- Một file thực thi (main) phụ thuộc vào file đối tượng (main.o).

**IPC - Interprocess Communication**
- IPC (Interprocess Communication) là cơ chế cho phép các process trao đổi thông tin và chia sẽ dữ liệu 
- Các phương thức IPC phổ biến
	- Pipe:Giao tiếp một chiều, chỉ trong tiến trình cha-con.
	- FIFO:Giao tiếp hai chiều. phù hợp cho các tiến trình không liên quan trực tiếp.
	- Socket: Giao tiếp giữa các tiến trình qua mạng hoặc cùng một máy.
	- Message Queue:Gửi và nhận thông điệp giữa các tiến trình thông qua hàng đợi (queue).
	- Shared Memory: các tiến trình cùng truy cập một vùng bộ nhớ chung.
	- Semaphore:
		- Dùng để giới hạn số lượng tiến trình truy cập tài nguyên chung.
	- Mutex (Mutual Exclusion):
		- Cơ chế khóa tài nguyên để chỉ một tiến trình được phép truy cập tại một thời điểm.
- RCU (Read-Copy-Update) một cơ chế đồng bộ cho phép các tiến trình đọc dữ liệu mà không bị cản trở bởi các tiến trình ghi dữ Liệu
	-  đồng thời đảm bảo tính nhất quán của dữ liệu được truy cập.

**Physical Memory,Virtual Memory**
- Physical Memory:Là RAM thực tế trên phần cứng.
- Virtual Memory:Là không gian bộ nhớ   do hệ điều hành tạo ra.
-  Lý do cơ chế Virtual Memory ra đời
	+  cho phép nhiều chương trình sử dụng bộ nhớ đồng thời bằng cách:
		+ Chỉ tải các phần cần thiết của chương trình vào RAM.
		+ Lưu phần còn lại trên ổ cứng (swap space).
	+ Tạo không gian bộ nhớ lớn hơn RAM:
		+ cho phép chương trình yêu cầu bộ nhớ vượt quá dung lượng RAM thực tế.

**Kernel Panic là gì?**
- Kernel Panic là một trạng thái lỗi nghiêm trọng của hệ điều hành, xảy ra khi kernel gặp một lỗi không thể phục hồi hoặc xử lý được
+ Lỗi phần cứng:
	+ RAM bị lỗi hoặc không tương thích.
	+ CPU quá nhiệt hoặc gặp vấn đề.
 





**Phân biệt Macro và Function trong C/C++**
 

1. Macro:
	- Macro là một đoạn mã được định nghĩa  bằng chỉ thị #define, được xử lý trong quá trình tiền xử lý 
	- Khi biên dịch,thay thế tên macro bằng nội dung của nó .
2. Function :
	- Function là một khối mã được định nghĩa với  tên 
	- Có thể được gọi nhiều lần trong chương trình.
	- Function được xử lý trong giai đoạn Compilation và Linking.
		+ Compilation	Biên dịch Function thành mã máy 
		+ Linking	Liên kết các Function từ các file hoặc thư viện để tạo file thực thi cuối cùng.
![image](https://github.com/user-attachments/assets/d7764ecd-1bf9-457a-ad0d-99c91b6833e0)


**Cách hệ điều hành xử lý hàm ngắt**
Bước 1: Phát hiện ngắt
- Ngắt có thể được gửi từ phần cứng (như bàn phím, timer, mạng) hoặc phần mềm (như lỗi chương trình hoặc yêu cầu hệ thống).
- Khi một ngắt xảy ra, CPU tạm dừng thực thi chương trình hiện tại.
Bước 2: Lưu trạng thái hiện tại
- CPU lưu trạng thái hiện tại (giá trị thanh ghi, bộ đếm chương trình - PC) vào stack.
Bước 3: Chuyển quyền điều khiển đến hàm xử lý ngắt(ISR)
- CPU tìm địa chỉ của hàm xử lý ngắt  thông qua bảng vector ngắt
- Hệ điều hành nhảy đến ISR tương ứng để xử lý sự kiện.
Bước 4: Xử lý ngắt
- ISR thực hiện công việc cần thiết:
	- Ví dụ: Nếu ngắt do bàn phím, ISR sẽ đọc dữ liệu từ bộ đệm bàn phím.
Bước 5: Khôi phục trạng thái và tiếp tục chương trình
- Sau khi ISR hoàn thành, hệ điều hành:
	- Khôi phục trạng thái CPU từ stack.
	- Tiếp tục thực thi chương trình trước đó từ điểm bị ngắt.

**enum,typedef**
- enum là một kiểu dữ liệu liệt kê, cho phép định nghĩa một tập hợp các hằng số nguyên có tên
- Các giá trị trong enum mặc định được gán giá trị nguyên tăng dần từ 0.
enum EnumName {
    VALUE1,
    VALUE2,
    VALUE3,
    // ...
};
- typedef: Định nghĩa tên mới cho kiểu dữ liệu hiện có.
typedef unsigned int uint;
uint x = 10;  // x là một unsigned int

**Atomic**
 
- Chúng đảm bảo rằng một thao tác đọc-ghi (ví dụ, tăng giá trị của biến) sẽ diễn ra trọn vẹn mà không bị xen ngang
- Khi nào sử dụng, cần thao tác nhanh, đơn giản.Không cần dùng mutex

**Spinlock(c++ không hỗ trợ)**
- Spinlock là một loại lock nhẹ
- Khác với mutex: Mutex có thể đưa luồng vào trạng thái ngủ, còn spinlock không làm vậy mà tiếp tục "quay vòng".
- Ưu điểm:Hiệu quả hơn mutex khi thời gian giữ khóa ngắn, vì không có chi phí chuyển trạng thái giữa chạy và ngủ.

**Semaphore**
- Semaphore là một công cụ đồng bộ hóa cho phép giới hạn số lượng luồng truy cập vào một tài nguyên cụ thể cùng một lúc.
- Có hai loại chính
	- Giới hạn số lượng luồng có thể truy cập.
	- Giống như mutex, chỉ cho phép một luồng truy cập.
	- Các luồng khác có thể giải phóng luồng nắm giữ dữ liệu
- Mục đích là điều phối luồng có thể truy cập dữ liệu, không bảo vệ

**fork()**
- fork() là một hàm hệ thống trong các hệ điều hành Unix/Linux, 
- được sử dụng để tạo ra một tiến trình con (child process) từ tiến trình cha (parent process). 
- Sau khi gọi fork(), tiến trình cha và tiến trình con sẽ chạy song song và độc lập
- Hàm fork() trả về các giá trị khác nhau tùy thuộc vào ngữ cảnh:
	- 0: Trả về trong tiến trình con.
	- Dương số (> 0): Trả về PID (Process ID) của tiến trình con trong tiến trình cha.
	- Âm số (< 0): Trả về nếu có lỗi, không thể tạo tiến trình con.
- Khi tiến trình con kết thúc nhưng tiến trình cha chưa gọi wait(), tiến trình con trở thành "zombie".
	- Lãng phí tài nguyên trong Process Table.(hết pid)
- Orphan Process:
- Nếu tiến trình cha kết thúc trước khi tiến trình con kết thúc, tiến trình con trở thành "orphan" và được init process nhận quản lý.
	
**cross compiler**
- Cross Compiler là trình biên dịch có khả năng tạo ra mã nhị phân có thể chạy trên một nền tảng khác với nền tảng nơi trình biên dịch đang hoạt động.
- Biên dịch mã trên máy tính (x86_64) để chạy trên vi điều khiển STM32 (kiến trúc ARM Cortex-M).
- Ví dụ:
- Bạn đang làm việc trên máy tính Windows/Linux và muốn viết chương trình chạy trên vi điều khiển ARM Cortex-M. Trong trường hợp này, bạn cần một cross compiler để tạo mã nhị phân có thể chạy trên vi điều khiển.
- Tại sao Keil C là một cross compiler?
- Host System:
- Keil C chạy trên máy tính (Windows) để viết mã nguồn.
- Target System:
- Keil C biên dịch mã thành mã nhị phân để chạy trên các vi điều khiển (như ARM Cortex-M, 8051...).
- Chức năng cross compiling:
- Keil C biên dịch mã C/C++ trên máy tính thành mã máy (machine code) có thể chạy trên các vi điều khiển đích.
- Hệ nhị phân (firmware) này sau đó được nạp vào vi điều khiển thông qua giao tiếp như SWD, JTAG, hoặc UART.


**Phân tích issue**
- Xác định rõ vấn đề, thu thập dữ liệu, tái hiện lỗi, phân tích log, và xác định nguyên nhân gốc rễ.
- Log cần thiết:
	- Log hệ thống, log ứng dụng, log mạng, log debugger, core dump, và log cấu hình.
- Bước 1: Xác định rõ issue
	- Sau một bản cập nhật, khi tải cao, hoặc trên môi trường cụ thể.
- Bước 2: Thu thập dữ liệu liên quan
	- Log file: Ghi lại các sự kiện trước và trong khi lỗi xảy ra.
- Bước 3: Tái hiện lỗi
	- Tái hiện theo kịch bản người dùng đã gặp lỗi.
- Bước 4: Phân tích log và triệu chứng
	- Phân tích các log thu thập được:
	- Kiểm tra trạng thái hệ thống:
	- CPU, bộ nhớ, I/O, hoặc kết nối mạng có bị quá tải không?
- Bước 5: Xác định nguyên nhân gốc rễ
	- Xác định vấn đề thuộc về:
	- Lỗi phần mềm: Bug trong logic hoặc code.
	- Lỗi cấu hình: Cài đặt sai cấu hình phần mềm hoặc môi trường.
	- Lỗi môi trường: Phần cứng, mạng, hoặc tài nguyên không đủ.
- Bước 6: Đề xuất và thực hiện giải pháp
	- Sau khi xác định nguyên nhân:
	- Cung cấp bản vá hoặc sửa lỗi.
	- Điều chỉnh cấu hình hệ thống.
	- Nâng cấp tài nguyên phần cứng (nếu cần).
	- Thử nghiệm và xác minh lại để đảm bảo vấn đề được giải quyết.


**Linux có mấy loại context?**
- context là môi trường có  đó một tiến trình hoặc tác vụ  đang chạy
1. User Context các chương trình thông thường như trình duyệt, biên dịch, ứng dụng.
2. Kernel Context (Ngữ cảnh nhân)
	- Đây là ngữ cảnh trong đó mã của kernel (nhân Linux) chạy. Kernel có toàn quyền kiểm soát hệ thống và phần cứng,
3. Interrupt Context :Ngữ cảnh này xuất hiện khi hệ thống xử lý một ngắt 




**Tính chất của ngôn ngữ C:**
- Ngôn ngữ lập trình bậc thấp (Low-level language): C gần với ngôn ngữ máy hơn các ngôn ngữ lập trình bậc cao khác, điều này giúp nó có khả năng điều khiển phần cứng mạnh mẽ và tối ưu hóa hiệu suất.
- Ngôn ngữ thủ tục (Procedural Language): C chủ yếu dựa trên cách lập trình thủ tục, tức là chương trình được cấu trúc thành các hàm 
- cho phép truy cập trực tiếp vào phần cứng và quản lý tài nguyên hệ thống hiệu quả.
	+  lập trình viên có thể trực tiếp thao tác với thanh ghi, không cần phụ thuộc vào lớp trung gian, giảm độ trễ và tăng hiệu quả.
- Nó tạo ra mã máy gọn nhẹ, phù hợp với các hệ thống nhúng có tài nguyên hạn chế (bộ nhớ, CPU).
- Chương trình viết bằng C thường chiếm ít dung lượng hơn so với các ngôn ngữ khác, 
- Quản lý bộ nhớ: C cho phép lập trình viên cấp phất và giải phóng bộ nhớ  thông qua các con trỏ. 
- Điều này giúp tối ưu hóa bộ nhớ hạn chế trong hệ thống nhúng, 
- vì lập trình viên có thể chỉ cấp phát đúng lượng bộ nhớ cần thiết và giải phóng nó khi không còn dùng.
- tự động quản lý bộ nhớ (garbage collection) Điều này tiện lợi, nhưng gây ra chi phí tài nguyên không cần thiết,




**Tính chất của ngôn ngữ C++:**
- C++ là một ngôn ngữ bậc trung:C++ cung cấp cả tính năng gần gũi với phần cứng như C (ví dụ như quản lý bộ nhớ thủ công, truy cập địa chỉ bộ nhớ trực tiếp,...) và các tính năng bậc cao như lập trình hướng đối tượng, xử lý ngoại lệ (exception handling), và thư viện chuẩn phong phú (STL).
g.

**Mảng và con trỏ**
- Tên của mảng là một con trỏ hằng, trỏ đến địa chỉ ô nhớ đầu tiên của mảng
- Truy cập phần tử mảng bằng con trỏ.
- Khi làm việc với mảng động,dùng  con trỏ để quản lý bộ nhớ.
- Khi truyền mảng vào hàm, thực chất bạn đang truyền địa chỉ của phần tử đầu tiên của mảng.
- Khác biệt :
	- Mảng là một vùng nhớ liên tiếp được định nghĩa cố định.
	- Con trỏ là một biến có thể trỏ đến bất kỳ địa chỉ nào, không nhất thiết phải là mản


**Câu lệnh if và switch**
- if: 
	+ Ở đây, if kiểm tra một điều kiện phức tạp liên quan đến nhiều biến và phép toán logic (&&, ||).
	+ if có thể kiểm tra mọi loại điều kiện, bao gồm cả biểu thức logic phức tạp.
- switch: Hạn chế, chỉ sử dụng cho kiểm tra giá trị của biến nguyên, ký tự, hoặc enum.

```C
int a = 10;
int b = 20;
int c = 30;

if (a < b && c > b) {
    std::cout << "a nhỏ hơn b và c lớn hơn b" << std::endl;
} else if (a == b || c < b) {
    std::cout << "a bằng b hoặc c nhỏ hơn b" << std::endl;
} else {
    std::cout << "Điều kiện không thỏa mãn" << std::endl;
}

```

```c
int option = 2;

switch (option) {
    case 1:
        std::cout << "Lựa chọn 1" << std::endl;
        break;
    case 2:
        std::cout << "Lựa chọn 2" << std::endl;
        break;
    case 3:
        std::cout << "Lựa chọn 3" << std::endl;
        break;
    default:
        std::cout << "Lựa chọn không hợp lệ" << std::endl;
}

#include <iostream>

// Định nghĩa một enum để đại diện cho các ngày trong tuần
enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    Day today = Wednesday;

    switch (today) {
        case Monday:
            std::cout << "Hôm nay là Thứ Hai." << std::endl;
            break;
        case Tuesday:
            std::cout << "Hôm nay là Thứ Ba." << std::endl;
            break;
        default:
            std::cout << "Ngày không hợp lệ!" << std::endl;
    }

    return 0;
}

```
**Memory leak trong C programming**
- Memory leak(rò rỉ bộ nhớ) : Xảy ra khi bộ nhớ được cấp phát động bằng malloc() hoặc calloc() nhưng không được giải phóng bằng free(). Điều này dẫn đến việc bộ nhớ bị chiếm dụng không cần thiết, làm giảm hiệu suất và có thể làm chương trình gặp lỗi do thiếu bộ nhớ.

**Phân biệt Program và Process,Thread:**
1. Program: Nó là một thực thể thụ động (passive entity) và không có trạng thái thực thi. được lưu trữ trên một thiết bị lưu trữ (như ổ cứng) dưới dạng một tệp thực thi Ví dụ, tệp .exe hoặc .bin là các chương trình.Nó không hoạt động cho đến khi được thực thi
2. Process: Là một thực thể hoạt động (active entity) đại diện cho việc thực thi của một chương trình. Khi một chương trình(Program) được chạy, nó trở thành một process. Process bao gồm các tài nguyên như CPU thời gian, bộ nhớ, các tập tin đang mở  
	+  CPU (Bộ xử lý)  CPU thực hiện các lệnh trong chương trình của process.
	+  Bộ nhớ Process cần không gian bộ nhớ để lưu

3. Tóm lại, program là "kế hoạch" còn process là "thực thi kế hoạch đó". Khi bạn chạy một chương trình, nó sẽ trở thành một hoặc nhiều process trên hệ thống.
4. Thread:Là đơn vị nhỏ hơn của một process, một luồng thực thi bên trong process. Một process có thể chứa nhiều thread.
5.  Các thread trong cùng một process chia sẻ cùng không gian địa chỉ, có thể chia sẻ dữ liệu và tài nguyên với nhau nhưng vẫn có ngăn xếp và bộ đếm chương trình riêng.
6.  So sánh giữa Process và Thread:
 - Memory:
	+ Process: Có không gian địa chỉ riêng biệt. Mỗi process có bộ nhớ riêng không chia sẻ với các process khác.
	+ Thread: Các thread trong cùng một process chia sẻ không gian địa chỉ và tài nguyên của process đó. Mỗi thread có ngăn xếp riêng nhưng chia sẻ mã lệnh, dữ liệu, và heap với các thread khác trong cùng process.
 - Data Sharing:
	+ Process: Dữ liệu không thể dễ dàng chia sẻ giữa các process vì chúng có không gian địa chỉ riêng. Việc chia sẻ dữ liệu giữa các process thường yêu cầu các cơ chế IPC (Inter-Process Communication) như pipes, message queues, hoặc shared memory.
	+ Thread: Dễ dàng chia sẻ dữ liệu với các thread khác trong cùng process vì chúng chia sẻ cùng một không gian địa chỉ.
 - Process Switching vs Thread Switching:
	+ Process Switching (Chuyển đổi tiến trình): Process switching xảy ra khi hệ điều hành dừng việc thực thi của một process hiện tại và chuyển sang thực thi một process khác. Quá trình này thường xảy ra khi một process bị chuyển sang trạng thái chờ (waiting) hoặc hệ điều hành quyết định thực hiện lập lịch lại (scheduling) để phân chia tài nguyên CPU cho các process khác.
	+ Thread Switching (Chuyển đổi luồng) Thread switching xảy ra khi hệ điều hành chuyển đổi việc thực thi từ một thread này sang thread khác, thường là trong cùng một process. Điều này có thể xảy ra khi một thread bị chuyển sang trạng thái chờ hoặc khi một thread khác có độ ưu tiên cao hơn cần được thực thi.
	+ Process Switching: Đòi hỏi nhiều tài nguyên vì cần phải lưu và khôi phục ngữ cảnh đầy đủ của process, bao gồm không gian địa chỉ và tài nguyên hệ thống. Quá trình này chậm hơn so với thread switching.
	+ Thread Switching: Nhanh hơn vì chỉ cần lưu và khôi phục ngữ cảnh của thread, và các thread chia sẻ cùng không gian địa chỉ nên không cần chuyển đổi toàn bộ không gian địa chỉ.


**Context Switching hoạt động như thế nào?**
- Context Switching: Là quá trình mà hệ điều hành dừng việc thực thi một process hiện tại để chuyển sang thực thi một process khác. Trong quá trình này, ngữ cảnh (context) của process hiện tại (bao gồm các thanh ghi CPU, chương trình đếm, ngăn xếp, v.v.) được lưu trữ vào một nơi nào đó (thường là PCB - Process Control Block). Sau đó, ngữ cảnh của process khác được nạp vào để tiếp tục thực thi. Đây là một quá trình nặng về tài nguyên vì cần phải lưu và nạp lại nhiều thông tin từ bộ nhớ.

**Phân biệt Zombie Process và Orphan Process**
1. Zombie Process: Là một process đã kết thúc việc thực thi nhưng vẫn còn tồn tại trong bảng process vì nó chưa được parent process lấy thông tin trạng thái (status) của nó thông qua lệnh wait. Nó vẫn giữ một PID nhưng không còn sử dụng tài nguyên hệ thống.
2. Orphan Process: Là một process mà parent process đã kết thúc hoặc bị kill trước khi nó kịp hoàn thành. Khi một process trở thành orphan, hệ điều hành (thường là init process) sẽ nhận làm parent mới của nó để quản lý.
3. PID (Process ID): Mỗi process trong hệ thống đều có một mã định danh duy nhất gọi là PID. Ngay cả khi process đã chuyển sang trạng thái Zombie, PID của nó vẫn được hệ điều hành giữ lại.
4. Nếu có quá nhiều Zombie Process, chúng có thể làm cạn kiệt số lượng PID có sẵn trong hệ thống, dẫn đến việc không thể tạo thêm process mới.
5. Tại sao PID được giữ lại?: Khi một process kết thúc, nó cần báo cáo lại cho parent process về kết quả thực thi của mình (thông qua tín hiệu như SIGCHLD). PID được giữ lại để parent process có thể xác định và xử lý thông tin này. Nếu parent process gọi lệnh wait() hoặc waitpid() sau khi nhận tín hiệu, PID của Zombie Process sẽ được giải phóng và process này sẽ bị xóa khỏi bảng process.
6. Orphan Process: Là một process mà parent process đã kết thúc hoặc bị kill trước khi nó kịp hoàn thành. Khi một process trở thành orphan, hệ điều hành (thường là init process) sẽ nhận làm parent mới của nó để quản lý.
7. Process Image: bao gồm tất cả dữ liệu và mã lệnh cần thiết để thực thi process.
8. Khi Child Process kết thúc vòng đời thực thi của mình, signal nào được gửi đến Parent Process?
	- nó sẽ gửi một tín hiệu SIGCHLD đến parent process của nó. Parent process có thể xử lý tín hiệu này để gọi hàm wait() hoặc waitpid() nhằm lấy thông tin trạng thái và dọn dẹp tài nguyên của child process.

**Synchronous/Asynchronous là gì?**
1. Synchronous (Đồng bộ):
- Các hoạt động đồng bộ đòi hỏi phải hoàn thành từng bước một. Một hoạt động phải hoàn tất trước khi hoạt động tiếp theo có thể bắt đầu.
- Ví dụ: Khi gọi một hàm đồng bộ, chương trình sẽ chờ hàm đó hoàn thành trước khi tiếp tục.
2. Asynchronous (Bất đồng bộ):
- Các hoạt động bất đồng bộ cho phép các bước tiếp theo được thực hiện mà không cần chờ hoạt động trước hoàn thành.
- Ví dụ: Khi gọi một hàm bất đồng bộ, chương trình có thể tiếp tục thực thi mà không cần chờ hàm đó hoàn thành, và kết quả của hàm sẽ được xử lý sau khi hoàn thành.
3. Mutex (Mutual Exclusion):
-  Là một cơ chế đồng bộ được sử dụng để tránh tình trạng truy cập đồng thời vào một tài nguyên dùng chung (shared resource), như một biến hoặc một đoạn mã. Chỉ một thread có thể nắm giữ mutex tại một thời điểm, do đó ngăn chặn các thread khác truy cập vào tài nguyên dùng chung đó.
4. Conditional Variable:
- Là một cơ chế đồng bộ cho phép các thread chờ cho đến khi một điều kiện cụ thể trở thành đúng. Nó thường được sử dụng kết hợp với mutex để quản lý truy cập vào tài nguyên dùng chung dựa trên điều kiện.

**Atomic/Non-Atomic, Shared Resource, Critical Section**
1. Atomic/Non-Atomic:
- Atomic Operation: Là một hoạt động hoàn toàn không thể bị ngắt giữa chừng. Điều này có nghĩa là nếu một hoạt động atomic bắt đầu, nó sẽ hoàn thành mà không bị gián đoạn, đảm bảo tính toàn vẹn dữ liệu.
- Non-Atomic Operation: Là hoạt động có thể bị ngắt giữa chừng, dẫn đến khả năng gặp phải các vấn đề như race condition khi nhiều thread hoặc process truy cập vào cùng một tài nguyên.
2. Shared Resource:
- Là tài nguyên (như biến, file, hoặc bộ nhớ) được nhiều thread hoặc process cùng truy cập và sử dụng. Việc truy cập đồng thời vào tài nguyên chia sẻ có thể dẫn đến xung đột và đòi hỏi cơ chế đồng bộ như mutex để đảm bảo tính toàn vẹn.
3. Critical Section:
- Là một đoạn mã mà tại đó tài nguyên chia sẻ được truy cập. Để ngăn chặn tình trạng race condition, chỉ một thread hoặc process được phép vào critical section tại một thời điểm, thường được bảo vệ bằng mutex hoặc các cơ chế đồng bộ khác.
4. Một vài trường hợp gây ra hiện tượng Deadlock
- Deadlock xảy ra khi hai hoặc nhiều process hoặc thread rơi vào tình trạng chờ lẫn nhau, dẫn đến không thể tiếp tục thực thi. Một số tình huống dẫn đến deadlock:
- Mutual Exclusion: Hai thread đều cần truy cập một tài nguyên và tài nguyên này không thể chia sẻ (như khóa mutex).
- Hold and Wait: Một thread đã giữ một tài nguyên và chờ để có được tài nguyên khác, trong khi thread khác đang giữ tài nguyên đó và cũng chờ tài nguyên của thread đầu tiên.
- No Preemption: Tài nguyên không thể bị thu hồi từ một thread khi nó đã nắm giữ.
Circular Wait: Một chuỗi các thread hình thành một vòng lặp trong đó mỗi thread chờ tài nguyên mà thread tiếp theo đang giữ.
5. IPC là gì?
- IPC là viết tắt của Inter-Process Communication (Giao tiếp giữa các tiến trình).
- IPC được sử dụng khi:
- Các tiến trình cần chia sẻ dữ liệu hoặc tài nguyên.
- Các tiến trình cần phối hợp hoặc đồng bộ hóa để thực hiện một tác vụ chung.
- Thực hiện truyền tải dữ liệu giữa các tiến trình trên cùng một hệ thống hoặc trên các hệ thống khác nhau (qua mạng).
6.  Một vài phương thức IPC phổ biến
- Pipe: Giao tiếp một chiều giữa hai tiến trình, thường là giữa tiến trình cha và con.
- FIFO (Named Pipe): Giao tiếp hai chiều, cho phép các tiến trình không cùng họ (không phải cha-con) giao tiếp.
- Message Queue: Hàng đợi lưu trữ các thông điệp để các tiến trình đọc/ghi không đồng bộ.
- Shared Memory: Bộ nhớ chia sẻ giữa các tiến trình, cho phép tốc độ truyền dữ liệu nhanh nhưng cần đồng bộ hóa.
- Socket: Giao tiếp giữa các tiến trình trên cùng máy hoặc giữa các máy khác nhau qua mạng.
- Semaphore: Đồng bộ hóa truy cập tài nguyên giữa các tiến trình.
- Signal: Gửi tín hiệu để thông báo hoặc điều khiển tiến trình khác.
7. Phân loại IPC
- Communication (Truyền thông)
	- Data Transfer (Truyền dữ liệu): Phương thức IPC này được sử dụng để truyền dữ liệu giữa các tiến trình.
	- Pipe: Giao tiếp một chiều, chỉ cho phép một tiến trình ghi và tiến trình khác đọc.
	- FIFO (Named Pipe): Giao tiếp hai chiều, có thể dùng cho các tiến trình không liên quan.
	- Stream Socket: Giao tiếp hai chiều qua mạng, thường dùng cho giao tiếp TCP.
	- Message (Thông điệp): Cho phép các tiến trình gửi và nhận thông điệp theo cơ chế hàng đợi hoặc gói dữ liệu.
	- Message Queue: Lưu trữ các thông điệp để tiến trình khác đọc khi cần.
	- Datagram Socket: Giao tiếp qua UDP, không đảm bảo thứ tự và tính toàn vẹn dữ liệu.
- 3.2. Synchronization (Đồng bộ hóa)
	- Phương thức này được sử dụng để đảm bảo các tiến trình hoặc luồng thực thi đúng trình tự hoặc không xảy ra xung đột khi truy cập tài nguyên dùng chung.
	- Semaphore: Dùng để đồng bộ hóa truy cập tài nguyên, kiểm soát số lượng tiến trình có thể truy cập tài nguyên cùng lúc.
	- Mutex: Đảm bảo chỉ có một tiến trình duy nhất truy cập tài nguyên tại một thời điểm.
	- Barrier: Đồng bộ các tiến trình để tất cả phải đạt đến một điểm chung trước khi tiếp tục.
	Condition Variable: Cơ chế đồng bộ cho phép tiến trình chờ một điều kiện cụ thể xảy ra.
- Tổng kết:
	- Communication tập trung vào việc truyền dữ liệu.
	- Synchronization đảm bảo tính đúng đắn trong việc truy cập tài nguyên hoặc thực hiện các tác vụ đồng thời.
8. volatile trong C là gì?
	- Khi khai báo một biến là volatile, trình biên dịch sẽ không tối ưu hóa giá trị của biến đó. 
	- Khi nào cần khai báo một biến là volatile?
		- Phần cứng: Các thanh ghi phần cứng có thể thay đổi giá trị tự động.
		- Biến toàn cục được truy xuất từ nhiều tác vụ trong ứng dụng đa luồng
			- Trong các ứng dụng đa luồng, các luồng khác nhau có thể truy cập và thay đổi giá trị của một biến toàn cục.
			- Nếu không dùng volatile, trình biên dịch có thể tối ưu hóa và giữ giá trị của biến trong một bộ nhớ cache cục -  bộ, dẫn đến các luồng khác không nhìn thấy được thay đổi
			- Nếu không sử dụng volatile, trình biên dịch có thể tối ưu hóa và chỉ đọc giá trị này một lần, dẫn đến sai sót khi thanh ghi tự động thay đổi.
		-  Ngắt (Interrupt): Giá trị của biến có thể được cập nhật trong trình xử lý ngắt.Ví dụ nhấn nút
	- Ví dụ thanh ghi Phần cứng:
		- Thanh ghi dữ liệu ADC, Thanh ghi đếm timer ,trạng thái GPIO:	
			- Các giá trị này liên tục và giống nhau , khi tối ưu thì sẽ mất dữ liệu 
		- Ngắt (Interrupt):Tình biên dịch thường cố gắng tối ưu hóa hiệu suất bằng cách giữ giá trị của biến trong thanh ghi CPU thay vì đọc từ bộ nhớ mỗi lần.
			- Nếu biến buttonPressed không được khai báo là volatile, trình biên dịch có thể giả định rằng giá trị của biến này không thay đổi trong suốt vòng lặp chính của chương trình, dẫn đến:
			- Vòng lặp chính sẽ sử dụng giá trị cũ trong thanh ghi mà không biết rằng trình xử lý ngắt đã thay đổi giá trị của biến.

- Trong lập trình nhúng, chúng ta hay gặp đoạn code khi ta khai báo 1 biến đếm count, mỗi khi bấm nút xảy ra ngắt ngoài, chúng ta tăng biến đếm count. Tuy nhiên, khi chúng ta bật tính năng tối ưu code của compiler, nó sẽ hiểu rằng các biến như vậy dường như không thay đổi giá trị bởi phần mềm nên compiler có xu hướng loại bỏ biến count để có thể tối ưu kích cỡ file code chạy được sinh ra.
- Lý do trình biên dịch loại bỏ biến không dùng volatile
	- Khi bật các tính năng tối ưu hóa, trình biên dịch sẽ cố gắng:
	- Tối ưu hóa kích thước mã lệnh.
	- Giảm số lượng truy cập bộ nhớ.
	- Vì trình biên dịch không biết rằng biến count có thể bị thay đổi bên ngoài (do ISR), nó có thể:
	- Chuyển count vào một thanh ghi CPU.
	- Sử dụng giá trị cũ mà không cập nhật từ bộ nhớ.

9. Hiện tượng Race Condition
- Khái niệm:
	- Race Condition xảy ra khi nhiều thread hoặc tiến trình cùng truy cập và thao tác trên critical resource (tài nguyên quan trọng) mà không được đồng bộ hóa đúng cách.
	- Nếu các thao tác không diễn ra theo thứ tự dự kiến, hệ thống có thể rơi vào trạng thái không xác định, dẫn đến lỗi.
	- Ví dụ về Race Condition:
	- Giả sử có hai thread cùng thao tác trên một biến đếm counter:
```c
Sao chép mã
// Thread 1
counter++;

// Thread 2
counter++;
```
- Nếu hai thread này chạy đồng thời, kết quả của counter có thể sai do:
	- counter được đọc, tăng, rồi ghi lại một cách không đồng bộ, dẫn đến giá trị cuối cùng không đúng.
	- Cơ chế xử lý: Mutual Exclusion
	- Mutual Exclusion đảm bảo rằng tại mỗi thời điểm, chỉ một thread có quyền truy cập và thao tác trên critical resource.
- Công cụ để thực thi:
	- Mutex (Mutual Exclusion Lock).
	- Semaphore.
	- Spinlock.
10. Atomic
- Khái niệm:
	- Atomic operations là các thao tác trên dữ liệu mà không thể bị gián đoạn hoặc bị ảnh hưởng bởi các thread khác.
	Chúng đảm bảo rằng một thao tác đọc-ghi (ví dụ, tăng giá trị của biến) sẽ diễn ra trọn vẹn mà không bị xen ngang.
- Case sử dụng:
	- Khi critical resource chỉ là một biến đơn giản hoặc một bit.
	- Ví dụ: Tăng, giảm giá trị một biến đếm (counter), hoặc kiểm tra, đặt một cờ (flag) trạng thái.
- Các thao tác Atomic thường gặp:
	- Atomic trên số nguyên:
	
```c
//Tăng hoặc giảm giá trị nguyên tử:
__sync_fetch_and_add(&counter, 1);  // Tăng counter một cách nguyên tử
__sync_fetch_and_sub(&counter, 1);  // Giảm counter một cách nguyên tử
```
- Atomic trên bit:
```c
//Kiểm tra, đặt hoặc xóa bit:
__sync_or_and_fetch(&flags, 0x01);  // Đặt bit 0
__sync_and_and_fetch(&flags, ~0x01); // Xóa bit 0

```

11. Spinlock
- Khái niệm:
	- Spinlock là một loại khóa giúp thực thi mutual exclusion.
	- Khi một thread cố gắng khóa spinlock, nếu nó chưa có sẵn, thread sẽ liên tục kiểm tra (spin) cho đến khi khóa được giải phóng.
- Hoạt động:
	- Nếu spinlock đã bị khóa bởi một thread khác, thread hiện tại sẽ:
	- Không bị chặn (block) mà sẽ liên tục kiểm tra trạng thái khóa.
	- Khi khóa được giải phóng, thread giành được quyền truy cập và tiếp tục thực thi.
- Case sử dụng:
	- Khi critical resource là một cấu trúc dữ liệu phức tạp hoặc bộ nhớ chia sẻ cần đồng bộ hóa.
	- Thích hợp khi thời gian giữ khóa ngắn vì việc spin tiêu tốn CPU.
- Ưu điểm:
	- Hiệu quả cho các tác vụ ngắn, tránh chi phí cao của việc block/unblock thread.
- Nhược điểm:
	- Tiêu tốn tài nguyên CPU nếu thời gian chờ khóa dài.
- Tóm tắt
	- Race Condition: Xảy ra khi nhiều thread truy cập và thao tác trên cùng một tài nguyên mà không có đồng bộ hóa.
	- Atomic: Đảm bảo thao tác trên biến đơn giản diễn ra toàn vẹn, không bị gián đoạn.
	- Spinlock: Một dạng khóa cho phép thực hiện mutual exclusion, hiệu quả cho các tác vụ cần khóa ngắn.
12. Mutex
- Khái niệm
	- Mutex (Mutual Exclusion) là một cơ chế đồng bộ hóa, đảm bảo rằng chỉ một thread hoặc tiến trình có thể truy cập vào critical resource tại một thời điểm.
	- Khác với spinlock, mutex cho phép blocking. Thread không giành được mutex sẽ bị đưa vào trạng thái chờ và không tiêu tốn CPU trong khi đợi.
- Case sử dụng
	- Khi critical resource là cấu trúc dữ liệu phức tạp hoặc khi critical section gồm nhiều câu lệnh.
	- Kỹ thuật atomic không phù hợp vì chỉ hoạt động tốt với các thao tác đơn giản như tăng hoặc giảm biến.
	- Mutex phù hợp khi cần:
	- Đồng bộ hóa tài nguyên phức tạp.
	- Tránh busy-waiting như trong spinlock.
	- Cấu tạo của Mutex
	- Mutex trong hệ điều hành thường bao gồm các thành phần sau:
- atomic_t count
	- count đại diện cho trạng thái của mutex:
	- count = 1: Mutex đang mở (UNLOCKED), có thể được giành bởi thread khác.
	- count = 0: Mutex đang đóng (LOCKED), thread khác phải chờ.
- *struct task_struct owner
	- Biến này lưu trữ thông tin về thread hiện tại đang nắm giữ mutex.
	- Dùng để xác định thread nào đang chiếm giữ tài nguyên và có thể ưu tiên xử lý nếu cần.
	- struct list_head wait_list
	- Hàng đợi các thread đang chờ mutex.
	- Nếu một thread không giành được mutex, nó sẽ được thêm vào danh sách wait_list và chuyển sang trạng thái chờ (sleep).
	- Hoạt động của Mutex
- Locking (Khóa):
	- Khi một thread gọi acquire_mutex:
	- Nếu mutex đang UNLOCKED (count = 1), thread đó giành được mutex, count = 0.
	- Nếu mutex đang LOCKED (count = 0), thread đó được thêm vào wait_list và chuyển sang trạng thái chờ.
- Unlocking (Mở khóa):
	- Khi thread giữ mutex hoàn thành critical section và gọi release_mutex:
	count được đặt lại thành 1.
	- Nếu có thread trong wait_list, một thread sẽ được đánh thức và giành mutex.
- Thread Ownership:
	- Mutex thường yêu cầu chủ sở hữu (owner) chính là thread đã khóa mutex.
	- Chỉ thread này mới có thể mở khóa mutex, giúp ngăn ngừa lỗi khi một thread không hợp lệ cố gắng mở khóa mutex.
	- Ưu điểm của Mutex
	- Tránh lãng phí CPU:
	- Thread không giành được mutex sẽ bị block và không tiêu tốn CPU trong khi chờ.
	- Đồng bộ hóa hiệu quả:
- Đảm bảo mutual exclusion cho critical section phức tạp với nhiều thao tác.
- Nhược điểm của Mutex
- Deadlock:
	- Nếu hai thread giữ mutex và chờ mutex khác, có thể dẫn đến deadlock. Ví dụ:
	- Thread 1 giữ Mutex A, chờ Mutex B.
	- Thread 2 giữ Mutex B, chờ Mutex A.
- Overhead lớn hơn spinlock:
	- Do mutex phải quản lý wait_list và chuyển trạng thái thread.
13. Semaphore
- Khái niệm
	- Semaphore là một cấu trúc dữ liệu được sử dụng để:
	- Đồng bộ tài nguyên: Quản lý truy cập đồng thời vào critical resource.
	- Đồng bộ hoạt động: Đảm bảo thứ tự thực thi giữa các thread.
- Case sử dụng
	- Semaphore được ví như bộ chìa khóa dự phòng:
	- Counting semaphore: Quản lý số lượng tài nguyên giới hạn, cho phép nhiều thread đồng thời sử dụng tài nguyên.
	- Binary semaphore: Hoạt động như mutex, cho phép một thread truy cập tài nguyên tại một thời điểm.
- Ví dụ:
	- Counting semaphore:
	- Kiểm soát số lượng kết nối vào một dịch vụ mạng (ví dụ: tối đa 10 kết nối cùng lúc).
	- Binary semaphore:
	- Đồng bộ hóa truy cập vào một critical section tương tự như mutex, nhưng không yêu cầu thread giữ khóa phải là thread - giải phóng khóa.
- Cấu tạo của Semaphore
	- raw_spinlock_t lock:
	- Spinlock bảo vệ các thành phần bên trong semaphore.
	- Do semaphore là một critical resource, cần spinlock để đảm bảo các thao tác trên count và wait_list được thực hiện nguyên tử.
- atomic_t count:
	- Quản lý số lượng tài nguyên sẵn có.
	- Khi một thread giành được semaphore, count giảm.
	- Khi một thread giải phóng semaphore, count tăng.
- struct task_struct *owner:
	- Lưu trữ thông tin về thread hiện tại đang giữ semaphore (nếu có).
- struct list_head wait_list:
	- Hàng đợi các thread đang chờ semaphore.
	- Nếu không giành được semaphore, thread sẽ được thêm vào wait_list và chuyển sang trạng thái chờ.
- Phân loại Semaphore
	- Counting Semaphore:
		- Giá trị count có thể lớn hơn 1.
		- Quản lý tài nguyên có giới hạn nhiều đơn vị (ví dụ: số lượng kết nối, bộ nhớ dùng chung).
	- Binary Semaphore:
		- Count chỉ có 2 giá trị: 0 hoặc 1.
- Tương tự như mutex, đảm bảo mutual exclusion nhưng không yêu cầu thread giữ khóa phải là thread giải phóng khóa.
- Chú ý khi sử dụng Semaphore
- Chỉ sử dụng trong thread được phép đi ngủ:

- Semaphore sử dụng cơ chế sleep-waiting, do đó:
- Phù hợp: Kernel threads thông thường hoặc bottom-half sử dụng workqueue.
- Không phù hợp: ISR hoặc bottom-half dựa trên tasklet/softirq vì các ngữ cảnh này không cho phép sleep.
- Critical section dài:
	- Semaphore phù hợp với critical section chứa nhiều câu lệnh hoặc có thể gọi sleep/schedule.
	- Thread khác có thể giải phóng Semaphore:
	- Không như mutex hay spinlock, một thread có thể giải phóng semaphore ngay cả khi nó không phải thread giữ semaphore.
	- Điều này giúp semaphore linh hoạt hơn trong các mô hình đồng bộ phức tạp.
- Không đệ quy semaphore:
	- Semaphore không hỗ trợ đệ quy. Nếu một thread cố gắng giành lại semaphore mà nó đã giữ, hệ thống sẽ rơi vào trạng thái deadlock.

14. RCU (Read-Copy-Update)
- Khái niệm:
	- RCU (Read-Copy-Update) là một cơ chế đồng bộ hóa trong kernel, cho phép nhiều thread đọc đồng thời một vùng dữ liệu mà không cần khóa (lock).
	- Khi cần ghi, RCU tạo một bản sao (clone) của dữ liệu để ghi vào đó. Sau khi hoàn thành ghi, dữ liệu sẽ được cập nhật vào vùng nhớ chung khi không còn thread nào đang đọc.
- Cách hoạt động:
	- Nhiều thread có thể đọc đồng thời mà không cần sử dụng mutex hoặc spinlock.
- Khi có thread ghi:
	- Tạo bản sao vùng dữ liệu cần ghi.
	- Ghi dữ liệu vào bản sao.
	- Sau khi không còn thread nào đang đọc dữ liệu gốc, tiến hành thay thế dữ liệu gốc bằng dữ liệu đã chỉnh sửa.
	- Lock-free reading: Đọc không cần khóa, giúp giảm độ trễ và tăng hiệu năng trong hệ thống có nhiều luồng đọc.
- Ưu điểm:
	- Tối ưu hóa hiệu năng khi có nhiều tác vụ đọc.
	- Giảm thiểu xung đột truy cập dữ liệu giữa các thread.
- Nhược điểm:
	- Chi phí bộ nhớ cao hơn do cần tạo bản sao dữ liệu trong quá trình ghi.
	- Độ phức tạp trong việc triển khai, đặc biệt khi cần xác định thời điểm không còn thread đọc dữ liệu cũ.
15. Virtual Memory và Physical Memory
-  Vì sao cơ chế Virtual Memory ra đời?
- Khái niệm cơ bản:
	- Process Address Space: Mỗi tiến trình có một không gian địa chỉ riêng, bao gồm các địa chỉ mà tiến trình sử dụng để tham chiếu tới lệnh và dữ liệu.
	- CPU 32-bit: Không gian địa chỉ tối đa là 4GB (2³² địa chỉ).
- Phân tích vấn đề:
- Yêu cầu vùng nhớ liên tục:
	- Trong một số hệ thống (ví dụ: uCLinux), chương trình được đưa vào một vùng nhớ liên tục trên RAM khi khởi chạy.
- Lợi ích:
	- Lệnh và dữ liệu luôn sẵn sàng, dễ quản lý.
- Nhược điểm:
	- Không thể chạy chương trình có kích thước lớn hơn RAM.
	- Khó tìm vùng nhớ liên tục đủ lớn để chứa chương trình, gây lãng phí bộ nhớ.
- Không cần toàn bộ chương trình trong RAM:
	- Không phải tất cả mã đều được thực thi:
		- Tiến trình chỉ thực thi một số đoạn mã tại một thời điểm.
		- Ví dụ: Trong if-else, đoạn mã else hiếm khi chạy.
	- Một số tính năng ít sử dụng:
		- Mã cho các tính năng này không cần thiết phải tải vào RAM.
	- CPU thực thi tuần tự:
		- Mã chỉ được thực thi lần lượt, không cần đồng thời tải toàn bộ chương trình vào RAM.
- Kết luận:
	- Virtual Memory ra đời để giải quyết các vấn đề trên.
	- Không gian địa chỉ ảo (virtual address space) lớn hơn không gian vật lý, cho phép chương trình sử dụng bộ nhớ hiệu quả.
	- Tăng hiệu suất bằng cách:
		- Chỉ tải các phần cần thiết của chương trình vào RAM.
		- Cho phép chạy chương trình lớn hơn RAM.
- Virtual Memory hoạt động như thế nào?
	- Tách biệt giữa Virtual Memory và Physical Memory:
		- Virtual Address Space: Không gian địa chỉ mà tiến trình sử dụng.
		- Physical Memory: Không gian bộ nhớ vật lý (RAM) thực tế.
- Cơ chế phân trang (Paging):
	- Virtual Memory được chia thành các trang (pages).
	- Khi một trang được tham chiếu, nếu chưa có trong RAM, Page Fault xảy ra và hệ điều hành tải trang từ đĩa cứng vào RAM.
- Lợi ích của Virtual Memory:
	- Sử dụng hiệu quả RAM:
		- Chỉ giữ các trang đang được sử dụng trong RAM.
	- Tăng không gian bộ nhớ:
		- Cho phép các chương trình lớn hơn bộ nhớ vật lý thực tế.
	- Bảo vệ bộ nhớ:
		- Mỗi tiến trình có không gian địa chỉ riêng, giúp cách ly giữa các tiến trình.
- Tóm tắt
	- RCU: Cơ chế đồng bộ hóa, cho phép nhiều thread đọc không cần khóa và ghi thông qua bản sao dữ liệu.
	- Virtual Memory: Tối ưu hóa bộ nhớ bằng cách tách biệt địa chỉ ảo và địa chỉ vật lý, cho phép sử dụng hiệu quả RAM và chạy chương trình lớn hơn bộ nhớ vật lý.
16. Cơ chế Virtual Memory:
	- Virtual Memory cho phép ánh xạ không gian địa chỉ ảo (virtual address space) của tiến trình tới không gian địa chỉ vật lý (physical address space) trên RAM. Điều này giúp hệ điều hành quản lý bộ nhớ hiệu quả hơn.
	- Các thành phần chính:
		- Paging (Phân trang):
			- Bộ nhớ ảo được chia thành các trang (pages) có kích thước cố định.
			- Bộ nhớ vật lý được chia thành các khung trang (page frames) có cùng kích thước.
			- Khi một trang được tham chiếu, hệ điều hành kiểm tra xem trang đó có trong RAM không
				- Nếu có, tiến trình tiếp tục thực thi.
				- Nếu không, xảy ra Page Fault, và hệ điều hành sẽ tải trang từ đĩa cứng (swap space) vào RAM.

		- Page Table (Bảng trang):
			- Mỗi tiến trình có một bảng trang riêng để ánh xạ từ địa chỉ ảo sang địa chỉ vật lý.
			- Giúp đảm bảo tách biệt và bảo mật giữa các tiến trình.











**Enum là gì?**
- Enum (enumeration) là một kiểu dữ liệu cho phép định nghĩa các hằng số có tên.  
- Ví dụ: enum Day{Mon=2, Tue=3, Wed=4, Thur=5, Fri=6, Sat=7, Sun=8}; 
- Day myDay = Wed;
- std::cout << "Day value of WEDNESDAY: " << myDay << std::endl;// in ra 4
**Từ khóa typedef**
- typedef KIỂU DỮ LIỆU  TÊN THAY THẾ; 
- typedef được sử dụng để định nghĩa một tên mới cho một kiểu dữ liệu có sẵn.Hoặc các kiểu mà người dùng định nghĩa (class & struct)
- `typedef double db;db val1 = 1.1;`
- `typedef CodeLearn CL; Với CodeLearn là 1 struct`
**Khác nhau giữa typedef giữa define**
- typedef: Dùng để định nghĩa kiểu dữ liệu đã tồn tại, được xử lý trong quá trình biên dịch.
- #define: có thể thay thế bất kỳ đoạn mã nào như giá trị và câu lệnh., được xử lý trong quá trình tiền xử lý.
- Thay thế giá trị : `#define PI 3.14`
- Ví Dụ Thay Thế Câu Lệnh:`#define PRINT_HELLO printf("Hello, World!\n");`
- define có thể thay thế kiểu dữ liệu có sẵn không? 
	+ Có , Ví dụ: #define INT long
- Cú pháp :`define tên macro Văn bản sẽ thay thế` 
```C
#define PI 3.14
		int main() {
			float area, radius = 5.0;
			area = PI * radius * radius;
			return 0;
		}
```


**Con trỏ là gì, chức năng của con trỏ**
- Con trỏ: Là biến lưu trữ địa chỉ bộ nhớ của biến khác. Chức năng chính của con trỏ bao gồm:
- Truy cập và sửa đổi giá trị của biến khác thông qua địa chỉ.
- Quản lý bộ nhớ động.
**Hàm sleep hoạt động như thế nào?**
- Hàm sleep: Tạm dừng thực thi chương trình trong khoảng thời gian xác định (theo giây). Hàm này thường được sử dụng để tạo độ trễ.
- Ví dụ:sleep(5);


**Sự khác biệt khi cấp phát static memory và dynamic memory**
- Static memory allocation: Bộ nhớ được cấp phát tại thời điểm biên dịch. Kích thước bộ nhớ cố định và không thể thay đổi tại thời điểm chạy.
- Ưu điểm: Quản lý bộ nhớ đơn giản, không có nguy cơ memory leak.
- Nhược điểm: Lãng phí bộ nhớ nếu không sử dụng hết.
- Dynamic memory allocation: Bộ nhớ được cấp phát tại thời điểm chạy bằng các hàm như malloc(), calloc(), realloc().
- Ưu điểm: Linh hoạt, có thể cấp phát bộ nhớ theo nhu cầu.
- Nhược điểm: Quản lý phức tạp, có nguy cơ memory leak nếu không giải phóng bộ nhớ.

**array**
- Trong C++, mảng (array) là một cấu trúc dữ liệu cố định, có kích thước xác định tại thời điểm biên dịch và không thể thay đổi kích thước khi đã được khai báo. 
- Điều này khác với các cấu trúc dữ liệu động như std::vector, std::list, std::map, và std::set.


**list trong C++ khác với danh sách liên kết (linked list) trong C**
1. Triển khai sẵn: 
	- list trong C++ là một container có sẵn trong thư viện chuẩn STL, cung cấp các thao tác tiện lợi như chèn, xóa, và duyệt qua các phần tử
2. Quản lý bộ nhớ: 
	- Trong C, khi sử dụng danh sách liên kết, bạn phải tự quản lý bộ nhớ bằng cách cấp phát và giải phóng thủ công. C++ list tự động quản lý bộ nhớ. 
3. Tính năng: 
	- list trong C++ có nhiều tính năng và phương thức hỗ trợ hơn, như push_back, push_front, pop_back, pop_front, v.v.


**i++ và ++i**

- i++ : Hậu tố, dùng i trước rồi tăng i sau
- ++i : Tiền tố, tăng i trước rồi mới dùng i sau

ví dụ:
```c
int i=1;
int x=0;

x=i++;//x=1;i=2;
x=++i;//x=2;i=2;

```



**Header trong ngôn ngữ C là gì?**
- header  là 1 file .h chứa các khai báo hàm, khai báo biến, các define macros, và các khai báo khác mà chương trình có thể sử dụng. Header files thường được sử dụng để chia sẻ thông tin giữa các file mã nguồn và thư viện.

**destructor có thể bị overloaded?**
-  không thể overload (nạp chồng)
-  Lý do trong 1 class chỉ có 1 destructor

**operator overloading là gì ?**
- Nạp chồng toán tử , có nghĩa là ta có thể định nghĩa lại cách hoạt động của các toán tử 
**IDE**
-  IDE là viết tắt của "Integrated Development Environment"(Môi trường Phát triển Tích hợp): keil C , vs2022(nặng)
	+ Editor 
	+ Compiler(trình biên dịch)
	+ Debugger 
- Text editer :dùng để soạn thảo văn bản: vscode(nhẹ)
- MinGW :là 1 trình biên dịch c/c++ chạy trên window
- objcopy  :công cụ trong GNU
- GNU:  dự án phần mềm bao gồm công cụ, thư viện và hệ điều hành
- GCC (GNU Compiler Collection): Công cụ biên dịch

**Function overloading và operator overloading?**
- Function overloading là tính năng của ngôn ngữ C++ (không có trong C). Kỹ thuật này cho phép sử dụng cùng một tên gọi cho nhiều hàm (có cùng mục đích). Nhưng khác nhau về kiểu dữ liệu tham số hoặc số lượng tham số.Chú ý , phải cùng kiểu dữ liệu trả về , tham số không phải là 1 con trỏ
- operator overloading:operator overloading là 1 tính năng trong c++ , cho phép thực hiện các toán tử với các đối tượng dược tao ra từ class . dùng từ khóa `operator+ toán tử`

```c++
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Operator overloading for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Display the complex number
    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 7);
    Complex sum = c1 + c2; // Using operator overloading for addition
    sum.display(); // Output: 4 + 9i
    return 0;
}
```


**Friend classes và Friend funtion** 
- Friend classes :
	+ được truy cập vào các thành viên pri và protected của một lớp khác. 
	+ Điều này được thực hiện bằng cách khai báo lớp đó là friend trong phạm vi của lớp khác.

	```c++

	public:
		MyClass(int d) : data(d) {}

		friend class FriendClass; // Khai báo lớp bạn

		// Các thành viên khác của lớp
	};

	class FriendClass {
	public:
		void accessData(const MyClass& obj) {
			std::cout << "Data: " << obj.data << std::endl; // Truy cập thành viên private của MyClass
		}
	};


	```
	
- friend function:
	+ hàm bên ngoài lớp nhưng được cấp quyền truy cập các thành viên riêng tư và bảo vệ của lớp đó.
	+ thực hiện bằng cách khai báo hàm đó là friend trong lớp đó

	```C++

		class MyClass {
		private:
			int data;

		public:
			MyClass(int d) : data(d) {}

			friend void displayData(const MyClass& obj); // Khai báo hàm bạn

			// Các thành viên khác của lớp
		};

		void displayData(const MyClass& obj) {
			std::cout << "Data: " << obj.data << std::endl;
		}

		int main() {
			MyClass obj(10);
			displayData(obj); // Gọi hàm bạn để hiển thị dữ liệu private của obj
			return 0;
		}
	
	```

**So sánh struct với union trong c** 
- giống về mục đích là kiểu dữ liệu chứa các dữ liệu khác nhau trong 1 đối tượng
- Khác là về 
	+ kích thước của một union bằng với kích thước của thành viên lớn nhất trong union, trong khi kích thước của một struct là tổng của kích thước của các thành viên của nó.
	+ Mỗi thành viên trong struct có vùng nhớ riêng, trong khi tất cả các thành viên trong union chia sẻ cùng một vùng nhớ
	+ 
**So sánh struct với class**
- Mặc định truy cập: Trong một struct, mặc định truy cập  public, một class mặc định truy cập là private.
- Mục đích sử dụng: Thường thì struct được sử dụng để đại diện cho một cấu trúc dữ liệu đơn giản trong khi class  được sử dụng để tạo 1 đối tượng 


**Làm sao biết được dữ liệu gửi đi trong SPI,I2C là đúng**

- Thêm 1 byte check sum vào data
- Thuật toán như CRC (Cyclic Redundancy Check) hoặc checksum đơn giản như tổng các byte.



**LSB,MSB là gì**
- Least significant bit LSB.  bit từ phải sang trái
- Most Significant Bit MSB . bit từ trái sang phải




**Macro,Function**
- Marco làm 1 tên do người code đặt trỏ tới 1 khối lệnh thực hiện một chức năng nào đó.Được xử lý bởi preprocessor(tiền xử lý)
- Function là 1 khối lệnh thực hiện một chức năng nào đó
- Macro không cần quan tâm kiểu dữ liệu của tham số đầu vào
- Function phải chỉ rõ kiểu dữ liệu của tham số đầu vào
-  Khi vào chương trình Macro đơn giản là copy -paste vào chương trình ,Điều này làm tăng kich thước nhưng time xử lý ngắn hơn
- khi khởi tạo hàm ,RAM chỉ tốn 1 bộ nhớ cố định để lưu>>gọi 20 lần, cũng sẽ chỉ tốn 1 bộ nhớ như vậy.nhưng sẽ mất time nhiều hơn vì dịch từ vùng nhớ lưu hàm sang vùng nhớ goi hàm.
**Funtion call là gì?**
- Có 2 khái niệm cần chú ý:
	+ Stack Pointer(SP): là 1 con trỏ
	+ Program Counter (PC) là 1 thanh ghi trong CPU, lưu trữ địa chỉ của lệnh hiện tại đang được thực thi trong chương trình.
- Khi tạo 1 hàm thì Ram sẽ cấp 1 vùng địa chỉ cố định cho hàm(ví du:0x01>>0x05)
- Khi chạy 1 chương trình trong hàm main().Mà gặp phải lệnh gọi  hàm thì hệ thống sẽ lưu địa chỉ của lệnh gọi hàm`(0x00)` vào Program Counter rồi Stack Pointer sẽ trỏ tới địa chỉ đầu tiên`(0xC1)` của hàm khi khởi tạo, sau khi chạy hết vùng địa chỉ của hàm thì Stack Pointer sẽ lấy địa chỉ lệnh gọi hàm đã lưu vào Program Counter`(0x00)` và chạy tiếp hàm main >> Qúa trình này sẽ được thực hiện lại nếu gặp tiếp hàm 
>> Nếu gọi nhiều hàm thì nó sẽ chậm hơn Macro vì tốn thời gian lưu địa chỉ vào PC, rồi trỏ con trỏ SP 


**Inline Funtion là gì?**
- 1 hàm có từ khóa inline 
- Khi khởi tạo hàm ,hàm sẽ được cấp 1 vùng nhớ `0XC1>>0XC5`
- Tác dụng của nó sẽ bỏ quá quá trình gọi hàm thông thường nghĩa là bỏ qua bước lưu địa chỉ vào Program Counter và dùng stack pointer trỏ tới địa chỉ khởi tạo của hàm .Lúc này địa chỉ của hàm trùng với địa chỉ lệnh 	gọi hàm trong main `0X00`
- Hơn nữa nếu dùng Inline Funtion thì compiler sẽ buid hàm đó ra mã máy và dán vào vị trí gọi hàm trong main >> kích thước sẽ to ra
- Nên tốc độ nó sẽ nhanh hơn funtion  , nhưng dùng nhiều thì làm cho bộ nhớ 
>> Inline Funtion  và macro giống nhau ở tính năng , khác nhau về bản chất

**Lỗi tràn vùng nhớ HEAP**
- Khi cấp dữ liệu cho 1 biến vượt qua kích thước của vùng HEAP

**Khi nào truyền  con trỏ , truyền biến**
- Khi muốn thay đổi giá trị tại 1 địa chỉ thì truyền  con trỏ 
- Khi đọc giá trị tại địa chỉ đó thì truyền biến

**khi nào dùng struct , khi nào dùng union**
- Dùng struct khi bạn cần lưu trữ và truy cập nhiều loại dữ liệu khác nhau trong một đối tượng

```c
struct Person {
    char name[50];
    int age;
    char address[100];
};
```
- Dùng Union muốn tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho nhiều trường dữ liệu và chỉ muốn sử dụng một kiểu dữ liệu tại một thời điểm.

**Giao thức truyền thông nối tiếp đồng bộ, bất đồng bộ**
- Trong giao thức đồng bộ, dữ liệu được truyền đi và nhận với sự đồng bộ hoàn toàn với một tín hiệu clock chung. Cả bộ gửi và bộ nhận phải được đồng bộ hóa theo tín hiệu clock này.
- Trong giao thức bất đồng bộ, không có tín hiệu clock chung để đồng bộ hóa dữ liệu

**Kích thước Enum**
- Bằng kích thước của int , kích thước int sẽ phụ thuộc vào kiến trúc hệ thống(32 bit -4 byte , 64 bit -8 byte)

**So sánh các chuẩn giao tiếp**
1. Tốc độ truyền dẫn:
	- SPI: Thường có tốc độ truyền dẫn nhanh nhất trong ba giao thức này. Tốc độ có thể lên đến hàng chục MHz.Lý do truyền nhanh hơn vì nó có chân truyền và nhận riêng biệt , trong khi I2C chỉ có 1 đường là SDA
	- UART: Thường có tốc độ truyền dẫn thấp hơn so với I2C và SPI, thường dưới 1 Mbps.
	- I2C: Tốc độ truyền dẫn thường nhanh hơn UART nhưng chậm hơn SPI, thường dưới 1 Mbps.
	- CAN: Thường có tốc độ truyền dẫn cao, với các biến thể như CAN FD (Flexible Data-rate) có thể đạt tới hàng trăm Mbps.
2. Số lượng thiết bị kết nối:
	- SPI: Thường hỗ trợ kết nối với nhiều thiết bị hơn so với I2C và UART, do SPI sử dụng các dây riêng biệt cho mỗi thiết bị.
	- UART: Thường chỉ hỗ trợ kết nối một đến một giữa các thiết bị.
	- I2C: Cũng hỗ trợ kết nối nhiều thiết bị, nhưng địa chỉ của mỗi thiết bị phải là duy nhất trên bus.
	- CAN: Hỗ trợ kết nối một số lượng lớn các thiết bị trên một mạng CAN, có thể lên đến hàng trăm hoặc thậm chí hàng nghìn thiết bị.
3. Số dây truyền dẫn:
	- SPI: Yêu cầu ít nhất bốn dây truyền dẫn: MOSI, MISO, SCK, và SS.
	- UART: Yêu cầu hai dây truyền dẫn: một dây RX và một dây TX.
	- I2C: Chỉ yêu cầu hai dây truyền dẫn: SDA và SCL.
	- CAN: Sử dụng hai dây truyền dẫn: CANH và CANL.
4. Khả năng điều khiển:
	- SPI: 1 Master nhiều slayer
	- I2C: Hỗ trợ nhiều master và nhiều slave
5. Tiết kiệm nguồn điện:
	- I2C và UART,CAN: Có thể tiết kiệm nguồn điện hơn so với SPI vì chúng chỉ yêu cầu hai dây truyền dẫn.
	- SPI: Tiêu tốn nhiều nguồn điện hơn do sử dụng nhiều dây truyền dẫn.

**i++ khác ++i**
- Cả 2 dùng để tăng giá trị của i lên 1 đơn vị. Tuy nhiên, chúng có 1 điểm khác nhau cơ bản:
	+ i++: tăng giá trị i sau khi thực hiện các phép toán 
		```c
		 int i = 5;
		 int result = i++; //result = 5,i=6
		 ```
	+ ++i: i sẽ được tăng lên một đơn vị trước khi thực hiện các phép toán
		```c
		 int i = 5;
		 int result = ++i; //result = 6,i=6
		 ```
		 
**khi cấu hình Timer cần những thông số gì**
1. Chế độ hoạt động (Mode):
	- Chế độ đếm (Count Mode): 
	- Chế độ PWM (Pulse Width Modulation): 
	- Chế độ ngắt(interrupt mode)
2. Tần số hoạt động (Clock Frequency):xung clock
3. Chu kỳ và thời gian đếm (Period and Counting Time):xác định cần tạo chu kỳ bao nhiêu 
4. Bộ chia tần số (Prescaler):
	- Bộ chia tần số được sử dụng để chia tần số của Clock đầu vào để đạt được tần số hoạt động mong muốn cho Timer.



**Thông số khi cấu hình ADC**

1. Chế độ hoạt động (Operating Mode):
	- single conversion mode (chế độ chuyển đổi đơn): ADC thực hiện một lần chuyển đổi khi được kích hoạt.
	- continuous conversion mode (chế độ chuyển đổi liên tục) :ADC liên tục thực hiện các chuyển đổi mà không cần phải kích hoạt lại sau mỗi lần chuyển đổi.
	- scan mode (chế độ quét nhiều kênh).
2. Độ phân giải (Resolution):8-bit đến 12-bit.
3. Nguồn tham chiếu (Reference Voltage):
	- Thường là nguồn điện hoặc nguồn tham chiếu nội bộ trên vi điều khiển.
4. Chu kỳ chuyển đổi (Conversion Time):
	- Xác định thời gian mà ADC sẽ thực hiện mỗi lần chuyển đổi. Thời gian này phụ thuộc vào độ phân giải của ADC và tần số Clock.
5. Kênh đầu vào (Input Channel):
	- Chọn kênh đầu vào mà ADC sẽ chuyển đổi. STM32F4 thường có nhiều kênh ADC khác nhau cho phép đo lường nhiều tín hiệu khác nhau.
6. Ngắt (Interrupt):
	- Cấu hình xem ADC có cần phát sinh ngắt sau mỗi lần chuyển đổi hay không. Nếu cần, bạn cần cấu hình và xử lý hàm ngắt tương ứng để xử lý kết quả chuyển đổi.
7. Bộ chia tỉ số (Prescaler):
	- Xác định bộ chia tần số được sử dụng để chia tần số Clock đầu vào của ADC, từ đó xác định tốc độ chuyển đổi của ADC.

**Thông số khi cấu hình DMA**

1. Chọn Kênh DMA (DMA Channel):
	- STM32F4 hỗ trợ nhiều kênh DMA khác nhau, mỗi kênh có thể được sử dụng cho một mục đích cụ thể.
2. Chế Độ Hoạt Động (Operation Mode):
	- single transfer mode (chế độ truyền chuyển đổi đơn), 
	- circular mode (chế độ vòng tròn), 
	- memory-to-memory mode (chế độ truyền dữ liệu từ bộ nhớ này sang bộ nhớ khác)
3. Nguồn Dữ Liệu (Source Address):
	- Xác định địa chỉ bắt đầu của dữ liệu cần truyền đi (nguồn dữ liệu).
4. Đích Dữ Liệu (Destination Address):
	- Xác định địa chỉ bắt đầu của bộ nhớ đích, nơi dữ liệu sẽ được truyền đến.
5. Số Lượng Dữ Liệu (Data Length):
	- Xác định số lượng dữ liệu cần truyền đi, hoặc số lượng dữ liệu cần nhận về.
6. Xử Lý Ngắt (Interrupt Handling):
	- Cấu hình xem DMA có cần phát sinh ngắt sau mỗi lần chuyển đổi hoàn tất hay không. 
7. Chọn Định Dạng Dữ Liệu (Data Width):
	- Xác định chiều rộng của dữ liệu (8-bit, 16-bit, 32-bit) được truyền hoặc nhận trong mỗi lần chuyển đổi.
8. Cài Đặt Ưu Tiên (Priority Setting):
	- Nếu có nhiều hoạt động DMA cùng xảy ra, bạn có thể cấu hình độ ưu tiên giữa chúng.

**Thông số khi cấu hình SPI**

1. Chế Độ Hoạt Động (Mode):
	- Xác định chế độ hoạt động của SPI: Master hoặc Slave.
2. Tốc Độ Truyền Dữ Liệu (Baud Rate):
	- Xác định tốc độ truyền dữ liệu của SPI, thường được đo bằng kHz hoặc MHz.
	- Tốc độ truyền dữ liệu của SPI sẽ bằng xung clock chia giá trị(2,4,8, 16, 32, 64, 128)
3. Mod truyền :
	- SPI_CPOL và SPI_CPHA
4. Bit Data Trong Khung (Frame Format):
	- 8 hoặc 16 bit
5. Bit Order:
	- MSB hoặc LSB
6. Chế Độ Làm Việc (Operating Mode):
	- Full-duplex, Half-duplex, hay Simplex.
	- full-duplex cho phép truyền và nhận dữ liệu đồng thời, half-duplex cho phép truyền và nhận dữ liệu lần lượt, và simplex chỉ cho phép truyền dữ liệu một chiều

**Thông số khi cấu hình I2C**
1. Tốc độ I2C (I2C Clock Speed): như 100 kHz, 400 kHz 
2. Chế độ I2C (I2C Mode):
	- Xác định chế độ hoạt động của I2C: Master hoặc Slave.
3. Địa chỉ Slave (Slave Address)
4. (Data Length): kích thước này có thể là 8 bit 
 
**Thông số khi cấu hình UART**
1. baud Rate (Tốc độ truyền dữ liệu):
	- Xác định tốc độ truyền dữ liệu trên UART. Tốc độ này được đo bằng bit/s (bps).
2. Data Bits (Số bit dữ liệu):
	- 5>9 bit
3. Parity (Kiểm tra chẵn/lẻ)
4. Stop Bits (Số bit dừng):
5. Mode (Chế độ hoạt động):
 - Xác định chế độ hoạt động của UART: Full-duplex hoặc Half-duplex.
 






**I2S (Inter-IC Sound):**
- Là một giao thức truyền dữ liệu âm thanh kỹ thuật số được sử dụng để kết nối các thiết bị âm thanh

**Thanh Ghi (Registers) ,Cờ (Flags):**
- Thanh ghi là nơi lưu trữ dữ liệu cụ thể trong vi điều khiển
- Cờ (Flags):Cờ là các biến boolean (đúng/sai) . Các cờ thường được sử dụng để kiểm tra trạng sự kiện đã xảy ra hay chưa.

**USART và UART**
- USART mô tả giao thức truyền dữ liệu đồng bộ và không đồng bộ xung clock.
- UART mô tả giao thức truyền dữ liệu không đồng bộ.

**IDE là gì?**
- là môi trường  dùng để viết code ,tích hợp các tool như trình biên dịch (Compiler), trình thông dịch (Interpreter), kiểm tra lỗi (Debugger)..
- Visual Studio Code là trình soạn thảo mã nguồn .Nhờ khả năng mở rộng debug

**GCC là gì?**
- GCC là viết tắt của "GNU Compiler Collection," là bộ trình biên dịch mã nguồn mở được phát triển bởi Dự án GNU. GCC hỗ trợ nhiều ngôn ngữ lập trình như C, C++, Fortran, Ada, và nhiều ngôn ngữ khác.

**Sự khác biệt giữa vi điều khiển và vi xử lý**

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/d31fc2aa-30b4-43bc-86f4-8e9bad64a870)

 
**Giải thích các phần tử của vi điều khiển.**
- Một bộ vi điều khiển thường bao gồm CPU (Bộ xử lý trung tâm), RAM (Bộ nhớ truy cập ngẫu nhiên), ROM (Bộ nhớ chỉ đọc), bộ hẹn giờ và các thiết bị ngoại vi như GPIO, UART, SPI, I2C, ADC, DAC, PWM, timers/counters...

**Data padding...**
 - CPU hiện đại thao tác data vùng nhớ là số chẵn, không thể thao tác là số lẻ được. 
- Data alignment: Compiler sắp xếp data sao cho vùng nhớ các biến luôn là số chẵn và phù hợp với hệ thống: 
- Data padding: Để alignment Compiler sẽ thêm “padding” (đệm) một số byte vào sau biến ,để vùng nhớ là số chẵn

**Tại sao không nên sử dụng đệ quy trong các hệ thống nhúng?**
- Đệ quy là  một hàm gọi chính nó.

```C
public int sum(int n) {
if (n >= 1) {
      return sum(n - 1) + n;
}
return n;
}


```
- Sử dụng đệ quy có thể dẫn đến tràn bộ nhớ stack (stack overflow) trong các hệ thống nhúng. Điều này có thể làm cho chương trình bị dừng đột ngột .
- Đảm bảo có điều kiện dừng hợp lý, là quan trọng khi sử dụng đệ quy trong lập trình


</details>

	
<details>
  <summary><h3>Các giao thức (Protocols)</h3></summary>


<details>
  <summary><h4>SPI protocol</h4></summary>


1. SPI hỗ trợ tối đa bao nhiêu thiết bị trên cùng một bus? Có hạn chế nào không?
- Số lượng slave phụ thuộc vào số chân CS/SS trên master. Nếu không đủ, 
- có thể sử dụng multiplexer ( IC Multiplexer 74HC138)hoặc decoder để mở rộng.
- chip chuyển đổi giao thức (SPI-to-I2C).
Hạn chế:
- Càng nhiều slave, dây nối càng phức tạp.
- Dễ bị nhiễu khi số lượng thiết bị lớn.
2.  Nếu một thiết bị SPI yêu cầu tốc độ cao nhưng vi điều khiển không hỗ trợ, bạn sẽ xử lý như thế nào?
- Giảm lượng dữ liệu truyền để tiết kiệm băng thông.
- Sử dụng DMA (Direct Memory Access) để tăng tốc độ truyền dữ liệu.
3. Bạn sẽ làm gì nếu dữ liệu SPI bị nhiễu hoặc mất đồng bộ?
- Kiểm tra và điều chỉnh điện trở pull-up/pull-down.
- Giảm tốc độ giao tiếp SPI.
- Sử dụng cáp ngắn và thêm tụ lọc để giảm nhiễu.
4. Bạn đã từng gặp lỗi nào khi giao tiếp qua SPI chưa? Làm thế nào để xử lý?
- Slave không phản hồi: Kiểm tra mức logic của CS.
- Xung clock không đều: Kiểm tra nguồn clock và mạch điện.
5. Làm thế nào để tăng tốc độ giao tiếp SPI mà không gây nhiễu tín hiệu?
- Dùng cáp ngắn để giảm nhiễu.
- Thêm bộ đệm tín hiệu.
- Sử dụng PCB có thiết kế tốt với đường truyền tín hiệu đồng nhất.
6. Nếu dữ liệu SPI gửi đi không khớp với dữ liệu nhận lại, bạn sẽ debug như thế nào?
- Sử dụng oscilloscope để kiểm tra tín hiệu MOSI và MISO.




- Tốc độ của SPI phụ thuộc xung cloc, thông thường từ vài M tới vài chục M bps(bit/s)
- Các bit dữ liệu được truyền nối tiếp nhau và có xung clock đồng bộ.
- Giao tiếp song công, có thể truyền và nhận cùng một thời điểm.
- Có chế độ 1 dây: truyền hoặc nhận
- Khoảng cách truyền ngắn
- Giao tiếp 1 Master với nhiều Slave.
- Tốc độ truyền khoảng vài MHz hoặc vài chục MHz.
- ![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/1287cafd-d263-4991-9fca-1d90ae15081e)


- Các bước triển khai:
	- Bước 1: Bật Clock cho SPI
		- Bật clock cho SPI bằng cách cấu hình thanh ghi RCC.
	- Bước 2: Cấu hình SPI
		- Chọn chế độ Master/Slave.
		- Thiết lập tốc độ truyền (Baud Rate) bằng Prescaler.	
		- Cấu hình các thông số:
			- Polarity (CPOL): Mức xung nhịp khi idle (Low/High).
			- Phase (CPHA): Xung nhịp bắt đầu ở cạnh lên/xuống.
			- Frame Size: 8-bit hoặc 16-bit.
	- Bước 3: Cấu hình chân GPIO
		- Thiết lập các chân liên quan:
		- MOSI (Master Out Slave In): Gửi dữ liệu từ Master.
		- MISO (Master In Slave Out): Nhận dữ liệu từ Slave.
		- SCK (Clock): Đồng bộ hóa giữa Master và Slave.
		- NSS (Slave Select): Chọn thiết bị Slave.
	- Bước 4: Gửi và nhận dữ liệu
		- Gửi dữ liệu qua thanh ghi DR (Data Register).
		- Kiểm tra cờ TXE (Transmit Empty) và RXNE (Receive Not Empty) để đảm bảo dữ liệu đã được gửi hoặc nhận.
	- Bước 5: Xử lý phản hồi
		- Đọc dữ liệu từ DR để xử lý.













Các bước truyền dữ liệu trong SPI
Bước 1: Master kích hoạt Slave
- Master sử dụng chân SS (Slave Select) để chọn Slave cụ thể:
- Đưa chân SS của Slave xuống mức thấp (LOW) để kích hoạt.
- Khi có nhiều Slave, chỉ một Slave được kích hoạt tại một thời điểm
Bước 2: Gửi xung clock (SCLK)
- Tùy gửi hoặc nhận là 8 bit hoặc 16 bit
- Master bắt đầu tạo xung clock trên đường SCLK.
- Mỗi cạnh xung clock (lên hoặc xuống) sẽ đồng bộ dữ liệu giữa Master và Slave.
Bước 3: Truyền dữ liệu từ Master đến Slave (MOSI)
- Dữ liệu từ Master sẽ được gửi qua đường MOSI (Master Out Slave In).
- Slave đọc dữ liệu từ MOSI vào mỗi cạnh xung clock (dựa trên cấu hình CPOL và CPHA).
Bước 4: Truyền dữ liệu từ Slave đến Master (MISO)
- Đồng thời, Slave có thể gửi dữ liệu ngược lại Master qua đường MISO (Master In Slave Out).
- Master đọc dữ liệu từ MISO vào mỗi cạnh xung clock.
Bước 5: Dừng giao tiếp
- Sau khi truyền xong, Master đưa chân SS lên mức cao (HIGH) để kết thúc giao tiếp với Slave


**Vấn Đề Đồng Bộ Hóa Trong SPI**
- Kiểm tra xung clock (CPOL và CPHA) 2 con cài như nhau chưa?
- Check mode truyền của 2 con (master-slayer)
- Khung truyền 2 con đúng chưa(8-16 bit)
**Quy tình cơ bản khi lập trình SPI**
- Cấp Xung cho SPI:
- Cấu Hình Chân Dựa Trên Reference Manual (RM) của Nhà Sản Xuất
- Cấu Hình Các Chức Năng cho SPI
	+ Cài đặt chế độ Master/Slave.
	+ Thiết lập tốc độ truyền (Baud Rate).
	+ Cấu hình CPOL, CPHA cho pha và cực của xung clock.
	+ Kích hoạt giao thức SPI để bắt đầu giao tiếp.

- Có 4 chế độ truyền dữ liệu:
  	| Mode | CPOL | CPHA |
  	|:---:|:---:|:---:|
  	|0|0|0|
  	|1|0|1|
  	|2|1|0|
  	|3|1|1|
- CPOL = 0: Bắt đầu 1 chu kì là xung cạnh lên.
- CPOL = 1: Bắt đầu 1 chu kì là xung cạnh xuống.
- CPHA = 0: Bit dữ liệu đầu ra sẽ rơi vào cạnh xung đầu tiên của chu kì.
- CPHA = 1: Bit dữ liệu đầu ra sẽ rơi vào cạnh xung thứ hai của chu kì.
- CPOL = 0 , CPHA = 0 là mặc định.
### Ưu, nhược điểm của chuẩn giao tiếp SPI.
- Ưu điểm:
  - Không có hệ thống định địa chỉ slave phức tạp như I2C
  - Tốc độ truyền dữ liệu cao hơn I2C (nhanh gần gấp đôi)
  - Hỗ trợ truyền dữ liệu hai chiều đồng thời (full-duplex), giúp tăng hiệu suất giao tiếp.
- Nhược điểm:
  - Sử dụng bốn dây (I2C và UART sử dụng hai dây).
  - Chỉ cho phép một master duy nhất.
  - khoảng cách truyền ngắn



</details>

<details>
  <summary><h4>I2C protocol</h4></summary>

- I2C (Inter-Integrated Circuit) là một giao thức truyền thông nối tiếp đồng bộ. Nên các bit dữ liệu truyền đi được đồng bộ hóa với xung nhịp do Master điều khiển.
- Hỗ trợ nhiều Master và Slave trên một đường truyền
- Tốc Độ Truyền (Baud Rate): Thông thường 100 kbps, 400 kbps đối với STM32F4( bit trên giây)

1. Bạn sẽ làm gì nếu hai thiết bị I2C có cùng địa chỉ?
- Sử dụng I2C Multiplexer để tạo nhiều bus I2C.
- Dùng module chuyển đổi giao thức (I2C-to-SPI).
- Nếu thiết bị hỗ trợ, thay đổi địa chỉ qua jumper hoặc lệnh cấu hình.?
2. Bạn đã từng gặp lỗi nào khi giao tiếp qua I2C chưa? 
- Lỗi ACK: Slave không phản hồi.
	- Giải pháp: Kiểm tra kết nối, mức điện áp, và cấu hình địa chỉ.
3. Làm thế nào để tăng tốc độ giao tiếp I2C trong hệ thống nhúng mà không gây nhiễu tín hiệu?
	- Thêm điện trở pull-up phù hợp (4.7kΩ hoặc thấp hơn).?
4. Khi giao tiếp với nhiều slave qua I2C, làm thế nào để ưu tiên xử lý dữ liệu từ các thiết bị quan trọng?
- Sử dụng queue hoặc luồng ưu tiên cao để xử lý dữ liệu từ thiết bị quan trọng trước.
4. bạn thường cấu hình I2C bằng thư viện chuẩn hay viết mã thủ công? Tại sao?
- Sử dụng HAL/LL (Thư viện chuẩn) vì nhanh và ít lỗi.
- Viết mã thủ công khi cần tối ưu hóa hoặc hệ thống phức tạp.
5. làm thế nào để kiểm tra và debug giao tiếp I2C trên phần cứng?
- Logic Analyzer: Ghi và giải mã dữ liệu I2C.
- Oscilloscope: Kiểm tra tín hiệu SDA và SCL để phát hiện nhiễu.
6.  Nếu thiết bị slave không phản hồi hoặc truyền dữ liệu sai, bạn sẽ làm gì?
- Kiểm tra địa chỉ và kết nối vật lý.
- Thử reset slave hoặc khởi động lại bus I2C.
7. Bạn sẽ xử lý ra sao nếu một thiết bị slave liên tục làm treo bus I2C?
- Reset slave bằng cách gửi tín hiệu STOP hoặc reset toàn bộ bus.
- Kiểm tra tính năng clock stretching của slave.

**Các thông số cần cấu hình:**
1. Chế độ hoạt động (Master/Slave):
- Master: Điều khiển quá trình truyền dữ liệu.
- Slave: Nhận và phản hồi dữ liệu khi được yêu cầu.
2. Tốc độ truyền (I2C Speed):
- Standard Mode: Tốc độ tối đa 100 kHz.
- Fast Mode: Tốc độ tối đa 400 kHz.
-  Ngoài ra, một số vi điều khiển hỗ trợ Fast Mode Plus (1 MHz).
3. Địa chỉ thiết bị (Addressing Mode):
- 7-bit hoặc 10-bit địa chỉ cho các thiết bị Slave.
4. Acknowledge (ACK):
- Kích hoạt hoặc vô hiệu hóa ACK để xác nhận khi dữ liệu được nhận thành công.


Các bước triển khai:
- Bước 1: Bật Clock cho I2C
	- Bật clock cho I2C bằng cách cấu hình thanh ghi RCC.
- Bước 2: Cấu hình tốc độ truyền (Clock Speed)
	- Thiết lập tốc độ I2C (100 kHz hoặc 400 kHz) bằng cách cấu hình các thanh ghi:
- Bước 3: Cấu hình chân GPIO
- Bước 4: Bắt đầu giao tiếp
	- Gửi tín hiệu START để bắt đầu giao tiếp.
	- Gửi địa chỉ thiết bị Slave qua thanh ghi DR.
- Bước 5: Gửi/nhận dữ liệu
	- Gửi dữ liệu qua DR.
	- Nhận dữ liệu phản hồi từ Slave qua DR.
- Bước 6: Kết thúc giao tiếp
	- Gửi tín hiệu STOP để kết thúc giao tiếp













**Vấn đề về đồng bộ hóa trong I2C:**
- Kiểm tra Master,Slayer tốc độ truyền có đồng bộ chưa
- Khung truyền ,nhận có giống nhau chưa
- Kiểm tra giá trị trở kéo lên trên đường dữ liệu (SDA) và đường clock , quá lớn hay nhỏ đều lỗi.
- I2C chỉ sử dụng hai dây để truyền dữ liệu giữa các thiết bị:
  - SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu.
  - SCL (Serial Clock) - đường mang tín hiệu xung nhịp.
**Ứng dụng thực tế của I2C trong lĩnh vực nhúng:**
- Giao tiếp với các cảm biến.
- Kết nối với LCD hoặc các bộ nhớ lưu trữ dữ liệu.
**Khi nào nên dùng I2C**
- Yêu Cầu Dây Dẫn Ít Hơn
- Cần Kết Nối Nhiều Thiết Bị 
- Tiết Kiệm Năng Lượng : các thiết bị không hoạt động không ảnh hưởng đến bus, giúp tiết kiệm năng lượng
 

### Cách hoạt động:

![Connect with orther](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-I2C-Message-Frame-and-Bit-2.png)

- Dữ liệu được truyền trong các `Message`, mỗi `Message` có một `khung địa chỉ` nhị phân chứa địa chỉ của `Slave` và một hoặc nhiều `khung dữ liệu` chứa dữ liệu đang được truyền.
- Trong mỗi thông điệp bao gồm điều kiện `Start` và `Stop`, các bit `Read/Write` và các bit `ACK/NACK` giữa mỗi `khung dữ liệu`.

![Connect with orther](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTry4sV-ui_OqN3z3ioNBQlq25u2RSJ0i1ucA&usqp=CAU)

- ***Điều kiện khởi động (1 bit):*** Chân `SDA` chuyển từ mức cao xuống mức thấp trước khi `SDL` chuyển từ cao xuống thấp.
- ***Khung địa chỉ (7 hoặc 10 bit):*** Là một chuỗi 7 hoặc 10 bit duy nhất cho mỗi `Slave` để xác định `Slave` mà `Master` muốn liên lạc và bit `Read/Write` cũng được gửi cùng ngay sau `khung địa chỉ`. 

  	-`Master` sẽ gửi địa chỉ cho tất cả `Slave`, và những `Slave` sẽ so sánh địa chỉ đó với địa chỉ của nó.
  	- Nếu phù hợp nó sẽ gửi lại một bit `ACK` mức thấp trở lại cho `Master`, và nếu không khớp thì không làm gì cả và `SDA` giữa hai thiết bị đó vẫn ở mức cao
- ***Read/Write (1 bit):*** Sẽ cho `Slave` biết là `Master` muốn ghi dữ liệu vào nó hay nhận dữ liệu từ nó.
	- Nếu `Write`(gửi) thì `0`, còn `Read` thì `1`.
- ***Data Frame (8 bit):*** Sau khi Master phát hiện bit `ACK` gửi từ `Slave`, thì `khung dữ liệu` bắt đầu gửi.
	- Bit MSB được gửi trước.
 	- Theo sau mỗi khung dữ liệu sẽ có 1 bit `ACK/NACK` để xác nhận khung đã được nhận thành công(bit 0 chân `SDA`).
  	- Bit `ACK` phải được nhận bởi `Master` hoặc `Slave` (tùy vào thiết bị gửi dữ liệu) trước khi khung dữ liệu tiếp theo được gửi.
- ***Điều kiện dừng (1 bit):*** Sau khi tất cả khung dữ liệu đã được gửi đi, thì `Master` có thể gửi điều kiện dừng bằng cách:
	- Chuyển `SCL` từ mức thấp lên mức cao trước khi chuyển `SDA` từ thấp lên cao.

### Ưu, nhược điểm của chuẩn giao tiếp I2C

- **Ưu điểm:**
  - Chỉ sử dụng hai dây
  - Hỗ trợ nhiều `master` và nhiều `slave`
  - Bit `ACK / NACK` xác nhận rằng mỗi khung dữ liệu hay địa chỉ được gửi (hoặc nhận) thành công
  - Phần cứng ít phức tạp hơn với giao tiếp `UART`
  - Giao thức nổi tiếng và được sử dụng rộng rãi

- **Nhược điểm:**
  - Tốc độ truyền dữ liệu giao tiếp `I2C` chậm hơn so với giao tiếp `SPI`
  - Kích thước của khung dữ liệu được giới hạn ở `8 bit`
  - Cần phần cứng phức tạp hơn để triển khai so với giao tiếp `SPI`
### I2C trong STM32F407VET6.
**I2C:**
- Bước đầu, ta định nghĩa cho 2 chân sử dụng cho ic2 và cấp xung CLK:

<details>
		<summary>Software:</summary>

```C
#include "stm32f4xx.h"

#define I2C_SCL_PIN GPIO_Pin_6
#define I2C_SDA_PIN GPIO_Pin_7
#define I2C_GPIO_PORT GPIOB

void I2C_Config() {
    GPIO_InitTypeDef GPIO_InitStructure;
    I2C_InitTypeDef I2C_InitStructure;

    // Enable the I2C and GPIO clocks
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    // Configure the I2C pins
    GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN | I2C_SDA_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStructure);

    // Connect the I2C pins to AF
    GPIO_PinAFConfig(I2C_GPIO_PORT, GPIO_PinSource6, GPIO_AF_I2C1); // SCL
    GPIO_PinAFConfig(I2C_GPIO_PORT, GPIO_PinSource6, GPIO_AF_I2C1); // SDA

    // Configure the I2C peripheral
    I2C_InitStructure.I2C_ClockSpeed = 400000;
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C1, &I2C_InitStructure);

    // Enable the I2C peripheral
    I2C_Cmd(I2C1, ENABLE);
}

void I2C_Start() {
    // Send I2C start condition
    I2C_GenerateSTART(I2C1, ENABLE);

    // Wait until start condition is sent
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
}

void I2C_Stop() {
    // Send I2C stop condition
    I2C_GenerateSTOP(I2C1, ENABLE);

    // Wait until stop condition is sent
    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_STOPF));
}

void I2C_Write(uint8_t u8Data) {
    // Send a byte of data
    I2C_SendData(I2C1, u8Data);

    // Wait until the byte is transferred
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

void I2C_Write_Array(uint8_t deviceAddress, uint8_t* data, uint8_t dataSize) {
    // Start the I2C communication
    I2C_Start();

    // Send the device address with the write bit
    I2C_Write(deviceAddress << 1);

    // Send each byte of the array
    for (uint8_t i = 0; i < dataSize; i++) {
        I2C_Write(data[i]);
    }

    // Stop the I2C communication
    I2C_Stop();
}

int main() {
    // Initialize the I2C hardware
    I2C_Config();

    while (1) {
        // Perform I2C communication with the array
        uint8_t array[] = {7, 8, 4, 2};
        I2C_Write_Array(0x27, array, sizeof(array));

        // Add delay or other functionality as needed
    }
}

```
</details>

**Tóm lại:**

![I2C](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/d758fc68-1880-47ad-bd56-3b7b5a2a516f)

- SDA,SCL nối trở kéo lên >> mức cao
- Để bắt đầu truyền thì Master sẽ kéo đường SDA từ cao xuống thấp, sau đó SCL sẽ kéo từ cao xuống thấp.
- Sau đó Master sẽ gửi 7 bit địa chỉ + 1 bit(read(1) hoặc write(0)) + nhận 1 bit ACK(0) hoặc NACK(1) từ slayer .
	- Slayer nào trùng địa chỉ thì sẽ gửi 1 bit ACK cho Master.Có nghĩa là nếu SDA từ mức cao(nếu bit số 8 là 1) sẽ chuyển thành mức thấp do slayer kéo xuống.
- Đồng thời cứ mỗi bit thì SCL sẽ được kéo từ mức thấp lên cao.(tổng cộng 9 xung CK )

	- Nguyên nhân dịch trái 1 bit hoặc dịch trái 1 bít rồi or với bit 1.Mục đích để bit cuối là 0 hoặc 1
	- Ví dụ 0x27:0010 0111 ,Nếu Master muốn gửi dữ liệu cho slayer chỉ cần dịch trái bit 1 `0x27<<1`
	- Muốn nhận dữ liệu từ Slayer thì `(0x27 <<1)|0x01)` để biết cuối thành 1
- Tiếp theo là truyền hoặc nhận khung dữ liệu 8 bit trên đường SDA + 1 bit ACK/NACK
- SCL sẽ gửi 9 xung CK.
- Điều kiện để kết thúc SCL sẽ kéo từ mức 0 lên mức 1 , rồi SDA từ mức 0 lên 1


















</details>

<details>
  <summary><h4>UART protocol</h4></summary>



**Nguyên nhân lỗi chính và cách khắc phục:**
1. Không đồng bộ baud rate theo thời gian
- Nguyên nhân:
- Dao động của thạch anh (crystal oscillator) hoặc bộ dao động nội (internal oscillator) của vi điều khiển có sai số.
- Sai số nhỏ tích lũy theo thời gian, làm mất đồng bộ baud rate giữa hai thiết bị.
- Sử dụng thạch anh chất lượng cao với độ chính xác cao hơn (ví dụ: 20 ppm thay vì 50 ppm).
- Đảm bảo cả hai thiết bị sử dụng cùng nguồn clock nếu có thể.
2. Tràn buffer 
- Nó là một vùng nhớ tạm thời được dùng để lưu trữ và quản lý dữ liệu
- Phần mềm xử lý UART  không đọc dữ liệu từ buffer đủ nhanh, dẫn đến tràn dữ liệu.
- Xảy ra khi tốc độ truyền dữ liệu quá cao hoặc hệ thống bị bận xử lý công việc khác.
- Kiểm tra và tăng kích thước buffer nếu có thể.
- Sử dụng DMA (Direct Memory Access) nếu vi điều khiển hỗ trợ, giảm tải CPU trong việc xử lý UART.
3. Nhiễu tín hiệu
- Tín hiệu truyền qua dây dài hoặc môi trường có nhiễu điện từ (EMI).
- Thiết bị ngoại vi khác trong hệ thống gây xung đột hoặc nhiễu tín hiệu.
- Dùng cáp chống nhiễu (shielded cable) hoặc cáp xoắn đôi (twisted pair).
- Đảm bảo thiết kế PCB có đường tín hiệu UART tách biệt
4.  Sai cấu hình UART do phần mềm
- Cấu hình UART trong phần mềm bị thay đổi do lỗi lập trình hoặc interrupt
- Đảm bảo không có hàm nào ghi đè hoặc thay đổi cấu hình UART trong runtime.
5. Vấn đề cấp nguồn
- Nguồn không ổn định hoặc tụt áp khi hệ thống hoạt động lâu.
- Kiểm tra nguồn cấp cho vi điều khiển và các module ngoại vi.
6. xử lý lỗi khi giao tiếp UART bị mất dữ liệu hoặc nhận dữ liệu không chính xác?
- Thêm kiểm tra parity bit để phát hiện lỗi. Nếu phát hiện lỗi, tôi yêu cầu gửi lại gói tin.
7. Nếu thay thế SPI bằng UART bạn sẽ thiết kế lại hệ thống như thế nào?
- UART sẽ giới hạn tốc độ so với SPI, nên cần điều chỉnh   baudRATE
8. Với Bluetooth, tôi sử dụng UART để gửi và nhận dữ liệu giữa vi điều khiển và smartphone.
9. với các thiết bị Wi-Fi/Router, Tôi sử dụng UART để kết nối với cổng debug (console) của router. Các công cụ như terminal (TeraTerm, Putty) cho phép tôi gửi lệnh kiểm tra trạng thái hệ thống  
10. Làm gì nếu hai thiết bị UART giao tiếp nhưng có mức điện áp khác nhau (3.3V và 5V)?
- Dùng bộ chia điện áp chuyển 5v > 3.3v
11. Làm thế nào để tối ưu tốc độ truyền dữ liệu UART
- Tăng baud rate: Nhưng đảm bảo không vượt khả năng phần cứng.
- Dùng DMA (Direct Memory Access): Để giảm tải CPU
- Cần kiểm tra khả năng đồng bộ giữa master và slave, đảm bảo không bị lỗi dữ liệu ở tốc độ cao.
12.  Bạn sẽ kiểm tra và debug UART trên phần cứng như thế nào
- Sử dụng oscilloscope để kiểm tra tín hiệu vật lý.(mức điện áp, hình dạng xung).
	- Đảm bảo tín hiệu có dạng xung vuông và không bị nhiễu.
	- Phát hiện các lỗi như nhiễu tín hiệu, méo tín hiệu, hoặc sụt áp.
	- Nếu tín hiệu không đúng mức điện áp: Kiểm tra nguồn
- Logic analyzer để kiểm tra khung dữ liệu.
	- Ghi nhận dữ liệu truyền qua UART.
	- Kiểm tra xem dữ liệu có khớp với dữ liệu dự kiến không.
- Các công cụ phần mềm như Tera , Putty để gửi và nhận dữ liệu.
	- debug giao tiếp giữa PC và thiết bị phần cứng
	- Truy cập và cấu hình router hoặc switch qua giao diện CLI 
13. Cấu hình UART bằng thư viện chuẩn (HAL/LL) hay viết mã thủ công? Tại sao?
- Thường sử dụng thư viện HAL/LL để tiết kiệm thời gian phát triển và giảm lỗi.
- Trong các dự án yêu cầu hiệu suất cao, tôi viết mã thủ công để tối ưu tài nguyên.
14.  cần giao tiếp nhiều thiết bị qua UART,
-  Dùng nhiều cổng UART,vi điều khiển hỗ trợ nhiều cổng UART
- Sử dụng bộ IC  UART-to-Multiple UART 

 







- `UART` (Universal Asynchronous Receiver / Transmitter) hoàn toàn khác biệt với chuẩn giao tiếp `SPI` hoặc `I2C`, những chuẩn này chỉ đơn tuần là giao tiếp phần mềm.
- Mục đích chính của `UART` là truyền và nhận dữ liệu nối tiếp không đồng bộ vì không có chân `Clock`. Nên tốc độ truyền `Baudrate` rất quan trọng trong giao thức này.
- Thông thường, tốc độ truyền của UART được đặt ở một số chuẩn, như 9600, 19200, 38400, 57600, 115200 baud . Tốc độ truyền này định nghĩa số lượng bit được truyền qua mỗi giây
- Chuẩn giao tiếp `UART` sử dụng 2 dây để truyền và nhận dữ liệu giữa các thiết bị:
 - `TX (Transmiter)` – Dây truyền dữ liệu
 - `RX (Receiver)` – Dây nhận dữ liệu
- Giao tiếp giữa 1 `Master` và 1 `Slave`.
- Dữ liệu được truyền một frame (gồm start bit, data bits, parity bit nếu có, và stop bits) . Master truyền dữ liệu bắt đầu bằng một start bit và kết thúc bằng một hoặc nhiều stop bits. Slayer nhận dữ liệu đọc dữ liệu từng bit và xác định khung bằng cách đọc start bit và đếm số bit cho đến khi đến stop bit.
- Uart truyền dữ liệu nối tiếp, theo 1 trong 3 chế độ:
	+ Simplex: Chỉ tiến hành giao tiếp một chiều.
 	+ Half duplex: Dữ liệu sẽ đi theo một hướng tại 1 thời điểm
	+ Full duplex: Thực hiện giao tiếp đồng thời đến và đi từ mỗi master và slave

**Ứng dụng thực tế của UART trong lĩnh vực nhúng là gì?** 
- UART được sử dụng trong các ứng dụng như kết nối giữa vi điều khiển và máy tính,
### Cách truyền nhận dữ liệu:
**Cờ quan trọng trong UART:**
- UART_FLAG_RXNE
- UART_FLAG_TX
- UART_FLAG_FE :Được set khi xảy ra lỗi khung, tức là không có bit stop
- UART_FLAG_PE:Được set khi xảy ra lỗi kiểm tra chẵn/le.
![Connect with orther](https://kysungheo.com/wp-content/uploads/2023/03/3-300x129.png)
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/3b03fecd-3c23-4ec4-a498-9b1758b5bcd8)


- UART sẽ truyền và nhận dữ liệu từ một Data Bus
- Data Bus được sử dụng để gửi dữ liệu đến UART bởi một thiết bị khác như vi điều khiển.
- Dữ liệu được gửi từ Data Bus sang UART ở dạng song song.
- Sau khi UART nhận được dữ liệu từ Data Bus, nó sẽ thêm một bit Start, một bit Parity và một bit Stop.
- Tạo ra gói dữ liệu và truyền đi nối tiếp từng bit qua chân TX.
- Bên nhận sẽ chuyển đổi gói dữ liệu đó sang dạng song song và lược bỏ các bit Start, Parity, Stop và chuyển qua Data Bus.

![Connect with orther](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Packet-Frame-and-Bits-2.png)

- ***Start bit:*** Để bắt đầu truyền dữ liệu, UART truyền sẽ kéo đường truyền từ mức cao xuống mức thấp trong một chu kỳ đồng hồ. Khi UART bên nhận phát hiện sự chuyển đổi điện áp cao xuống thấp, nó bắt đầu đọc các bit trong khung dữ liệu ở tần số của tốc độ truyền (Baud rate).
- ***Data Frame:***
  - Nó có thể dài từ 5 bit đến 8 bit nếu sử dụng bit Parity (bit chẵn lẻ).
  - Nếu không sử dụng bit Parity, khung dữ liệu có thể dài 9 bit.
  - Trong hầu hết các trường hợp, dữ liệu được gửi với bit LSB (bit có trọng số thấp nhất) trước tiên.
- ***Parity Bit*** bit Parity là một cách để UART bên nhận kiểm tra dữ liệu đã thay đổi trong quá trình truyền hay không. Bit có thể bị thay đổi bởi tốc độ truyền không khớp hoặc truyền dữ liệu khoảng cách xa,… Sau khi UART bên nhận đọc khung dữ liệu, nó sẽ đếm số bit có giá trị là 1 và kiểm tra xem tổng số là số chẵn hay lẻ.
  - Nếu bit Parity là 0 (chẵn), thì tổng các bit 1 trong khung dữ liệu phải là một số chẵn.
  - Nếu bit Parity là 1 (lẻ), thì tổng các bit 1 trong khung dữ liệu sẽ là một số lẻ. Do đó qua kiểm tra sẽ biết được quá trình truyền dữ liệu có chính xác.
- ***Stop Bit:*** Để báo hiệu sự kết thúc của gói dữ liệu, UART gửi sẽ điều khiển đường truyền dữ liệu từ điện áp thấp đến điện áp cao trong ít nhất hai khoảng thời gian bit.

### Ưu, nhược điểm của chuẩn giao tiếp UART

Không có giao thức truyền thông nào là hoàn hảo, nhưng UART thực hiện khá tốt công việc của chúng. Dưới đây là một số ưu và nhược điểm của chuẩn giao tiếp UART. Mong rằng chúng có thể hỗ trợ cho dự án của bạn.
- Ưu điểm:
  - Chỉ sử dụng hai dây
  - Không cần tín hiệu đồng hồ
  - Có một bit chẵn lẻ để cho phép kiểm tra lỗi
  - Cấu trúc của gói dữ liệu có thể được thay đổi
  - Phương pháp được ghi chép rõ ràng và được sử dụng rộng rãi

- Nhược điểm:
  - Kích thước của khung dữ liệu được giới hạn tối đa là 9 bit
  - chỉ 1 Master và 1 slayer
  - Tốc độ truyền của mỗi UART phải nằm trong khoảng 10% của nhau
**CODE**
 <details>
<summary>STM32F4_MASTER</summary>

- Cấp xung,Cấu hình chân,cấu hình UART.
- Dựa vào hình thì UART từ ABP2
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/c706fb8d-3be9-4b93-82c2-b660d3334790)

- GPIOA ở AHB1
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/44b33b80-296a-4a72-ad31-b1b43a8f207c)

```C
void RCC_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);// PA9 USART1_TX,PA10_USART1_RX
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
}
```
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/306534cd-4f82-41e4-9045-5b0d3a7d2e1f)
- Cấu hình chân:PA9 USART1_TX,PA10_USART1_RX

```C
	void GPIO_Config(){
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10 ;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz ;
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
		GPIO_Init(GPIOA,&GPIO_InitStruct);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
	}
```
- Cấu hình UART:

```C
void URART1_Config(){
	USART_InitTypeDef UART_INITSTRUCT;
	UART_INITSTRUCT.USART_BaudRate =9600;
	UART_INITSTRUCT.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	UART_INITSTRUCT.USART_Mode = USART_Mode_Tx |USART_Mode_Rx;
	UART_INITSTRUCT.USART_Parity =USART_Parity_No ;
	UART_INITSTRUCT.USART_StopBits =USART_StopBits_1 ;
	UART_INITSTRUCT.USART_WordLength = USART_WordLength_8b ;
	USART_Init(USART1,&UART_INITSTRUCT);
	USART_Cmd(USART1,ENABLE);
}
```
- USART_Mode: Cấu hình chế độ hoạt động cho UART:
- USART_Mode_Rx: Cấu hình truyền.
- USART_Mode_Tx: Cấu hình nhận.Có thể cấu hình cả 2 cùng lúc.
- USART_BaudRate: Cấu hình tốc độ baudrate cho uart.
- USART_HardwareFlowControl: Cấu hình chế độ bắt tay cho uart.
- USART_WordLength: Cấu hình số bit mỗi lần truyền.
- USART_StopBits: Cấu hình số lượng stopbits.
- USART_Parity: cấu hình bit kiểm tra chẳn, lẻ.

**Hàm main**
```C
uint8_t arr[4]={5,2,3,4};
int main(){
	RCC_Config();
	GPIO_Config();
	URART1_Config();
	while(1){
		for(uint8_t i=0;i<4;i++){
			USART1->DR =0;
			USART_SendData(USART1,arr[i]);
			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==0); // TXE=TE
			for(uint32_t j=0;j<10000;j++);
		}	
	}	
}
```
- UART xóa hết data trong thanh ghi DR để đảm bảo data đúng.`USART1->DR =0;`
- Hàm `USART_SendData(USART_TypeDef* USARTx, uint16_t Data)`, truyền data từ UARTx
- `USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG)`
- USART_FLAG_TXE: Cờ truyền, set lên 1 nếu quá trình truyền hoàn tất.
- USART_FLAG_RXNE: Cờ nhận, set lên 1 nếu quá trình nhận hoàn tất.
- USART_FLAG_IDLE: Cờ báo đường truyền đang ở chế độ Idle.
- USART_FLAG_PE: Cờ báo lỗi Parity

- Trong tài liệu tiếng anh:
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/306534cd-4f82-41e4-9045-5b0d3a7d2e1f)

</details>

 <details>
<summary>STM32F1_USART_SLAYER</summary>
- Cấp xung,Cấu hình chân,cấu hình UART.
- Dựa vào hình thì UART,GPIOA từ ABP2

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/0e4cbdf9-1f27-4925-9f46-b6f3e79a82ce)

```C
void RCC_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);// PA9 USART1_TX,PA10_USART1_RX
}
```
- Cấu hình GPIO:
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/d63639b0-5144-4389-9eaa-1e9425af93a2)


```C
void GPIO_Config(){
GPIO_InitTypeDef GPIOInitStruct;
	GPIOInitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;// MODE NHẬN DL nếu là Slayer
	//GPIO_INIT.GPIO_Mode =  GPIO_Mode_AF_PP;// nếu là Master
	GPIO_Init(GPIOA, &GPIOInitStruct);
	GPIOInitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIOInitStruct);
}

```
- Cấu hình UART:Các hàm tương tự như F4

```C
void URART1_Config(){
	USART_InitTypeDef UART_INITSTRUCT;
	UART_INITSTRUCT.USART_BaudRate =9600;
	UART_INITSTRUCT.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	UART_INITSTRUCT.USART_Mode = USART_Mode_Tx |USART_Mode_Rx;
	UART_INITSTRUCT.USART_Parity =USART_Parity_No ;
	UART_INITSTRUCT.USART_StopBits =USART_StopBits_1 ;
	UART_INITSTRUCT.USART_WordLength = USART_WordLength_8b ;
	USART_Init(USART1,&UART_INITSTRUCT);
	USART_Cmd(USART1,ENABLE);
}
```
**Hàm main**
- Các cở như F4
```C
uint8_t arr[4];
uint8_t i=0;
int main(){
	RCC_Config();
	GPIO_Config();
	URART1_Config();
	while(1){
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==0);
		arr[i]=USART_ReceiveData(USART1); 
		i++;
		if(i==4){
			i =0;
		}
	}	
}
```




























</details>
</details>

<details>
  <summary><h4>CAN protocol</h4></summary>
	
### CAN là gì?
- Controller Area Network (CAN Bus) là giao thức truyền thông nối tiếp, tốc độ cao. Gồm có hai dây (CAN-High và CAN-Low).
- CAN có 4 chế độ:
	- Data Frame (khung dữ liệu): Gửi dữ liệu đến 1 node
	- Remote Frame (khung yêu cầu hay điều khiển): Gửi yêu cầu tới 1 node và yêu cầu nó gửi dữ liệu lại
	- Error Frame (khung lỗi):  node A phát hiện lỗi CRC .Nó sẽ không gửi Data Frame mà sẽ gửi 1 Error Frame tới các node khác để thông báo lỗi , các node khác khi nhận dc farm này sẽ có biện pháp xử lý hoặc thông báo lỗi
	- Overflow Frame (khung báo tràn):  một nút trong mạng gặp phải tình trạng quá tải ,nguyên nhân có thể có 2 node cùng giành truyền tạo ra quá tải thì 1 node đó sẽ gửi Overflow Frame tới các node khác , các node nhận Overflow Frame sẽ điều chỉnh tốc độ truyền dữ liệu
- Trong mạng CAN, các thiết bị được kết nối trên cùng 1 đường gồm 2 dây CAN_H và CAN_L, gọi là bus. Mỗi thiết bị trong mạng được gọi là 1 Node, gồm:
	+ MCU: Chịu trách nhiệm truyền nhận xử lý data.
	+ CAN Controller: Gồm CANTX,CANRX
	+ CAN Transceiver: tạo điện áp cho Bus.
- Trong 1 thời điểm chỉ có 1 node truyền và các node khác phải nhận

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/353762a0-c9c3-491f-a987-0d27529c9854)

**Cụ thể**
![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/2c05c965-fa51-4f6d-a562-f03bb99e1274)

- Nếu MCU gửi bit `1` thì:
	
![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/858ebce9-e4f6-4f8f-8210-f4244f7a02ae)

- Nếu MCU gửi bit `0` thì:
![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/f061914a-8176-4c5a-aa41-129e7bda8413)

- Nếu MCU nhận bit `1` hoặc `0` thì:
	+ Nhận 1 điện áp là Can H - CanL

- Can H - Can L phải bắt xoắn dây để tránh nhiễu

**ID càng thấp thì có độ ưu tiên càng cao**
- Trong trường hợp nhiều node, thì node có ID thấp thì node đó được ưu tiên truyền trước.ID có thể được code 
- Ví dụ có 3 node:
	+ Node A: 0100101 (7 bits)
	+ Node B: 0010010 (7 bits)
	+ Node C: 0010100 (7 bits)
- Thì node B được ưu tiên truyền trước vì ID nó nhỏ nhất

**ID càng thấp thì có độ ưu tiên càng cao**

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/8a608ca9-f445-4320-8b07-58fc763c46ab)

**Data Frame của CAN (Phiên bản 2.0A) gồm các bit:**
1. Trường bắt đầu khung  Start Of Frame Field – SOF là bit `0`
2. Trường xác định quyền ưu tiên (Arbitration Field) gồm 11 bit ID và bit RTR(Remote Transmission Request)
	+ Nếu là Data Frame, bit này luôn bằng 0 (Dominant Bit).
	+ Nếu là Remote Frame, bit này luôn bằng 1 (Recessive Bit).
	- Cụ thể là RTR bằng `0` thì MCUA sẽ gửi dữ liệu cho MCUB 
	- Nếu RTR bằng `1` thì MCUA sẽ yêu cầu MCUB gửi dữ liệu
3. Trường điều khiển (Control Field)  bit r1,r0 là 2 bit đệm và bằng `0` và Bit DLC(Data Length Code) 
	+ DLC= `0` nếu RTR =`1`( RTR =1 là remote frame)
	+ DLC =(0001>1000) 
4. Trường dữ liệu (Data Field) Data field(0-8 byte) muốn truyền đi , muốn truyền 8 byte thì DLC =1000
5. Trường kiểm tra  CRC gồm 15 bit checksum: xem thử DATA có toàn vẹn không  
6. Trường báo nhận (ACK) 1 bit ACK:nếu truyền đi mà các node khác nhận được thì sẽ phản hồi bằng ACK =0  
7. Trường kết thúc (End Of Frame Field – EOF)Bit kết thúc End Of Frame Field – EOF =`1`










</details>
</details>

<details>
  <summary><h3>TIMER  </h3></summary>

**Timer là gì**
-  là một phần cứng trong vi điều khiển 



1. chức năng và ứng dụng của Timer ?
- Đếm thời gian (tạo độ trễ, đo thời gian sự kiện).
- Phát tín hiệu định kỳ (ngắt Timer).
- Tạo tín hiệu PWM (điều khiển động cơ, độ sáng LED).
- Đo tần số hoặc độ dài xung (Input Capture).
2. Sự khác biệt giữa Timer và Counter là gì?
- Timer: Đếm dựa trên xung clock nội bộ. Dùng để đo thời gian hoặc tạo tín hiệu định kỳ.
- Counter: Đếm dựa trên xung tín hiệu bên ngoài. Dùng để đếm các sự kiện như số lần nhấn nút hoặc số vòng quay.
3.  Các loại Timer phổ biến là gì? Bạn có thể giải thích cách hoạt động của mỗi loại?
- Basic Timer: Đơn giản, chỉ để đếm thời gian hoặc phát ngắt định kỳ.
- General-Purpose Timer: Đa năng, hỗ trợ chế độ đếm, đo tín hiệu (Input Capture), và tạo PWM.
- Advanced Timer: Tích hợp thêm tính năng phức tạp như điều khiển động cơ.
- Watchdog Timer (WDT): Reset hệ thống nếu không được làm mới trong khoảng thời gian nhất định.
4. Bạn hiểu thế nào về các chế độ hoạt động của Timer (One-shot, Periodic, PWM)?
- One-shot: Timer chạy một lần và dừng sau khi hết thời gian.
- Periodic: Timer tự động reset và tiếp tục đếm, tạo ngắt định kỳ.
- PWM: Timer tạo tín hiệu xung vuông với chu kỳ và độ rộng xung có thể điều chỉnh
5. Timer có thể được sử dụng để tạo độ trễ như thế nào?
- Cấu hình Timer với tốc độ đếm cụ thể.
- Đợi đến khi Timer đạt giá trị mong muốn hoặc sử dụng ngắt Timer để báo hiệu hết thời gian.
7. Bạn đã từng cấu hình Timer để tạo tín hiệu PWM chưa? Nếu có, hãy mô tả cách bạn thực hiện.
	1. Cấp xung clock cho Timer .
	2. Tính Prescaler và Period( ví dụ tính cho động có 50hz)
		- Bộ chia tần số:Prescaler giảm tần số clock gốc (84 MHz xuống 1 MHz).= f clock -1;
		- Chu kỳ Timer:Period = ftimer/fpwm=1 triệu/50 -1=20.000-1
	3. Cấu hình Timer ở chế độ PWM.
	4. Cấu hình GPIO (AF)
	5. Bắt đầu Timer ở chế độ PWM.
		- Sử dụng Compare Register để điều chỉnh Duty Cycle 
		- 1 ms (5% Duty Cycle): Góc quay nhỏ nhất (thường là 0°).
		- 1 ms là thời gian ở mức cao trong 20ms
		- 5 % là Duty Cycle , nghĩa là 1 ms tương ứng 5 % 


8. Bạn đã sử dụng Timer để đếm số xung chưa?
    1. Cấp xung clock cho Timer .
	2. cấu hình  Prescaler và Period phù hợp
		- Prescaler: Cấu hình để điều chỉnh tần số đếm phù hợp thường là 1Mhz
		- Period  Thiết lập giá trị tối đa để Timer tự động quay lại 0 , thường là 1ms
	3. Cấu hình Timer ở chế độ Counter.
		- Đếm lên (UP) hoặc đếm xuống (DOWN).
	4. Cấu hình nguồn xung Clock
		- Internal Clock: Dùng clock nội bộ.
		- External Clock: Sử dụng tín hiệu từ chân GPIO (cấu hình Timer ở chế độ External Clock hoặc Encoder).
	5. Bắt đầu Timer ở chế độ đếm .
		- Khởi động Timer để bắt đầu đếm số xung
	6.  Đọc giá trị Counter

9. Khi làm việc với hệ thống nhúng có nhiều Timer, bạn đã tối ưu hóa cách sử dụng chúng như thế nào?
   - Phân chia nhiệm vụ phù hợp cho từng Timer
   - Tính toàn Prescaler và Period hợp ly
   - Kết hợp DMA với Timer

   
10. Làm thế nào để cấu hình Timer để phát ra ngắt định kỳ? Bạn đã từng xử lý ngắt từ Timer chưa?
    - Cấp xung clock cho Timer .
	- cấu hình  Prescaler và Period để thiết lập chu kỳ ngắt.
	- Kích hoạt tính năng ngắt Timer và đăng ký ngắt với NVIC
	- Viết hàm xử lý ngắt Thực hiện các tác vụ khi ngắt xảy ra.
 

11. Bạn sẽ làm gì nếu Timer không chính xác (ví dụ: sai tần số hoặc độ trễ)?
    - Kiểm tra xung clock đầu vào (prescaler, nguồn clock).
    - Đảm bảo giá trị Prescaler và Period tính toán chính xác

12. Nếu Timer hết hạn trước khi tác vụ hiện tại hoàn thành, bạn sẽ xử lý tình huống này như thế nào?
    - Tăng Period
    - Kết hợp DMA với Timer

13. Làm thế nào để xử lý lỗi tràn số của Timer (Timer Overflow)?
    - tính toán để Period và ARR phù hợp không vượt quá độ phân giải timer(8 bit,16 bit)có thể ARR sẽ quay về 0 trước Period 
	- ARR: Là mốc lớn nhất mà Timer được cài đặt để đếm đến trước khi quay lại 0.
	- Period Là khoảng thời gian thực để Timer đếm từ 0 đến ARR và quay về 0
	- Khi Timer đạt ARR, nó sẽ quay về 0 

15. Trong một hệ thống đa nhiệm, Timer được sử dụng như thế nào ?
    - Timer được cấu hình để phát ra ngắt ở các khoảng thời gian cố định.
    - Timer Điều khiển thời gian thực hiện các tác vụ.


16. Khi cấu hình Timer trên STM32 hoặc ESP32, bạn thường sử dụng thư viện chuẩn (HAL/LL) hay viết mã thủ công? Tại sao?
    - Sử dụng HAL/LL để tiết kiệm thời gian và giảm lỗi.
    - Viết mã thủ công khi cần tối ưu hóa hiệu suất hoặc cấu hình phức tạp.

17. Bạn sẽ debug như thế nào nếu Timer không hoạt động hoặc không tạo ra ngắt?
    - Timer không chạy:
		- Đảm bảo Timer đã được cấp xung clock từ RCC (Reset and Clock Control).
		- Kiểm tra giá trị Prescaler và Period xem thử tính toán chính xác chưa
		- Đảm bảo Timer được đặt ở chế độ đúng
	-  Kiểm tra ngắt (Interrupt)
		- đảm bảo chế độ ngắt được khởi động
		- đảm bảo đã bật ngắt trong NVIC.
		- Đảm bảo hàm ISR được khai báo chính xác trong file startup hoặc vector ngắt.
	- Phân tích lỗi với công cụ debug
18. Bạn đã sử dụng Timer để tạo độ trễ chính xác chưa? Làm thế nào để thực hiện điều này?
    - Cấu hình Timer với tốc độ đếm phù hợp.
    - Chờ Timer đạt giá trị mong muốn trước khi tiếp tục.

19. Làm thế nào để đo thời gian chính xác đến micro giây hoặc mili giây bằng Timer?
	- Prescaler thấp (1 MHz): Timer đếm với độ chính xác 1 µs 
    - Prescaler cao (1 kHz): Timer đếm với độ chính xác 1 ms 

20. Khi nào bạn chọn sử dụng Timer phần cứng thay vì giải pháp phần mềm để quản lý thời gian?
    - Dùng Timer phần cứng khi yêu cầu độ chính xác cao 
    - Dùng giải pháp phần mềm tài nguyên phần cứng hạn chế.


22. Bạn đã từng sử dụng Watchdog Timer chưa? Hãy mô tả cách nó hoạt động và khi nào cần sử dụng.
	- Mục đích: Đảm bảo hệ thống không bị treo hoặc dừng hoạt động.
    - WDT bắt đầu đếm từ 0 đến giá trị giới hạn (timeout).
	- Hệ thống phải "làm mới" (reset WDT) trước khi WDT đạt timeout.
	- Nếu không làm mới kịp:
		-  WDT sẽ reset hệ thống.
    - Đảm bảo hệ thống phục hồi từ lỗi như treo (hang) hoặc deadlock.




<details>
  <summary><h4>External interrupt </h4></summary>

























- Các bước triển khai:
	- Bước 1: Bật Clock cho TIMER
		- Bật clock cho TIMER bằng cách cấu hình thanh ghi RCC.
 
	- Bước 2: Cấu hình Prescaler
		- Prescaler chia tần số clock hệ thống xuống tần số thấp hơn phù hợp với TIMER.
		- Ví dụ: Nếu SYSCLK = 84 MHz và cần tần số TIMER = 1 MHz, Prescaler = 84.
	- Bước 3: Cấu hình chu kỳ Timer (ARR - Auto-Reload Register)
		- Thiết lập giá trị chu kỳ (ARR) để TIMER đếm từ 0 đến ARR, sau đó lặp lại.
		- Ví dụ: Với TIMER 1 MHz và ARR = 1000, tín hiệu đầu ra có tần số 1 kHz.
	- Bước 4: Cấu hình chế độ hoạt động
		- Chọn chế độ TIMER: đếm tăng, đếm giảm, hoặc đếm lặp lại.
		- Ví dụ: Sử dụng chế độ PWM hoặc Capture Compare.
	- Bước 5: Bật TIMER
		- Kích hoạt TIMER bằng cách thiết lập bit CEN trong thanh ghi CR1.












- External interrupt (EXTI) hay còn gọi là ngắt ngoài. Là 1 sự kiện ngắt xảy ra khi có tín hiệu can thiệp từ bên ngoài, từ phần cứng, người sử dụng hay ngoại vi,… 
- Sơ đồ khối của các khối điều khiển ngắt ngoài:
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/0d74dfa6-8c4a-4108-b7ec-b8b5793513ed)

- Ngắt ngoài của chip STM32F4bao gồm có 16 line:
	+ External interrupt/event line mapping
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/1b8b9683-c81d-4074-8482-3dcc2f2948c3)

- Tiếp theo các Line ngắt sẽ được phân vào các Vector ngắt tương ứng
	+ Table 61. Vector table for STM32F405xx/07xx and STM32F415xx/17xx
- Các Line0, Line1, Line2, Line3, Line4 sẽ được phân vào các vector ngắt riêng biệt EXTI0, EXTI1, EXTI2, EXTI3, EXTI4
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/e1a4a0b8-e4c2-4ee0-b9fd-22780022101d)
- Còn từ Line5->Line9 sẽ được phân vào vector ngắt EXTI9_5, Line10->Line15 được phân vào vecotr EXTI15_10.
- ![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/cfd36fa1-9a2b-491d-82b4-a9687c0399fa)
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/e245a7fc-08c6-4166-be0d-a1928cf49d06)
- Bảng mức độ ưu tiên ngắt NVIC:
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/73a2d0c7-1ad8-44f2-a7f8-738862765b37)
- Có hai loại ưu tiên ngắt khác nhau trên MCU STM32F103C8T6 đó là Preemption Priorities và Sub Priorities:
	+ Mặc định thì ngắt nào có Preemtion Priority cao hơn thì sẽ được thực hiện trước.
	+ Khi nào 2 ngắt có cùng một mức Preemption Priority thì ngắt nào có Sub Priority cao hơn thì ngắt đó được thực hiện trước.
	+ Còn trường hợp 2 ngắt có cùng mức Preemption và Sub Priority luôn thì ngắt nào đến trước được thực hiện trước.

 <details>
<summary>CODE_STM32F4</summary>
+ Cau hinh nut nhan PE4
+ // Cau hinh LED PA6
Khi nhấn nút thì ngắt xảy ra

```C
#include "stm32f4xx.h"

void RCC_Config(){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);// (enable) xung nhịp cho bộ chuyển mạch hệ thống (System Configuration - SYSCFG)
//Khi xung nhịp được kích hoạt cho SYSCFG, để  cấu hình các chân ngắt ngoại (external interrupts) thông qua hàm SYSCFG_EXTILineConfig
}

void GPIO_Config(){
    GPIO_InitTypeDef GPIO_InitStruct;

    // Cau hinh nut nhan PE4
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStruct);

    // Cau hinh LED PA6
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void EXTI_Config(){
    EXTI_InitTypeDef EXTI_InitStruct;

    // Định tuyến chân ngắt ngoại từ PE4 đến EXTI_Line4
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);

    // Cấu hình chân ngắt ngoại EXTI_Line4
    EXTI_InitStruct.EXTI_Line = EXTI_Line4; // Chọn chân ngắt ngoại là EXTI_Line4
    EXTI_InitStruct.EXTI_LineCmd = ENABLE; // Kích hoạt chân ngắt ngoại
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt; // Chọn chế độ ngắt ngoại
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising; // Chọn kiểu ngắt ngoại: cạnh dương
    EXTI_Init(&EXTI_InitStruct);
}

// Cấu hình ngắt (NVIC)
void NVIC_Config(){
    NVIC_InitTypeDef NVIC_InitStruct;

    // Cấu hình ngắt EXTI4
    NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn; // Chọn kênh ngắt là EXTI4
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; // Kích hoạt ngắt
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0; // Độ ưu tiên ngắt
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0; // Độ ưu tiên ngắt
    NVIC_Init(&NVIC_InitStruct);
}
// Hàm xử lý ngắt khi nút nhấn được nhấn
void EXTI4_IRQHandler(){
    if (EXTI_GetITStatus(EXTI_Line4) != RESET){
        GPIO_ToggleBits(GPIOA, GPIO_Pin_6);
    }
    EXTI_ClearITPendingBit(EXTI_Line4);// Xóa cờ ngắt
}

int main(){
    RCC_Config();
    GPIO_Config();
    EXTI_Config();
    NVIC_Config();

    while(1){
 
    }
}




```
</details>
</details>

<details>
  <summary><h4>Ngắt Timer </h4></summary>

- Timers thường được sử dụng để thực hiện các chức năng thời gian, đo đạc thời gian, và tạo ngắt theo chu kỳ. Các timers thường đi kèm với các chức năng ngắt (interrupts) để thực hiện các công việc liên quan đến thời gian.
**Reset and clock control for STM32F42xxx and STM32F43xxx (RCC)**
- ![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/b6b0065e-a44e-42e1-9f10-d88cfe765077)
-  xung nhịp hệ thống là 168MHz, chia 1,2 vẫn giữ nguyên.
<details>
<summary>CODE_STM32F4</summary>

-Timer (TIM2) và một GPIO pin (GPIOA Pin 6).
- Tạo một ngắt (interrupt) sau mỗi khoảng thời gian nhất định và trong hàm ngắt, trạng thái của GPIOA Pin 6(LED)

```c
#include "stm32f4xx.h"

// Cấu hình xung nhịp cho cổng GPIOA và timers TIM2 và TIM3
void RCC_Config() {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // Kích hoạt xung nhịp cho GPIOA
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);   // Kích hoạt xung nhịp cho TIM2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);   // Kích hoạt xung nhịp cho TIM3
}

// Cấu hình chân GPIOA Pin 6 làm chân đầu ra
void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

// Cấu hình timers TIM2 và TIM3
void Tim_Config() {
    TIM_TimeBaseInitTypeDef Tim_InitStruct;

    // Cấu hình TIM2
    Tim_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    Tim_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    Tim_InitStruct.TIM_Period = 1000000 - 1;  // Chu kỳ là 1 giây (đếm từ 0 đến 999999)
    Tim_InitStruct.TIM_Prescaler = 168 - 1;    // Bộ chia tần, giả sử xung nhịp hệ thống là 168MHz
    TIM_TimeBaseInit(TIM2, &Tim_InitStruct);
    TIM_Cmd(TIM2, ENABLE);  // Bắt đầu đếm
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);  // Kích hoạt ngắt khi đếm đến giá trị Period

    // Cấu hình TIM3 để tạo hàm delay
    Tim_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    Tim_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    Tim_InitStruct.TIM_Period = 0xFFFF - 1;   // Giả sử đếm từ 0 đến 65535
    Tim_InitStruct.TIM_Prescaler = 168 - 1;
    TIM_TimeBaseInit(TIM3, &Tim_InitStruct);
    TIM_Cmd(TIM3, ENABLE);
}

// Cấu hình ngắt cho TIM2
void NVIC_Config() {
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_InitStruct);
}

// Hàm xử lý ngắt TIM2
void TIM2_IRQHandler() {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update)) {
        GPIO_ToggleBits(GPIOA, GPIO_Pin_6);    // Chuyển đổi trạng thái của GPIOA Pin 6
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);  // Xóa cờ ngắt TIM2
    }
}

// Hàm delay sử dụng TIM3
void delay(uint32_t TIM_TIME) {
    TIM_SetCounter(TIM3, 0);  // Reset bộ đếm của TIM3
    while (TIM_GetCounter(TIM3) < TIM_TIME * 1000);  // Đợi cho đến khi bộ đếm đạt đến giá trị cần
}

// Hàm main
int main() {
    RCC_Config();   // Cấu hình xung nhịp và các thành phần cần thiết
    GPIO_Config();
    NVIC_Config();
    Tim_Config();

    while (1) {
        // Chương trình chính
    }
}







```
</details>
</details>

<details>
  <summary><h4>Timer_PWM_SEGVO</h4></summary>


- Timer là bộ đếm thời gian:
- Chia thành các loại Timer:
	+ Basic Timers (TIM6 và TIM7): Thường được sử dụng cho các ứng dụng cơ bản, như tạo ra các tín hiệu đơn giản.
	+ General-purpose Timers (TIM2 đến TIM5 và TIM9 đến TIM14): Cung cấp nhiều tính năng, bao gồm các chế độ đếm, PWM (Pulse Width Modulation), và đặc biệt là chức năng Encoder Interface.
	+ Advanced Timers (TIM1 và TIM8): Cung cấp nhiều tính năng cao cấp hơn như chế độ PWM mở rộng, chế độ Capture/Compare và chế độ Encoder.
- PWM hay Pulse Width Modulation là phương pháp điều chỉnh độ rộng xung , nhằm tạo ra sự thay đổi điện áp tại đầu ra.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/61dc04f7-b3aa-4a63-b28e-b5540cfdd036)
- PWM ứng dụng nhiều trong việc điều khiển động cơ, các bộ nguồn xung boot, buck, nghịch lưu 1 pha, 3 pha…
- Sử dụng TIM2 để tạo PWM:
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/e2c6e206-d3b5-4862-828c-791e3c9dae50)
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/cbb56880-659c-4e50-9dbc-12cc77cfb414)
- AHB1 =42 mhz ,nó đã qua bộ chia 4,  dựa vào hình ta có TIM2 =AHB1x2 =42MHZ
- Gỉa sử nếu làm TIM1 >> TIM1 =168MHZ
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/c63eeb39-b30a-4936-9c0e-4ad8bc04d0c8)
- Dựa vào hình ta tính TIM_Period

<details>
<summary>CODE_STM32F4</summary>

```C
#include "stm32f4xx.h"
void RCC_Configuration(void)
{ 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
}

void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);  
}

void TIM_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_TimeBaseStructure.TIM_Period = 20000-1;
	//thời gian xung cạnh lên là 20ms
    TIM_TimeBaseStructure.TIM_Prescaler = 84-1; // bộ chia 84
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;// đếm lên
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  

    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 10000-1; // 50% duty cycle
	// thời gian xung canh lên 
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC2Init(TIM2, &TIM_OCInitStructure); 
    TIM_Cmd(TIM2, ENABLE);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
    TIM_Cmd(TIM2, ENABLE);
    TIM_ARRPreloadConfig(TIM2, ENABLE);
}


int main(void)
{
    RCC_Configuration();
    GPIO_Configuration();
    TIM_Configuration();

    while (1)
    {
			TIM_SetCompare2(TIM2,999);
			for(uint32_t i=0;i<84000000;i++);
			TIM_SetCompare2(TIM2,1499);
			for(uint32_t i=0;i<84000000;i++);
			TIM_SetCompare2(TIM2,1999);
			for(uint32_t i=0;i<84000000;i++);
			TIM_SetCompare2(TIM2,1499);
			for(uint32_t i=0;i<84000000;i++);
			 
    }
} 

```

</details>


</details>
</details>
<details>
  <summary><h3>ADC</h3></summary>


1. ADC là bộ chuyển đổi tín hiệu analog (tín hiệu tương tự) thành tín hiệu số (digital).
2. Bạn hiểu thế nào về độ phân giải của ADC?
- Độ phân giải xác định số lượng  tín hiệu số mà ADC có thể tạo ra từ tín hiệu analog.
3. Tần số lấy mẫu (Sampling Rate) là gì và tại sao nó quan trọng?
- Tần số lấy mẫu là  tốc độ mà ADC lấy mẫu tín hiệu analog  trong 1 s
4. Sự khác biệt giữa độ chính xác và độ phân giải của ADC là gì?
- Độ phân giải: Liên quan đến số bit của ADC, xác định mức điện áp nhỏ nhất mà ADC có thể phân biệt.
- Độ chính xác: Liên quan đến mức độ gần gũi giữa giá trị chuyển đổi và giá trị thực của tín hiệu đầu vào, phụ thuộc vào nhiễu, lỗi tham chiếu, và chất lượng thiết kế.
5. Các phương pháp chuyển đổi ADC phổ biến là gì?
- Successive Approximation Register (SAR): Phương pháp phổ biến nhất, cân bằng giữa tốc độ và độ chính xác.
- Sigma-Delta: Độ chính xác cao, tốc độ thấp, thường dùng trong âm thanh.
- Flash ADC: Nhanh nhất, nhưng tốn tài nguyên và đắt đỏ.
- Dual-Slope: Độ chính xác cao, thường dùng trong đo đạc.
6. Trong một dự án cụ thể, bạn đã sử dụng ADC như thế nào để đọc tín hiệu?
- Cảm biến LM35 xuất tín hiệu analog tuyến tính theo nhiệt độ.
- ADC trên vi điều khiển (STM32) chuyển đổi tín hiệu analog từ cảm biến sang số.
7. Bạn đã từng sử dụng DMA (Direct Memory Access) với ADC chưa? Nếu có, hãy mô tả cách thực hiện.
	1. Cấp xung cho ADC, DMA, và GPIO
	2. Đặt chân GPIO ở chế độ Analog để kết nối tín hiệu ADC
	3. Cấu hình DMA:DMA tự động truyền dữ liệu từ ADC vào bộ nhớ đệm 
	4. Cấu hình ADC với chế độ DMA
	5. Xử lý giá trị ADC để chuyển thành điện áp hoặc thông số vật lý.
	6. Dùng Điện áp tham chiếu để chuyển đổi số ADC
8. Bạn đã từng xử lý nhiễu tín hiệu ADC chưa? Nếu có, bạn làm như thế nào?
- Tăng độ chính xác: Thêm tụ lọc (capacitor) ở chân analog để giảm nhiễu.
- Lọc trung bình (Averaging): Lấy trung bình nhiều giá trị ADC để làm mượt dữ liệu.
- Sử dụng nguồn tham chiếu ổn định (Vref): Đảm bảo Vref không bị dao động.
9. Làm thế nào để đo điện áp âm với ADC?
- Chuyển đổi tín hiệu âm: Thêm một điện áp offset (DC bias) vào tín hiệu để chuyển nó sang dải điện áp dương.
- Sử dụng Op-Amp: Khuếch đại và chỉnh sửa tín hiệu trước khi đưa vào ADC.
10. Bạn sẽ làm gì nếu ADC đọc giá trị không chính xác?
- Nguồn tham chiếu (Vref) ổn định.
- Tín hiệu đầu vào trong dải điện áp của ADC.
- Thêm kỹ thuật lọc tín hiệu hoặc hiệu chỉnh ADC.
11. Làm thế nào để tối ưu hiệu suất ADC khi cần tốc độ cao?
- Tăng tần số clock ADC nhưng vẫn trong dải hỗ trợ.
- Sử dụng DMA để giảm tải CPU.
- Giảm số lượng kênh chuyển đổi hoặc độ phân giải nếu cần thiết.
12. Bạn đã từng sử dụng ADC để đo tín hiệu tốc độ cao (như âm thanh) chưa? 
- Sử dụng ADC với độ phân giải cao (16-bit hoặc 24-bit).
- Tăng tần số lấy mẫu (theo nguyên tắc Nyquist).
- Dùng bộ lọc thấp (Low-Pass Filter) để loại bỏ nhiễu tần số cao.
14. Khi cấu hình ADC trên STM32, bạn thường sử dụng thư viện HAL hay viết mã thủ công? Tại sao?
- Sử dụng HAL để tiết kiệm thời gian và giảm lỗi.
- Viết mã thủ công khi cần tối ưu hóa hiệu suất hoặc cấu hình phức tạp.
15. Bạn sẽ debug như thế nào nếu ADC không hoạt động hoặc đọc giá trị sai?
- Kiểm tra cấu hình clock và nguồn tham chiếu.
- Đảm bảo tín hiệu đầu vào trong dải điện áp hợp lệ.
- Sử dụng oscilloscope để kiểm tra tín hiệu analog.
16. Làm thế nào để đảm bảo ADC hoạt động chính xác trong môi trường nhiễu?
- Dùng tụ lọc ở đầu vào tín hiệu.
- Tăng thời gian lấy mẫu.
- Dùng vỏ bọc kim loại (shielding) để giảm nhiễu.
17. Khi nào bạn chọn ADC 10-bit thay vì 12-bit hoặc 16-bit?
- Chọn ADC 10-bit khi:
- Yêu cầu tốc độ cao.
- Độ phân giải cao không cần thiết.
- Hệ thống có tài nguyên hạn chế.
18. Làm thế nào để đo tín hiệu AC với ADC?
- Sử dụng mạch chỉnh lưu
- Sử dụng bộ lọc thấp để giảm nhiễu.
19. Làm thế nào để tối ưu hóa hiệu suất ADC trong hệ thống đa kênh?
- Sử dụng DMA để tự động lưu dữ liệu.
- Tối ưu tần số clock để tăng tốc độ mà không giảm chất lượng.


**Lý thuyết ADC**



- ADC Analog to Digital Convert là bộ chuyển đổi tương tự sang số.
- Cho phép chuyển đổi tín hiệu analog như điện áp , dòng điện ,ánh sáng .. thông số thay đổi liên tục thành dạng số để máy tính hoặc VXL xử lý
- Cách hoạt động:
	- Tín hiệu đầu vào: Là tín hiệu điện áp tương tự, ví dụ: từ 0V đến 3.3V.
	- Chuyển đổi thành số: ADC chia dải điện áp này thành các mức số rời rạc. Ví dụ: một ADC 10-bit sẽ chia dải điện áp thành 1024 mức.
- Độ phân giải (Resolution):
	- Số lượng bit đầu ra (ví dụ: 8-bit, 10-bit, 12-bit). Độ phân giải càng cao, tín hiệu số càng chính xác.
- Tốc độ lấy mẫu (Sampling Rate):
	- Tốc độ mà ADC có thể đọc tín hiệu analog (đơn vị: Samples per second).

Quy trình lập trình ADC:
- Bước 1: Cấu hình ADC
	- Mục tiêu: Cấu hình các thông số của ADC phù hợp với yêu cầu của ứng dụng.
	- Chi tiết:
	- Chọn kênh ADC để đọc tín hiệu (ví dụ: kênh ADC1 trên STM32).
	- Cấu hình độ phân giải ADC (8-bit, 10-bit, hoặc 12-bit) tùy thuộc vào độ chính xác yêu cầu.
	- Thiết lập tần số lấy mẫu (sampling rate) để phù hợp với tín hiệu đầu vào.
		- Sampling Rate (Tần số lấy mẫu) là số lần ADC chuyển đổi tín hiệu analog (liên tục),thành tín hiệu digital (rời rạc) trong một giây.
		- Nếu Sampling Rate là 1 kHz, ADC sẽ đo giá trị tín hiệu 1000 lần mỗi giây.
	- Cấu hình chế độ hoạt động:
	- Single conversion mode: Chỉ chuyển đổi một lần khi được kích hoạt.
	- Continuous mode: Tự động chuyển đổi liên tục.
- Bước 2: Khởi động ADC
	- Mục tiêu: Kích hoạt ADC để bắt đầu quá trình chuyển đổi.
	- Chi tiết:
	- Nếu sử dụng chế độ single conversion, cần kích hoạt ADC mỗi lần lấy mẫu.
	- Trong chế độ DMA (Direct Memory Access), ADC tự động chuyển giá trị sang bộ nhớ.

- Bước 3: Đọc giá trị ADC
	- Mục tiêu: Lấy giá trị từ ADC và chuyển đổi sang giá trị thực tế.
	- Chi tiết:
	- Sử dụng hàm lấy giá trị ADC sau khi chuyển đổi hoàn tất.
	- Chuyển đổi giá trị ADC thành đại lượng vật lý (ví dụ: điện áp, nhiệt độ).



**tại sao cần chia tần số ?**
- Nếu không chia tần số, CPU phải xử lý liên tục, làm giảm hiệu suất của các tác vụ khác trong hệ thống.
- Tần số tối đa của các ngoại vi có giới hạn 
	- ví dụ :ADC chỉ hỗ trợ tốc độ tối đa 36 MHz.
	
**Khi nào cần chú ý đến thanh ghi trong code ADC?**
- Nếu bạn không sử dụng thư viện hỗ trợ (như HAL/LL của STM32 hoặc Arduino), cần trực tiếp thao tác với các thanh ghi điều khiển của ADC để cấu hình và vận hành.
- Điều này đòi hỏi bạn phải hiểu chi tiết về cấu trúc thanh ghi từ datasheet của vi điều khiển.

</details> 
<details>
  <summary><h3>DMA</h3></summary>

- DMA  là một module phần cứng cho phép các thiết bị ngoại vi giao tiếp trực tiếp với bộ nhớ mà không cần sự can thiệp của CPU..
- Điều này giúp Giảm tải cho CPU. tăng hiệu suất hệ thống.

1. Cách hoạt động:
- CPU cấu hình DMA với thông tin: nguồn, đích, kích thước dữ liệu.
- DMA tự động chuyển dữ liệu giữa các thiết bị mà không làm gián đoạn CPU.
- Sau khi hoàn tất, DMA phát tín hiệu (interrupt) để báo CPU.
2. Ưu điểm của việc sử dụng DMA là gì?
- Giảm tải CPU: CPU có thể xử lý các tác vụ khác trong khi DMA thực hiện việc truyền dữ liệu.
- Tăng tốc độ: DMA hoạt động nhanh hơn so với việc chuyển dữ liệu bằng phần mềm.
- Tiết kiệm năng lượng: Giảm chu kỳ xử lý của CPU.
3. DMA được sử dụng trong những trường hợp nào?
- Giao tiếp dữ liệu tốc độ cao giữa ngoại vi và bộ nhớ (UART, SPI, I2C, ADC, DAC).
- Các hệ thống thời gian thực yêu cầu hiệu suất cao.
4. DMA hoạt động đồng bộ và bất đồng bộ như thế nào?
- Đồng bộ: DMA hoạt động dưới sự kiểm soát của một tín hiệu hoặc sự kiện (trigger).
- Bất đồng bộ: DMA tự động chuyển dữ liệu theo cấu hình mà không cần tín hiệu trigger.
5. Trong một dự án cụ thể, bạn đã sử dụng DMA để truyền dữ liệu như thế nào?
- UART:
	- DMA được cấu hình để tự động truyền dữ liệu từ bộ nhớ đến UART TX.
	- Khi bộ đệm truyền đầy, DMA gửi tín hiệu interrupt để xử lý dữ liệu tiếp theo.
- SPI:
	- Cấu hình DMA để truyền dữ liệu từ bộ nhớ đến SPI TX.
	- SPI RX sử dụng DMA để nhận dữ liệu vào bộ nhớ.
- I2C:
	- DMA truyền dữ liệu từ bộ nhớ đến I2C để giao tiếp với slave.
	- DMA tự động xử lý mà không cần CPU can thiệp.
- ADC:
	- Cấu hình ADC để hoạt động ở chế độ Scan Mode.
	- Kích hoạt DMA để tự động lưu dữ liệu ADC vào buffer.
	- Sử dụng Circular Mode để liên tục đọc dữ liệu từ các kênh ADC.
	- Ưu điểm: CPU không cần xử lý từng mẫu dữ liệu ADC, giúp giảm tải đáng kể.
6. Khi làm việc với DMA, bạn đã xử lý lỗi như thế nào?
- Dữ liệu không đầy đủ: Kiểm tra kích thước buffer và nguồn/đích cấu hình đúng hay chưa.
- DMA không khởi động: Đảm bảo DMA đã được bật và có trigger từ ngoại vi.
- Giao tiếp ngắt quãng: Sử dụng chế độ Circular hoặc tăng kích thước buffer.
7. Bạn đã từng tối ưu hóa DMA cho ứng dụng tốc độ cao chưa?
- Double Buffer Mode: Truyền dữ liệu liên tục mà không chờ đợi.
- Ưu tiên DMA: Đặt mức ưu tiên cao hơn cho các kênh DMA quan trọng
8. Làm thế nào để cấu hình DMA để truyền dữ liệu giữa hai bộ nhớ (Memory-to-Memory)?
- Cấu hình DMA với:
	- Nguồn (Source): Địa chỉ vùng bộ nhớ đầu vào.
	- Đích (Destination): Địa chỉ vùng bộ nhớ đầu ra.
	- Kích thước (Data Size): Số byte cần truyền.
	- Kích hoạt DMA và chờ tín hiệu hoàn thành (interrupt hoặc polling).
9. Bạn sẽ xử lý như thế nào nếu DMA không kích hoạt hoặc không truyền dữ liệu?
- Kiểm tra cấu hình:
	- Kênh DMA có được bật không?
	- Địa chỉ nguồn và đích có hợp lệ không?
	- Trigger từ ngoại vi đã được kích hoạt chưa?
	- Đảm bảo clock của DMA đã được bật trong cấu hình RCC.
10. Làm thế nào để ngăn chặn xung đột dữ liệu khi sử dụng DMA và CPU cùng truy cập vào một buffer?
- Double Buffer Mode: Dùng hai buffer để luân phiên truyền và xử lý dữ liệu.
- Mutex hoặc Flag: Đồng bộ giữa DMA và CPU để đảm bảo không truy cập đồng thời.
11. DMA có thể hoạt động song song với CPU như thế nào?
- DMA truyền dữ liệu độc lập với CPU, trong khi CPU thực hiện các tác vụ khác.
- Khi DMA hoàn tất, nó gửi một tín hiệu interrupt để thông báo cho CPU.
12. Làm thế nào để đo hiệu suất của DMA?
- So sánh thời gian truyền dữ liệu giữa việc sử dụng DMA và CPU.
- Sử dụng công cụ debug (logic analyzer, oscilloscope) để đo thời gian truyền thực tế.
13. Bạn đã từng sử dụng DMA trong ứng dụng âm thanh hoặc video chưa? Nếu có, hãy mô tả
- DMA được sử dụng để liên tục truyền dữ liệu từ buffer đến DAC để phát âm thanh.
- Sử dụng Circular Mode để đảm bảo luồng dữ liệu không bị gián đoạn.
14. Làm thế nào để kết hợp DMA và Timer để xử lý tín hiệu liên tục?
- Cấu hình Timer để tạo tín hiệu trigger cho DMA.
- DMA đọc dữ liệu từ ADC (hoặc bộ nhớ) và lưu vào buffer theo chu kỳ định sẵn.
15. Bạn sẽ debug như thế nào nếu DMA không hoạt động như mong đợi?
- Kiểm tra cấu hình nguồn, đích, và kích thước dữ liệu.
- Đảm bảo ngoại vi kích hoạt DMA (trigger) hoạt động đúng.
- Sử dụng công cụ debug để kiểm tra trạng thái DMA (flag hoặc interrupt).
16. Làm thế nào để sử dụng DMA cho hệ thống đa kênh (multi-channel)?
- Cấu hình từng kênh DMA với ưu tiên khác nhau.
- Sử dụng chế độ Circular Mode cho kênh liên tục.
- Kích hoạt interrupt để xử lý khi mỗi kênh hoàn thành.
17. Khi nào bạn chọn DMA thay vì sử dụng interrupt hoặc polling?
- Chọn DMA: Khi cần truyền dữ liệu lớn hoặc tốc độ cao, giảm tải CPU.
- Chọn interrupt: Khi dữ liệu nhỏ hoặc yêu cầu thời gian thực cao.
- Chọn polling: Khi hệ thống đơn giản và không yêu cầu hiệu suất cao.
18. Làm thế nào để tối ưu hóa việc sử dụng DMA trong hệ thống có tài nguyên hạn chế?
- Sử dụng DMA cho các tác vụ ưu tiên cao.
- Giảm kích thước buffer để tiết kiệm bộ nhớ.
- Tận dụng DMA đa kênh để quản lý

Quy trình lập trình DMA:

1. Cấp xung cho DMA và ngoại vi
- Bật clock DMA bằng cách cấu hình trong thanh ghi RCC.
2. Thiết lập DMA để truyền dữ liệu giữa ngoại vi và bộ nhớ
- Xác định nguồn dữ liệu (peripheral) và đích (bộ nhớ hoặc buffer).
- Cấu hình số lượng mẫu dữ liệu cần truyền.( ví dụ 100 mẫu , mỗi mẫu 16 bit)
- Chọn chế độ truyền:
	- Normal Mode: Truyền một lần rồi dừng.
	- Circular Mode: Liên tục truyền khi đạt số lượng dữ liệu đã cấu hình.
3.  Cấu hình ngoại vi (ví dụ: ADC) 
	- Cấu hình như bình thường , thêm Kích hoạt DMA trong ngoại vi
4. Kích hoạt DMA
	- Kích hoạt DMA bằng cách thiết lập thanh ghi điều khiển tương ứng.
5. Xử lý dữ liệu
	- Xử lý dữ liệu trong bộ nhớ sau khi DMA hoàn thành.
	- Dùng ngắt DMA nếu cần để tối ưu xử lý.
		- ví dụ Xử lý dữ liệu ADC
**QUY TRÌNH**
1. DMA với ADC (Liên tục đọc dữ liệu)
	- Quy trình:
	- Cấu hình ADC ở chế độ Continuous.
	- Cấu hình DMA để đọc giá trị ADC từ thanh ghi DR và lưu vào buffer.
	- Kích hoạt ADC và DMA.
	- Dữ liệu sẽ tự động được cập nhật trong buffer.
2. DMA với SPI (Gửi/nhận dữ liệu nhanh)
	- Quy trình:
	- Cấu hình SPI ở chế độ Master.
	- Cấu hình DMA để gửi và nhận dữ liệu qua SPI.
	- Kích hoạt SPI và DMA.
	- Dữ liệu tự động truyền qua SPI khi DMA chạy.


</details>


<details>
  <summary><h3>Booting</h3></summary>

**Quá Trình Booting**
- là quá trình khởi động (hoặc restart) MCU 
- Là chế độ nạp CODE của MCU

- STM32 Có 3 chế độ BOOT có thể lựa chọn qua chân BT0,BT1

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/743eb220-223d-4527-ba45-d50579cb0d96)

- Main Flash memory : (x 0)

	+ Chọn Main Flash memory làm không gian boot. 
	+ Vi điều khiển sẽ khởi động từ địa chỉ bắt đầu của Flash memory.(0x08000000)

- System memory : (0 1)
	+ Chọn System memory làm không gian boot. 
	+ Vi điều khiển sẽ khởi động từ địa chỉ bắt đầu của System memory.(0x1FFF 0000.)

- Embedded SRAM :(1 1)
	+ Chọn Embedded SRAM làm không gian boot. 
	+ Vi điều khiển sẽ khởi động từ địa chỉ bắt đầu của Embedded SRAM.(0x2000 0000 )

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/20a6cd2f-7259-4df3-a1b2-e47704a84a17)

**Vector Table**

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/5dcbc72a-028a-4eca-8fa2-4a9ecb7cd541)


- Vector table là một bảng  chứa các địa chỉ của các hàm xử lý ngắt (interrupt service routines - ISR) được liên kết với các nguồn ngắt cụ thể

- Dưới đây là một số vector quan trọng:
	+ Reset Vector (Number 1): Được gọi khi vi điều khiển được khởi động lại.
	+ Systick Vector (Number 15): Được gọi khi sự kiện ngắt Systick xảy ra.
	+ NMI Vector (Number 2): Được gọi khi sự kiện NMI xảy ra.
	+ Hard Fault Vector (Number 3): Được gọi khi sự kiện ngắt Hard Fault xảy ra.
	+ SVCall Vector (Number 11): Được gọi khi sự kiện ngắt SVCall xảy ra.
	+ PendSV Vector (Number 14): Được gọi khi sự kiện ngắt PendSV xảy ra.

**Quá trình khởi động MCU**

- Trường hợp 1: Khởi động bình thường (không có Bootloader)
	1. Bước 1: Reset hệ thống
	- Khi MCU được bật nguồn hoặc reset, CPU bắt đầu thực thi từ địa chỉ khởi động mặc định.
	- Địa chỉ này thường là 0x00000000 (vùng đầu của bộ nhớ Flash hoặc ROM tùy MCU).
	2. Bước 2: Đọc Vector Table
	- Vector Table nằm ở địa chỉ khởi động mặc định, thường chứa:
	- Stack Pointer (SP): Giá trị khởi tạo của SP được lấy từ địa chỉ đầu tiên (0x00000000).
	- Địa chỉ của Reset_Handler: Lấy từ địa chỉ thứ hai (0x00000004).
	3. Bước 3: Thực thi Reset_Handler
	- Reset_Handler được thực thi và thường thực hiện các nhiệm vụ sau:
	- Khởi tạo hệ thống: Thiết lập bộ nhớ (RAM, heap, stack).
	- Cấu hình các thanh ghi ngoại vi.
	- Khởi tạo thư viện C (runtime C).
	4. Bước 4: 
	- Sau khi hoàn tất khởi tạo, Reset_Handler sẽ nhảy đến hàm main.
	- Hàm main bắt đầu thực thi chương trình chính.
	- Startup code (nằm trong file startup) được viết để đảm bảo hệ thống luôn gọi main() sau khi hoàn thành khởi tạo.
- Trường hợp 2: Khởi động với Bootloader
	- Khi xảy ra ngắt hoặc reset:CPU sẽ tham chiếu Vector Table tại địa chỉ được chỉ định bởi SCB->VTOR.
	Bước 1: Reset hệ thống
	- Khi MCU khởi động, nó vẫn bắt đầu từ địa chỉ khởi động mặc định (0x00000000).
	Bước 2: Đọc Vector Table của Bootloader
	- Tương tự như khởi động bình thường:
	- Stack Pointer (SP) được lấy từ địa chỉ đầu tiên của Vector Table của Bootloader.
	- Địa chỉ Reset_Handler của Bootloader từ địa chỉ thứ hai trong Vector Table của Bootloader.
	Bước 3: Thực thi Reset_Handler của Bootloader
	- Reset_Handler của Bootloader thực hiện các nhiệm vụ:
	- Khởi tạo phần cứng cơ bản.
	- Kiểm tra firmware hoặc nạp firmware mới.
	- Thiết lập SCB_VTOR để trỏ đến địa chỉ Vector Table của ứng dụng chính.( khác 0x00000)
	Bước 4: Thực thi main của Bootloader
	- Sau khi hoàn tất nhiệm vụ của bootloader, nó sẽ:
	- Thiết lập địa chỉ Vector Table  > Reset_Handler cũng bắt đầu từ địa chỉ Vector Table
	Bước 5: Thực thi Reset_Handler của ứng dụng chính
	- Reset_Handler của ứng dụng chính thực hiện các bước khởi tạo như:
	- Thiết lập bộ nhớ, khởi tạo biến toàn cục và cấu hình phần cứng cần thiết.
	Bước 6: Gọi main của ứng dụng chính
	- Sau khi Reset_Handler hoàn tất, ứng dụng chính bắt đầu thực thi từ hàm main..

- Tóm lại muốn chương trình khởi động từ địa chỉ nào chỉ cần thay đổi vector VTOR
**Bootloader là gì?**

- Chương trình Boot chương trình được lưu trong bộ nhớ. Khi Vi điều khiển Reset.nó sẽ nhảy vào chương trình Boot này, để lựa chọn chương trình ứng dụng nào để bắt đầu thực hiện
- Tại sao Bootloader cập nhật từ địa chỉ khác địa chỉ 0x0000:
	+ Tránh ghi đè chính Bootloader trong quá trình cập nhật.
	+ Phân vùng rõ ràng giữa Bootloader và ứng dụng, giúp dễ bảo trì và quản lý.









</details>
</details>





</details>
<details>
  <summary><h1>▶ ⭐Autosar</h1></summary>

<details>
  <summary><h2>Khái niệm</h2></summary

**Autosar là gì?**
-  là một tiêu chuẩn để phát triển phần mềm cho các hệ thống nhúng trong xe ô tô
- AutoSAR không tập trung vào mã nguồn , mà đặt ra các hướng dẫn về cách tổ chức mã, quản lý cấu hình, và làm thế nào các thành phần phần mềm tương tác với nhau. 

**Mô hìnhAutosar?**

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/04226826-e3ff-48ef-af51-fac5079e0338)

- BSW:
	+ MCAL:Tạo 1 môi trường giúp MCU giao tiếp với các ngoại vi bên ngoài như cảm biển
	
	+ ECU:Cung cấp những tính năng cụ thể cho MCU.
		+ Ví dụ như Đk động cơ thì khởi động , tắt động cơ

	+ SL: Tạo các service để gọi các tính năng đã đề cập ở lớp ECU

- RTE:một lớp phần mềm trung gian giữa ứng dụng và các lớp  khác ,quản lý và cung cấp các dịch vụ hệ thống cần thiết để chạy các ứng dụng nhúng trong xe ô tô
- Application Layer: Chứa code liên quan đến ứng dụng cụ thể của hệ thống ô tô.
	+ Những hàm trong Application chạy độc lập với nhau

**Bài toán thực tế?**
- Điều khiển động cơ bằng STM32 theo tiêu chuẩn Autosar

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/ed56f0fa-b8f2-4a68-85be-b2612c33f71e)

- Vậy khi thay đổi MCU khác chỉ cần thay đổi code lớp MCAL

</details>
<details>
  <summary><h2>BMS</h2></summary

**Battery Management System (BMS)**

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/bc58321d-96fe-41c1-90e8-386537eab2e1)
- Mục đích :Cung cấp thông tin về trạng thái pin hiện tại, bao gồm điện áp, dòng điện,  dung lượng pin thời gian sử dụng pin
- Xe điện Huyndai , hãng pin LG chem
- Pin lithium-ion polyme(lipo) có dung lượng 38.3 kWh, pin sạc đầy là 350vol
- Phần cứng:1 con MCU (PC1500) sẽ giao tiếp các cảm biến , các cảm biến xe nối với  pin để đo cảm  dòng hiện tại, điện áp hiện tại(350vol)đầy , cạn là 280v ,.Các dữ liệu này sẽ truyền qua MCU thông qua ADC,
- Nói về nhiệt độ ,khi nhiệt độ lớn hơn nhiệt độ an toàn >60 độ , thì MCU sẽ gửi 1 bit kích hoạt hệ thống làm mát ( hệ thống này gồm role và quạt)( nguồn 3.3 v kích nguồn 5 v)
- MCP3008 
- Hall Effect
- Sau khi có các dữ liệu thì ECU chính sẽ gửi ECU pin thông qua CAN , bằng mode remote farm ,và ECU pin sẽ gửi lại 1 data farm 1byte nhiệt độ ,1 byte điện áp , 1 byte dòng điện,1byte quạt, byte CRC để tính dung lượng pin và thời gian sử dụng
- Thời gian lấy mẫu là liên tục .
 



- Battery Management System là 1 ECU để quản lý pin , trên xe thì có nhiều ECU và ECU này gồm MCU+ Cảm biến đo thông số pin 
- pin lithium-ion (Li-ion) và lithium polymer (LiPo) - hai loại pin phổ biến trong các xe điện
- V pin xe điện  4 volt mỗi ô pin (cell) khi sạc đầy, 350 vol /4= 88 cell
- V pin khi xài cạn là 3 volt mỗi ô pin (cell)
- V pin tổng khi đầy là 350v(88 cell)
- V pin khi cạn là  260v


1. Công thức tính dung lượng pin và thời gian sử dụng còn lại

![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/5129f945-5a9b-45c6-94a7-345c29abb149)

	 
![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/207a7ea3-ef57-4355-a44f-1e09930a276e)

2.  Các loại cảm biến:

	- INA219  :
		+ PIN + MẠCH chia áp(sử dụng mạch chia áp với tỉ lệ 70:1.)  để giảm điện áp xuống phù hợp khoảng đo ADC(0 tới 5 v)+ INA219 + I2C MCU
		+ Cảm biến này cho phép bạn đo điện áp từ các nguồn analog và chuyển đổi chúng thành giá trị số để xử lý bởi vi điều khiển hoặc các thiết bị khác
		+ INA219  sẽ tính toán cụ thể giá trị vol rồi truyền qua MCU
		+ INA219 sử dụng một điện trở shunt (hoặc shunt resistor) để đo điện áp dòng điện qua mạch
		+ Điện áp shunt được chuyển đổi thành giá trị số thông qua bộ chuyển đổi analog-to-digital (ADC) tích hợp trong INA219
		+ Dựa vào giá trị số ADC, giá trị của shunt resistor và các thông số calibation của INA219>> Ra điện áp thực tế
		![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/f3ecd7d6-5d9b-4075-8b2d-99f5b7ed8b8e)

	- ACS756 : 
		+ Hoạt động dựa trên hiệu ứng Hal
		+ ADC đọc giá trị này và chuyển đổi thành dữ liệu số.
		+ Measured Current = Giá trị số đọc từ bộ ADC * Tỷ lệ đo
		+ `Measured Current = 512 * 10ma/A = 20.48A`
		+ khi một dòng điện đi qua một dẫn dẻo (conductor), nó tạo ra một lực từ gọi là "lực từ Hall" vuông góc với cả hai dòng điện và trường từ bên ngoài (nếu có). Cảm biến Hall được đặt gần dẫn sẽ phát hiện và đo lực từ Hall này.
		+ Dựa trên lực từ Hall phát sinh, cảm biến sẽ tạo ra một tín hiệu điện áp tương tự với dòng điện đi qua dẫn. Độ lớn của tín hiệu này tỉ lệ thuận với dòng điện đi qua cảm biến.
		+ Tín hiệu điện áp từ cảm biến Hall sau đó được chuyển đổi từ tín hiệu analog sang tín hiệu số bằng một bộ chuyển đổi analog-to-digital (ADC) tích hợp trong cảm biến hoặc được kết nối với một bộ chuyển đổi ADC ngoài.


3.  Main ECU:
	-  Main ECU giao tiếp với BSM qua CAN
	-  Main ECU sẽ gửi remote farme tới BSM , yêu cầu BSM gửi các thông số của PIN
	-  Data farm gồm các byte : 1 byte dòng , áp 
	-  Sau khi có các thông số ở BSM thì Main ECU sẽ tính toán thời gian sạc đầy , tràn pin(code )
	-  MCU trong BSM chỉ thu nhận thông số thôi








</details>
</details>

</details>

</details>


</details>
<details>
  <summary><h1>▶ ⭐RFID-RC522 </h1></summary>



**MQTT**
![image](https://github.com/user-attachments/assets/1df22b89-d581-4ddd-bfe6-ac9b6db701e9)

- MQTT  là một giao thức giao tiếp nhẹ dựa trên mô hình publish-subscribe. 
- Giao thức này cho phép các thiết bị IOT gửi và nhận các tin nhắn nhỏ và đơn giản qua mạng Internet.
- MQTT có ba thành phần chính: publisher, broker và subscriber
- Publisher là thiết bị gửi tin nhắn đến broker, 
- broker là máy chủ trung gian quản lý các tin nhắn và chuyển tiếp chúng đến subscriber,
- subscriber là thiết bị nhận tin nhắn từ broker.
- Tạo broker MQTT: sử dụng HiveMQ broker. Bạn truy cập vào website: https://www.hivemq.com/

**Blynk IOT**
- Blynk IoT là một nền tảng đơn giản, cho phép  kết nối và điều khiển các thiết bị IoT từ xa qua internet.
- Cung cấp giao diện người dùng
- Dùng  https://blynk.cloud/ 
- Tối ưu hóa hiệu suất và độ ổn định của hệ thống khi sử dụng Blynk IoT?
	+ chỉ gửi dữ liệu khi có sự kiện xảy ra (ví dụ: khi có thẻ được quẹt). 
	+ Điều này giúp giảm băng thông và tiết kiệm năng lượng.
**Zigbee**
- Cả Zigbee ều là giao thức không dây
- sử dụng băng tần 2.4 GHz (Zigbee cũng hỗ trợ các tần số khác như 868 MHz, 915 MHz).
- Tiêu thụ năng lượng thấp , dùng pin trong nhiều năm
- Tốc độ truyền dữ liệu thấp , tối da 250kb/s
- Khả năng mở rộng cao

**Về kết quả và ứng dụng thực tế**
- hệ thống được thiết kế để sẵn sàng tích hợp vào các hệ thống smart home
 
**phối hợp với các thành viên như thế nào**
1. Phân chia công việc
	+ thiết kế phần cứng, 
	+ lập trình giao tiếp cảm biến, và tôi
	+ phụ trách lập trình vi điều khiển
2. Trao đổi ý tưởng, tiến độ, và giải quyết các vấn đề phát sinh nhanh chóng.
3. Hỗ trợ các thành viên
	+ giải quyết các lỗi phần mềm hoặc tối ưu hóa giao tiếp giữa các module.

**trình bày kết quả hoặc thuyết phục khách hàng/đồng đội ra sao?**
1. Trình bày qua các bước cụ thể:
	+  Chia nhỏ kết quả thành các phần dễ hiểu như thiết kế hệ thống, mã nguồn chính, và dữ liệu thử nghiệm.
2. Sử dụng công cụ hỗ trợ:
	+ sử dụng slide PowerPoint hoặc biểu đồ để minh họa rõ ràng các quy trình và kết quả.
3. Trình bày hiệu quả của giải pháp:
	+ Độ chính xác: Tỷ lệ nhận diện thẻ RFID thành công.
	+ Tốc độ: Thời gian từ lúc quẹt thẻ đến khi cửa mở.
	+ Độ ổn định: Hệ thống hoạt động liên tục mà không xảy ra lỗi trong các thử nghiệm dài hạn.
	+ Tính mở rộng


**WIFI**
![image](https://github.com/user-attachments/assets/d2ffaa36-58f0-4434-8a0f-929f38ab2029)


**Mục tiêu chính:**
- Xây dựng một hệ thống kiểm soát truy cập an toàn, có thể giám sát và điều khiển từ xa
- sử dụng các công cụ như Trello để quản lý công việc và Git để quản lý mã nguồn.
- Tôi chọn ESP32 vì nó có tích hợp Wi-Fi
- Tôi tích hợp ESP32 với Blynk qua Wi-Fi, cho phép người dùng theo dõi trạng thái (ví dụ: cửa mở hay đóng) và điều khiển từ xa (mở cửa) thông qua ứng dụng di động.
![image](https://github.com/user-attachments/assets/d67d0c54-6c7d-4d18-a2d0-e658683103e0)


**Về vai trò và đóng góp**
- Tôi là người thiết kế hệ thống, ựa chọn linh kiện, đến lập trình các thành phần chính. 
- Tôi đảm nhận việc lập trình ESP32 để giao tiếp với RFID RC522 qua giao thức SPI, xử lý dữ liệu trên SDCARD, và điều khiển servo motor. 
- Ngoài ra, tôi  tích hợp hệ thống với nền tảng Blynk IoT để hỗ trợ giám sát và điều khiển từ xa.

**Làm thế nào  quản lý kết nối, lập trình các cảm biến, đặc biệt là giao tiếp SPI trong dự án này?**
1. phần cứng:
	- Đảm bảo các chân SPI (MISO, MOSI, SCK, CS) của ESP32 được kết nối đúng với RC522 và SDCARD.
2. Lập trình  SPI:
	- Sử dụng thư viện SPI có sẵn.
	- Đảm bảo cấu hình đúng các thông số SPI ( tốc độ, chế độ)
3. Quản lý đa thiết bị trên cùng bus SPI:
	- Sử dụng chân Chip Select (CS) để chọn thiết bị . 
	- Khi làm việc với RC522, chân CS của SDCARD sẽ được đặt ở trạng thái không hoạt động, và ngược lại.
4. Xử lý dữ liệu:
	- Tôi viết hàm đọc và ghi dữ liệu qua SPI, sau đó tích hợp với logic hệ thống.
	- Ví dụ, đọc thẻ RFID từ RC522 và kiểm tra dữ liệu với thông tin lưu trên SDCARD.

**giải quyết những thách thức**
1. Xung đột t khi kết nối nhiều thiết bị:
	+ Quản lý chân (CS) Mđảm bảo chỉ một thiết bị được kích hoạt tại một thời điểm. 
	+ Giảm tốc độ xung nhịp SPI nếu có vấn đề tín hiệu.
2. Độ trễ khi đọc dữ liệu từ SDCARD:
	+ truy xuất dữ liệu bị chậm, ảnh hưởng đến hiệu suất tổng thể.
	+ Tối ưu hóa mã lập trình bằng cách giảm kích thước  dữ liệu đọc/ghi
3. Khả năng mất ổn định của servo motor
	+ hệ thống gặp hiện tượng nhiễu tín hiệu PWM, khiến motor hoạt động không chính xác.
	+ Sử dụng PWM với tần số phù hợp hơn
	+ Cấp nguồn riêng cho servo để tránh nhiễu từ các thành phần khác.
4. Tích hợp Blynk IoT:
	+ Gặp khó khăn khi đường truyền Wi-Fi không ổn định.
	+ Lưu trữ tạm thời dữ liệu gửi đi, đảm bảo khi kết nối Wi-Fi khôi phục, dữ liệu sẽ được gửi mà không mất mát.
5. Tại sao lại chọn ESP32
	+ Có Wi-Fi tích hợp sẵn, giúp tôi dễ dàng thêm tính năng IoT vào hệ thống.



**Servo Motor**
- Chu kỳ PWM phổ biến: 20ms (50 Hz).
- Chiều rộng xung (duty cycle) quyết định góc quay của trục:
	- 1ms (hoặc 5%): Góc 0°.
	- 1.5ms (hoặc 7.5%): Góc 90° (vị trí trung tâm).
	- 2ms (hoặc 10%): Góc 180°.
- 3 chân: Nguồn , đất , PWM



**Vấn đề bảo mật**
- AES là một thuật toán mã hóa được sử dụng để   bảo mật dữ liệu
- Thuật toán hoạt động bằng cách chia dữ liệu thành các khối 128-bit và mã hóa chúng thông qua một chuỗi các vòng (rounds) chuyển đổi dữ liệu dựa trên khóa.
- ESP32:Tích hợp phần cứng hỗ trợ AES-128.
- Sử dụng thư viện được cung cấp bởi SDK (ESP-IDF)

1. Mã hóa dữ liệu khi truyền giữa ESP32 và các thiết bị ngoại vi qua giao thức SPI.
- Sử dụng các thuật toán mã hóa như AES-128
2. Bảo mật kết nối IoT (ESP32 - Blynk IoT)
- Cấu hình ESP32 kết nối Wi-Fi với WPA2 hoặc WPA3
- Xác thực hai lớp (2FA): Tích hợp xác thực hai lớp cho ứng dụng Blynk
3. Bảo mật dữ liệu lưu trữ trên SD Card
- Dữ liệu ID thẻ RFID trên SD Card cần được mã hóa bằng AES
4. Bảo mật xác thực RFID
- Áp dụng rolling code: Mỗi lần quẹt thẻ, hệ thống và thẻ sẽ đồng bộ một mã xác thực mới.
5. Bảo mật phần cứng : Bảo vệ vật lý

**Vấn đề về Thẻ nhớ SDCARD trong Dự án**
1. Kiểm tra Dung lượng Thẻ nhớ SDCARD:
- Theo dõi dung lượng lưu trữ: Vi điều khiển STM32 có thể được lập trình để theo dõi dung lượng trống trên thẻ nhớ SDCARD.
- Cách thức thực hiện:
	+ Sử dụng các hàm để lấy thông tin dung lượng thẻ nhớ (ví dụ: hàm f_getfree trong FATFS library cho hệ thống file FAT).
	+ So sánh dung lượng trống với một ngưỡng nhất định (ví dụ: 10% dung lượng thẻ nhớ) để cảnh báo khi sắp đầy.
	+ Gửi cảnh báo qua giao diện người dùng hoặc đèn LED khi dung lượng sắp đầy.
2. Kiểm tra Thẻ nhớ SDCARD Bị Hỏng
- Kiểm tra lỗi đọc/ghi: Vi điều khiển có thể thực hiện kiểm tra định kỳ các lỗi đọc/ghi trên thẻ nhớ.
- Cách thức thực hiện:
	+ Kiểm tra mã trả về của các hàm đọc/ghi (ví dụ: f_read, f_write trong FATFS).
    +  Nếu mã trả về là lỗi (ví dụ: FR_DISK_ERR, FR_NOT_READY), có thể thẻ nhớ đã bị hỏng hoặc gặp vấn đề.
3. Các loại định dạng thẻ nhớ
	+ FAT32:Hỗ trợ dung lượng thẻ nhớ lên đến 2 TB.với khả năng tương thích cao trên nhiều thiết bị.
	+ NTFS: Tốt cho các thiết bị lưu trữ cần các tính năng bảo mật và quản lý tệp tin nâng cao, nhưng không phổ biến trên các thiết bị di động.
4. Tại sao Không Sử dụng Định dạng NTFS cho Dự án Nhúng
	+ phức tạp: NTFS là một hệ thống tập tin phức tạp với nhiều tính năng nâng cao như quyền truy cập, mã hóa. Sự phức tạp này đòi hỏi nhiều tài nguyên hệ thống để quản lý.
	+ Tài nguyên yêu cầu cao: NTFS yêu cầu bộ nhớ RAM và ROM lớn để lưu trữ và quản lý các cấu trúc dữ liệu phức tạp. Các vi điều khiển như STM32 thường có tài nguyên giới hạn, do đó việc sử dụng NTFS không khả thi.
	+ Hỗ trợ hạn chế trên vi điều khiển: Không có nhiều thư viện mã nguồn mở hoặc các thư viện được hỗ trợ tốt cho NTFS trên vi điều khiển. Ngược lại, FATFS là một thư viện phổ biến và đã được kiểm chứng trên nhiều nền tảng nhúng.
	+ Đơn giản và hiệu quả: FAT32 có cấu trúc đơn giản, dễ triển khai và tối ưu cho các hệ thống nhúng với tài nguyên hạn chế.
5. Cấu trúc của FAT32:
	+ Ưu Điểm:
		+ Đơn Giản và Phổ Biến: FAT32 được hỗ trợ rộng rãi trên nhiều hệ điều hành và thiết bị.
		+ Hiệu Năng Cao: Đơn giản và nhẹ, phù hợp cho các thiết bị lưu trữ nhỏ và các ứng dụng không đòi hỏi hiệu năng cao.
	+ Nhược Điểm:
		+ Giới Hạn Kích Thước Tập Tin: Kích thước tối đa của một tập tin trong FAT32 là 4 GB.
		+ Giới Hạn Kích Thước Phân Vùng: Kích thước tối đa của phân vùng FAT32 là 2 TB.
		+ Bảo Mật và Quản Lý Phân Quyền: Không hỗ trợ tính năng bảo mật và quản lý phân quyền như các hệ thống tập tin hiện đại khác.
6. Thư viện FATFS
	+ lấy thư viện này từ trang web chính thức của dự án ChaN
7. Tính bảo mật :
	+ Giới Hạn Quyền Truy Cập: Thiết lập các chính sách bảo mật để giới hạn quyền truy cập vào thẻ nhớ.
	+ Sử dụng AES: Để mã hóa và giải mã dữ liệu thẻ RFID.
	+ Thẻ Nhớ 1 (SD1):
		+ Lưu Trữ Khóa AES: Khóa AES được mã hóa trước khi lưu.
		+ Log Backup: Bản sao lưu log, giúp khôi phục nếu cần.
		+ Dữ Liệu Thẻ Backup: Bản sao lưu dữ liệu thẻ (đã mã hóa).
		+ Thẻ Nhớ 2 (SD2):
		+ Log File: Lưu trữ log hoạt động hàng ngày.
		+ Dữ Liệu Thẻ Mã Hóa: Lưu trữ dữ liệu thẻ đã mã hóa.
	+ STM32:   lấy và lưu trữ khóa AES, mã hóa/giải mã dữ liệu thẻ RFID, và cập nhật file log.
8. TinyAES là một thư viện mã hóa nhẹ dành cho ngôn ngữ lập trình C, sử dụng thuật toán Advanced Encryption Standard (AES)
	+ Các đặc điểm chính của TinyAES:
	+ Nhỏ gọn và nhẹ: Thư viện này được thiết kế để chiếm ít bộ nhớ và tài nguyên hệ thống.
	+ Dễ dàng tích hợp: TinyAES có thể được tích hợp dễ dàng vào các dự án C/C++ mà không cần phải cài đặt các thư viện bên ngoài phức tạp.
	+ Hỗ trợ nhiều chế độ mã hóa: TinyAES hỗ trợ các chế độ mã hóa AES-128, AES-192, và AES-256.
	+ An toàn: Thuật toán AES được đánh giá cao về độ an toàn và được sử dụng rộng rãi trong các ứng dụng bảo mật.

9. Cơ Chế Của AES :
	+ AES (Advanced Encryption Standard) là một thuật toán mã hóa khối đối xứng được sử dụng rộng rãi để bảo mật dữ liệu. Đây là thuật toán mã hóa tiêu chuẩn do Viện Tiêu chuẩn và Công nghệ Quốc gia Mỹ (NIST) chọn vào năm 2001.
	+ Các Thành Phần Chính Của AES
		+ Khối Dữ Liệu: AES mã hóa dữ liệu theo các khối có kích thước cố định là 128 bit (16 byte).
		+ Khóa Mã Hóa: AES sử dụng các khóa mã hóa có độ dài 128, 192, hoặc 256 bit.
10. Độ Dài Khóa
	+ AES-128: Sử dụng khóa dài 128 bit (16 byte).có 10 vòng lặp
	+ AES-192: Sử dụng khóa dài 192 bit (24 byte).Có 12 vòng lặp.
	+ AES-256: Sử dụng khóa dài 256 bit (32 byte).Có 14 vòng lặp.
14. AES-128 là lựa chọn hợp lý nhất:
	+  Bảo Mật Đủ: AES-128 cung cấp mức độ bảo mật đủ cao cho hầu hết các ứng dụng, bao gồm cả kiểm soát truy cập.
	+  Hiệu Suất Cao: Tốc độ xử lý nhanh, đảm bảo thời gian phản hồi nhanh chóng khi quét thẻ RFID.
	+  Tiêu Tốn Ít Tài Nguyên: Giúp tiết kiệm tài nguyên của ESP32, để nó có thể thực hiện các tác vụ khác một cách hiệu quả.
15. Chuyển Khóa AES Sang Chuỗi Hex Để Gửi Lên Trang Web
	+ Khi gửi dữ liệu nhị phân (binary data) như khóa AES lên các dịch vụ web hoặc API, việc chuyển đổi dữ liệu thành chuỗi hex (hexadecimal string) là cần thiết vì các giao thức HTTP/HTTPS không hỗ trợ tốt cho dữ liệu nhị phân trực tiếp.
16. Nhược Điểm Của ThingSpeak
	+ Giới Hạn Dung Lượng:Tài khoản miễn phí có giới hạn về dung lượng và tần suất gửi dữ liệu, có thể không phù hợp cho các dự án lớn.
	+ Số Lượng Tin Nhắn:Tài khoản miễn phí cho phép gửi tối đa 3 triệu tin nhắn mỗi năm. Mỗi lần gửi dữ liệu lên ThingSpeak được tính là một tin nhắn.
	+ Tần Suất Gửi Dữ Liệu:Tài khoản miễn phí cho phép gửi dữ liệu với tần suất tối đa là 15 giây/lần. Điều này có nghĩa là bạn có thể gửi dữ liệu lên ThingSpeak mỗi 15 giây cho mỗi kênh.
17. RC522 và Các Loại Thẻ RFID
	+ Thẻ RFID HF (High Frequency):
	+ Tần số: 13.56 MHz.
	+ Khoảng cách đọc: Thường từ 1 cm đến 10 cm.
	+ Chuẩn: ISO 14443A (MIFARE), ISO 15693.
	+ Ứng dụng: Thẻ NFC, thẻ thanh toán không tiếp xúc, thẻ giao thông.
18.	Hoạt Động của RC522 Khi Không Có Thẻ 
	+ RC522 chờ lệnh: Khi không có thẻ trong phạm vi quét, RC522 sẽ không làm gì và chỉ chờ lệnh tiếp theo từ VĐK.
	+ Lập trình kiểm tra chu kỳ: VĐK kiểm tra thẻ theo chu kỳ đã lập trình (ví dụ: mỗi 500 ms) để tối ưu hóa tài nguyên và năng lượng.
	+ Không tiêu tốn tài nguyên khi không có thẻ: RC522 không thực hiện hành động nào, giúp tiết kiệm tài nguyên hệ thống.
	+ RC522 phát hiện thẻ bằng cách kiểm tra sự thay đổi từ trường khi thẻ RFID nằm trong phạm vi.RC522 có một cuộn dây phát tín hiệu từ trường và một mạch nhận để cảm nhận sự thay đổi từ trường.
	+ Nhận Phản Hồi: RC522 kiểm tra sự hiện diện của thẻ và phản hồi lại VĐK qua SPI.
	+ Đọc UID Thẻ: Nếu có thẻ, VĐK sẽ gửi tiếp lệnh PICC_ReadCardSerial() để đọc UID của thẻ.
19. Giám Sát Truy Cập Thẻ SD Bằng Ngắt Ngoài:
	+ Khởi Động Hệ Thống Với Timer: Sử dụng timer để cho phép lấy khóa AES từ thẻ SD1 trong khoảng thời gian nhất định (ví dụ: 1 giây).
	+ Để giám sát truy cập vào thẻ SD và đảm bảo tính bảo mật, bạn có thể sử dụng ngắt ngoài (external interrupt) để theo dõi trạng thái của thẻ SD. Cụ thể, bạn có thể giám sát các sự kiện sau:
	+ Thẻ Bị Tháo Ra hoặc Lắp Vào:
	+ Phát hiện khi thẻ SD bị tháo ra hoặc lắp vào để ngăn chặn truy cập trái phép.
	+ Truy Cập Thẻ Ngoài Khoảng Thời Gian Cho Phép:
	+ Phát hiện khi có truy cập vào thẻ SD ngoài khoảng thời gian cho phép (ví dụ: sau khoảng thời gian 1 giây ban đầu để lấy khóa).
	+ Cách Thực Hiện
		+ Sử Dụng Chân GPIO Để Giám Sát Trạng Thái Thẻ SD:
		+ Sử dụng chân GPIO của STM32 để kết nối với chân phát hiện thẻ SD (card detect pin) trên khe cắm thẻ SD.
		+ Cấu Hình Ngắt Ngoài (EXTI):
		+ Cấu hình ngắt ngoài trên chân GPIO được kết nối với chân phát hiện thẻ SD để phát hiện khi thẻ bị tháo ra hoặc lắp vào.
	+ Khởi Động Lại Hệ Thống: Khi phát hiện truy cập trái phép, hệ thống sẽ gửi cảnh báo và khởi động lại để đảm bảo an toàn.
20. Phát Hiện Thẻ SD Bị Tháo Rời hoặc Lắp Vào trên STM32:
	+  STM32 có thể phát hiện khi thẻ SD bị tháo rời hoặc lắp vào, bạn cần sử dụng một chân GPIO được cấu hình để nhận tín hiệu từ chân "Card Detect" (CD) của khe cắm thẻ SD. Khi thẻ SD được lắp vào hoặc tháo ra, chân CD sẽ thay đổi trạng thái, từ đó kích hoạt ngắt ngoài (external interrupt) trên STM32 để xử lý sự kiện.




	
</details>
</details>


</details>
<details>
  <summary><h1>▶ Linux 2024 </h1></summary>

**Những cài đặt cần thiết**

- Giao thức SFTP
- Các bước cài chương trình:VS code
![image](https://github.com/user-attachments/assets/3a5bbd8a-d75a-44aa-a464-6bf62de0944d)
- Tạo 1 foder remote trên máy thật 
- Sau đó add foder này vào work space
![image](https://github.com/user-attachments/assets/4ef2741c-38ba-4cd4-aa08-ea7d7d10c7eb)
- Sau đó bấm ctrl+ shift +p, chọn SFTP
- Setup như trong ảnh
![image](https://github.com/user-attachments/assets/3d410ffb-7f5b-4691-b3e9-4b7e2170d55e)
- Cách fix cannot edit  ..
![image](https://github.com/user-attachments/assets/a86cc93f-040f-41b5-9d86-53a90d5701e7)

- Giao thức SSH: Dùng moba xtearm
![image](https://github.com/user-attachments/assets/bbe9e9bb-32e9-4ab5-9bde-f7ee364a7b7c)


**Cấu trúc MakeFile**
![image](https://github.com/user-attachments/assets/701e4254-2c3a-4aa8-9ac1-9e530e06d8be)
+ hello.c  main.c  là điều kiện , nếu trong thư mục không có 2 file này thì bị lỗi
+ Action phải lùi 1 tab vào
 





**1 số lệnh trên linux**
1. Lệnh kiểm tra IP máy ảo: `ifconfig`
2. Tạo 1 file : ví dụ `touch main.c`
3. Hiển thị danh sách các tệp và thư mục:`ls -l`
4. hiển thị nội dung của một hoặc nhiều tệp:`cat main.c`
5. Khi  mở một tập tin bằng vim và muốn chỉnh sửa code:
	+ Nhấn i để vào chế độ chèn (Insert mode).
```C
#include <stdio.h>
	int main()
	{
		printf("Hello World!\n"); // Sửa lỗi thiếu dấu chấm than và xuống dòng
		return 0;
	}
```
+ Nhấn Esc để thoát chế độ chèn.
+ Gõ :wq và nhấn Enter để lưu và thoát.
6. Lệnh biên dịch 1 chương trình :`gcc -o main main.c`
7. Lệnh chạy 1 file:`./main`





**Static library và  shared library**

- Thư viện là một tập hợp các đoạn mã được biên dịch sẵn để tái sử sụng.Có 2 loại
- Static library :Static library là loại thư viện mà mã nguồn của nó được liên kết trực tiếp vào file thực thi (executable) tại thời điểm biên dịch.
- Thời điểm biên dịch là quá trình chuyển mã nguồn sang mã máy 
- Đặc điểm:
	+ Khi chương trình được biên dịch, toàn bộ nội dung của thư viện tĩnh được sao chép và gắn trực tiếp vào file thực thi. Do đó, file thực thi chứa tất cả các mã cần thiết để chạy mà không phụ thuộc vào các thư viện bên ngoài khi thực thi.
	+ File thư viện tĩnh có đuôi mở rộng là .a (trên Unix/Linux) hoặc .lib (trên Windows).
- Ví dụ: libmylib.a.
- Ưu điểm:
	+ Không phụ thuộc vào môi trường bên ngoài: Khi chương trình đã được biên dịch, nó không cần thư viện tĩnh để chạy, vì mã đã được nhúng vào trong file thực thi.
	+ Chạy nhanh hơn vì không cần tìm và tải thư viện bên ngoài trong lúc chạy.
- Nhược điểm:
+ Kích thước file thực thi lớn: Do mã của thư viện được sao chép vào file thực thi, kích thước của file thực thi sẽ tăng lên đáng kể.
+ Mỗi khi thư viện thay đổi, bạn cần biên dịch lại toàn bộ chương trình để áp dụng thay đổi.
	

- Shared library(dynamic) là loại thư viện mà mã nguồn của nó được liên kết vào chương trình tại thời điểm chạy (runtime), thay vì thời điểm biên dịch.
	+ Thời điểm chạy là  chương trình đã được biên dịch thành công (tạo ra file thực thi)
- Đặc điểm:
	+ Thư viện dùng chung không được gắn trực tiếp vào file thực thi. Thay vào đó, file thực thi chứa các liên kết đến thư viện và khi chương trình chạy, hệ điều hành sẽ tải thư viện này vào bộ nhớ.
	+ File thư viện dùng chung có đuôi mở rộng là .so (trên Unix/Linux) hoặc .dll (trên Windows).

- Ưu điểm:
	+ Kích thước file thực thi nhỏ hơn: Vì thư viện không được sao chép vào file thực thi, kích thước của file thực thi sẽ nhỏ hơn.
	+ Tiết kiệm bộ nhớ: Nhiều chương trình có thể dùng chung một thư viện, và hệ điều hành chỉ cần tải một bản của thư viện vào bộ nhớ.
	+ Dễ bảo trì và nâng cấp: Bạn chỉ cần cập nhật phiên bản của thư viện và tất cả các chương trình sử dụng nó sẽ tự động được cập nhật theo mà không cần phải biên dịch lại.
- Nhược điểm:
	+ Phụ thuộc vào môi trường: Chương trình cần thư viện phải tồn tại và được đặt đúng chỗ trên hệ thống khi chương trình chạy, nếu không chương trình sẽ không thể chạy được.
	+ Tốc độ chạy có thể chậm hơn: Vì hệ điều hành cần tải thư viện vào bộ nhớ khi chương trình chạy.
![image](https://github.com/user-attachments/assets/ae643c48-1158-44cc-9115-51d72a943c96)


**Chú ý**
- Ví dụ file stdio.h ,time.h.... không phải là 1 thư viện mà là file header 
- chứa các khai báo.Nó không chứa định nghĩa (definitions)(chính là mã thực thi)  do đó không phải là một thư viện (static hay shared).
- file header không chứa mã thực thi mà chỉ chứa các khai báo để trình biên dịch biết về các hàm và biến khi bạn sử dụng chúng trong mã nguồn của mình.
- Khi bạn sử dụng #include <stdio.h>, bạn đang chỉ định cho trình biên dịch tìm các khai báo cần thiết để sử dụng các hàm như printf, scanf, fopen,... Những khai báo này nằm trong file stdio.h.
- stdio.h không thuộc static library hay shared library, nhưng nó là cầu nối để các hàm từ những thư viện này có thể được sử dụng trong chương trình của bạn.
- Tổng quan các thành phần chứa trong cả static và shared library:
- Mã máy:
- Được biên dịch từ mã nguồn C/C++ và lưu dưới dạng mã nhị phân. 
- Bảng ký hiệu (Symbol Table):
	+ Chứa tên của các hàm, biến, và đối tượng khác trong thư viện. Đây là nơi trình biên dịch tìm kiếm khi chương trình gọi đến một hàm hay biến trong thư viện.
	+ Trong static library, bảng này giúp trình liên kết biết những gì cần sao chép vào file thực thi.
	+ Trong shared library, bảng này giúp hệ điều hành biết cách kết nối các hàm tại thời điểm chạy.
- Relocation Information (chỉ có trong shared library):
	+ Thông tin về cách điều chỉnh địa chỉ bộ nhớ khi thư viện được tải vào chương trình. Vì shared library được tải vào địa chỉ bộ nhớ khác nhau trong các chương trình khác nhau, cần có thông tin điều chỉnh để hàm trong thư viện hoạt động chính xác.
Metadata:
+ phiên bản của thư viện, kiến trúc CPU  (ví dụ: x86, ARM) ..
- Ví dụ:
Giả sử bạn có một thư viện (static hoặc shared) chứa các hàm toán học như add, subtract, multiply, và divide. Cả static và shared library sẽ chứa mã nhị phân đã được biên dịch của các hàm này, cùng với các thông tin cần thiết để trình biên dịch hoặc hệ điều hành có thể sử dụng lại chúng mà không cần phải viết lại từ đầu.Khi sử dụng static library, mã nhị phân của các hàm sẽ được sao chép vào chương trình, trong khi với shared library, các hàm sẽ được tải vào bộ nhớ khi chương trình thực thi.


**Cách tạo static and sharelib**
- Link :[text](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index)
- Cấu tạo 1 project cơ bản:
	+ mkdir inc // chưa file.h
	+ mkdir src // chưa file.c
	+ touch main.c
	+ touch Makefile
	+ touch bin // chứa chương trình thực thi
	+ mkdir -p libs/static   // chứa chương trình thư viện
	+ mkdir -p libs/shared
	+ mkdir obj // chưa file.o
	+ tree   // sẽ thấy cấu trúc

- Các file mã cần thiết

<details>
<summary>Mã nguồn:</summary>
1.main.c

```c
#include <stdio.h>
 
void main()
{
	helloworld();
	hellothai();




}


```
2.hello_thai.h

```c
#include <stdio.h>
void hellothai();

```
3.hello_thai.c

```c
#include <stdio.h>
void hellothai()
{
	printf("hello thai\n");



}

```
4.hello_word.h

```c
#include <stdio.h>
void helloword();
 

```
5.hello_word.c

```c
#include <stdio.h>
void helloword()
{
	printf("hello word\n");



}

```

</details>


**Viết Makefile**

<details>
<summary>Makefile</summary>

```C
	.PHONY:
	CUR_DIR := .
	INC_DIR := $(CUR_DIR)/inc
	SRC_DIR := $(CUR_DIR)/src
	OBJ_DIR := $(CUR_DIR)/obj
	BIN_DIR := $(CUR_DIR)/bin
	LIB_NAME := hello
	LIBS_DIR := $(CUR_DIR)/libs
	LIBS_STATIC_DIR := $(LIBS_DIR)/static
	LIBS_SHARED_DIR := $(LIBS_DIR)/shared

	# Create the object files
	share_objs:
		gcc -c -o  $(OBJ_DIR)/main.o main.c -I $(INC_DIR)
		gcc -c -fPIC -o $(OBJ_DIR)/hello_thai.o $(SRC_DIR)/hello_thai.c 
		gcc -c -fPIC -o $(OBJ_DIR)/hello_thai.o $(SRC_DIR)/hello_world.c 

	# Create the shared library
	create_shared_lib:
		gcc -shared $(OBJ_DIR)/hello_thai.o  $(OBJ_DIR)/hello_thai.o -o $(LIBS_SHARED_DIR)/lib$(LIB_NAME).so

	# Link dynamically	
	link_shared_lib:
		gcc  $(OBJ_DIR)n/main.o -L$(LIBS_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-library

	install_shared_lib:
		install $(LIBS_SHARED_DIR)/lib$(LIB_NAME).so /usr/lib
	all: share_objs create_shared_lib link_shared_lib install_shared_lib
		@echo "make all target"
	clean:
		rm -rf $(OBJ_DIR)/*.o
		rm -rf $(LIBS_SHARED_DIR)/lib$(LIB_NAME).so
		rm -rf $(BIN_DIR)/use-shared-library



```

- tới đây thì chạy make install_shared_lib, nhưng không chạy dc , vì đang là user bình thường nên dùng sudo make install_shared_lib

![image](https://github.com/user-attachments/assets/5475df32-ac70-43f9-9d80-6dca46f4b5a7)

- Chạy tiếp ./bin/use -shared- library
![image](https://github.com/user-attachments/assets/4cab69e2-dfcb-4019-bbf1-816dab557e10)
- Gõ tree
![image](https://github.com/user-attachments/assets/08d0c69b-c759-4791-9026-1bedf7d37477)
- sudo make all
![image](https://github.com/user-attachments/assets/c6053863-45ae-4943-9a35-4a3cf2ed4735)

</details>


**Tổng quan về file trên linux**
![image](https://github.com/user-attachments/assets/47fbaaad-1838-4bfc-98f8-cf14a2ec1ad9)

- Cách thêm quyền cho 1 file:
- Ví dụ file A.TXT
![image](https://github.com/user-attachments/assets/b69ffe9b-10c2-4cd2-80de-ee2284cce596)
![image](https://github.com/user-attachments/assets/602eeae1-8ed1-468a-b1f6-b5afecefe933)
- Dùng lệnh `sudo chmod 0642 A.txt` sau đó `ls -l`
![image](https://github.com/user-attachments/assets/fc2ee822-84bb-4792-b162-d2e6763fabc3)
![image](https://github.com/user-attachments/assets/252093de-a363-47ab-be6c-9b735ced15d3)

- Đổi user bằng lệnh `sudo chown slayer:slayer A.txt`
![image](https://github.com/user-attachments/assets/30b948de-9372-4643-897f-f40c6d862029)

**Thao tác file trên linux**
- Chương trình

```C
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
    int fd;
    int numb_read, numb_write;
    char buf[12] = "hello world\n";

    // assume foobar.txt is already created
    fd = open("hello.txt", O_RDWR | O_CREAT, 0667);
    if (-1 == fd) {
        printf("open() hello.txt failed\n");
    }

    numb_write = write(fd, buf, strlen(buf));
    printf("Write %d bytes to hello.txt\n", numb_write);

    lseek(fd, 2, SEEK_SET);
    write(fd, "AAAAAAAAAA", strlen("AAAAAAAAAA"));

    close(fd);

    return 0;
}

```

- Trang web chính để tìm hiểu các hàm:
[text](https://man7.org/linux/man-pages/man2/open.2.html)
1. open()
` int open(const char *pathname, int flags, ... /* mode_t mode */ );`
` fd = open("hello.txt", O_RDWR | O_CREAT, 0667);`
- O_RDWR: Đây là cờ chỉ định rằng tệp tin sẽ được mở với quyền đọc và ghi (Read and Write).
- O_CREAT: Đây là cờ tạo tệp tin nếu tệp tin chưa tồn tại.
- Câu lệnh này sẽ cố gắng mở tệp tin "hello.txt" với quyền đọc/ghi. Nếu tệp tin chưa tồn tại, nó sẽ được tạo với quyền truy cập là 0667 (đọc và ghi cho chủ sở hữu và nhóm, và đọc, ghi, thực thi cho người khác). Nếu quá trình mở tệp không thành công (ví dụ, tệp tin không thể mở được do không có quyền), hàm open() sẽ trả về -1.

- Hàm open() trả về một giá trị đại diện cho "file descriptor" (fd), một chỉ số nguyên không âm đại diện cho tệp tin đã được mở thành công. Tệp tin này có thể được sử dụng trong các thao tác tiếp theo như đọc (read), ghi (write), hoặc đóng (close).
















**Các khái niệm cơ bản**
- Kernel:sẽ có nhiệm vụ quản lý nhiều task cùng chạy 1 lúc, mỗi task thường chạy mất vài ms.Tại lúc kết thúc task thường:
	+ Lưu trạng thái task
	+ Thanh ghi CPU sẽ load trạng thái của task tiếp theo
	+ Task tiếp theo cần khoảng vài ms để thực hiện
	![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/de11d2ab-fb6e-4ae8-ae02-76cd45e10145)
- Task state(trạng thái):
	+ RUNNING: đang thực thi
	+ READY: sẵn sàng để thực hiện
	+ WAITING: chờ sự kiện
	+ INACTIVE: không được kích hoạt
	![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/12fc80ad-18bf-401e-884d-f1e86a1272d4)

- Scheduler:
	+ Cooperative: giống với lập trình thông thường, mỗi task chỉ có thể thực thi khi task đang chạy dừng lại, nhược điểm của nó là task này có thể dùng hết tất cả tài nguyên của CPU
	+ Round-robin: mỗi task được thực hiện trong thời gian định trước (time slice) và không có ưu tiên.
	![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/68628bc9-adb3-4c2b-96a8-fbcc45c60297)
	+ Priority base: Task được phân quyền cao nhất sẽ được thực hiện trước, nếu các task có cùng quyền như nhau thì sẽ giống với round-robin, các task có mức ưu tiên thấp hơn sẽ được thực hiện cho đến cuối time slice
	![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/d49c15ad-7bbe-4aad-932b-0885274b1a3a)
	+ Task A chờ event
	+ Task B chờ event
	+ Task B event sẵn sàng
	+ Task A event sẵn sàng
	+ Priority-based pre-emptive: Các task có mức ưu tiên cao nhất luôn nhường các task có mức ưu tiên thấp hơn thực thi trước.
	![image](https://github.com/khokhanptv/Embedded-Software_2023/assets/136571945/0508619c-f7d1-415f-8900-5d4da44898ed)

	+ Task A chờ event
	+ Task B chờ event
	+ Task B event sẵn sàng
	+ Task A event sẵn sàng

- Task:
	+ Một task là một chương trình, chương trình này chạy liên tục trong vòng lặp vô tận và không bao giờ dừng lại. Với mỗi task thì có niềm tin duy nhất là chỉ mình nó đang chạy và có thể sử dụng hết nguồn tài nguyên sẵn có của bộ xử lý (mặc dù là thực tế thì nó vẫn phải chia sẻ nguồn tài nguyên này với các task khác).

	+ Một chương trình thường sẽ có nhiều task khác nhau. Ví dụ như máy bán đồ uống tự động sẽ có các thành task sau

	+ Task quản lý việc lựa chọn của người dùng
	Task để kiểm tra đúng số tiền người dùng đã trả
	Task để điều khiển động cơ/ cơ cấu cung cấp nước uống.
	Kernel sẽ quản lý việc chuyển đổi giữa các task, nó sẽ lưu lại ngữ cảnh của task sắp bị hủy và khôi phục lại ngữ cảnh của task tiếp theo bằng cách:

	+ Kiểm tra thời gian thực thi đã được định nghĩa trước (time slice được tạo ra bởi ngắt systick)
	Khi có các sự kiện unblocking một task có quyền cao hơn xảy ra (signal, queue, semaphore,…)
	Khi task gọi hàm Yield() để ép Kernel chuyển sang các task khác mà không phải chờ cho hết time slice
	Khi khởi động thì kernel sẽ tạo ra một task mặc định gọi là Idle Task.

	+ Để tạo một task thì cần phải khai báo hàm định nghĩa task, sau đó tạo task và cấp phát bộ nhớ, phần này mình sẽ nói sau.
- Kết nối Inter-task & Chia sẻ tài nguyên:
	- Các task cần phải kết nối và trao đổi dữ liệu với nhau để có thể chia sẻ tài nguyên, có một số khái niệm cần lưu ý
	- Với Inter-task Communication:
		+ Signal Events – Đồng bộ các task
		+ Message queue – Trao đổi tin nhắn giữa các task trong hoạt động giống như FIFO
		+ Mail queue – Trao đổi dữ liệu giữa các task sử dụng hằng đợi của khối bộ nhớ
	- Với Resource Sharing
		+ Semaphores – Truy xuất tài nguyên liên tục từ các task khác nhau
		+ Mutex – Đồng bộ hóa truy cập tài nguyên sử dụng Mutual Exclusion
- Signal event:
	- Signal event được dùng để đồng bộ các task, task 1 phải hoàn thành điều kiện rồi mới tới task 2
- Message queue:
    - Message queue là cơ chế cho phép các task có thể kết nối với nhau, nó là một FIFO buffer được định nghĩa bởi độ dài (số phần tử mà buffer có thể lưu trữ) và kích thước dữ liệu (kích thước của các thành phần trong buffer)
- Mail queue:
	- Giống như message queue nhưng dũ liệu sẽ được truyền dưới dạng khối(memory block) thay vì dạng đơn. Mỗi memory block thì cần phải cấp phát trước khi đưa dữ liệu vào và giải phóng sau khi đưa dữ liệu ra.

- Semaphore
	- Được sử dụng để đồng bộ task với các sự kiện khác trong hệ thống. Có 2 loại

		- Binary semaphore
			+ Trường hợp đặc biệt của counting semaphore
			+ Có duy nhất 1 token
			+ Chỉ có 1 hoạt động đồng bộ 
		- Counting semaphore
			+ Có nhiều token
			+ Có nhiều hoạt động đồng bộ
- Mutex:
	+ Sử dụng cho việc loại trừ (mutial exclution), hoạt động như là một token để bảo vệ tài nguyên được chia sẻ. Một task nếu muốn truy cập vào tài nguyên chia sẻ
		+ Cần yêu cầu (đợi) mutex trước khi truy cập vào tài nguyên chia sẻ
		+ Đưa ra token khi kết thúc với tài nguyên.
	+ Tại mỗi một thời điểm thì chỉ có 1 task có được mutex.




</details>
</details>

</details>
<<<<<<< HEAD
=======
<details>
  <summary><h1>▶ ⭐OpenWrt</h1></summary>

# 🚀 Giới thiệu về OpenWrt và Hướng dẫn phát triển ứng dụng Web trên Router TP-Link

**OpenWrt** là một hệ điều hành được thiết kế chủ yếu cho các router (bộ định tuyến mạng) và thiết bị nhúng. Nó thay thế firmware mặc định của thiết bị như TP-Link, Tenda, Linksys... nhằm tăng tính **linh hoạt**, **hiệu suất** và **khả năng tùy chỉnh**.

---

## 1. 🌟 Đặc điểm nổi bật của OpenWrt

- Dựa trên Linux, nhẹ và tối ưu cho phần cứng hạn chế.
- Hỗ trợ cài thêm gói phần mềm (giống `apt` trên Ubuntu, dùng `opkg`).
- Cấu hình mạnh qua dòng lệnh (SSH) và có giao diện web thân thiện (**LuCI**).

---

## 2. 🧠 Sử dụng C++ trong OpenWrt

- OpenWrt hỗ trợ chạy chương trình viết bằng **C hoặc C++**.
- Các ứng dụng/tiện ích mạng có thể viết bằng C++, sau đó **cross-compile** để chạy trên router.

---

## 3. 🌐 Giao diện quản lý web (LuCI)

- **LuCI** là giao diện web mặc định.
- Truy cập tại địa chỉ: `http://192.168.1.1` (hoặc địa chỉ IP khác nếu đã đổi).

---

## 🛠️ BƯỚC 1: Chuẩn bị thiết bị và môi trường

### A. Kiểm tra router có hỗ trợ OpenWrt:
- Truy cập: [https://openwrt.org/toh/start](https://openwrt.org/toh/start)
- Tìm model (VD: TL-WR841N, Archer C7…)
- Kiểm tra phiên bản phần cứng (Hardware Version)

### B. Tải firmware tương thích:
- Tải đúng bản `.bin` cho model và version của bạn.

---

## ⚡ BƯỚC 2: Cài OpenWrt lên router TP-Link

- Truy cập: `http://192.168.0.1` (giao diện gốc của TP-Link)
- Chọn mục **Firmware Upgrade**
- Tải lên file `.bin` → Flash → Đợi hoàn tất

> ⚠️ **Cảnh báo:** Flash sai firmware có thể làm hỏng thiết bị. Kiểm tra kỹ và **backup** trước.

---

## 🧑‍💻 BƯỚC 3: Truy cập OpenWrt

- Sau khi flash thành công → Truy cập: `http://192.168.1.1`
- Giao diện **LuCI** sẽ xuất hiện
- Thiết lập mật khẩu và cấu hình WiFi nếu cần

---

## 💻 BƯỚC 4: SSH vào router

```bash
ssh root@192.168.1.1

Dùng Truy cập hệ điều hành bên trong router

🔹 Gõ http://192.168.1.1 trong trình duyệt:
Truy cập vào giao diện quản lý web (LuCI của OpenWrt)


```

🧩 BƯỚC 5: Viết chương trình backend (C/C++ hoặc shell)
Bạn có thể viết các file .sh, .c, .cpp để xử lý logic (bật/tắt thiết bị, thu thập dữ liệu...).

Ví dụ C++ đơn giản:
```c++
#include <iostream>
int main() {
    std::cout << "Router Control Interface Started!" << std::endl;
    return 0;
}
```
- Cross-compile bằng toolchain cho MIPS/ARM → Copy sang router để chạy.

🌐 BƯỚC 6: Tạo giao diện web (HTML + JS + CGI/Shell)
A. Tạo thư mục giao diện:
bash
Sao chép
Chỉnh sửa
cd /www
vi index.html
B. Nội dung index.html ví dụ:
html
<!DOCTYPE html>
<html>
<head><title>Control Panel</title></head>
<body>
  <h1>Chào mừng đến router!</h1>
  <form action="/cgi-bin/toggle_led.sh" method="POST">
    <input type="submit" value="Bật/Tắt đèn">
  </form>
</body>
</html>
C. Tạo script CGI:

```bash

mkdir -p /www/cgi-bin
vi /www/cgi-bin/toggle_led.sh
chmod +x /www/cgi-bin/toggle_led.sh
```

Nội dung toggle_led.sh:

sh
 
#!/bin/sh
echo "Content-type: text/html"
echo ""
echo "<html><body><h2>LED toggled!</h2></body></html>"
# Ở đây bạn có thể điều khiển GPIO nếu muốn

🧪 BƯỚC 7: Truy cập và kiểm thử
Mở trình duyệt → vào http://192.168.1.1

Click nút "Bật/Tắt đèn" → script backend xử lý

📁 Tại sao cần 2 file riêng biệt?
✅ 1. File HTML – Giao diện (frontend)
Vai trò: Hiển thị form đăng nhập cho người dùng nhập Username và Password

Không xử lý dữ liệu, chỉ dùng để gửi thông tin lên server

📍 Giống như: một biểu mẫu giấy bạn điền tên, gửi lên quầy tiếp nhận

✅ 2. File CGI script (Shell) – Xử lý (backend)
Vai trò: Nhận dữ liệu từ form HTML → kiểm tra hợp lệ → trả về kết quả

Có thể xử lý nâng cao như:

Kiểm tra mật khẩu

Điều khiển đèn, motor, thiết bị

Ghi log, chuyển hướng trang

📍 Giống như: nhân viên quầy tiếp nhận, kiểm tra thông tin bạn gửi lên



## ✅ TỔNG QUAN CÁC BƯỚC PHÁT TRIỂN ỨNG DỤNG HẸN GIỜ TẮT WIFI TRÊN TP-LINK (OPENWRT)

| Bước | Mục tiêu                           | Việc cần làm cụ thể |
|------|------------------------------------|----------------------|
| 1    | Cài OpenWrt cho TP-Link           | - Tải firmware đúng cho **TP-Link TL-WR841N v13**  <br> - Truy cập `192.168.0.1` (firmware gốc TP-Link) <br> - Nâng cấp bằng file `.bin` <br> - Sau khi flash thành công, truy cập `192.168.1.1` |
| 2    | Tạo giao diện HTML                 | - SSH vào router: `ssh root@192.168.1.1` <br> - Tạo file `/www/mytime.html` <br> - Viết mã HTML gồm form nhập số giây và nút gửi |
| 3    | Viết script xử lý backend         | - Tạo thư mục `/www/cgi-bin` nếu chưa có <br> - Tạo file `/www/cgi-bin/set_timer.sh` <br> - Viết shell script nhận giá trị POST và hẹn giờ tắt WiFi |
| 4    | Liên kết HTML với script backend  | - Trong form HTML, đặt `action="/cgi-bin/set_timer.sh"` <br> - Đảm bảo script có quyền thực thi: `chmod +x set_timer.sh` |
| 5    | Kiểm tra hoạt động trên trình duyệt | - Mở trình duyệt: `http://192.168.1.1/mytime.html` <br> - Nhập thời gian (giây) → bấm nút <br> - Quan sát router tắt WiFi sau thời gian đã đặt |



 
## 🔧 Những tính năng bạn có thể phát triển trên router chạy OpenWrt

| #   | Nhóm tính năng                        | Mô tả chi tiết |
|-----|----------------------------------------|----------------|
| 📡 1 | **Quản lý WiFi nâng cao**              | - Tắt/bật WiFi theo giờ <br> - Thay đổi SSID, mật khẩu <br> - Chặn người dùng lạ |
| 🌐 2 | **Thiết lập Web Server**               | - Giao diện điều khiển tùy chỉnh (HTML + JS + CGI) <br> - Trang điều khiển LED, relay, cảm biến |
| 🛡️ 3 | **Firewall / Port Forwarding tự động**| - Script bật NAT, forward port cho camera/game <br> - Cấu hình `iptables` động |
| 🔁 4 | **Tạo API điều khiển từ xa**           | - Viết REST API với CGI/Lua: `GET /status`, `POST /wifi` <br> - Tích hợp với app điện thoại |
| 🔌 5 | **Điều khiển thiết bị vật lý**         | - Điều khiển GPIO: bật/tắt LED, role, quạt, còi <br> - Đọc cảm biến qua UART, SPI, I2C |
| 🧠 6 | **Hệ thống hẹn giờ / tự động hóa**     | - Hẹn giờ tắt WiFi <br> - Tự động reboot, gửi email khi mất mạng |
| 📥 7 | **Tự cập nhật firmware (OTA)**         | - Viết module kiểm tra & tải firmware mới tự động |
| 📊 8 | **Theo dõi hệ thống (Monitoring)**     | - Ghi log truy cập <br> - Theo dõi tốc độ mạng, nhiệt độ, RAM, CPU |
| 🧰 9 | **Gắn thiết bị ngoài (USB, SSD)**      | - Lưu log, cấu hình, chạy web server mở rộng <br> - Ghi dữ liệu cảm biến vào USB |
| 🌍 10 | **Dịch vụ mạng mở rộng**              | - Thiết lập VPN Server (OpenVPN, WireGuard) <br> - Làm Proxy, DNS, DHCP Server mở rộng |





</details>
>>>>>>> 925cd5078fca11c050819c36c83dd1885a9af4a5
