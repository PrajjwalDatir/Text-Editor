# Terminal Text Editor

A lightweight C-based terminal text editor built with the Ncurses library.

## Requirements

- **macOS**: Xcode Command Line Tools (`xcode-select --install`)
- **Linux**: GCC/Clang and Ncurses development libraries (`sudo apt-get install libncurses5-dev libncursesw5-dev` or `sudo dnf install ncurses-devel`)
- **Windows**: WSL2 (Ubuntu) or MinGW with PDCurses

## Build & Run

```bash
# Build
make

# Run
./text_editor [filename]

# Clean build artifacts
make clean
```

## Features

- **File Operations**: Create, open, edit, and save files
- **Editing**: Character and line insertion, deletion, backspace
- **Clipboard**: Cut and copy words and lines
- **Search & Navigation**: Word search, word replace, goto line number
- **Typing Assistance**: Word completion suggestions (`Tab`)
- **History**: Undo / redo support
- **Input Modes**: Full keyboard navigation and mouse click support
- **Large Files**: Chunked file streaming for handling large files
