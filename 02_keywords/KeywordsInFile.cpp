#include "KeywordsInFile.h"

KeywordsInFile::KeywordsInFile(const std::string &fkeywords, const std::string &ftext) {
    std::ifstream fkeys(fkeywords);
    if (fkeys.fail()) {
        throw(std::invalid_argument("'" + fkeywords + "' is not a valid file name"));
    }

    std::ifstream ftexts(ftext);
    if (ftexts.fail()) {
        throw(std::invalid_argument("'" + ftext + "' is not a valid file name"));
    }

    process_keys(fkeys); 
    process_text(ftexts); 


}

void KeywordsInFile::process_keys (std::ifstream &fin) {
    std::string line, word;

    while(std::getline(fin, line)) {
        word = "";
        for (int i = 0; i < line.length(); i++) {  // go through every character in the line 
            if (isalpha(line[i])) { // add to word if it's a letter
                word += line[i];
            }

            else if (word != "") { // add current word to the hash table if it isn't and reset the word
                frequency.insert({word,0});
                word = "";
            }
        }
        if (word != "") {
            frequency.insert({word,0});
            word = "";
        }
    }
}

void KeywordsInFile::process_text (std::ifstream &fin) {
    std::string line, word;
    int ln = 1;

    while(std::getline(fin, line)) {
        word = "";
        for (int i = 0; i < line.length(); i++) { 
            if (isalpha(line[i])) {
                word += line[i];
            }
            else if (word != "") { 
                if (frequency.count(word) > 0) {
                    frequency[word] += 1;

                    std::string serialized = key_line(word,ln);
                    if (frequency.count(serialized) == 0) {
                        frequency.insert({serialized,1});
                    }
                    else {
                        frequency[serialized] += 1;
                    }
                }
                word = "";
            }
        }
        if (word != "") { 
            if (frequency.count(word) > 0) {
                frequency[word] += 1;

                std::string serialized = key_line(word,ln);
                if (frequency.count(serialized) == 0) {
                    frequency.insert({serialized,1});
                }
                else {
                    frequency[serialized] += 1;
                }
            }
            word = "";
        }
        ln++;
    }
}

std::ostream& operator<<(std::ostream& stream, const KeywordsInFile& target) {
    for( const auto& n : target.frequency) {
        if (isalpha(n.first.back())) {
            stream << n.first << ":\t" << n.second << std::endl;
        }
    }
    
    return stream;
}

bool KeywordsInFile::KeywordFound(const std::string &keyword) {
    if (frequency.count(keyword) > 0) {
        return frequency[keyword] > 0;
    } 
    else {
        throw(std::invalid_argument("'" + keyword + "' is not a keyword"));
    }
}

int KeywordsInFile::KeywordInLine(const std::string &keyword, const int line_number) {
    if (frequency.count(keyword) == 0) {
        throw(std::invalid_argument("'" + keyword + "' is not a keyword"));
    }
    if (line_number < 1) {
        throw std::out_of_range(std::to_string(line_number) + " is an invalid line number"); 
    }

    std::string serialized = key_line(keyword,line_number);
    if (frequency.count(serialized) > 0) {
        return frequency[serialized];
    }
    return 0;
}

int KeywordsInFile::TotalOccurrences(const std::string &keyword) {
    if (frequency.count(keyword) > 0){
        return frequency[keyword];
    } 
    else {
        throw(std::invalid_argument("'" + keyword + "' is not a keyword"));
    }
    return 0;
}

std::string KeywordsInFile::key_line (const std::string &keyword, const int line) const {
    return keyword + " (" + std::to_string(line) + ")";
}

std::unordered_map<std::string, int> KeywordsInFile::data () const {
    return frequency;
}



