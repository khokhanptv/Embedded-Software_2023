	<details>
<summary><h1>▶ ⭐Bài tập ứng dụng</h1></summary>

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
<summary><h1>▶ ⭐C Basic</h1></summary>

<details>
<summary><h3>Kiểu dữ liệu</h3></summary>

  ![kieu du lieu](./Kieu_Dulieu(1).PNG)
  ![kieu du lieu](./Kieu_Dulieu(2).PNG)

</details>

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
- **_Linker (Giải đoạn liên kết):_** 
	- 1 hoặc nhiều file.o sẽ được compiler liên kết lại 1 File  `.exe`.
	- File này để hệ điều hành chạy
	- Dùng lệnh `gcc  main.o -o filename` để tạo ra tệp thực thi .

</details>
<details>
  <summary><h2>Stdargt - Assert</h2></summary>

- **Stdargt:** 
- Cú pháp: `#include<stdarg.h>`
- stdarg.h trong Thư viện C định nghĩa một kiểu biến va_list và 3 macro  được sử dụng để lấy các tham số trong một hàm khi không cần biết có bao nhiêu tham số đầu vào
- va_list: là một kiểu dữ liệu được sử dụng để lưu trữ danh sách các đối số biến đổi.
- va_start:  được sử dụng để khởi tạo một va_list. Nó nhận hai giá trị: va_list và số lượng tham số
- va_arg: lấy giá trị đầu tiên của va_list và di chuyển con trỏ trong va_list tới đối số tiếp theo
- va_end: Kết thúc việc sử dụng va_list.

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
- con trỏ hàm là một biến chứa địa chỉ của một hàm.`void (*ptr)();`
- khi khởi tạo xong thì phải gán địa chỉ của hàm cho con trỏ hàm.`ptr = add;`
- sau khi gán rồi có thể gọi hàm thông qua con trỏ hàm  .`ptr();`
- Cú pháp:
`kiểu dữ liệu (*tên con trỏ hàm)(kieu du liêu1, kieu du liêu2)` 
- kiểu dữ liệu trùng với kiểu dữ liệu của hàm trỏ tới.
- Nếu cần truyền tham số thì kiểu dữ liệu 1 ,2 trùng với hàm truyền vào.
- Điều này cho phép truyền một hàm cụ thể vào một hàm khác 
- Có thể thông qua mảng để lưu giá trị các hàm mà nó trỏ tới
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
- Void Pointer  là một kiểu đặc biệt của con trỏ ,nó có thể trỏ đến bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
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
- Khai báo:`const　<Kiểu dữ liệu>　* <Tên con trỏ>;`
- không thể thay đổi giá trị tại biến mà nó đang trỏ đến.
- Ứng dụng:Trong bài toán thao tác với mảng, lý do arr trả về địa chỉ ,là 1 con trỏ , có thể thay đổi giá trị thông qua địa chỉ .
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
	- Khi khai báo hằng con trỏ cần khởi tạo giá trị địa chỉ cho nó.
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
- Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.Nghĩa là `extern` không dùng được
- Ví dụ:globalStaticVar được khai báo là static và nằm trong file "File1.c". Do đó, bạn không thể trực tiếp truy cập nó từ file "File2.c", bằng extern int globalStaticVar; trong File2.c, chương trình sẽ không biên dịch được và thông báo lỗi.

**Biến Extern:**
- Extern trước 1 biến để thông báo biến này đã được khai báo ở một nơi file khác.
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

- Linked list là một cấu trúc dữ liệu , được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
- Dùng trong các bài toán thao tác với mảng:Thêm, xóa, chèn ....phần tử vào mảng.
- Ngoài ra ta có các hàm thực hiện chức năng sau:

```C
node *createNode(int value); 
void push_back(node** array, int value); // thêm một node vào cuối
void push_front(node **array, int value); // them 1 node vao phia truoc
void pop_back(node **array); //  bỏ node cuối 
void pop_front(node **array); // xoa node dau tien
int front(node **array); // lay gia tri cua node dau tien
int back(node **array); // lay gia tri cua node cuoi cung
void insert(node **array, int value, int pos); // them 1 node vao mot vi tri bat ky
void deletee(node **array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node **array); // lay kich thuoc cua list
int get(node **array, int pos); 
bool empty(node **array); // kiem tra list co rong hay khong


```
 <details>
<summary>Ví dụ</summary>

