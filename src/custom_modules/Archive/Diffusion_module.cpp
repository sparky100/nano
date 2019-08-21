void death_rate_concentratio_based( Cell* pCell, Phenotype& phenotype, double dt )
{

	if( phenotype.death.dead == true )
	{ return; }
	
	// Use oxygen to start with
	static int oxygen_substrate_index = pCell->get_microenvironment()->find_density_index( "oxygen" ); 
	
	// sample the microenvironment to get the pO2 value 
	
	double pO2 = (pCell->nearest_density_vector())[oxygen_substrate_index]; // PhysiCell_constants::oxygen_index]; 
	
	// this multiplier is for linear interpolation of the oxygen value 
	double multiplier = 1.0;
		
	// Assume death rate updated	
	// pdate the appropriate death transition rate based on sampled value  / consider relative to maximum value 
	// Calc multiplier
	
	phenotype.cycle.data.transition_rate(start_phase_index,end_phase_index) = multiplier * 
		pCell->parameters.pReference_live_phenotype->cycle.data.transition_rate(start_phase_index,end_phase_index);
	
	
	return; 
}

};