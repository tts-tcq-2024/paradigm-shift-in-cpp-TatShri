#include "messageTranslate.h"
#include <map>
#include <string>

// Defining the translation map
const std::map<std::string, std::map<std::string, std::string>> translateMessage{
    {"english", {{"Temperature", "Temperature"}, {"State of Charge", "State Of Charge"}, {"Charge Rate", "Charge Rate"}, {"is out of range", "is out of range"}, {"is in range", "is in range"}}},
    {"german", {{"Temperature", "Temperatur"}, {"State of Charge", "Ladezustand"}, {"Charge Rate", "Laderate"}, {"is out of range", "liegt außerhalb des Bereichs"}, {"is in range", "liegt im Bereich"}}}
};

// Helper function to convert preferredLanguage enum to string
std::string languageToString(preferredLanguage lang) {
    switch (lang) {
        case preferredLanguage::English: return "english";
        case preferredLanguage::German: return "german";
        default: return "english"; // Default to English if unknown
    }
}

// Function to translate messages
std::string messageTranslate(const std::string& key, preferredLanguage lang) {
    std::string langStr = languageToString(lang);

    // Check if the current language has a translation for the given key
    if (translateMessage.find(langStr) != translateMessage.end()) {
        const auto& translations = translateMessage.at(langStr);
        if (translations.find(key) != translations.end()) {
            return translations.at(key);
        }
    }
    // If no translation is found, return the key itself
    return key;
}
