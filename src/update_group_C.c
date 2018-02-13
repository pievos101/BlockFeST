#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

extern SEXP update_group(SEXP Roldalpha, SEXP Rwhatgroup, SEXP Rsubgroup, SEXP Regroup){

SEXP ret = R_NilValue;
SEXP Rvalue1;
SEXP Rvalue2;
SEXP Rvalue3;
SEXP Rvalue4;

int ngroups             = length(Rwhatgroup);
int nalpha              = length(Roldalpha);
int nsubgroup           = length(Rsubgroup);

Rvalue1                 = coerceVector(Roldalpha, REALSXP);
double *oldalpha        = REAL(Rvalue1);
Rvalue2                 = coerceVector(Rsubgroup, INTSXP);
int *subgroup           = INTEGER(Rvalue2);
Rvalue3                 = coerceVector(Regroup, REALSXP);
double *egroup          = REAL(Rvalue3);
Rvalue4                 = coerceVector(Rwhatgroup, INTSXP);
int *whatgroup          = INTEGER(Rvalue4);

PROTECT(Rvalue1);

for (int xx=0; xx<ngroups; xx++ ){

     // Find the group
     for ( int yy = 0; yy < nsubgroup ; yy ++ ){
        
         if(whatgroup[xx]==subgroup[yy]){
           oldalpha[yy] = egroup[xx];          
         }  
    
     }

}

//PROTECT(newalpha = allocVector(REALSXP,R_length(Roldalpha)));

UNPROTECT(1);

return Rvalue1;

}

// update alpha in the Jump Model
extern SEXP update_group_Jump(SEXP Ralpha, SEXP RGROUP, SEXP Rwhatgroup, SEXP Regroup){

SEXP ret = R_NilValue;
PROTECT(ret);

int nalpha  = length(Ralpha);
int ngroups = length(Rwhatgroup);

int *whatgroup    = INTEGER(Rwhatgroup);
int *GROUP        = INTEGER(RGROUP);
double *alpha     = REAL(Ralpha);
double *egroup    = REAL(Regroup);
int start = 0;

for (int xx=0; xx<ngroups; xx++ ){
        
	for (int yy=start; yy<nalpha; yy++){
         
		if(whatgroup[xx]==GROUP[yy]){

			alpha[yy] = egroup[xx];
			start = yy;

		}

	}
}

UNPROTECT(1);

return ret;

}

// update alpha in the Jump Model
extern SEXP update_group_Jump2(SEXP Rdalpha, SEXP Roldalpha, SEXP RGROUP, SEXP Rgroupid, SEXP Ralphaincluded){

SEXP ret = R_NilValue;
PROTECT(ret);

int nalpha  = length(Rdalpha);
int ngroups = length(Rgroupid);

int    *groupid        = INTEGER(Rgroupid);
int    *GROUP          = INTEGER(RGROUP);
double *dalpha         = REAL(Rdalpha);
double *oldalpha       = REAL(Roldalpha);
//double *alphaincluded  = REAL(Ralphaincluded);
int start =  0;

for (int xx=0; xx<ngroups; xx++ ){
        
	for (int yy=start; yy<nalpha; yy++){
         
		if(groupid[xx]==GROUP[yy]){

			dalpha[yy]        = oldalpha[yy];
			// switch state 
			LOGICAL(Ralphaincluded)[yy] = !LOGICAL(Ralphaincluded)[yy];
			start = yy;
		}

	}
}

UNPROTECT(1);

return ret;

}

// update alpha in the Jump Model
extern SEXP update_group_JumpX(SEXP Ralpha, SEXP RGROUP, SEXP Rwhatgroup, SEXP Regroup){

SEXP ret = R_NilValue;
PROTECT(ret);

int nalpha  = length(Ralpha);
int ngroups = length(Rwhatgroup);

int *whatgroup    = INTEGER(Rwhatgroup);
int *GROUP        = INTEGER(RGROUP);
double *alpha     = REAL(Ralpha);
double *egroup    = REAL(Regroup);

for (int xx=0; xx<ngroups; xx++ ){
        
	for (int yy=0; yy<nalpha; yy++){
         
		if(whatgroup[xx]==GROUP[yy]){

			alpha[yy] = alpha[yy] + egroup[xx];

		}

	}
}

UNPROTECT(1);

return ret;

}



