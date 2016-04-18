#define tool_diferencias_cxx
#include "tool_diferencias.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void tool_diferencias::Loop()
{
       const char* name_file[1000] = {



        };


  	// 8 GeV Pos 		// 6 GeV Pos 		// 4 GeV Pos 		// 8 GeV Neg 		// 6 GeV Neg 		// 4 GeV Neg 	// 9 GeV Pos 		// 10 GeV Pos 		// 16 GeV Pos 		// 9 GeV Neg 		// -10 GeV Neg
		Int_t nfiles_files=74 + 							71 + 								74 +					68+							69+							74+						68+						65 +							32+							65+									65 ;


    TString energy_value ="All_energies_";
    TString polarity ="All_polarities_";
    TString label ="Differences_tbegin_e39.root";
    char * name_results = energy_value + polarity +  label;

    TFile foutput(name_results,"RECREATE");
    TTree *tree_diff = new TTree("tree_diff","Difference tbegin and e39");

    Int_t polarityb, energyb, file;
    Double_t delta_time, delta_time_old;
    Double_t time_root_file;

    TBranch *b_delta_time_old = tree_diff->Branch("delta_time_old", &delta_time_old, "delta_time_old/D" );
    TBranch *b_time_root_file = tree_diff->Branch("time_root_file", &time_root_file, "time_root_file/D" );
    TBranch *b_polarityb = tree_diff->Branch("polarityb", &polarityb, "polarityb/I" );
    TBranch *b_energyb = tree_diff->Branch("energyb", &energyb, "energyb/I" );
    TBranch *b_file = tree_diff->Branch("file", &file, "file/I" );

    delta_time = 0;
    delta_time_old = 1000000000;

    // ==

    TTree *tree_e39;
    Double_t unixtime_e39;
    TBranch *b_unixtime_e39;

    TFile *finput_e39 = (TFile*)gROOT->GetListOfFiles()->FindObject("root_e39_unixtime.root");

     if (tree_e39 == 0) {
        TFile *finput_e39 = (TFile*)gROOT->GetListOfFiles()->FindObject("root_e39_unixtime.root");
        if (!finput_e39 || !finput_e39->IsOpen()) {
           finput_e39 = new TFile("root_e39_unixtime.root");
        }
        finput_e39->GetObject("tree_unixtime_e39",tree_e39);

     }

    tree_e39->SetMakeClass(1);
    tree_e39->SetBranchAddress("unixtime_e39", &unixtime_e39, &b_unixtime_e39);

    //==Calculating


    //==============
    char buffer [50];
    TString variable1 = "delta_time_pions_nentries39_final.txt";
    char * myfile_name = variable1 ;
    ofstream myfile (myfile_name, ios::out | ios::app);
    if (myfile.is_open());
    myfile <<"Differences_tbegin_e39" << endl;

    TString variable2 = "tbegin_pions_3_final.txt";
    char * myfile_name = variable2 ;
    ofstream myfile2 (myfile_name, ios::out | ios::app);
    if (myfile2.is_open());
    myfile2 <<"tbegin Pions" << endl;

    TFile *f_tb[100000];
    TTree *tree[100000];
    Double_t t_begin[100000];


    myfile << "+8" << endl;

  for(Int_t i=0; i< 74 ; i++){ //For() over all the root files
  polarityb = 1 ;
  energyb = 8 ;



     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t last_jentry_e39, nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;
	            ////myfile2 << t_begin[i] -  1429838288.48 << endl;

              break;
           }

         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //if (ientry_e39 < 0) break


            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time > 0 ){ }
              else {
                //myfile << delta_time_old << endl;
                tree_diff->Fill();
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];
              last_jentry_e39 = jentry_e39;
              }
              file = i ;
              //tree_diff->Fill();
        cout <<  i  << "." << endl  ;

}// ENF FOR files



 	 myfile << "+6" << endl;

  for(Int_t i=74; i< 74+71 ; i++){ //For() over all the root files
  polarityb = 1 ;
  energyb = 6 ;


     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;
	            ////myfile2 << t_begin[i] -  1429838288.48 << endl;
              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=990; jentry_e39<nentries_e39;jentry_e39++) {
           //        for (Long64_t jentry_e39=last_jentry_e39; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);

            ////////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;


              if(delta_time >0 ){ }
              else {
                myfile <<  delta_time_old << endl;
                tree_diff->Fill();
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];

              }
              file = i ;
              //tree_diff->Fill();
        cout <<  i  << "." << endl  ;

}// ENF FOR files



	myfile << "+4" << endl;
  for(Int_t i=74+71; i< 74+71+74 ; i++){ //For() over all the root files
  polarityb = 1 ;
  energyb = 4 ;


     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;
	      ////myfile2 << t_begin[i] -  1429838288.48 << endl;
              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;


         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;
		        //myfile << "jentrye39 " << jentry_e39 << ": " <<delta_time << endl;

            if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                tree_diff->Fill();
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];

              }
              file = i ;
              //tree_diff->Fill();
        cout <<  i  << "." << endl  ;

	       //cout << nentries_e39<< endl;


}// ENF FOR files


  for(Int_t i=74+71+74; i< 74+71+74+68 ; i++){ //For() over all the root files
  polarityb = -1 ;
  energyb = 8 ;

	myfile << "-8" << endl;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;
	      ////myfile2 << t_begin[i] -  1429838288.48 << endl;
              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                tree_diff->Fill();
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }

              file = i ;
        cout <<  i  << "." << endl  ;

}// ENF FOR files


  for(Int_t i=74+71+74+68; i< 74+71+74+68+69 ; i++){ //For() over all the root files
  polarityb = -1 ;
  energyb = 6 ;



     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;
	      ////myfile2 << t_begin[i] -  1429838288.48 << endl;
              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                tree_diff->Fill();
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              ();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files


  for(Int_t i=74+71+74+68+69; i< 74+71+74+68+69+74 ; i++){ //For() over all the root files
  polarityb = -1 ;
  energyb = 4 ;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;

              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              tree_diff->Fill();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files


  for(Int_t i=74+71+74+68+69+74; i< 74+71+74+68+69+74+68 ; i++){ //For() over all the root files
  polarityb = 1 ;
  energyb = 9 ;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;

              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              tree_diff->Fill();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files

  for(Int_t i=74+71+74+68+69+74+68; i< 74+71+74+68+69+74+68+65 ; i++){ //For() over all the root files
  polarityb = 1 ;
  energyb = 10 ;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;

              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              tree_diff->Fill();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files


  for(Int_t i=74+71+74+68+69+74+68+65; i< 74+71+74+68+69+74+68+65+32 ; i++){ //For() over all the root files
  polarityb = 1 ;
  energyb = 16 ;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;

              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              tree_diff->Fill();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files


  for(Int_t i=74+71+74+68+69+74+68+65+32; i< 74+71+74+68+69+74+68+65+32+65 ; i++){ //For() over all the root files
  polarityb = -1 ;
  energyb = 9 ;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;

              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              tree_diff->Fill();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files



  for(Int_t i=74+71+74+68+69+74+68+65+32+65; i< 74+71+74+68+69+74+68+65+32+65+65 ; i++){ //For() over all the root files
  polarityb = -1 ;
  energyb = 10 ;

     t_begin[i] = 0;
      // =========================  Open the array_root_file[i] and the corresponding tree[i]

      f_tb[i] = (TFile*)gROOT->GetListOfFiles()->FindObject(name_file[i]);
        if (!f_tb[i] || !f_tb[i]->IsOpen()) {
           f_tb[i] = new TFile(name_file[i],"READ");
        }

      f_tb[i]->GetObject("CAMACTree",tree[i]);
      Init(tree[i]);      //fChaintb equal to the tree corresponding to the array_file_root[i]


        //====

          if (fChain == 0 ) return ;
          Long64_t nentries = fChain->GetEntries();
          Long64_t nbytes = 0, nb = 0;

           for (Long64_t jentry=0; jentry<1;jentry++) {
              Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;

              t_begin[i] = (Double_t) Time;

              break;
           }



         if (tree_e39 == 0) return;
         Long64_t nentries_e39 = tree_e39->GetEntries();
         Long64_t nbytes_e39 = 0, nb_e39 = 0;

         for (Long64_t jentry_e39=0; jentry_e39<nentries_e39;jentry_e39++) {
            Long64_t ientry_e39 = LoadTree(jentry_e39);
            //////if (ientry_e39 < 0) break;
            nb = tree_e39->GetEntry(jentry_e39);   nbytes_e39 += nb_e39;
            // if (Cut(ientry) < 0) continue;
            delta_time =  t_begin[i] - unixtime_e39;

              if(delta_time >0 ){ }
              else {
                //myfile << delta_time_old << endl;
                break;
              }

              delta_time_old = delta_time; time_root_file = t_begin[i];



              }
              file = i ;
              tree_diff->Fill();
        cout <<  i  << "." << endl  ;

  }// ENF FOR files


  foutput.Write();
  myfile << "####" << endl;

}


void tool_diferencias::Draw(){


      TTree *tree_diff;
      if (tree_diff == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("All_energies_All_polarities_Differences_tbegin_e39.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("All_energies_All_polarities_Differences_tbegin_e39.root");
         }
         f->GetObject("tree_diff",tree_diff);

      }

      Int_t polarityb;
      Int_t energyb;
      Int_t file;
      Double_t time_root_file;
      Double_t delta_time_old;


      TBranch        *b_energyb;
      TBranch        *b_polarityb;
      TBranch        *b_file;
      TBranch        *b_delta_time_old;
      TBranch        *b_time_root_file;



      tree_diff->SetMakeClass(1);
      tree_diff->SetBranchAddress("energyb", &energyb, &b_energyb);
      tree_diff->SetBranchAddress("time_root_file", &time_root_file, &b_time_root_file);
      tree_diff->SetBranchAddress("polarityb", &polarityb, &b_polarityb);
      tree_diff->SetBranchAddress("file", &file, &b_file);
      tree_diff->SetBranchAddress("delta_time_old", &delta_time_old, &b_delta_time_old);



      //== Spills during Run 3

      Int_t nbins3 = 50;
      Double_t xmin3 = 1.429764e+09;
      Double_t xmax3 = 1.430226e+09;


      TH1F *hist_delta_date_pos = new TH1F("hist_delta_date_pos","$39 and beginning subrun vs file Pos",nbins3,xmin3,xmax3);
      TH1F *hist_delta_date_neg = new TH1F("hist_delta_date_neg","$39 and beginning subrun vs file Neg",nbins3,xmin3,xmax3);
      TCanvas *c_deltaT = new TCanvas("deltaT","Delta between $39 and beginning subrun vs file",10,10,700,400);
      TText T; T.SetTextFont(42); T.SetTextAlign(21);
      c_deltaT->Divide(1);
      c_deltaT->cd(1);

      //tree_diff->Project("hist_delta", "number_spills:Timespill");
      tree_diff->Project("hist_delta_date_pos", "delta_time_old:time_root_file", "polarityb == 1");
      tree_diff->Project("hist_delta_date_neg", "delta_time_old:time_root_file", "polarityb == -1");

      hist_delta_date_pos->Draw();


      Int_t ci;   // for color index setting
      ci = TColor::GetColor("#000099");
      hist_delta_date_pos->SetLineColor(ci);
      hist_delta_date_pos->GetYaxis()->SetTitle("Interval(s)");
      hist_delta_date_pos->SetTitle("Seconds between $e39 vs tbegin in time");
      hist_delta_date_pos->GetXaxis()->SetTitle("Subruns");
      hist_delta_date_pos->GetXaxis()->SetTimeDisplay(1);
      hist_delta_date_pos->GetXaxis()->SetTimeFormat("%H:%M %F 1970-01-01 00:00:00");
      hist_delta_date_pos->SetMarkerColor(2);
      hist_delta_date_pos->SetMarkerStyle(5);
      hist_delta_date_pos->Draw();

      hist_delta_date_neg->SetMarkerStyle(4);
      hist_delta_date_neg->SetMarkerColor(3);
      hist_delta_date_neg->Draw("SAME");

      c_deltaT->SaveAs("B_hist_delta_e39_subrun_date_all_e_p.gif");

/*

      // Ploting Spill Number for all



       TCanvas *c_hist_delta_only = new TCanvas("c_hist_delta_only ","Interval of time $39 and beginning root file",10,10,600,400);
       c_hist_delta_only->Divide(1);
       c_hist_delta_only->cd(1);
       Int_t nbins2 = 200;
       Double_t xmin2 = -5;
       Double_t xmax2 = 1200;

      TH1F *hist_hist_delta_only = new TH1F("hist_hist_delta_only","Interval of time $39 and beginning root file",nbins2,xmin2,xmax2);

      tree_diff->Project("hist_hist_delta_only","delta_time_old");
      hist_hist_delta_only->Draw();
      hist_hist_delta_only->GetXaxis()->SetTitle(" Interval time (seconds)");
      hist_hist_delta_only->SetTitle("Interval of time $39 and beginning root file");
      hist_hist_delta_only->SetMarkerColor(2);
      hist_hist_delta_only->SetMarkerStyle(5);
      hist_hist_delta_only->Draw();


      c_hist_delta_only->SaveAs("B_hist_delta_e39_subrun_NOdate_all_e_p.gif");
      ///////////////////////////////////

  // Ploting Spill Number for all


        // Ploting Spill Number for all



         TCanvas *c_hist_delta_file = new TCanvas("c_hist_delta_file ","Interval of time $39 and beginning root file",10,10,600,400);
         c_hist_delta_file->Divide(1);
         c_hist_delta_file->cd(1);
         Int_t nbins2 = 50;
         Double_t xmin2 = 0;
         Double_t xmax2 = 800;

        TH1F *hist_delta_file = new TH1F("hist_delta_file","Interval of time $39 and beginning root file",nbins2,xmin2,xmax2);

        tree_diff->Project("hist_delta_file","delta_time_old:file");
        hist_delta_file->Draw();
        hist_delta_file->GetXaxis()->SetTitle("Subruns");
        hist_delta_file->SetTitle("Interval of time $39 and beginning root related file");
        hist_delta_file->SetMarkerColor(2);
        hist_delta_file->SetMarkerStyle(5);
        hist_delta_file->Draw();


        c_hist_delta_file->SaveAs("B_hist_delta_e39_subrun_file_all_e_p.gif");
        ///////////////////////////////////

*/
}
