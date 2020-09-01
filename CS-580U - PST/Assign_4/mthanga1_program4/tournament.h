#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include<stdio.h>

// Definition of struct Player
typedef struct Player{
	int offensive;
	int defensive;
	int number;
	int team;
	char * first;
	char * last;
} Player;

// Definition of struct Team
typedef struct Team{
	char * name;
	Player * players;
    //void(* delete) (struct Team *);
} Team;

// Function declaration wheras the implementation is encapsulated. 
Player * draftPlayers(char * filename, int team, int num_players);
Team * initializeTeam(char * name, Player * players);
Team * game(Team *, Team *);
Team * tournament(Team **, int);
void * deleteTeam(Team * );
#endif