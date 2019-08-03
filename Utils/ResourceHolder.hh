//
// Created by Mouhammad DAHALANI on 2019-07-17.
//

#ifndef SPACE_INVADERS_RESOURCEHOLDER_HH
#define SPACE_INVADERS_RESOURCEHOLDER_HH
#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "NonCopyable.hh"
#include "NonMoveable.hh"
#include "ResourceManager.hh"

class ResourceHolder : public NonCopyable, public NonMovable {
public:
    static ResourceHolder &get();

    ResourceManager<sf::Font> fonts;
    ResourceManager<sf::Texture> textures;
    ResourceManager<sf::SoundBuffer> soundBuffers;

private:
    ResourceHolder();
};

#endif //SPACE_INVADERS_RESOURCEHOLDER_HH
