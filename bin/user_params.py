 
# This file is auto-generated from a Python script that parses a PhysiCell configuration (.xml) file.
#
# Edit at your own risk.
#
import os
from ipywidgets import Label,Text,Checkbox,Button,HBox,VBox,FloatText,IntText,BoundedIntText,BoundedFloatText,Layout,Box
    
class UserTab(object):

    def __init__(self):
        
        micron_units = Label('micron')   # use "option m" (Mac, for micro symbol)

        constWidth = '180px'
        tab_height = '500px'
        stepsize = 10

        #style = {'description_width': '250px'}
        style = {'description_width': '25%'}
        layout = {'width': '400px'}

        name_button_layout={'width':'25%'}
        widget_layout = {'width': '15%'}
        units_button_layout ={'width':'15%'}
        desc_button_layout={'width':'45%'}

        param_name1 = Button(description='random_seed', disabled=True, layout=name_button_layout)
        param_name1.style.button_color = 'lightgreen'

        self.random_seed = IntText(
          value=0,
          step=1,
          style=style, layout=widget_layout)

        param_name2 = Button(description='use_defaults', disabled=True, layout=name_button_layout)
        param_name2.style.button_color = 'tan'

        self.use_defaults = Checkbox(
          value=False,
          style=style, layout=widget_layout)

        param_name3 = Button(description='death_modelling', disabled=True, layout=name_button_layout)
        param_name3.style.button_color = 'lightgreen'

        self.death_modelling = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name4 = Button(description='diffusion_model', disabled=True, layout=name_button_layout)
        param_name4.style.button_color = 'tan'

        self.diffusion_model = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name5 = Button(description='o2_Modelling', disabled=True, layout=name_button_layout)
        param_name5.style.button_color = 'lightgreen'

        self.o2_Modelling = Checkbox(
          value=False,
          style=style, layout=widget_layout)

        param_name6 = Button(description='diffusion_model_boundary', disabled=True, layout=name_button_layout)
        param_name6.style.button_color = 'tan'

        self.diffusion_model_boundary = Checkbox(
          value=False,
          style=style, layout=widget_layout)

        param_name7 = Button(description='create_sphere', disabled=True, layout=name_button_layout)
        param_name7.style.button_color = 'lightgreen'

        self.create_sphere = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name8 = Button(description='o2_uptake_rate', disabled=True, layout=name_button_layout)
        param_name8.style.button_color = 'tan'

        self.o2_uptake_rate = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name9 = Button(description='o2_boundary', disabled=True, layout=name_button_layout)
        param_name9.style.button_color = 'lightgreen'

        self.o2_boundary = FloatText(
          value=60.0,
          step=1,
          style=style, layout=widget_layout)

        param_name10 = Button(description='cell_type', disabled=True, layout=name_button_layout)
        param_name10.style.button_color = 'tan'

        self.cell_type = IntText(
          value=1,
          step=0.1,
          style=style, layout=widget_layout)

        param_name11 = Button(description='birth_rate_UCI101', disabled=True, layout=name_button_layout)
        param_name11.style.button_color = 'lightgreen'

        self.birth_rate_UCI101 = FloatText(
          value=0.00037,
          step=0.0001,
          style=style, layout=widget_layout)

        param_name12 = Button(description='death_rate_UCI101', disabled=True, layout=name_button_layout)
        param_name12.style.button_color = 'tan'

        self.death_rate_UCI101 = FloatText(
          value=0.000,
          step=0.01,
          style=style, layout=widget_layout)

        param_name13 = Button(description='birth_rate_A2780', disabled=True, layout=name_button_layout)
        param_name13.style.button_color = 'lightgreen'

        self.birth_rate_A2780 = FloatText(
          value=0.0009,
          step=0.0001,
          style=style, layout=widget_layout)

        param_name14 = Button(description='death_rate_A2780', disabled=True, layout=name_button_layout)
        param_name14.style.button_color = 'tan'

        self.death_rate_A2780 = FloatText(
          value=0.001,
          step=0.0001,
          style=style, layout=widget_layout)

        param_name15 = Button(description='no_of_cells', disabled=True, layout=name_button_layout)
        param_name15.style.button_color = 'lightgreen'

        self.no_of_cells = FloatText(
          value=14,
          step=1,
          style=style, layout=widget_layout)

        param_name16 = Button(description='drug', disabled=True, layout=name_button_layout)
        param_name16.style.button_color = 'tan'

        self.drug = Text(
          value='cisplatin',
          style=style, layout=widget_layout)

        param_name17 = Button(description='drug_diffusion_rate', disabled=True, layout=name_button_layout)
        param_name17.style.button_color = 'lightgreen'

        self.drug_diffusion_rate = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name18 = Button(description='drug_decay_rate', disabled=True, layout=name_button_layout)
        param_name18.style.button_color = 'tan'

        self.drug_decay_rate = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name19 = Button(description='drug_boundary_condition', disabled=True, layout=name_button_layout)
        param_name19.style.button_color = 'lightgreen'

        self.drug_boundary_condition = FloatText(
          value=5.0,
          step=0.1,
          style=style, layout=widget_layout)

        param_name20 = Button(description='Dirichlet', disabled=True, layout=name_button_layout)
        param_name20.style.button_color = 'tan'

        self.Dirichlet = Checkbox(
          value=True,
          style=style, layout=widget_layout)

        param_name21 = Button(description='device_secretion_rate', disabled=True, layout=name_button_layout)
        param_name21.style.button_color = 'lightgreen'

        self.device_secretion_rate = FloatText(
          value=1000.0,
          step=100,
          style=style, layout=widget_layout)

        param_name22 = Button(description='add_device_secretion', disabled=True, layout=name_button_layout)
        param_name22.style.button_color = 'tan'

        self.add_device_secretion = Checkbox(
          value=False,
          style=style, layout=widget_layout)

        param_name23 = Button(description='cell_radius', disabled=True, layout=name_button_layout)
        param_name23.style.button_color = 'lightgreen'

        self.cell_radius = FloatText(
          value=7.5,
          step=0.1,
          style=style, layout=widget_layout)

        param_name24 = Button(description='death_rate_type', disabled=True, layout=name_button_layout)
        param_name24.style.button_color = 'tan'

        self.death_rate_type = IntText(
          value=2,
          step=0.1,
          style=style, layout=widget_layout)

        param_name25 = Button(description='standard_deviation', disabled=True, layout=name_button_layout)
        param_name25.style.button_color = 'lightgreen'

        self.standard_deviation = FloatText(
          value=0.2,
          step=0.01,
          style=style, layout=widget_layout)

        param_name26 = Button(description='motile_cell_persistence_time', disabled=True, layout=name_button_layout)
        param_name26.style.button_color = 'tan'

        self.motile_cell_persistence_time = FloatText(
          value=15,
          step=1,
          style=style, layout=widget_layout)

        param_name27 = Button(description='motile_cell_migration_speed', disabled=True, layout=name_button_layout)
        param_name27.style.button_color = 'lightgreen'

        self.motile_cell_migration_speed = FloatText(
          value=0.25,
          step=0.01,
          style=style, layout=widget_layout)

        param_name28 = Button(description='motile_cell_relative_adhesion', disabled=True, layout=name_button_layout)
        param_name28.style.button_color = 'tan'

        self.motile_cell_relative_adhesion = FloatText(
          value=0.05,
          step=0.01,
          style=style, layout=widget_layout)

        param_name29 = Button(description='motile_cell_apoptosis_rate', disabled=True, layout=name_button_layout)
        param_name29.style.button_color = 'lightgreen'

        self.motile_cell_apoptosis_rate = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name30 = Button(description='motile_cell_relative_cycle_entry_rate', disabled=True, layout=name_button_layout)
        param_name30.style.button_color = 'tan'

        self.motile_cell_relative_cycle_entry_rate = FloatText(
          value=0.1,
          step=0.01,
          style=style, layout=widget_layout)

        units_button1 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button1.style.button_color = 'lightgreen'
        units_button2 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button2.style.button_color = 'tan'
        units_button3 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button3.style.button_color = 'lightgreen'
        units_button4 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button4.style.button_color = 'tan'
        units_button5 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button5.style.button_color = 'lightgreen'
        units_button6 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button6.style.button_color = 'tan'
        units_button7 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button7.style.button_color = 'lightgreen'
        units_button8 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button8.style.button_color = 'tan'
        units_button9 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button9.style.button_color = 'lightgreen'
        units_button10 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button10.style.button_color = 'tan'
        units_button11 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button11.style.button_color = 'lightgreen'
        units_button12 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button12.style.button_color = 'tan'
        units_button13 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button13.style.button_color = 'lightgreen'
        units_button14 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button14.style.button_color = 'tan'
        units_button15 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button15.style.button_color = 'lightgreen'
        units_button16 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button16.style.button_color = 'tan'
        units_button17 = Button(description='micro m^2/min', disabled=True, layout=units_button_layout) 
        units_button17.style.button_color = 'lightgreen'
        units_button18 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button18.style.button_color = 'tan'
        units_button19 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button19.style.button_color = 'lightgreen'
        units_button20 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button20.style.button_color = 'tan'
        units_button21 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button21.style.button_color = 'lightgreen'
        units_button22 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button22.style.button_color = 'tan'
        units_button23 = Button(description='micron', disabled=True, layout=units_button_layout) 
        units_button23.style.button_color = 'lightgreen'
        units_button24 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button24.style.button_color = 'tan'
        units_button25 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button25.style.button_color = 'lightgreen'
        units_button26 = Button(description='min', disabled=True, layout=units_button_layout) 
        units_button26.style.button_color = 'tan'
        units_button27 = Button(description='micron/min', disabled=True, layout=units_button_layout) 
        units_button27.style.button_color = 'lightgreen'
        units_button28 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button28.style.button_color = 'tan'
        units_button29 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button29.style.button_color = 'lightgreen'
        units_button30 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button30.style.button_color = 'tan'

        desc_button1 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button1.style.button_color = 'lightgreen'
        desc_button2 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button2.style.button_color = 'tan'
        desc_button3 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button3.style.button_color = 'lightgreen'
        desc_button4 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button4.style.button_color = 'tan'
        desc_button5 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button5.style.button_color = 'lightgreen'
        desc_button6 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button6.style.button_color = 'tan'
        desc_button7 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button7.style.button_color = 'lightgreen'
        desc_button8 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button8.style.button_color = 'tan'
        desc_button9 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button9.style.button_color = 'lightgreen'
        desc_button10 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button10.style.button_color = 'tan'
        desc_button11 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button11.style.button_color = 'lightgreen'
        desc_button12 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button12.style.button_color = 'tan'
        desc_button13 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button13.style.button_color = 'lightgreen'
        desc_button14 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button14.style.button_color = 'tan'
        desc_button15 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button15.style.button_color = 'lightgreen'
        desc_button16 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button16.style.button_color = 'tan'
        desc_button17 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button17.style.button_color = 'lightgreen'
        desc_button18 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button18.style.button_color = 'tan'
        desc_button19 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button19.style.button_color = 'lightgreen'
        desc_button20 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button20.style.button_color = 'tan'
        desc_button21 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button21.style.button_color = 'lightgreen'
        desc_button22 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button22.style.button_color = 'tan'
        desc_button23 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button23.style.button_color = 'lightgreen'
        desc_button24 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button24.style.button_color = 'tan'
        desc_button25 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button25.style.button_color = 'lightgreen'
        desc_button26 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button26.style.button_color = 'tan'
        desc_button27 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button27.style.button_color = 'lightgreen'
        desc_button28 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button28.style.button_color = 'tan'
        desc_button29 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button29.style.button_color = 'lightgreen'
        desc_button30 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button30.style.button_color = 'tan'

        row1 = [param_name1, self.random_seed, units_button1, desc_button1] 
        row2 = [param_name2, self.use_defaults, units_button2, desc_button2] 
        row3 = [param_name3, self.death_modelling, units_button3, desc_button3] 
        row4 = [param_name4, self.diffusion_model, units_button4, desc_button4] 
        row5 = [param_name5, self.o2_Modelling, units_button5, desc_button5] 
        row6 = [param_name6, self.diffusion_model_boundary, units_button6, desc_button6] 
        row7 = [param_name7, self.create_sphere, units_button7, desc_button7] 
        row8 = [param_name8, self.o2_uptake_rate, units_button8, desc_button8] 
        row9 = [param_name9, self.o2_boundary, units_button9, desc_button9] 
        row10 = [param_name10, self.cell_type, units_button10, desc_button10] 
        row11 = [param_name11, self.birth_rate_UCI101, units_button11, desc_button11] 
        row12 = [param_name12, self.death_rate_UCI101, units_button12, desc_button12] 
        row13 = [param_name13, self.birth_rate_A2780, units_button13, desc_button13] 
        row14 = [param_name14, self.death_rate_A2780, units_button14, desc_button14] 
        row15 = [param_name15, self.no_of_cells, units_button15, desc_button15] 
        row16 = [param_name16, self.drug, units_button16, desc_button16] 
        row17 = [param_name17, self.drug_diffusion_rate, units_button17, desc_button17] 
        row18 = [param_name18, self.drug_decay_rate, units_button18, desc_button18] 
        row19 = [param_name19, self.drug_boundary_condition, units_button19, desc_button19] 
        row20 = [param_name20, self.Dirichlet, units_button20, desc_button20] 
        row21 = [param_name21, self.device_secretion_rate, units_button21, desc_button21] 
        row22 = [param_name22, self.add_device_secretion, units_button22, desc_button22] 
        row23 = [param_name23, self.cell_radius, units_button23, desc_button23] 
        row24 = [param_name24, self.death_rate_type, units_button24, desc_button24] 
        row25 = [param_name25, self.standard_deviation, units_button25, desc_button25] 
        row26 = [param_name26, self.motile_cell_persistence_time, units_button26, desc_button26] 
        row27 = [param_name27, self.motile_cell_migration_speed, units_button27, desc_button27] 
        row28 = [param_name28, self.motile_cell_relative_adhesion, units_button28, desc_button28] 
        row29 = [param_name29, self.motile_cell_apoptosis_rate, units_button29, desc_button29] 
        row30 = [param_name30, self.motile_cell_relative_cycle_entry_rate, units_button30, desc_button30] 

        box_layout = Layout(display='flex', flex_flow='row', align_items='stretch', width='100%')
        box1 = Box(children=row1, layout=box_layout)
        box2 = Box(children=row2, layout=box_layout)
        box3 = Box(children=row3, layout=box_layout)
        box4 = Box(children=row4, layout=box_layout)
        box5 = Box(children=row5, layout=box_layout)
        box6 = Box(children=row6, layout=box_layout)
        box7 = Box(children=row7, layout=box_layout)
        box8 = Box(children=row8, layout=box_layout)
        box9 = Box(children=row9, layout=box_layout)
        box10 = Box(children=row10, layout=box_layout)
        box11 = Box(children=row11, layout=box_layout)
        box12 = Box(children=row12, layout=box_layout)
        box13 = Box(children=row13, layout=box_layout)
        box14 = Box(children=row14, layout=box_layout)
        box15 = Box(children=row15, layout=box_layout)
        box16 = Box(children=row16, layout=box_layout)
        box17 = Box(children=row17, layout=box_layout)
        box18 = Box(children=row18, layout=box_layout)
        box19 = Box(children=row19, layout=box_layout)
        box20 = Box(children=row20, layout=box_layout)
        box21 = Box(children=row21, layout=box_layout)
        box22 = Box(children=row22, layout=box_layout)
        box23 = Box(children=row23, layout=box_layout)
        box24 = Box(children=row24, layout=box_layout)
        box25 = Box(children=row25, layout=box_layout)
        box26 = Box(children=row26, layout=box_layout)
        box27 = Box(children=row27, layout=box_layout)
        box28 = Box(children=row28, layout=box_layout)
        box29 = Box(children=row29, layout=box_layout)
        box30 = Box(children=row30, layout=box_layout)

        self.tab = VBox([
          box1,
          box2,
          box3,
          box4,
          box5,
          box6,
          box7,
          box8,
          box9,
          box10,
          box11,
          box12,
          box13,
          box14,
          box15,
          box16,
          box17,
          box18,
          box19,
          box20,
          box21,
          box22,
          box23,
          box24,
          box25,
          box26,
          box27,
          box28,
          box29,
          box30,
        ])

    # Populate the GUI widgets with values from the XML
    def fill_gui(self, xml_root):
        uep = xml_root.find('.//user_parameters')  # find unique entry point into XML
        self.random_seed.value = int(uep.find('.//random_seed').text)
        self.use_defaults.value = ('true' == (uep.find('.//use_defaults').text.lower()) )
        self.death_modelling.value = ('true' == (uep.find('.//death_modelling').text.lower()) )
        self.diffusion_model.value = ('true' == (uep.find('.//diffusion_model').text.lower()) )
        self.o2_Modelling.value = ('true' == (uep.find('.//o2_Modelling').text.lower()) )
        self.diffusion_model_boundary.value = ('true' == (uep.find('.//diffusion_model_boundary').text.lower()) )
        self.create_sphere.value = ('true' == (uep.find('.//create_sphere').text.lower()) )
        self.o2_uptake_rate.value = float(uep.find('.//o2_uptake_rate').text)
        self.o2_boundary.value = float(uep.find('.//o2_boundary').text)
        self.cell_type.value = int(uep.find('.//cell_type').text)
        self.birth_rate_UCI101.value = float(uep.find('.//birth_rate_UCI101').text)
        self.death_rate_UCI101.value = float(uep.find('.//death_rate_UCI101').text)
        self.birth_rate_A2780.value = float(uep.find('.//birth_rate_A2780').text)
        self.death_rate_A2780.value = float(uep.find('.//death_rate_A2780').text)
        self.no_of_cells.value = float(uep.find('.//no_of_cells').text)
        self.drug.value = (uep.find('.//drug').text)
        self.drug_diffusion_rate.value = float(uep.find('.//drug_diffusion_rate').text)
        self.drug_decay_rate.value = float(uep.find('.//drug_decay_rate').text)
        self.drug_boundary_condition.value = float(uep.find('.//drug_boundary_condition').text)
        self.Dirichlet.value = ('true' == (uep.find('.//Dirichlet').text.lower()) )
        self.device_secretion_rate.value = float(uep.find('.//device_secretion_rate').text)
        self.add_device_secretion.value = ('true' == (uep.find('.//add_device_secretion').text.lower()) )
        self.cell_radius.value = float(uep.find('.//cell_radius').text)
        self.death_rate_type.value = int(uep.find('.//death_rate_type').text)
        self.standard_deviation.value = float(uep.find('.//standard_deviation').text)
        self.motile_cell_persistence_time.value = float(uep.find('.//motile_cell_persistence_time').text)
        self.motile_cell_migration_speed.value = float(uep.find('.//motile_cell_migration_speed').text)
        self.motile_cell_relative_adhesion.value = float(uep.find('.//motile_cell_relative_adhesion').text)
        self.motile_cell_apoptosis_rate.value = float(uep.find('.//motile_cell_apoptosis_rate').text)
        self.motile_cell_relative_cycle_entry_rate.value = float(uep.find('.//motile_cell_relative_cycle_entry_rate').text)


    # Read values from the GUI widgets to enable editing XML
    def fill_xml(self, xml_root):
        uep = xml_root.find('.//user_parameters')  # find unique entry point into XML 
        uep.find('.//random_seed').text = str(self.random_seed.value)
        uep.find('.//use_defaults').text = str(self.use_defaults.value)
        uep.find('.//death_modelling').text = str(self.death_modelling.value)
        uep.find('.//diffusion_model').text = str(self.diffusion_model.value)
        uep.find('.//o2_Modelling').text = str(self.o2_Modelling.value)
        uep.find('.//diffusion_model_boundary').text = str(self.diffusion_model_boundary.value)
        uep.find('.//create_sphere').text = str(self.create_sphere.value)
        uep.find('.//o2_uptake_rate').text = str(self.o2_uptake_rate.value)
        uep.find('.//o2_boundary').text = str(self.o2_boundary.value)
        uep.find('.//cell_type').text = str(self.cell_type.value)
        uep.find('.//birth_rate_UCI101').text = str(self.birth_rate_UCI101.value)
        uep.find('.//death_rate_UCI101').text = str(self.death_rate_UCI101.value)
        uep.find('.//birth_rate_A2780').text = str(self.birth_rate_A2780.value)
        uep.find('.//death_rate_A2780').text = str(self.death_rate_A2780.value)
        uep.find('.//no_of_cells').text = str(self.no_of_cells.value)
        uep.find('.//drug').text = str(self.drug.value)
        uep.find('.//drug_diffusion_rate').text = str(self.drug_diffusion_rate.value)
        uep.find('.//drug_decay_rate').text = str(self.drug_decay_rate.value)
        uep.find('.//drug_boundary_condition').text = str(self.drug_boundary_condition.value)
        uep.find('.//Dirichlet').text = str(self.Dirichlet.value)
        uep.find('.//device_secretion_rate').text = str(self.device_secretion_rate.value)
        uep.find('.//add_device_secretion').text = str(self.add_device_secretion.value)
        uep.find('.//cell_radius').text = str(self.cell_radius.value)
        uep.find('.//death_rate_type').text = str(self.death_rate_type.value)
        uep.find('.//standard_deviation').text = str(self.standard_deviation.value)
        uep.find('.//motile_cell_persistence_time').text = str(self.motile_cell_persistence_time.value)
        uep.find('.//motile_cell_migration_speed').text = str(self.motile_cell_migration_speed.value)
        uep.find('.//motile_cell_relative_adhesion').text = str(self.motile_cell_relative_adhesion.value)
        uep.find('.//motile_cell_apoptosis_rate').text = str(self.motile_cell_apoptosis_rate.value)
        uep.find('.//motile_cell_relative_cycle_entry_rate').text = str(self.motile_cell_relative_cycle_entry_rate.value)
