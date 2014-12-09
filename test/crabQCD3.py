from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName=  'PFClusterTimingQCD3'
config.General.workArea = 'PFAnalyzer_Files'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'new.py'

config.section_("Data")
config.Data.inputDataset = '/RelValQCDForPF_14TeV/CMSSW_6_2_0_SLHC20_patch1-PU_DES23_62_V1_UPG23SHcalib-v1/GEN-SIM-RECO'
#config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 5
#config.Data.totalUnits = -1
config.Data.ignoreLocality = True
#config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions12/8TeV/Prompt/Cert_190456-208686_8TeV_PromptReco_Collisions12_JSON.txt'
#config.Data.runRange = '193093-193999' # '193093-194075'
#config.Data.outLFN = 'crab3QCD3' # or '/store/group/<subdir>'
config.Data.publication = False
#config.Data.publishDataName = 'CRAB3_tutorial_Data_analysis_test5'

config.section_("Site")
config.Site.storageSite = 'T3_US_FNALLPC'
