#include "LanParty.h"

int main(int argc, char **argv) {
    Team *teams = NULL;
    FILE *fp;
    fp = fopen(argv[2], "r");

    if (fp == NULL) {
        printf("ERROR IN OPENING\n");
        exit(1);
    }
    int num_teams = 0;
    fscanf(fp, "%d", &num_teams);
//    printf("%d\n", num_teams);
    for (int i = 0; i < num_teams; i++) {
        Team *team = (Team *) malloc(sizeof(Team));
        if (team == NULL) {
            printf("Memory allocation failed!");
            exit(1);
        }
        fscanf(fp, "%d", &team->nr_players);

        char teamName[100];
        fscanf(fp, " %[^\n]s", teamName);
        int l = strlen(teamName);
        team->name = (char *) malloc((l+1)*sizeof(char));
        strcpy(team->name, teamName);

        team->players = (Player *) malloc(sizeof(Player) * team->nr_players);
//        printf("Number of players: %d, Team Name: %s\n", team->nr_players, team->name);

        if (team->players == NULL) {
            printf("Dynamic allocation failed!");
            exit(1);
        }

        for (int j = 0; j < team->nr_players; j++) {
            char name[100], surname[100];
            fscanf(fp, "%s %s %d", name, surname, &team->players[j].points);
            int l = strlen(name);
            team->players[j].firstName = (char *) malloc((l+1)*sizeof(char));
            if (team->players[j].firstName == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            strcpy(team->players[j].firstName, name);

            l = strlen(surname);
            team->players[j].secondName = (char *) malloc((l+1)*sizeof(char));
            if (team->players[j].secondName == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            strcpy(team->players[j].secondName, surname);

            team->punctaj += (float) team->players[j].points;
//            printf("Nume jucator %d : %s %s\n", j, team->players[j].firstName, team->players[j].secondName);
        }

        team->punctaj /= (float) team->nr_players;
//        printf("Number of points per team %d: %.2f \n", i, team->punctaj);
    }
    printf("\n");


    fclose(fp);

    return 0;
}