#include <string>
#include <map>
#include "messageTranslate.h"

//Defining the translation map
const std::map<std::string, std::map<std::string, std::string>> translateMessage{
        {"english", {{"Temp", "Temperature"}, {"SOC", "State Of Charge"}, {"CR", "Charge Rate"}, {"out", "is out of range"}, {"in", "is in range"}}},
        {"german", {{"Temp", "Temperatur"}, {"SOC", "Ladezustand"}, {"CR", "Laderate"}, {"out", "liegt außerhalb des Bereichs"}, {"in", "liegt im Bereich"}}}
    };

// Default language is English
Language messageLanguage = Language::English;

std::string messageTranslate(const std::string& key) {
    // Check if the current language has a translation for the given key
    if (translateMessage.find(messageLanguage) != translateMessage.end()) {
        const auto& translations = translateMessage.at(messageLanguage);
        if (translations.find(key) != translations.end()) {
            return translations.at(key);
        }
    }
    // If no translation is found, return the key itself
    return key;
}
