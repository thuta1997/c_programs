#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t temperature = 2500;

    uint16_t *ptr = &temperature;

    printf("Temperature = %u\n", temperature);
    printf("Address     = %p\n", &temperature);
    printf("Pointer     = %p\n", ptr);
    printf("Value       = %u\n", *ptr);

    return 0;
}