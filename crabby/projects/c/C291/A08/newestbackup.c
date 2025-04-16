#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CREWMEMBERS 10

typedef enum { Terran, Martian, Venusian, Saturian } Race;
typedef enum { Crew, Com, Nav, Eng, Sec, Cap } Post;
typedef enum { Spcr, Ens, Lt, Comm } Rank;

typedef struct {
    int Charisma;
    int Intelligence;
    int Strength;
    int Psionics;
    int Agility;
} Abilities;

typedef struct {
    int Navigation;
    int Engineering;
    int Tactics;
    int Leadership;
    int Diplomacy;
} Skills;

typedef struct Crewmember {
    int sernum;
    Post post;
    Rank rank;
    Skills skills;
    Abilities abilities;
    Race race;
    char* name;
    struct Crewmember* captain;
} Crewmember;

int roll(int sides)
{
    return (rand() % sides) + 1;
}

int generateAbility()
{
    return roll(6) + roll(6) + roll(6);
}

void generateSkills(Crewmember* crew)
{
    int avgNavigation = (crew->abilities.Intelligence + crew->abilities.Psionics) / 2;
    int avgEngineering = (crew->abilities.Intelligence + crew->abilities.Agility) / 2;
    int avgTactics = (crew->abilities.Strength + crew->abilities.Agility) / 2;
    int avgLeadership = (crew->abilities.Charisma + crew->abilities.Intelligence) / 2;
    int avgDiplomacy = (crew->abilities.Charisma + crew->abilities.Psionics) / 2;

    crew->skills.Navigation = (avgNavigation >= 10) ? 2 : (avgNavigation >= 15) ? 1 : (avgNavigation >= 7) ? 0 : (avgNavigation >= 4) ? -1 : -2;
    crew->skills.Engineering = (avgEngineering >= 10) ? 2 : (avgEngineering >= 15) ? 1 : (avgEngineering >= 7) ? 0 : (avgEngineering >= 4) ? -1 : -2;
    crew->skills.Tactics = (avgTactics >= 10) ? 2 : (avgTactics >= 15) ? 1 : (avgTactics >= 7) ? 0 : (avgTactics >= 4) ? -1 : -2;
    crew->skills.Leadership = (avgLeadership >= 10) ? 2 : (avgLeadership >= 15) ? 1 : (avgLeadership >= 7) ? 0 : (avgLeadership >= 4) ? -1 : -2;
    crew->skills.Diplomacy = (avgDiplomacy >= 10) ? 2 : (avgDiplomacy >= 15) ? 1 : (avgDiplomacy >= 7) ? 0 : (avgDiplomacy >= 4) ? -1 : -2;
}

void adjustAbilitiesRace(Crewmember* crew)
{
    switch (crew->race) {
        case Martian:
            crew->abilities.Strength -= 2;
            crew->abilities.Psionics += 2;
            crew->abilities.Agility += 1;
            break;
        case Venusian:
            crew->abilities.Charisma += 1;
            crew->abilities.Intelligence -= 1;
            crew->abilities.Strength += 1;
            crew->abilities.Psionics += 1;
            crew->abilities.Agility -= 1;
            break;
        case Saturian:
            crew->abilities.Charisma -= 1;
            crew->abilities.Intelligence += 2;
            crew->abilities.Strength -= 1;
            crew->abilities.Psionics += 1;
            break;
        case Terran:
            break;
    }
}

