\name{GeneFeST}

\docType{methods}
\alias{GeneFeST}


\title{Bayesian calculation of gene-specific FST from genomic SNP data}


\description{

The method is based on the work from Beaumont and Balding (2004) where they introduce a FST-based hierarchical Bayesian model to detect loci that are subject to selection. In this Bayesian approach they use a logistic regression model to distinguish between locus-specific effects like selection and population-specific effects which are shared by all loci (e.g effects caused by migration rates) (Riebler, 2008). 
Foll and Gaggiotti (2008) extended this work using a reversible jump MCMC (Green, 1995) which enables testing the hypothesis that a locus is subject to selection; a very similar approach was developed in parallel by Riebler & Stefan (2008). The method is implemented in a software named BayeScan (http://cmpg.unibe.ch/software/BayeScan/). The new method introduced here is a modification of BayeScan (see details). 
}

\usage{

GeneFeST(input,GROUP=FALSE,nb.pilot=20,pilot.runtime=500,main.runtime=5000,
type=1,only.pilots=FALSE,h.average.P=0.2,h.step.width=1,mcmc.diag=FALSE,h=TRUE)

}

\arguments{

  \item{input}{textfile or an R-object returned from getBayes() provided by the R-package PopGenome}
  \item{GROUP}{SNP groups}
  \item{nb.pilot}{number of pilot runs}
  \item{pilot.runtime}{length of pilot runs}
  \item{main.runtime}{length of main runs} 
  \item{type}{1: one alpha one group, 2: most extrem alpha to label group}
  \item{only.pilots}{only pilot runs are performed}
  \item{h.average.P}{the expected probability that a gen is under selection}
  \item{h.step.width}{step width of the heuristic, see details !}
  \item{mcmc.diag}{the input for the R-package coda is returned after the pilot runs, Note: 'coda' is required !}
  \item{h}{if \code{h=FALSE} the \code{h.average.P} should be set like the \code{prior.odds} variable suggested by Foll & Gaggiotti}

} 

\value{

returned value is an object of class \code{"BAYESRETURN"} \cr \cr
-------------------------------------------------------------- \cr
Following Slots will be filled \cr
-------------------------------------------------------------- \cr

   \item{pilot.alpha}{alpha effects after pilot runs}
   \item{pilot.beta}{beta effects after pilot runs}
   \item{pilot.var_alpha}{variance of pilot alphas}
   \item{pilot.fst}{fst values after pilt runs}
   \item{pilot.P.norm}{alphas are fitted to a normal distribution after the pilot runs}
   \item{pilot.Q.norm}{Q values out of the normal distribution}
   \item{post.alpha}{posterior alpha}
   \item{post.fst}{posterior fst}
   \item{post.beta}{posterior beta}
   \item{post.P}{posterior P-values}
   \item{post.Q}{posterior Q-values}
   \item{region.names}{names of region}
}

\details{

Type of measurenments: \cr \cr
type 1: \cr
Our type 1 method considers all SNPs separately but is restricted to generate exactly one alpha 
for each gene (or group of SNPs). This approach assumes that all SNPs observed in one gene share the same genetic effect.
The type 1 method is default ! \cr \cr
type 2: \cr
To loosen up the condition that all SNPs in a gene are forced by the same selective pressure we 
provide an alternative approach which considers all SNPs separately, but sets no restrictions on 
the alphas of each SNP in a group. 
Basically this is exactly what BayeScan does in case of SNP data (Foll and Gaggiotti, 2008). However, to interpret a gene we 
label the gene with the most extreme alpha value in the corresponding group of SNPs. 
To calculate the posterior probabilities we again interpret the whole group of SNPs (genes). \cr \cr
Heuristic: \cr
We recognized that the type 1 method has good power to distinguish between balancing and positive selection
but produces rapid increasing posterior P-values. 
Instead of correcting this with normalization, e.g with the use of empirical functions, we introduce 
here a heuristic which controls the number of  included alphas during the jump model. A "h.average.P"  
variable takes the expected probability that a locus is under selection into account. 
We keep that value variable in order to adjust the average number of alphas included in the model during the reversible jump until an 
user-defined ratio (expected fraction of loci under selection=alpha included) is reached. The underlying algorithm logarithmically 
decreases the probability that a gene is subject to selection while it stays 100 iterations at each state to ensure good differentiation 
at the full P-value scale [0,1]. The step width can be tuned by the user. 
The ratio (n.genes.included/n.genes) is printed during the jump model. If \code{h=FALSE} the parameter \code{h.average.P} is treated like 
the \code{prior.odds} variable in BayeScan and should be set accordingly.
}

\references{ 
[1] Foll M and OE Gaggiotti (2008). \emph{A genome scan method to identify selected loci appropriate for both dominant and codominant markers: A Bayesian perspective.} Genetics 180: 977-993 \cr \cr
[2] Beaumont M, Balding D. 2004. \emph{Identifying adaptive genetic divergence among populations from genome scans}.Molecular Ecology. 13:969-980. \cr \cr
[3] Riebler A, Held L, Stephan W. 2008. \emph{Bayesian variable selection for detecting adaptive genomic differences among populations}. Genetics 178: 1817-1829 \cr \cr
[4] Green  PJ. 1995. \emph{Reversible jump Markov chain Monte Carlo computation and Bayesian model determination}. Biometrika 82: 711-732. \cr \cr

}
\examples{

# Example files can be found in the subdirectory "data".
# results <- GeneFeST(input="snps.txt", GROUP="groups.txt",prior.odds=0.1)
# Using the R-package PopGenome to generate the input
# install.packages("PopGenome")
# library(PopGenome)
# GENOME.class <- readData("Alignments")# Alignments is a folder 
# GENOME.class <- set.populations(GENOME.class, list(c(....),c(....)))
# input        <- getBayes(GENOME.class, snps=TRUE)
# results      <- GeneFeST(input)

}



\keyword{methods}
