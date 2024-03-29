#ifndef GAME_H
#define GAME_H

#include <sys/types.h>
#include <unistd.h>
#include "deck.h"
#include "path.h"
#include "errors.h"
#include "participants.h"
#include "utils.h"

void calc_next_turn(Path* myPath, Participant* participants);

void set_up(Path* myPath, Participant* p);

bool is_valid_move(Path* myPath, Participant* participants, const int playerId,
        int toPosition);

void handle_move(FILE* file, Deck* myDeck, Path* myPath, Participant* participants,
        int playerId, const int toPosition);

void display_sites(FILE* file, Path* myPath);

void display_player_position(FILE* file, Path* myPath, Participant* participants);

void display_dealer_output(FILE* file, Participant* participants);

void display_game(FILE* file, Path* myPath, Participant* participants);

bool is_end_game(Path* myPath, Participant* participants);

void calc_scores(FILE* file, Participant* participants);

void close_pipes_and_files(int id, int** pipesWrite, int** pipesRead,
        FILE** writeFile, FILE** readFile);

void send_last_message(pid_t* childIds, int numberOfPlayers, 
        FILE** writeFile, FILE** readFile, int** pipesWrite, int** pipesRead,
        bool early);

void handle_child(int id, char* currentPlayer, char* playersCountString,
        int** pipesWrite, int** pipesRead);

void handle_parent(int id, char* rawPath, FILE** writeFile, FILE** readFile,
        int** pipesWrite, int** pipesRead);

void initial_game(int numberOfPlayers, FILE** writeFile, FILE** readFile,
        int** pipesWrite, int** pipesRead, pid_t* childIds, char* rawPath,
        char** argv);

void communicate(Deck* myDeck, Path* myPath, Participant* participants, pid_t* childIds,
        FILE** writeFile, FILE** readFile,
        int** pipesWrite, int** pipesRead);

void run_game(Deck* myDeck, Path* myPath, Participant* participants, char** argv);

#endif