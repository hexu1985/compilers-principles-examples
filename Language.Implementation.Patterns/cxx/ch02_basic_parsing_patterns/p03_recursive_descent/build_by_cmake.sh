#!/bin/bash

current_dir=$( cd $(dirname ${BASH_SOURCE[0]}) && pwd )
src_dir=${current_dir}
build_dir=${current_dir}/build

cmake -S ${src_dir} -B ${build_dir} -DGTest_DIR=~/local/googletest/lib/cmake/GTest
#-DCMAKE_BUILD_TYPE=Debug
cmake --build ${build_dir} -j 4

