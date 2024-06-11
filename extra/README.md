# README

## Overview

The `PlayNotes.cpp` file is designed to read musical notes from a specified file and play them using the Allolib framework. It uses MIDI note numbers to trigger the notes and includes functionality to handle note duration and timing. This file leverages external libraries and specific classes within Allolib to synthesize and play the music.

## High-Level Functionality

- **NotePlayer Class**: 
  - This class reads notes from a file, where each note is specified by its name and duration.
  - It converts note names to MIDI note numbers.
  - It plays the notes using a synthesizer, handling the timing and duration of each note.
  - The class inherits from `MyApp`, which is part of the Allolib framework, and overrides the `onAnimate` function to manage note playback.

- **Main Function**:
  - Initializes an instance of the `NotePlayer` class.
  - Loads notes from a file if provided as a command-line argument.
  - Configures audio settings and starts the application.

## Usage Instructions

1. **Compile the Program**:
   - Save the code in a file named `PlayNotes.cpp`.
   - Open a terminal and navigate to the directory containing the file.
   - Compile the program using the appropriate compiler and include paths for Allolib and its dependencies.

2. **Run the Program**:
   - Execute the program with the path to the notes file as a command-line argument:
     ```bash
     ./PlayNotes <path_to_notes_file>
     ```

## Known Issue

This code does not work as expected because it needs to reference a directory `allolib`, which is a pointer to another GitHub repository within the `allolib_playground` repository. I wasn't able to figure out how to correctly set up this reference, but it could be a cool project to continue if anybody wants to.

## Potential Extension

This project can be extended to:
- Properly integrate the `allolib` directory and dependencies.
- Expand the note-to-MIDI mapping to support a broader range of notes.
- Add more sophisticated audio effects and real-time audio processing features using Allolib.

This would be a valuable contribution to the Allolib community, enhancing its capabilities for music synthesis and digital audio technology.
