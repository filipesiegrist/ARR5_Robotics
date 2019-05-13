% Cinemática direta simples.

function [pwx,pwy,pwz] = Dir_ARR5(d1,a1,a2,a3,th_1,th_2,th_3)
	% Nesse caso, por enquanto, calcula apenas posição.

	% Substituições relevantes:
	c1 = cos(th_1);
	s1 = sin(th_1);
	c2 = cos(th_2);
	s2 = sin(th_2);
	c23 = cos(th_2 + th_3);
	s23 = sin(th_2 + th_3);

	pwx = c1*(a1 + a3*c23 + a2*c2);
	pwy = s1*(a1 + a3*c23 + a2*c2);
	pwz = d1 + a3*s23 + a2*s2;
endfunction