Crewmember* generateCrewmember(int sernum, int crewnum)
{
    Crewmember* crew = (Crewmember*)malloc(sizeof(Crewmember));
    crew->sernum = sernum;
    crew->name = (char*)malloc(50 * sizeof(char));
    sprintf(crew->name, "Crewman%d", crewnum);

    // Race
    crew->race = rand() % 4;

    // Abilities
    crew->abilities.Charisma = generateAbility();
    crew->abilities.Intelligence = generateAbility();
    crew->abilities.Strength = generateAbility();
    crew->abilities.Psionics = generateAbility();
    crew->abilities.Agility = generateAbility();

    // Adjust
    adjustAbilitiesRace(crew);

    // Skills
    generateSkills(crew);

    int rank_roll = roll(6) + roll(6);
    if (rank_roll <= 7) {
        crew->rank = Spcr;
    } else if (rank_roll <= 10) {
        crew->rank = Ens;
    } else if (rank_roll == 11) {
        crew->rank = Lt;
    } else {
        crew->rank = Comm;
    }

    // Post
    crew->post = Crew;

    // Cap'n pointer
    crew->captain = NULL;

    return crew;
}

//void outputTable(struct Crew crew)
void outputTable(Crewmember** crew, int crewsize)
{
    int captainIndex = -1;
    for (int x = 0; x < CREWMEMBERS; x++) {
        if (crew[x]->captain != NULL) {
            captainIndex = x;
        }
    }
    if (captainIndex != -1) {
        printf("Captain : %s\n", crew[captainIndex]->name);
    } else {
        printf("Captain : %s\n", "NONE");
    }
    printf("\t\t\t%-16s %s\n", "Skills", "Abilities");
    printf("Ser#   Post Rank  | N  E  T  L  D  | C  I  S  P  A  | Race Name\n");
    for (int i = 0; i < 10; i++) {
        //printf("%-6d %-4s %-4s  | %-2d %-2d %-2d %-2d %-2d | %-2d %-2d %-2d %-2d %-2d | %-4s %s\n", 123456, "Crew", "Spcr", 0, -1, 2, -2, 1, 13, 3, 18, 5, 10, "T", "Kerlin");
        printf("%-6d ", crew[i]->sernum);
        switch (crew[i]->post) {
            case Crew: printf("%-4s ", "Crew"); break;
            case Com: printf("%-4s ", "Com"); break;
            case Nav: printf("%-4s ", "Nav"); break;
            case Eng: printf("%-4s ", "Eng"); break;
            case Sec: printf("%-4s ", "Sec"); break;
            case Cap: printf("%-4s ", "Cap"); break;
        }
        switch (crew[i]->rank) {
            case Spcr: printf("%-4s ", "Spcr"); break;
            case Ens: printf("%-4s ", "Ens"); break;
            case Lt: printf("%-4s ", "Lt"); break;
            case Comm: printf("%-4s ", "Comm"); break;
        }
        printf(" | %-2d %-2d %-2d %-2d %-2d | %-2d %-2d %-2d %-2d %-2d | ", //%-4s %s\n", 
               //crew[i]->sernum, crew[i]->post, crew[i]->rank, 
               crew[i]->skills.Navigation, crew[i]->skills.Engineering, crew[i]->skills.Tactics, crew[i]->skills.Leadership, crew[i]->skills.Diplomacy, 
               crew[i]->abilities.Charisma, crew[i]->abilities.Intelligence, crew[i]->abilities.Strength, crew[i]->abilities.Psionics, crew[i]->abilities.Agility);
               //crew[i]->race, crew[i]->name);
        switch (crew[i]->race) {
            case Terran: printf("%-4s", "T"); break;
            case Martian: printf("%-4s", "M"); break;
            case Venusian: printf("%-4s", "V"); break;
            case Saturian: printf("%-4s", "S"); break;
        }
        printf(" %s\n", crew[i]->name);
    }
}

int generateSernum()
{
    int lb = 100000;
    int ub = 999999;
    return (rand() % (ub - lb + 1) + lb );
}

void printMenu()
{
    printf("\nOptions\n");
    printf("D   - Redisplay the table of crewmembers.\n");
    printf("N # - Provide a name for the specified crewmember.\n");
    printf("C # - Make the specified crewmember the captain for the crew. (No other crewmember should have a higher rank than the captain.)\n");
    printf("B # - Assign the specified crewmember to a bridge position by specifying a menu of bridge crew positions. Use single letter to indicate the bridge post assigned (N C S E).\n");
    printf("S   - Save the crewmember list to a file crewmember_list.txt\n");
    printf("R # - Regenerate the given crewmember.\n");
    printf("P   - Allows the user to play the game which for your program will result in exiting the program.\n");
}

