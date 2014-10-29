import FWCore.ParameterSet.Config as cms

process = cms.Process("ANA")

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")



#input stuff for Run/Lumi selection with the "JSON"-formatted files from the PVT group
import FWCore.PythonUtilities.LumiList as LumiList


## Options and Output Report
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
        'file:/build/grimes/SLHC17_patch2+clean_shashlik_timing/step3_13839_aged_vHCalDepthClustering_noOOT.root'
                                )
                                )

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('pionPFAnalyzer_step3_13839_aged_vHCalDepthClustering_noOOT.root')
                                   )



process.load('Analysis.PFAnalyzers.pionPFAnalyzer_cfi')
process.load('RecoParticleFlow/PFClusterProducer/particleFlowRecHitHBHE_cfi')
process.load('RecoParticleFlow/PFClusterProducer/particleFlowClusterHBHE_cfi')

process.clusters = cms.Sequence(process.particleFlowRecHitHBHE+process.particleFlowClusterHBHE)

process.p = cms.Path(
    process.clusters+
    process.pionPFAnalyzer
    )

process.MessageLogger.cerr.FwkReport.reportEvery = 1000
