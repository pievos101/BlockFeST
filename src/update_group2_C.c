#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

extern SEXP update_group2(SEXP Rgroupid, SEXP RGROUP, SEXP Rdalpha, SEXP Rnewalpha, SEXP Raccalpha){

SEXP ret = R_NilValue;
PROTECT(ret);


int ngroups             = length(RGROUP);
//int nalpha            = length(Roldalpha);
int nsubgroups          = length(Rgroupid);

int *groupid            = INTEGER(Rgroupid);
int *GROUP              = INTEGER(RGROUP);
double *dalpha          = REAL(Rdalpha);
double *newalpha        = REAL(Rnewalpha);
double *accalpha        = REAL(Raccalpha);
int start		= 0;

for (int xx=0; xx<nsubgroups; xx++ ){
     // Find the group
     for ( int yy = start; yy < ngroups ; yy ++ ){
        
         if(groupid[xx]==GROUP[yy]){
           dalpha[yy]  = newalpha[yy];
           accalpha[yy]= accalpha[yy] + 1;         
	   start = yy;	
         }  
    
     }

}
    

UNPROTECT(1);

return ret;

}


