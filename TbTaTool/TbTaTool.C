#define TbTaTool_cxx
#include "TbTaTool.h"
#include "TbTaTool_files.h"
//#include "TbTaTool_files.h"
//#include "Aux_TbTaTool.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

const int super_limit = 12; //the numbes of entries in the arrays of energy and polarity
Long64_t nbytes = 0, nb = 0;
Double_t TbTaTool::NumberEventsInSpill(char* file_name, int value_NumberSpills=6, int r) //fully works
{

	char *condition_entry = new char[40];
	Double_t values_NumberEventsInSpill[20];

	for(int j=1; j<=value_NumberSpills; j++){
		sprintf(condition_entry,"In_spill > 0.5 && Spill_number == %d",j);
		values_NumberEventsInSpill[j] = fChain->GetEntries(condition_entry);

	}
	return values_NumberEventsInSpill[r];

}



void TbTaTool::NumberEventsInSpillForRun(int file_inicial, int file_end) //fully works
{

	TFile *f[10000];
	TTree *tree[10000];
	Double_t t_begin[100000];
	Double_t value_NumberEventsInSpillForRun[10000];

	for(int i=file_inicial; i<file_end; i++)
	{
		TbTaToolRun(name_file[i],i);
		for(int k=1; k<value_NumberSpills+1; k++)
			{
				// NumberEventsInSpill(char* file_name, int value_NumberSpills=0, int r)
				cout<< i << "#entradas: "<< NumberEventsInSpill(name_file[i], value_NumberSpills, k)<< endl;
			}
	}

}



Double_t TbTaTool::BeginTimeOneSubRun(char* file_name ) //fully works
{
	Double_t t_begin = -404;
  Long64_t nbytes = 0, nb = 0;

	 for (Long64_t jentry=0; jentry<1;jentry++) //Loop only the first event
	 {
				Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
				nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin = (Double_t) Time;
	 }
	 t_begin = t_begin-5*3600; //This is good, the inclusion assure us to have the time in Local Time, the time that Leo works
	 return t_begin;
}

void TbTaTool::BeginTimeForRun(int i_begin, int i_final) //fullyworks
{


	TString variable1 = "tbegin_spill.txt";
	char * myfile_name =root_path + type_label + variable1 ;
	ofstream myfile (myfile_name, ios::out | ios::app);
	if (myfile.is_open());

	TFile *f[10000];
	TTree *tree[10000];
	Double_t t_begin[100000];



	myfile <<"Unixtime outside of the first event in the spill for " << type_label << " " << variable1 << endl;
	for(int i=i_begin; i<i_final ; i++) //i number of files
	{
		TbTaToolRun(name_file[i],i);
		cout << i <<"." <<endl;
		t_begin[i]=BeginTimeOneSubRun(name_file[i]);
		myfile << t_begin[i]  - 1429810209.67 << endl;
	}
 	myfile << "The End" << endl;

}

Double_t TbTaTool::MatchTwoPoints(int r,  Double_t t_begin)//fully works
{
	Double_t value_MatchTwoPoints[2];
	Double_t delta_time, delta_time_old;
	int ne39 = 10000; //number of points of e39

	for (int k=0; k<ne39;k++)
		{
			 delta_time =  t_begin - e39times[k];
				 if(delta_time > 0 ){ }
				 else {
					 value_MatchTwoPoints[0]=e39times[k-1];
					 value_MatchTwoPoints[1]=delta_time_old;
					 break;
				 }
				 delta_time_old = delta_time;
		}

		return value_MatchTwoPoints[r];
		//value_MatchTwoPoints[0]: e39 time matched_time
		//value_MatchTwoPoints[1]: delta_time for matched values
		//value_MatchTwoPoints[2]: tbegin not necessary since BeginTimeOneSubRun() makes the work


}



