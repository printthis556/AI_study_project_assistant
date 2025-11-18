#!/bin/bash
# Build script for AI Study Assistant

set -e

echo "==================================="
echo "AI Study Assistant Build Script"
echo "==================================="
echo ""

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build

# Configure with CMake
echo "Configuring project with CMake..."
cmake ..

# Build the project
echo "Building project..."
cmake --build .

echo ""
echo "==================================="
echo "Build completed successfully!"
echo "==================================="
echo ""
echo "To run the application:"
echo "  cd build"
echo "  ./AIStudyAssistant"
echo ""
