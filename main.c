#include "LanParty.h"

int main(int argc, char **argv) {
    Team *teams = NULL;
    Team *lastEightTeams = NULL;
    Queue *q;
    q = createQueue();
    if (q == NULL) {
        printf("Failed to create queue.\n");
        exit(1);
    }
    FILE *fp, *out, *in;
    fp = fopen(argv[2], "r");
    in = fopen(argv[1], "r");
    out = fopen(argv[3], "w");
    if (fp == NULL || in == NULL || out == NULL) {
        printf("ERROR IN OPENING\n");
        exit(1);
    }


    int cerinta1, cerinta2, cerinta3, cerinta4, cerinta5;
    fscanf(in, "%d %d %d %d %d", &cerinta1, &cerinta2, &cerinta3, &cerinta4, &cerinta5);
    int num_teams = 0;
    fscanf(fp, "%d", &num_teams);
//    printf("%d\n", num_teams);
    float *arraytodelete = calloc(num_teams, sizeof(float));
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
        deleteLeadingSpaces(team->name);
        arraytodelete[i] = team->punctaj;
        addAtBeginning(&teams, team);
    }
    printf("\n");
    for (int k = 0; k < num_teams; k++) {
        sort_for_delete(arraytodelete, num_teams);
//        printf("%d = %.2f \n", k, arraytodelete[k]);
    }
    int numteams2;
    // Sorting and deleting logic
   int numar_stergeri = 2;

    while (1) {
        numar_stergeri *= 2;
        if (num_teams < numar_stergeri)
            break;
    }
    numteams2 = numar_stergeri/2;
    numar_stergeri = num_teams - numar_stergeri / 2;

    Node *root = NULL;
    if (cerinta1 == 1 && cerinta2 == 0 && cerinta3 == 0) {
        print_to_file(teams, out);
    }

    if (cerinta2 == 1 && cerinta3 == 0) {
        for (int i = 0; i < numar_stergeri; i++) {
            delete(&teams, arraytodelete[i]);
        }
        print_to_file(teams, out);
    }

    if (cerinta2 == 1 && cerinta3 == 1) {
        for (int i = 0; i < numar_stergeri; i++) {
            delete(&teams, arraytodelete[i]);
        }
        print_to_file(teams, out);
        createMatchesAndStacks(&teams, out, numteams2);
    }
//    print(lastEightTeams);
    fclose(fp);
    fclose(in);
    fclose(out);

    return 0;
}
