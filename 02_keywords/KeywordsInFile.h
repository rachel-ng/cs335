#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <cctype>
#include <string>

class KeywordsInFile{
private:
    std::unordered_map<std::string, int> frequency;
    void process_keys(const std::string fname);
    void process_text(const std::string fname);

    std::string key_line(const std::string &keyword, const int line) const;

public:
    KeywordsInFile(const std::string &fkeywords, const std::string &ftext);
    KeywordsInFile()=delete;

    friend std::ostream& operator<<(std::ostream& stream, const KeywordsInFile& target);
    bool KeywordFound(const std::string &keyword);

    int KeywordInLine(const std::string &keyword, const int line_number);
    int TotalOccurrences(const std::string &keyword);

    std::unordered_map<std::string, int> data () const; 
};

