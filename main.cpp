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
  string running = "true";

  cout << "Random Maths Question Generator (RMQG) Copyright (C) 2011 - 2019 Peter Wright" << endl;
  cout << "This program comes with ABSOLUTELY NO WARRANTY; for details see the file named COPYING in the program folder." << endl;
  cout << "This is free software, and you are welcome to redistribute it" << endl;
  cout << "under certain conditions; for details see the file named COPYING in the program folder." << endl;
  cout << " " << endl;

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

        cout << "Help." << endl;

        break;
      }
      case 4:
      {
        running = "false";

        break;
      }
    }
  }

  return 0;
}
