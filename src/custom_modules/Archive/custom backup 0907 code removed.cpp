/*
###############################################################################
# If you use PhysiCell in your project, please cite PhysiCell and the version #
# number, such as below:                                                      #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1].    #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# See VERSION.txt or call get_PhysiCell_version() to get the current version  #
#     x.y.z. Call display_citations() to get detailed information on all cite-#
#     able software used in your PhysiCell application.                       #
#                                                                             #
# Because PhysiCell extensively uses BioFVM, we suggest you also cite BioFVM  #
#     as below:                                                               #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1],    #
# with BioFVM [2] to solve the transport equations.                           #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# [2] A Ghaffarizadeh, SH Friedman, and P Macklin, BioFVM: an efficient para- #
#     llelized diffusive transport solver for 3-D biological simulations,     #
#     Bioinformatics 32(8): 1256-8, 2016. DOI: 10.1093/bioinformatics/btv730  #
#                                                                             #
###############################################################################
#                                                                             #
# BSD 3-Clause License (see https://opensource.org/licenses/BSD-3-Clause)     #
#                                                                             #
# Copyright (c) 2015-2018, Paul Macklin and the PhysiCell Project             #
# All rights reserved.                                                        #
#                                                                             #
# Redistribution and use in source and binary forms, with or without          #
# modification, are permitted provided that the following conditions are met: #
#                                                                             #
# 1. Redistributions of source code must retain the above copyright notice,   #
# this list of conditions and the following disclaimer.                       #
#                                                                             #
# 2. Redistributions in binary form must reproduce the above copyright        #
# notice, this list of conditions and the following disclaimer in the         #
# documentation and/or other materials provided with the distribution.        #
#                                                                             #
# 3. Neither the name of the copyright holder nor the names of its            #
# contributors may be used to endorse or promote products derived from this   #
# software without specific prior written permission.                         #
#                                                                             #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" #
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   #
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  #
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   #
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         #
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        #
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    #
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     #
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     #
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  #
# POSSIBILITY OF SUCH DAMAGE.                                                 #
#                                                                             #
###############################################################################
*/

#include "./custom.h"
// Custom rule defined here
void custom_cisplatin_phenotype_rule( Cell* pCell, Phenotype& phenotype, double dt )
{
// don't bother if you're dead
if( pCell->phenotype.death.dead == true )
{ return; }
// first, call the standard function
// Check if the O2 update is switched on / off
  
if (parameters.bools("o2_Modelling")==true)
{
	update_cell_and_death_parameters_O2_based(pCell,phenotype,dt);
  
}
// Let's check oxygen
	static int o2_index = microenvironment.find_density_index( "oxygen" ); 
	double o2 = pCell->nearest_density_vector()[o2_index];	

// next, let's evaluate the cisplatin
static int drug_index = microenvironment.find_density_index(parameters.strings("drug"));
double drug = pCell->nearest_density_vector()[drug_index];
double multiplier=1.0;

// get apoptosis data
int apoptosis_model_index = pCell->phenotype.death.find_death_model_index( "Apoptosis" );
int start = live.find_phase_index( PhysiCell_constants::live );
int end = live.find_phase_index( PhysiCell_constants::live );
double death_rate;
	if (parameters.ints("cell_type")==1)
		{
			cell_defaults.name = "UCI101";
			death_rate=parameters.doubles("death_rate_UCI101");
		}
	else
		{
			cell_defaults.name = "A2780"; 
			death_rate=parameters.doubles("death_rate_A2780");
		}
// Boundary value =38.0
	static double drug_boundary_condition=parameters.doubles("drug_boundary_condition");
	multiplier=drug/(drug_boundary_condition);
	pCell->phenotype.death.rates[apoptosis_model_index]=death_rate*multiplier;
 //   std::cout <<pCell->position<<" Drug conc "<<drug << " Multiplier "<<multiplier<<" Death Rate " <<pCell->phenotype.death.rates[apoptosis_model_index]<<std::endl;
   return;
}


// declare cell definitions here 

Cell_Definition source_cell; 

void create_cell_types( void )
{
	// use the same random seed so that future experiments have the 
	// same initial histogram of oncoprotein, even if threading means 
	// that future division and other events are still not identical 
	// for all runs 
	
	SeedRandom( parameters.ints("random_seed") ); // or specify a seed here 
	
	// housekeeping 
	
	initialize_default_cell_definition();
	cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment ); 
	
	// Name the default cell type 
	
	cell_defaults.type = 0;
	
	// set default cell cycle model 

	cell_defaults.functions.cycle_model = live; 
	
	// set default_cell_functions; 
	
	cell_defaults.functions.update_phenotype=	cell_defaults.functions.update_phenotype = update_cell_and_death_parameters_O2_based;
	
	// needed for a 2-D simulation: if( default_microenvironment_options.simulate_2D == true )
		
	// make sure the defaults are self-consistent. 
	
	cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment );
	cell_defaults.phenotype.sync_to_functions( cell_defaults.functions ); 

	// first find index for a few key variables. 
	int apoptosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Apoptosis" );
	int necrosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Necrosis" );
	int oxygen_substrate_index = microenvironment.find_density_index( "oxygen" ); 

	int start = live.find_phase_index( PhysiCell_constants::live );
	int end = live.find_phase_index( PhysiCell_constants::live );
	
