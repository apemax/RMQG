/*
    This file is part of RMQG.

    RMQG is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RMQG is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with RMQG.  If not, see <http://www.gnu.org/licenses/>.
*/
// Copyright (C) 2011 - 2022 Peter Wright
// Author: Peter Wright
// Random Maths Question Generator (RMQG)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

#ifndef GLOBAL_H
#define GLOBAL_H

void Casual();
void Challenge();
void Listgen(string Opt1, string Opt2, string Opt3, string Opt4, string Opt5, string Filename);
void Listcheck(string Filename);

extern double qnum1;
extern double qnum2;
extern double qnuma1;
extern double qnuma2;
extern int count;
extern int qtype1;
extern int qtype2;
extern int qtypec;
extern int BRangeMin;
extern int BRangeMax;
extern double DRangeMin;
extern double DRangeMax;
extern string qtypecl;
extern char ans1;
extern char ans2;
extern string CLoption1;
extern string CLoption2;
extern string CLoption3;
extern string CLoption4;
extern string CLoption5;
extern string CLoption6;

#endif
