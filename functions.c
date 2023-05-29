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

void deleteLeadingSpaces(char *s) {
    int i, j;
    for (i = 0; s[i] == ' ' || s[i] == '\t'; i++);

    for (j = 0; s[i]; i++) {
        s[j++] = s[i];
    }
    s[j] = '\0';
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t')
            j = i;
    }
    s[j + 1] = '\0';
}

void print(Team *teams) {
    Team *current = teams;
    while (current != NULL) {
        printf("%s\n%.2f\n", current->name, current->punctaj);
        current = current->next;
    }
}

int size(Stack *stack) {
    int count = 0;
    Team *current = stack->top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void printMatchDetails(FILE *out, Team *team1, Team *team2) {
    char aux1[100], aux2[100];

    // Copy team names and format them
    strcpy(aux1, team1->name);
    strcpy(aux2, team2->name);
    aux1[strlen(aux1) - 1] = '\0';
    aux2[strlen(aux2) - 1] = '\0';
    deleteLeadingSpaces(aux1);
    deleteLeadingSpaces(aux2);

    // Calculate spaces for alignment
    int numSpaces1 = 33 - strlen(aux1);
    int numSpaces2 = 33 - strlen(aux2);

    // Print match details
    fprintf(out, "%s%*s", aux1, numSpaces1, "");
    fprintf(out, "-");
    for (int k = 0; k < numSpaces2; k++) {
        fprintf(out, " ");
    }
    fprintf(out, "%s\n", aux2);
}

// Function to simulate the match and update stacks
void simulateMatch(Stack *winnersStack, Stack *losersStack, Team *team1, Team *team2) {
    if (team1->punctaj > team2->punctaj) {
        team1->punctaj += 1;
        push(winnersStack, team1);
        push(losersStack, team2);
    } else {
        team2->punctaj += 1;
        push(winnersStack, team2);
        push(losersStack, team1);
    }
}

// Function to print winner details
void printWinnerDetails(FILE *out, Team *team) {
    char aux3[100];
    strcpy(aux3, team->name);
    int numSpaces3 = 35 - strlen(aux3);
    aux3[strlen(aux3) - 1] = '\0';
    fprintf(out, "%s%*s", aux3, numSpaces3, "");
    fprintf(out, "-  %.2f\n", team->punctaj);
}

//Functia principala de creare meci si stive;
void createMatchesAndStacks(Team **teams, FILE *out, int numteams2) {
    Team *lastEightTeams = NULL;
    Queue *matchQueue = createQueue();
    Stack *winnersStack = createStack();
    Stack *losersStack = createStack();
    // Create match queue
    Team *currentTeam = *teams;
    while (currentTeam != NULL) {
        enQueue(matchQueue, currentTeam);
        currentTeam = currentTeam->next;
    }
    int roundNo = 1;
    while (!isEmpty(matchQueue)) {
        numteams2 /= 2;
        fprintf(out, "\n--- ROUND NO:%d\n", roundNo);

        while (!isEmpty(matchQueue)) {
            Team *currentMatch1 = deQueue(matchQueue);
            Team *currentMatch2 = deQueue(matchQueue);
            //
            printMatchDetails(out, currentMatch1, currentMatch2);
            // Simulate the match and update stacks
            simulateMatch(winnersStack, losersStack, currentMatch1, currentMatch2);
        }

        int aux = 0;
        fprintf(out, "\nWINNERS OF ROUND NO:%d\n", roundNo);
        while (!isStackEmpty(winnersStack)) {
            aux++;
            Team *team = pop(winnersStack);
            if (numteams2 == 8) {
                addAtBeginning(&lastEightTeams, team);
            }
            enQueue(matchQueue, team);
            // Print winner details
            printWinnerDetails(out, team);
//            free(team); aici ii dadea free si imi lua adresa noului castigator adica al winnerului numarul1, 2 zile mi-a mancat linia asta
        }
        while (!isStackEmpty(losersStack)) {
            Team *team = pop(losersStack);
            free(team);
        }
        if (aux == 1)
            break;
        roundNo++;
    }
    free(matchQueue);
    free(winnersStack);
    free(losersStack);
}

Node *newNode(Team *team) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->team = team;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *node, Team *team) {
    // daca ( sub) arborele este gol , creaza nod
    if (node == NULL) return newNode(team);
    // Compararea punctajelor
    if (team->punctaj > node->team->punctaj) {
        node->left = insert(node->left, team);
    } else if (team->punctaj < node->team->punctaj) {
        node->right = insert(node->right, team);
    } else {
        // Daca punctajele sunt egale, se compara numele in ordine descrescatoare
        if (strcmp(team->name, node->team->name) > 0) {
            node->left = insert(node->left, team);
        } else {
            node->right = insert(node->right, team);
        }
    }

    return node;
}
// Functie pentru eliberarea memoriei ocupate de arborele BST
void freeBST(Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root->team);
        free(root);
    }
}
// Funcție pentru afișarea conținutului arborelui în ordine descrescătoare
void printTree(Node *node) {
    if (node == NULL) return;
    printTree(node->left);
    printf("%s - %.2f\n", node->team->name, node->team->punctaj);
    printTree(node->right);
}

// Funcție pentru eliberarea memoriei ocupate de arbore
void freeTree(Node *node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}