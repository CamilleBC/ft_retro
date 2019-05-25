/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 14:18:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

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
    endwin();
    delete_grid();
    std::cout << "Game destroyed" << std::endl;
}

void Game::get_user_input() {
    int key = getch();
    static int const key_escape = 27;
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
    case key_escape:
        // go up
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

void Game::pause() {
    is_running = false;
    while (!is_running) {
        get_user_input();
    }
}

void Game::run() {
    while (is_running) {
        main_screen.print(grid);
        refresh();
        get_user_input();
        play_frame();
        usleep(100000);
    }
}

/* PRIVATE */

void Game::init() {
    setlocale(LC_ALL, "en_US");
    initscr();
    // cbreak(); /* Line buffering disabled */
    nocbreak();
    refresh();
    noecho(); /* Don't echo() while we do getch */
    main_screen.init();
    status_screen.init();
    refresh();
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
            // if (grid[h][w]) {
            //     delete grid[h][w];
            // }
        }
        // if (grid[h]) {
        // delete grid[h];
        // }
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
    // std::cout << move.x << " " << move.y << std::endl;
    dest = &(grid[position.y + move.y][position.x + move.x]);
    *dest = (*dest == NULL ? entity : entity->collide(*dest));
}
