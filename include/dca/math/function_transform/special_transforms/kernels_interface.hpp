// Copyright (C) 2018 ETH Zurich
// Copyright (C) 2018 UT-Battelle, LLC
// All rights reserved.
//
// See LICENSE.txt for terms of usage.
// See CITATION.txt for citation guidelines if you use this code for scientific publications.
//
// Author: Giovanni Balduzzi (gbalduzz@itp.phys.ethz.ch)
//
// Interface to the kernels used by SpaceTransform2DGpu.

#ifndef DCA_MATH_FUNCTION_TRANSFORM_SPECIAL_TRANSFORMS_SPACE_KERNELS_INTERFACE
#define DCA_MATH_FUNCTION_TRANSFORM_SPECIAL_TRANSFORMS_SPACE_KERNELS_INTERFACE
#ifdef DCA_HAVE_GPU

#include "dca/platform/dca_gpu.h"

#include <complex>

namespace dca {
namespace math {
namespace transform {
namespace details {
// dca::math::transform::details::

template <typename Real>
void phaseFactorsAndRearrange(const std::complex<Real>* in, const int ldi, std::complex<Real>* out,
                              const int ldo, const int nb, const int nk, const int nw,
                              const std::complex<Real>* phase_factors, cudaStream_t const stream);


extern template void phaseFactorsAndRearrange<double>(const std::complex<double>* in, const int ldi,
                                               std::complex<double>* out, const int ldo,
                                               const int nb, const int nk, const int nw,
                                               const std::complex<double>* phase_factors,
                                               const cudaStream_t stream);
extern template void phaseFactorsAndRearrange<float>(const std::complex<float>* in, const int ldi,
                                              std::complex<float>* out, const int ldo, const int nb,
                                              const int nk, const int nw,
                                              const std::complex<float>* phase_factors,
                                              cudaStream_t const stream);

}  // namespace details
}  // namespace transform
}  // namespace math
}  // namespace dca

#endif  // DCA_HAVE_GPU
#endif  // DCA_MATH_FUNCTION_TRANSFORM_SPECIAL_TRANSFORMS_SPACE_KERNELS_INTERFACE
