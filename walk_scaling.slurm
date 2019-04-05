#!/bin/bash
# SLURM submission script for multiple serial jobs on Teach
#
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=16
#SBATCH --time=4:00:00
#SBATCH --job-name ants-serial16
 
# Load modules
module load gcc hdf5 netcdf boost gnu-parallel
 
# DIRECTORY TO RUN - $SLURM_SUBMIT_DIR is the directory from which the job was submitted
cd $SLURM_SUBMIT_DIR
  
# EXECUTION COMMAND 
parallel --joblog runs_walk.log -j 1 --no-run-if-empty < subjobs_walkring



