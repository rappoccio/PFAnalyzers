# Auto generated configuration file
# using: 
# Revision: 1.20 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step2 --filein file:JME-Upg2023SHCAL14DR-00001_step1.root --fileout file:JME-Upg2023SHCAL14DR-00001.root --pileup_input dbs:/MinBias_TuneZ2star_14TeV-pythia6/Upg2023SHCAL14-DES23_62_V1-v1/GEN-SIM --mc --eventcontent RECOSIM --pileup AVE_140_BX_25ns --customise SLHCUpgradeSimulations/Configuration/combinedCustoms.cust_2023SHCal,Configuration/DataProcessing/Utils.addMonitoring --datatier GEN-SIM-RECO --conditions PH2_1K_FB_V4::All --step RAW2DIGI,L1Reco,RECO --magField 38T_PostLS1 --geometry Extended2023SHCalNoTaper,Extended2023SHCalNoTaperReco --python_filename JME-Upg2023SHCAL14DR-00001_2_cfg.py --no_exec -n 3
import FWCore.ParameterSet.Config as cms

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

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring('file:/tmp/bachtis/oot.root')
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
    outputCommands = cms.untracked.vstring("keep *_*_*_*"),                                         
    fileName = cms.untracked.string('file:/tmp/bachtis/oot2.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN-SIM-RECO')
    )
)

# Additional output definition

# Other statements
process.mix.input.nbPileupEvents.averageNumber = cms.double(140.000000)
process.mix.bunchspace = cms.int32(25)
process.mix.minBunch = cms.int32(-12)
process.mix.maxBunch = cms.int32(3)
process.mix.input.fileNames = cms.untracked.vstring(['/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/00077CBD-9831-E411-978B-001E6739CFA9.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/002CF98D-8531-E411-B60C-60EB69BAC99A.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/00814409-9731-E411-A424-003048CDC922.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/0084FE94-8531-E411-9E78-0025B3203778.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/009AB11D-8931-E411-9B9F-E0CB4E1A1145.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/00B689C8-9E31-E411-9DEA-02163E00F524.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/00C26096-9831-E411-91EB-002590A37122.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/00E3D6A8-8031-E411-A1C8-003048947BB9.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/022B0198-9031-E411-AE25-0025901FB0CE.root', '/store/mc/Upg2023SHCAL14/MinBias_TuneZ2star_14TeV-pythia6/GEN-SIM/DES23_62_V1-v1/10000/022DA5FD-9D31-E411-B9DF-0025904C7F5C.root'])
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'PH2_1K_FB_V4::All', '')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.particleFlowCluster)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.reconstruction_step,process.endjob_step,process.RECOSIMoutput_step)

# customisation of the process.

# Automatic addition of the customisation function from SLHCUpgradeSimulations.Configuration.combinedCustoms
from SLHCUpgradeSimulations.Configuration.combinedCustoms import cust_2023SHCal 

#call to customisation function cust_2023SHCal imported from SLHCUpgradeSimulations.Configuration.combinedCustoms
process = cust_2023SHCal(process)

# Automatic addition of the customisation function from Configuration.DataProcessing.Utils
from Configuration.DataProcessing.Utils import addMonitoring 

#call to customisation function addMonitoring imported from Configuration.DataProcessing.Utils
process = addMonitoring(process)

# End of customisation functions
