

#ifndef _RH_LIB_H
#define _RH_LIB_H

#include "RH_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================================================================
 > Standard
============================================================================================================================*/
uint8_t     __swap_8BIT   (uint8_t   x);
uint16_t    __swap_16BIT  (uint16_t  x);
uint32_t    __swap_32BIT  (uint32_t  x);
uint32_t    __swap_nBIT   (uint32_t  x, size_t n);
uint32_t    __swap_DATA   (uint32_t  x);
 
size_t      __sizeof_BITs (uint32_t  x);
size_t      __sizeof_OCTs (uint32_t  x);
size_t      __sizeof_DECs (uint32_t  x);
size_t      __sizeof_HEXs (uint32_t  x);
 
uint32_t    __Bin2Gray    (uint32_t  x);
uint32_t    __Gray2Bin    (uint32_t  x); //

/*===========================================================================================================================
 > Memory Programming Reference
============================================================================================================================*/

#define __VIRTUAL_HEAP_SIZE_BYTE       (0)
void* __mallocHEAP(size_t size);
void  __freeHEAP(void* ptr);

void* __memsetWORD  (void* __b, uint16_t value, size_t num);
void* __memsetDWORD (void* __b, uint32_t value, size_t num);

void* __memset_Area (void*                __b,int                      value,size_t size,size_t nmenb_line,long xs,long ys,long xe,long ye);
void* __memcpy_Area (void* __restrict__ __dst,const void* __restrict__ __src,size_t size,size_t nmenb_line,long xs,long ys,long xe,long ye);
void* __memgrab_Area(void* __restrict__ __dst,const void* __restrict__ __src,size_t size,size_t nmenb_line,long xs,long ys,long xe,long ye);

#ifdef __cplusplus
}
#endif

#endif
