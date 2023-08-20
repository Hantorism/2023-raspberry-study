cmake_minimum_required(VERSION 3.16 )

project(
    FDPS_Master
    VERSION 1.0
    LANGUAGES C
)

set(HEADER_DIRECTORY ./include)
set(SOURCE_DIRECTORY ./src)
set(LIBRARIE_DIRECTORY ./lib)

ADD_LIBRARY (gpio STATIC ${HEADER_DIRECTORY}/gpio.c)
ADD_LIBRARY (pwm STATIC ${HEADER_DIRECTORY}/pwm.c)
ADD_LIBRARY (socket STATIC ${HEADER_DIRECTORY}/socket.c)
ADD_LIBRARY (spi STATIC ${HEADER_DIRECTORY}/spi.c)
ADD_LIBRARY (lcd STATIC ${HEADER_DIRECTORY}/lcd.c)
ADD_LIBRARY (utils STATIC ${HEADER_DIRECTORY}/utils.c)
ADD_LIBRARY (parson STATIC ${LIBRARIE_DIRECTORY}/parson.c)

ADD_EXECUTABLE(
    main.out 
    ${SOURCE_DIRECTORY}/main.c
)

TARGET_LINK_LIBRARIES( 
    main.out
    gpio
    pwm
    socket
    spi
    lcd
    utils
    parson
    pthread
    curl
    wiringPi
)