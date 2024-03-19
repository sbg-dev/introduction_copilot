#include "settings.h"
#include <nlohmann/json.hpp>
#include <fstream>

class Settings::Impl
{
    public:
    nlohmann::json mJson;
};

Settings::Settings() : mImpl(new Impl)
{
}

Settings::~Settings()
{
    delete mImpl;
}

void Settings::setInt(const std::string& key, int value)
{
    mImpl->mJson[key] = value;
}

int Settings::getInt(const std::string& key, int defaultValue) const
{
    if (mImpl->mJson.contains(key))
    {
        return mImpl->mJson[key];
    }
    return defaultValue;
}

void Settings::setBool(const std::string& key, bool value)
{
    mImpl->mJson[key] = value;
}

bool Settings::getBool(const std::string& key, bool defaultValue) const
{
    if (mImpl->mJson.contains(key))
    {
        return mImpl->mJson[key];
    }
    return defaultValue;
}

void Settings::setString(const std::string& key, const std::string& value)
{
    mImpl->mJson[key] = value;
}

std::string Settings::getString(const std::string& key, const std::string& defaultValue) const
{
    if (mImpl->mJson.contains(key))
    {
        return mImpl->mJson[key];
    }
    return defaultValue;
}

void Settings::save(const std::string& filename) const
{
    std::ofstream file(filename);
    file << mImpl->mJson.dump(4);
}

void Settings::load(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        file >> mImpl->mJson;
    }
    else
    {
        throw std::runtime_error("Could not open file " + filename);
    }
}

std::string Settings::toJson() const
{
    return mImpl->mJson.dump(4);
}
