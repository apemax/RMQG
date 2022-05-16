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

#include <algorithm>
#include <chrono>
#include <thread>
#include "types.h"
#include "global.h"

using namespace std;

void SortLeaderboard()
{
  int SLeaderboard = 0;
  int SSubLeaderboard = 0;
  double TmpLeaderboard[10];

  for (; SLeaderboard < 1; SLeaderboard++)
  {
    for (; SSubLeaderboard < 2; SSubLeaderboard++)
    {
      for (int Position = 0; Position < 10; Position++)
      {
        TmpLeaderboard[Position] = ChallengeLeaderboard[SLeaderboard][SSubLeaderboard][Position];
      }

      std::sort(TmpLeaderboard, TmpLeaderboard + 10);

      for (int Position = 0; Position < 10; Position++)
      {
        ChallengeLeaderboard[SLeaderboard][SSubLeaderboard][Position] = TmpLeaderboard[Position];
      }
    }
  }
}

void OutputLeaderboard(int Leaderboard, int SubLeaderboard)
{
  int OutputPosition = 1;

  for (int Position = 0; Position < 10; Position++)
  {
    if (ChallengeLeaderboard[Leaderboard][SubLeaderboard][Position] != 0)
    {
      cout << OutputPosition << ". " << ChallengeLeaderboard[Leaderboard][SubLeaderboard][Position] << " Seconds." << endl;

      OutputPosition++;
    }
  }
  for (int Position = 0; Position < 10; Position++)
  {
    if (ChallengeLeaderboard[Leaderboard][SubLeaderboard][Position] == 0)
    {
      cout << OutputPosition << ". " << endl;

      OutputPosition++;
    }
  }
}

void Challenge()
{
  int OptC1;
  int OptC2;
  int OptC3;
  bool CRunning = true;

  while (CRunning == true)
  {
    cout << "1) Start a Challenge. 2) View Leaderboard. 3) Exit." << endl;
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
            Leaderboard = 0;

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
                SubLeaderboard = 0;

                ChallengeB();

                break;
              }
              case 2:
              {
                BRangeMin = 10;
                BRangeMax = 100;
                SubLeaderboard = 1;

                ChallengeB();

                break;
              }
              case 3:
              {
                BRangeMin = 100;
                BRangeMax = 1000;
                SubLeaderboard = 2;

                ChallengeB();

                break;
              }
            }

            break;
          }
          case 2:
          {
            Leaderboard = 1;
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
                SubLeaderboard = 0;

                ChallengeD();

                break;
              }
              case 2:
              {
                DRangeMin = 1.0;
                DRangeMax = 10.0;
                SubLeaderboard = 1;

                ChallengeD();

                break;
              }
              case 3:
              {
                DRangeMin = 10.0;
                DRangeMax = 100.0;
                SubLeaderboard = 2;

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
        int OptL1;
        int OptL2;

        cout << "1) Whole number leaderboards. 2) Decimal number leaderboards." << endl;
        cout << "> ";
        cin >> OptL1;

        switch (OptL1)
        {
          case 1:
          {
            Leaderboard = 0;
            cout << "1) 1 - 10 leaderboard. 2) 10 - 100 leaderboard. 3) 100 - 1000 leaderboard." << endl;
            cout << "> ";
            cin >> OptL2;

            switch (OptL2)
            {
              case 1:
              {
                SubLeaderboard = 0;

                OutputLeaderboard(Leaderboard, SubLeaderboard);

                break;
              }
              case 2:
              {
                SubLeaderboard = 1;

                OutputLeaderboard(Leaderboard, SubLeaderboard);

                break;
              }
              case 3:
              {
                SubLeaderboard = 2;

                OutputLeaderboard(Leaderboard, SubLeaderboard);

                break;
              }
            }
            break;
          }
          case 2:
          {
            Leaderboard = 1;
            cout << "1) 0.1 - 1.0 leaderboard. 2) 1.0 - 10.0 leaderboard. 3) 10.0 - 100.0 leaderboard." << endl;
            cout << "> ";
            cin >> OptL2;

            switch (OptL2)
            {
              case 1:
              {
                SubLeaderboard = 0;

                OutputLeaderboard(Leaderboard, SubLeaderboard);

                break;
              }
              case 2:
              {
                SubLeaderboard = 1;

                OutputLeaderboard(Leaderboard, SubLeaderboard);

                break;
              }
              case 3:
              {
                SubLeaderboard = 2;

                OutputLeaderboard(Leaderboard, SubLeaderboard);

                break;
              }
            }
            break;
          }
        }

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
