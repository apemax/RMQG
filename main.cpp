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
  string File_name;
  string running = "true";

  time_t seconds;

  time(&seconds);

  srand((unsigned int) seconds);

  cout << "Random Maths Question Generator (RMQG) Copyright (C) 2011 - 2019 Peter Wright" << endl;
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
      cout << "1) Casual mode. 2) Challenge mode. 3) Help. 4) Exit." << endl;
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
          //Help.
          cout << endl;
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

    if(CLoption1 == "-h")
    {
      cout << "Usage: RMQG [Options] [Question type 1] [Question type 2] [Question count] filename" << endl;
      cout << endl;
      cout << "Options:" << endl;
      cout << "-o   Outputs a list of a specific type of question to a file." << endl;
      cout << "-c   Reads in and checks a list of questions that you have answered." << endl;
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
      cout << "-r   A random type of question." << endl;
      cout << endl;
      cout << "Question count:" << endl;
      cout << "x   Number of questions to output." << endl;
      cout << endl;
      cout << "Examples:" << endl;
      cout << "RMQG -o -b -a 10 list //Outputs a list of 10 whole number addition questions." << endl;
      cout << "RMQG -c list //Reads in and checks questions answered in the file \"list\"." << endl;
    }
    else if(CLoption1 == "-o")
    {
      CLoption2 = argv[2];
      CLoption3 = argv[3];

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
      else if (CLoption3 == "-r")
      {
        qtype2 = 5;
      }

      File_name = argv[5];

      ofstream Qlist_file(File_name, ios::out | ios::app);

      if(Qlist_file.is_open())
      {
        int LineCount = stoi(argv[4]);

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
            int RandOptCL = rand() % 3;

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
                qtypecl = "%";

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
    else if(CLoption1 == "-c")
    {
      File_name = argv[2];

      ifstream Qlist_file(File_name, ios::in);

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
              if(LoadLine.substr(PosNum3, 1) == "+" || LoadLine.substr(PosNum3, 1) == "-" || LoadLine.substr(PosNum3, 1) == "x" || LoadLine.substr(PosNum3, 1) == "%")
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

              cout << qnum1 << " | " << qnum2 << endl;

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
              else if(QType == "%")
              {
                qnuma1 = (qnum1 / qnum2);
              }

              if(qnuma1 == qnuma2)
              {
                cout << "Correct: " << qnuma1 << endl;

                PosNum = LoadLine.size();
              }
              else
              {
                cout << "Wrong: " << qnuma1 << endl;

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
  }

  return 0;
}
