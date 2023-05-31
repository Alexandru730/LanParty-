# LanParty-


This is a program for managing a LAN party tournament. It reads team and player data from a file, simulates matches between teams, and generates rankings based on the results.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [File Format](#file-format)
- [License](#license)

## Introduction

The LanParty program is designed to facilitate the organization and management of LAN party tournaments. It allows you to read team and player data from a file, simulate matches between teams, and generate rankings based on the results. The program uses various data structures such as linked lists, queues, stacks, and binary search trees to efficiently manage the tournament data.

## Features

- Read team and player data from a file
- Simulate matches between teams
- Calculate team scores based on player performance
- Generate rankings based on team scores
- Output results to a file

## Usage

To use the LanParty program, follow these steps:

1. Compile the source code using a C compiler.
2. Run the executable file generated.
3. Provide the input file containing team and player data.
4. Specify the output file to store the results.
### Makefile

You can use the following Makefile to build and run the project:

```make
# Variables
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = myprogram

# Rules
all: $(TARGET)

$(TARGET): main.c
    $(CC) $(CFLAGS) -o $@ $<

clean:
    rm -f $(TARGET)
    
 
## File Format

The input file should follow a specific format to ensure proper parsing of team and player data. Here's an example of the file format:

3<br>
Team A<br>
John Doe 100<br>
Jane Smith 150<br>
Mark Johnson 200<br>
2<br>
Team B<br>
Sarah Williams 120<br>
Robert Davis 180<br>
4<br>
Team C<br>
Michael Brown 90<br>
Emily Wilson 110<br>
David Taylor 130<br>
Lisa Anderson 170<br>


Each team entry starts with the number of players in the team, followed by the team name. After that, each player is listed with their first name, last name, and performance points.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
