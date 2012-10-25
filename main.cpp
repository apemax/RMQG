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
// Copyright (C) 2011 - 2012 Peter Wright
// author: peter wright
// version: 0.5.3
// Random Maths Question Generator (RMQG)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "types.h"
using namespace std;

int main( )
{
    int qtype1;
    char ans1;

    cout << "Random Maths Question Generator (RMQG) Copyright (C) 2011 Peter Wright" << endl;
    cout << "This program comes with ABSOLUTELY NO WARRANTY; for details see the file named COPYING in the program folder." << endl;
    cout << "This is free software, and you are welcome to redistribute it" << endl;
    cout << "under certain conditions; for details see the file named COPYING in the program folder." << endl;
    cout << " " << endl;

    cout << "welcome to the random maths question generator.\n";
    do
    {
        cout << "1 = basic, 2 = decimal. x = 1,+ = 2,- = 3,% = 4.\n";
        cout << "what type of question would you like to do?: ";
        cin >> qtype1;

        switch (qtype1)
        {
            case 11:
                MultiplyB();

                break;

			case 12:
                AddB();

				break;

			case 13:
                SubtractB();

				break;

            case 14:
                DivideB();

                break;

            case 21:
                MultiplyD();

                break;

            case 22:
                AddD();

                break;

            case 23:
                SubtractD();

                break;

            case 24:
                DivideD();

                break;

        }
        cout << "do you want another question?(y/n): ";
        cin >> ans1;
    }
    while (ans1 == 'y' || ans1 == 'Y');
	//cout << "do you what to know how many questions you got right?: ";
	//cin >> ans3;
	//if (ans3 == 'y' || ans3 == 'Y')
	    //cout << "your score is " << count << endl;
	//else
        cout << "thats all.\n";
    return 0;

}


