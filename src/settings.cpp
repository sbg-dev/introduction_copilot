// Implementation of the settings class using the pImpl idiom.

#include "settings.h"
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <fstream>

class Settings::Impl
{
    nlohmann::json m_settings;

    public:
        void setInt(const std::string& name, int value)
        {
            m_settings[name] = value;
        }

        int getInt(const std::string& name)
        {
            if (m_settings.find(name) == m_settings.end())
            {
                throw std::runtime_error("Setting not found");
            }
            return m_settings[name];
        }

        void setString(const std::string& name, const std::string& value)
        {
            m_settings[name] = value;
        }

        std::string getString(const std::string& name)
        {
            if (m_settings.find(name) == m_settings.end())
            {
                throw std::runtime_error("Setting not found");
            }
            return m_settings[name];
        }

        void setBool(const std::string& name, bool value)
        {
            m_settings[name] = value;
        }

        bool getBool(const std::string& name)
        {
            if (m_settings.find(name) == m_settings.end())
            {
                throw std::runtime_error("Setting not found");
            }
            return m_settings[name];
        }

        std::string serialize() const
        {
            return m_settings.dump();
        }

        void deserialize(const std::string& serialized)
        {
            m_settings = nlohmann::json::parse(serialized);
        }
};

Settings::Settings()
    : m_pImpl(new Impl)
{
}

Settings::~Settings()
{
    delete m_pImpl;
}

void Settings::setInt(const std::string& name, int value)
{
    m_pImpl->setInt(name, value);
}

int Settings::getInt(const std::string& name)
{
    return m_pImpl->getInt(name);
}

void Settings::setString(const std::string& name, const std::string& value)
{
    m_pImpl->setString(name, value);
}

std::string Settings::getString(const std::string& name)
{
    return m_pImpl->getString(name);
}

void Settings::setBool(const std::string& name, bool value)
{
    m_pImpl->setBool(name, value);
}

bool Settings::getBool(const std::string& name)
{
    return m_pImpl->getBool(name);
}

std::string Settings::serialize() const
{
    return m_pImpl->serialize();
}

void Settings::deserialize(const std::string& serialized)
{
    m_pImpl->deserialize(serialized);
}

void Settings::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);
    file << serialize();
    file.close();
}

void Settings::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string serialized((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    deserialize(serialized);
    file.close();
}