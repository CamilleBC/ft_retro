/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:10:14 by chaydont          #+#    #+#             */
/*   Updated: 2019/05/25 10:38:56 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"

Grid::Grid() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = NULL;
        }
    }
    grid[60][2] =  new Obstacle(Point(2, 1));
    grid[20][8] =  new Obstacle(Point(1, 2));
    grid[15][55] = new Obstacle(Point(-1, -2));
    grid[25][40] = new Obstacle(Point(2, -1));
    grid[30][41] = new Obstacle(Point(3, -1));
    grid[40][24] = new Obstacle(Point(1, -2));
    grid[48][72] = new Obstacle(Point(1, 1));
    grid[48][20] = new Obstacle(Point(1, -1));
    grid[45][13] = new Obstacle(Point(-2, 1));
    grid[55][4] =  new Obstacle(Point(-3, -2));
    grid[27][10] = new Obstacle(Point(-1, 1));
    grid[20][35] = new Enemy(Point(1, 1));
    grid[50][50] = new Enemy(Point(0, -1));
    std::cout << "Object Built" << std::endl;
}

Grid::~Grid() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j])
                delete grid[i][j];
        }
    }
}

Grid::Grid(Grid const &a) { *this = a; }

Grid &Grid::operator=(Grid const &a) {
    (void)a;
    return *this;
}

void Grid::play_frame() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j]) {
                move_entity(Point(j, i));
            }
        }
    }
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j]) {
                grid[i][j]->end_turn();
            }
        }
    }
}

void Grid::move_entity(Point position) {
    IGameEntity *entity;
    IGameEntity **dest;

    entity = grid[position.y][position.x];
    grid[position.y][position.x] = NULL;
    Point move = entity->get_move();
    if (position.y + move.y >= GRID_HEIGHT || position.y + move.y < 0 ||
        position.x + move.x >= GRID_WIDTH || position.x + move.x < 0){
            return;
    }
    std::cout << move.x << " " <<  move.y << std::endl;
    dest = &(grid[position.y + move.y][position.x + move.x]);
    *dest = (*dest == NULL ? entity : entity->collide(*dest));
}

void Grid::print() const {
    std::cout << std::string( 100, '\n' );
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j])
                std::cout << grid[i][j]->get_texture();
            else
                std::cout << "   ";
        }
        std::cout << std::endl;
    }
}
