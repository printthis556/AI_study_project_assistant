#!/bin/bash
set -e

echo "Installing Qt6 and development tools..."

# Update package list
sudo apt-get update

# Install Qt6 and required dependencies
sudo apt-get install -y \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    libqt6core6 \
    libqt6gui6 \
    libqt6widgets6 \
    qmake6 \
    cmake \
    build-essential \
    mesa-common-dev \
    libglu1-mesa-dev \
    libxkbcommon-x11-0 \
    designer \
    qtcreator

# Install additional Qt modules that might be useful
sudo apt-get install -y \
    libqt6sql6 \
    libqt6network6 \
    qt6-base-private-dev

echo "Qt6 installation completed!"
echo "Qt version:"
qmake6 --version
echo ""
echo "Available Qt tools:"
echo "  - qmake6: Qt build system"
echo "  - designer: Qt Designer (UI editor)"
echo "  - qtcreator: Qt Creator IDE"