void TbTaTool::MatchTwoPointsInterval(int i_index=0, int f_index =1, int fenergy=-404, int fpolarity=-404) //only for one
{



		//polarityb = -404;energyb=-404;

	for(int i=i_index; i < f_index; i++)			{	//Abrir valor de tbegin

				TbTaToolRun(name_file[i],i);
				//Get the time of the subrun in local time
				time_subrun= BeginTimeOneSubRun(name_file[i]);
				unixtimee39 = MatchTwoPoints(0, time_subrun);
				delta_time = MatchTwoPoints(1,time_subrun);
				//cout <<i<<"|";}
				polarityb = fpolarity;
				energyb = fpolarity*fenergy;
				file = i;
				tree_diff->Fill();

			}

}

void TbTaTool::GenerateMatchedTimesAnalysis(int plot=0)
{

	/* code */

	//Create the root file
	//Open teh files
	TString label ="analysis_tbegin_and_e39.root";
		char * name_results =  root_path +type_label + label;
		TFile foutput(name_results,"UPDATE");
	TTree *tree_diff = new TTree("tree_diff","Analysis tbegin and e39");

	Int_t polarityb, energyb, file, number_spill, number_spill_temp;
	Double_t delta_time, time_subrun, unixtimee39;

	TBranch *b_unixtimee39 = tree_diff->Branch("unixtimee39",&unixtimee39,"unixtimee39/D"); //matched unixtime e39
		TBranch *b_delta_time = tree_diff->Branch("delta_time", &delta_time, "delta_time/D" ); // interval between the time and the e39
		TBranch *b_time_subrun = tree_diff->Branch("time_subrun", &time_subrun, "time_subrun/D" ); //tbegin of subrun
		TBranch *b_energyb = tree_diff->Branch("energyb", &energyb, "energyb/I" );
		TBranch *b_polarityb = tree_diff->Branch("polarityb", &polarityb, "polarityb/I" );
		TBranch *b_file = tree_diff->Branch("file", &file, "file/I" );

	for(int k=0; k<super_limit-1; k++)
	{

		cout<<"\n="<< k <<"=" << energyb << "GeV=" << endl;
		for(int i=aindex[k]; i < aindex[k+1]; i++)			{	//Abrir valor de tbegin
					TbTaToolRun(name_file[i],i);
					//Get the time of the subrun in local time
					time_subrun= BeginTimeOneSubRun(name_file[i]);
					unixtimee39 = MatchTwoPoints(0, time_subrun);
					delta_time = MatchTwoPoints(1,time_subrun);
					file = i;
					polarityb = apolarity[k];
					energyb = aenergy[k];

					tree_diff->Fill();
				}
	}

	foutput.Write();


	//==ROOT FILE is already created ==//
	// the plots will be made if plot=1
	if(plot==1)
	{
		cout << "Ploting the Analysis for" << label << endl;
		//Get the TTree and put it as a

		cout << "\nend." << endl;
	}
	else{cout << "\nend." << endl;}


}

void TbTaTool::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriest();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}



