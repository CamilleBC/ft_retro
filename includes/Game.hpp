/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:18:03 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 01:57:06 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include "KeyPress.hpp"
#include "MainScreen.hpp"

class Game {
  private:
    WINDOW *main_screen;
    KeyPress pressed_keys;
    bool is_running;
    static unsigned int const main_height;
    static unsigned int const main_width;
    // static unsigned int const side_height;
    // static unsigned int const side_width;
    static unsigned int const max_key_pressed = 10;
    // constructor
    Game(Game const &other);
    // operator
    Game &operator=(Game const &rhs);
    // methods
    void init();
    void init_mainscreen();

  public:
    Game();
    ~Game();
    // methods
    void get_user_input();
    void pause();
    void run();
};

#endif /* GAME_HPP */
