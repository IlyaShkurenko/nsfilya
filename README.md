# Travis-CI Sample Project (C + CMake)

[![Build Status](https://travis-ci.org/PublicHadyniak/travis-ci-sample.svg?branch=master)](https://travis-ci.org/PublicHadyniak/travis-ci-sample) [![codecov-badge](https://codecov.io/gh/PublicHadyniak/Travis-ci-sample/branch/master/graph/badge.svg)](https://codecov.io/gh/PublicHadyniak/travis-ci-sample)

1. Add [`CodeCoverage.cmake`](https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake) file to `scripts/cmake/` project directory
1. Enable testing and add test coverage config to `CMakeLists.txt` 
(after test executable target setup, see full [file](https://github.com/PublicHadyniak/travis-ci-sample/blob/master/CMakeLists.txt)):

	```
	#
	# Create make test
	#
	enable_testing()
	add_test(unit-tests ${CMAKE_PROJECT_NAME})

	## Coverage
	set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)
	include(CodeCoverage)
	setup_target_for_coverage(${CMAKE_PROJECT_NAME}_coverage ${CMAKE_PROJECT_NAME} coverage)
	SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
	SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
	```
1. Coverage badge link: `https://codecov.io/gh/IlyaShkurenko/nsfilya/branch/master/graph/badge.svg`

