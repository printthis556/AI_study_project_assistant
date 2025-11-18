# AI Study Project Assistant

This is a group project for Programming 2. The goal is to create an AI assistant that will help students study and assist with projects they may have. This application uses the Qt framework and will integrate with AI APIs for enhanced functionality.

## Features

- **Flashcard Management**: Create, edit, and delete flashcards for studying
- **Import Content**: Import text files and convert them into flashcards
- **Study Mode**: Review flashcards with a question/answer reveal system
- **Save/Load**: Persist your flashcard collections to JSON files
- **Qt GUI**: Full-featured graphical interface built with Qt6

## Prerequisites

- Qt6 (Qt6 Core, Gui, Widgets)
- CMake 3.16 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Build tools (make or ninja)

## Development Setup

### Using Codespaces/Devcontainer

This project includes a devcontainer configuration that automatically sets up the Qt6 development environment. Simply open the project in GitHub Codespaces or VS Code with the Dev Containers extension.

### Manual Setup

#### Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install -y qt6-base-dev qt6-tools-dev qt6-tools-dev-tools cmake build-essential
```

#### macOS

```bash
brew install qt@6 cmake
```

#### Windows

Download and install Qt6 from [qt.io](https://www.qt.io/download)

## Building the Project

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
cmake --build .

# Run the application
./AIStudyAssistant
```

## Using Qt Creator (Optional)

You can also open this project in Qt Creator:

1. Open Qt Creator
2. File -> Open File or Project
3. Select the `CMakeLists.txt` file
4. Configure the project with your Qt6 kit
5. Build and run

## Project Structure

```
AI_study_project_assistant/
├── .devcontainer/          # Devcontainer configuration for Codespaces
├── include/                # Header files
│   ├── mainwindow.h
│   ├── flashcard.h
│   ├── flashcardmanager.h
│   └── flashcarddialog.h
├── src/                    # Source files
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── flashcard.cpp
│   ├── flashcardmanager.cpp
│   └── flashcarddialog.cpp
├── ui/                     # Qt UI files
│   ├── mainwindow.ui
│   └── flashcarddialog.ui
├── CMakeLists.txt          # CMake build configuration
└── README.md               # This file
```

## Usage

### Creating Flashcards

1. Click the "Add" button in the left panel
2. Enter your question and answer in the dialog
3. Click "OK" to save the flashcard

### Importing Content

1. Click the "Import File" button
2. Select a text file (.txt)
3. The content will be imported as a flashcard
4. Edit the flashcard to create proper question/answer pairs

### Studying

1. Select a flashcard from the list
2. Read the question displayed
3. Click "Study Mode (Reveal Answer)" to see the answer
4. Click again to hide the answer

### Saving and Loading

- Use "Save" to export your flashcard collection to a JSON file
- Use "Load" to import a previously saved collection

## Future Enhancements

- AI-powered flashcard generation from uploaded content
- Spaced repetition algorithm for optimal study scheduling
- Multiple choice quiz mode
- Statistics and progress tracking
- Cloud sync support
- Support for images and multimedia in flashcards

## Contributing

This is a group project. Please follow these guidelines:

1. Create a feature branch for your work
2. Write clear commit messages
3. Test your changes before submitting
4. Document any new features in this README

## License

This project is for educational purposes as part of Programming 2 coursework.
