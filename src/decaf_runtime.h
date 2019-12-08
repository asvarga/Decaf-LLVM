/************************************************************************/
/*									*/
/*		decaf_runtime.h 					*/
/*									*/
/*	Run time header file for DECAF programs 			*/
/*									*/
/************************************************************************/


#ifndef DECAF_RUNTIME_ALREADY_INCLUDED
#define DECAF_RUNTIME_ALREADY_INCLUDED




#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/************************************************************************/
/*									*/
/*	Generic object							*/
/*									*/
/************************************************************************/


struct __Object {
   void * v_table;
};


typedef struct __Object *	Object;



/************************************************************************/
/*									*/
/*	Strings 							*/
/*									*/
/************************************************************************/


struct __String {
   void * v_table;
   char contents[1];
};


typedef struct __String *	String;




/************************************************************************/
/*									*/
/*	IO								*/
/*									*/
/************************************************************************/


struct __IO {
   void * v_table;
};


typedef struct __IO *		IO;



/************************************************************************/
/*									*/
/*	Arrays								*/
/*									*/
/************************************************************************/


struct __ARRAY {
   int length;
   char data[1];
};


typedef struct __ARRAY *	ARRAY;


#endif


/* end of decaf_runtime.h */