```C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa cấu trúc của một node trong danh sách liên kết
typedef struct node
{
    int value;           // Giá trị của node
    struct node* next;   // Con trỏ trỏ đến node kế tiếp trong danh sách
} node;

// Hàm tạo một node mới với giá trị cho trước
node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));  // Cấp phát bộ nhớ cho node mới
    ptr->value = value;                       // Gán giá trị
    ptr->next = NULL;                         // Khởi tạo con trỏ next là NULL
    return ptr;
}

// Hàm thêm một node vào cuối danh sách
void push_back(node** array, int value)
{
    node* temp = createNode(value);

    if (*array == NULL)
    {
        *array = temp;
    }
    else
    {
        node* p = *array;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = temp;
    }
}

// Hàm thêm một node vào đầu danh sách
void push_front(node** array, int value)
{
    node* temp = createNode(value);
    temp->next = *array;
    *array = temp;
}

// Hàm loại bỏ node cuối cùng trong danh sách
void pop_back(node** array)
{
    if (*array == NULL)
    {
        printf("Error: List is empty\n");
        return;
    }

    node* p = *array;

    if (p->next == NULL)
    {
        free(p);
        *array = NULL;
        return;
    }

    while (p->next->next != NULL)
    {
        p = p->next;
    }

    free(p->next);
    p->next = NULL;
}

// Hàm loại bỏ node đầu tiên trong danh sách
void pop_front(node** array)
{
    if (*array == NULL)
    {
        printf("Error: List is empty\n");
        return;
    }

    node* temp = *array;
    *array = (*array)->next;
    free(temp);
}

// Hàm trả về giá trị của node đầu tiên trong danh sách
int front(node** array)
{
    if (*array == NULL)
    {
        printf("Error: List is empty\n");
        return 0; // Return a default value or handle the error as needed
    }

    return (*array)->value;
}

// Hàm trả về giá trị của node cuối cùng trong danh sách
int back(node** array)
{
    if (*array == NULL)
    {
        printf("Error: List is empty\n");
        return 0; // Return a default value or handle the error as needed
    }

    node* p = *array;
    while (p->next != NULL)
    {
        p = p->next;
    }

    return p->value;
}

// Hàm chèn một node mới vào danh sách tại một vị trí cụ thể
void insert(node** array, int value, int pos)
{
    if (pos < 0)
    {
        printf("Error: Invalid position\n");
        return;
    }

    if (pos == 0)
    {
        push_front(array, value);
        return;
    }

    node* temp = createNode(value);
    node* p = *array;

    for (int i = 0; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Error: Invalid position\n");
        free(temp);
        return;
    }

    temp->next = p->next;
    p->next = temp;
}

// Hàm xóa một node khỏi danh sách tại một vị trí cụ thể
void deletee(node** array, int pos)
{
    if (*array == NULL)
    {
        printf("Error: List is empty\n");
        return;
    }

    if (pos < 0)
    {
        printf("Error: Invalid position\n");
        return;
    }

    if (pos == 0)
    {
        pop_front(array);
        return;
    }

    node* p = *array;
    node* temp;

    for (int i = 0; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL || p->next == NULL)
    {
        printf("Error: Invalid position\n");
        return;
    }

    temp = p->next;
    p->next = p->next->next;
    free(temp);
}

// Hàm trả về kích thước của danh sách
int size(node** array)
{
    int count = 0;
    node* p = *array;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

// Hàm trả về giá trị của node tại một vị trí cụ thể trong danh sách
int get(node** array, int pos)
{
    int i = 0;
    node* p = *array;

    while (p != NULL && pos != i)
    {
        p = p->next;
        i++;
    }

    if (pos != i || p == NULL)
    {
        printf("Error: Invalid position\n");
        return 0; // Return a default value or handle the error as needed
    }

    return p->value;
}

// Hàm kiểm tra xem danh sách có rỗng hay không
bool empty(node** array)
{
    return (*array == NULL);
}

// Hàm main để kiểm tra các hàm đã triển khai
int main()
{
    node* arr = NULL;

    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Size: %d\n", size(&arr));

    push_front(&arr, 1);
    pop_back(&arr);

    printf("Front: %d\n", front(&arr));
    printf("Back: %d\n", back(&arr));

    insert(&arr, 99, 2);
    deletee(&arr, 4);

    for (int i = 0; i < size(&arr); i++)
    {
        printf("Value at position %d: %d\n", i, get(&arr, i));
    }

    printf("Is empty? %s\n", empty(&arr) ? "Yes" : "No");

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
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/84c5b5de-2ee0-42c3-8f95-2c95cf81c682)

**Các Phép Toán Cơ Bản trên Hàng Đợi**

- Enqueue: Thêm một phần tử vào cuối hàng đợi.
- Dequeue: Loại bỏ một phần tử từ đầu hàng đợi.
- IsEmpty: Kiểm tra xem hàng đợi có trống không.
- IsFull: Kiểm tra xem hàng đợi có đầy không.
- Peek: Lấy giá trị ở đầu hàng đợi mà không loại bỏ nó.

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
- Class là 1 kiểu dữ liệu do người dùng định nghĩa
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
**Constructor**
-  Constructor  là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class,Nó được sử dụng để khởi tạo các thuộc tính của đối tượng..
-  Có hai loại chính:
	+ Default Constructor (Constructor mặc định): không có tham số .
	+ Parameterized Constructor (Constructor với tham số):   constructor được khởi tạo và có tham số truyền vào.
<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>

class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;

    // Parameterized Constructor
    HinhChuNhat(int dai = 5, int rong = 3) {
        chieuDai = dai;
        chieuRong = rong;
    }

    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};

int main() {
    // Tạo đối tượng HinhChuNhat và sử dụng constructor với giá trị mặc định
    HinhChuNhat hinhCN1;

    // Tạo đối tượng HinhChuNhat và truyền giá trị khác cho constructor
    HinhChuNhat hinhCN2(7, 4);

    // Hiển thị diện tích của hình chữ nhật 1 và 2
    std::cout << "Dien tich hinh chieuDai1: " << hinhCN1.tinhDienTich() << std::endl;
    std::cout << "Dien tich hinh chieuDai2: " << hinhCN2.tinhDienTich() << std::endl;

    return 0;
}


```
</details>

**Destructor**
- DDestructor trong C++ là một method sẽ được tự động gọi khi đối tượng được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>

class HinhChuNhat {
public:
    double chieuDai;  
    double chieuRong;

    // Constructor
    HinhChuNhat() {
        chieuDai = 10;
        chieuRong = 9;
    }

    // Destructor
    ~HinhChuNhat() {
        std::cout << "Destructor" << '\n';
    }

    // Hàm tính diện tích   
    double tinhDienTich() {       
        return chieuDai * chieuRong; 
    }
};

int main() {
    HinhChuNhat hinh1;
    std::cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';

    return 0;
}

