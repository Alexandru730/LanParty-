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

