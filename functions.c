//
// Created by alexa on 5/17/2023.
//

#include "LanParty.h"

void addAtBeginning(Team **teams, Team *team) {
    if (*teams == NULL) {
        *teams = team;
        team->next = NULL;  // Initialize the next pointer to NULL
    } else {
        team->next = *teams;
        *teams = team;

    }
}

void print_to_file(Team *head, FILE *out) {
    while (head != NULL) {
        fprintf(out, "%s\n", head->name);
        head = head->next;
    }
}

void sort_for_delete(float v[100], int n) {
    float aux;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1 - j; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
    }
}

void delete(Team **head, float points) {
// 0. Lista goala
    if (*head == NULL) return;
// 1. Elementul de sters este capul listei

    if ((*head)->punctaj == points) {
        Team *headcopy = *head;
        *head = (*head)->next;
        free(headcopy); // sterge primul element
        return;
    }
// 2. Elementul de sters are o pozitie oarecare
    Team *prev = *head; // predecesorul elementului cautat
    Team *headcopy = (*head)->next;
    while (headcopy != NULL) {
        if (headcopy->punctaj == points) {
            prev->next = headcopy->next;
            Team *temp = headcopy;
            headcopy = headcopy->next;
            free(temp);//sterge elementul
            break;// Exit the loop after deleting the desired node
        } else {
            prev = headcopy;
            headcopy = headcopy->next;
        }
    }
}

//crearea si initializarea cozii
Queue *createQueue() {
    Queue *q;
    q = (Queue *) malloc(sizeof(Queue));
    if (q == NULL) return NULL;
    q->front = q->rear = NULL;
    return q;
}

//verificam daca coada este goala
int isEmpty(Queue *q) {
    return (q->front == NULL);
}

//Adaugam un meci in coada
void enQueue(Queue *q, Team *team) {
    Team *newMatch = (Team *) malloc(sizeof(Team));
    *newMatch = *team;
    newMatch->next = NULL;
// nodurile noi se adauga la finalul cozii
    if (q->rear == NULL) {
        q->rear = newMatch;
        q->front = newMatch;
    }
// daca nu exista niciun nod in coada
    else {
        (q->rear)->next = newMatch;
        (q->rear) = newMatch;
    }
// daca exita un singur element in coada
    if (q->front == NULL) q->front = q->rear;
}

// Funție pentru extragerea unui element din coadă și returnarea sa
// Returnează un pointer la elementul extras (de tip MATCH)
Team *deQueue(Queue *q) {
    Team *aux;
    if (isEmpty(q)) return NULL;
    aux = q->front;
    q->front = (q->front)->next;
    return aux;
}

// Crearea si initializarea stivei
Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Verificarea daca stiva este goala
int isStackEmpty(Stack *stack) {
    return (stack->top == NULL);
}

// Adaugarea unui element in varful stivei|push
void push(Stack *stack, Team *team) {
    Team *newMatch = (Team *) malloc(sizeof(Team));
    *newMatch = *team;
    newMatch->next = (struct Team *) stack->top;
    stack->top = (struct Team *) newMatch;
}

//Extrage un element din varful stivei

Team *pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        return NULL;
    }

    Team *removedMatch = stack->top;
    Team *removedTeam = (Team *) malloc(sizeof(Team));
    *removedTeam = *removedMatch;
    stack->top = stack->top->next;
    free(removedMatch);

    return removedTeam;
}

//adaugam punct echipei castigatoare
void addPoint(Team *team) {
    team->punctaj = team->punctaj + 1;
}