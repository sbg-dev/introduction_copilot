#pragma once
#include <string>

/*!
    \brief Class for storing settings of different types
    \code{.cpp}
    // Example usage
    Settings settings;
    settings.setInt("intSetting", 5);
    int value = settings.getInt("intSetting");
    assert(value == 5);

    const std::string serialized = settings.serialize();
    fuction to save serialized string to file
    \endcode
*/
class Settings
{
    public:
        /*!
            \brief Constructor
        */
        Settings();

        /*!
            \brief Destructor
        */
        ~Settings();

        /*!
            \brief Set integer setting
            \param name Setting name
            \param value Setting value
        */
        void setInt(const std::string& name, int value);

        /*!
            \brief Get integer setting
            \param name Setting name
            \error Throws exception if setting does not exist
            \return Setting value
        */
        int getInt(const std::string& name);

        /*!
            \brief Set string setting
            \param name Setting name
            \param value Setting value
        */
        void setString(const std::string& name, const std::string& value);

        /*!
            \brief Get string setting
            \param name Setting name
            \error Throws exception if setting does not exist

            \return Setting value
        */
        std::string getString(const std::string& name);

        /*!
            \brief Set boolean setting
            \param name Setting name
            \param value Setting value
        */
        void setBool(const std::string& name, bool value);

        /*!
            \brief Get boolean setting
            \param name Setting name
            \error Throws exception if setting does not exist
            \return Setting value
        */
        bool getBool(const std::string& name);

        /*!
            \brief Serialize settings to string
            \return Serialized settings
        */
        std::string serialize() const;

        /*!
            \brief Deserialize settings from string
            \param serialized Serialized settings
        */
        void deserialize(const std::string& serialized);

        /*!
            \brief Save settings to file
            \param filename File name
        */
        void saveToFile(const std::string& filename) const;

        /*!
            \brief Load settings from a file
            \param filename Name of the file to load settings from
            \throw std::runtime_error If the file cannot be opened or read
        */
        void loadFromFile(const std::string& filename);
    private:
        class Impl;
        Impl* m_pImpl;
};