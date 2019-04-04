% Date: April 3, 2019
% Author: Stewart Pearson 
% Description: Matlab script for Assignment 9 which plots the scaling for
% the diffring and montecarlo ring and displays the respective serial
% fraction f

clear all;

% Data is formated in [#cores:time(s)]
diff_data =[16 469.027;
            15 464.875;
            14 506.029;
            13 534.003;
            12 510.029;
            11 543.924;
            10 555.214;
            9 597.852;
            8 591.155;
            7 608.849;
            6 616.524;
            5 621.652;
            4 630.479;
            3 639.849;
            2 663.032;
            1 710.118];
        
Ts_diff = diff_data(16,2);
Tp_diff = diff_data(1,2);
S_diff = Ts_diff/Tp_diff
f_diff = (1-S_diff/16)/(S_diff-S_diff/16)
        
% Plot diffring scaling
figure;
plot(diff_data(:,1), diff_data(:,2))
ylabel('Walltime (s)')
xlabel('OMP NUM THREADS')
title('Scaling analysis for diffring')

