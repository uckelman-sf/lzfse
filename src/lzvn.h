#ifndef LZVN_H
#define LZVN_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#  define __attribute__(X)
#  pragma warning(disable : 4068)
#endif

#if defined(LZFSE_DLL)
#  if defined(_WIN32) || defined(__CYGWIN__)
#    if defined(LZFSE_DLL_EXPORTS)
#      define LZFSE_API __declspec(dllexport)
#    else
#      define LZFSE_API __declspec(dllimport)
#    endif
#  endif
#endif

#if !defined(LZFSE_API)
#  if __GNUC__ >= 4
#    define LZFSE_API __attribute__((visibility("default")))
#  else
#    define LZFSE_API
#  endif
#endif

LZFSE_API size_t lzvn_encode_scratch_size(void);

LZFSE_API size_t lzvn_encode_buffer(void *__restrict dst,
                                    size_t dst_size,
                                    const void *__restrict src,
                                    size_t src_size,
                                    void *__restrict work);

LZFSE_API size_t lzvn_decode_buffer(void *__restrict dst,
                                    size_t dst_size,
                                    const void *__restrict src,
                                    size_t src_size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LZVN_H */
