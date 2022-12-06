/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim <minkim@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:30:51 by minkim            #+#    #+#             */
/*   Updated: 2022/10/24 20:37:22 by minkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);
    
    delete ptr;
    return 0;
}