```
</details>

**Static keyword**
- Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>
#include <string>

class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;
    static int var;
};

int HinhChuNhat::var =0;
// Đây là cách đặt giá trị khởi tạo cho biến static var trong lớp HinhChuNhat(bắt buộc)
int main() {
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    std::cout << "address of chieu dai: " << &hinh1.chieuDai << '\n'; 
    std::cout << "address of chieu dai: " << &hinh2.chieuDai << '\n'; 
    std::cout << "address of chieu dai: " << &hinh3.chieuDai << '\n'; 

    std::cout << "address of var: " << &hinh1.var << '\n'; 
    std::cout << "address of var: " << &hinh2.var << '\n'; 
    std::cout << "address of var: " << &hinh3.var << '\n'; 

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
  <summary><h2>namespace</h2></summary>

- Namespace:là từ khóa trong C++ được sử dụng để phân biệt các hàm, lớp, biến cùng tên trong các file khác nhau.
 tạo những vùng nhớ khác nhau ,mỗi namespace là 1 chương trình riêng ,với 2 namespace khác nhau có thể tạo các biến trùng tên. Nhưng trong 1 namespace không thể có 2 biến cùng tên

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
  <summary><h2>Lambda</h2></summary>

**Lambda**
- Lambda là một cú pháp trong ngôn ngữ lập trình C++ cho phép tạo ra các hàm vô danh (anonymous functions) ngắn gọn và linh hoạt ngay tại chỗ mà không cần phải đặt tên  cho chúng,Cú pháp của lambda rất linh hoạt và có thể được sử dụng để viết mã ngắn gọn và dễ đọc.
- Cú pháp :
` [capture clause] (parameter list) -> return type { body }`
- Capture clause: Là cách bạn chọn để capture các biến từ phạm vi bên ngoài vào bên trong lambda. Có thể capture bằng reference (&), capture bằng giá trị (=), hoặc không capture ([]).
- parameter list: Là danh sách các tham số của hàm lambda, tương tự như danh sách tham số của một hàm thông thường.
- return type: Là kiểu dữ liệu của giá trị trả về của hàm lambda. Trong một số trường hợp, trình biên dịch có thể tự suy luận kiểu dữ liệu này.
- body: Là phần thân của hàm lambda, nơi  viết mã lệnh thực thi các công việc của hàm.
- Trong C++, có ba cách chính để capture các biến từ phạm vi bên ngoài vào trong một lambda function:
	+	Capture bằng Giá Trị (=):
		+ Capture tất cả các biến được sử dụng trong lambda theo cách sao chép giá trị của chúng.
		Các biến được capture bằng giá trị sẽ không thay đổi giá trị của chúng ngoài lambda khi chúng được thay đổi trong lambda.
	+	Capture bằng Reference (&):
		+ Capture tất cả các biến được sử dụng trong lambda theo cách tham chiếu đến chúng.
		+ Các biến được capture bằng reference cho phép thay đổi giá trị của chúng ngoài lambda khi chúng được thay đổi trong lambda.
	+ Capture Tự Do (không sử dụng capture clause):
		+ Không capture bất kỳ biến nào từ phạm vi bên ngoài vào trong lambda.
		+ Lambda chỉ có thể truy cập các biến được định nghĩa trong lambda hoặc các biến toàn cục.
**Lambda function mang lại tính ngắn gọn và linh hoạt trong việc viết code, giúp tăng cường độ dễ đọc và dễ bảo trì của chương trình**

</details>


</details>
<details>

  <summary><h3>Hướng đối tượng </h3></summary>

### hướng đối tượng là gi?
- OOP là một phương pháp lập trình dưới dạng các "đối tượng," mỗi đối tượng có chứa dữ liệu và các phương thức để thao tác dữ liệu đó.
- Các khái niệm quan trọng trong OOP bao gồm:
	+ Class: để tạo ra các đối tượng , nó mô tả dữ liệu và phương thức của đối tượng đó
	+ Đối tượng (Object) : Một đối tượng cụ thể được tạo ra từ class, có 
**Phạm vi truy cập:**
- Public:Member nào trong Public thì object có thể trỏ trực tiếp được và nội tại trong class cũng sử dụng được .
- protected:Member trong protected thì Class con có thể trỏ tới được
- private: Chỉ có nội tại trong class mới sử dụng được.Lý do đặt PROPERTY trong private, để chắc chắn object không trỏ tới được.

**1/Encapsulation (Tính đóng gói):**
- Object không được phép truy cập PROPERTY từ phạm vi public
- PROPERTY nằm ở private hoặc protected.
- Để truy cập PROPERTY phải thông qua method.
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
- Một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.
Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trongC++.

**khi nào nên dùng/không dùng class kế thừa**
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

- Các kiểu kế thừa: public,private và protected .Thì private là không  dùng vì class con kế thừa private sẽ đưa tất cả property từ class cha vào private. Làm cho các class tiếp theo không thể truy cập vào được( private chỉ cho phép nội tại class trỏ tới)

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
- Các method có thể trùng tên với nhau , nhưng phải khác các input parameter
<details>
<summary>Ví dụ:</summary>

```C++
using namespace std;

class toanhoc{

	protected:
	int namsinh;
	void tong(int a,int b ){ 
	    	printf("tong a+b :%d\n",a+b);
	}
	void hienthi(int a,int b ,int c){ 
		printf("tong a+b+c :%d\n",a+b+c);
	}
	int hienthi(int a,double b){ 		
		return a +(int)b;
	}
};

int main(void){
	toanhoc th;
	th.tong(7,4);
	th.tong(5,3,5);
	printf("tong:%d\n",th.tong(5,6.7));

}
```
</details>

**4/Abstraction (Tính trừu tượng ):**

- Ẩn đi các chi tiết của một đối tượng và hiển thị những gì cần thiết, để sử dụng đối tượng đó.

**Template trong C++ là gì?**
- Là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...

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


**Virtual trong C++ là gì?**
- Được sử dụng để tạo hàm ảo. Hàm ảo cho phép lớp con ghi đè hàm của lớp cha  . 


<details>
<summary>Ví dụ</summary>

```C++

 #include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->speak();  // Output: Dog barks
    animal2->speak();  // Output: Cat meows

    delete animal1;
    delete animal2;

    return 0;
}


```
</details>


</details>
<details>
  <summary><h2>Standard template library </h2></summary>

## STL là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến

**Một số thành phần chính của STL:**
- Container:Một container là một cấu trúc dữ liệu chứa nhiều phần tử gồm:
	+ Vector
	+ List
	+ Map
	+ Array

- Iterator
- Algorithms
- Functor


**Vector trong C++ là gì?**

- vector là một mảng động, tức là có khả năng thay đổi kích thước  
- Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.
- Một số method của vector:
1. at(): Truy cập vào phần tử của vector
2. size(): Trả về kích thước của vector
3. resize(): Thay đổi kích thước của vector
4. begin(): Địa chỉ của phần tử đầu tiên của vector
5. end(): Địa chỉ của phần tử cuối cùng của vector
6. push_back(): Thêm phần tử vào vị trí cuối của vector
<details>
<summary>Ví dụ </summary>

```C++
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

</details>


**List là gì**

- List là một c  danh sách liên kết hai chiều.
- Dưới đây là một số đặc điểm quan trọng của list:
	+ Truy cập tuần tự
	+ Hiệu suất chèn và xóa: 
- Một số method của list:
	+ push_back():
	+ pop_back():
	+ insert(): Chèn một node vào list
	+ erase(): Xóa một node của list
	+ size(): Trả về kích thước của list
- Sử dụng vector khi:
	+ Cần truy cập ngẫu nhiên đến các phần tử.
    + Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách.
	+ Dung lượng có thể biết trước hoặc thay đổi ít.
- Sử dụng list khi:
	+ Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
	+ Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.

**Map**
- Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value
- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử của map

**Array**
- Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)
- array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []

# Iterator
- Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.

# Algorithm
- Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. 
- Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 















<details>
<summary>Ví dụ quan trọng</summary>

