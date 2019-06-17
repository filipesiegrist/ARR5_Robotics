#ifndef __ARR5_WORKING_SPACE_H__
#define __ARR5_WORKING_SPACE_H__

#include "../ARR5_Data.h"


/*

	Dado um ponto do espaco (coordenadas x,y e z),
	diz se esse ponto e alcancavel pelo manipulador.

	Verifica se os cossenos da cinematica inversa, alem de verificar se os angulos estao nos limites dos servos.



*/
bool is_point_on_working_space(distance_t d1, distance_t a1, distance_t a2, distance_t a3, position_t point, basic_orientation_t elbow_up_or_down);

#endif