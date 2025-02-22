# Initial cache list for Summit
#
# Usage: cmake -C /path/to/this/file /path/to/DCA/source -D<option>=<value> ...

# Prevent CMake from searching for BLAS and LAPACK libraries.
# Paths to IBM's ESSL (preferred) and NETLIB-LAPACK will be set manually.
set(DCA_HAVE_LAPACK TRUE CACHE INTERNAL "If set to TRUE, prevents CMake from searching for LAPACK.")
# To give ESSL precedence it needs to be specified before NETLIB.
set(LAPACK_LIBRARIES $ENV{OLCF_ESSL_ROOT}/lib64/libessl.so;$ENV{OLCF_NETLIB_LAPACK_ROOT}/lib64/liblapack.so;$ENV{OLCF_NETLIB_LAPACK_ROOT}/lib64/libblas.so CACHE FILEPATH "Libraries to link against to use LAPACK.")

# Set the include directory for the ESSL library.
set(DCA_ESSL_INCLUDES $ENV{OLCF_ESSL_ROOT}/include CACHE PATH "Path to ESSL include directory.")
mark_as_advanced(DCA_ESSL_INCLUDES)

option(DCA_WITH_ADIOS2 "Enable ADIOS2 support." ON)
set(ADIOS2_DIR "/gpfs/alpine/world-shared/cph102/epd/ADIOS2/build" CACHE PATH "Directory for ADIOS2")

# Use jsrun for executing the tests.
set(TEST_RUNNER "jsrun" CACHE STRING "Command for executing (MPI) programs.")
set(MPIEXEC_NUMPROC_FLAG "-n" CACHE STRING
  "Flag used by TEST_RUNNER to specify the number of processes.")
# Use 1 resource set with 1 GPU and 5 cores for executing the tests.
set(MPIEXEC_PREFLAGS "-a 1 -g 1 -c 5" CACHE STRING
  "Flags to pass to TEST_RUNNER directly before the executable to run.")
# The flag "--smpiargs=none" is needed to execute tests with no MPI functionalities.
set(SMPIARGS_FLAG_NOMPI "--smpiargs=none" CACHE STRING
  "Spectrum MPI argument list flag for serial tests.")
# Let's keep this option in case we need it again in the future.
set(SMPIARGS_FLAG_MPI "--smpiargs=\"-gpu\"" CACHE STRING "Spectrum MPI argument list flag for MPI tests.")

# Enable the GPU support.
option(DCA_WITH_CUDA "Enable GPU support." ON)
option(DCA_WITH_GPU_AWARE_MPI "Enable GPU aware MPI." ON)
set(CMAKE_CUDA_ARCHITECTURES 70 CACHE STRING "GPU Hardware Architecture.")

# Summit's static CUDA runtime is bugged.
option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)

# For the GPU support we also need MAGMA.
set(MAGMA_DIR "/gpfs/alpine/world-shared/cph102/epd/magma_cuda11" CACHE PATH
  "Path to the MAGMA installation directory. Hint for CMake to find MAGMA.")

option(DCA_WITH_TESTS_FAST "Fast minimal tests" ON)

# FFTW paths.
set(FFTW_INCLUDE_DIR $ENV{OLCF_FFTW_ROOT}/include CACHE PATH "Path to fftw3.h.")
set(FFTW_LIBRARY $ENV{OLCF_FFTW_ROOT}/lib/libfftw3.so CACHE FILEPATH "The FFTW3(-compatible) library.")
