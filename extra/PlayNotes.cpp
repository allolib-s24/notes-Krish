// PlayNotes.cpp
#include "allolib/external/Gamma/Gamma/Gamma.h"
#include "allolib/external/Gamma/Gamma/Analysis.h"


#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

// Make sure to provide the correct relative path to your SineEnv and MyApp classes
#include "01_SineEnv_Piano.cpp"

class NotePlayer : public MyApp {
public:
    struct Note {
        int midiNote;   // MIDI note number
        float duration; // Duration of the note in seconds
    };

private:
    std::vector<Note> notes;
    int currentNoteIndex = 0;
    float noteTimer = 0;

public:
    void loadNotes(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string noteName;
            float duration;
            if (!(iss >> noteName >> duration)) {
                break;  // Error handling
            }

            int midiNote = noteNameToMIDI(noteName);
            notes.push_back({midiNote, duration});
        }
    }

    void onAnimate(double dt) override {
        MyApp::onAnimate(dt);
        if (currentNoteIndex < notes.size() && noteTimer <= 0) {
            Note& note = notes[currentNoteIndex++];
            synthManager.triggerOn(note.midiNote);
            noteTimer = note.duration;
        }
        if (noteTimer > 0) {
            noteTimer -= dt;
            if (noteTimer <= 0 && currentNoteIndex < notes.size()) {
                synthManager.triggerOff(notes[currentNoteIndex - 1].midiNote);
            }
        }
    }

    static int noteNameToMIDI(const std::string& noteName) {
        // Simplified version; expand this dictionary as needed
        if (noteName == "C4") return 60;
        if (noteName == "D4") return 62;
        // Add additional note mappings here
        return 0; // Default case for unknown notes
    }
};

int main(int argc, char* argv[]) {
    NotePlayer app;
    if (argc > 1) {
        app.loadNotes(argv[1]);
    } else {
        std::cout << "Usage: " << argv[0] << " <path_to_notes_file>" << std::endl;
        return 1;
    }
    app.dimensions(1200, 600);
    app.configureAudio(48000., 512, 2, 0);
    app.start();
    return 0;
}
