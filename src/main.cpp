#include <iostream>
#include "settings.h"

int main() {
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
    return 0;
}