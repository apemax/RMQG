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

using namespace std;

int main(int argc, char *argv[])
{
  int Opt1;
  string File_name;
  string running = "true";

  cout << "Random Maths Question Generator (RMQG) Copyright (C) 2011 - 2022 Peter Wright" << endl;
  cout << "This program comes with ABSOLUTELY NO WARRANTY; for details see the file named COPYING in the program folder." << endl;
  cout << "This is free software, and you are welcome to redistribute it" << endl;
  cout << "under certain conditions; for details see the file named COPYING in the program folder." << endl;
  cout << endl;

  if(argc <= 1)
  {
    cout << "welcome to the Random Maths Question Generator." << endl;
    cout << endl;

    while (running == "true")
    {
      cout << "1) Casual mode. 2) Challenge mode. 3) Generate question list. 4) Help. 5) Exit." << endl;
      cout << "> ";
      cin >> Opt1;

      switch (Opt1)
      {
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
          cout << "1) Whole number questions. 2) Decimal number questions." << endl;
          cout << "> ";

          cin >> CLoption2;

          if (CLoption2 == "1")
          {
            cout << "Please enter a minimum and maximum range of numbers to use." << endl;
            cout << "Default is Min = 1, Max = 10." << endl;
            cout << "Minimum: ";
            cin >> CLoption3;
            cout << "Maximum: ";
            cin >> CLoption4;
          }
          else if (CLoption2 == "2")
          {
            cout << "Please enter a minimum and maximum range of numbers to use." << endl;
            cout << "Default is Min = 0.1, Max = 10." << endl;
            cout << "Minimum: ";
            cin >> CLoption3;
            cout << "Maximum: ";
            cin >> CLoption4;
          }

          cout << "1) Multiply questions. 2) Addition questions. 3) Subtraction questions. 4) Division question. 5) A random type of question." << endl;
          cout << "> ";

          cin >> CLoption5;

          cout << "Number of questions to output:" << endl;
          cout << "> ";

          cin >> CLoption6;

          cout << "File name for the list file:" << endl;
          cout << "> ";

          cin >> File_name;

          Listgen(CLoption2, CLoption3, CLoption4, CLoption5, CLoption6, File_name);

          break;
        }
        case 4:
        {
          //Help.
          cout << endl;
          cout << "Casual mode." << endl;
          cout << "When it asks you what type of question you would like to do type in either 1 for" << endl;
          cout << "whole number questions followed by what type of basic question you want to do or 2 for" << endl;
          cout << "decimal questions followed by what type of decimal question you would like to do." << endl;
          cout << "Here's a couple of examples:" << endl;
          cout << "Typing in 11 would make it show you a basic multiply question." << endl;
          cout << "Typing in 21 would make it show you a decimal multiply question." << endl;

          break;
        }
        case 5:
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

    if(CLoption1 == "-h")
    {
      cout << "Usage: RMQG [Options] [Question type 1] [Question type 2] [Question count] filename" << endl;
      cout << endl;
      cout << "Options:" << endl;
      cout << "-o   Outputs a list of a specific type of question to a file." << endl;
      cout << "-c   Reads in and checks a list of questions that you have answered." << endl;
      cout << endl;
      cout << "Question type 1:" << endl;
      cout << "-b   Whole number questions followed by Min and Max number range, Example: 1 10" << endl;
      cout << "-d   Decimal number questions followed by Min and Max number range. Example: 0.1 1.0" << endl;
      cout << endl;
      cout << "Question type 2:" << endl;
      cout << "-m   Multiply questions." << endl;
      cout << "-a   Addition questions." << endl;
      cout << "-s   Subtraction questions." << endl;
      cout << "-d   Division question." << endl;
      cout << "-r   A random type of question." << endl;
      cout << endl;
      cout << "Question count:" << endl;
      cout << "x   Number of questions to output." << endl;
      cout << endl;
      cout << "Examples:" << endl;
      cout << "RMQG -o -b 1 10 -a 10 list //Outputs a list of 10 whole number addition questions within th erange of 1 to 10." << endl;
      cout << "RMQG -c list //Reads in and checks questions answered in the file \"list\"." << endl;
    }
    else if(CLoption1 == "-o")
    {
      Listgen(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    }

    else if(CLoption1 == "-c")
    {
      Listcheck(argv[2]);
    }
  }

  return 0;
}
