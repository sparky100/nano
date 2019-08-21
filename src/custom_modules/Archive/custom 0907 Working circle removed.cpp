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
	double birth_rate;
	double death_rate;
	if (parameters.ints("cell_type")==1)
		{
			cell_defaults.name = "UCI101";
			birth_rate=parameters.doubles("birth_rate_UCI101");
			death_rate=parameters.doubles("death_rate_UCI101");
			 
		}
	else
		{
			cell_defaults.name = "A2780"; 
			birth_rate=parameters.doubles("birth_rate_A2780");
			death_rate=parameters.doubles("death_rate_A2780");


		}
	
	// set default cell cycle model 

	cell_defaults.functions.cycle_model = live; 
	
	
	// set default_cell_functions; 
	
	if (parameters.bools( "o2_Modelling")==true)
	{
		cell_defaults.functions.update_phenotype = update_cell_and_death_parameters_O2_based; 
	}
	else if (parameters.bools("diffusion_model")==true)
	{
		cell_defaults.functions.update_phenotype = custom_cisplatin_phenotype_rule; 
	}
	else
	{
		cell_defaults.functions.update_phenotype=empty_function;
	}
	
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
	
	cell_defaults.phenotype.cycle.data.transition_rate(start,end)=birth_rate;
	cell_defaults.phenotype.death.rates[apoptosis_model_index]=death_rate;

	// initially no necrosis 
	cell_defaults.phenotype.death.rates[necrosis_model_index] = 0.0; 

	// set oxygen uptake / secretion parameters for the default cell type 
	cell_defaults.phenotype.secretion.uptake_rates[oxygen_substrate_index] = parameters.doubles("o2_uptake_rate"); 
	cell_defaults.phenotype.secretion.secretion_rates[oxygen_substrate_index] = 0; 
	cell_defaults.phenotype.secretion.saturation_densities[oxygen_substrate_index] = 38; 
	
	// add custom data here, if any 

	double static pi=3.141592564;
	
	//double total=parameters.doubles("total");
	double cell_rad=parameters.doubles("cell_radius");
	
	// Use standard cell data 
	if (parameters.bools("use_defaults")==false)
	{
		cell_defaults.phenotype.volume.total=(4.0/3.0)*pi*pow(cell_rad,3.0);
		cell_defaults.phenotype.geometry.radius=cell_rad;
		cell_defaults.phenotype.geometry.nuclear_radius=4.503;
		cell_defaults.phenotype.volume.fluid = 	cell_defaults.phenotype.volume.fluid_fraction * cell_defaults.phenotype.volume.total; 
		cell_defaults.phenotype.volume.solid = 	cell_defaults.phenotype.volume.total-	cell_defaults.phenotype.volume.fluid; 
		
		cell_defaults.phenotype.volume.nuclear = 540.0; 
		cell_defaults.phenotype.volume.nuclear_fluid = 	cell_defaults.phenotype.volume.fluid_fraction * cell_defaults.phenotype.volume.nuclear; 
		cell_defaults.phenotype.volume.nuclear_solid = 	cell_defaults.phenotype.volume.nuclear - 	cell_defaults.phenotype.volume.nuclear_fluid;

		cell_defaults.phenotype.volume.cytoplasmic = 	cell_defaults.phenotype.volume.total - 	cell_defaults.phenotype.volume.nuclear;
		cell_defaults.phenotype.volume.cytoplasmic_fluid = 	cell_defaults.phenotype.volume.fluid_fraction*	cell_defaults.phenotype.volume.cytoplasmic; 
		cell_defaults.phenotype.volume.cytoplasmic_solid = 	cell_defaults.phenotype.volume.cytoplasmic - 	cell_defaults.phenotype.volume.cytoplasmic_fluid; 
		
		cell_defaults.phenotype.volume.target_solid_cytoplasmic = 	cell_defaults.phenotype.volume.cytoplasmic_solid;
		cell_defaults.phenotype.volume.target_solid_nuclear = 	cell_defaults.phenotype.volume.nuclear_solid;
		cell_defaults.phenotype.volume.target_fluid_fraction = 	cell_defaults.phenotype.volume.fluid_fraction;

		cell_defaults.phenotype.volume.cytoplasmic_to_nuclear_ratio = 	cell_defaults.phenotype.volume.cytoplasmic / ( 1e-16 + 	cell_defaults.phenotype.volume.nuclear);
		cell_defaults.phenotype.volume.target_cytoplasmic_to_nuclear_ratio = 	cell_defaults.phenotype.volume.cytoplasmic_to_nuclear_ratio; 
		
		// as fraction of volume at entry to the current phase
		cell_defaults.phenotype.volume.rupture_volume = 	cell_defaults.phenotype.volume.relative_rupture_volume * cell_defaults.phenotype.volume.total; // in volume units 	
		cell_defaults.phenotype.geometry.surface_area = 4.0*pi*cell_defaults.phenotype.geometry.radius*cell_defaults.phenotype.geometry.radius; 

	}
	// Now, let's define source cell type
		
	source_cell = cell_defaults; 
	source_cell.type = 1; 
	source_cell.name = "source drug cell"; 
	
	// make sure the new cell type has its own reference phenotype
	
	source_cell.parameters.pReference_live_phenotype = &( source_cell.phenotype ); 
	
	// disable motility 
	source_cell.phenotype.motility.is_motile = false; 
	
	// Set proliferation and apoptosis to zero 
	source_cell.phenotype.death.rates[apoptosis_model_index] = 0.0;
	source_cell.phenotype.cycle.data.transition_rate(start,end) =0.0; // 0.1; 

	source_cell.phenotype.secretion.uptake_rates[oxygen_substrate_index] = 0; 
	source_cell.phenotype.secretion.secretion_rates[oxygen_substrate_index] = 0; 
	source_cell.phenotype.secretion.saturation_densities[oxygen_substrate_index] = 0; 

	
	if (parameters.bools("diffusion_model")==true) // Define uptake values
	
	{
		int drug_substrate_index=microenvironment.find_density_index( parameters.strings("drug") ); 
		cell_defaults.phenotype.secretion.uptake_rates[drug_substrate_index] = 0; 
		cell_defaults.phenotype.secretion.secretion_rates[drug_substrate_index] = 0; 
		cell_defaults.phenotype.secretion.saturation_densities[drug_substrate_index] =0.0; 

		//source_cell.phenotype.secretion.sync_to_microenvironment( &microenvironment ); 
		source_cell.phenotype.secretion.uptake_rates[drug_substrate_index] = 0; 
		source_cell.phenotype.secretion.secretion_rates[drug_substrate_index] = parameters.doubles("device_secretion_rate"); 
		source_cell.phenotype.secretion.saturation_densities[drug_substrate_index] =parameters.bools("drug_boundary_condition"); 
		
	}
	
	return; 
}

