#ifndef MESSAGETRANSLATE_H
#define MESSAGETRANSLATE_H

#include <string>

// Enum class for supported languages
enum class preferredLanguage {
    English,
    German
};

// Function to translate messages
std::string messageTranslate(const std::string& key);

#endif // MESSAGETRANSLATE_H
