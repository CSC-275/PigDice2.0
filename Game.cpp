#include <iostream>
#include "Game.h"

Game::Game() {
    m_game_score = 0;
    m_game_over = false;
    play_game();
}
void Game::set_game_score() {
}
int Game::get_game_score(){
    return m_game_score;
}
void Game::set_game_over() {
}
bool Game::reset_game_over(){
    m_game_over = false;
}

void Game::display_rules() {
    std::cout << "Let's Play PIG Dice!";
    std::cout << "\n\n* See how many turns it takes you to get to 20.";
    std::cout << "\n* Turn ends when you hold or roll a 1.";
    std::cout << "\n* If you roll a 1, you lose all points for the turn.";
    std::cout << "\n* If you hold, you save all points for the turn.";
}

void Game::play_game() {
    display_rules();
    while (!m_game_over) {
        m_myTurn.take_turn();
        std::cout << "Score for turn:" << m_myTurn.get_score_this_turn();
        m_game_score += m_myTurn.get_score_this_turn();
        std::cout << "\nTotal score:" << m_game_score;
        m_myTurn.reset_score_this_turn();
        m_myTurn.reset_turn_over();
        if (m_game_score >= 20) {
            m_game_over = true;
        }
    }
    std::cout << "\n\nYou finished with a final score of 20 or more in " << m_myTurn.get_turn_count() << " turns!";
}
