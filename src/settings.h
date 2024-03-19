#pragma once
#include <string>

/*
The settings class can be used to store integers, bools and strings under a key.
The settings class can be used to save settings in the json format on disk.
The settings class uses the pimpl idiom to hide the implementation details.
The settings class uses nlohmann json to parse and serialize the settings.

Example:
Settings settings;
settings.setInt("width", 800);
assert(settings.getInt("width") == 800);
settings.setBool("fullscreen", true);
assert(settings.getBool("fullscreen") == true);
settings.setString("title", "My Game");
assert(settings.getString("title") == "My Game");
settings.save("settings.json");

Settings settings2;
settings2.load("settings.json");
assert(settings2.getInt("width") == 800);
assert(settings2.getBool("fullscreen") == true);
assert(settings2.getString("title") == "My Game");

assert(settings2.toJson() == settings.toJson());
*/
class Settings
{
public:
    Settings();
    ~Settings();

    /**
     * @brief Set the value of the key to the given integer.
     * @param key The key to set.
     * @param value The value to set.
     * @threading This function is not thread safe.
     * @error This function does not throw exceptions.
    */
    void setInt(const std::string& key, int value);
    int getInt(const std::string& key, int defaultValue = 0) const;

    /**
     * @brief Set the value of the key to the given boolean.
     * @param key The key to set.
     * @param value The value to set.
     * @pre The key must be a valid string.
     * @threading This function is not thread safe.
     * @error This function does not throw exceptions.
    */
    void setBool(const std::string& key, bool value);
    bool getBool(const std::string& key, bool defaultValue = false) const;

    /**
     * @brief Set the value of the key to the given string.
     * @param key The key to set.
     * @param value The value to set.
     * @pre The key must be a valid string.
     * @threading This function is not thread safe.
     * @error This function does not throw exceptions.
    */
    void setString(const std::string& key, const std::string& value);
    std::string getString(const std::string& key, const std::string& defaultValue = "") const;

    void save(const std::string& filename) const;
    void load(const std::string& filename);

    std::string toJson() const;

private:
    class Impl;
    Impl* mImpl;
};