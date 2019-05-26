/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusScreen.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:56:43 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/26 21:02:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StatusScreen.hpp"

StatusScreen::StatusScreen(unsigned int height, unsigned int width,
                           unsigned int starty, unsigned int startx,
                           unsigned int lives, MsTimer const *timer)
    : Screen(height, width, starty, startx,
             Borders(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER,
                     ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER)),
      lives(lives), score(0), timer(timer) {}

StatusScreen::~StatusScreen() {}

void StatusScreen::print_status() {
    print_current_time();
    print_lives();
    print_score();
}

/* PRIVATE */

StatusScreen::StatusScreen() : Screen(), lives(0), score(0), timer(NULL) {}

void StatusScreen::print_current_time() {
    std::string time_str("Elapsed time: ");
    time_str.append(timer->get_current_string());
    mvwprintw(get_win(), 5, 5, time_str.c_str());
}

void StatusScreen::print_lives() {
    mvwprintw(get_win(), 6, 5, "Lives: %u", lives);
}
// setters

void StatusScreen::set_score(unsigned int new_score) { score = new_score; }
void StatusScreen::set_lives(unsigned int new_lives) { lives = new_lives; }

void StatusScreen::print_score() {
    mvwprintw(get_win(), 7, 5, "Score: %u", score);
}
