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
