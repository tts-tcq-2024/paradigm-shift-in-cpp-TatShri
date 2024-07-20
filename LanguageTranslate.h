#ifndef LANGUAGETRANSLATE_H
#define LANGUAGETRANSLATE_H

#include <string>
#include <map>

// Declare the languagetranslation_map and current language
extern const std::map<std::string, std::map<std::string, std::string>> languagetranslation_map;
extern std::string outputlanguage;

// Function to set the output language
void setoutputlanguage(const std::string& language);

// Function to translate messages
std::string languagetranslate(const std::string& key);

#endif // LANGUAGETRANSLATE_H
