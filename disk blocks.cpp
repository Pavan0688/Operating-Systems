#include <stdio.h>

#define DISK_BLOCK_SIZE 8192
#define POINTER_SIZE 4
#define NUM_DIRECT_BLOCKS 12

int main() {
    int maxFileSize = 0;

    
    maxFileSize += NUM_DIRECT_BLOCKS * DISK_BLOCK_SIZE;

    
    maxFileSize += (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;

   
    maxFileSize += (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;

   
    maxFileSize += (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * (DISK_BLOCK_SIZE / POINTER_SIZE) * DISK_BLOCK_SIZE;

    printf("Maximum file size: %d bytes\n", maxFileSize);
    return 0;
}
