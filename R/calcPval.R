calcPval <- function(BlockFeST.result, q=0.95){

# Get the alpha values from the BlockFeST.result object
mean_alpha = BlockFeST.result@alpha
var_alpha  = BlockFeST.result@var_alpha
# Generate samples and calculate the empirical P-values
iter = 1000
P_values = numeric(length(mean_alpha))
inc = numeric(length(mean_alpha))
for (x in 1:iter){
 samples  = rnorm(rep(1,length(mean_alpha)),mean_alpha,sqrt(var_alpha))
 quantile = quantile(samples, q)
 samples2 = rnorm(rep(1,length(mean_alpha)),mean_alpha,sqrt(var_alpha))
 inc      = inc + (samples2>quantile)
}
P_values = inc/iter

return(P_values)

}



