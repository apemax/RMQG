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
// Copyright (C) 2011 - 2019 Peter Wright
// Author: Peter Wright
// Random Maths Question Generator (RMQG)

#include "types.h"
#include "global.h"

int main(int argc, char *argv[])
{
  int Opt1;
  int CLOpt1;
  string File_name;
  string running = "true";

  cout << "Random Maths Question Generator (RMQG) Copyright (C) 2011 - 2019 Peter Wright" << endl;
  cout << "This program comes with ABSOLUTELY NO WARRANTY; for details see the file named COPYING in the program folder." << endl;
  cout << "This is free software, and you are welcome to redistribute it" << endl;
  cout << "under certain conditions; for details see the file named COPYING in the program folder." << endl;
  cout << " " << endl;

  if(argc <= 1)
  {
    cout << "welcome to the random maths question generator." << endl;
    cout << " " << endl;

    while (running == "true")
    {
      cout << "1) Casual mode. 2) Challenge mode. 3) Help. 4) Exit." << endl;
      cout << ">";
      cin >> Opt1;

      switch (Opt1) {
        case 1:
        {
          //Casual mode.

          Casual();

          break;
        }
        case 2:
        {
          //Challenge mode, Coming soon.

          Challenge();

          break;
        }
        case 3:
        {
          //Help.
          cout << " " << endl;
          cout << "Casual mode." << endl;
          cout << "When it asks you what type of question you would like to do type in either 1 for" << endl;
          cout << "basic questions followed by what type of basic question you want to do or 2 for" << endl;
          cout << "decimal questions followed by what type of decimal question you would like to do." << endl;
          cout << "Here's a couple of examples:" << endl;
          cout << "Typing in 11 would make it show you a basic multiply question." << endl;
          cout << "Typing in 21 would make it show you a decimal multiply question." << endl;

          break;
        }
        case 4:
        {
          running = "false";

          break;
        }
      }
    }
  }
  else
  {
    CLoption1 = argv[1];
    CLoption2 = argv[2];
    CLoption3 = argv[3];

    if(CLoption1 == "-h")
    {
      cout << "Usage: RMQG [Option] [Question type 1] [Question type 2] [Question count] filename" << endl;
      cout << endl;
      cout << "Options:" << endl;
      cout << "-o   Outputs a list of a specific type of question to a file." << endl;
      cout << endl;
      cout << "Question type 1:" << endl;
      cout << "-b   Whole number questions." << endl;
      cout << "-d   Decimal number questions." << endl;
      cout << endl;
      cout << "Question type 2:" << endl;
      cout << "-m   Multiply questions." << endl;
      cout << "-a   Addition questions." << endl;
      cout << "-s   Subtraction questions." << endl;
      cout << "-d   Division question." << endl;
      cout << endl;
      cout << "Question count:" << endl;
      cout << "x   Number of questions to output." << endl;
      cout << endl;
      cout << "Examples:" << endl;
      cout << "RMQG -o 1 2 10 list //Outputs a list of 10 whole number addition questions." << endl;
    }
    else
    {
      if(CLoption2 == "-b")
      {
        qtype1 = 1;
      }
      else if(CLoption2 == "-d")
      {
        qtype1 = 2;
      }

      if(CLoption3 == "-m")
      {
        qtype2 = 1;
        qtypecl = "x";
      }
      else if(CLoption3 == "-a")
      {
        qtype2 = 2;
        qtypecl = "+";
      }
      else if(CLoption3 == "-s")
      {
        qtype2 = 3;
        qtypecl = "-";
      }
      else if(CLoption3 == "-d")
      {
        qtype2 = 4;
        qtypecl = "%";
      }

      File_name = argv[5];

      if(CLoption1 == "-o")
      {
        CLOpt1 = 1;
      }
      cout << qtype1 << qtype2 << endl;

      cout << argv[2] << endl;

      switch(CLOpt1)
      {
        case 1:
        {
          cout << "Working so far." << endl;

          ofstream Qlist_file(File_name, ios::out | ios::app);

          if(Qlist_file.is_open())
          {
            int val = stoi(argv[4]);

            for(int i = 0; i <= val; i++ )
            {
              cout << "1" << endl;
              if(qtype1 == 1)
              {
                cout << "2" << endl;
                GrandnumB();
              }
              else if(qtype1 == 2)
              {
                GrandnumD();
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
      }
    }
  }



  return 0;
}
