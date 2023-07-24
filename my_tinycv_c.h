#ifndef TINYCV_C_H_
#define TINYCV_C_H_

#include "stdbool.h"
#include "stddef.h"
#include "stdint.h"
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief the simple Matrix description
 */
typedef struct TinyMat {
    size_t rows;
    size_t cols;
    size_t channels;
    void* data;
} TinyMat;

/**
 * \fn armcommon_tinycv_rotate_ui8
 * \brief Rotate image 90 degree, clockwise indicate the direction.
 *
 * \param[in] src Input mat ptr.
 * \param[out] dst Output mat ptr.
 * \param[in] clockwise The rotate direction.
 *
 */
void armcommon_tinycv_rotate_ui8(const TinyMat* src, const TinyMat* dst, bool clockwise);


#ifdef __cplusplus
}
#endif
#endif
// vim: syntax=cpp.doxygen foldmethod=marker foldmarker=f{{{,f}}}
