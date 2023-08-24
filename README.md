# 2023 Hantor Raspberry Pi System Programming Study Example

### 개요

본 레포지토리는 아주대학교 소프트웨어학과 소학회 한터의 2023학년도 하계 시스템 프로그래밍 스터디의 예시 소스코드 입니다.

<br>

### 프로젝트 상세

본 레포지토리는 시스템 프로그래밍 관련 프로젝트를 더욱 손쉽게 진행할 수 있도록 `GPIO`, `PWM`, `SPI` 등의 여러 인터페이스에 대한 실습 소스코드를 제공합니다.

각 실습 소스코드에 대한 설명은 다음과 같습니다.
- `FILE`: 파일 입출력 라이브러리와 시스콜 실습을 위한 소스코드입니다.
- `GPIO`: GPIO 인터페이스 제어 실습을 위한 소스코드입니다.
- `PWM`: PWM 인터페이스 제어 실습을 위한 소스코드입니다.
- `SPI`: SPI 인터페이스 제어 실습을 위한 소스코드입니다.
- `WIRINGPI`: WiringPi 라이브러리 실습을 위한 소스코드입니다.
- `W1`: 1-Wire 인터페이스 제어 실습을 위한 소스코드입니다.
- `THREAD`: 스레드 및 프로세스 실습을 위한 소스코드입니다.
- `SOCKET`: 소켓 통신 및 소켓 프로그래밍 실습을 위한 소스코드입니다.
- `PROJECT`: 미니 프로젝트 진행을 위한 템플릿 소스코드입니다.

<br>

### 프로젝트 실행

``` bash
user@raspberrypi:~/2023-raspberry-study $ cd [directory]
user@raspberrypi:~/2023-raspberry-study/[directory] $ gcc -o [output].out [source].c
user@raspberrypi:~/2023-raspberry-study/[directory] $ ./[output].out
```

<br>

### 참고 자료
- 2022-2학기 시스템 프로그래밍 실습 강의 자료(한창헌, 염현석)
- 2022-2학기 시스템 프로그래밍 FDPS Master, FDPS Slave 프로젝트(강동우, 송영범, 이기현)