void setup_microenvironment( void )
{
	// set domain parameters 

	std::vector<double> bc_vector( 1 , 38.0 ); // 5% o2
	
	if (parameters.bools("diffusion_model")==true) //  cisplatin  added
	{
		microenvironment.add_density( parameters.strings("drug"), "dimensionless" );
		microenvironment.diffusion_coefficients[1] = parameters.doubles("drug_diffusion_rate");
		microenvironment.decay_rates[1] = parameters.doubles("drug_decay_rate");
		//extend boundary condition vector
		if (parameters.bools("Dirichlet")==true)
		{
			bc_vector.push_back(parameters.doubles("drug_boundary_condition"));
		}
		else
		{
			bc_vector.push_back(0.0);
		}
		
	}
	
		// no gradients need for this example 
	default_microenvironment_options.calculate_gradients = false; 
	
	// set outer Dirichlet conditions 
	default_microenvironment_options.outer_Dirichlet_conditions = true;
	
	// if there are more substrates, resize accordingly 
	default_microenvironment_options.Dirichlet_condition_vector = bc_vector;
	
	// initialize BioFVM 
	
	initialize_microenvironment(); 	
	
	// This creates the voxels
	
	if (parameters.bools("diffusion_model")==true)
	{
		if (parameters.bools("Dirichlet")==true)
		{
			if (parameters.bools("diffusion_model_boundary")==false)
			{
				double sphere_radius=parameters.doubles("no_of_cells")*cell_defaults.phenotype.geometry.radius;
				std::cout << "Sphere radius " << sphere_radius<< std::endl; 
				for( int i=0; i < microenvironment.number_of_voxels() ; i++ )
				{
					double a=dist(microenvironment.voxels(i).center, {0.0,0.0,0.0});
					if(dist(microenvironment.voxels(i).center, {0.0,0.0,0.0})>(sphere_radius+3*cell_defaults.phenotype.geometry.radius))		
					{
						microenvironment.update_dirichlet_node( i , bc_vector);
						//std::cout << "Updating Voxel " << microenvironment.voxels(i).center<< std::endl; 
					}
				}
			}	
			get_default_microenvironment()->set_substrate_dirichlet_activation(0,true);
			get_default_microenvironment()->set_substrate_dirichlet_activation(1,true);
		}
		else
		{
			//if not Dirichlet then apply condition on O2 but not Drug
			get_default_microenvironment()->set_substrate_dirichlet_activation(0,true);
			get_default_microenvironment()->set_substrate_dirichlet_activation(1,false); // Neuman condition
		}
	}
	else
	{
		// if not diffusion model
		// Dirichlet boundary condition applied in O2
	}
				
	microenvironment.apply_dirichlet_conditions();
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
		std::vector<double> tmp(3,0.0);

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
	//cell_radius=7.5; 
	double sphere_radius =no_of_cells*cell_radius;

	 std::cout << "sphere radius " << sphere_radius << std::endl;
	 std::cout << "cell_radius " << cell_radius << std::endl;


	// std::cout << __FILE__ << " custom " << __LINE__ << std::endl;

	bool create_Sphere_check = parameters.bools( "create_sphere" );
	
	Cell* pCell;

		std::vector<std::vector<double>> cell_positions;
		
			cell_positions= create_sphere(cell_radius, cell_radius*no_of_cells);
	

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

void adjust_death_rates( void )
{
	// Get list of all cells
	Cell* pC = NULL;
	// loop through cells


	std::vector<double> tempPoint(3,0.0);

	double max_radial_position=0.0;
	double radial_position=0.0;
	
	for( int i=0; i < (*all_cells).size(); i++ )
	{
		pC = (*all_cells)[i];
		//std::cout << pC->ID << ": " << pC->phenotype.cycle.current_phase().name << std::endl;
		// Determine maximum radial position
		// Add custom field to store radial position

		radial_position = sqrt(norm_squared(pC->position));

		if (pC->phenotype.cycle.current_phase().code == PhysiCell_constants::live )  
			{
				if ((radial_position)>max_radial_position)
				{max_radial_position=radial_position;}
			}
	}

	double apoptosis_rate;
	if (parameters.bools("use_defaults")==false)
	{
		if (parameters.ints("cell_type")==1)
		{
			apoptosis_rate=parameters.doubles("death_rate_UCI101");
		}
		else
		{
			apoptosis_rate=parameters.doubles("death_rate_A2780");
		}
	}
	else
	{
		int apoptosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Apoptosis" );	
		apoptosis_rate= cell_defaults.phenotype.death.rates[apoptosis_model_index];
	}	
	//std::cout << "applied death rate"<< ": " << apoptosis_rate << std::endl;
		
	
	double sd=parameters.doubles("standard_deviation");

	for ( int i=0; i < (*all_cells).size(); i++ )
	{
		int apoptosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Apoptosis" );

		pC = (*all_cells)[i];
		//std::cout << pC->ID << ": " << pC->phenotype.cycle.current_phase().name << std::endl;
		// Determine maximum radial position
		// Add custom field to store radial position
		// Look only at live cells!!
		if (pC->phenotype.cycle.current_phase().code == PhysiCell_constants::live )  
		{
			radial_position = sqrt(norm_squared(pC->position));
			if (parameters.ints("death_rate_type")==1)
			{
				double scale=radial_position/max_radial_position;
				std::cout <<"scale" << ": " << scale <<"calc"<<apoptosis_rate*scale<< std::endl;

				pC->phenotype.death.rates[apoptosis_model_index]=apoptosis_rate*scale;
			}
			else if (parameters.ints("death_rate_type")==2)
			{
				double normal =radial_position/max_radial_position;
				
				double xminusmu2=pow(normal-1.0,2.0);
				double sd2=2*(pow(sd,2.0));
				double scale =exp(-(xminusmu2/sd2));
			//	std::cout << pC->ID << ":sd2 " <<sd<<" xmin "<< xminusmu2<< std::endl;
			//	std::cout << pC->ID << ":max " <<max_radial_position<<" rad "<< radial_position<<" scale "<< scale <<" Transition "<< pC->phenotype.cycle.data.transition_rate(0,0)<< std::endl;
				pC->phenotype.death.rates[apoptosis_model_index]=apoptosis_rate*scale;
				//std::cout <<"scale" << ": " << normal <<" calc "<<apoptosis_rate*scale<< std::endl;
			}	
			else if (parameters.ints("death_rate_type")==3)
			{
				NULL;
			} 
		}
	//	std::cout << pC->ID <<" "<< pC->position << std::endl;
	//	std::cout << pC->ID << ":max " <<max_radial_position<<" rad "<< radial_position<<" scale "<< scale <<" Transition "<< pC->phenotype.cycle.data.transition_rate(0,0)<< std::endl;
		//
	}

	return; 
}
