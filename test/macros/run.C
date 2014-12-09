gSystem->CompileMacro("TTreeAnalyzer.cc", "k");
TChain * t = new TChain("pionPFAnalyzer/pfClusterTree");
t->Add("/eos/uscms/store/user/rappocc/RelValQCDForPF_14TeV/crab_PFClusterTimingQCD3/141209_172801/0000/pionPFAnalyzer_QCD_*.root");
Analyze(t, "PU");
