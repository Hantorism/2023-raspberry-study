#include <stdio.h>
#include <stdlib.h>

int main() {
    // 파일 열기 및 생성
    FILE *file = fopen("numbers.txt", "w");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 숫자 입력 받기
    int num1, num2;

    printf("첫 번째 숫자를 입력하세요: ");
    scanf("%d", &num1);

    printf("두 번째 숫자를 입력하세요: ");
    scanf("%d", &num2);

    // 숫자 파일에 쓰기
    fprintf(file, "%d %d\n", num1, num2);

    // 파일 닫기
    fclose(file);

    // 파일 열기
    file = fopen("numbers.txt", "r");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일에서 숫자 읽어오기
    int read_num1, read_num2;

    fscanf(file, "%d %d", &read_num1, &read_num2);

    // 파일 닫기
    fclose(file);

    // 읽은 숫자로 연산 수행
    int sum = read_num1 + read_num2;
    int product = read_num1 * read_num2;

    // 결과 출력
    printf("첫 번째 숫자: %d\n", read_num1);
    printf("두 번째 숫자: %d\n", read_num2);
    printf("합: %d\n", sum);
    printf("곱: %d\n", product);

    // 문자열 생성 및 형식화된 문자열 출력
    char formatted_string[100];
    sprintf(formatted_string, "합: %d, 곱: %d\n", sum, product);
    printf("형식화된 문자열: %s", formatted_string);

    // 형식화된 문자열에서 데이터 읽기
    int read_sum, read_product;
    sscanf(formatted_string, "합: %d, 곱: %d\n", &read_sum, &read_product);

    printf("형식화된 문자열에서 읽은 합: %d\n", read_sum);
    printf("형식화된 문자열에서 읽은 곱: %d\n", read_product);

    // 숫자를 문자열로 변환하여 버퍼에 저장
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "합: %d, 곱: %d\n", sum, product);

    printf("snprintf로 생성된 문자열: %s", buffer);

    return 0;
}
