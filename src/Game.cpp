#include "Game.hpp"

Game::Game() : m_clientEngine{} {}

void Game::run() {
    m_clientEngine.runClient();
}
