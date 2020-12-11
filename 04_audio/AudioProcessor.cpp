#include "AudioProcessor.h"

std::vector<short> AudioProcessor::Compress(const std::vector<short> & audio, short threshold, float rate) {
    std::vector<short> processed; 
    
    if (threshold < 0) {
        throw std::invalid_argument("ERROR: negative threshold");
    }
    if (rate < 1.0) {
        throw std::invalid_argument("ERROR: rate less than 1.0");
    }
    if (audio.size() == 0) {
        return processed;
    }

    for (int i = 0; i < audio.size(); i++) {
        if (std::abs(audio[i]) > threshold) {
            processed.push_back((audio[i] >= 0 ? 1 : -1) * ((short) std::round(((float) (((float) std::abs(audio[i]) - threshold) / rate) + threshold))));
        }
        else {
            processed.push_back(audio[i]);
        }
    }
    return processed;
}

std::vector<short> AudioProcessor::CutOutSilence(const std::vector<short> & audio, short level, int silenceLength) {
    std::vector<short> processed; 

    if (level < 0) {
        throw std::invalid_argument("ERROR: negative level");
    }
    if (silenceLength < 1) {
        throw std::invalid_argument("ERROR: silenceLength less than 1");
    }
    if (audio.size() == 0) {
        return processed;
    }

    bool silence = false;
    int len = 0;
    for (int i = 0; i < audio.size(); i++) {

        if (std::abs(audio[i]) <= level) {
            silence = true;
            len += 1;
            
            if (len < silenceLength) {
                processed.push_back(audio[i]);
            }
            else if (len == silenceLength) {
                /*for (const auto& n:processed) {
                    std::cout << n << ", ";
                }*/
                for (int j = 0; j < len - 1; j++) {
                    processed.pop_back();
                }
            }
        } 
        else {
            silence = false; 
            len = 0;
            processed.push_back(audio[i]);
        }

    }

    return processed;
}

std::vector<short> AudioProcessor::StretchTwice(const std::vector<short> & audio) {
    std::vector<short> processed; 
    
    if (audio.size() == 0) {
        return processed;
    }
    if (audio.size() == 1) {
        processed = audio;
        return processed;
    }

    for (int i = 0; i < audio.size() - 1; i++) {
        processed.push_back(audio[i]);
        processed.push_back(std::round((((float) audio[i]) + ((float) audio[i+1])) / 2));
    }
    processed.push_back(audio[audio.size()-1]);

    return processed;
}

std::vector<short> AudioProcessor::Normalize(const std::vector<short> & audio, short normalizeTarget) {
    std::vector<short> processed; 
    
    if (normalizeTarget < 1) {
        throw std::invalid_argument("ERROR: normalizeTarget less than 1");
    }
    if (audio.size() == 0) {
        return processed;
    }

    auto mnmx = std::minmax_element(audio.begin(), audio.end());
    // std::cout << *mnmx.first << ", " << *mnmx.second << std::endl;
    short max_elem = std::max(std::abs(*mnmx.first),std::abs(*mnmx.second));
    float mult = (float) normalizeTarget / (float) max_elem;
    // std::cout << max_elem << "\t" << normalizeTarget << "/" << max_elem << " = " << mult << std::endl;

    for (int i = 0; i < audio.size(); i++) {
        processed.push_back((short) std::round(audio[i] * mult));
    }

    return processed;
}



