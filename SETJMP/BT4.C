#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char exception_message[100]; // Dung lưu trữ thông điệp lỗi

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, msg) { \
    int i = 0; \
    while ((msg[i] != '\0') && (i < sizeof(exception_message) - 1)) { \
        exception_message[i] = msg[i]; \
        i++; \
    } \
    exception_message[i] = '\0'; \
    longjmp(buf, (x)); \
}

double divide(int a, int b) {
    if (b == 0) {
        THROW(1, "Error: Divide by 0!"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

// Hàm thử nghiệm ném một loại lỗi khác nhau
void testFunction(int value) {
    if (value < 0) {
        THROW(2, "Error: Negative value!"); // Mã lỗi 2 cho giá trị âm
    }
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("%s\n", exception_message);
    }

    TRY {
        testFunction(-5); // Thử nghiệm hàm với giá trị âm
    } CATCH(2) {
        printf("%s\n", exception_message);
    }

    // Các xử lý khác của chương trình
    return 0;
}
