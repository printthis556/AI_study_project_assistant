#!/bin/bash
# Simple test script for AI Study Assistant

echo "Building and running tests..."
echo ""

# Compile test
g++ -std=c++17 -fPIC \
    tests/test_flashcards.cpp \
    src/flashcard.cpp \
    src/flashcardmanager.cpp \
    -I include \
    -I /usr/include/x86_64-linux-gnu/qt6 \
    -I /usr/include/x86_64-linux-gnu/qt6/QtCore \
    -I /usr/include/x86_64-linux-gnu/qt6/QtGui \
    -I /usr/include/x86_64-linux-gnu/qt6/QtWidgets \
    -L /usr/lib/x86_64-linux-gnu \
    -lQt6Core -lQt6Gui -lQt6Widgets \
    -o /tmp/test_flashcards

if [ $? -eq 0 ]; then
    echo "Test compiled successfully!"
    echo ""
    echo "Running tests:"
    echo "----------------------------------------"
    /tmp/test_flashcards
    TEST_RESULT=$?
    echo "----------------------------------------"
    echo ""
    if [ $TEST_RESULT -eq 0 ]; then
        echo "All tests passed! ✓"
    else
        echo "Some tests failed!"
        exit 1
    fi
else
    echo "Test compilation failed!"
    exit 1
fi
