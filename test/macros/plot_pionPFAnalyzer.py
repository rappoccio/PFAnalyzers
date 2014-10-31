#!/usr/bin/env python

from ROOT import TTree, TFile, AddressOf, gROOT, gDirectory, TH1F, TCanvas, TLegend
import numpy as np


pt1 = np.zeros(1, dtype=float)
pt2 = np.zeros(1, dtype=float)

f1 = TFile("pionPFAnalyzer.root")
f2 = TFile("pionPFAnalyzer_PU.root")

t1 = f1.Get("pionPFAnalyzer/pfRecHitTree")
t2 = f2.Get("pionPFAnalyzer/pfRecHitTree")

t1.Draw("reco_pt>>h_pt1(150,0,150)", "", "b")
h_pt1 = gDirectory.Get("h_pt1")
t2.Draw("reco_pt>>h_pt2(150,0,150)", "", "b")
h_pt2 = gDirectory.Get("h_pt2")

leg = TLegend(0.2, 0.5, 0.5, 0.8 )
leg.SetBorderSize(0)
leg.SetFillColor(0)

c = TCanvas("reco_pt", "reco_pt")
h_pt1.Sumw2()
h_pt1.Draw('hist')
leg.AddEntry(h_pt1, "No PU")
h_pt2.Sumw2()
h_pt1.SetLineColor(2)
h_pt2.Draw('hist same')
leg.AddEntry(h_pt2, "AVE_20_BX_25ns")
leg.Draw()

c.Print("reco_pt.png", "png")
c.Print("reco_pt.pdf", "pdf")
