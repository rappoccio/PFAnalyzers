#include <TTree.h>
#include <TFile.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <TROOT.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TF2.h>
#include <TH2D.h>
#include <sstream>
//#include "TH1D.h"
#include "TFile.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
using namespace std;

void TTreeAnalyzer(){
  cout << "Analyze(file,'outname_for_root') " << endl;
  return;
}

void Analyze(TTree * tree, TString outfile) {
  Int_t nn = tree->GetEntries();
  float energy_input[10000];
  float time_input[10000];
  Int_t depth_input[10000];
  Int_t layer_input[10000];
  //cout << "11111111!" << endl;
  tree->SetBranchAddress("energy_input",energy_input);
  tree->SetBranchAddress("time_input",time_input);
  tree->SetBranchAddress("depth_input",depth_input);
  tree->SetBranchAddress("layer_input",layer_input);

  TH2F* e_v_t_1HB = new TH2F("e_v_t_1HB"," energy v time depth 1", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_2HB = new TH2F("e_v_t_2HB"," energy v time depth 2", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_3HB = new TH2F("e_v_t_3HB"," energy v time depth 3", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_4HB = new TH2F("e_v_t_4HB"," energy v time depth 4", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_5HB = new TH2F("e_v_t_5HB"," energy v time depth 5", 100, 0, 1000, 60, -30, 30);

  TH2F* e_v_t_1HE = new TH2F("e_v_t_1HE"," energy v time depth 1", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_2HE = new TH2F("e_v_t_2HE"," energy v time depth 2", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_3HE = new TH2F("e_v_t_3HE"," energy v time depth 3", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_4HE = new TH2F("e_v_t_4HE"," energy v time depth 4", 100, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_5HE = new TH2F("e_v_t_5HE"," energy v time depth 5", 100, 0, 1000, 60, -30, 30);

  TH1F* t_1HB = new TH1F("t_1HB","time depth 1", 60, -30, 30);
  TH1F* t_2HB = new TH1F("t_2HB","time depth 2", 60, -30, 30);
  TH1F* t_3HB = new TH1F("t_3HB","time depth 3", 60, -30, 30);
  TH1F* t_4HB = new TH1F("t_4HB","time depth 4", 60, -30, 30);
  TH1F* t_5HB = new TH1F("t_5HB","time depth 5", 60, -30, 30);

  TH1F* t_1HE = new TH1F("t_1HE","time depth 1", 60, -30, 30);
  TH1F* t_2HE = new TH1F("t_2HE","time depth 2", 60, -30, 30);
  TH1F* t_3HE = new TH1F("t_3HE","time depth 3", 60, -30, 30);
  TH1F* t_4HE = new TH1F("t_4HE","time depth 4", 60, -30, 30);
  TH1F* t_5HE = new TH1F("t_5HE","time depth 5", 60, -30, 30);



  TH2F* HBHists[]   = {e_v_t_1HB, e_v_t_2HB, e_v_t_3HB, e_v_t_4HB, e_v_t_5HB} ;
  TH2F* HEHists[]   = {e_v_t_1HE, e_v_t_2HE, e_v_t_3HE, e_v_t_4HE, e_v_t_5HE} ;
  TH1F* HBHists1d[] = {t_1HB, t_2HB, t_3HB, t_4HB, t_5HB} ;
  TH1F* HEHists1d[] = {t_1HE, t_2HE, t_3HE, t_4HE, t_5HE} ;



  for ( int i = 0; i < 5; ++i) { 
    HBHists[i]->UseCurrentStyle();
    HEHists[i]->UseCurrentStyle(); 
    HBHists1d[i]->UseCurrentStyle();
    HEHists1d[i]->UseCurrentStyle(); 
  }

  for (Int_t i=0; i< nn; i++){
    if ( i %1000 == 0 )
      std::cout << "Processing " << i << " / " << nn << std::endl;
    tree->GetEvent(i);
    Int_t j = 0;
    //cout << "3" << endl;
    while( j < 10000 && energy_input[j] > 0.0001 ){//NEED TO USE LAYER TO FIGURE OUT DETECTOR

      if ( depth_input[j] <= 0 || depth_input[j] >= 5 ) {
	++j;
	continue;
      }
      
      if ( layer_input[j] == 1 ) {
	HBHists[ depth_input[j] - 1]->Fill( energy_input[j], time_input[j] );
	HBHists1d[ depth_input[j] - 1]->Fill( time_input[j] );
      }
      else {
	HEHists[ depth_input[j] - 1]->Fill( energy_input[j], time_input[j] );
	HEHists1d[ depth_input[j] - 1]->Fill( time_input[j] );
      }

      j++;
    }
    //cout << "4" << endl;
    
    //cout << "energy: " << energy[0] << endl;
  }

  TFile f(outfile + TString(".root"),"recreate");

  for ( int i = 0; i < 5; ++i ) {
    HBHists[i]->Write();
    HEHists[i]->Write();
    HBHists1d[i]->Write();
    HEHists1d[i]->Write();
  }

  f.Close();
  return;
}

void Analyze(TFile* infile, TString outfile) {
  
  TTree *tree = (TTree*)infile->Get("pionPFAnalyzer/pfClusterTree");
  Analyze( tree, outfile );
}

