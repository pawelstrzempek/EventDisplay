#!/bin/bash
    #-b means run i bach mode and -n means do not load rootlogon file. 

#the lines below work. But this same effect can be obtained using just root logong and typing gROOT->ProcessLine(".L ./TStrawMap.cpp+");
#root -b -l -n << EOF
#.L TStraw.cpp++ 
#.L TStrawsMap.cpp++ 
#.q
#EOF

root -l 'launchMacro.C'
