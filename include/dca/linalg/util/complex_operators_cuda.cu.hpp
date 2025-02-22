// Copyright (C) 2021 ETH Zurich
// Copyright (C) 2021 UT-Battelle, LLC
// All rights reserved.
//
// See LICENSE for terms of usage.
// See CITATION.md for citation guidelines, if DCA++ is used for scientific publications.
//
// Author: Raffaele Solca' (rasolca@itp.phys.ethz.ch)
//         Peter Doak (doakpw@ornl.gov)
//

/** \file
 *  This file provides operators (+,-,*,/) for cuComplex and cuDoubleComplex.
 *  For HIP we just use the magma_operators and magmaComplex types
 */
#ifndef DCA_LINALG_UTIL_COMPLEX_OPERATORS_CUDA_CU_HPP
#define DCA_LINALG_UTIL_COMPLEX_OPERATORS_CUDA_CU_HPP

#include "dca/config/haves_defines.hpp"
#include "dca/platform/dca_gpu.h"
#include "dca/platform/dca_gpu_complex.h"
#include "dca/linalg/util/atomic_add_cuda.cu.hpp"

namespace dca {
namespace linalg {
// dca::linalg::

// magma_operators.h defines these operators
#ifdef DCA_HAVE_CUDA
__device__ __host__ static __inline__ cuComplex operator+(const cuComplex a, const cuComplex b) {
  return cuCaddf(a, b);
}
__device__ __host__ static __inline__ cuComplex operator-(const cuComplex a, const cuComplex b) {
  return cuCsubf(a, b);
}
__device__ __host__ static __inline__ cuComplex operator*(const cuComplex a, const cuComplex b) {
  return cuCmulf(a, b);
}
__device__ __host__ static __inline__ cuComplex operator/(const cuComplex a, const cuComplex b) {
  return cuCdivf(a, b);
}
__device__ __host__ static __inline__ cuComplex operator*=(cuComplex& a, const cuComplex b) {
  a = a * b;
  return a;
}
__device__ __host__ static __inline__ cuComplex operator+=(cuComplex& a, const cuComplex b) {
  a = a + b;
  return a;
}
__device__ __host__ static __inline__ cuComplex operator-=(cuComplex& a, const cuComplex b) {
  a = a - b;
  return a;
}

__device__ __host__ static __inline__ cuComplex operator-(cuComplex a) {
  a.x = -a.x;
  a.y = -a.y;
  return a;
}
__device__ __host__ static __inline__ cuComplex operator*(const cuComplex a, const float b) {
  return make_cuComplex(a.x * b, a.y * b);
}
__device__ __host__ static __inline__ cuComplex operator*(const float a, const cuComplex b) {
  return make_cuComplex(a * b.x, a * b.y);
}
__device__ __host__ static __inline__ cuComplex conj(cuComplex a) {
  a.y = -a.y;
  return a;
}
#endif

// magma_operators.h defines these operators
#ifdef DCA_HAVE_CUDA
__device__ __host__ static __inline__ cuDoubleComplex operator+(const cuDoubleComplex a,
                                                                const cuDoubleComplex b) {
  return cuCadd(a, b);
}
__device__ __host__ static __inline__ cuDoubleComplex operator-(const cuDoubleComplex a,
                                                                const cuDoubleComplex b) {
  return cuCsub(a, b);
}
__device__ __host__ static __inline__ cuDoubleComplex operator*(const cuDoubleComplex a,
                                                                const cuDoubleComplex b) {
  return cuCmul(a, b);
}
__device__ __host__ static __inline__ cuDoubleComplex operator/(const cuDoubleComplex a,
                                                                const cuDoubleComplex b) {
  return cuCdiv(a, b);
}
__device__ __host__ static __inline__ cuDoubleComplex operator*=(cuDoubleComplex& a,
                                                                 const cuDoubleComplex b) {
  a = a * b;
  return a;
}
__device__ __host__ static __inline__ cuDoubleComplex operator+=(cuDoubleComplex& a,
                                                                 const cuDoubleComplex b) {
  a = a + b;
  return a;
}
__device__ __host__ static __inline__ cuDoubleComplex operator-=(cuDoubleComplex& a,
                                                                 const cuDoubleComplex b) {
  a = a - b;
  return a;
}
  
__device__ __host__ static __inline__ cuDoubleComplex operator-(cuDoubleComplex a) {
  a.x = -a.x;
  a.y = -a.y;
  return a;
}
__device__ __host__ static __inline__ cuDoubleComplex operator*(const cuDoubleComplex a,
                                                                const double b) {
  return make_cuDoubleComplex(a.x * b, a.y * b);
}
__device__ __host__ static __inline__ cuDoubleComplex operator*(const double a,
                                                                const cuDoubleComplex b) {
  return make_cuDoubleComplex(a * b.x, a * b.y);
}
__device__ __host__ static __inline__ cuDoubleComplex conj(cuDoubleComplex a) {
  a.y = -a.y;
  return a;
}
#endif


}  // linalg
}  // dca

#endif  // DCA_LINALG_UTIL_COMPLEX_OPERATORS_CUDA_CU_HPP
