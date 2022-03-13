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

void Listcheck(string Filename)
{
  ifstream Qlist_file(Filename, ios::in);

  if(Qlist_file.is_open())
  {
    int LineCount;
    string LoadLine;

    getline(Qlist_file, LoadLine);

    LineCount = stoi(LoadLine.substr(11, 2));

    for(int i = 0; i <= LineCount; i++)
    {
      getline(Qlist_file, LoadLine);

      for(unsigned int PosNum = 0; PosNum <= LoadLine.size(); PosNum++)
      {
        string QType;

        for(unsigned int PosNum3 = 0; PosNum3 <= LoadLine.size(); PosNum3++)
        {
          if(LoadLine.substr(PosNum3, 1) == "+" || LoadLine.substr(PosNum3, 1) == "-" || LoadLine.substr(PosNum3, 1) == "x" || LoadLine.substr(PosNum3, 1) == "/")
          {
            QType = LoadLine.substr(PosNum3, 1);
          }
        }

        if(LoadLine.substr(PosNum, 1) == QType)
        {
          unsigned int Pos;
          unsigned int Len;

          if(PosNum == 1)
          {
            Len = 1;
          }
          else if(PosNum == 2)
          {
            Len = 2;
          }

          qnum1 = stoi(LoadLine.substr(0, Len));

          if(PosNum == 1)
          {
            Pos = 2;
          }
          else if(PosNum == 2)
          {
            Pos = 3;
          }

          for(unsigned int PosNum1 = 0; PosNum1 <= LoadLine.size(); PosNum1++)
          {
            if(LoadLine.substr(PosNum1, 1) == "=")
            {
              if(PosNum1 == 3)
              {
                Len = 1;
              }
              else if(PosNum1 == 4)
              {
                Len = 2;
              }
            }
          }

          qnum2 = stoi(LoadLine.substr(Pos, Len));

          for(unsigned int PosNum2 = 0; PosNum2 <= LoadLine.size(); PosNum2++)
          {
            if(LoadLine.substr(PosNum2, 1) == "=")
            {
              if(PosNum2 == 3)
              {
                Pos = 4;
              }
              else if(PosNum2 == 4)
              {
                Pos = 5;
              }
              else if(PosNum2 == 5)
              {
                Pos = 6;
              }

              if(PosNum2 == 3)
              {
                Len = 1;
              }
              else if(PosNum2 == 4)
              {
                Len = 3;
              }
              else if(PosNum2 == 5)
              {
                Len = 3;
              }
            }
          }

          qnuma2 = stoi(LoadLine.substr(Pos, Len));

          cout << qnum1 << QType << qnum2 << endl;

          if(QType == "+")
          {
            qnuma1 = (qnum1 + qnum2);
          }
          else if(QType == "-")
          {
            qnuma1 = (qnum1 - qnum2);
          }
          else if(QType == "x")
          {
            qnuma1 = (qnum1 * qnum2);
          }
          else if(QType == "/")
          {
            qnuma1 = (qnum1 / qnum2);
          }

          if(qnuma1 == qnuma2)
          {
            cout << "Correct, The answer: " << qnuma1 << endl;

            PosNum = LoadLine.size();
          }
          else
          {
            cout << "Wrong, The correct answer is: " << qnuma1 << endl;

            PosNum = LoadLine.size();
          }
        }
      }
    }
  }
  else
  {
    cout << "Unable to open file." << endl;
  }
}
