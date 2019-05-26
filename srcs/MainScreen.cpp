/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainScreen.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:43 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 18:21:39 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainScreen.hpp"

MainScreen::MainScreen(unsigned int height, unsigned int width,
                       unsigned int starty, unsigned int startx)
    : Screen(height, width, starty, startx,
             Borders(ACS_LTEE, ACS_RTEE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER,
                     ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER)) {}

MainScreen::~MainScreen() {}

void MainScreen::print(IGameEntity ***grid) {
    for (size_t h = 0; h < GRID_HEIGHT; ++h) {
        for (size_t w = 0; w < GRID_WIDTH; ++w) {
            if (grid[h][w] != NULL) {
                print_object(grid[h][w]->get_blueprint(), Point(w, h));
            } else {
                print_empty(Point(w, h));
            }
        }
    }
}

void MainScreen::print_empty(Point coord) {
    std::string empty(x_factor, ' ');
    mvwprintw(get_win(), coord.y + get_box(), coord.x * x_factor + get_box(),
              empty.c_str());
}

void MainScreen::print_object(BluePrint const &object, Point coord) {
    for (size_t i = 0; i < object.size; ++i) {
        mvwprintw(get_win(), coord.y + i + get_box(),
                  coord.x * x_factor + get_box(), object.texture[i].c_str());
    }
}

/* PRIVATE */

MainScreen::MainScreen() : Screen() {}

// static

size_t const MainScreen::x_factor = 3;
