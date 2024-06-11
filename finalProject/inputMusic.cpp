#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

// Initialize note frequencies
std::map<std::string, double> initNoteFrequencies() {
    std::map<std::string, double> notes;
    notes["C"] = 523.25;    // Q
    notes["D"] = 587.33;    // W
    notes["E"] = 659.26;    // E
    notes["F"] = 698.46;    // R
    notes["G"] = 783.99;    // T
    notes["A"] = 880.00;    // Y
    notes["B"] = 987.77;    // U
    notes["C'"] = 1046.50;  // I
    notes["D'"] = 1174.66;  // O
    notes["E'"] = 1318.51;  // P
   
    notes["C#"] = 277.18;   // 2
    notes["D#"] = 311.13;   // 3
    notes["F#"] = 369.99;   // 5
    notes["G#"] = 415.30;   // 6
    notes["A#"] = 466.16;   // 7
    notes["C#'"] = 554.37;  // 9
    notes["D#'"] = 622.25;  // 0
    return notes;
}

// Global map of note frequencies
const std::map<std::string, double> noteFrequencies = initNoteFrequencies();

// Beats per minute and beat duration
const double bpm = 119;
const double beatDuration = 60.0 / bpm;

// Split a string by a delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Process a line of notes into the desired format
std::string processNotes(const std::string& line, double& time) {
    std::vector<std::string> notes = split(line, ' ');
    std::ostringstream result;
    for (size_t i = 0; i < notes.size(); ++i) {
        // If the note is in the map, process it
        if (noteFrequencies.find(notes[i]) != noteFrequencies.end()) {
            result << "@ " << time << " " << beatDuration << " SineEnv 0.6 " 
                   << noteFrequencies.at(notes[i]) << " 0.1 0.4 0.5 50 50 100 20\n";
            time += beatDuration;

            // Add a brief pause if the next note is the same
            if (i < notes.size() - 1 && notes[i] == notes[i + 1]) {
                result << "@ " << time << " " << (beatDuration / 2) << " SineEnv 0 0 0 0 0 0 0 0 0\n";
                time += (beatDuration / 2);
            }
        } else if (notes[i] == "-") {
            result << "@ " << time << " " << (beatDuration / 2) << " SineEnv 0 0 0 0 0 0 0 0 0\n";
            time += (beatDuration / 2);
        }
    }
    return result.str();
}

int main() {
    std::ifstream inputFile("inputMusic.txt");
    std::ofstream outputFile("outputPlay.synthSequence");
    std::string line;
    double currentTime = 0.0;

    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            std::string processedLine = processNotes(line, currentTime);
            outputFile << processedLine;
            outputFile << "@ " << currentTime << " " << (beatDuration / 2) << " SineEnv 0 0 0 0 0 0 0 0 0\n";
            currentTime += (beatDuration / 2);
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