void changeName(Crewmember** crew, int identifier)
{
    int indexPos = 11;
    for (int i = 0; i < CREWMEMBERS; i++) {
        if (crew[i]->sernum == identifier) {
            indexPos = i;
        }
    }
    if (indexPos != 11) {
        printf("Enter new name for crewmember #%d: ", crew[indexPos]->sernum);
        scanf(" %s", crew[indexPos]->name);
        printf("\n%d is now %s\n", crew[indexPos]->sernum, crew[indexPos]->name);
    } else {
        printf("Invalid crewmember\n");
    }
}

void makeCaptain(Crewmember** crew, int identifier)
{
    int indexPos = -1;
    for (int i = 0; i < CREWMEMBERS; i++) {
        if (crew[i]->sernum == identifier) {
            indexPos = i;
            crew[i]->captain = NULL;
            crew[i]->post = Cap;
            crew[i]->rank = Comm;
            printf("\n%s is now the captain\n", crew[i]->name);

            for (int j = 0; j < CREWMEMBERS; j++) {
                if (i != j) {
                    crew[j]->captain = crew[i];
                }
            }
            break;
        }
    }
    if (indexPos != -1) {
        Crewmember* temp = crew[0];
        crew[0] = crew[indexPos];
        crew[indexPos] = temp;
    }
}

void assignBridge(Crewmember** crew, int identifier)
{
    char bridgePos;
    printf("\nAssigning %d, enter C, N, E, or S: ", identifier);
    for (int i = 0; i < CREWMEMBERS; i++) {
        if (crew[i]->sernum == identifier) {
            scanf(" %c", &bridgePos);
            switch (bridgePos) {
                case 'C': crew[i]->post = Com; break;
                case 'N': crew[i]->post = Nav; break;
                case 'E': crew[i]->post = Eng; break;
                case 'S': crew[i]->post = Sec; break;
                default: printf("\nInvalid option\n"); break;
            }
            printf("\n%d has been reassigned\n", crew[i]->sernum);
        }
    }
}


void writeOutputTableToFile(Crewmember** crew, int crewsize)
{
    FILE *file = fopen("crewmember_list.txt", "w");

    fprintf(file, "Captain : %s\n", "placeholder");
    fprintf(file, "\t\t\t%-16s %s\n", "Skills", "Abilities");
    fprintf(file, "Ser#   Post Rank  | N  E  T  L  D  | C  I  S  P  A  | Race Name\n");
    for (int i = 0; i < 10; i++) {
        //printf("%-6d %-4s %-4s  | %-2d %-2d %-2d %-2d %-2d | %-2d %-2d %-2d %-2d %-2d | %-4s %s\n", 123456, "Crew", "Spcr", 0, -1, 2, -2, 1, 13, 3, 18, 5, 10, "T", "Kerlin");
        fprintf(file, "%-6d ", crew[i]->sernum);
        switch (crew[i]->post) {
            case Crew: fprintf(file, "%-4s ", "Crew"); break;
            case Com: fprintf(file, "%-4s ", "Com"); break;
            case Nav: fprintf(file, "%-4s ", "Nav"); break;
            case Eng: fprintf(file, "%-4s ", "Eng"); break;
            case Sec: fprintf(file, "%-4s ", "Sec"); break;
            case Cap: fprintf(file, "%-4s ", "Cap"); break;
        }
        switch (crew[i]->rank) {
            case Spcr: fprintf(file, "%-4s ", "Spcr"); break;
            case Ens: fprintf(file, "%-4s ", "Ens"); break;
            case Lt: fprintf(file, "%-4s ", "Lt"); break;
            case Comm: fprintf(file, "%-4s ", "Comm"); break;
        }
        fprintf(file, " | %-2d %-2d %-2d %-2d %-2d | %-2d %-2d %-2d %-2d %-2d | ", //%-4s %s\n", 
               //crew[i]->sernum, crew[i]->post, crew[i]->rank, 
               crew[i]->skills.Navigation, crew[i]->skills.Engineering, crew[i]->skills.Tactics, crew[i]->skills.Leadership, crew[i]->skills.Diplomacy, 
               crew[i]->abilities.Charisma, crew[i]->abilities.Intelligence, crew[i]->abilities.Strength, crew[i]->abilities.Psionics, crew[i]->abilities.Agility);
               //crew[i]->race, crew[i]->name);
        switch (crew[i]->race) {
            case Terran: fprintf(file, "%-4s", "T"); break;
            case Martian: fprintf(file, "%-4s", "M"); break;
            case Venusian: fprintf(file, "%-4s", "V"); break;
            case Saturian: fprintf(file, "%-4s", "S"); break;
        }
        fprintf(file, " %s\n", crew[i]->name);
    }
    fclose(file);
}


