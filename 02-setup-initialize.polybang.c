//
//  polybang.c
//  PolyBang
//
//  Created by hdez on 7/8/16.
//  Copyright © 2016 hdez. All rights reserved.
//

//Get the Pure Data headers from: https://github.com/pure-data/pure-data/blob/master/src/m_pd.h
#include "m_pd.h"

//Create a static pointer to the class; it will be initialized in the _setup() method
static t_class *polybang_class;

//Carve out memory for the class data model and typdef it
typedef struct _polybang {
    t_object    x_obj;
    t_int       init_count, current_count;
    t_int       mod_A, mod_B;
} t_polybang;

//The _new method is a class constructor
//It is required to be named [filename]_new()
void *polybang_new(void){
    //Create an instance of the polybang class
    t_polybang *x = (t_polybang *)pd_new(polybang_class);
    
    //Return the instance
    return (void *)x;
}

//The _setup method initializes the class in memory
//This method is the place where class behaviors are added
//It is required to be named [filename]_setup()
void polybang_setup(void){
    //Initialize the class
    polybang_class = class_new(gensym("polybang"), //the name we'll type in PD for this object
                               (t_newmethod)polybang_new, // initializer method
                               (t_method)polybang_free, // free method
                               sizeof(t_polybang), // how much space this object will take up in mem
                               CLASS_DEFAULT, //how the object looks visually
                               A_DEFFLOAT, //A of A:B - first arg 
                               A_DEFFLOAT, //B of A:B - second arg
                               0); // 0 denotes end of args
}
