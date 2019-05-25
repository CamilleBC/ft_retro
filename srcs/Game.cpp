/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 10:30:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
    : main_screen(
          MainScreen(main_height, main_width, main_starty, main_startx)),
      pressed_keys(KeyPress(max_key_pressed)), is_running(true) {
    std::cout << "Game created." << std::endl;
    init();
}

Game::~Game() {
    endwin();
    std::cout << "Game destroyed" << std::endl;
}

void Game::get_user_input() {
    int key = getch();
    // dbg
    std::string *plan = new std::string[2];
    plan[0] = "@@";
    plan[1] = "@@";
    BluePrint obj(plan, 2);
    static int i = 1;
    // dbg
    switch (key) {
    case ' ':
        // shoot
        // dbg
        i = (i + obj.size);
        main_screen.print(obj, Point(3, i));
        // dbg
        break;
    case 'P':
        is_running ? pause() : run();
        break;
    case 'S':
    case KEY_DOWN:
        // go down
        break;
    case 'A':
    case KEY_LEFT:
        // go left
        break;
    case 'D':
    case KEY_RIGHT:
        // go right
        break;
    case 'W':
    case KEY_UP:
        // go up
        break;
    default:
        break;
    }
}

void Game::pause() {
    std::cout << "PAUSED" << std::endl;
    is_running = false;
    while (!is_running) {
        get_user_input();
    }
}

void Game::run() {
    std::cout << "RUNNING" << std::endl;
    while (is_running) {
        get_user_input();
        main_screen.render();
        refresh();
    }
}

/* PRIVATE */

void Game::init() {
    setlocale(LC_ALL, "en_US");
    initscr();
    cbreak(); /* Line buffering disabled */
    refresh();
    noecho(); /* Don't echo() while we do getch */
    main_screen.init();
    refresh();
}

// static

unsigned int const Game::main_height = 80;
unsigned int const Game::main_width = 240;
unsigned int const Game::main_startx = 0;
unsigned int const Game::main_starty = 0;
// unsigned int const Game::side_height = 94;
// unsigned int const Game::side_width = 80;
