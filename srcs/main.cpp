/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:57:40 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 16:27:41 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <cstdlib> // exit codes
#include <iostream>

int main(void) {
    Game game;
    game.run();
    std::cout << "Game quit!";
    return EXIT_SUCCESS;
}
