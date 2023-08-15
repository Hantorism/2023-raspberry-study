#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s <파일 이름> <권한>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    mode_t permission = strtol(argv[2], 0, 8);

    // 파일 열기 및 생성 (시스템 콜 사용)
    int fd = open(filename, O_CREAT | O_WRONLY, permission);

    if (fd == -1) {
        perror("파일 생성 오류");
        return 1;
    }

    // 파일에 "Hello World" 쓰기
    if (write(fd, "Hello World\n", strlen("Hello World\n")) == -1) {
        perror("파일 쓰기 오류");
        close(fd);
        return 1;
    }

    // 파일 닫기
    close(fd);

    // 파일 열기 및 읽기 (시스템 콜 사용)
    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("파일 열기 오류");
        return 1;
    }

    // 파일 내용 출력
    char buffer[100];
    ssize_t bytes_read;
    
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        perror("파일 읽기 오류");
        close(fd);
        return 1;
    }

    // 파일 닫기
    close(fd);

    return 0;
}
