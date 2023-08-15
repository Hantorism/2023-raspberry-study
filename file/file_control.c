#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s <파일 이름>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // 파일 열기 및 생성 (시스템 콜 사용)
    int file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (file == -1) {
        printf("파일 열기 오류\n");
        return 1;
    }

    // "Hello World" 쓰기
    char message[] = "Hello World\n";
    long bytes_written = write(file, message, strlen(message));
    
    if (bytes_written == -1) {
        printf("파일 쓰기 오류\n");
        close(file);
        return 1;
    }

    // 파일의 위치를 이동하여 읽기
    long long offset = lseek(file, 6, SEEK_SET);  // "World" 부분부터 읽어옴
    if (offset == -1) {
        printf("lseek 오류\n");
        close(file);
        return 1;
    }

    // 파일 내용 출력 (printf 사용)
    char buffer[100];
    long bytes_read = read(file, buffer, sizeof(buffer));
    
    if (bytes_read == -1) {
        printf("파일 읽기 오류\n");
        close(file);
        return 1;
    }

    buffer[bytes_read] = '\0';  // Null-terminate the buffer
    printf("파일 내용 (offset %ld부터):\n%s", offset, buffer);

    // 파일 닫기
    close(file);

    return 0;
}