```C++
#include <iostream>
#include <string>
#include <vector>

#define in 0
#define intb 1
#define add 2
#define del 3
#define fix 4
#define rs 5
#define out 6


 

using namespace std;

class sinhvien {
protected:
    string tensv;
    int tuoisv;
    int idsv;
    float diemtoansv;
    float diemlysv;
    float diemhoasv;
    float diemtrungbinhsv;

public:
    sinhvien() : tuoisv(0), idsv(0), diemtoansv(0.0), diemlysv(0.0), diemhoasv(0.0), diemtrungbinhsv(0.0) {}

    sinhvien(string name, int old, int id, float diemtoan, float diemly, float diemhoa)
        : tensv(name), tuoisv(old), idsv(id), diemtoansv(diemtoan), diemlysv(diemly), diemhoasv(diemhoa) {}

    void nhapthongtinsv() {
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, tensv);

        cout << "Nhap tuoi sinh vien: ";
        cin >> tuoisv;

        do {
        cout << "Nhap diem toan sinh vien (0>>10): ";
        cin >> diemtoansv;
        } while (diemtoansv < 0 || diemtoansv >10 );
        
       

        do {
            cout << "Nhap diem ly sinh vien (0>>10): ";
            cin >> diemlysv;
        } while (diemlysv < 0 || diemlysv > 10);

        do {
            cout << "Nhap diem hoa sinh vien (0>>10): ";
            cin >> diemhoasv;
        } while (diemhoasv < 0 || diemhoasv > 10);
    }

    float diemtrungbinh() {
        diemtrungbinhsv = (diemtoansv + diemlysv + diemhoasv) / 3;
        return diemtrungbinhsv;
    }

    string layXepLoai()  {
        float dtb = diemtrungbinh();
        if (dtb > 8) {
            return "Gioi";
        } else if (dtb >= 6.5 && dtb < 8) {
            return "Kha";
        } else {
            return "TB";
        }
    }

    string layThongTin()  {
        return "Ten: " + tensv + "\nTuoi: " + to_string(tuoisv) + "\nID: " + to_string(idsv) +
               "\nDiem Toan: " + to_string(diemtoansv) + "\nDiem Ly: " + to_string(diemlysv) +
               "\nDiem Hoa: " + to_string(diemhoasv) + "\nDiem Trung Binh: " + to_string(diemtrungbinhsv) +
               "\nXep loai: " + layXepLoai();
    }

    int layIdSV()  {
        return idsv;
    }
    void setIdSV(int newId) {
        idsv = newId;
    }
 
};

class danhsachSV {
private:
    vector<sinhvien> danhsachsinhvien;
    static int maxId ;
    

public:
   
    void xoasv(int id) {
        int n = danhsachsinhvien.size();
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (danhsachsinhvien[i].layIdSV() == id) {
                found = true;
                // Xóa sinh viên tại vị trí i
                danhsachsinhvien.erase(danhsachsinhvien.begin() + i);
                cout << "Da xoa sinh vien co ID " << id << endl;

            break;  
            }   
        }  
        if (!found) {
        cout << "Khong tim thay sinh vien co ID " << id << endl;   
        }

    }

    void suaThongTinSV(int id) {
        int n = danhsachsinhvien.size();
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (danhsachsinhvien[i].layIdSV() == id) {
                found = true;
                cout << "Nhap thong tin moi cho sinh vien:\n";
                sinhvien svMoi;
                svMoi.nhapthongtinsv();
                svMoi.diemtrungbinh();
                danhsachsinhvien[i] = svMoi;
                cout << "Da cap nhat thong tin cho sinh vien co ID " << id << endl;

                break;  
            }
        }

        if (!found) {
            cout << "Khong tim thay sinh vien co ID " << id << endl;
        }
    }


    void sapXepTheoDiemTB() {
        int n = danhsachsinhvien.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                 
                if (danhsachsinhvien[j].diemtrungbinh() > danhsachsinhvien[j + 1].diemtrungbinh()) {                  
                    sinhvien temp = danhsachsinhvien[j];
                    danhsachsinhvien[j] = danhsachsinhvien[j + 1];
                    danhsachsinhvien[j + 1] = temp;
                }
            }
        }
    }

    void inThongTinDanhSach() const {
        for (auto sv : danhsachsinhvien) {
            cout << sv.layThongTin() << endl;
            cout << "-------------" << endl;
        }
    }

    void nhapThemSV() {
        sinhvien sv;
        maxId++;
        sv.setIdSV(maxId);
        sv.nhapthongtinsv();
        sv.diemtrungbinh();
        danhsachsinhvien.push_back(sv);
    }
    
    void reset(){
        danhsachsinhvien.clear();


    }
};

int danhsachSV::maxId = 0;

int main() {
    danhsachSV dssv;
    int nhapkey;
    int i_id;
    
    int soluongsv;

    do {
        cout << "Nhap so luong sinh vien (khong duoc am): ";
        cin >> soluongsv;
    } while (soluongsv < 0);

    for (int i = 0; i < soluongsv; i++) {
        dssv.nhapThemSV();
    }
    do {
        cout << "Vui long lam theo huong dan: "<< endl;
        cout << "Nhap 0:In ra danh sach sinh vien "<< endl;
        cout << "Nhap 1:In ra danh sach sinh vien theo diem TB"<< endl;
        cout << "Nhap 2:them sinh vien va in ra theo diem TB"<< endl;
        cout << "Nhap 3:xoa sinh vien va in ra theo diem TB"<< endl;
        cout << "Nhap 4:sua sinh vien va in ra theo diem TB"<< endl;
        cout << "Nhap 5:reset chuong trinh"<< endl;
        cout << "Nhap 6:thoat chuong trinh"<< endl;
    
    
        cin >> nhapkey;
        switch (nhapkey)
        {
        case  in:
            cout << "Danh sach sinh vien:"<< endl;;
            dssv.inThongTinDanhSach();
            break;

        case  intb:
            dssv.sapXepTheoDiemTB();
            cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh:"<< endl;;
            dssv.inThongTinDanhSach();
            break;

        case add:
            dssv.nhapThemSV(); 
            dssv.inThongTinDanhSach();  
            break;

        case del:
            cout << "vui long nhap id sinh vien can xoa:"<< endl;;
            cin >> i_id;
            dssv.xoasv(i_id);
            dssv.inThongTinDanhSach();  
            break;

        case fix:
            cout << "vui long nhap id sinh vien can sua:"<< endl;;
            cin >> i_id;
            dssv.suaThongTinSV(i_id); 
            dssv.inThongTinDanhSach();  
            break;
        case rs:
            cout << "reset tat ca du lieu" << endl;
            dssv.reset();
            break;
        case out:
            cout << "Thoat chuong trinh" << endl;
            break;
        
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai"<< endl;
            break;
        }
    }
    while (nhapkey!=6);
 
    return 0;

}


```
</details>





</details>



</details>


<details>
  <summary><h1>▶ ⭐Embedded</h1></summary>

<details>
  <summary><h2>1 Số câu hỏi</h2></summary

