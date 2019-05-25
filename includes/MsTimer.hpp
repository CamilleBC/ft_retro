/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MsTimer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:22:56 by cbaillat          #+#    #+#             */
/*   Updated: 2019/05/25 18:25:24 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSTIMER_HPP
#define MSTIMER_HPP

#include <cstddef>
#include <ctime>

class MsTimer {
  private:
    timespec delta_start;
    timespec start;
    timespec substract_timespec(timespec t1, timespec t2);

  public:
    MsTimer();
    MsTimer(MsTimer const &other);
    ~MsTimer();
    MsTimer &operator=(MsTimer const &rhs);
    bool is_new_frame();
    timespec get_current_time() const;
};

#endif /* TIMER_HPP */