int main(int argc, char* argv[])
{
    int seed = time(NULL);
    if (argc > 1) {
        seed = atoi(argv[1]);
    }
    srand(seed);

    Crewmember* crew[CREWMEMBERS];
    int sernum;

    for (int i = 0; i < CREWMEMBERS; i++) {
        sernum = generateSernum();
        crew[i] = generateCrewmember(sernum, i + 1);
    }

    outputTable(crew, CREWMEMBERS);

    char choice;
    int modify;
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        
        if (scanf(" %c", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 'D') {
            outputTable(crew, CREWMEMBERS);
        } else if (choice == 'N') {
            if (scanf("%d", &modify) == 1 && modify >= 100000 && modify <= 999999) {
//                printf("NNN : %d\n", modify);
                changeName(crew, modify);
            } else {
                printf("Invalid crew #. Provide 6 digit number\n");
            }
        } else if (choice == 'C') {
            if (scanf("%d", &modify) == 1 && modify >= 100000 && modify <= 999999) {
//                printf("CCC : %d\n", modify);
                makeCaptain(crew, modify);
            } else {
                printf("Invalid crew member #. Provide 6 digit number\n");
            }
        } else if (choice == 'B') {
            if (scanf("%d", &modify) == 1 && modify >= 100000 && modify <= 999999) {
//                printf("BBB : %d\n", modify);
                assignBridge(crew, modify);
            } else {
                printf("Invalid crew member #. Provide 6 digit number\n");
            }
        } else if (choice == 'R') {
            if (scanf("%d", &modify) == 1 && modify >= 100000 && modify <= 999999) {
//                printf("RRR : %d\n", modify);
                for (int i = 0; i < CREWMEMBERS; i++) {
                    if (crew[i]->sernum == modify) {
                        int rSernum = generateSernum();
                        crew[i] = generateCrewmember(rSernum, i);
                        printf("\n%d has been regenerated and is now %d\n", modify, rSernum);
                    }
                }
            } else {
                printf("Invalid crew member #. Provide 6 digit number\n");
            }
        } else if (choice == 'S') {
            writeOutputTableToFile(crew, CREWMEMBERS);
            printf("File saved as crewmember_list.txt\n");
        } else if (choice == 'P') {
            printf("Have fun\n");
            break;
        }
        

        /*if (scanf("%c %d", &choice, &modify) == 2) {
            switch (choice) {
                case 'N': printf("NNN"); break;
                case 'C': printf("CCC"); break;
                case 'B': printf("BBB"); break;
                case 'R': printf("RRR"); break;
            }
        } else if (scanf("%c", &choice) == 1) {
            switch (choice) {
                case 'D': outputTable(crew, CREWMEMBERS); break;
                case 'S': printf("SSS"); break;
                case 'P': exit(0);
            }
        } else {
            printf("Invalid input\n");
        }*/


    }

    for (int i = 0; i < CREWMEMBERS; i++) {
        free(crew[i]->name);
        free(crew[i]);
    }

    return 0;
}














