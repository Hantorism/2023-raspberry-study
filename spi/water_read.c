
#define SPI_DEV_NUM 0

#define INTERVAL 1

int main()
{
    int fd = spi_init(SPI_DEV_NUM);

    if (fd == -1)
    {
        perror("spi_init");
        exit(0);
    }

    if (spi_set(fd) == -1)
    {
        perror("spi_set");
        exit(0);
    }

    int count = 0;

    do
    {
        int water_level = read_adc(fd, 0);

        printf("value = %d\n", water_level);

        sleep(INTERVAL);
    } while (count++ < 10);

    if (spi_final(fd) == -1)
    {
        perror("spi_final");
        exit(0);
    }

    return (0);
}