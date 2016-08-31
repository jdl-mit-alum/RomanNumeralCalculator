# Response to the Pillar coding challenge

Hi Pillar,

My name is Jonathan D. Lettvin and
I think I have what it takes to be on your team.
I have provided this response in the spirit of both
brevity (comments, but not to the Doxygen level) and
completeness (handle specified cases and exhaustive cases).

I truly enjoy SOLID, DRY, TDD and have been
a proponent of pair and multiple programming for decades.
I personally believe it amplifies quality and output
sometimes by a factor of 4 to 10 over
contributions of the same number of individual developers.
I have had the very highest value-add with remote pair programming
whether with tmux/skype or lync or join.me.
I have worked in continuous integration environments
and am a believer in the agile manifesto.

## Update from previous version
* Added "-std=gnu99" to Makefile compile for test.

## Environment
* New virtualbox ubuntu 14.04.4 installed
* sudo apt-get install git
* browse to https://github.com/libcheck/check/releases
* download download/0.10.0/check-0.10.0.tar.gz
* tar xvzf check-0.10.0.tar.gz
* cd check-0.10.0; ./configure; make; sudo make install

## Compile and run
* git clone https://github.com/jdl-mit-alum/RomanNumeralCalculator
* cd RomanNumeralCalculator
* make

## Expect output
Note that I inluded the date time stamp as first output.
```bash
$ make
20160831095002
Running suite(s): Test_Roman_Numeral_Calculator_Primitives
100%: Checks: 11, Failures: 0, Errors: 0
$ make clean
```

# Roman Numeral Calculator

For this programming exercise, you will be creating a library which will allow the addition and subtraction of
Roman numerals.  Once your solution is complete, please provide your solution as a Git repository (publicly
available via Github or Bitbucket).  Please include within your repository, all source and test code.

## The solution will be reviewed for:
* Test coverage
* Test Driven Development
* Algorithm Usage
* Code structure
* Use of source control 
* Completeness of the overall solution

## The environment for this programming exercise *must* utilize:
* Ubuntu Linux 14.04
* The C programming language
* GNU GCC compiler tool chain
* GNU Make
* Check unit testing framework ( https://libcheck.github.io/check/ )
* git

## Roman Numeral rules:
* Roman numerals consist of the following letters: I, V, X, L, C, D, and M which mean one, five, ten, fifty, hundred, five hundred and one thousand respectively.
* An example would be "XIV" + "LX" = "LXXIV"
* Numerals can be concatenated to form a larger numeral ("XX" + "II" = "XXII").
* If a lesser numeral is put before a bigger it means subtraction of the lesser from the bigger ("IV" means four, "CM" means ninehundred).
* If the numeral is I, X or C you can't have more than three ("II" + "II" = "IV" not “IIII”).
* If the numeral is V, L or D you can't have more than one ("D" + "D" = "M" not “DD”)
* The maximum roman numeral is 3999 (MMMCMXCIX)

## Stories

### User Story: Addition
As a Roman bookkeeper, I want to be able to add two numbers together.  So that I can do my work faster
with fewer mathematical errors.

### User Story: Subtraction
As a Roman bookkeeper, I want to be able to subtract one number from another.  So that I can do my work
faster and with fewer mathematical errors.
