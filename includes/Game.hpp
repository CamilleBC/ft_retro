/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:18:03 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 14:37:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include "Enemy.hpp"
#include "IGameEntity.hpp"
#include "KeyPress.hpp"
#include "MainScreen.hpp"
#include "MenuScreen.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "StatusScreen.hpp"

#include <locale.h>
#include <unistd.h> // usleep

class Game {
  private:
    MenuScreen menu_screen;
    MainScreen main_screen;
    StatusScreen status_screen;
    Player *player;
    MsTimer timer;
    // IGameEntity ***grid;
    IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH];
    // constructor
    Game(Game const &other);
    // operator
    Game &operator=(Game const &rhs);
    // methods
    void delete_grid();
    void init();
    void init_grid();
    void init_mainscreen();
    void play_frame();
    void move_entity(Point position);
    void spawn_obstacle();

  public:
    Game();
    ~Game();
    // methods
    int  rand_int(int n);
    bool get_user_input();
    bool pause();
    void run();
};

#endif /* GAME_HPP */
