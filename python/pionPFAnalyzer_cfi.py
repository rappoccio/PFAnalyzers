import FWCore.ParameterSet.Config as cms


pionPFAnalyzer = cms.EDAnalyzer('PionPFAnalyzer',
                                dRMin = cms.double( 0.1 ),
                                jetSrc = cms.InputTag('ak5PFJets'),
                                clusterSrc = cms.InputTag('particleFlowClusterHBHE'),
                                genSrc = cms.InputTag('genParticles')
                                   )
