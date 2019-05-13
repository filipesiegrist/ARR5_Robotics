%
% @Author: Filipe Ernesto Siegrist Gonçalves
% @Date:   2019-04-20 21:31:14
% @Last Modified by:   filipe-ufsc
% @Last Modified time: 2019-05-12 21:57:20
%


function [th_1,th_2,th_3] = Inv_ARR5 (d1,a1,a2,a3,pwx,pwy,pwz)
	% Mudanca de variavel: descontando o valor de a1.
	pwh = sqrt(pwx^2+pwy^2) - a1;

	% Outra mudança: Acha um pwz alternativo, descontando a altura do robô
	pwz0 = pwz;
	pwz = pwz - d1;

	c3 = (pwh^2 + pwz^2 - a2^2 - a3^2) / (2*a2*a3);
    s3 = sqrt(1-c3^2); % pode ser negativo
    th_3 = atan2(s3,c3);

    % Usa lei dos senos para calcular beta:
    b = asin( a3*sin(th_3) / sqrt(pwh^2+pwz^2) );


    % Calcula psi:
    p = atan2(pwz,pwh);

    % theta2 = psi +/- beta
    th_2 = b + p % Pode ser uma subtração também.

    th_1 = atan2(pwy,pwx);

    %th_1 = th_1 * 180 / pi
    %th_2 = th_2 * 180 / pi
    %th_3 = th_3 * 180 / pi

endfunction
