/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:57:40 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 21:57:23 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <cstdlib> // exit codes
#include <iostream>
#include <stdlib.h>
#include <time.h>

// void check_colours() {
//     if (has_colors() == FALSE) {
//         std::cerr << "Your terminal does not support color\n";
//         exit(EXIT_FAILURE);
//     }
// }

int main(void) {
    // check_colours();
    srand(time(NULL));
    Game game;
    game.run();
    return EXIT_SUCCESS;
}
