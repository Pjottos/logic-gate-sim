cmake_minimum_required (VERSION 3.15)
project (logic-gate-sim)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

include_directories(${PROJECT_SOURCE_DIR}/include)

# exe
set(EXE_NAME "logic-gate-sim")
add_executable(${EXE_NAME} 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/logic/Component.cpp
    ${PROJECT_SOURCE_DIR}/src/logic/ComponentManager.cpp
    ${PROJECT_SOURCE_DIR}/src/logic/Gate.cpp
    ${PROJECT_SOURCE_DIR}/src/logic/Slot.cpp
    ${PROJECT_SOURCE_DIR}/src/ui/ComponentMenu.cpp
)

# dependencies
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/sfml)
include_directories(${PROJECT_SOURCE_DIR}/ext/sfml/include)
target_link_libraries(${EXE_NAME} sfml-main sfml-window sfml-graphics)


install(TARGETS logic-gate-sim DESTINATION bin)