**Macro,Function**
- Marco trỏ tới 1 khối lệnh thực hiện một chức năng nào đó.Được xử lý bởi preprocessor(tiền xử lý)
- Function là 1 khối lệnh thực hiện một chức năng nào đó
- Macro không cần quan tâm kiểu dữ liệu của tham số đầu vào
- Function phải chỉ rõ kiểu dữ liệu của tham số đầu vào
- Macro đơn giản là copy -paste vào chương trình ,Điều này làm tốn kich thước nhưng time xử lý ngắn hơn
- khi khởi tạo hàm ,RAM chỉ tốn 1 bộ nhớ cố định để lưu>>gọi 20 lần, cũng sẽ chỉ tốn 1 bộ nhớ như vậy.nhưng sẽ mất time nhiều hơn vì dịch từ vùng nhớ lưu hàm sang vùng nhớ goi hàm.
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
- Bộ vi điều khiển tích hợp CPU, bộ nhớ và các thiết bị ngoại vi trên một con chip duy nhất, được thiết kế riêng cho các tác vụ cụ thể.
- Bộ vi xử lý tập trung vào tính toán đa năng, yêu cầu các thành phần bên ngoài để tạo nên một hệ thống hoàn chỉnh.

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

**SMT32F4**
- Watchdog timer (WDT)  là một tính năng quan trọng để bảo vệ chương trình . Nó giám sát hoạt động của chương trình và thực hiện các hành động nhất định nếu hệ thống lỗi

-	Khi bắt đầu một chu kỳ, chương trình phải feed một giá trị cụ thể vào thanh ghi của watchdog timer. Nếu chương trình không feed trong khoảng thời gian nhất định, watchdog timer sẽ tự động reset hoặc thực hiện một hành động khác như kích hoạt một ngắt, tùy thuộc vào cấu hình của nó.
	+ Independent Watchdog (IWDG):	
		+ IWDG hoạt động độc lập với hệ thống chính.
		+ Nó được cấu hình để đếm một khoảng thời gian cố định.
		+ Nếu không feed (reset) IWDG trong khoảng thời gian cấu hình, nó sẽ kích hoạt một hành động nhất định như reset hệ thống.
		+ Thích hợp cho các ứng dụng yêu cầu một cơ chế đơn giản để kiểm tra hoạt động của hệ thống và reset nếu cần.
	+ Window Watchdog (WWDG):  
		+ WWDG cũng hoạt động độc lập với hệ thống chính.
		+ Nó được cấu hình với hai giá trị: giá trị trễ (delay) và giá trị cửa sổ (window).
		+ Trong thời gian delay, bạn phải feed WWDG. Sau thời gian delay và trước khi kết thúc cửa sổ, bạn phải feed nó một lần nữa.
		+ Nếu không feed WWDG trong thời gian delay hoặc nếu feed nó sau thời gian cửa sổ, nó sẽ kích hoạt một hành động nhất định như reset hệ thống.
		+ WWDG thường được sử dụng trong các ứng dụng yêu cầu một cơ chế kiểm tra chặt chẽ hơn, nơi mà không chỉ thời gian mà còn thứ tự của các sự kiện được quan trọng.

- stm32F4 thuộc dòng ARM-M(có 3 loại)
	+ Cortex-A :Dùng trong oto
	+ Cortex-R :Dùng trong y tế 
	+ Cortex-M :Tiêu thu năng lượng thấp , chi phí thấp
- ARM Cortex  được thiết kế dựa trên kiến trúc RISC.RISC  phương pháp thiết kế tập trung vào sự đơn giản của tập lệnh.
và  cấu trúc Von Neumann, một kiểu cấu trúc trong đó dữ liệu và lệnh được lưu trữ trong cùng một bộ nhớ, để giảm chi phí và độ phức tạp của hệ thống.
**STM32F4**
- Flash memory có thể lên đến 1 megabyte
- SRAM có dung lượng 192+4 kilobytes
- 16  bộ DMA ,17 timer
- 3 × I2C ,4 USARTs/2 UARTs ,3 SPIs (42 Mbits/s),
- 2 × CAN interfaces (2.0B Active)
-  SDIO interface

![z4957623054341_76e371e0a646a50f810f7ba8450aed45](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/b64d3b82-97fc-4c9d-a9d4-f05e9bb794f3)

<details>
  <summary><h4>SPI protocol</h4></summary>

- Các bit dữ liệu được truyền nối tiếp nhau và có xung clock đồng bộ.
- Giao tiếp song công, có thể truyền và nhận cùng một thời điểm.
- Có chế độ 1 dây: truyền hoặc nhận
- Khoảng cách truyền ngắn
- Giao tiếp 1 Master với nhiều Slave.
- Tốc độ truyền khoảng vài Mbps hoặc vài chục Mbps.
- ![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/1287cafd-d263-4991-9fca-1d90ae15081e)
- Với STM32F4 :tần số xung  là 84 MHz, qua bộ chia 8(có thể chọn bộ chia 2,4,8....)>> tốc độ bằng 10.5 Mbps.
- Để xử lý lỗi truyền dữ liệu trong giao thức SPI,có thể sử dụng cờ (flags) để kiểm tra trạng thái của các lỗi như Overrun, Mode Fault, CRC Error
**Master/Slave Configuration:**

- Master (Thiết Bị Chủ Động): Master là thiết bị kiểm soát quá trình truyền/nhận dữ liệu. Nó tạo ra xung clock và chọn slave để gửi hoặc nhận dữ liệu từ.
- Slave (Thiết Bị Bị Động): Slave là thiết bị nghe lệnh từ Master và truyền hoặc nhận dữ liệu tùy thuộc vào yêu cầu của Master.
Các Dây Truyền Thông Chính:

- MOSI (Master Out Slave In): Dữ liệu được truyền từ Master đến Slave qua dây này.
- MISO (Master In Slave Out): Dữ liệu được truyền từ Slave đến Master qua dây này.
- SCK (Serial Clock): Tín hiệu xung clock được tạo ra bởi Master để đồng bộ hóa truyền dữ liệu.
**Nguyên Tắc Full-Duplex:**

