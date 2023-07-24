#include <stdio.h>
#include <stdlib.h>
#include "my_tinycv_c.h"

typedef uint8_t dtype;

void printMat(const TinyMat *mat) {
    dtype *data = mat->data;
    for (int c = 0; c < mat->channels; c++) {
        printf("channel %d:\n", c);
        for (int i = 0; i < mat->rows; i++) {
            for (int j = 0; j < mat->cols; j++) {
                if (sizeof(dtype) == 1) // uint8_t
                    printf("%d ", data[i * mat->cols + j]);
                else 
                    printf("%f ", data[i * mat->cols + j]);
            }
            printf("\n");
        }
    }
}

void init_mat(const TinyMat *mat) {
    dtype *data = mat->data;
    for (int c = 0; c < mat->channels; c++) {
        for (int i = 0; i < mat->rows; i++) {
            for (int j = 0; j < mat->cols; j++) {
                data[i * mat->cols + j] = i * mat->cols + j;
            }
        }
    }
}

int main() {
    int rows = 16;
    int cols = 16;
    dtype* data = malloc(rows * cols * sizeof(dtype));
    dtype* dst_data = malloc(rows * cols * sizeof(dtype));
    TinyMat mat = {rows, cols, /*channels*/ 1, data};
    TinyMat dst = {rows, cols, /*channels*/ 1, dst_data};
    init_mat(&mat);
    armcommon_tinycv_rotate_ui8(&mat, &dst, true);
    printMat(&mat);
    printMat(&dst);
    return 0;
}