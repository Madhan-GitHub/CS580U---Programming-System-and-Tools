#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tournament.h"

// Function implementation of draftPlayers().
Player * draftPlayers(char * filename, int team, int num_players)
{
    char str[100];
	int index = 0;
	Player *teamPlayer = malloc( num_players * sizeof(Player) );
    // To read the I/O file(players.dat) 
	FILE *f = fopen("players.dat" , "r" );
	while(fgets(str, sizeof(str), f)){
		char *team_ch = strtok(str, ",");
		if(atoi(team_ch) == team){
			teamPlayer[index].team = atoi(team_ch);
			teamPlayer[index].first = strdup(strtok(NULL, ","));
			teamPlayer[index].last = strdup(strtok(NULL, ","));
			teamPlayer[index].number = atoi(strtok(NULL , ","));
			teamPlayer[index].offensive = atoi(strtok(NULL, ","));
			teamPlayer[index].defensive = atoi(strtok(NULL, ","));
			index++;
		}
	}
	fclose(f);
	return teamPlayer;
}

// Function implementation of initializeTeam().
Team * initializeTeam(char * name, Player * players) 
{
    Team * team= malloc(sizeof(Team));
	team->name=malloc(sizeof(name));
	strcpy(team->name,name);
    team->players = players;
    //team->delete = deleteTeam; 
	return team;
}

// Function implementation of game().
Team * game(Team * team1,Team * team2)
{
    Team *winner = NULL;
    int team1_totalOffence = 0; 
    int team1_totalDefence = 0;
    int team2_totalOffence = 0;
    int team2_totalDefence = 0; 
	int team1_score = 0;
    int team2_score = 0;
    // returns null if the passed team has empty values.
    if(team1 == NULL || team2 == NULL){
        return NULL;
    }
    else{
        for(int i = 0; i < 10; i++){
		    team1_totalOffence += team1->players[i].offensive;
	        team1_totalDefence += team1->players[i].defensive;
            team2_totalOffence += team2->players[i].offensive;
            team2_totalDefence += team2->players[i].defensive;	
        }
    // To get the team's offence by a random value 
        int team1_offence = rand()%team1_totalOffence;
        int team2_offence = rand()%team2_totalOffence;
	// To detemine which team has better defence/attack and increases the score by 1    
        for(int i = 0; i < 10; i++){  	
            if(team1_offence > team2_totalDefence){
                team1_score++;
            }
            else{
                team2_score++;
            }
            if(team2_offence > team1_totalDefence){
                team2_score++;
            }
            else{
                team1_score++;
            }
        }
    // To decide the winner among the two teams.
        if(team1_score > team2_score){
            winner = team1;
        }
        else{
            winner = team2;
        }
	    return winner;
    }
}

// Function implementation to find the passed value is power of 2.
int isPowerOf2(int i) 
{
   if(i == 0 || i == 1){
		return 0;
	}
    while(i != 1){
	    if(i % 2 != 0){
		    return 0;
		}
	    i = i/2;
	}
    return 1;   
}

// Function implementation of tournament().
Team * tournament(Team **team,int numberOfTeams)
{
    int check = 0;
	check = isPowerOf2(numberOfTeams);
    if(check != 0){
        Team * finalWinner[numberOfTeams];
        int index = 0;
        // To ittrate the total number of teams and to find the winner, it copy contents from team array to finalWinner array
    	while(index < numberOfTeams){
        	finalWinner[index] = team[index];
        	index++;
    	}
        // for every itteration the number of teams reduced to its half eventually to determine the winner.
    	while(numberOfTeams > 1){
        	for(index = 0; index < (numberOfTeams / 2); index++) {
        		finalWinner[index] = game(finalWinner[index], finalWinner[(numberOfTeams / 2) + index]);
        	}
        	if(numberOfTeams > 2) {
                numberOfTeams = numberOfTeams / 2;
            } 
            else {
                break;
            }
        }
        // After the ittration the the value stored in the zero'th index is the winner.
        Team *winner = finalWinner[0];
        return winner;
	}   // To handle the exception if the total teams is not the power of two.
	else{
		printf("\nInvalid number of teams in the tournament, the number of teams should be a power of 2(2,4,8,16,32...)");
        return NULL;
	}
}

// Function implementation of deleteTeam().
void * deleteTeam(Team * team)
{
free(team);
team = NULL;
}