Khi Master muốn truyền dữ liệu, nó tạo ra một xung clock và đặt giá trị dữ liệu trên dây MOSI.
Đồng thời, Slave lắng nghe xung clock và đọc giá trị dữ liệu từ dây MOSI.
Ngược lại, khi Slave muốn truyền dữ liệu, nó đặt giá trị dữ liệu trên dây MISO và lắng nghe xung clock.
Master nhận dữ liệu từ Slave thông qua dây MISO đồng bộ với xung clock.
(CS).
**Vấn Đề Đồng Bộ Hóa Trong SPI**
- Kiểm tra xung clock (CPOL và CPHA) 2 con cài như nhau chưa?
- Check mode truyền của 2 con (master-slayer)
- Khung truyền 2 con đúng chưa(8-16 bit)
**Ứng Dụng Thực Tế của SPI:**
- Truyền Dữ Liệu Trong Các Ứng Dụng IoT :  ví dụ như mô-đun cảm biến nhiệt độ và độ ẩm sẽ gửi thông số cho microcontroller 
- Truyền Dữ Liệu Giữa Vi xử lý và Các Thiết Bị Ngoại Vi:LCD,EEPROM
**Cờ quan trọng trong STM32F4**
- SPI_I2S_FLAG_TXE: Cờ báo truyền, cờ này sẽ set lên 1 khi truyền xong data trong buffer.
- SPI_I2S_FLAG_RXNE: Cờ báo nhận, cờ này set lên 1 khi nhận xong data.
- SPI_I2S_FLAG_BSY: Cờ báo bận,set lên 1 khi SPI đang bận truyền nhận
- SPI_I2S_FLAG_MODF:Được set khi có lỗi trong chế độ hoạt động của SPI.
- SPI_I2S_FLAG_OVR :Được set khi có một lỗi Overrun xảy ra, tức là khi dữ liệu mới nhận được trước khi kịp đọc dữ liệu cũ từ bộ đệm.
- SPI_I2S_FLAG_CRCERR:Được set khi có lỗi trong việc so sánh giá trị  truyền và nhận.
**Quy tình cơ bản khi lập trình SPI**
- Cấp Xung cho SPI:
- Cấu Hình Chân Dựa Trên Reference Manual (RM) của Nhà Sản Xuất
- Cấu Hình Các Chức Năng cho SPI
![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/SPI_single_slave.svg/800px-SPI_single_slave.svg.png)

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fc/SPI_three_slaves.svg/350px-SPI_three_slaves.svg.png)
- ***SCLK (Serial Clock):*** Xung clock phát ra từ master
- ***MOSI (Master Out Slave In):*** Truyền data từ `master` đến `slave`. Chân `MOSI` ở `master` sẽ kết nối đến chân `MOSI` ở `slave`.
- ***MISO (Master In Slave Out):*** Truyền data từ `slave` đến `master`. Chân `MISO
` ở `master` sẽ kết nối đến chân `MISO` ở `slave`.
- ***CS/SS (Chip/Slave Select):*** Chân CS được master sử dụng để lựa chọn slave cần giao tiếp. Master chỉnh chân SS xuống mức 0 để chọn slave truyền data.

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bb/SPI_8-bit_circular_transfer.svg/500px-SPI_8-bit_circular_transfer.svg.png)
Khung truyền SPI:

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/5ed1598f-be34-4626-833e-2f3e6fdd89d0)
- Tùy thuộc vào bit chọn định dạng khung dữ liệu (DFF trong thanh ghi SPI_CR1), dữ liệu
gửi hoặc nhận là 8 bit hoặc 16 bit. Lựa chọn này phải được thực hiện trước khi kích hoạt SPI để đảm bảo hoạt động chính xác.
- Bắt đầu quá trình, master sẽ kéo chân CS của slave muốn giao tiếp xuống 0 để báo hiệu muốn truyền nhận.
- Mỗi xung clock, Master sẽ gửi đi 1 bit từ thanh ghi dịch (Shift Register) của nó đến thanh ghi dịch của Slave thông qua đường MOSI. Đồng thời Slave cũng gửi lại 1 bit đến cho Master qua đường MISO.Như vậy sau 8 chu kỳ clock thì hoàn tất việc truyền và nhận 1 byte dữ liệu.

- Trong giao tiếp SPI, chỉ có thể có 1 Master nhưng có thể 1 hoặc nhiều Slave cùng lúc. Ở trạng thái nghỉ, chân SS của các Slave ở mức 1, muốn giao tiếp với Slave nào thì ta chỉ việc kéo chân SS của Slave đó xuống mức 0.


![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/SPI_timing_diagram2.svg/400px-SPI_timing_diagram2.svg.png)
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

### SPI trong STM32F407VET6.
**SPI Software:**
- Trên mỗi dòng vi điều khiển khác nhau module SPI khác nhau, đấy gọi là SPI cứng (hardware SPI). Như vậy bản chất chuẩn truyền thông SPI giống nhau trên mỗi chip nhưng lại được cài đặt và sử dụng không giống nhau. 
- Để khắc phục nhược điểm trên, có 1 cách lập trình giả lập SPI cứng đó là “SPI mềm”. Thực chất SPI mềm là cách “mô phỏng” bằng cách tạo ra một giao thức truyền thông giống SPI.

- Bước đầu, ta định nghĩa cho 4 chân sử dụng cho SPI và cấp xung CLK:
<details>
		<summary>Software:</summary>
    
```C
// định nghĩa chân
#define SPI_SCK GPIO_Pin_0	// output
#define SPI_NSS GPIO_Pin_1	// ouput
#define SPI_MOSI GPIO_Pin_2	// ouput
#define SPI_MISO GPIO_Pin_3 // input
#define SPI_GPIO GPIOA
// cấp xung CK
void RCC_Config(){
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
}
// cấu hình chân
void GPIO_Config(){
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SPI_SCK| SPI_MOSI| SPI_NSS;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = SPI_MISO;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);

}
// cấu hình timer
void TIM_Config(){
TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_TimeBaseInitStruct.TIM_Prescaler = 16800-1;
	TIM_TimeBaseInitStruct.TIM_Period = 0xFFFF-1; 
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	TIM_Cmd(TIM2, ENABLE);
}
// hàm delay
void delay_ms(uint32_t time){
	
	TIM_SetCounter(TIM2,0);
	while(TIM_GetCounter(TIM2) < time*10);
}
// Mode truyền 
Void Clock(){
	GPIO_WriteBit(SPI_GPIO, SPI_SCK, Bit_SET);
	delay_ms(2);
	GPIO_WriteBit(SPI_GPIO, SPI_SCK, Bit_RESET);
	delay_ms(2);
}
//Hàm truyền ở master:
void SPI_Master_Transmit(uint8_t u8Data){
	uint8_t u8Mask = 0x80;
	uint8_t tempData;
	GPIO_WriteBit(SPI_GPIO, SPI_NSS, Bit_RESET);
	delay_ms(1);
	for(int i=0; i<8; i++){
		tempData = u8Data & u8Mask;
		if(tempData){
			GPIO_WriteBit(SPI_GPIO, SPI_MOSI, Bit_SET);
			delay_ms(1);
		} else{
			GPIO_WriteBit(SPI_GPIO, SPI_MOSI, Bit_RESET);
			delay_ms(1);
		}
		u8Data=u8Data<<1;
		Clock();
	}
	GPIO_WriteBit(SPI_GPIO, SPI_NSS, Bit_SET);
	delay_ms(1);
}
uint8_t array[] = {7, 8, 4, 2};

int main(){
	RCC_Config();
	GPIO_Config();
	TIM_Config();
	
	while(1){
		for(uint8_t i = 0; i< 8; i++){
				SPI_Master_Transmit(array[i]);
				delay_ms(1000);
		}
	}

}
```
</details>

