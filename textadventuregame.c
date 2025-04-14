#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Room {
    char description[200];
    struct Room* next;
    int hasEnemy; // 1 if the room contains an enemy, 0 if no enemy
} Room;

typedef struct Player {
    Room* currentRoom;
    int health;
    int attackPower;
} Player;

typedef struct Enemy {
    char name[50];
    int health;
    int attackPower;
} Enemy;

Room* createRoom(char* description, int hasEnemy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->description, description);
    newRoom->next = NULL;
    newRoom->hasEnemy = hasEnemy;
    return newRoom;
}

void displayRoom(Room* room) {
    printf("You are in a room: %s\n", room->description);
}

void moveToRoom(Player* player, Room* newRoom) {
    player->currentRoom = newRoom;
}

void fight(Player* player, Enemy* enemy) {
    printf("A wild %s appears!\n", enemy->name);
    
    while (player->health > 0 && enemy->health > 0) {
        printf("\nYour health: %d | %s's health: %d\n", player->health, enemy->name, enemy->health);
        printf("You attack %s!\n", enemy->name);
        enemy->health -= player->attackPower;

        if (enemy->health <= 0) {
            printf("You defeated %s!\n", enemy->name);
            break;
        }

        printf("%s attacks you!\n", enemy->name);
        player->health -= enemy->attackPower;

        if (player->health <= 0) {
            printf("You were defeated by %s...\n", enemy->name);
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Create rooms
    Room* room1 = createRoom("A dark and spooky room.", 1); // Has an enemy
    Room* room2 = createRoom("A bright and sunny garden.", 0); // No enemy
    Room* room3 = createRoom("A library full of dusty books.", 1); // Has an enemy

    // Link rooms
    room1->next = room2;
    room2->next = room3;

    // Create player and set initial room
    Player player = {room1, 100, 20}; // Player starts with 100 health and 20 attack power

    // Create enemies
    Enemy enemy1 = {"Goblin", 50, 10};
    Enemy enemy2 = {"Orc", 80, 15};

    // Game loop
    char choice[10];
    while (1) {
        displayRoom(player.currentRoom);
        
        if (player.currentRoom->hasEnemy) {
            Enemy* currentEnemy = (player.currentRoom == room1) ? &enemy1 : &enemy2;
            fight(&player, currentEnemy);
            if (player.health <= 0) {
                printf("Game Over!\n");
                break;
            }
        }

        printf("\nDo you want to move to the next room? (yes/no): ");
        scanf("%s", choice);

        if (strcmp(choice, "yes") == 0 && player.currentRoom->next != NULL) {
            moveToRoom(&player, player.currentRoom->next);
        } else if (strcmp(choice, "no") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("There is no next room.\n");
        }
    }

    // Free allocated memory (for room objects)
    free(room1);
    free(room2);
    free(room3);

    return 0;
}
