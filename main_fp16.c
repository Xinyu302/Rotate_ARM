#include <stdio.h>
#include <stdlib.h>
#include <arm_neon.h>
#include "my_tinycv_c.h"

typedef float16_t dtype;

void printMat(const TinyMat *mat) {
    dtype *data = mat->data;
    for (int c = 0; c < mat->channels; c++) {
        printf("channel %d:\n", c);
        for (int i = 0; i < mat->rows; i++) {
            for (int j = 0; j < mat->cols; j++) {
                if (sizeof(dtype) == 1) // uint8_t
                    printf("%d ", data[(i * mat->cols + j) * mat->channels + c]);
                else 
                    printf("%f ", data[(i * mat->cols + j) * mat->channels + c]);
            }
            printf("\n");
        }
    }
}

void init_mat(const TinyMat *mat) {
    dtype *data = mat->data;
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            for (int c = 0; c < mat->channels; c++) {
                data[(i * mat->cols + j) * mat->channels + c] = i * mat->cols + j;
            }
        }
    }
}

int main() {
    int rows = 9;
    int cols = 9;
    int channels = 3;
    dtype* data = malloc(rows * cols * channels * sizeof(dtype));
    dtype* dst_data = malloc(rows * cols * channels * sizeof(dtype));
    TinyMat mat = {rows, cols, /*channels*/ channels, data};
    TinyMat dst = {rows, cols, /*channels*/ channels, dst_data};
    init_mat(&mat);
    armcommon_tinycv_rotate_fp16(&mat, &dst, false);
    printMat(&mat);
    printMat(&dst);
    return 0;
}