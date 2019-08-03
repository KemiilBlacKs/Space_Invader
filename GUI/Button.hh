//
// Created by Mouhammad DAHALANI on 2019-07-19.
//

#ifndef SPACE_INVADERS_BUTTON_HH
#define SPACE_INVADERS_BUTTON_HH

#pragma once

#include <functional>

#include "Widget.hh"

namespace gui {

/**
    Enum pour la taille d'un bouton
*/
    enum class ButtonSize {
        Small,
        Wide,
    };

/**
 * @brief Une classe qui représente un seul bouton
 *
 */
    class Button : public gui::Widget {
    public:
        /**
         * @brief Constructeur pour un nouveel objet bouton
         *
         * @param s La taille du bouton
         */
        Button(ButtonSize s = ButtonSize::Wide);

        /**
         * @brief Définir un callback lorsque le bouton est enfoncé
         *
         * @param function La fonction de callback
         */
        void setFunction(std::function<void(void)> function);

        /**
         * @brief Définir le texte qui apparaît sur le bouton
         *
         * @param text Le texte sur le bouton
         */

        void setText(const std::string &text);

        /**
         * @brief Définir la texture pour apparaître sur l'arrière-plan du bouton
         *
         * @param texture
         */
        void setTexture(const sf::Texture &texture);

        /**
         * @brief Gère les événements de fenêtre
         * Certains événements comme les clics et les survols de souris peuvent déclencher le bouton
         * quelque chose, cette fonction gère de tels événements
         * @param e L'événement SFML qui contient des informations sur l'événement
         * @param window La fenêtre sur laquelle le jeu se joue
         */
        void handleEvent(sf::Event e, const sf::RenderWindow &window);

        /**
         * @brief Rendu du bouton
         * Rend le bouton à une render target
         * @param renderer La cible pour rendre le bouton
         */
        void render(sf::RenderTarget &renderer);

        /**
         * @brief Régler la position du bouton
         *
         * @param pos La position pour régler le bouton
         */
        void setPosition(const sf::Vector2f &pos);

        /**
         * @brief Obtenir la taille des boutons
         * Retruns la taille du bouton telle qu'elle apparaît dans la fenêtre
         * @return sf::Vector2f La taille du bouton
         */
        sf::Vector2f getSize() const;

    private:
        /**
         * @brief Réaligne la position du texte à centrer dans la fenêtre
         *
         */
        void updateText();

        sf::Vector2f m_position;
        Rectangle m_button;
        Text m_text;
        std::function<void(void)> m_function = []() {};
    };

/**
 * @brief Crée un objet bouton
 *
 * @return std::unique_ptr<Button> Un pointeur unique vers un nouvel objet bouton
 */
    inline std::unique_ptr<Button> makeButton() {
        return std::make_unique<Button>();
    }
}


#endif //SPACE_INVADERS_BUTTON_HH
