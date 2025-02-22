#!/bin/bash
#
# Loads all modules that are required to build DCA++ on ORNL's Spock cluster.
# A reset is done at the beginning to restore to the default programming environment on Spock.
# This is for development only at this point.
#
# Usage: source spock_load_modules.sh

module reset
module load gcc/10.3.0
module load openblas
module load hdf5
module load rocm/4.3.0
module load fftw
module load cmake
module load ninja

export CC=mpicc
export CXX=mpicxx
