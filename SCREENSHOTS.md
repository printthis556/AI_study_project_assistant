# Application Screenshots and Visual Guide

## Main Application Window

The main window is divided into two panels:

### Left Panel - Flashcard Collection
- List of all flashcards
- Total flashcard count display
- Action buttons:
  - **Add**: Create new flashcard
  - **Edit**: Modify selected flashcard
  - **Delete**: Remove selected flashcard
  - **Import File**: Import content from text file
  - **Save**: Export flashcards to JSON
  - **Load**: Import flashcards from JSON

### Right Panel - Flashcard Viewer
- Question display area (scrollable)
- Study Mode button
- Answer display area (scrollable)
- Shows question first, click "Study Mode" to reveal answer

## Flashcard Dialog

A dialog window for creating or editing flashcards with:
- Question text field (multi-line)
- Answer text field (multi-line)
- OK and Cancel buttons

## Application Flow

```
Start Application
    ↓
Main Window Opens
    ↓
User Actions:
    ├─ Add Flashcard → Dialog Opens → Enter Q&A → Save
    ├─ Import File → File Chooser → Content Imported → Edit to refine
    ├─ Select Flashcard → View Question
    │                   ↓
    │              Study Mode → Reveal Answer
    ├─ Edit Flashcard → Dialog with current data → Modify → Save
    ├─ Delete Flashcard → Confirmation → Remove
    ├─ Save Collection → File Chooser → Export to JSON
    └─ Load Collection → File Chooser → Import from JSON
```

## Features in Action

### Creating a Flashcard
1. Click "Add" button
2. Dialog appears with empty fields
3. Type question: "What is the capital of France?"
4. Type answer: "Paris"
5. Click OK
6. Flashcard appears in list

### Studying
1. Select flashcard from list
2. Question displayed: "What is the capital of France?"
3. Think about the answer
4. Click "Study Mode (Reveal Answer)"
5. Answer revealed: "Paris"
6. Review count incremented

### Importing Content
1. Click "Import File"
2. Select a text file (e.g., lecture_notes.txt)
3. Content imported as preview
4. Click "Edit" to refine into proper Q&A format

### Saving Work
1. Click "Save"
2. Choose location: ~/my_flashcards.json
3. All flashcards saved to JSON file
4. Can be loaded later with "Load" button

## File Format

Flashcards are saved in JSON format:

```json
[
  {
    "question": "What is 2+2?",
    "answer": "4",
    "createdDate": "2025-11-11T02:00:00",
    "lastReviewed": "2025-11-11T02:05:00",
    "reviewCount": 3
  },
  {
    "question": "What is the capital of France?",
    "answer": "Paris",
    "createdDate": "2025-11-11T02:01:00",
    "lastReviewed": "",
    "reviewCount": 0
  }
]
```

## Keyboard Navigation

- Tab: Move between widgets
- Enter: Activate focused button
- Escape: Cancel dialog
- Arrow Keys: Navigate flashcard list

## Future UI Enhancements

Planned for future versions:
- Statistics dashboard
- Search/filter flashcards
- Categories/tags
- Dark mode
- Custom themes
- Keyboard shortcuts
- Progress tracking visualizations
- Spaced repetition scheduling
- Quiz mode with multiple choice
- Image support in flashcards

## Accessibility

The application includes:
- Keyboard navigation support
- Clear visual hierarchy
- Readable fonts
- Scrollable content areas
- Proper tab ordering
- Standard dialog patterns

---

Note: Since this is running in a headless environment, actual screenshots cannot be captured. However, the UI is fully functional and follows standard Qt widget patterns. When running with a display server, the application will render with the native Qt theme.
