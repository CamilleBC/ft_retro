/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:38:41 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 15:43:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() {}

Player::Player(Player const &other) {}

Player const &Player::operator=(Player const &rhs) {}

Player::~Player() {}

Point Player::get_move() {}

BluePrint const &Player::get_blueprint() const { return BluePrint(); }

IGameEntity *Player::collide(IGameEntity *) { return NULL; }
IGameEntity *Player::get_collided(Obstacle *) { return NULL; }
IGameEntity *Player::get_collided(Enemy *) { return NULL; }
