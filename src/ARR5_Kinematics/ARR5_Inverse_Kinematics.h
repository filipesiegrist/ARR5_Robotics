/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-05-26 15:37:39
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-26 15:37:39
*/

#ifndef ARR5_INVERSE_KINEMATICS_H__
#define ARR5_INVERSE_KINEMATICS_H__

#include <math.h>
#include "../ARR5_Data.h"
#include "../ARR5_Angle_Conversions/degreesRadiansConversions.h"

distance_t SQ(distance_t X);

robot_angles_t inverse_kinematics(distance_t d1, distance_t a1, distance_t a2, distance_t a3, position_t point, basic_orientation_t elbow_up_or_down);

/*

Algumas instrucoes pra vc implementar:

Tem que converter os angulos vindos das funções acos e atan2 de radianos pra graus. Ignora a conversao que usei no fim da funcao do matlab.

robot_angles_t é uma estrutura que guarda três angulos, feita pra facilitar a sua vida. ela ta declarada no ARR5_Data.h

Tem um arquivo no ARR5_Angle_Conversions que tem essas funções prontas, qualquer dúvida dá uma olhada no ARR5_Direct_Kinematics.

O parametro elbow_up_or_down só vai dizer se o cotovelo do robo estara pra cima e pra baixo, pq temos duas respostas pra raiz quadrada. Vc vai colocar ele multiplicando na hora de calcular o s3 e multiplicando o p (psi) pra calcular o "th_2".

A proposito: b é beta e p é psi, se isso te ajudar a interpretar o codigo. Pra usar o acos e atan2, basta incluir o math.h e usar normal, não tem muito segredo.

*/

#endif /* end of include guard: ARR5_INVERSE_KINEMATICS_H__ */