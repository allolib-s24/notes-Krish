# Project: Music Composition and Synthesis with Allolib

## Overview

This project involves composing and arranging music for an Allolib synthesized instrument. The project is structured to satisfy course requirements and demonstrate proficiency in digital audio technology using the Allolib framework. 

### Project Deliverables

1. **A piece of music** composed or arranged for an Allolib synthesized instrument, performed by the student. This includes:
   - A GitHub repository with the code.
   - An explanation of the piece.
   - A live performance of the piece.

2. **A final project** categorized as an extension of the basic features of Allolib. This project includes:
   - Converters from existing formats for representing musical scores into formats consumable by Allolib.

### Project Category

This project falls into category (d): An extension of the basic features of Allolib. Specifically, it involves:
- Converting musical scores from text format into a format that can be consumed by the Allolib framework.
- Generating sound using Allolib based on the converted musical scores.
- The main motive behind this project is to help beginners with little to no music experience compose longer pieces without having to learn the piano or memorize many notes

## Files Included

All files should be placed in the folder `SineEnv_Piano-data`.

### `inputMusic.txt`

This file contains the musical score in a text format. Each line represents a sequence of notes and the corresponding lyrics. The format is designed to be easily readable and convertible into a format suitable for Allolib. The website I used for this is here (https://noobnotes.net/). You can pick a song you want to translate, copy paste the notes into this file and run the cpp file. 

### `inputMusic.cpp`

This C++ program reads the musical score from `inputMusic.txt`, processes it, and outputs a sequence of commands in `outputPlay.synthSequence` that Allolib can consume. The program ensures that the musical notes are correctly formatted, including necessary pauses and timing adjustments. One thing to note is that you have to manually adjust the BPM based on the song you choose. 

### `outputPlay.synthSequence`

This file is generated by the `inputMusic.cpp` program. It contains the synthesized sequence of musical notes formatted for playback using Allolib.

## Usage Instructions

1. **Prepare the Input File**:
   - Save your musical notes in a text file named `inputMusic.txt`. Follow the provided format for notes and lyrics.
   - Place the `inputMusic.txt` file in the `SineEnv_Piano-data` folder.

2. **Compile the C++ Program**:
   - Save the C++ code in a file named `inputMusic.cpp`.
   - Open a terminal and navigate to the directory containing the `inputMusic.cpp` file.
   - Compile the program using the command:
     ```bash
     g++ -std=c++11 -o inputMusic inputMusic.cpp
     ```

3. **Run the Program**:
   - Ensure the `inputMusic.txt` file is in the `SineEnv_Piano-data` folder.
   - Execute the program using the command:
     ```bash
     ./inputMusic
     ```

4. **View the Output**:
   - The processed notes will be saved in a file named `outputPlay.synthSequence` in the `SineEnv_Piano-data` folder.


- The piece is a composition or arrangement specifically crafted for playback using the Allolib synthesized instrument.
- The musical score is provided in a text format, ensuring easy readability and conversion.
- The C++ program processes the musical score, ensuring correct formatting, timing, and necessary pauses, outputting a file suitable for Allolib playback.

