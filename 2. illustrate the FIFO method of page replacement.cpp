#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGE_FRAMES 10

int main() {
    int page_frames[MAX_PAGE_FRAMES];
    int page_reference_seq[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int num_page_frames = 3;
    int num_page_reference = sizeof(page_reference_seq) / sizeof(page_reference_seq[0]);

    int i, j, k, fault_count = 0;
    bool found;

    // Initialize the page frames to -1
    for (i = 0; i < num_page_frames; i++) {
        page_frames[i] = -1;
    }

    // Traverse the page reference sequence
    for (i = 0; i < num_page_reference; i++) {
        found = false;
        // Check if the page is already in a frame
        for (j = 0; j < num_page_frames; j++) {
            if (page_frames[j] == page_reference_seq[i]) {
                found = true;
                break;
            }
        }
        // If the page is not in a frame, replace the oldest page in the queue
        if (!found) {
            page_frames[fault_count % num_page_frames] = page_reference_seq[i];
            fault_count++;
        }
        // Print the current state of the page frames
        printf("Page frames: ");
        for (k = 0; k < num_page_frames; k++) {
            if (page_frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", page_frames[k]);
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", fault_count);
    return 0;
}
