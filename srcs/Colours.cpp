/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colours.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:40:04 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/21 10:46:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colours.hpp"

Colours::Colours() {}

Colours::~Colours() {}

const char *Colours::red = "\033[1;31m";
const char *Colours::green = "\033[1;32m";
const char *Colours::yellow = "\033[1;33m";
const char *Colours::blue = "\033[1;34m";
const char *Colours::purple = "\033[1;35m";
const char *Colours::cyan = "\033[1;36m";
const char *Colours::white = "\033[1;37m";
const char *Colours::nc = "\033[0m";
