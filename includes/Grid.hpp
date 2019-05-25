/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:04:30 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 01:40:40 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
#define GRID_HPP

#define GRID_HEIGHT 80
#define GRID_WIDTH 80

#include "IGameEntity.hpp"
#include "Point.hpp"
#include "Obstacle.hpp" /// TO REMOVE //
#include <iostream>

class Grid {
  private:
    IGameEntity *grid[GRID_HEIGHT][GRID_WIDTH];

    void move_entity(Point);
    Grid(Grid const &);
    Grid &operator=(Grid const &);

  public:
    Grid();
    ~Grid();

    void play_frame();
    void print() const;
};

#endif /* GRID_HPP */
