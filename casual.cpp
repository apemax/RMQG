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

#include "types.h"
#include "global.h"

void Casual()
{
  do
  {
    cout << "1 = basic, 2 = decimal. x = 1,+ = 2,- = 3,/ = 4," << endl;
    cout << "Random type of question = 5." << endl;
    cout << "what type of question would you like to do?" << endl;
    cout << "> ";
    cin >> qtypec;

    if (qtypec == 11 || qtypec == 12 || qtypec == 13 || qtypec == 14 || qtypec == 15)
    {
      cout << "Please enter a minimum and maximum range of numbers to use." << endl;
      cout << "Default is Min = 1, Max = 10." << endl;
      cout << "Minimum: ";
      cin >> BRangeMin;
      cout << "Maximum: ";
      cin >> BRangeMax;
    }
    else if (qtypec == 21 || qtypec == 22 || qtypec == 23 || qtypec == 24 || qtypec == 25)
    {
      cout << "Please enter a minimum and maximum range of numbers to use." << endl;
      cout << "Default is Min = 0.1, Max = 10." << endl;
      cout << "Minimum: ";
      cin >> DRangeMin;
      cout << "Maximum: ";
      cin >> DRangeMax;
    }

    switch (qtypec)
    {
      case 11:
      {
        MultiplyB();

        break;
      }
      case 12:
      {
        AddB();

        break;
      }
      case 13:
      {
        SubtractB();

        break;
      }
      case 14:
      {
        DivideB();

        break;
      }
      case 15:
      {
        RandomB();

        break;
      }
      case 21:
      {
        MultiplyD();

        break;
      }
      case 22:
      {
        AddD();

        break;
      }
      case 23:
      {
        SubtractD();

        break;
      }
      case 24:
      {
        DivideD();

        break;
      }
      case 25:
      {
        RandomD();

        break;
      }
    }

    cout << "do you want another question?(y/n)" << endl;
    cout << "> ";

    cin >> ans1;

    cout << "do you what to know how many questions you got right?(y/n)" << endl;
    cout << "> ";

    cin >> ans2;

    if (ans2 == 'y' || ans2 == 'Y')
    {
      cout << "your score is: " << count << endl;
    }

  }
  while(ans1 == 'y' || ans1 == 'Y');
}
