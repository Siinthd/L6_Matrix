cmake_minimum_required(VERSION 3.5)

if(DEFINED ENV{GITHUB_RUN_NUMBER})
    project(Matrix VERSION 1.0.$ENV{GITHUB_RUN_NUMBER})
else()
    project(Matrix VERSION 1.0.1)
endif()

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")


include_directories(${SOURCE_PATH})

# find packages
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# target version_lib
configure_file(${SOURCE_PATH}/version.h.in version.h)
add_library(version_lib ${SOURCE_PATH}/version.cpp)
target_include_directories(version_lib
    PUBLIC "${CMAKE_BINARY_DIR}"
)
target_compile_options(version_lib PRIVATE
    -Wall -Wextra -pedantic -Werror
)


add_executable(Matrix ${SOURCE_PATH}/main.cpp)


set_target_properties(Matrix PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )
        
        
install(TARGETS Matrix RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEB_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${Matrix_VERSION})
set(CPACK_PACKAGE_CONTACT razelim@list.ru)
include(CPack)
