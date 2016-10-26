aux_source_directory(.  SOURCES)

set(CMAKE_AUTORCC On)

# Block qt debug output
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${CMAKE_SOURCE_DIR}/resouces.qrc)
target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Svg
    Qt5::Qml
    Qt5::Quick)