// Check birth and death rates
	
	//cell_defaults.phenotype.cycle.data.transition_rate(start,end)=birth_rate;
	//cell_defaults.phenotype.death.rates[apoptosis_model_index]=death_rate;

	// initially no necrosis 
	//ell_defaults.phenotype.death.rates[necrosis_model_index] = 0.0; 

	// set oxygen uptake / secretion parameters for the default cell type 
	cell_defaults.phenotype.secretion.uptake_rates[oxygen_substrate_index] = parameters.doubles("o2_uptake_rate"); 
	cell_defaults.phenotype.secretion.secretion_rates[oxygen_substrate_index] = 0; 
	cell_defaults.phenotype.secretion.saturation_densities[oxygen_substrate_index] = 38; 
	
	// add custom data here, if any 

	double static pi=3.141592564;
	
	// Now, let's define source cell type
		
	source_cell = cell_defaults; 
		
	return; 
}

void setup_microenvironment( void )
{
	// set domain parameters 

	std::vector<double> bc_vector( 1 , 38.0 ); // 5% o2
	
	// no gradients need for this example 
	default_microenvironment_options.calculate_gradients = false; 
	
	// set outer Dirichlet conditions 
	default_microenvironment_options.outer_Dirichlet_conditions = true;
	
	// if there are more substrates, resize accordingly 
	default_microenvironment_options.Dirichlet_condition_vector = bc_vector;
	
	// initialize BioFVM 
	
	initialize_microenvironment(); 	
	
	// This creates the voxels
	
				
	return; 
}

std::vector<std::vector<double>> create_sphere(double cell_radius, double sphere_radius)
{
std::vector<std::vector<double>> cells;
	int xc=0,yc=0,zc=0;
	double x_spacing= cell_radius*sqrt(3);
	double y_spacing= cell_radius*2;
	double z_spacing= cell_radius*sqrt(3);
	
	std::vector<double> tempPoint(3,0.0);
	// std::vector<double> cylinder_center(3,0.0);
	
	for(double z=-sphere_radius;z<sphere_radius;z+=z_spacing, zc++)
	{
		for(double x=-sphere_radius;x<sphere_radius;x+=x_spacing, xc++)
		{
			for(double y=-sphere_radius;y<sphere_radius;y+=y_spacing, yc++)
			{
				tempPoint[0]=x + (zc%2) * 0.5 * cell_radius;
				tempPoint[1]=y + (xc%2) * cell_radius;
				tempPoint[2]=z;
				
				if(sqrt(norm_squared(tempPoint))< sphere_radius)
				{ cells.push_back(tempPoint); }
			}
			
		}
	}
	return cells;
}



void setup_tissue( void )
{
	
	double no_of_cells=parameters.doubles( "no_of_cells" );
    double cell_radius=cell_defaults.phenotype.geometry.radius; 
	double sphere_radius =no_of_cells*cell_radius;

	 std::cout << "sphere radius " << sphere_radius << std::endl;
	 std::cout << "cell_radius " << cell_radius << std::endl;


	// std::cout << __FILE__ << " custom " << __LINE__ << std::endl;

	bool create_Sphere_check = parameters.bools( "create_sphere" );
	
	Cell* pCell;

		std::vector<std::vector<double>> cell_positions;
	
		cell_positions= create_sphere(cell_radius, sphere_radius);
		

		// Create cells based on each of the calculated positions
	
		for(int i=0;i<cell_positions.size();i++)
		// for(int i=0;i<2;i++)
		{
			pCell = create_cell();

			pCell->assign_position(cell_positions[i]);
		}
	

	return; 

}
	
std::vector<std::string> my_coloring_function( Cell* pCell )
{
	// SP - switch to live coloring model 
// red Apoptosis
	// green live
	// brown necrotic	
	
	std::vector<std::string> output = false_cell_coloring_live_dead(pCell); 
	
	// if the cell is motile and not dead, paint it black 
	
	if( pCell->phenotype.death.dead == false && 
		pCell->type == 1 )
	{
		 output[0] = "black"; 
		 output[2] = "black"; 	
	}
	
	return output; 
}
