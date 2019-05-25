/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 20:00:47 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <stdlib.h>

Game::Game()
    : main_screen(MainScreen(MAINSCREEN_HEIGHT, MAINSCREEN_WIDTH, 0, 0)),
      status_screen(StatusScreen(STATUSSCREEN_HEIGHT, STATUSSCREEN_WIDTH, 0,
                                 MAINSCREEN_WIDTH + 1, 3, &timer))
    {
    std::cout << "Game created." << std::endl;
    init();
    player = new Player(Point(0, 0));
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
        player->set_shoot();
        break;
    case 'p':
        pause();
        break;
    case 's':
    case KEY_DOWN:
        player->set_direction(Point(0, 1));
        break;
    case 'a':
    case KEY_LEFT:
        player->set_direction(Point(-1, 0));
        break;
    case 'd':
    case KEY_RIGHT:
        player->set_direction(Point(1, 0));
        break;
    case 'w':
    case KEY_UP:
        player->set_direction(Point(0, -1));
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
    int key = getch();
    while (key != 'p') {
        key = getch();
    }
}

void Game::run() {
    while (true) {
        play_frame();
        main_screen.print(grid);
        status_screen.print();
        main_screen.render();
        status_screen.render();
        if (!get_user_input()) {
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
    player = new Player(Point(0, 0));
    grid[70][40] = player;
    grid[20][35] = new Enemy(Point(1, 1));
    grid[50][50] = new Enemy(Point(0, -1));
}

void Game::spawn_obstacle() {
    int rand = rand_int(1000);
    if (rand < 800)
        return ;
    if (rand < 805)
    {
        for (size_t i  = 0; i < GRID_WIDTH; ++i)
        {
            grid[0][i] = new Obstacle(Point(0, 1));
        }
        return ;
    }
    if (rand < 900)
    {
        rand = rand_int(GRID_WIDTH - 3);
        for (int i = 0; i < 6; i += 2)
        {
            for (int j = 0; j < 3; ++j)
            {
                grid[i][rand + j] = new Obstacle(Point(0, 1));
            }
        }
        return ;
    }
    for (int i = 0; i < rand_int(4) + 2; ++i)
    {
        grid[rand_int(GRID_HEIGHT / 20)][rand_int(GRID_WIDTH)] = new Obstacle();
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
        position.y + move.y < 0) {
            delete entity;
        return;
    }
    if ((size_t)(position.x + move.x) >= GRID_WIDTH ||
        position.x + move.x < 0)
    {
        entity->direction.x *= -1;
        move.x *= -1;
    }
    Point shot = entity->get_shoot();
    if (shot.x != 0 || shot.y != 0){
        grid[position.y + shot.y][position.x + shot.x] = new Projectile(shot);
        grid[position.y][position.x] = entity;
        entity->set_shoot(Point(0, 0));
    } else {
        dest = &(grid[position.y + move.y][position.x + move.x]);
        *dest = (*dest == NULL ? entity : entity->collide(*dest));
    }
}
