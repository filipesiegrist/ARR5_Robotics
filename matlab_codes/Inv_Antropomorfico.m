/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-04-20 21:31:14
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-05-10 14:54:21
*/

function [th_1,th_2,th_3] = Inv_Antropomorfico (a2,a3,pwx,pwy,pwz)

	c3 = (pwx^2 + pwy^2 + pwz^2 - a2^2 - a3^2) / (2*a2*a3);
    s3 = sqrt(1-c3^2); % pode ser positivo
    th_3 = atan2(s3,c3);

    % É possivel trocar o sinal das duas raizes, mas tem que fazer nas duas.
	c2 = (sqrt(pwx^2+pwy^2)*(a2+a3*c3) + pwz*a3*s3) / (a2^2+a3^2+2*a2*a3*c3);
    s2 = (pwz*(a2+a3*c3)-sqrt(pwx^2+pwy^2)*a3*s3) / (a2^2+a3^2+2*a2*a3*c3);
    th_2 = atan2(s2,c2);

    th_1 = atan2(pwy,pwx);

endfunction
