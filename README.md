# Random Maths Question Generator or RMQG

The Random Maths Question Generator or RMQG for short is as you would have guessed it a program that generates random maths questions.

## Usage

### Casual mode

When it asks you what type of question you would like to do type in either 1 for whole number questions followed by what type of whole number question you want to do or 2 for decimal number questions followed by what type of decimal number question you would like to do. Here's a couple of examples:

Typing in 11 would make it show you a whole number multiply question.

Typing in 21 would make it show you a decimal number multiply question.

### Challenge mode

Challenge mode asks you 20 random questions in three different ranges for both whole and decimal numbers and records the time it takes to answer all of them and how many questions you got right. First you select the type of question, Then the range for the numbers, Then you have to answer the 20 questions as quick as possible.

Once you have answered all the questions you will then be asked whether you want the results saved to the leaderboard. You can then view your previous saved results in the leaderboard.

### Command line mode

Allows you to output a list of questions to a file direct from the command line.

#### Usage:

RMQG [Options] [Question type 1] [Question type 2] [Question count] filename

Options:\
-o   Outputs a list of a specific type of question to a file.\
-c   Reads in and checks a list of questions that you have answered.

Question type 1:\
-b   Whole number questions.\
-d   Decimal number questions.

Question type 2:\
-m   Multiply questions.\
-a   Addition questions.\
-s   Subtraction questions.\
-d   Division question.\
-r   A random type of question.

Question count:\
x   Number of questions to output.

Examples:\
RMQG -o -b -a 10 list //Outputs a list of 10 whole number addition questions.\
RMQG -c list //Reads in and checks questions answered in the file "list".

## Building

### Linux

To compile, clone the RMQG repo:

~~~
git clone https://github.com/apemax/RMQG.git
~~~

Then cd to the RMQG directory and run make:

~~~
cd RMQG
make
~~~
