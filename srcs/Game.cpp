/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 19:14:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
    : main_screen(MainScreen(MAINSCREEN_HEIGHT, MAINSCREEN_WIDTH, 0, 0)),
      status_screen(StatusScreen(STATUSSCREEN_HEIGHT, STATUSSCREEN_WIDTH, 0,
                                 MAINSCREEN_WIDTH + 1, 3, &timer)),
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
    switch (key) {
    case ' ':
        // shoot
        break;
    case 'p':
        is_running ? pause() : run();
        break;
    case 's':
    case KEY_DOWN:
        // go down
        break;
    case 'a':
    case KEY_LEFT:
        // go left
        break;
    case 'd':
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
    flushinp();

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
        status_screen.print();
        main_screen.render();
        status_screen.render();
        if (get_user_input() == false) {
            break;
        }
        while (!timer.is_new_frame()) {
        }
    }
}

/* PRIVATE */

void Game::init() {
    initscr();
    keypad(stdscr, true);
    cbreak(); /* Line buffering disabled */
    refresh();
    noecho();              /* Don't echo() while we do getch */
    nodelay(stdscr, true); /* getch is non-blocking */
    main_screen.init();
    status_screen.init();
}

void Game::init_grid() {
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            grid[h][w] = NULL;
        }
    }
    grid[60][2] = new Obstacle(Point(2, 1));
    grid[20][8] = new Obstacle(Point(1, 2));
    grid[15][55] = new Obstacle(Point(-1, -2));
    grid[25][40] = new Obstacle(Point(2, -1));
    grid[30][41] = new Obstacle(Point(3, -1));
    grid[40][24] = new Obstacle(Point(1, -2));
    grid[48][72] = new Obstacle(Point(1, 1));
    grid[48][20] = new Obstacle(Point(1, -1));
    grid[45][13] = new Obstacle(Point(-2, 1));
    grid[55][4] = new Obstacle(Point(-3, -2));
    grid[27][10] = new Obstacle(Point(-1, 1));
    grid[20][35] = new Enemy(Point(1, 1));
    grid[50][50] = new Enemy(Point(0, -1));
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
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
                move_entity(Point(w, h));
            }
        }
    }
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
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
    dest = &(grid[position.y + move.y][position.x + move.x]);
    *dest = (*dest == NULL ? entity : entity->collide(*dest));
}
