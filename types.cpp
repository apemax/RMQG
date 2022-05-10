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
#include <iomanip>
#include "types.h"
#include "global.h"

using namespace std;

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
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(BRangeMin, BRangeMax);
  qnum1 = dist(mt);
  qnum2 = dist(mt);
}

void GrandnumD()
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(DRangeMin, DRangeMax);
  qnum1 = dist(mt);
  qnum2 = dist(mt);
}

int GrandOpt()
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 3);
  return dist(mt);
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

    cout << "correct" << endl;

    count++;
  }
  else
  {
    wrong();

    cout << "wrong" << endl;
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

    cout << "correct" << endl;

    count++;
  }
  else
  {
    wrong();

    cout << "wrong" << endl;
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

    cout << "correct" << endl;

    count++;
  }
  else
  {
    wrong();

    cout << "wrong" << endl;
  }
}

void DivideB ()
{
  GrandnumB();

  cout << qnum1 << "/" << qnum2 << endl;
  cout << "answer: ";

  cin >> qnuma2;

  qnuma1 = (qnum1 / qnum2);

  cout << qnuma1 << endl;

  if (qnuma1 == qnuma2)
  {
    correct();

    cout << "correct" << endl;

    count++;
  }
  else
  {
    wrong();

    cout << "wrong" << endl;
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

    cout << "correct" << endl;

    count++;
  }
	else
	{
    wrong();

    cout << "wrong" << endl;
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

    cout << "correct"<< endl;

    count++;
  }
	else
	{
    wrong();

    cout << "wrong" << endl;
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

    cout << "correct" << endl;

    count++;
  }
	else
	{
    wrong();

    cout << "wrong" << endl;
  }
}

void DivideD()
{
  GrandnumD();

  cout << qnum1 << "/" << qnum2 << endl;
  cout << "Note: only enter 5 numbers after the decimal point." << endl;
	cout << "answer: ";

	cin >> qnuma2;

	qnuma1 = (qnum1 / qnum2);

	cout << qnuma1 << endl;

	if (qnuma1 == qnuma2)
	{
    correct();

    cout << "correct" << endl;

    count++;
  }
	else
	{
    wrong();

    cout << "wrong" << endl;
  }
}

void RandomB()
{
  int RandOpt = GrandOpt();

  switch (RandOpt)
  {
    case 0:
    {
      MultiplyB();

      break;
    }
    case 1:
    {
      AddB();

      break;
    }
    case 2:
    {
      SubtractB();

      break;
    }
    case 3:
    {
      DivideB();

      break;
    }
  }
}

void RandomD()
{
  int RandOpt = GrandOpt();

  switch (RandOpt)
  {
    case 0:
    {
      MultiplyD();

      break;
    }
    case 1:
    {
      AddD();

      break;
    }
    case 2:
    {
      SubtractD();

      break;
    }
    case 3:
    {
      DivideD();

      break;
    }
  }
}

void ChallengeB()
{
  int SROpt;
  cout << fixed;
  cout << setprecision(0);

  auto StartTimer1 = chrono::steady_clock::now();

  for (size_t i = 0; i < 20; i++)
  {
    RandomB();
  }

  auto EndTimer1 = chrono::steady_clock::now();

  chrono::duration<double> ChallengeTime = EndTimer1 - StartTimer1;

  cout << fixed;
  cout << setprecision(2);

  cout << "Your time was: " << ChallengeTime.count() << "seconds" << endl;

  cout << "Do you want to save your result to the leaderboard? 1) Yes. 2) No." << endl;
  cin >> SROpt;

  if (SROpt == 1)
  {
    BChallengeLeaderboard[BLeaderboard][BSubLeaderboard][BLeaderboardPosition] = ChallengeTime.count();

    BLeaderboardPosition++;

    SortLeaderboard();
  }
}

void ChallengeD()
{
  int SROpt;
  cout << fixed;
  cout << setprecision(5);

  auto StartTimer1 = chrono::steady_clock::now();

  for (size_t i = 0; i < 20; i++)
  {
    RandomD();
  }

  auto EndTimer1 = chrono::steady_clock::now();

  chrono::duration<double> ChallengeTime = EndTimer1 - StartTimer1;

  cout << fixed;
  cout << setprecision(2);

  cout << "Your time was: " << ChallengeTime.count() << "Seconds." << endl;

  cout << "Do you want to save your result to the leaderboard? 1) Yes. 2) No." << endl;
  cin >> SROpt;

  if (SROpt == 1)
  {
    DChallengeLeaderboard[DLeaderboard][DSubLeaderboard][DLeaderboardPosition] = ChallengeTime.count();

    DLeaderboardPosition++;

    SortLeaderboard();
  }
}

// This next function is for fractions but as of now i don't know how to do it yet.
// So it will sit here until i figure out how to do fractions in C++. :)
/*
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
*/
