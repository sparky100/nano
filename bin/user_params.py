 
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

        param_name2 = Button(description='motile_cell_persistence_time', disabled=True, layout=name_button_layout)
        param_name2.style.button_color = 'tan'

        self.motile_cell_persistence_time = FloatText(
          value=15,
          step=1,
          style=style, layout=widget_layout)

        param_name3 = Button(description='motile_cell_migration_speed', disabled=True, layout=name_button_layout)
        param_name3.style.button_color = 'lightgreen'

        self.motile_cell_migration_speed = FloatText(
          value=0.25,
          step=0.01,
          style=style, layout=widget_layout)

        param_name4 = Button(description='motile_cell_relative_adhesion', disabled=True, layout=name_button_layout)
        param_name4.style.button_color = 'tan'

        self.motile_cell_relative_adhesion = FloatText(
          value=0.05,
          step=0.01,
          style=style, layout=widget_layout)

        param_name5 = Button(description='motile_cell_apoptosis_rate', disabled=True, layout=name_button_layout)
        param_name5.style.button_color = 'lightgreen'

        self.motile_cell_apoptosis_rate = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name6 = Button(description='motile_cell_relative_cycle_entry_rate', disabled=True, layout=name_button_layout)
        param_name6.style.button_color = 'tan'

        self.motile_cell_relative_cycle_entry_rate = FloatText(
          value=0.1,
          step=0.01,
          style=style, layout=widget_layout)

        units_button1 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button1.style.button_color = 'lightgreen'
        units_button2 = Button(description='min', disabled=True, layout=units_button_layout) 
        units_button2.style.button_color = 'tan'
        units_button3 = Button(description='micron/min', disabled=True, layout=units_button_layout) 
        units_button3.style.button_color = 'lightgreen'
        units_button4 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button4.style.button_color = 'tan'
        units_button5 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button5.style.button_color = 'lightgreen'
        units_button6 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button6.style.button_color = 'tan'

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

        row1 = [param_name1, self.random_seed, units_button1, desc_button1] 
        row2 = [param_name2, self.motile_cell_persistence_time, units_button2, desc_button2] 
        row3 = [param_name3, self.motile_cell_migration_speed, units_button3, desc_button3] 
        row4 = [param_name4, self.motile_cell_relative_adhesion, units_button4, desc_button4] 
        row5 = [param_name5, self.motile_cell_apoptosis_rate, units_button5, desc_button5] 
        row6 = [param_name6, self.motile_cell_relative_cycle_entry_rate, units_button6, desc_button6] 

        box_layout = Layout(display='flex', flex_flow='row', align_items='stretch', width='100%')
        box1 = Box(children=row1, layout=box_layout)
        box2 = Box(children=row2, layout=box_layout)
        box3 = Box(children=row3, layout=box_layout)
        box4 = Box(children=row4, layout=box_layout)
        box5 = Box(children=row5, layout=box_layout)
        box6 = Box(children=row6, layout=box_layout)

        self.tab = VBox([
          box1,
          box2,
          box3,
          box4,
          box5,
          box6,
        ])

    # Populate the GUI widgets with values from the XML
    def fill_gui(self, xml_root):
        uep = xml_root.find('.//user_parameters')  # find unique entry point into XML
        self.random_seed.value = int(uep.find('.//random_seed').text)
        self.motile_cell_persistence_time.value = float(uep.find('.//motile_cell_persistence_time').text)
        self.motile_cell_migration_speed.value = float(uep.find('.//motile_cell_migration_speed').text)
        self.motile_cell_relative_adhesion.value = float(uep.find('.//motile_cell_relative_adhesion').text)
        self.motile_cell_apoptosis_rate.value = float(uep.find('.//motile_cell_apoptosis_rate').text)
        self.motile_cell_relative_cycle_entry_rate.value = float(uep.find('.//motile_cell_relative_cycle_entry_rate').text)


    # Read values from the GUI widgets to enable editing XML
    def fill_xml(self, xml_root):
        uep = xml_root.find('.//user_parameters')  # find unique entry point into XML 
        uep.find('.//random_seed').text = str(self.random_seed.value)
        uep.find('.//motile_cell_persistence_time').text = str(self.motile_cell_persistence_time.value)
        uep.find('.//motile_cell_migration_speed').text = str(self.motile_cell_migration_speed.value)
        uep.find('.//motile_cell_relative_adhesion').text = str(self.motile_cell_relative_adhesion.value)
        uep.find('.//motile_cell_apoptosis_rate').text = str(self.motile_cell_apoptosis_rate.value)
        uep.find('.//motile_cell_relative_cycle_entry_rate').text = str(self.motile_cell_relative_cycle_entry_rate.value)
