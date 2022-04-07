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

void Listgen(string Opt1, string Opt2, string Opt3, string Filename)
{
  if(Opt1 == "-b" || Opt1 == "1")
  {
    qtype1 = 1;
  }
  else if(Opt1 == "-d" || Opt1 == "2")
  {
    qtype1 = 2;
  }
  if(Opt2 == "-m" || Opt2 == "1")
  {
    qtype2 = 1;
    qtypecl = "x";
  }
  else if(Opt2 == "-a" || Opt2 == "2")
  {
    qtype2 = 2;
    qtypecl = "+";
  }
  else if(Opt2 == "-s" || Opt2 == "3")
  {
    qtype2 = 3;
    qtypecl = "-";
  }
  else if(Opt2 == "-d" || Opt2 == "4")
  {
    qtype2 = 4;
    qtypecl = "/";
  }
  else if (Opt2 == "-r" || Opt2 == "5")
  {
    qtype2 = 5;
  }

  ofstream Qlist_file(Filename, ios::out | ios::app);

  if(Qlist_file.is_open())
  {
    int LineCount = stoi(Opt3);

    Qlist_file << "Line count=" << LineCount << endl;

    for(int i = 0; i <= LineCount; i++ )
    {
      if(qtype1 == 1)
      {
        GrandnumB();
      }
      else if(qtype1 == 2)
      {
        GrandnumD();
      }

      if (qtype2 == 5)
      {
        int RandOptCL = GrandOpt();

        switch (RandOptCL)
        {
          case 0:
          {
            qtypecl = "x";

            break;
          }
          case 1:
          {
            qtypecl = "+";

            break;
          }
          case 2:
          {
            qtypecl = "-";

            break;
          }
          case 3:
          {
            qtypecl = "/";

            break;
          }
        }
      }

      Qlist_file << qnum1 << qtypecl << qnum2 << "=" << endl;
    }
  }
  else
  {
    cout << "Unable to open file." << endl;
  }

  Qlist_file.close();
}
