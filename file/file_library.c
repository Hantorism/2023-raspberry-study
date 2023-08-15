#include <stdio.h>

int main() {
    // 파일 생성 및 열기
    FILE *file = fopen("simple.txt", "w");
    
    if (file == NULL) {
        printf("파일을 생성할 수 없습니다.\n");
        return 1;
    }

    // 파일에 "Hello World" 쓰기
    fprintf(file, "Hello World\n");
    
    // 파일 닫기
    fclose(file);

    // 파일 열기
    file = fopen("simple.txt", "r");
    
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일 내용 출력
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    
    // 파일 닫기
    fclose(file);

    return 0;
}
