#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

extern SEXP update_group(SEXP Roldalpha, SEXP Rwhatgroup, SEXP Rsubgroup, SEXP Regroup){

SEXP ret = R_NilValue;
SEXP Rvalue1 = R_NilValue;
SEXP Rvalue2 = R_NilValue;
SEXP Rvalue3 = R_NilValue;
SEXP Rvalue4 = R_NilValue;

int ngroups             = length(Rwhatgroup);
int nalpha              = length(Roldalpha);
int nsubgroup           = length(Rsubgroup);

Rvalue1                 = coerceVector(Roldalpha, REALSXP);
PROTECT(Rvalue1);
double *oldalpha        = REAL(Rvalue1);
Rvalue2                 = coerceVector(Rsubgroup, INTSXP);
PROTECT(Rvalue2);
int *subgroup           = INTEGER(Rvalue2);
Rvalue3                 = coerceVector(Regroup, REALSXP);
PROTECT(Rvalue3);
double *egroup          = REAL(Rvalue3);
Rvalue4                 = coerceVector(Rwhatgroup, INTSXP);
PROTECT(Rvalue4);
int *whatgroup          = INTEGER(Rvalue4);



for (int xx=0; xx<ngroups; xx++ ){

     // Find the group
     for ( int yy = 0; yy < nsubgroup ; yy ++ ){
        
         if(whatgroup[xx]==subgroup[yy]){
           oldalpha[yy] = egroup[xx];          
         }  
    
     }

}

//PROTECT(newalpha = allocVector(REALSXP,R_length(Roldalpha)));

UNPROTECT(4);

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



