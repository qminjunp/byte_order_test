#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

uint32_t my_ntohl (uint32_t n){
    uint32_t n1 = (n & 0xff000000) >>24;
    uint32_t n2 = (n & 0x00ff0000) >>8;
    uint32_t n3 = (n & 0x0000ff00) <<8;
    uint32_t n4 = (n & 0x000000ff) <<24;
    return n1 | n2 | n3 | n4;
}

uint32_t filetoint(char* file) {
    FILE* fp = fopen(file, "rb");
    if (fp == nullptr) {
        printf("input is blank");
        return 1;
    }

    uint32_t n;
    size_t LEN = fread(&n, 1, sizeof(n), fp);
    if (LEN != sizeof(n)) {
        printf("read %lu\n, Fail to read file", LEN);
        return 1;
    }
    n = my_ntohl(n);
    fclose(fp);
    return n;
    }

int main(int argc, char *argv[]) {
    if (argc != 3) {
            return 1;
        }
    uint32_t n1 = filetoint(argv[1]);
    uint32_t n2 = filetoint(argv[2]);

    printf ("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);
    return 0;
    }
