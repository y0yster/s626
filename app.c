/***************************************************************************
 *   Copyright (C) 2014 by Wojciech Domski                                 *
 *   Wojciech.Domski@gmail.com                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <rtdm/rtdm.h>
#include <xeno_config.h>
#include <analogy/analogy.h>

#include "S626API.h"

#define BUS0 6
#define SLOT0 2

#define BUS1 6
#define SLOT1 1

int main(int argc, char ** argv)
{
  ts626 * s626;
  ts626 * s626_2;

  printf("Opening a0 with s0\n");
  s626 = s626_init("S626", "analogy0");
	s626_set_options(s626);
 	s626_set_bus(s626, BUS0);
 	s626_set_slot(s626, SLOT0);
 	s626_open(s626);

  getchar();

 	printf("Opening a1 with s1\n");
  s626_2 = s626_init("S626", "analogy1");
	s626_set_options(s626_2);
 	s626_set_bus(s626_2, BUS1);
 	s626_set_slot(s626_2, SLOT1);
 	s626_open(s626_2);
 	
  getchar();

 	printf("Closing a0 with s0\n");
	s626_close( s626);
	s626_deinit( s626);
	s626 = NULL;
	
	getchar();

	printf("Closing a1 with s1\n");
	s626_close( s626_2);
	s626_deinit( s626_2);
	s626_2 = NULL;
	
	getchar();

  printf("Opening a0 with s1\n");
  s626 = s626_init("S626", "analogy0");
	s626_set_options(s626);
 	s626_set_bus(s626, BUS1);
 	s626_set_slot(s626, SLOT1);
 	s626_open(s626);
 	
 	getchar();

  printf("Opening a1 with s0\n");
  s626_2 = s626_init("S626", "analogy1");
	s626_set_options(s626_2);
 	s626_set_bus(s626_2, BUS0);
 	s626_set_slot(s626_2, SLOT0);
 	s626_open(s626_2);
 	
 	getchar();

	printf("Closing a0 with s1\n");
	s626_close( s626);
	s626_deinit( s626);
	s626 = NULL;

	getchar();

	printf("Closing a1 with s0\n");
	s626_close( s626_2);
	s626_deinit( s626_2);
	s626_2 = NULL;

  return 0;
}
