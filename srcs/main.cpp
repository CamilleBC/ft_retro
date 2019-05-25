/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:57:40 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 10:20:59 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // exit codes
#include <iostream>

#include "IGameEntity.hpp"
#include "Point.hpp"
#include "Grid.hpp"

#include <unistd.h>

int main(void) {
    Grid world;

    while(true){
        world.play_frame();
        world.print();
         usleep(200000);
    }
}
