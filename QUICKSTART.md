# Quick Start Guide - AI Study Assistant

## For New Users

### 1. Setting Up the Development Environment

If you're using **GitHub Codespaces** or **VS Code with Dev Containers**, the environment will be set up automatically. Just wait for the container to build.

If you're setting up **manually**:

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y qt6-base-dev qt6-tools-dev qt6-tools-dev-tools cmake build-essential

# macOS
brew install qt@6 cmake

# Windows - download Qt6 from https://www.qt.io/download
```

### 2. Building the Application

```bash
# Simple method - use the build script
./build.sh

# OR manually
mkdir build
cd build
cmake ..
cmake --build .
```

### 3. Running the Application

```bash
cd build
./AIStudyAssistant
```

### 4. Running Tests

```bash
./run_tests.sh
```

## Using the Application

### Creating Your First Flashcard

1. Launch the application: `./build/AIStudyAssistant`
2. Click the **"Add"** button in the left panel
3. Enter a question in the "Question" field
4. Enter an answer in the "Answer" field
5. Click **"OK"**

Your flashcard will appear in the list!

### Studying with Flashcards

1. Select a flashcard from the list on the left
2. The question will be displayed on the right
3. Try to recall the answer mentally
4. Click **"Study Mode (Reveal Answer)"** to see the answer
5. Click again to hide the answer for the next review

### Importing Content

1. Click the **"Import File"** button
2. Select a text file (`.txt`) from your computer
3. The content will be imported as a flashcard
4. Click **"Edit"** to refine the question and answer

### Saving Your Work

1. Click the **"Save"** button
2. Choose a location and filename (e.g., `my_flashcards.json`)
3. Your flashcards will be saved

### Loading Saved Flashcards

1. Click the **"Load"** button
2. Select a previously saved `.json` file
3. Your flashcards will be loaded into the application

## For Developers

### Project Structure

```
AI_study_project_assistant/
├── src/           # C++ source files (.cpp)
├── include/       # C++ header files (.h)
├── ui/            # Qt UI files (.ui) - edit with Qt Designer
├── tests/         # Unit tests
├── build/         # Build output (created when you build)
└── CMakeLists.txt # Build configuration
```

### Making Changes to the UI

**Option 1: Using Qt Designer (Visual Editor)**
```bash
designer ui/mainwindow.ui
```
- Drag and drop widgets
- Configure properties visually
- Save and rebuild the project

**Option 2: Using Qt Creator (Full IDE)**
```bash
qtcreator CMakeLists.txt
```
- Full IDE with code completion
- Integrated debugger
- Built-in UI editor

**Option 3: Manual Editing**
- Edit the `.ui` XML files directly (advanced)

### Adding New Features

1. **Add a new class**:
   - Create `include/myclass.h`
   - Create `src/myclass.cpp`
   - Add both files to `CMakeLists.txt`

2. **Add a new dialog/window**:
   - Create `ui/mydialog.ui` with Qt Designer
   - Create `include/mydialog.h` and `src/mydialog.cpp`
   - Add files to `CMakeLists.txt`

3. **Rebuild**:
   ```bash
   cd build
   cmake --build .
   ```

### Running Tests

Tests ensure the core functionality works correctly:

```bash
./run_tests.sh
```

Add new tests in `tests/test_flashcards.cpp` or create new test files.

## Common Tasks

### Task: Add a new button to the main window

1. Open `ui/mainwindow.ui` in Qt Designer
2. Drag a QPushButton from the widget box to your layout
3. Set the button's `text` property (e.g., "My Button")
4. Set the button's `objectName` property (e.g., "myButton")
5. Save the file
6. In `include/mainwindow.h`, add a new slot:
   ```cpp
   private slots:
       void onMyButtonClicked();
   ```
7. In `src/mainwindow.cpp`, add the implementation:
   ```cpp
   void MainWindow::onMyButtonClicked() {
       // Your code here
   }
   ```
8. In the MainWindow constructor, connect the signal:
   ```cpp
   connect(ui->myButton, &QPushButton::clicked, 
           this, &MainWindow::onMyButtonClicked);
   ```
9. Rebuild and run

### Task: Change the application window title

**Method 1: In Qt Designer**
1. Open `ui/mainwindow.ui`
2. Click on the main window (background)
3. Find `windowTitle` in the property editor
4. Change the value
5. Save and rebuild

**Method 2: In code**
```cpp
// In mainwindow.cpp constructor:
setWindowTitle("My Custom Title");
```

### Task: Add a new flashcard field

1. Modify `include/flashcard.h` to add the new field
2. Update `src/flashcard.cpp` with getter/setter methods
3. Update `ui/flashcarddialog.ui` to add a UI element for the field
4. Update `src/flashcarddialog.cpp` to handle the new field
5. Update `src/flashcardmanager.cpp` to save/load the new field
6. Rebuild and test

## Tips

- **Use Qt Assistant** for documentation: `assistant` command
- **Check compile errors carefully** - they often point to typos or missing includes
- **Use Git** to track your changes: commit often!
- **Test frequently** - run `./run_tests.sh` after making changes
- **Ask for help** - Qt has excellent documentation and community support

## Next Steps

1. ✅ Set up environment
2. ✅ Build and run the application
3. ✅ Create some test flashcards
4. 🔄 Explore the code
5. 🔄 Make small changes
6. 🔄 Add new features!

## Resources

- **Qt Documentation**: https://doc.qt.io/
- **C++ Reference**: https://en.cppreference.com/
- **CMake Tutorial**: https://cmake.org/cmake/help/latest/guide/tutorial/
- **Git Guide**: https://guides.github.com/

## Getting Help

- Check `README.md` for project overview
- Check `QT_TOOLS_GUIDE.md` for detailed Qt tools usage
- Read Qt documentation: `assistant` or https://doc.qt.io/
- Ask your team members
- Search Stack Overflow for Qt-specific questions

Happy coding! 🚀
