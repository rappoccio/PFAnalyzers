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
#include <TH1D.h>
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

  TH2F* e_v_t_1HB = new TH2F("e_v_t_1HB"," energy v time depth 1", 40, 0, 400, 50, -50, 50);
  TH2F* e_v_t_2HB = new TH2F("e_v_t_2HB"," energy v time depth 2", 40, 0, 400, 50, -50, 50);
  TH2F* e_v_t_3HB = new TH2F("e_v_t_3HB"," energy v time depth 3", 40, 0, 400, 50, -50, 50);
  
  

  TH2F* e_v_t_1HE = new TH2F("e_v_t_1HE"," energy v time depth 1", 40, 0, 400, 50, -50, 50);
  TH2F* e_v_t_2HE = new TH2F("e_v_t_2HE"," energy v time depth 2", 40, 0, 400, 50, -50, 50);
  TH2F* e_v_t_3HE = new TH2F("e_v_t_3HE"," energy v time depth 3", 40, 0, 400, 50, -50, 50);
  TH2F* e_v_t_4HE = new TH2F("e_v_t_4HE"," energy v time depth 4", 40, 0, 400, 50, -50, 50);
  TH2F* e_v_t_5HE = new TH2F("e_v_t_5HE"," energy v time depth 5", 40, 0, 400, 50, -50, 50);

  TH1F* time_1HB = new TH1F("time_1HB","time in depth 1", 50, -50, 50 ); 
  TH1F* time_2HB = new TH1F("time_2HB","time in depth 2", 50, -50, 50 );
  TH1F* time_3HB = new TH1F("time_3HB","time in depth 3", 50, -50, 50 );
  TH1F* time_1HE = new TH1F("time_1HE","time in depth 1", 50, -50, 50 );
  TH1F* time_2HE = new TH1F("time_2HE","time in depth 2", 50, -50, 50 );
  TH1F* time_3HE = new TH1F("time_3HE","time in depth 3", 50, -50, 50 );
  TH1F* time_4HE = new TH1F("time_4HE","time in depth 4", 50, -50, 50 );
  TH1F* time_5HE = new TH1F("time_5HE","time in depth 5", 50, -50, 50 );


  TH2F* HBHists[] = {e_v_t_1HB, e_v_t_2HB, e_v_t_3HB} ;
  TH2F* HEHists[] = {e_v_t_1HE, e_v_t_2HE, e_v_t_3HE, e_v_t_4HE, e_v_t_5HE} ;

  for ( int i = 0; i < 5; ++i) { if(i < 3) HBHists[i]->UseCurrentStyle();HEHists[i]->UseCurrentStyle(); }

  for (Int_t i=0; i< nn; i++){
    tree->GetEvent(i);
    Int_t j = 0;
    //cout << "3" << endl;
    while( j < 10000 && energy_input[j] > 0.0001 ){//NEED TO USE LAYER TO FIGURE OUT DETECTOR

      
      if ( layer_input[j] == 1 ) {
	if(depth_input[j] == 1){
	  e_v_t_1HB->Fill( energy_input[j], time_input[j] );
	  time_1HB->Fill( time_input[j] );
	}
	else if(depth_input[j] == 2){
	  e_v_t_2HB->Fill( energy_input[j], time_input[j] );
	  time_2HB->Fill( time_input[j] );
	}
	else if(depth_input[j] == 3){
	  e_v_t_3HB->Fill( energy_input[j], time_input[j] );
	  time_3HB->Fill( time_input[j] );
	}
      }
      else {
	if(depth_input[j] == 1){
	  e_v_t_1HE->Fill( energy_input[j], time_input[j] );
	  time_1HE->Fill( time_input[j] );
	}
	else if(depth_input[j] == 2){
	  e_v_t_2HE->Fill( energy_input[j], time_input[j] );
	  time_2HE->Fill( time_input[j] );
	}
	else if(depth_input[j] == 3){
	  e_v_t_3HE->Fill( energy_input[j], time_input[j] );
	  time_3HE->Fill( time_input[j] );
	}
	else if(depth_input[j] == 4){
	  e_v_t_4HE->Fill( energy_input[j], time_input[j] );
	  time_4HE->Fill( time_input[j] );
	}
	else if(depth_input[j] == 5){
	  e_v_t_5HE->Fill( energy_input[j], time_input[j] );
	  time_5HE->Fill( time_input[j] );
	} 

      }

      j++;
    }
    //cout << "4" << endl;
    
    //cout << "energy: " << energy[0] << endl;
  }

  //TCanvas * c[5][2];

  /*for ( int i = 0; i < 3; ++i ) {
    //TString ii; ii.Form("%d", i);
    //TCanvas * c1 = new TCanvas("c1" + TString(ii), "c1" + TString(ii));
    //HBHists[i]->Draw("box");
    //c1->Print(outfile + TString("_HB_") + TString(ii) + TString(".pdf") );
    //c1->Print(outfile + TString("_HB_") + TString(ii) + TString(".png") );
    //TCanvas * c2 = new TCanvas("c2" + TString(ii), "c2" + TString(ii));
    //HEHists[i]->Draw("box");
    //c2->Print(outfile + TString("_HE_") + TString(ii) + TString(".pdf") );
    //c2->Print(outfile + TString("_HE_") + TString(ii) + TString(".png") );

    //c[i][0] = c1;
    //c[i][1] = c2;
  }*/
  /*for( int i = 3; i < 5; i++) {
    //TString ii; ii.Form("%d", i);
    //TCanvas * c2 = new TCanvas("c2" + TString(ii), "c2" + TString(ii));
    //HEHists[i]->Draw("box");
    //c2->Print(outfile + TString("_HE_") + TString(ii) + TString(".pdf") );
    //c2->Print(outfile + TString("_HE_") + TString(ii) + TString(".png") );

    //c[i][0] = c1;
    //c[i][1] = c2;
  }*/

  TFile f(outfile + TString(".root"),"recreate");
  e_v_t_1HB->Write();
  e_v_t_2HB->Write();
  e_v_t_3HB->Write();
  e_v_t_1HE->Write();
  e_v_t_2HE->Write();
  e_v_t_3HE->Write();
  e_v_t_4HE->Write();
  e_v_t_5HE->Write();
  time_1HB->Write();
  time_2HB->Write();
  time_3HB->Write();
  time_1HE->Write();
  time_2HE->Write();
  time_3HE->Write();
  time_4HE->Write();
  time_5HE->Write();
  return;
}

