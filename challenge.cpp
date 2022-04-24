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

#include <chrono>
#include <thread>
#include "types.h"
#include "global.h"

void Challenge()
{
  int OptC1;
  int OptC2;
  int OptC3;
  bool CRunning = true;

  while (CRunning == true)
  {
    cout << "1) Start a Challenge. 2) View saved results. 3) Exit." << endl;
    cout << "> ";
    cin >> OptC1;

    switch (OptC1)
    {
      case 1:
      {
        cout << "Choose type of questions, 1) Whole numbers. 2) Decimal numbers." << endl;
        cout << "> ";
        cin >> OptC2;

        switch (OptC2)
        {
          case 1:
          {
            cout << "Choose range of numbers. 1) 1 - 10. 2) 10 - 100. 3) 100 - 1000." << endl;
            cout << "> ";
            cin >> OptC3;

            cout << "Ready?" << endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));

            cout << "Go!" << endl;

            switch (OptC3)
            {
              case 1:
              {
                BRangeMin = 1;
                BRangeMax = 10;

                ChallengeB();

                break;
              }
              case 2:
              {
                BRangeMin = 10;
                BRangeMax = 100;

                ChallengeB();

                break;
              }
              case 3:
              {
                BRangeMin = 100;
                BRangeMax = 1000;

                ChallengeB();

                break;
              }
            }

            break;
          }
          case 2:
          {
            cout << "Choose range of numbers. 1) 0.1 - 1.0. 2) 1.0 - 10.0. 3) 10.0 - 100.0." << endl;
            cout << "> ";
            cin >> OptC3;

            cout << "Ready?" << endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));

            cout << "Go!" << endl;

            switch (OptC3)
            {
              case 1:
              {
                DRangeMin = 0.1;
                DRangeMax = 1.0;

                ChallengeD();

                break;
              }
              case 2:
              {
                DRangeMin = 1.0;
                DRangeMax = 10.0;

                ChallengeD();

                break;
              }
              case 3:
              {
                DRangeMin = 10.0;
                DRangeMax = 100.0;

                ChallengeD();

                break;
              }
            }

            break;
          }
        }

        break;
      }
      case 2:
      {
        //Saved results.

        cout << "Saved results." << endl;

        break;
      }
      case 3:
      {
        CRunning = false;

        break;
      }
    }
  }

}