**SPI Hardware:**
- Dựa vào tài liệu nhà sản xuất ta cấu hình chân:\
![STM32F4_AF](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/74503806-d47a-4395-8beb-6152728f7423)
 
<details>
		<summary>Hardware_rcv</summary>

```C
// Slayer Hardware
// DỰA VÀO PHẦN CỨNG STM32F1
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_spi.h"              // Keil::Device:StdPeriph Drivers:SPI
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC


#define SPI1_NSS 	GPIO_Pin_4
#define SPI1_SCK	GPIO_Pin_5
#define SPI1_MISO 	GPIO_Pin_6
#define SPI1_MOSI 	GPIO_Pin_7
#define SPI1_GPIO 	GPIOA


void delay (uint32_t time){
	uint32_t i;
	for (i = 0; i< time; i++){
	}
	
}

void RCC_CONFIG(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
}

void GPIO_Cofig(){
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SPI1_NSS| SPI1_SCK| SPI1_MISO| SPI1_MOSI;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(SPI1_GPIO, &GPIO_InitStructure);
}

void SPI_config(){
	SPI_InitTypeDef SPI_InitStructure;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	
	SPI_Init(SPI1, &SPI_InitStructure);
	SPI_Cmd(SPI1, ENABLE);
}

uint8_t SPI_RCV(void){
	volatile uint8_t temp;
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY)==1);
	temp =(uint8_t)SPI_I2S_ReceiveData(SPI1);
	return temp;

}

uint8_t arr[4]; 
uint8_t i=0;
int main(){
	RCC_CONFIG();
	GPIO_Cofig();
	SPI_config();
		while(1)
		{	
			
			while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)== 0);
			if(GPIO_ReadInputDataBit(SPI1_GPIO, SPI1_NSS ) == 0){
					arr[i] = SPI_RCV();
					i++;
					if(i > 3){ 
						i = 0;
					}
			}

		}
}

```
</details>

<details>
		<summary>Hardware_Mater</summary>

```C
#include "stm32f4xx.h"

#define SPI1_NSS 	GPIO_Pin_4
#define SPI1_SCK	GPIO_Pin_5
#define SPI1_MISO 	GPIO_Pin_6
#define SPI1_MOSI 	GPIO_Pin_7
#define SPI1_GPIO 	GPIOA

void delay (uint32_t time){
	uint32_t i;
	for (i = 0; i< time; i++){
	}
	
}
void RCC_Config(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
}

void GPIO_Config(){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = SPI1_NSS|SPI1_SCK|SPI1_MISO|SPI1_MOSI;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(SPI1_GPIO,&GPIO_InitStruct); 
	
	
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,1);
}
void SPI_Config(){
	SPI_InitTypeDef SPI_InitStruct;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128; //84mhz /16
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 10;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI_InitStruct);
	SPI_Cmd(SPI1,ENABLE);
	
}
void SPI_Trans(uint8_t arr ){
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_SendData(SPI1,arr);
	while(!SPI_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==0);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}

uint8_t arr[4]={5,2,3,4};
int main(){
	RCC_Config();
	GPIO_Config();
	SPI_Config();
	while(1){
		
		for(uint8_t i=0;i<4;i++){	
			SPI_Trans(arr[i]);		 
			delay(1000000);
		}
		 
		
	}
	
	
	
}









```




</details>

</details>

<details>
  <summary><h4>I2C protocol</h4></summary>

- I2C (Inter-Integrated Circuit) là một giao thức truyền thông nối tiếp đồng bộ. Nên các bit dữ liệu truyền đi được đồng bộ hóa với xung nhịp do Master điều khiển.
- Hỗ trợ nhiều Master và Slave trên một đường truyền
-Tốc Độ Truyền (Baud Rate): Thông thường 100 kbps, 400 kbps đối với STM32F4( bit trên giây)

![Connect with orther](https://upload.wikimedia.org/wikipedia/commons/thumb/3/3e/I2C.svg/220px-I2C.svg.png)

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

**Cờ quan trọng trong IC2:**
- I2C_FLAG_TXE:Được set khi thanh ghi truyền (Transmit Data Register) trống và có thể gửi dữ liệu mới.
- I2C_FLAG_RXNE:Được set khi thanh ghi nhận (Receive Data Register) không trống và có dữ liệu để đọc.
- I2C_FLAG_AF :Được set khi không nhận được ACK từ thiết bị Slave.
- I2C_FLAG_OVR:Được set khi có lỗi Overrun xảy ra trong quá trình truyền dữ liệu.
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
  - 1 dây là CAN high: điện áp dao động từ 2.5 – 3.75 V
  - 1 dây là CAN low: điện áp dao động từ 1.25 – 2.5 V

</details>
</details>

<details>
  <summary><h3>Interrupt  </h3></summary>
<details>
  <summary><h4>External interrupt </h4></summary>

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

- ADC Analog to Digital Convert là bộ chuyển đổi tương tự sang số.Cho phép chuyển đổi tín hiệu analog như điện áp , dòng điện ,ánh sáng .. thông số thay đổi liên tục thành dạng số để máy tính hoặc VXL xử lý
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/4e15c95b-de89-4019-af49-143daffd8e26)
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/bc01ddc4-82b8-4a6f-8ea6-0d39a13d3768)
- Độ phân giải (resolution):Đó là số bit mà ADC sử dụng để biểu diễn giá trị đầu vào trong tín hiệu số .Tính theo Bit bộ ADC có độ phân giải 12 Bit sẽ có 2^12 giá trị.ADC có độ phân giải càng lớn thì mô phỏng tín hiệu analog càng mịn.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/b9b2600b-1a30-4aa1-ae3b-8361ef724222)
-  Tần số lấy mẫu: số lần ADC chuyển đổi tín hiệu analog thành tín hiệu số trong một đơn vị thời gian.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/c4cd8997-b0e7-4f4b-8af6-10f7786700a6)

**ADC trong STM3207.**
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/22085530-0851-4946-8000-bb02e601d350)

- STM32F4 có 3 bộ ADC
- Thanh ghi dữ liệu là 16 bit, chuyển đổi là 12bit, thanh ghi này sẽ xác định dữ liệu sẽ được căn lề bên trái hoặc phải
- Có 19 kênh , 16 kênh đo từ bên ngoài ,2 bên trong và 1 đo Vpin
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/7d544f34-6e85-4ae2-8097-caaef649f919)

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/fed58cd4-a937-48b8-9058-bc926a0d9e97)

