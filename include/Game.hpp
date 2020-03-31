#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include "client/Engine.hpp"

class Game {
    public:
        Game();

        void run();
    private:
        Client::Engine m_clientEngine;
};

#endif
