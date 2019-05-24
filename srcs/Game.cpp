/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 01:57:14 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
    : // main_screen(MainScreen(main_height, main_width, 0, 0)),
      pressed_keys(KeyPress(max_key_pressed)), is_running(true) {
    std::cout << "Game created." << std::endl;
    init();
}

Game::~Game() {
    endwin();
    std::cout << "Game destroyed" << std::endl;
}

void Game::get_user_input() {
    pressed_keys.add(getch());
    if (pressed_keys.contains(' ')) {
        is_running ? pause() : run();
    }
    pressed_keys.display_content();
    pressed_keys.clear();
}

void Game::pause() {
    std::cout << "PAUSED" << std::endl;
    is_running = false;
    while (!is_running) {
        get_user_input();
    }
}

// DEBUG
#include <unistd.h>
void Game::run() {
    std::cout << "RUNNING" << std::endl;
    while (is_running) {
        refresh();
        wrefresh(main_screen);
        sleep(1);
        get_user_input();
    }
}

/* PRIVATE */

void Game::init() {
    initscr();
    cbreak(); /* Line buffering disabled */
    refresh();
    noecho(); /* Don't echo() while we do getch */
    init_mainscreen();
    refresh();
}

void Game::init_mainscreen() {
    main_screen = newwin(LINES, COLS, 0, 0);
    nodelay(main_screen, true); /* getch is non-blocking */
    wborder(main_screen, '|', '|', '-', '-', '|', '|', '|', '|');
        wprintw(main_screen, "");
    /* The parameters taken are
     * 1. win: the window on which to operate
     * 2. ls: character to be used for the left side of the window
     * 3. rs: character to be used for the right side of the window
     * 4. ts: character to be used for the top side of the window
     * 5. bs: character to be used for the bottom side of the window
     * 6. tl: character to be used for the top left corner of the window
     * 7. tr: character to be used for the top right corner of the window
     * 8. bl: character to be used for the bottom left corner of the window
     * 9. br: character to be used for the bottom right corner of the window
     */
    wrefresh(main_screen);
}

// static
unsigned int const Game::main_height = 40;
unsigned int const Game::main_width = 20;
// unsigned int const Game::side_height = 94;
// unsigned int const Game::side_width = 80;
