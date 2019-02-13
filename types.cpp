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

void correct()
{
    string correctout;
    char results_file[20] = "results.txt";

    correctout = "correct.";

    ofstream results_out(results_file, ios::out | ios::app);

    results_out << correctout << endl;

    results_out.close();
}

void wrong()
{
    string wrongout;
    char results_file[20] = "results.txt";

    wrongout = "wrong.";

    ofstream results_out(results_file, ios::out | ios::app);

    results_out << wrongout << endl;

    results_out.close();
}

void GrandnumB()
{
    time_t seconds;

    time(&seconds);

    srand((unsigned int) seconds);

    qnum1 = rand() % 30;
    qnum2 = rand() % 30;
}

void GrandnumD()
{
    time_t seconds;

    time(&seconds);

    srand((unsigned int) seconds);

    qnum1 = (RAND_MAX - rand( ))/static_cast<double>(RAND_MAX);
    qnum2 = (RAND_MAX - rand( ))/static_cast<double>(RAND_MAX);
}

void MultiplyB()
{
    GrandnumB();
    cout << qnum1 << "x" << qnum2 << endl;
    cout << "answer: ";
    cin >> qnuma2;
    qnuma1 = (qnum1 * qnum2);
    cout << qnuma1 << endl;
    if (qnuma1 == qnuma2)
    {
        correct();
        cout << "correct\n";
        count++;
    }
    else
    {
        wrong();
        cout << "wrong\n";
    }
}

void AddB ()
{
    GrandnumB();
    cout << qnum1 << "+" << qnum2 << endl;
    cout << "answer: ";
    cin >> qnuma2;
    qnuma1 = (qnum1 + qnum2);
    cout << qnuma1 << endl;
    if (qnuma1 == qnuma2)
    {
        correct();
        cout << "correct\n";
        count++;
    }
    else
    {
        wrong();
        cout << "wrong\n";
    }
}

void SubtractB ()
{
    GrandnumB();
    cout << qnum1 << "-" << qnum2 << endl;
    cout << "answer: ";
    cin >> qnuma2;
    qnuma1 = (qnum1 - qnum2);
    cout << qnuma1 << endl;
    if (qnuma1 == qnuma2)
    {
        correct();
        cout << "correct\n";
        count++;
    }
    else
    {
        wrong();
        cout << "wrong\n";
    }
}

void DivideB ()
{
    GrandnumB();
    cout << qnum1 << "%" << qnum2 << endl;
    cout << "answer: ";
    cin >> qnuma2;
    qnuma1 = (qnum1 / qnum2);
    cout << qnuma1 << endl;
    if (qnuma1 == qnuma2)
    {
        correct();
        cout << "correct\n";
        count++;
    }
    else
    {
        wrong();
        cout << "wrong\n";
    }
}

void MultiplyD()
{
    GrandnumD();
    cout << qnum1 << "x" << qnum2 << endl;
    cout << "Note: only enter 5 numbers after the decimal point." << endl;
	cout << "answer: ";
	cin >> qnuma2;
	qnuma1 = (qnum1 * qnum2);
	cout << qnuma1 << endl;
	if (qnuma1 == qnuma2)
	{
        correct();
        cout << "correct\n";
        count++;
    }
	else
	{
        wrong();
        cout << "wrong\n";
    }
}

void AddD()
{
    GrandnumD();
    cout << qnum1 << "+" << qnum2 << endl;
    cout << "Note: only enter 5 numbers after the decimal point." << endl;
	cout << "answer: ";
	cin >> qnuma2;
	qnuma1 = (qnum1 + qnum2);
	cout << qnuma1 << endl;
	if (qnuma1 == qnuma2)
	{
        correct();
        cout << "correct\n";
        count++;
    }
	else
	{
        wrong();
        cout << "wrong\n";
    }
}

void SubtractD()
{
    GrandnumD();
    cout << qnum1 << "-" << qnum2 << endl;
    cout << "Note: only enter 5 numbers after the decimal point." << endl;
	cout << "answer: ";
	cin >> qnuma2;
	qnuma1 = (qnum1 - qnum2);
	cout << qnuma1 << endl;
	if (qnuma1 == qnuma2)
	{
        correct();
        cout << "correct\n";
        count++;
    }
	else
	{
        wrong();
        cout << "wrong\n";
    }
}

void DivideD()
{
    GrandnumD();
    cout << qnum1 << "%" << qnum2 << endl;
    cout << "Note: only enter 5 numbers after the decimal point." << endl;
	cout << "answer: ";
	cin >> qnuma2;
	qnuma1 = (qnum1 / qnum2);
	cout << qnuma1 << endl;
	if (qnuma1 == qnuma2)
	{
        correct();
        cout << "correct\n";
        count++;
    }
	else
	{
        wrong();
        cout << "wrong\n";
    }
}

// This next function is for fractions but as of now i don't know how to do it yet.
// So it will sit here until i figure out how to do fractions in C++. :)

void qtypef()
{
	double qnum1,
		qnum2,
		qnum3,
		qnum4,
		//qnuma1,
		qnuma2;

	qnum1 = rand( ) % 30;
    qnum2 = rand( ) % 30;
    qnum3 = rand( ) % 30;
    qnum4 = rand( ) % 30;
    cout << qnum1 << "/" << qnum2 << " " << "x" << " " << qnum3 << "/" << qnum4 << endl;
	cout << "answer: ";
	cin >> qnuma2;

}
