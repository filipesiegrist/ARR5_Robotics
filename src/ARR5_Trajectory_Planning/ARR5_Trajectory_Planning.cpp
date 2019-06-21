#ifndef ARR5_TRAJECTORY_PLANNING_CPP
#define ARR5_TRAJECTORY_PLANNING_CPP

#include "../ARR5_Data.h"
#include "ARR5_Trajectory_Planning.h"

void pontos_intermediarios(position_t p1, position_t p2, position_t out_pontos[])
{
    distance_t tam_x,tam_y,tam_z;
    distance_t dist_x, dist_y, dist_z; 
    tam_x = p2.x - p1.x;
    tam_y = p2.y - p1.y;
    tam_z = p2.z - p1.z;
    dist_x = tam_x/(N_PONTOS + 1);
    dist_y = tam_y/(N_PONTOS + 1);
    dist_z = tam_z/(N_PONTOS + 1);
    position_t aux;
    for(int i=1; i<N_PONTOS+1; i++)
    {
        aux.x = p1.x + dist_x*i;
        aux.y = p1.y + dist_y*i;
        aux.z = p1.z + dist_z*i;
        out_pontos[i-1] = aux;
    }
}

position_t move_x(position_t pos, distance_t delta){
	position_t out = pos;
	out.x += delta;
	return out;
}
position_t move_y(position_t pos, distance_t delta){
	position_t out = pos;
	out.y += delta;
	return out;
}
position_t move_z(position_t pos, distance_t delta){
	position_t out = pos;
	out.z += delta;
	return out;
}

#endif