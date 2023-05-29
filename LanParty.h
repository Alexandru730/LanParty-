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

Team* readTeamFromFile(FILE* fp, Team **teams, float *arraytodelete, int index);

Player* readPlayersFromFile(FILE* fp, int num_players);

int isEmpty(Queue *q);

Team *deQueue(Queue *q);

void enQueue(Queue *q, Team *team1);

Queue *createQueue();

int isStackEmpty(Stack *stack);

Stack *createStack();

void createMatchesAndStacks(Team **teams, FILE *out, int nu, int cc);

void addPoint(Team *team);

Team *pop(Stack *stack);

void push(Stack *stack, Team *team);

void sort_for_delete(float v[100], int n);

void delete(Team **head, float points);

void addAtBeginning(Team **teams, Team *team);

void createAndPrintLastEightRanking(Team *lastEightTeams, FILE *out);

void deleteLeadingSpaces(char *);

Node *insert(Node *node, Team *team);

Player *createPlayer(char *name, char *surrname, int points);

void freeBST(Node *root);

void printTree(Node *node, FILE *out);

void print_to_file(Team *, FILE *);

void writeMatchesToFile(Team *team1, Team *team2, FILE *out);

