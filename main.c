#include "LanParty.h"

int main(int argc, char **argv) {
    Team *teams = NULL;
    Queue *q;
    q = createQueue();
    if (q == NULL) {
        printf("creare esuata.\n");
        exit(1);}
    FILE *fp, *out, *in;
    fp = fopen(argv[2], "r");    in = fopen(argv[1], "r");    out = fopen(argv[3], "w");
    if (fp == NULL || in == NULL || out == NULL) {
        printf("eroare la deschidere\n");
        exit(1);
    }
    int cerinta1, cerinta2, cerinta3, cerinta4, cerinta5; // cerintele din fisierul de intrare
    fscanf(in, "%d %d %d %d %d", &cerinta1, &cerinta2, &cerinta3, &cerinta4, &cerinta5); // citire cerinte
    int num_teams = 0;
    fscanf(fp, "%d", &num_teams);
    float *arraytodelete = calloc(num_teams, sizeof(float)); // vector pentru a stoca punctajele echipelor
    for (int i = 0; i < num_teams; i++) {
        Team* team = readTeamFromFile(fp, &teams, arraytodelete, i);
        addAtBeginning(&teams, team);
    }
    for (int k = 0; k < num_teams; k++) {
        sort_for_delete(arraytodelete, num_teams);} // sortare vector
    int numteams2; // pentru aflare cand mai sunt 8 echipe in stiva
    // pentru sortarea echipelor cu punctaj mic
    int numar_stergeri = 2;
    while (1) {
        numar_stergeri *= 2;
        if (num_teams < numar_stergeri)
            break;}
    numteams2 = numar_stergeri / 2;
    numar_stergeri = num_teams - numar_stergeri / 2; // numarul de echipe care trebuie sterse
    // cerinta 1
    if (cerinta1 == 1 && cerinta2 == 0 && cerinta3 == 0) {
        print_to_file(teams, out);    }
    // cerinta 2
    if (cerinta2 == 1 && cerinta3 == 0) {
        for (int i = 0; i < numar_stergeri; i++) {
            delete(&teams, arraytodelete[i]); }
        print_to_file(teams, out);    }
    // cerinta 3
    if (cerinta2 == 1 && cerinta3 == 1 && cerinta4 != 1) {
        for (int i = 0; i < numar_stergeri; i++) {
            delete(&teams, arraytodelete[i]);
        }
        print_to_file(teams, out);
        createMatchesAndStacks(&teams, out, numteams2, cerinta4);
    }
    // cerinta 4
    if (cerinta3 == 1 && cerinta4 == 1) {
        for (int i = 0; i < numar_stergeri; i++) {
            delete(&teams, arraytodelete[i]);
        }
        print_to_file(teams, out);
        createMatchesAndStacks(&teams, out, numteams2, cerinta4);
    }
    // inchidere fisiere
    fclose(fp); fclose(in); fclose(out);
    freeTeams(teams); // eliberam memoria pentru toate echipele
    return 0;
}