void TbTaTool::PlotOneVariableOverAllEnergies(char* variable1="delta_time", char* restriction_var ="delta_time != 0", char* label_hist_result1="Interval e39-tbegin Run2", int nbins = 100, float xmin=0, float xmax=200)
{

	//Open the file txt for becnhmarking
	//Open the root file
	char* file_name="/home/gsalazarq/Dropbox/min_conocimiento/e45.MINERvA/tools/final_tools/TbTaTool/ThesisVersionTool/Results_Pions/PionsRun2analysis_tbegin_and_e39.root";
	TbTaToolAnalysis(0,file_name);
  //Limits of the histogram
  //Creation of Histogram
	TH1F *hist_result1[12];
	int m;
	TCanvas *canvas_result_[15];
	char *label_canvas = new char[20];
	char *title_canvas = new char[12];
	char *labelYaxis = new char[60];
	char *cond_histo1 = new char[80];


		for(int n=0; n<super_limit-1;n++)
		{
			sprintf(label_canvas, "canvas_result_%d",n);
			canvas_result_[n] = new TCanvas(label_canvas,label_canvas,10,10,600,400);
			TText T; T.SetTextFont(42); T.SetTextAlign(21);
			canvas_result_[n]->Divide(1);
			canvas_result_[n]->cd(1);

			//Project and plot. histname is the name of the histogram
			sprintf(labelYaxis,"Events/%d",nbins);
			m = aenergy[n]*apolarity[n];

			sprintf(cond_histo1," %s && energyb ==%d && polarityb ==%d",restriction_var,aenergy[n],apolarity[n]);

			char *histname = new char[20];
			sprintf(histname,"hist_result1%d",n);

			hist_result1[n] = new TH1F(histname,label_hist_result1,nbins,xmin,xmax);

			fChainA->Project(histname,variable1,cond_histo1);
			hist_result1[n]->Draw();
			hist_result1[n]->SetFillColor(kGreen);
			hist_result1[n]->GetXaxis()->SetTitle("Time (seconds)");
			hist_result1[n]->GetYaxis()->SetTitle(labelYaxis);
			hist_result1[n]->Draw();

			char *energy_polarity_label = new char[15] ;
			sprintf(energy_polarity_label, "%dGeV",m);

			TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
				ptstats->SetName("stats");
				ptstats->SetBorderSize(1);
				ptstats->SetFillColor(0);
				ptstats->SetTextAlign(12);
				ptstats->SetTextFont(42);
				TText *text = ptstats->AddText(energy_polarity_label); //Name
				text->SetTextSize(0.0068);
				char *entries_label = new char[12];
				Double_t entries_run =  hist_result1[n]->GetEntries();
				sprintf(entries_label," Entries %d", entries_run);//<=========================
				text = ptstats->AddText(entries_label);
				char *mean_label = new char[12];
				Float_t mean_run =  hist_result1[n]->GetMean();//<=========================
				sprintf(mean_label," Mean %0.2f", mean_run);
				text = ptstats->AddText(mean_label);
				char *rms_label = new char[12];
				Float_t rms_run =  hist_result1[n]->GetRMS(); //<=========================
				sprintf(rms_label," RMS %0.3f", rms_run);
				text = ptstats->AddText(rms_label);
				ptstats->SetOptStat(1111);
				ptstats->SetOptFit(0);
			ptstats->Draw();


			//Save the Canvas
			TString canvas_file_name;
			char *title_canvas = new char[20];

			sprintf(energy_polarity_label, "%dGeV",m);
			canvas_file_name =  root_path + variable1 +"_"+ type_label+ "_"+energy_polarity_label + ".gif";
			canvas_result_[n]->SaveAs(canvas_file_name);

			//File with data
			char buffer [50];
			TString temp1 = "entries_excluded_cut.txt";
			char * myfile_name = root_path + variable1 +"_"+temp1 ;
			ofstream myfile (myfile_name, ios::out | ios::app);
			if (myfile.is_open());
			myfile <<"Values excluded by the cut in the xmax of the histogram" << endl;
			myfile << m << "GeV" << endl;
			myfile <<"xmax = " << xmax << endl;


			char *condition_entries = new char[150];
			char *buffer_restriction = new char[100];
			sprintf(buffer_restriction,"%s && %s >%d",restriction_var, variable1,xmax);
			sprintf(condition_entries,"%s && %s && energyb ==%d && polarityb ==%d",variable1, buffer_restriction,aenergy[n],apolarity[n]);
			myfile << fChainA->GetEntries(condition_entries) << endl;
			myfile <<"####"<< endl;


		}

}



