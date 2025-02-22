# Advanced exact diagonalization integration tests

dca_add_gtest(hamiltonian_test
  GTEST_MAIN
  INCLUDE_DIRS ${FFTW_INCLUDE_DIR}
  LIBS function json time_and_frequency_domains cluster_domains enumerations quantum_domains ${LAPACK_LIBRARIES}
       ${DCA_GPU_LIBS} ${UTIL_LIBS})

set(IO_LIBS gpu_utils dca_hdf5)
if (DCA_HAVE_ADIOS2)
  set(IO_LIBS dca_adios2 ${IO_LIBS})
endif()

dca_add_gtest(ed_cluster_solver_single_site_test
  GTEST_MAIN
  CUDA
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS}
  LIBS function json time_and_frequency_domains cluster_domains enumerations quantum_domains ${IO_LIBS} timer
       dca_algorithms ${LAPACK_LIBRARIES} ${DCA_GPU_LIBS})

dca_add_gtest(ed_cluster_solver_four_site_test
  EXTENSIVE
  GTEST_MAIN
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS} 
  LIBS function json time_and_frequency_domains cluster_domains enumerations quantum_domains ${IO_LIBS} timer
       dca_algorithms ${LAPACK_LIBRARIES} ${DCA_GPU_LIBS})
