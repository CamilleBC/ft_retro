/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:19:14 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 22:39:05 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <stdlib.h>

Game::Game()
    // : menu_screen(MenuScreen(MENUSCREEN_HEIGHT, MENUSCREEN_WIDTH, 40, 40)),
    : main_screen(MainScreen(MAINSCREEN_HEIGHT, MAINSCREEN_WIDTH, 0, 0)),
      status_screen(StatusScreen(STATUSSCREEN_HEIGHT, STATUSSCREEN_WIDTH, 0,
                                 MAINSCREEN_WIDTH + 1, 3, &timer)),
      lives(3), score(0) {
    init();
    random_gen = new RandomGenerator();
    grid = create_grid();
    spawn_player();
}

Game::~Game() {
    clear();
    endwin();
    empty_grid();
    delete_grid();
    print_exit_message();
}

bool Game::get_user_input() {
    int key = getch();
    switch (key) {
    case ' ':
        player->set_is_shooting(true);
        break;
    case 'p':
        return pause();
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
    return true;
}

bool Game::pause() {
    timer.start_pause();
    while (true) {
        int key = getch();
        switch (key) {
        case 'p':
            timer.end_pause();
            return true;
            break;
        case 'q':
            timer.end_pause();
            return false;
        default:
            break;
        }
    }
}

void Game::run() {
    while (true) {
        play_frame();
        if (!lives_observer() || !get_user_input()) {
            break;
        }
        main_screen.print(grid);
        status_screen.set_score(score);
        status_screen.print_status();
        main_screen.render();
        status_screen.render();
        while (!timer.is_new_frame()) {
        }
    }
}

void Game::print_exit_message() const {
    std::cout << std::endl
              << Colours::green << "Congratulations, you lost!" << Colours::nc
              << std::endl
              << "Your final " << Colours::blue << "score" << Colours::nc
              << " was " << Colours::blue << score << ", in " << Colours::purple
              << timer.get_current_string() << Colours::nc << "." << std::endl
              << "Well done, loser." << std::endl
              << std::endl;
}

bool Game::lives_observer() {
    static unsigned int lives_prev = 3;

    if (lives != lives_prev) {
        lives_prev = lives;
        if (lives == 0) {
            return false;
        } else {
            spawn_player();
            status_screen.set_lives(lives);
        }
    }
    return true;
}

/* PRIVATE */

void Game::init() {
    initscr();
    keypad(stdscr, true);
    cbreak();              /* Line buffering disabled */
    noecho();              /* Don't echo() while we do getch */
    nodelay(stdscr, true); /* getch is non-blocking */
    curs_set(0);           /* Don't show the cursor */
    init_colours();
    refresh();
    main_screen.init();
    status_screen.init();
}

void Game::init_colours() {
    start_color();
    init_pair(SPACE_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(OBSTACLE_PAIR, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(ENEMY_PAIR, COLOR_CYAN, COLOR_BLACK);
    init_pair(ROAD_PAIR, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PLAYER_PAIR, COLOR_GREEN, COLOR_BLACK);
    init_pair(PROJECTILE_PAIR, COLOR_RED, COLOR_BLACK);
}

int Game::rand_int(int n) { return ((int)((rand() / (double)RAND_MAX) * n)); }

IGameEntity **Game::create_array1D() {
    IGameEntity **array1D = new IGameEntity *[GRID_WIDTH];
    for (size_t i = 0; i < GRID_WIDTH; ++i) {
        array1D[i] = NULL;
    }
    return array1D;
}

IGameEntity ***Game::create_grid() {
    IGameEntity ***array2D = new IGameEntity **[GRID_HEIGHT];
    for (size_t i = 0; i < GRID_HEIGHT; ++i) {
        array2D[i] = create_array1D();
    }
    return array2D;
}

void Game::empty_grid() {
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
                delete grid[h][w];
            }
        }
    }
}

void Game::delete_grid() {
    for (size_t i = 0; i < GRID_HEIGHT; i++) {
        delete grid[i];
    }
    delete grid;
}

void Game::spawn_player() {
    player = new Player(Point(0, 0), &lives);
    for (size_t h = 70; h > 0; --h) {
        for (size_t w = 40; w < GRID_WIDTH; ++w) {
            if (!grid[h][w]) {
                grid[h][w] = player;
                return;
            }
        }
    }
}

void Game::play_frame() {
    IGameEntity ***new_grid = create_grid();

    static size_t frames = 0;
    random_gen->spawn(grid, frames);
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w]) {
                move_entity(new_grid, Point(w, h));
            }
        }
    }
    delete_grid();
    grid = new_grid;
    frames++;
}

void Game::move_entity(IGameEntity ***new_grid, Point position) {
    IGameEntity *entity;
    IGameEntity **dest;

    entity = grid[position.y][position.x];
    Point move = entity->get_move();
    if ((size_t)(position.y + move.y) >= GRID_HEIGHT ||
        position.y + move.y < 0) {
        delete entity;
        return;
    }
    if ((size_t)(position.x + move.x) >= GRID_WIDTH ||
        position.x + move.x < 0) {
        Point new_dir =
            Point(-entity->get_direction().x, entity->get_direction().y);
        entity->set_direction(new_dir);
        move.x *= -1;
    }
    if (dynamic_cast<ICanShoot *>(entity) &&
        dynamic_cast<ICanShoot *>(entity)->get_is_shooting()) {
        Point shot = dynamic_cast<ICanShoot *>(entity)->get_shot();
        int *projectile_score =
            (entity->get_type() == ::player) ? &score : NULL;
        if ((size_t)(position.y + shot.y) < GRID_HEIGHT &&
            position.y + shot.y >= 0 &&
            (size_t)(position.x + shot.x) < GRID_WIDTH &&
            position.x + shot.x >= 0 &&
            !new_grid[position.y + shot.y][position.x + shot.x])
            new_grid[position.y + shot.y][position.x + shot.x] =
                new Projectile(shot, projectile_score);
        new_grid[position.y][position.x] = entity;
        dynamic_cast<ICanShoot *>(entity)->set_is_shooting(false);
    } else {
        dest = &(new_grid[position.y + move.y][position.x + move.x]);
        *dest = (*dest == NULL ? entity : entity->collide(*dest));
    }
}
