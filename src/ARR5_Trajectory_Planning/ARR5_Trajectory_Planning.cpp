#ifndef ARR5_TRAJECTORY_PLANNING_CPP
#define ARR5_TRAJECTORY_PLANNING_CPP 

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