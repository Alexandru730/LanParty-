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

typedef struct Node {
    Team *team;
    struct Node *left, *right;
} Node;

void printTop8Winners(Team *top8Winners);

void printList(Team *head);

int isEmpty(Queue *q);

Team *deQueue(Queue *q);

Queue *createQueue();

int isStackEmpty(Stack *stack);

Stack *createStack();

void createMatchesAndStacks(Team **teams, FILE *out, int);

void addAtBeginning2(Team **head, Team *team);

void addPoint(Team *team);

Team *pop(Stack *stack);

void push(Stack *stack, Team *team);

void enQueue(Queue *q, Team *team1);

void sort_for_delete(float v[100], int n);

void delete(Team **head, float points);

Team *copyTeam(Team *team);

void addAtBeginning(Team **teams, Team *team);

void deleteLeadingSpaces(char *);

Player *createPlayer(char *name, char *surrname, int points);

void printList(Team *head);

void print(Team *head);

void print_to_file(Team *, FILE *);

void writeMatchesToFile(Team *team1, Team *team2, FILE *out);

void printRec(Team *head);