void TbTaTool::GenerateTimeProfile()
{

    TString labelTP ="_time_profile_spills.root";
	  char * name_results = root_path + type_label + labelTP;

	  TFile f_spill(name_results,"RECREATE");
	  TTree *tree_spill = new TTree("tree_spill","Tree Spill");

	  Double_t Time_spill_1b, Time_spill_2b, Time_spill_3b, Time_spill_4b, Time_spill_5b, Time_spill_6b;
		Int_t energyb, polarityb, Spill_numberb, file;

	  TBranch *b_Time_spill_1b = tree_spill->Branch("Time_spill_1b", &Time_spill_1b, "Time_spill_1b/D" );
	  TBranch *b_Time_spill_2b = tree_spill->Branch("Time_spill_2b", &Time_spill_2b, "Time_spill_2b/D" );
	  TBranch *b_Time_spill_3b = tree_spill->Branch("Time_spill_3b", &Time_spill_3b, "Time_spill_3b/D" );
	  TBranch *b_Time_spill_4b = tree_spill->Branch("Time_spill_4b", &Time_spill_4b, "Time_spill_4b/D" );
	  TBranch *b_Time_spill_5b = tree_spill->Branch("Time_spill_5b", &Time_spill_5b, "Time_spill_5b/D" );
	  TBranch *b_Time_spill_6b = tree_spill->Branch("Time_spill_6b", &Time_spill_6b, "Time_spill_6b/D" );
		TBranch *b_file = tree_spill->Branch("file", &file, "file/I");
	  TBranch *b_Spill_numberb = tree_spill->Branch("Spill_numberb", &Spill_numberb, "Spill_numberb/I" );
	  TBranch *b_energyb = tree_spill->Branch("energyb", &energyb, "energyb/I" );
	  TBranch *b_polarityb = tree_spill->Branch("polarityb", &polarityb, "polarityb/I" );


		// Definition of variables


		Double_t t_o_spill_absolute;


		Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;
		Double_t t_o_spill_absolute,code_spill_1, code_spill_2, code_spill_3, code_spill_4, code_spill_5, code_spill_6;
		Double_t exists_spill_1, exists_spill_2, exists_spill_3, exists_spill_4, exists_spill_5, exists_spill_6;
		Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;
		Double_t Time_spill, Time_spill_1, Time_spill_2, Time_spill_3, Time_spill_4, Time_spill_5, Time_spill_6;
		Double_t Time_begin_spill, Time_begin_spill_1, Time_begin_spill_2, Time_begin_spill_3, Time_begin_spill_4, Time_begin_spill_5, Time_begin_spill_6;
		Double_t t_o_spill_6, t_o_spill_5, t_o_spill_4, t_o_spill_3, t_o_spill_2, t_o_spill_1;
		Float_t interval_between_spills = 60.53333333;

		Double_t TimeBeginSpill_[20];
		Double_t DidTBeginWasCalculated_[20];
		Double_t DidAbsoluteTBeginWasRecalculated_[20];

		TString labelSD ="spill_duration.root";
		char * name_file_global = root_path + type_label + labelSD;

		TFile f_global(name_file_global,"RECREATE");
		TTree *spill_global     = new TTree("spill_global","Spill Global");

		Double_t duration_spill, mi_cycle, temp ;
		Int_t value_category ;
		Int_t category ;
		TBranch *b_duration_spill = spill_global->Branch("duration_spill", &duration_spill, "duration_spill/D" );
		TBranch *b_mi_cycle = spill_global->Branch("mi_cycle", &mi_cycle, "mi_cycle/D" );
		TBranch *b_category = spill_global->Branch("category", &category, "category/I" );
		TBranch *b_energyb = spill_global->Branch("energyb", &energyb, "energyb/I" );
		TBranch *b_polarityb = spill_global->Branch("polarityb", &polarityb, "polarityb/I" );




    TFile *f[10000];
    TTree *tree[10000];
    Double_t t_begin[100000];
		Double_t exists_spill[20];

		for(int i_index=0; i_index<super_limit-1; i_index++)
		{
			polarityb = apolarity[i_index];
			energyb = aenergy[i_index];

			cout << "Energy " << polarityb*energyb << "GeV" << endl;
			for(Int_t i=aindex[i_index]; i<aindex[i_index+1]; i++)
			{ //For() over all the root files
				cout << i << "." << endl;
						TbTaToolRun(name_file[i],i);

						exists_spill_1 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 1");
						//myfile3 << "Existe el spill 1?: " << exists_spill_1 << endl;
						exists_spill_2 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 2");
						//myfile3 << "Existe el spill 2?: " <<exists_spill_2 << endl;
						exists_spill_3 = fChain->GetEntries("Time && In_spill>0.5  && Spill_number == 3");
						//myfile3 << "Existe el spill 3?: " <<exists_spill_3 << endl;
						exists_spill_4 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 4");
						//myfile3 << "Existe el spill 4?: " <<exists_spill_4 << endl;
						exists_spill_5 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 5");
						//myfile3 << "Existe el spill 5?: " <<exists_spill_5 << endl;
						exists_spill_6 = fChain->GetEntries("Time && In_spill>0.5 && Spill_number == 6");
						//myfile3 << "Existe el spill 6?: " <<exists_spill_6 << endl;

						// ================= LOOP 0 : Begin of the Variable Time and =================== //

						if (fChain == 0) return; Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;
						Double_t signal1_t_begin_spill_1, signal1_t_begin_spill_2, signal1_t_begin_spill_3, signal1_t_begin_spill_4, signal1_t_begin_spill_5, signal1_t_begin_spill_6;


											signal1_t_begin_spill_1 = 0; signal1_t_begin_spill_2 = 0;
											signal1_t_begin_spill_3 = 0; signal1_t_begin_spill_4 = 0;
											signal1_t_begin_spill_5 = 0; signal1_t_begin_spill_6 = 0;
										  Time_begin_spill_1 = -404; Time_begin_spill_2 = -404;
						 				  Time_begin_spill_3 = -404; Time_begin_spill_4 = -404;
						 				  Time_begin_spill_5 = -404; Time_begin_spill_6 = -404;


						t_begin[i] = MatchTwoPoints(0,BeginTimeOneSubRun(name_file[i]));


							// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

						// ================= LOOP 1 : Begin Time for the Spill_number == 1 =================== //

						for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

							 if (In_spill > 0.5 ){if (Spill_number == 1 && exists_spill_1 != 0 ){
								 //jentry_array= (Double_t) jentry;

								Time_begin_spill_1 = (Double_t) Time - t_begin[i];
								t_o_spill_1 = (Double_t) Time;
								signal1_t_begin_spill_1 = 1;
																					break ;                  }                 }             }

						// ================= LOOP 2 : Begin Time for the Spill_number == 2 =================== //

						 for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
								nb = fChain->GetEntry(jentry);   nbytes += nb;

								if (In_spill > 0.5 ){ if (Spill_number == 2 ){ //jentry_array2= (Double_t) jentry;
									Time_begin_spill_2 = (Double_t) Time - t_begin[i];
									t_o_spill_2 = (Double_t) Time;
									////myfile << "jentry_array2: "<< jentry_array2 << endl;
									 //myfile2 << "Time_spill_2 "<< Time_begin_spill_2 << endl;
									 signal1_t_begin_spill_2 = 1;
											break ;                    }                  }              }

						// ================= LOOP 3 : Begin Time for the Spill_number == 3 =================== //

						for (Long64_t jentry=0; jentry<nentries;jentry++) {
								 Long64_t ientry = LoadTree(jentry);                 //if (ientry < 0) break;
								 nb = fChain->GetEntry(jentry);   nbytes += nb;

								 if (In_spill > 0.5 ){if (Spill_number == 3 ){//jentry_array3= (Double_t) jentry;
									Time_begin_spill_3 = (Double_t) Time - t_begin[i];
									t_o_spill_3 = (Double_t) Time;
									 ////myfile << "jentry_array3: "<< jentry_array3 << endl;
									 //myfile2 << "Time_spill_3 "<< Time_begin_spill_3 << endl;
									 signal1_t_begin_spill_3 = 1;
											 break ;                     }                   }               }

						// ================= LOOP 4 : Begin Time for the Spill_number == 4 =================== //

						for (Long64_t jentry=0; jentry<nentries;jentry++) {
									Long64_t ientry = LoadTree(jentry);
									// if (ientry < 0) break;
									nb = fChain->GetEntry(jentry);   nbytes += nb;

									if (In_spill > 0.5 ){if (Spill_number == 4 ){//jentry_array4= (Double_t) jentry;
									Time_begin_spill_4 = (Double_t) Time - t_begin[i];
									t_o_spill_4 = (Double_t) Time;
									 ////myfile << "jentry_array4: "<< jentry_array4 << endl;
									 //myfile2 << "Time_spill_4 "<< Time_begin_spill_4 << endl;
									 signal1_t_begin_spill_4 = 1;
												break ;                      }                    }                }

						// ================= LOOP 5 : Begin Time for the Spill_number == 5 =================== //

						for (Long64_t jentry=0; jentry<nentries;jentry++) {
									 Long64_t ientry = LoadTree(jentry);
									 //if (ientry < 0) break;
									 nb = fChain->GetEntry(jentry);   nbytes += nb;

									 if (In_spill > 0.5 ){if (Spill_number == 5 ){//jentry_array5= (Double_t) jentry;
									Time_begin_spill_5 = (Double_t) Time - t_begin[i];
									t_o_spill_5 = (Double_t) Time;
									 ////myfile << "jentry_array5: "<< jentry_array5 << endl;
									 //myfile2 << "Time_spill_5 "<< Time_begin_spill_5 << endl;
									 signal1_t_begin_spill_5 = 1;
												 break ;                       }                     }                 }

						// ================= LOOP 6 : Begin Time for the Spill_number == 2 =================== //

						for (Long64_t jentry=0; jentry<nentries;jentry++) {
										Long64_t ientry = LoadTree(jentry);
										//if (ientry < 0) break;
										nb = fChain->GetEntry(jentry);   nbytes += nb;

										if (In_spill > 0.5 ){if (Spill_number == 6 ){//jentry_array6= (Double_t) jentry;
									Time_begin_spill_6 = (Double_t) Time - t_begin[i];
									t_o_spill_6 = (Double_t) Time;
									 ////myfile << "jentry_array6: "<< jentry_array6 << endl;
									 //myfile2 << "Time_spill_6 "<< Time_begin_spill_6 << endl;
									 signal1_t_begin_spill_6 = 1;
													break ;                        }                      }                  }

						Float_t interval_between_spills = 0.0;

						if (fChain == 0) return;
						 Long64_t nentries = fChain->GetEntries();
						 Long64_t nbytes = 0, nb = 0;

						 Double_t duration_spill_1, duration_spill_2, duration_spill_3, duration_spill_4, duration_spill_5, duration_spill_6;

						 for (Long64_t jentry=0; jentry<nentries;jentry++) {
							 Long64_t ientry = LoadTree(jentry);
							 //if (ientry < 0) break;
							 nb = fChain->GetEntry(jentry);   nbytes += nb;

								//Conditions for Spill has actual values

								Time_spill_1b = -1; Time_spill_2b = -1; Time_spill_3b = -1;
								Time_spill_4b = -1; Time_spill_5b = -1; Time_spill_6b = -1;
								mi_cycle = 0;

			      	if (In_spill > 0.5 )              {
			          if (Spill_number == 1  )                 {

			                  Time_spill_1 = (Double_t) Time -t_begin[i];
			                  duration_spill_1 = Time_spill_1 - Time_begin_spill_1;

			                  Time_spill_1b = (Double_t) Time - t_o_spill_1;
			                  Spill_numberb = 1;
			                  tree_spill->Fill();


			            }
			            else if (Spill_number == 2 )
			            {
			                  Time_spill_2= (Double_t) Time -t_begin[i];
			                  duration_spill_2 = Time_spill_2 - Time_begin_spill_2;


			                  Time_spill_2b = (Double_t) Time - t_o_spill_2;
			                  Spill_numberb = 2;
			                  tree_spill->Fill();

			            }

			            else if (Spill_number == 3  )
			            {
			                  Time_spill_3= (Double_t) Time -t_begin[i];
			                  duration_spill_3 = Time_spill_3 - Time_begin_spill_3;

			                  Time_spill_3b = (Double_t) Time - t_o_spill_3;
			                  Spill_numberb = 3;
			                  tree_spill->Fill();

			             }

			           else if (Spill_number == 4  )
			           {
			                 Time_spill_4= (Double_t) Time -t_begin[i];
			                 duration_spill_4 = Time_spill_4 - Time_begin_spill_4;


			                 Time_spill_4b = (Double_t) Time - t_o_spill_4 ;
			                 Spill_numberb = 4;
			                 tree_spill->Fill();
			          	}

			          	else if (Spill_number == 5  )
			          	{
			                Time_spill_5= (Double_t) Time -t_begin[i];
			                duration_spill_5 = Time_spill_5 - Time_begin_spill_5;


			                Time_spill_5b = (Double_t) Time - t_o_spill_5 ;
			                Spill_numberb = 5;
			                tree_spill->Fill();
			          	}

			         	 else if (Spill_number == 6  )
			         	 {
			               Time_spill_6= (Double_t) Time -t_begin[i];
			               duration_spill_6 = Time_spill_6 - Time_begin_spill_6;


			               Time_spill_6b = (Double_t) Time - t_o_spill_6;
			               Spill_numberb = 6;
			               tree_spill->Fill();
			         	 }

			        } // end of:  if (In_spill > 0.5 )
			 			}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)

						  	// ## 1

							  duration_spill =  duration_spill_1;
							  category = 1;
							  mi_cycle = 0;
								//myfile << mi_cycle << endl;
								//myfile4 << duration_spill << endl;
							  spill_global->Fill();

								// ## 2

								if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

									  duration_spill =  duration_spill_2;
									  mi_cycle = t_o_spill_2 - t_o_spill_1;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}
								else {

									  duration_spill =  duration_spill_2;
									  mi_cycle = 0;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}
								// ## 3

								if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

									  duration_spill =  duration_spill_3;
									  mi_cycle = t_o_spill_3 - t_o_spill_2;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}
								else {

									  duration_spill =  duration_spill_3;
									  mi_cycle = 0;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}

							  // ## 4
								if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

									  duration_spill =  duration_spill_4;
									  mi_cycle =  t_o_spill_4 - t_o_spill_3;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}
								else {

										duration_spill =  duration_spill_4;
									  mi_cycle = 0;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}
							  // ## 5

								if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

									  duration_spill =  duration_spill_5;
									  mi_cycle = t_o_spill_5 - t_o_spill_4;
									  category = 1;
									  //myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

								}
								else {

								  duration_spill =  duration_spill_5;
								  mi_cycle = 0 ;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

								}
							  // ## 6

								if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

								  duration_spill =  duration_spill_6;
								  mi_cycle = t_o_spill_6 - t_o_spill_5;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

								}
								else {

								  duration_spill =  duration_spill_6;
								  mi_cycle = 0;
								  category = 1;
								  //myfile << mi_cycle << endl;
									//myfile4 << duration_spill << endl;
								  spill_global->Fill();

								}


			}  // End For the ROOT files Energy


		} // end For for all the indexes


	f_spill.Write();
	f_global.Write();


}


void TbTaTool::VariableArrayInsideSubRun(char* name_file, TTree *tree, Long64_t nentries, Double_t t_begin, int value_number_spills, int SpillNumber=1, int r=0 )
{
	Double_t values_VariableArrayInsideSubRun[5];
	Double_t a,b;

	for (Long64_t jentry=0; jentry<nentries;jentry++)
		{
		 Long64_t ientry = LoadTree(jentry);                //if (ientry < 0) break;
		 nb = fChain->GetEntry(jentry);   nbytes += nb;

					if (In_spill > 0.5 )
					{
						if (Spill_number == SpillNumber  && NumberEventsInSpill(name_file, 6, SpillNumber) != 0     )
						{
							values_VariableArrayInsideSubRun[0] = Time - t_begin;;
							//TimeBeginSpill_[y] == values_VariableArrayInsideSubRun[0] = Time - t_begin;;
							values_VariableArrayInsideSubRun[1] = 1;
							//DidTBeginWasCalculated == values_VariableArrayInsideSubRun[1]
							break ;
						}
					}
		}
		return values_VariableArrayInsideSubRun[r];
	}
