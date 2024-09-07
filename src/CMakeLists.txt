file(GLOB SOURCES "./*.cpp")

if(SOURCES)
    add_library(CDSLIB STATIC ${SOURCES})
endif()
