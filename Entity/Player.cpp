/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Player.cpp                                                 #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/15/19 11:39:33 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 08/02/19 16:19:03 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include <iostream>
#include "Player.hh"
#include "../Utils/ResourceHolder.hh"
#include "../Utils/DisplayInfo.hh"

namespace SpaceInvaders {
    namespace {
        constexpr float BASE_Y = (float) Display::HEIGHT - 40.0f;

    }

    Player::Player() : Collidable(44, 32), m_deathAnimation(11, 8) {
        m_sprite.setSize({56, 37.5});
        m_sprite.setTexture(&ResourceHolder::get().textures.get("si/player-sp"));
        m_sprite.setTextureRect({0, 0, 99, 75}); // Pas besoin si pas de sprite pour le player
        //m_sprite.setTextureRect({99, 0, 112, 75}); // Pas besoin si pas de sprite pour le player
        //m_sprite.setTextureRect({211, 0, 98, 75}); // Pas besoin si pas de sprite pour le player
        m_sprite.setPosition({Display::WIDTH / 2 - 25, BASE_Y});

        for (int i = 0; i < 20; i++) {
            m_deathAnimation.addFrame(((i % 2) + 1), sf::seconds(0.1f));
        }

        m_deathSound.setBuffer(
                ResourceHolder::get().soundBuffers.get("si/explosion"));
    }

    void Player::restart() {
        m_velocity *= 0.0f;
        m_sprite.setTextureRect({0, 0, 99, 75}); // Pas besoin si pas de sprite pour le player
        //m_sprite.setTextureRect({99, 0, 112, 75}); // Pas besoin si pas de sprite pour le player
        //m_sprite.setTextureRect({211, 0, 98, 75}); // Pas besoin si pas de sprite pour le player
        m_isAlive = true;
        m_livesLeft--;
        m_sprite.setPosition({Display::WIDTH / 2 - 25, BASE_Y});
    }

    void Player::input() {
        using Key = sf::Keyboard::Key;
        auto keyDown = [](sf::Keyboard::Key k) {
            return sf::Keyboard::isKeyPressed(k);
        };

        float speed = 20;
        if (keyDown(Key::Left)) {
            m_velocity.x -= speed;
        } else if (keyDown(Key::Right)) {
            m_velocity.x += speed;
        }
    }

    void Player::update(float dt) {
        if (m_isAlive) {
            auto w = m_sprite.getGlobalBounds().width;
            m_sprite.move(m_velocity * dt);
            m_velocity *= 0.95f;
            if (m_sprite.getPosition().x <= 0) {
                m_velocity.x = 1.0f;
                m_sprite.setPosition(1.0f, BASE_Y);
            } else if (m_sprite.getPosition().x + w >= Display::WIDTH) {
                m_velocity.x = -1.0f;
                m_sprite.setPosition(Display::WIDTH - 1.0f - w, BASE_Y);
            }
        }
    }

    void Player::draw(sf::RenderTarget &target) {
        if (!m_isAlive) {
            m_sprite.setTextureRect(m_deathAnimation.getFrame());
        }
        if (m_livesLeft >= 0) {
            target.draw(m_sprite);
        }
    }

    sf::Vector2f Player::getGunPosition() const {
        return {m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2,
                m_sprite.getPosition().y};
    }

    const sf::Vector2f &Player::getPosition() const {
        return m_sprite.getPosition();
    }

    void Player::onCollide(Collidable &other) {
        m_isAlive = false;
        m_deathTimer.restart();
        m_deathSound.play();
    }

    int Player::getLives() const { return m_livesLeft; }

    bool Player::isAlive() const { return m_isAlive; }

    void Player::tryRevive() {
        if (m_deathTimer.getElapsedTime().asSeconds() >= 1.5f) {
            restart();
        }
    }

}