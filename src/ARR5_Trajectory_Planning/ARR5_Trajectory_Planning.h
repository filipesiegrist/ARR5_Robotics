#ifndef ARR5_TRAJECTORY_PLANNING_H
#define ARR5_TRAJECTORY_PLANNING_H 

#include "../ARR5_Data.h"

/*
	Numero de pontos intermediarios gerados.
*/
#define N_PONTOS 5

/*

Gera N_PONTOS pontos intermediarios na reta que liga p1 a p2.
E joga-os no vetor estaticamente alocado (com N_PONTOS) out_pontos
Esse vetor é do tipo position_t. Da uma olhada no ARR5_Data.h pra ver. Isso foi feito pra facilitar.

*/
void pontos_intermediarios(position_t p1, position_t p2, position_t out_pontos[]);

// Geram posicoes deslocadas em x, y ou z de uma distancia delta.

position_t move_x(position_t pos, distance_t delta);
position_t move_y(position_t pos, distance_t delta);
position_t move_z(position_t pos, distance_t delta);