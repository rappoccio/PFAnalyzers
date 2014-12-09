# Auto generated configuration file
# using: 
# Revision: 1.20 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step2 --filein file:JME-Upg2023SHCAL14DR-00001_step1.root --fileout file:JME-Upg2023SHCAL14DR-00001.root --pileup_input dbs:/MinBias_TuneZ2star_14TeV-pythia6/Upg2023SHCAL14-DES23_62_V1-v1/GEN-SIM --mc --eventcontent RECOSIM --pileup AVE_140_BX_25ns --customise SLHCUpgradeSimulations/Configuration/combinedCustoms.cust_2023SHCal,Configuration/DataProcessing/Utils.addMonitoring --datatier GEN-SIM-RECO --conditions PH2_1K_FB_V4::All --step RAW2DIGI,L1Reco,RECO --magField 38T_PostLS1 --geometry Extended2023SHCalNoTaper,Extended2023SHCalNoTaperReco --python_filename JME-Upg2023SHCAL14DR-00001_2_cfg.py --no_exec -n 3
import FWCore.ParameterSet.Config as cms
#from Configuration.AlCa.GlobalTag import GlobalTag

process = cms.Process('RECO2')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mix_POISSON_average_cfi')
process.load('Configuration.Geometry.GeometryExtended2023SHCalNoTaperReco_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_PostLS1_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#process.load('Configuration.Geometry.GeometryExtended2019Reco_cff')

#process.GlobalTag = GlobalTag process.GlobalTag, 'auto:upgrade2019', '')


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring('/store/relval/CMSSW_6_2_0_SLHC20_patch1/RelValQCDForPF_14TeV/GEN-SIM-RECO/DES23_62_V1_UPG23SHcalibNoPU-v1/00000/2449B660-AB71-E411-B0FD-02163E00E6F5.root')
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.20 $'),
    annotation = cms.untracked.string('step2 nevts:3'),
    name = cms.untracked.string('Applications')
)

# Output definition

process.RECOSIMoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = cms.untracked.vstring("drop *"),
    fileName = cms.untracked.string('oot2.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN-SIM-RECO')
    )
)


process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('pionPFAnalyzer_QCD.root')
                                   )



process.load('Analysis.PFAnalyzers.pionPFAnalyzer_cfi')
process.load('RecoParticleFlow/PFClusterProducer/particleFlowRecHitHBHE_cfi')
process.load('RecoParticleFlow/PFClusterProducer/particleFlowClusterHBHE_cfi')

process.clusters = cms.Sequence(process.particleFlowRecHitHBHE+process.particleFlowClusterHBHE)




# Other statements
process.mix.input.nbPileupEvents.averageNumber = cms.double(140.000000)
process.mix.bunchspace = cms.int32(25)
process.mix.minBunch = cms.int32(-12)
process.mix.maxBunch = cms.int32(3)
process.mix.input.fileNames = cms.untracked.vstring(['/store/RelVal/CMSSW_6_2_0_SLHC7/RelValMinBias_TuneZ2star_14TeV/GEN-SIM/DES19_62_V8_UPG2019-v2/00000/F29D1374-4590-E311-BEBE-002590494E40.root', '/store/RelVal/CMSSW_6_2_0_SLHC7/RelValMinBias_TuneZ2star_14TeV/GEN-SIM/DES19_62_V8_UPG2019-v2/00000/705AECA4-4C90-E311-843F-003048FEAEF0.root'])
#from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:upgrade2019', '')
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'PH2_1K_FB_V4::All', '')



# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.particleFlowCluster+process.pionPFAnalyzer)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.reconstruction_step,process.endjob_step,process.RECOSIMoutput_step)

# customisation of the process.

# Automatic addition of the customisation function from SLHCUpgradeSimulations.Configuration.combinedCustoms
from SLHCUpgradeSimulations.Configuration.combinedCustoms import cust_2023SHCal 
#from SLHCUpgradeSimulations.Configuration.combinedCustoms import cust_2019 
#call to customisation function cust_2023SHCal imported from SLHCUpgradeSimulations.Configuration.combinedCustoms
process = cust_2023SHCal(process)

# Automatic addition of the customisation function from Configuration.DataProcessing.Utils
from Configuration.DataProcessing.Utils import addMonitoring 

#call to customisation function addMonitoring imported from Configuration.DataProcessing.Utils
process = addMonitoring(process)

# End of customisation functions
