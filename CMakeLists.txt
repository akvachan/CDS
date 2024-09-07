
cmake_minimum_required(VERSION 3.10)

project(CDS VERSION 1.0)

# Exporting json config file for the clangd (static analysis, lsp stuff...)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Setting C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Where to search for the header files
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/templates)

# Add source and test code directories
add_subdirectory(src)
#add_subdirectory(test)

# Create executable 
add_executable(${PROJECT_NAME} main.cpp)

# Link src library to the executable
if(TARGET CDSLIB)
target_link_libraries(${PROJECT_NAME} PRIVATE CDSLIB)
endif()
