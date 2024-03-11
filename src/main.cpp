#include <iostream>
#include "settings.h"

int main() {
    // Test the settings class
    Settings settings;
    settings.setInt("intSetting", 5);
    int value = settings.getInt("intSetting");
    std::cout << (value == 5) << std::endl;

    // Test if exceptions are thrown
    try {
        settings.getInt("nonExistentSetting");
    } catch (const std::runtime_error& e) {
        std::cout << (std::string(e.what()) == "Setting not found") << std::endl;
    }

    // Test serialization
    const std::string serialized = settings.serialize();
    std::cout << (serialized == "{\"intSetting\":5}") << std::endl;

    // Test deserialization
    Settings settings2;
    settings2.deserialize(serialized);
    std::cout << (settings2.getInt("intSetting") == 5) << std::endl;

    // Test write to file
    settings2.saveToFile("settings.json");

    // Test read from file
    Settings settings3;
    settings3.loadFromFile("settings.json");
    std::cout << (settings3.getInt("intSetting") == 5) << std::endl;
    return 0;
}