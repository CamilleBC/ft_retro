/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:57:40 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 21:00:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <cstdlib> // exit codes
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	try {
    Game game;
    game.run();
    } catch (...) {
        clear();
        endwin();
    }
    return EXIT_SUCCESS;
}
