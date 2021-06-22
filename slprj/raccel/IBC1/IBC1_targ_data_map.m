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
      section.nData     = 61;
      section.data(61)  = dumData; %prealloc
      
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
	
	  ;% rtP.donotdeletethisgain_Gain_cswjbtqcc2
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 391;
	
	  ;% rtP.donotdeletethisgain_Gain_nwj215l5x1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 392;
	
	  ;% rtP.donotdeletethisgain_Gain_fy4vzgl50q
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 393;
	
	  ;% rtP.Step_Time
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 394;
	
	  ;% rtP.Step_Y0
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 395;
	
	  ;% rtP.Step_YFinal
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 396;
	
	  ;% rtP.Switch_Threshold
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 397;
	
	  ;% rtP.donotdeletethisgain_Gain_cthxcecbau
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 398;
	
	  ;% rtP.donotdeletethisgain_Gain_ctalfroa4m
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 399;
	
	  ;% rtP.donotdeletethisgain_Gain_o54pdurymu
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 400;
	
	  ;% rtP.Saturation1_UpperSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 401;
	
	  ;% rtP.Saturation1_LowerSat
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 402;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 403;
	
	  ;% rtP.Saturation_LowerSat
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
	
	  ;% rtP.Constant1_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 434;
	
	  ;% rtP.Constant_Value_dsqxhplhg3
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 435;
	
	  ;% rtP.eee_Value
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 436;
	
	  ;% rtP.eee_Value_pohmtfwesc
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 437;
	
	  ;% rtP.eee_Value_jlbhkxjaia
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 438;
	
	  ;% rtP.Constant_Value_gsv0vdx1vo
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 439;
	
	  ;% rtP.Constant_Value_gdp532zjna
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 440;
	
	  ;% rtP.Constant_Value_otf0qt4owd
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 441;
	
	  ;% rtP.Constant_Value_gwvmohj4ou
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 442;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.adxwqzxxlf._Y0
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.hhoyo4a5hdp._Y0
	  section.data(1).logicalSrcIdx = 62;
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
      
	  ;% rtB.odazhmwpn0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.oukfsqx50f
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 17;
	
	  ;% rtB.avcatdltyc
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 26;
	
	  ;% rtB.otoroldxt1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% rtB.lhmqma0bj3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% rtB.pkmdbed0es
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% rtB.cl2qzwvkbj
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% rtB.c0t5jmfaeg
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 33;
	
	  ;% rtB.cwpjvxmr0i
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 34;
	
	  ;% rtB.l3f0j0025k
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 35;
	
	  ;% rtB.nkqprozo1a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 36;
	
	  ;% rtB.cruaxvmogz
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 37;
	
	  ;% rtB.h1gogwi5ku
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 38;
	
	  ;% rtB.bdou3bnea4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 39;
	
	  ;% rtB.bg2jknexx5
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 40;
	
	  ;% rtB.dpjtgbbiz2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 41;
	
	  ;% rtB.aadob0orwm
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 42;
	
	  ;% rtB.gqvdelah3i
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 43;
	
	  ;% rtB.hxoya3o5lr
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 44;
	
	  ;% rtB.j2wnh3irqk
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 45;
	
	  ;% rtB.d3eaa0fx0a
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 46;
	
	  ;% rtB.dzkiqmr43p
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 47;
	
	  ;% rtB.ar5fz2uoyk
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 48;
	
	  ;% rtB.myup1cfdlk
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 49;
	
	  ;% rtB.defpijlxd3
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 50;
	
	  ;% rtB.mczadyhg2m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 51;
	
	  ;% rtB.dzvsubkdwz
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 52;
	
	  ;% rtB.l1j1ioj0sv
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 53;
	
	  ;% rtB.lsx1razqc1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 54;
	
	  ;% rtB.ohzinl1asd
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 55;
	
	  ;% rtB.huhtwrsccb
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 56;
	
	  ;% rtB.hvvgc3xdmn
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.bn0ratt3ev
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.brs0dgmc1a
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.efbnt10xks
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.adxwqzxxlf.gqyueovf0x
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.hhoyo4a5hdp.gqyueovf0x
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
      
	  ;% rtDW.kbsai0di0v
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ih1wy1g0a5.modelTStart
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtDW.o5rvrjh2wy.modelTStart
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtDW.dcsgtlggye.modelTStart
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtDW.gr1muksbyf.AS
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.py4fwtjufu.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.layaov5mlt.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.e5i1astk5k.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.pidpl03h2e.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtDW.fwdaf2hwel.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDW.lg0040upns.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtDW.ijmd3pa0bm.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 15;
	
	  ;% rtDW.ntvjnhct52.LoggedData
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 17;
	
	  ;% rtDW.k4nfq4y0nz.LoggedData
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 19;
	
	  ;% rtDW.n10mme0d0t.LoggedData
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 22;
	
	  ;% rtDW.d1ypcdq1l4.LoggedData
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 23;
	
	  ;% rtDW.knbfx43f4o.LoggedData
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 26;
	
	  ;% rtDW.nmpmd1jh5e.TUbufferPtrs
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 30;
	
	  ;% rtDW.ezgsnm2ktm.LoggedData
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% rtDW.mld3hblakv
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.coigdooovo.Tail
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 11;
	
	  ;% rtDW.nen2ftgc0l.Tail
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtDW.lkazb3z1og.Tail
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtDW.dmdu1pxmxg
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtDW.bgqwuyroks
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtDW.mrajto30cb
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.hzzdjgpnti
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ovfa2w42nr
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.humgsssfcu
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.apgwaguobm
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.adxwqzxxlf.ikjnmtqwv0
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.hhoyo4a5hdp.ikjnmtqwv0
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


  targMap.checksum0 = 2765813247;
  targMap.checksum1 = 2697726608;
  targMap.checksum2 = 1612699770;
  targMap.checksum3 = 806894874;

