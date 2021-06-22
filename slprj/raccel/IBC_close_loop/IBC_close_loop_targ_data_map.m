  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 60;
      section.data(60)  = dumData; %prealloc
      
	  ;% rtP.alp
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP._Fs
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.PIDController_I
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.PIDController1_I
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.PIDController1_InitialConditionForIntegrator
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.PIDController_InitialConditionForIntegrator
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.PIDController1_P
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.PIDController_P
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.IBC_Vin
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.RepeatingSequence_rep_seq_y
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.RepeatingSequence1_rep_seq_y
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% rtP.RepeatingSequence2_rep_seq_y
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtP.RepeatingSequence4_rep_seq_y
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% rtP.Constant_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% rtP.StateSpace_AS_param
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% rtP.StateSpace_BS_param
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 38;
	
	  ;% rtP.StateSpace_CS_param
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 90;
	
	  ;% rtP.StateSpace_DS_param
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 158;
	
	  ;% rtP.StateSpace_X0_param
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 379;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 383;
	
	  ;% rtP.LookUpTable1_bp01Data
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 384;
	
	  ;% rtP.TransportDelay1_InitOutput
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 387;
	
	  ;% rtP.TransportDelay2_InitOutput
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 388;
	
	  ;% rtP.Gain_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 389;
	
	  ;% rtP.donotdeletethisgain_Gain_dojjjvjkoc
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 390;
	
	  ;% rtP.Saturation1_UpperSat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 391;
	
	  ;% rtP.Saturation1_LowerSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 392;
	
	  ;% rtP.donotdeletethisgain_Gain_fy4vzgl50q
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 393;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 394;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 395;
	
	  ;% rtP.donotdeletethisgain_Gain_cswjbtqcc2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 396;
	
	  ;% rtP.donotdeletethisgain_Gain_nwj215l5x1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 397;
	
	  ;% rtP.Step_Time
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 398;
	
	  ;% rtP.Step_Y0
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 399;
	
	  ;% rtP.Step_YFinal
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 400;
	
	  ;% rtP.Switch_Threshold
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 401;
	
	  ;% rtP.donotdeletethisgain_Gain_cthxcecbau
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 402;
	
	  ;% rtP.donotdeletethisgain_Gain_ctalfroa4m
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 403;
	
	  ;% rtP.donotdeletethisgain_Gain_o54pdurymu
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 404;
	
	  ;% rtP.LookUpTable1_bp01Data_p4fekf0sau
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 405;
	
	  ;% rtP.LookUpTable1_bp01Data_eancggqfkt
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 408;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 411;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 412;
	
	  ;% rtP.LookUpTable1_bp01Data_fwaln5kcoo
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 413;
	
	  ;% rtP.SineWave1_Amp
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 416;
	
	  ;% rtP.SineWave1_Bias
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 417;
	
	  ;% rtP.SineWave1_Freq
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 418;
	
	  ;% rtP.SineWave1_Phase
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 419;
	
	  ;% rtP.TransferFcn1_A
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 420;
	
	  ;% rtP.TransferFcn1_C
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 422;
	
	  ;% rtP.SwitchCurrents_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 424;
	
	  ;% rtP.Constant_Value_oa4sl44jdq
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 433;
	
	  ;% rtP.Constant_Value_dsqxhplhg3
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 434;
	
	  ;% rtP.eee_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 435;
	
	  ;% rtP.eee_Value_pohmtfwesc
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 436;
	
	  ;% rtP.eee_Value_jlbhkxjaia
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 437;
	
	  ;% rtP.Constant_Value_gsv0vdx1vo
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 438;
	
	  ;% rtP.Constant_Value_gdp532zjna
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 439;
	
	  ;% rtP.Constant_Value_otf0qt4owd
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 440;
	
	  ;% rtP.Constant_Value_gwvmohj4ou
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 441;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.mpxykrjyje._Y0
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.bbl254ocw35._Y0
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% rtB.agn4x3drjs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.irxwz2klfa
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 17;
	
	  ;% rtB.idzaeea1lj
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 26;
	
	  ;% rtB.jirgucywty
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% rtB.njyqw3gypd
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% rtB.krjlzhi2hw
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% rtB.dvjrtmyu4l
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% rtB.eekajp3dsw
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 33;
	
	  ;% rtB.g4ttm0jd3j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 34;
	
	  ;% rtB.cy0apjvkno
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 35;
	
	  ;% rtB.eitgvaqdla
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 36;
	
	  ;% rtB.f5grkow3lv
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 37;
	
	  ;% rtB.amqaipqoht
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 38;
	
	  ;% rtB.jj5htd1qpd
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 39;
	
	  ;% rtB.iqodxjvqjm
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 40;
	
	  ;% rtB.pkdqnlyvhd
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 41;
	
	  ;% rtB.iyxr5frzyq
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 42;
	
	  ;% rtB.dpijkcpfpb
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 43;
	
	  ;% rtB.eh0txmg2mg
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 44;
	
	  ;% rtB.mwfeqafa0o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 45;
	
	  ;% rtB.hac1mxz2pn
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 46;
	
	  ;% rtB.opwmy0qdum
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 47;
	
	  ;% rtB.hvbnfudyrr
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 48;
	
	  ;% rtB.mcgxsf0lqd
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 49;
	
	  ;% rtB.ekt10g5oul
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 50;
	
	  ;% rtB.g3iapqckrv
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 51;
	
	  ;% rtB.kagelnoork
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 52;
	
	  ;% rtB.jmnr504r1m
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 53;
	
	  ;% rtB.nhlx1d2f35
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 54;
	
	  ;% rtB.i1ollxafrx
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 55;
	
	  ;% rtB.hofz3ldwny
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 56;
	
	  ;% rtB.gjh4vpxeef
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.dphockrl25
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.cibd5iyhfd
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.pl55r2bbaf
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.mpxykrjyje.p5wwiu03ls
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.bbl254ocw35.p5wwiu03ls
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.ezqniqrzfs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gkp3oik3j1.modelTStart
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtDW.lb0zviipkc.modelTStart
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtDW.izbfxxh1df.modelTStart
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtDW.dovginqio5.AS
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.kgdautj2em.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.i2wglovkhg.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.bwajcs0k3f.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.mwrrp12s1e.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtDW.cphqenwi0j.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDW.g4u2peeyzh.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtDW.hcwvjzomrk.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 15;
	
	  ;% rtDW.jnbhswzni2.LoggedData
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 17;
	
	  ;% rtDW.mddrxtspjz.LoggedData
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 19;
	
	  ;% rtDW.pn4hj5ts5w.LoggedData
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 22;
	
	  ;% rtDW.l5cuukvckv.LoggedData
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 23;
	
	  ;% rtDW.lvwscoupef.LoggedData
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 26;
	
	  ;% rtDW.cv4dngi50w.TUbufferPtrs
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 30;
	
	  ;% rtDW.gln2uf24nm.LoggedData
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% rtDW.mdhj3jmr2m
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bhyxixrkat.Tail
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 11;
	
	  ;% rtDW.f0mexgzhmf.Tail
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtDW.aqlhy4dn2h.Tail
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtDW.ckvi3kfspw
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtDW.lrunokatih
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtDW.duktatxh0g
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.cf10juf2yd
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.m1ehop2vyv
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ers0xtszdu
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.juaxs13w1s
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.mpxykrjyje.jyt15m5n5h
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.bbl254ocw35.jyt15m5n5h
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 929389569;
  targMap.checksum1 = 2019389511;
  targMap.checksum2 = 1737148957;
  targMap.checksum3 = 3003249467;

