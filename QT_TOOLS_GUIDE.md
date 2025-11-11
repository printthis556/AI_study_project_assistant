# Using Qt Tools with AI Study Assistant

This guide explains how to use Qt Designer, Qt Creator, and other Qt tools with this project.

## Qt Designer

Qt Designer is a visual tool for designing Qt GUI interfaces. You can use it to edit the `.ui` files in this project.

### Installing Qt Designer

Qt Designer is included with the `qt6-tools-dev-tools` package:

```bash
sudo apt-get install qt6-tools-dev-tools
```

### Opening UI Files in Qt Designer

```bash
# Open the main window UI
designer ui/mainwindow.ui

# Or open the flashcard dialog UI
designer ui/flashcarddialog.ui
```

### Editing the UI

1. Open a `.ui` file in Qt Designer
2. Use the widget palette on the left to add new widgets
3. Use the property editor on the right to modify widget properties
4. Use the signal/slot editor to connect events
5. Save your changes
6. Rebuild the project to see your changes

## Qt Creator

Qt Creator is a full-featured IDE for Qt development.

### Installing Qt Creator

```bash
sudo apt-get install qtcreator
```

### Opening the Project in Qt Creator

You can open the project in Qt Creator using either:

1. **CMake Project** (Recommended):
   - Open Qt Creator
   - File → Open File or Project
   - Navigate to the project directory
   - Select `CMakeLists.txt`
   - Configure your Qt6 kit
   - Build and run

2. **qmake Project**:
   - Open Qt Creator
   - File → Open File or Project
   - Select `AIStudyAssistant.pro`
   - Configure your Qt6 kit
   - Build and run

### Qt Creator Features

- **Syntax highlighting** and code completion
- **Visual debugging** with breakpoints
- **Integrated Qt Designer** - double-click `.ui` files to edit them
- **Signal/Slot Editor** - visual editor for connections
- **Qt Documentation** - press F1 on any Qt class for help
- **Refactoring tools** - rename, extract method, etc.

## Qt Assistant (Documentation Browser)

Qt Assistant provides searchable documentation for Qt.

```bash
# Launch Qt Assistant
assistant
```

You can also access it from Qt Creator: Help → Qt Help

## Using qmake Instead of CMake

If you prefer to use qmake instead of CMake, use the provided `.pro` file:

```bash
# Create build directory
mkdir build-qmake
cd build-qmake

# Generate Makefile with qmake
qmake6 ../AIStudyAssistant.pro

# Build
make

# Run
./AIStudyAssistant
```

## Qt Linguist (For Translations)

If you want to add internationalization support in the future:

```bash
sudo apt-get install qt6-l10n-tools
```

Then you can use Qt Linguist to create and manage translations.

## Useful Qt Tools Commands

### Using qmake to check configuration

```bash
qmake6 -query
```

### Checking Qt version

```bash
qmake6 --version
```

### Using moc (Meta-Object Compiler) manually

The MOC is automatically run by CMake, but you can run it manually:

```bash
moc include/mainwindow.h -o moc_mainwindow.cpp
```

### Using uic (User Interface Compiler) manually

The UIC is automatically run by CMake, but you can run it manually:

```bash
uic ui/mainwindow.ui -o ui_mainwindow.h
```

## Debugging with Qt Creator

1. Set breakpoints by clicking in the left margin of the code editor
2. Run → Start Debugging (F5)
3. Use the debugging toolbar to:
   - Step over (F10)
   - Step into (F11)
   - Continue (F5)
   - View variables in the Locals and Expressions window

## Best Practices

1. **Use Qt Designer** for complex UI layouts - it's faster than coding by hand
2. **Use Qt Creator's refactoring tools** when renaming classes or methods
3. **Check the Qt documentation** (F1) when using unfamiliar Qt classes
4. **Use CMake** for the build system - it's more flexible than qmake
5. **Keep UI logic separate** from business logic - use the Model-View pattern

## Tips for Using This Project

### Modifying the UI

1. Open `ui/mainwindow.ui` or `ui/flashcarddialog.ui` in Qt Designer
2. Make your changes
3. Save the file
4. Rebuild the project - the changes will be automatically applied

### Adding New Windows/Dialogs

1. Create a new `.ui` file in the `ui/` directory using Qt Designer
2. Create corresponding `.h` and `.cpp` files in `include/` and `src/`
3. Add the files to `CMakeLists.txt`
4. Rebuild the project

### Using Qt's Signal/Slot Mechanism

Signals and slots are Qt's mechanism for communication between objects:

```cpp
// In your code:
connect(ui->myButton, &QPushButton::clicked, 
        this, &MyClass::mySlotFunction);
```

You can also use Qt Creator's signal/slot editor (F4) for visual editing.

## Resources

- [Qt Documentation](https://doc.qt.io/)
- [Qt Designer Manual](https://doc.qt.io/qt-6/qtdesigner-manual.html)
- [Qt Creator Manual](https://doc.qt.io/qtcreator/)
- [Qt Tutorials](https://doc.qt.io/qt-6/qtexamplesandtutorials.html)

## Troubleshooting

### Qt Designer won't open

Make sure you have the tools package installed:
```bash
sudo apt-get install qt6-tools-dev-tools
```

### CMake can't find Qt6

Make sure Qt6 development packages are installed:
```bash
sudo apt-get install qt6-base-dev
```

### UI changes don't appear after building

Make sure you're rebuilding the project after UI changes:
```bash
cd build
cmake --build . --clean-first
```
