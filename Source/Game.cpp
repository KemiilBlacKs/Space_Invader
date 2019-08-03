/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Game.cpp                                                   #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Mouhammad <dahala_m@etna-alternance.net>               #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/01/19 20:15:58 by Mouhammad                    #          bachir_c          #   */
/*  updated: 08/02/19 20:25:36 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/
#include <iostream>
#include "Game.hh"

Game::Game() : m_window(sf::VideoMode(1920, 1080), "Space_Invaders") {
    m_window.setPosition({m_window.getPosition().x, 0});
    m_window.setFramerateLimit(60);

    sf::Image icon;
    icon.loadFromFile("../Images/icon.png");
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

// Lance la boucle principale
void Game::run() {
    constexpr unsigned TPS = 30; // ticks per seconds
    const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    // Boucle principale du jeu
    while (m_window.isOpen()) {
        auto &state = getCurrentState();

        // Obtenir le temps
        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;
        lastTime = time;
        lag += elapsed;

        // Mise à jour en temps réel
        state.handleInput();
        state.update(elapsed);
        counter.update();

        // Mise à jour à temps fixe
        while (lag >= timePerUpdate) {
            ticks++;
            lag -= timePerUpdate;
            state.fixedUpdate(elapsed);
        }

        // Rendu
        m_window.clear();
        state.render(m_window);
        counter.draw(m_window);
        m_window.display();

        // Événements de la fenêtre
        handleEvent();
        tryPop();
    }
}

// Essaie de faire apparaître l'état actuel du jeu
void Game::tryPop() {
    if (m_shouldPop) {
        m_shouldPop = false;
        if (m_shouldExit) {
            m_states.clear();
            return;
        } else if (m_shouldChageState) {
            m_shouldChageState = false;
            m_states.pop_back();
            pushState(std::move(m_change));
            return;
        }

        m_states.pop_back();
        if (!m_states.empty()) {
            getCurrentState().onOpen();
        }
    }
}

void Game::handleEvent() {
    sf::Event e;

    while (m_window.pollEvent(e)) {
        getCurrentState().handleEvent(e);
        switch (e.type) {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}

// Renvoie une référence à l'état actuel du jeu
StateBase &Game::getCurrentState() { return *m_states.back(); }

void Game::pushState(std::unique_ptr<StateBase> state) {
    m_states.push_back(std::move(state));
    getCurrentState().onOpen();
}

// Flag d'un booléen pour le jeu à l'état pop
void Game::popState() { m_shouldPop = true; }

void Game::exitGame() {
    m_shouldPop = true;
    m_shouldExit = true;
}

const sf::RenderWindow &Game::getWindow() const { return m_window; }

void Game::resizeWindow(unsigned width, unsigned height) {
    m_window.close();
    m_window.create(sf::VideoMode(width, height), "Space Invaders");
}