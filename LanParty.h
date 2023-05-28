//
// Created by alexa on 5/17/2023.
//

#ifndef TEMAPA_LANPARTY_H
#define TEMAPA_LANPARTY_H

#endif //TEMAPA_LANPARTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Player {
    char *firstName;
    char *secondName;
    int points;
    struct Player *next;
} Player;
//typedef struct player Player;

typedef struct Team {
    char *name;
    int nr_players;
    float punctaj;
    Player *players;
    struct Team *next;

} Team;
//typedef struct team Team;
typedef struct Match {
    Team *team1;
    struct Match *next;
} Match;

typedef struct Queue {
    Team *front, *rear;
} Queue;

// Definirea structurii pentru stivă
typedef struct stack {
    Team *top;
} Stack;

int isEmpty(Queue *q);

Team *deQueue(Queue *q);

Queue *createQueue();

int isStackEmpty(Stack *stack);

Stack *createStack();

void addAtBeginning(Team **teams, Team *team);

void print_to_file(Team *head, FILE *out);

void sort_for_delete(float v[100], int n);

void delete(Team **head, float points);

void deleteLeadingSpaces(char *s);

void createMatchesAndStacks(Team**, FILE*);