# Random Maths Question Generator or RMQG

The Random Maths Question Generator or RMQG for short is as you would have guessed it a program that generates rondom maths questions.

## Usage

### Casual mode

When it asks you what type of question you would like to do type in either 1 for basic questions followed by what type of basic question you want to do or 2 for decimal questions followed by what type of decimal question you would like to do. Here's a couple of examples:

Typing in 11 would make it show you a basic multiply question.

Typing in 21 would make it show you a decimal multiply question.

### Challenge mode

Coming soon.

### Command line mode

Allows you to output a list of questions to a file direct from the command line. Still Work In Progress.

#### Usage:

RMQG [Options] [Question type 1] [Question type 2] [Question count] filename

Options:
-o   Outputs a list of a specific type of question to a file.
-c   Reads in and checks a list of questions that you have answered.

Question type 1:
-b   Whole number questions.
-d   Decimal number questions.

Question type 2:
-m   Multiply questions.
-a   Addition questions.
-s   Subtraction questions.
-d   Division question.

Question count:
x   Number of questions to output.

Examples:
RMQG -o -b -a 10 list //Outputs a list of 10 whole number addition questions.
RMQG -c list //Reads in and checks questions answered in the file "list".

## Building

### Linux

To compile, clone the STE repo:

~~~
git clone https://github.com/apemax/RMQG.git
~~~

Then cd to the STE directory and run make:

~~~
cd RMQG
make
~~~
