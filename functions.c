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
