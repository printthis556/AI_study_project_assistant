cmake_minimum_required(VERSION 3.16)

project(AIStudyAssistant VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6 configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set the directory where UIC should look for .ui files
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

# Source files
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/flashcard.cpp
    src/flashcardmanager.cpp
    src/flashcarddialog.cpp
)

# Header files
set(HEADERS
    include/mainwindow.h
    include/flashcard.h
    include/flashcardmanager.h
    include/flashcarddialog.h
)

# UI files
set(UI_FILES
    ui/mainwindow.ui
    ui/flashcarddialog.ui
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI_FILES})

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets
)

# Install target
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
