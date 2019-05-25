/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 15:43:47 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <stdlib.h>

Game::Game()
    : main_screen(MainScreen(MAINSCREEN_HEIGHT, MAINSCREEN_WIDTH, 0, 0)),
      status_screen(StatusScreen(STATUSSCREEN_HEIGHT, STATUSSCREEN_WIDTH, 0,
                                 MAINSCREEN_WIDTH + 1)),
      is_running(true) {
    std::cout << "Game created." << std::endl;
    init();
    init_grid();
}

Game::~Game() {
    clear();
    endwin();
    delete_grid();
    std::cout << "Game destroyed" << std::endl;
}

bool Game::get_user_input() {
    int key = getch();
    // static int const key_escape = 27;
    switch (key) {
    case ' ':
        // shoot
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
    case 'q':
        return false;
        break;
    default:
        break;
    }
    return true;
}

void Game::pause() {
    is_running = false;
    while (!is_running) {
        get_user_input();
    }
}

void Game::run() {
    while (is_running) {
        play_frame();
        main_screen.print(grid);
        main_screen.render();
        if (get_user_input() == false) {
            break;
        }
        usleep(100000);
    }
}

/* PRIVATE */

void Game::init() {
    initscr();
    keypad(stdscr, true);
    cbreak(); /* Line buffering disabled */
    refresh();
    noecho(); /* Don't echo() while we do getch */
    nodelay(stdscr, true); /* getch is non-blocking */
    main_screen.init();
    status_screen.init();
}

int Game::rand_int(int n) {
    return ((int)((rand() / (double)RAND_MAX) * n));
}

void Game::init_grid() {
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            grid[h][w] = NULL;
        }
    }
    for (size_t i = 0; i < 4; ++i)
    {
        grid[rand_int(GRID_HEIGHT / 4)][rand_int(GRID_WIDTH)] = new Obstacle();
    }
    grid[20][35] = new Enemy(Point(1, 1));
    grid[50][50] = new Enemy(Point(0, -1));
}

void Game::spawn_obstacle() {
    int rand = rand_int(100);
    if (rand < 50)
        return ;
    if (rand < 55)
    {
        for (size_t i  = 0; i < GRID_WIDTH; ++i)
        {
            grid[0][i] = new Obstacle(Point(0, 1));
        }
        return ;
    }
    for (int i = 0; i < rand_int(20); ++i)
    {
        grid[rand_int(GRID_HEIGHT / 10)][rand_int(GRID_WIDTH)] = new Obstacle();
    }
}

void Game::delete_grid() {
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
                delete grid[h][w];
            }
        }
    }
}

void Game::play_frame() {
    spawn_obstacle();
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
                // std::cout << "move";
                move_entity(Point(w, h));
            }
        }
    }
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
             //   std::cout << "end";
                grid[h][w]->end_turn();
            }
        }
    }
}

void Game::move_entity(Point position) {
    IGameEntity *entity;
    IGameEntity **dest;

    entity = grid[position.y][position.x];
    grid[position.y][position.x] = NULL;
    Point move = entity->get_move();
    if ((size_t)(position.y + move.y) >= GRID_HEIGHT ||
        position.y + move.y < 0 ||
        (size_t)(position.x + move.x) >= GRID_WIDTH ||
        position.x + move.x < 0) {
        return;
    }
    // std::cout << move.x << " " << move.y << std::endl;
    dest = &(grid[position.y + move.y][position.x + move.x]);
    *dest = (*dest == NULL ? entity : entity->collide(*dest));
}
