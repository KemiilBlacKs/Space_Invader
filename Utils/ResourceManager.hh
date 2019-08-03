//
// Created by Mouhammad DAHALANI on 2019-07-17.
//

#ifndef SPACE_INVADERS_RESOURCEMANAGER_HH
#define SPACE_INVADERS_RESOURCEMANAGER_HH
#pragma once

#include <string>
#include <unordered_map>

/**
    Contient toutes les ressources du jeu
*/
template<typename Resource>
class ResourceManager {
public:
    ResourceManager(const std::string &folder, const std::string &extension)
            : m_folder("../Ressources/" + folder + "/"), m_extension("." + extension) {}

    const Resource &get(const std::string &name) {
        if (!exists(name)) {
            add(name);
        }
        return m_resources.at(name);
    }

    bool exists(const std::string &name) const {
        return m_resources.find(name) != m_resources.end();
    }

    void add(const std::string &name) {
        Resource r;

        // Si la ressource ne se charge pas, alors on ajoute une ressource par défaut
        if (!r.loadFromFile(getFullFilename(name))) {
            Resource fail;
            fail.loadFromFile(m_folder + "_fail_" + m_extension);
            m_resources.insert(std::make_pair(name, fail));
        } else {
            m_resources.insert(std::make_pair(name, r));
        }
    }

private:
    std::string getFullFilename(const std::string &name) {
        return m_folder + name + m_extension;
    }

    const std::string m_folder;
    const std::string m_extension;

    std::unordered_map<std::string, Resource> m_resources;
};

#endif //SPACE_INVADERS_RESOURCEMANAGER_HH