![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/b5d64739-049e-441c-80cb-f4ac10dd458b)
- Cấu hình chân ADC ở PA0
<details>
<summary>CODE_STM32F4</summary>

```C
#include "stm32f4xx.h"

#define SPI1_NSS 	GPIO_Pin_4
#define SPI1_SCK	GPIO_Pin_5
#define SPI1_MISO 	GPIO_Pin_6
#define SPI1_MOSI 	GPIO_Pin_7
#define SPI1_GPIO 	GPIOA

void delay (uint32_t time){
	uint32_t i;
	for (i = 0; i< time; i++){
	}
	
}
void RCC_Config(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);// ADC
	
}

void GPIO_Config(){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = SPI1_NSS|SPI1_SCK|SPI1_MISO|SPI1_MOSI;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(SPI1_GPIO,&GPIO_InitStruct); 

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,1);
	
	//CAU HINH CHAN ADC
	
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AN; 
	GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_0  ; 
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void ADC_config(){
	ADC_InitTypeDef ADC_InitStructure;
	ADC_StructInit(&ADC_InitStructure);
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b; // Ð? phân gi?i ADC
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 1;
  ADC_Init(ADC1, &ADC_InitStructure);
  ADC_Cmd(ADC1, ENABLE);
}
void SPI_Config(){
	SPI_InitTypeDef SPI_InitStruct;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128; //84mhz /16
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_16b;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 10;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI_InitStruct);
	SPI_Cmd(SPI1,ENABLE);
	
}
void SPI_Trans(uint8_t arr ){
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_SendData(SPI1,arr);
	while(!SPI_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==0);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}

uint8_t arr[4]={5,2,3,4};
uint16_t val;
int main(){
	
	RCC_Config();
	GPIO_Config();
	SPI_Config();
	ADC_config();
	while(1){
		// TRUYEN DU LIEU spi
		//for(uint8_t i=0;i<4;i++){	
			//SPI_Trans(arr[i]);		 
			//delay(1000000);
		///}
		
		ADC_SoftwareStartConv(ADC1);
		while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
			val= ADC_GetConversionValue(ADC1);
			SPI_Trans(val);
					
	}
	
}
```

</details>


</details> 
<details>
  <summary><h3>DMA</h3></summary>

**DMA – Direct memory access được sử dụng với mục đích truyền data với tốc độ cao từ thiết bị ngoại vi đến bộ nhớ cũng như từ bộ nhớ đến bộ nhớ**
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/cce6b54e-d870-4dc0-b413-6482951feb9a)

- DMA có thể điều khiển data truyền từ :
	+ Bộ nhớ đến Peripheral 
	+ Ngược lại, Periph đến Bộ nhớ.
	+ Giữa 2 vùng nhớ.
- Không thông qua data bus  của CPU. 
- Giữ cho tài nguyên của CPU được rảnh rỗi cho các thao tác khác. Đồng thời tránh việc data nhận về từ ngoại vi bị mất mát.

- Sơ đồ khối bộ DMA.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/36c6a3e8-3412-4c96-ae29-11ea7bbcc439)

- STM32F4 có 2 bộ DMA với nhiều kênh, mỗi kênh có nhiều ngoại vi có thể dùng DMA:


![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/1f242652-a0d1-4dff-a3a1-78f46c894e84)
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/c79dec05-7b5b-4ab5-ba82-f5472c5b7009)

- STM32F4 có 4 chế độ hoạt động:

	+	Circular Buffer Mode: DMA có thể được cấu hình để hoạt động trong chế độ vòng lặp với khả năng tự động quay lại địa chỉ ban đầu sau khi hoàn thành mỗi lần truyền.

	+	Normal Mode: Truyền dữ liệu một lần và sau đó dừng lại.

	+	Double Buffer Mode: DMA có thể được cấu hình để truyền dữ liệu giữa hai bộ đệm, giúp giảm thiểu thời gian chờ khi một bộ đệm đang được truyền dữ liệu, trong khi bộ đệm khác có thể được chuẩn bị cho truyền tiếp theo.

	+	Peripheral Increment Mode: Cho phép tăng địa chỉ của bộ nhớ đích hoặc nguồn dữ liệu sau mỗi lần truyền.

	+ Memory Increment Mode: Cho phép tăng địa chỉ của bộ nhớ đích hoặc nguồn dữ liệu sau mỗi lần truyền.

**Cấu hình DMA**

- Không như các ngoại vi khác, DMA cần được cấp xung từ AHB, cả 2 bộ DMA đều có xung cấp từ AHB. Ngoài ra cần cấp xung cho AFIO.
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/d48dc46a-b8f1-4ab5-8baa-d44c2cd8aa2e)


</details>


<details>
  <summary><h3>Booting</h3></summary>

**Quá Trình Booting**
- là quá trình khởi động (hoặc restart) MCU 

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
	
	+ Exception Number: Số thứ tự của ngắt
	+ IRQ Number: Số thứ tự của ngắt đặc biệt 
	+ Offset: Địa chỉ offset của vector từ địa chỉ bắt đầu của bảng vector.
	+ Vector: Tên của ngắt hoặc sự kiện tương ứng với vector đó
- Dưới đây là một số vector quan trọng:
	+ Reset Vector (Number 1): Được gọi khi vi điều khiển được khởi động lại.
	+ Systick Vector (Number 15): Được gọi khi sự kiện ngắt Systick xảy ra.
	+ NMI Vector (Number 2): Được gọi khi sự kiện NMI xảy ra.
	+ Hard Fault Vector (Number 3): Được gọi khi sự kiện ngắt Hard Fault xảy ra.
	+ SVCall Vector (Number 11): Được gọi khi sự kiện ngắt SVCall xảy ra.
	+ PendSV Vector (Number 14): Được gọi khi sự kiện ngắt PendSV xảy ra.

**Quá trình khởi động MCU**
![image](https://github.com/khokhanptv/ADVANCED-CC-ALGORITHM-T122023/assets/136571945/8d67675a-fcd4-413d-95e4-fdadcf2ea23e)
- Sau khi reset ,MCU khởi tạo giá trị SP bằng cách đọc giá trị tại địa chỉ 0X00000000  
- Tiếp theo VDK sẽ đọc giá trị của địa chỉ 0x0000004  (vector table ) cụ thể là vector reset
- Sau đó sẽ nhảy đến hàm main và thực hiện chương trình ứng dụng trong hàm main.

**Bootloader là gì?**
- Bootloader là một chương trình nằm ở vùng nhớ đặc biệt của bộ nhớ trong thiết bị nhúng. Chức năng chính của nó cho phép cập nhật hoặc nạp firmware 



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

</details>