% Date: April 3, 2019
% Author: Stewart Pearson 
% Description: Matlab script for Assignment 9 which plots the scaling for
% the diffring and montecarlo ring and displays the respective serial
% fraction f

clear all;

% Data is formated in [#cores:time(s)]
diff_data =[1 133.701;
            2 69.289;
            3 47.662;
            4 37.159;
            5 31.463;
            6 28.683;
            7 27.814;
            8 24.401;
            9 22.777;
            10 21.299;
            11 20.302;
            12 19.388;
            13 19.330;
            14 19.330;
            15 18.707;
            16 18.042];
walk_data =[1 81.910;
            2 45.399;
            3 32.988;
            4 25.272;
            5 20.980;
            6 18.803;
            7 17.777;
            8 16.084;
            9 14.467;
            10 13.338;	
            11 12.519;
            12 11.907;
            13 11.890;
            14 11.588;
            15 11.661;	
            16 10.967];

        
Ts_diff = diff_data(1,2);
Tp_diff = diff_data(16,2);
S_diff = Ts_diff/Tp_diff
f_diff = (1-S_diff/16)/(S_diff-S_diff/16)

Ts_walk = walk_data(1,2);
Tp_walk = walk_data(16,2);
S_walk = Ts_walk/Tp_walk
f_walk = (1-S_walk/16)/(S_walk-S_walk/16)
        
% Plot diffring scaling
figure;
plot(diff_data(:,1), diff_data(:,2))
ylabel('Walltime (s)')
xlabel('OMP NUM THREADS')
title('Scaling analysis for diffring')
        
% Plot walkring scaling
figure;
plot(walk_data(:,1), walk_data(:,2))
ylabel('Walltime (s)')
xlabel('OMP NUM THREADS')
title('Scaling analysis for walkring')

