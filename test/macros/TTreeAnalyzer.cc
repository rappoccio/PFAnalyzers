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
void Analyze(TFile* infile, TString outfile) {
  
  TTree *tree = (TTree*)infile->Get("pionPFAnalyzer/pfClusterTree");
  Int_t nn = tree->GetEntriesFast();
  float energy_input[10000];
  float time_input[10000];
  Int_t depth_input[10000];
  Int_t layer_input[10000];
  //cout << "11111111!" << endl;
  tree->SetBranchAddress("energy_input",energy_input);
  tree->SetBranchAddress("time_input",time_input);
  tree->SetBranchAddress("depth_input",depth_input);
  tree->SetBranchAddress("layer_input",layer_input);

  TH2F* e_v_t_1HB = new TH2F("e_v_t_1HB"," energy v time depth 1", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_2HB = new TH2F("e_v_t_2HB"," energy v time depth 2", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_3HB = new TH2F("e_v_t_3HB"," energy v time depth 3", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_4HB = new TH2F("e_v_t_4HB"," energy v time depth 4", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_5HB = new TH2F("e_v_t_5HB"," energy v time depth 5", 20, 0, 1000, 60, -30, 30);

  TH2F* e_v_t_1HE = new TH2F("e_v_t_1HE"," energy v time depth 1", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_2HE = new TH2F("e_v_t_2HE"," energy v time depth 2", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_3HE = new TH2F("e_v_t_3HE"," energy v time depth 3", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_4HE = new TH2F("e_v_t_4HE"," energy v time depth 4", 20, 0, 1000, 60, -30, 30);
  TH2F* e_v_t_5HE = new TH2F("e_v_t_5HE"," energy v time depth 5", 20, 0, 1000, 60, -30, 30);

  TH2F* HBHists[] = {e_v_t_1HB, e_v_t_2HB, e_v_t_3HB, e_v_t_4HB, e_v_t_5HB} ;
  TH2F* HEHists[] = {e_v_t_1HE, e_v_t_2HE, e_v_t_3HE, e_v_t_4HE, e_v_t_5HE} ;

  for ( int i = 0; i < 5; ++i) { HBHists[i]->UseCurrentStyle();HEHists[i]->UseCurrentStyle(); }

  for (Int_t i=0; i< nn; i++){
    tree->GetEvent(i);
    Int_t j = 0;
    //cout << "3" << endl;
    while( j < 10000 && energy_input[j] > 0.0001 ){//NEED TO USE LAYER TO FIGURE OUT DETECTOR

      
      if ( layer_input[j] == 1 ) {
	if(depth_input[j] == 1)
	  e_v_t_1HB->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 2)
	  e_v_t_2HB->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 3)
	  e_v_t_3HB->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 4)
	  e_v_t_4HB->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 5)
	  e_v_t_5HB->Fill( energy_input[j], time_input[j] ); 

      }
      else {
	if(depth_input[j] == 1)
	  e_v_t_1HE->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 2)
	  e_v_t_2HE->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 3)
	  e_v_t_3HE->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 4)
	  e_v_t_4HE->Fill( energy_input[j], time_input[j] );
	else if(depth_input[j] == 5)
	  e_v_t_5HE->Fill( energy_input[j], time_input[j] ); 

      }

      j++;
    }
    //cout << "4" << endl;
    
    //cout << "energy: " << energy[0] << endl;
  }
  TCanvas * c[5][2];

  for ( int i = 0; i < 5; ++i ) {
    TString ii; ii.Form("%d", i);
    TCanvas * c1 = new TCanvas("c1" + TString(ii), "c1" + TString(ii));
    HBHists[i]->Draw("box");
    c1->Print(outfile + TString("_HB_") + TString(ii) + TString(".pdf") );
    c1->Print(outfile + TString("_HB_") + TString(ii) + TString(".png") );
    TCanvas * c2 = new TCanvas("c2" + TString(ii), "c2" + TString(ii));
    HEHists[i]->Draw("box");
    c2->Print(outfile + TString("_HE_") + TString(ii) + TString(".pdf") );
    c2->Print(outfile + TString("_HE_") + TString(ii) + TString(".png") );

    c[i][0] = c1;
    c[i][1] = c2;
  }

  TFile f(outfile + TString(".root"),"recreate");
  e_v_t_1HB->Write();
  e_v_t_2HB->Write();
  e_v_t_3HB->Write();
  e_v_t_4HB->Write();
  e_v_t_5HB->Write();
  e_v_t_1HE->Write();
  e_v_t_2HE->Write();
  e_v_t_3HE->Write();
  e_v_t_4HE->Write();
  e_v_t_5HE->Write();
  return;
}
