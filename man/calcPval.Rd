\name{calcPval}

\docType{methods}
\alias{calcPval}


\title{Calculates empirical P-values}


\description{
We propose a simple sampling scheme to verify significant outlier loci subject to local adaptation based on the distribution of the \eqn{\alpha_{I}} values observed after the MCMC iterations (approximated through a region-specific normal distribution \eqn{(N(\alpha_{I}))} without using a time consuming reversible jump model for testing the null hypotheses:\cr \cr
1. For each region \eqn{I}, sample a single value \eqn{x_{I}  \sim N(\alpha_{I})} and \eqn{y_{I}  \sim N(\alpha_{I})}, resulting in a distribution of sampled values \eqn{D_{x}} and \eqn{D_{y}} across regions.\cr \cr
2. For each region \eqn{I},  increment its counter \eqn{c_I} if \eqn{y_I} is above the \eqn{q-quantile} for \eqn{D_{x}}. \cr \cr
3. repeat (1-2) 1000 times \cr \cr
The empirical P-value for each \eqn{\alpha_{I}} is the number of times the sample \eqn{x_{I}} is greater than the user-defined significance level \eqn{q} (e.g., the 0.95 quantile) divided by the number of iterations (1000 times).
}

\usage{

calcPval(BlockFeST.result, q=0.95)

}

\arguments{

  \item{BlockFeST.result}{an object returned from the function BlockFeST}
  \item{q}{quantile}

} 

\value{
empirical P-values
}

\examples{

snps   <- system.file("extdata", "snps.txt", package="BlockFeST")
groups <- system.file("extdata", "groups.txt", package="BlockFeST")
BlockFeST.result <- BlockFeST(input=snps, GROUP=groups, nb=3, runtime=10)
P <- calcPval(BlockFeST.result)

}



\keyword{methods}
