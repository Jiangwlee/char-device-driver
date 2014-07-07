#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp0 = NULL;
    char buffer[4096];

    // init
    strcpy(buffer, "Hello, this is a test of device driver!");
    printf("Buffer : %s\n", buffer);

    // open the device
    fp0 = fopen("/dev/chardev0", "r+");
    if (!fp0) {
        printf("Open /dev/chardev0 fail!\n");
        return -1;
    }

    fwrite(buffer, sizeof(buffer), 1, fp0);

    // clear the buffer
    memset(buffer, 0, 4096);

    // read from the device
    fread(buffer, 4096, 1, fp0);

    printf("Buffer after read : %s\n", buffer);

    fclose(fp0);

    return 0;
}
