import FWCore.ParameterSet.Config as cms


pionPFAnalyzer = cms.EDAnalyzer('PionPFAnalyzer',
                                dRMin = cms.double( 0.1 ),
                                jetSrc = cms.InputTag('ak4PFJetsCHS'),
                                clusterSrc = cms.InputTag('particleFlowClusterHCAL'),
                                genSrc = cms.InputTag('genParticles')
                                   )
