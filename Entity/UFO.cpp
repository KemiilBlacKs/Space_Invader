/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  UFO.cpp                                                    #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/19/19 12:14:47 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/29/19 10:57:33 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/
#include "UFO.hh"

#include "../Utils/ResourceHolder.hh"
#include "../Utils/DisplayInfo.hh"

namespace SpaceInvaders {
    namespace {
        constexpr float WIDTH = 36;
        constexpr float HEIGHT = 36;
        constexpr float Y_POS = 45;
    } // namespace

    UFO::UFO(Random<> &rand)
            : Collidable(WIDTH, HEIGHT), m_rng(rand), m_animation(91, 91) {
        m_sprite.setSize({WIDTH, HEIGHT});
        m_sprite.setPosition((float) Display::WIDTH, Y_POS);
        m_sprite.setTexture(&ResourceHolder::get().textures.get("si/ufo-sp"));
        m_sprite.setTextureRect({0, 0, 91, 91});

        for (int i = 0; i < 3; i++) {
            m_animation.addFrame(i, sf::seconds(0.2f));
        }
        m_flyingSound.setBuffer(
                ResourceHolder::get().soundBuffers.get("si/ufo_lowpitch"));
        m_flyingSound.setVolume(10);
    }

    UFO::State UFO::getState() const { return m_state; }

    void UFO::update(float dt) {
        switch (m_state) {
            case State::Destroyed:
                m_state = State::Waiting;
                break;

            case State::Flying:
                m_sprite.move(m_vx * dt, 0);
                if (getPosition().x <= -WIDTH ||
                    getPosition().x >= Display::WIDTH + WIDTH) {
                    m_state = State::Waiting;
                }
                if ((int) m_flyingSound.getStatus() != (int) sf::Sound::Status::Playing ||
                    m_flyingSound.getPlayingOffset() >= sf::seconds(1.5)) {
                    m_flyingSound.setPlayingOffset(sf::seconds(0.2f));
                    m_flyingSound.play();
                }
                break;

            case State::Waiting:
                if (m_rng.getIntInRange(1, 250) == 100) {
                    m_state = State::Flying;
                    m_vx = (float) m_rng.getIntInRange(-1, 1) * 200.0f;
                    float xPos;
                    if (m_vx >= 0) {
                        xPos = -WIDTH;
                    } else {
                        xPos = Display::WIDTH;
                    }
                    m_sprite.setPosition(xPos, Y_POS);
                }
                break;
        }
    }

    void UFO::draw(sf::RenderTarget &window) {
        if (m_state == State::Flying) {
            m_sprite.setTextureRect(m_animation.getFrame());
            window.draw(m_sprite);
        }
    }

    const sf::Vector2f &UFO::getPosition() const { return m_sprite.getPosition(); }

    void UFO::onCollide(Collidable &other) {
        m_state = State::Destroyed;
        m_sprite.setPosition(
                -1000, 0); // Sortir de l'écran pour éviter qu'il entre en collision avec des projectiles.
    }
}