#define TbTaTool_cxx
#include "TbTaTool.h"
#include "TbTaTool_files.h"
//#include "TbTaTool_files.h"
//#include "Aux_TbTaTool.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <ctime>
#include <iostream>
using namespace std;


const int super_limit = 12; //the numbes of entries in the arrays of energy and polarity
Long64_t nbytes = 0, nb = 0;
Double_t TbTaTool::NumberEventsInSpill(char* file_name, int value_NumberSpills=6, int r) //fully works
{
	//int r is the number of spills that you want to calculate
	char *condition_entry = new char[40];
	Double_t values_NumberEventsInSpill[20];

	for(int j=1; j<=value_NumberSpills; j++)
	{
		sprintf(condition_entry,"In_spill > 0.5 && Spill_number == %d",j);
		values_NumberEventsInSpill[j] = fChain->GetEntries(condition_entry);
	}
	return values_NumberEventsInSpill[r]; //numbers of events in the Spill_number == r
}



void TbTaTool::NumberEventsInSpillForRun(int file_begin, int file_end) //fully works
{
	TString variable1 = "_NumberEventsInSpillForRun.txt";
	char * myfile_name =root_path + type_label + variable1 ;
	ofstream myfile (myfile_name, ios::out | ios::app);
	if (myfile.is_open());

	time_t now = time(0);
	// Convert now to tm struct for local timezone
	tm* localtm = localtime(&now);
	myfile << "The local date and time is: " << asctime(localtm) << endl;


	Double_t value_NumberEventsInSpillForRun[10000];

	for(int i=file_begin; i<file_end; i++)
	{
		TbTaToolRun(name_file[i],i);
		for(int k=1; k<value_NumberSpills+1; k++)
			{
				// NumberEventsInSpill(char* file_name, int value_NumberSpills=0, int r)
				cout<< i << "#entradas: "<< NumberEventsInSpill(name_file[i], value_NumberSpills, k)<< endl;
				myfile<< i << "#entradas: "<< NumberEventsInSpill(name_file[i], value_NumberSpills, k)<< endl;
			}
	}

	myfile<< "###"<< endl;
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



Double_t TbTaTool::BeginTimeOfSpillsForOneSubRun(char* name_file, int m=1, Long64_t nentries=0) //fully works               <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
{
	//m is the spill number
	//
	Double_t value_BeginTimeOfSpillsForOneSubRun[20];

	Double_t t_begin = -404;
  Long64_t nbytes = 0, nb = 0;
	 for (Long64_t jentry=0; jentry<nentries;jentry++) //Loop only the first event
	 {
				Long64_t ientry = LoadTree(jentry); //if (ientry < 0) break;
				nb = fChain->GetEntry(jentry);   nbytes += nb;
				if(In_spill >0.5)
				{
					if(Spill_number ==m && NumberEventsInSpill(name_file, value_number_spills, m) != 0)
					{
						t_begin = (Double_t) Time;
						break;
					}
				}
		}

	value_BeginTimeOfSpillsForOneSubRun[m]= t_begin-5*3600; //This is good, the inclusion assure us to have the time in Local Time, the time that Leo works
	return value_BeginTimeOfSpillsForOneSubRun[m];
}


Double_t TbTaTool::KickOffOneSubRun(char* name_file,Long64_t nentries) //fully works               <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
{

	Double_t  value_KickOffOneSubRun;

	for(int m=1; m<value_number_spills; m++)
	{
		if(BeginTimeOfSpillsForOneSubRun(name_file,m,nentries)!=0)
		{
			value_KickOffOneSubRun = BeginTimeOfSpillsForOneSubRun(name_file,m,nentries);
			break;
		}
		else
		{
			value_KickOffOneSubRun = BeginTimeOfSpillsForOneSubRun(name_file,m+1,nentries);
		}
	}
	return value_KickOffOneSubRun;
}


void TbTaTool::BeginTimeForRun(int i_begin, int i_final,int which_tbegin= 0) //fullyworks
{

	if(which_tbegin == 0)
	{

	TString variable1 = "tbegin_spill.txt";
	cout << "Calculating the beginning of time considering tbegin " << endl;
	cout << "Usando ref_tb: " << ref_tb << endl;
	}
	else
	{
	TString variable1 = "kick_off_spill.txt";
	cout << "Calculating the beginning considering the kickoff" << endl;
	cout << "Usando ref_e39: " << ref_e39 << endl;
	}


	char * myfile_name =root_path + type_label + variable1 ;
	ofstream myfile (myfile_name, ios::out | ios::app);
	if (myfile.is_open());
	time_t now = time(0);
	// Convert now to tm struct for local timezone
	tm* localtm = localtime(&now);
	myfile << "The local date and time is: " << asctime(localtm) << endl;



	TFile *f[10000];
	TTree *tree[10000];
	Double_t t_begin[100000];
	Long64_t nentries;

	myfile <<"Unixtime outside of the first event in the spill for " << type_label << " " << variable1 << endl;
	for(int i=i_begin; i<i_final ; i++) //i number of files
	{
		TbTaToolRun(name_file[i],i);
		if (fChain == 0) return;
		nentries = fChain->GetEntries();

		if(which_tbegin == 0)
		{
			t_begin[i] = BeginTimeOneSubRun(name_file[i]);
			if(t_begin[i] > 0){myfile << t_begin[i]  - ref_tb << endl;}
			else {myfile << 0 << endl;}

		}
		else
		{
			//t_begin[i] = 1429810209.67;
			t_begin[i] =KickOffOneSubRun(name_file[i],nentries);
			if(t_begin[i] > 0){myfile << t_begin[i]  - ref_e39 << endl;}
			else {myfile << 0 << endl;}

		}

	}
 	myfile << "The End" << endl;
	cout << "End of BeginTimeForRun()" << endl;
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



void TbTaTool::MatchTwoPointsInterval(int i_index=0, int f_index =1, int fenergy=-404, int fpolarity=-404, int which_tbegin = 0) //only for one
{

	//polarityb = -404;energyb=-404;

	for(int i=i_index; i < f_index; i++)			{	//Abrir valor de tbegin

				TbTaToolRun(name_file[i],i);
				if (fChain == 0) return;
				nentries = fChain->GetEntries();
				//Get the time of the subrun in local time
				if(which_tbegin == 0)
				{
					time_subrun= BeginTimeOneSubRun(name_file[i]);
				}
				else
				{
					time_subrun = KickOffOneSubRun(name_file[i],nentries);
					if(time_subrun <0){time_subrun= BeginTimeOneSubRun(name_file[i]);}
				}

				unixtimee39 = MatchTwoPoints(0, time_subrun);
				delta_time = MatchTwoPoints(1,time_subrun);
				//cout <<i<<"|";}
				polarityb = fpolarity;
				energyb = fpolarity*fenergy;
				file = i;
				tree_diff->Fill();

			}

}

void TbTaTool::GenerateMatchedTimesAnalysis(int which_tbegin == 0)
{

	/* code */

	//Create the root file
	//Open teh files
	if(which_tbegin == 0)
	{
		TString label ="_analysis_tbegin_and_e39.root";
	}
	else
	{
		TString label ="_analysis_kickoff_and_e39.root";
	}
	Long64_t nentries;

	//TString label ="analysis_tbegin_and_e39.root";  tbegin e39
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

		cout<<"\n="<< k <<"=" << aenergy[k]*apolarity[k] << "GeV=" << endl;
		for(int i=aindex[k]; i < aindex[k+1]; i++)			{	//Abrir valor de tbegin
					TbTaToolRun(name_file[i],i);
					if (fChain == 0) return;
					nentries = fChain->GetEntries();
					//Get the time of the subrun in local time
					if(which_tbegin == 0)
					{
						time_subrun= BeginTimeOneSubRun(name_file[i]);
					}
					else
					{
						time_subrun = KickOffOneSubRun(name_file[i],nentries);
						if(time_subrun <0){time_subrun= BeginTimeOneSubRun(name_file[i]);}
					}
					//Get the time of the subrun in local time

					unixtimee39 = MatchTwoPoints(0, time_subrun);
					delta_time = MatchTwoPoints(1,time_subrun);
					file = i;

					tree_diff->Fill();
					polarityb = apolarity[k];
					energyb = aenergy[k];
				}
	}

	foutput.Write();




}



void TbTaTool::PlotOneVariableOverAllEnergies(int type_tree=0, int file_resultado_analizar =0 , char* variable1="delta_time", char* restriction_var ="delta_time != 0", char* label_hist_result1 = "Time between e39 and tbegin", int nbins = 100, float xmin=0, float xmax=200, int recursive = 1)
{

	//Open the file txt for becnhmarking
	//Open the root file
	char* file_name=name_file_results[file_resultado_analizar];
	TbTaToolAnalysis(0,file_name,type_tree);
  //Limits of the histogram
  //Creation of Histogram
	TH1F *hist_result1[12];
	int m,p;
	TCanvas *canvas_result_[100];

	char *label_canvas = new char[20];

	char *labelYaxis = new char[60];
	char *cond_histo1 = new char[80];
	char *title_canvas = new char[80];

	TString canvas_file_name;
	char *energy_polarity_label = new char[15] ;
	char *histname = new char[20];
	char *entries_label = new char[12];
	char *mean_label = new char[12];
	char *rms_label = new char[12];


		for(int n=0; n<super_limit-1;n++)
		{
			if(recursive ==1){p=n;}
			else if(recursive ==2){p=n+20;}
			else if(recursive ==3){p=n+30;}
			else if(recursive ==4){p=n+40;}
			else if(recursive ==5){p=n+50;}
			else if(recursive ==6){p=n+60;}

			sprintf(label_canvas, "canvas_result_%d",p);
			canvas_result_[p] = new TCanvas(label_canvas,label_canvas,10,10,600,400);
			TText T; T.SetTextFont(42); T.SetTextAlign(21);
			canvas_result_[p]->Divide(1);
			canvas_result_[p]->cd(1);

			//Project and plot. histname is the name of the histogram
			sprintf(labelYaxis,"Events/%d",nbins);
			m = aenergy[n]*apolarity[n];

			sprintf(cond_histo1," %s && energyb ==%d && polarityb ==%d",restriction_var,aenergy[n],apolarity[n]);


			sprintf(histname,"hist_result1%d",n);

			hist_result1[n] = new TH1F(histname,"",nbins,xmin,xmax);

			fChainA->Project(histname,variable1,cond_histo1);
			hist_result1[n]->Draw();



			if(file_resultado_analizar ==0)
			{
				hist_result1[n]->SetFillColor(kGreen);
			}
			else
			{
				hist_result1[n]->SetFillColor(kRed);
			}


			hist_result1[n]->GetXaxis()->SetTitle("Time (seconds)");
			hist_result1[n]->GetYaxis()->SetTitle(labelYaxis);
			hist_result1[n]->Draw();

			sprintf(energy_polarity_label, "%dGeV",m);

			TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
				ptstats->SetName("stats");
				ptstats->SetBorderSize(1);
				ptstats->SetFillColor(0);
				ptstats->SetTextAlign(12);
				ptstats->SetTextFont(42);
				TText *text = ptstats->AddText(energy_polarity_label); //Name
				text->SetTextSize(0.0068);

				Double_t entries_run =  hist_result1[n]->GetEntries();
				sprintf(entries_label," Entries %d", entries_run);//<=========================
				text = ptstats->AddText(entries_label);

				Float_t mean_run =  hist_result1[n]->GetMean();//<=========================
				sprintf(mean_label," Mean %0.2f", mean_run);
				text = ptstats->AddText(mean_label);

				Float_t rms_run =  hist_result1[n]->GetRMS(); //<=========================
				sprintf(rms_label," RMS %0.3f", rms_run);
				text = ptstats->AddText(rms_label);
				ptstats->SetOptStat(1111);
				ptstats->SetOptFit(0);
			ptstats->Draw();

			//Save the Canvas


			sprintf(title_canvas,"%s for %dGeV %s", label_hist_result1, m, char_type_label);
			if(file_resultado_analizar ==0)
			{
				canvas_file_name =  root_path + variable1 +"_"+ type_label+ "_"+energy_polarity_label + ".gif";
			}
			else if (file_resultado_analizar ==1)
			{
				canvas_file_name =  root_path + variable1 +"_kickoff_"+ type_label+ "_"+energy_polarity_label + ".gif";
			}
			else
			{
				canvas_file_name =  root_path + variable1 +"_"+ type_label+ "_"+energy_polarity_label + ".gif";
			}

			T.DrawTextNDC(.5,.95,title_canvas);
			canvas_result_[p]->SaveAs(canvas_file_name);


		}

}


void TbTaTool::PlotStackAllEnergiesPionsTimeProfile(int r=1, int recursive = 1)
{

		TbTaToolAnalysis(0,name_file_results[r], r);


			int nbins = 100;
			int nfiles=6; //number of the bins
			float xmin=-0.5,xmax=5; //Limits of the histogram

			TH1F *hist_spill_1[12];
			TH1F *hist_spill_2[12];
			TH1F *hist_spill_3[12];
			TH1F *hist_spill_4[12];
			TH1F *hist_spill_5[12];
			TH1F *hist_spill_6[12];
			char *histname = new char[15];
			char *histname2 = new char[15];
			char *histname3 = new char[15];
			char *histname4 = new char[15];
			char *histname5 = new char[15];
			char *histname6 = new char[15];

			char *label = new char[15];
			char *label2 = new char[15];
			char *file_label = new char[10];
			//char *energy_polarity_label= new char[10];
			char *label_canvas = new char[10];

			TCanvas *cs_stacked[100];



			//a is the number of files that you want to create 16 in this case
			int energy_value = 8 , polarity_value = -1;
			//char *energy_polarity_label[8];
			char *condition_entries = new char[100];

			int energy_t;
			int polarity_t;


			char *cond_histo1 = new char[60];
				char *cond_histo2 = new char[60];
				char *cond_histo3 = new char[60];
				char *cond_histo4 = new char[60];
				char *cond_histo5 = new char[60];
				char *cond_histo6 = new char[60];


				char *energy_polarity_label = new char[15] ;
				char *title_canvas = new char[40];
				int m,p;
				TString myfile_name8;


	for(int a = 0; a<super_limit-1 ; a++){

			 sprintf(cond_histo1,"Time_spill_1b != -404 && energyb ==%d && polarityb ==%d",aenergy[a],apolarity[a]);
			 sprintf(cond_histo2,"Time_spill_2b != -404 && energyb ==%d && polarityb ==%d",aenergy[a],apolarity[a]);
			 sprintf(cond_histo3,"Time_spill_3b != -404 && energyb ==%d && polarityb ==%d",aenergy[a],apolarity[a]);
			 sprintf(cond_histo4,"Time_spill_4b != -404 && energyb ==%d && polarityb ==%d",aenergy[a],apolarity[a]);
			 sprintf(cond_histo5,"Time_spill_5b != -404 && energyb ==%d && polarityb ==%d",aenergy[a],apolarity[a]);
			 sprintf(cond_histo6,"Time_spill_6b != -404 && energyb ==%d && polarityb ==%d",aenergy[a],apolarity[a]);

			  //				sprintf(file_label,"file_%d_",a);
				sprintf(histname,"hist_spill_1%d",a);
				sprintf(histname2,"hist_spill_2%d",a);
				sprintf(histname3,"hist_spill_3%d",a);
				sprintf(histname4,"hist_spill_4%d",a);
				sprintf(histname5,"hist_spill_5%d",a);
				sprintf(histname6,"hist_spill_6%d",a);

				sprintf(label_canvas, "cs_stacked_%d",a);


				hist_spill_1[a] = new TH1F(histname,"Spill #1",nbins,xmin,xmax);
				hist_spill_2[a] = new TH1F(histname2,"Spill #2",nbins,xmin,xmax);
				hist_spill_3[a] = new TH1F(histname3,"Spill #3",nbins,xmin,xmax);
				hist_spill_4[a] = new TH1F(histname4,"Spill #4",nbins,xmin,xmax);
				hist_spill_5[a] = new TH1F(histname5,"Spill #5",nbins,xmin,xmax);
				hist_spill_6[a] = new TH1F(histname6,"Spill #6",nbins,xmin,xmax);

				THStack *hs_spill_stack = new THStack("hs_spill_stack",""); //  Defining the THStack histogram
				// ====== Ploting the variables / Defining the histograms and attaching them into THStack  =========//
				 //1
				 tree_spill->Project(histname,"Time_spill_1b", cond_histo1);
				 hist_spill_1[a]->SetFillColor(kRed);
				 hs_spill_stack->Add(hist_spill_1[a]);
				 //2
				 tree_spill->Project(histname2,"Time_spill_2b", cond_histo2);
			   hist_spill_2[a]->SetFillColor(kBlue);
				 hs_spill_stack->Add(hist_spill_2[a]);
				 //3
				 tree_spill->Project(histname3,"Time_spill_3b", cond_histo3);
				 hist_spill_3[a]->SetFillColor(kYellow);
				 hs_spill_stack->Add(hist_spill_3[a]);
				 //4
				 tree_spill->Project(histname4,"Time_spill_4b", cond_histo4);

				 hist_spill_4[a]->SetFillColor(kGreen);
				 hs_spill_stack->Add(hist_spill_4[a]);
				 //5
				 tree_spill->Project(histname5,"Time_spill_5b", cond_histo5);
				 hist_spill_5[a]->SetFillColor(kOrange);
				 hs_spill_stack->Add(hist_spill_5[a]);
				 //6
				 tree_spill->Project(histname6,"Time_spill_6b", cond_histo6);
				 hist_spill_6[a]->SetFillColor(kBlack);
				 hs_spill_stack->Add(hist_spill_6[a]);

				 // ========= Defining the histograms and attaching them into THStack  =========//
				 if(recursive ==1){p=a;}
			 			else if(recursive ==2){p=a+20;}
			 			else if(recursive ==3){p=a+30;}
			 			else if(recursive ==4){p=a+40;}
			 			else if(recursive ==5){p=a+50;}
			 			else if(recursive ==6){p=a+60;}

				 cs_stacked[p] = new TCanvas(label_canvas,label_canvas,10,10,700,400);
				 TText T; T.SetTextFont(42); T.SetTextAlign(21);
				 cs_stacked[p]->Divide(1);
				 cs_stacked[p]->cd(1);

				 hs_spill_stack->Draw();
				 hs_spill_stack->GetXaxis()->SetTitle("Time (seconds)");
				 hs_spill_stack->GetYaxis()->SetTitle("Events/100");
				 hs_spill_stack->Draw();


				 Double_t xl1=.80, yl1=0.40, xl2=xl1+.15, yl2=yl1+.325; // Set the X Axis title, value, etc
				 // x position, y position, x ancho, y ancho
				 TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend
					 leg->SetHeader("Spill number");
					 leg->AddEntry(hist_spill_1[a],"#1","f");
					 leg->AddEntry(hist_spill_2[a],"#2","f");
					 leg->AddEntry(hist_spill_3[a],"#3","f");
					 leg->AddEntry(hist_spill_4[a],"#4","f");
					 leg->AddEntry(hist_spill_5[a],"#5","f");
					 leg->AddEntry(hist_spill_6[a],"#6","f");
					 leg->Draw();

					char *variable_stacked_spill = "StackedSpill_";

					m= aenergy[a]*apolarity[a];
					sprintf(energy_polarity_label, "Energy_%dGeV", m);
					myfile_name8=  root_path + variable_stacked_spill + "_"+ type_label +"_"+energy_polarity_label + ".gif";


					sprintf(title_canvas,"Time Profile for %dGeV Pions", m);
				 	T.DrawTextNDC(.5,.95,title_canvas);
					cs_stacked[p]->SaveAs(myfile_name8);

				} // end  for(int a = 0; a<super_limit-1 ; a++){


}



void TbTaTool::PlotOneVariableOnlyPolarity(int type_tree = 2, int file_resultado_analizar = 2 , char* variable1="mi_cycle", char* restriction_var ="mi_cycle != 0", char* label_hist_result1 = "MI's Frequency Spill", int nbins = 250, float xmin=60.2, float xmax=60.9, int recursive=1)
{

				//Open the file txt for becnhmarking
				//Open the root file
				char* file_name=name_file_results[file_resultado_analizar];
				TbTaToolAnalysis(0,file_name,type_tree);

				TString canvas_file_name;
				char *energy_polarity_label = new char[15] ;
				char *cond_histo1 = new char[80];
				char *histname = new char[20];

				TH1F *hist_result_[4];
				TCanvas *canvas_variable[10];

				char *label_canvas = new char[30];
				sprintf(label_canvas, "canvas_result_%s",variable1);
				int p;
				if(recursive ==1){p=recursive;}
		 			else if(recursive ==2){p=recursive;}
		 			else if(recursive ==3){p=recursive;}
		 			else if(recursive ==4){p=recursive;}
		 			else if(recursive ==5){p=recursive;}
		 			else if(recursive ==6){p=recursive;}

				canvas_variable[p] = new TCanvas("canvas_variable","canvas_variable",10,10,600,400);
				TText T; T.SetTextFont(42); T.SetTextAlign(21);
				char *title_canvas = new char[80];


				canvas_variable[p]->Divide(1);
				canvas_variable[p]->cd(1);
				sprintf(title_canvas,"%s for all energies  %s", label_hist_result1, char_type_label);

				for(int n=0; n<=2; n++)
				{
					if(n==0){
						sprintf(histname,"hist_result_%d",n); /////////////
						sprintf(cond_histo1," %s",restriction_var); ///////////7
						hist_result_[n] = new TH1F(histname,"",nbins,xmin,xmax);
						fChainA->Project(histname,variable1,cond_histo1);
					}
					else
					{
						sprintf(histname,"hist_result_%d",n); /////////////
						sprintf(cond_histo1," %s && polarityb ==%d",restriction_var,apolarity2[n]); ///////////7
						hist_result_[n] = new TH1F(histname,"",nbins,xmin,xmax);
						fChainA->Project(histname,variable1,cond_histo1);
					}

				}

				hist_result_[0]->GetXaxis()->SetTitle("MI Cycle");
				hist_result_[0]->SetTitle(title_canvas);
				gStyle->SetOptStat();
				hist_result_[0]->SetFillColor(kRed);
				hist_result_[0]->Draw();
				canvas_variable[p]->Update();


				hist_result_[1]->SetFillColor(kCyan);
				hist_result_[1]->Draw("SAMES");
				hist_result_[2]->SetFillColor(kBlue);
				hist_result_[2]->Draw("SAMES");

				Double_t xl1=.18, yl1=0.40, xl2=xl1+.2, yl2=yl1+.325; // Set the X Axis title, value, etc
				TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend

				leg->SetHeader("For differents energies");
				leg->AddEntry(hist_result_[0],"All energies","f");
				leg->AddEntry(hist_result_[1],"Pos","f");
				leg->AddEntry(hist_result_[2],"Neg","f");
				leg->Draw();

				char *condition_entries = new char[150]
				char *buffer_restriction = new char[100];


				sprintf(condition_entries,"%s && polarityb ==%d",variable1,apolarity2[n]);


				TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
					ptstats->SetName("stats");
					ptstats->SetBorderSize(1);
					ptstats->SetFillColor(0);
					ptstats->SetTextAlign(12);
					ptstats->SetTextFont(42);
					TText *text = ptstats->AddText("All energies");
					text->SetTextSize(0.0068);
					char *entries_label = new char[12];
					Double_t entries_run =  hist_result_[0]->GetEntries();
					sprintf(entries_label," Entries %d", entries_run);
					text = ptstats->AddText(entries_label);
					char *mean_label = new char[12];
					Float_t mean_run =  hist_result_[0]->GetMean();
					sprintf(mean_label," Mean %0.2f", mean_run);
					text = ptstats->AddText(mean_label);
					char *rms_label = new char[12];
					Float_t rms_run =  hist_result_[0]->GetRMS();
					sprintf(rms_label," RMS %0.3f", rms_run);
					text = ptstats->AddText(rms_label);
					ptstats->SetOptStat(1111);
					ptstats->SetOptFit(0);
				ptstats->Draw();


				canvas_file_name =  root_path + variable1 +"_"+ type_label+ "_"+ "Only_polarities_" + ".gif";

				//T.DrawTextNDC(.5,.95,title_canvas);
				canvas_variable[p]->SaveAs(canvas_file_name);


	}


void TbTaTool::PlotOneVariableAllEnergiesStacked(int type_tree=2, int file_resultado_analizar = 3 , char* variable1="mi_cycle", char* restriction_var ="mi_cycle != 0", char* label_hist_result1 = "MI's Frequency Spill", int nbins = 250, float xmin=60.2, float xmax=60.9, int recursive)
{

					TbTaToolAnalysis(0,name_file_results[file_resultado_analizar], type_tree);
					TH1F *hist_result_[20];
					char *cond_histo1 = new char[80];
					char *histname = new char[20];
					char *title_h = new char[80];
					char *labelYaxis = new char[60];
					char *title_canvas = new char[80];
					TCanvas *canvas_variable[10];
					int p;
					if(recursive ==1){p=recursive;}
						else if(recursive ==2){p=recursive;}
						else if(recursive ==3){p=recursive;}
						else if(recursive ==4){p=recursive;}
						else if(recursive ==5){p=recursive;}
						else if(recursive ==6){p=recursive;}

					canvas_variable[p] = new TCanvas("canvas_variable","canvas_variable",10,10,600,400);
					TText T; T.SetTextFont(42); T.SetTextAlign(21);
					canvas_variable[p]->Divide(1);
					canvas_variable[p]->cd(1);


					sprintf(labelYaxis,"Events/%d",nbins);

					for(int index_energy=0; index_energy < super_limit2; index_energy++)
					{
						cout << index_energy << "=" <<aenergy[index_energy]*apolarity[index_energy] <<"GeV ="<< endl;
						if(index_energy ==0)
						{
							sprintf(histname,"hist_result_%d",index_energy);
							sprintf(cond_histo1," %s",restriction_var); ///////////
							sprintf(title_h,"%s for all energies",label_hist_result1);
							hist_result_[index_energy] = new TH1F(histname,title_h,nbins,xmin,xmax);
							fChainA->Project(histname,variable1,cond_histo1);
							hist_result_[index_energy]->Draw();
							hist_result_[index_energy]->GetXaxis()->SetTitle("Time (seconds)");
							hist_result_[index_energy]->Draw();

						}
						else
						{
							sprintf(histname,"hist_result_%d",index_energy);
							sprintf(cond_histo1," %s && energyb ==%d",restriction_var,aenergy[index_energy]); ///////////
							sprintf(title_h,"%s for energies %dGeV",label_hist_result1, aenergy[index_energy]);
							hist_result_[index_energy] = new TH1F(histname,title_h,nbins,xmin,xmax);
							fChainA->Project(histname,variable1,cond_histo1);
						}
					}

						hist_result_[0]->Draw();
						hist_result_[0]->GetXaxis()->SetTitle("Time (seconds)");
						hist_result_[0]->Draw();
						hist_result_[0]->GetYaxis()->SetTitle(labelYaxis);
					  //hist_result->GetXaxis()->SetLimits(0, 5);
					  //hist_result_[0]->SetTitle("MI Cycle for Run 2 Pions");
					  //hist_result->SetMarkerColor(2);
					  //hist_result->SetMarkerStyle(2);
					  gStyle->SetOptStat();
					  hist_result_[0]->SetFillColor(kRed);
					  hist_result_[0]->Draw();
					  canvas_variable[p]->Update();


					  //Int_t ci3, ci4, ci5, ci6, ci7, ci8, ci9, ci10, ci11;   // for color index setting
					  //ci2 = TColor::GetColor(2);
					  //hist_numb_spill_pions_2->SetLineColor(ci2);
					  hist_result_[1]->SetFillColor(kCyan);
					  hist_result_[1]->Draw("SAMES");

					  //hist_numb_spill_pions_4->SetFillColor(kViolet);
					  //hist_spill_number_date_3->SetLineColor(ci4);
					  //ci4 = TColor::GetColor(4);
					  hist_result_[2]->SetFillColor(kBlue);
					  hist_result_[2]->Draw("SAMES");

					  //hist_numb_spill_pions_5->SetFillColor(kBlue);
					  //hist_spill_number_date_4->SetLineColor(ci5);
					  //ci5 = TColor::GetColor(5);

					  hist_result_[3]->SetFillColor(kYellow);
					  hist_result_[3]->Draw("SAMES");

					  //hist_numb_spill_pions_6->SetFillColor(kAzure);
					  //hist_spill_number_date_5->SetLineColor(ci6);
					  //ci6 = TColor::GetColor(7);

					  hist_result_[4]->SetFillColor(kOrange);
					  hist_result_[4]->Draw("SAMES");

					  //hist_numb_spill_pions_7->SetFillColor(kCyan);
					  //hist_spill_number_date_6->SetLineColor(ci7);
					  //ci7 = TColor::GetColor(8);
					  hist_result_[5]->SetFillColor(kGreen);
					  hist_result_[5]->Draw("SAMES");


					  hist_result_[6]->SetFillColor(kViolet);
					  hist_result_[6]->Draw("SAMES");



					 Double_t xl1=.18, yl1=0.40, xl2=xl1+.2, yl2=yl1+.325; // Set the X Axis title, value, etc
					 // x position, y position, x ancho, y ancho
					 TLegend *leg = new TLegend(xl1,yl1,xl2,yl2); // Legend
					 leg->SetHeader("For differents energies");
					 leg->AddEntry(hist_result_[0],"All energies","f");
					 leg->AddEntry(hist_result_[1],"8GeV","f");
					 leg->AddEntry(hist_result_[2],"6GeV","f");
					 leg->AddEntry(hist_result_[3],"4GeV","f");
					 leg->AddEntry(hist_result_[4],"9GeV","f");
					 leg->AddEntry(hist_result_[5],"10GeV","f");
					 leg->AddEntry(hist_result_[6],"16GeV","f");
					 leg->Draw();


							TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
							ptstats->SetName("stats");
							ptstats->SetBorderSize(1);
							ptstats->SetFillColor(0);
							ptstats->SetTextAlign(12);
							ptstats->SetTextFont(42);
							TText *text = ptstats->AddText("MI Cycle");
							text->SetTextSize(0.0068);
							char *entries_label = new char[12];
							Double_t entries_run =  hist_result_[0]->GetEntries();
							sprintf(entries_label," Entries %d", entries_run);
							text = ptstats->AddText(entries_label);
							char *mean_label = new char[12];
							Float_t mean_run =  hist_result_[0]->GetMean();
							sprintf(mean_label," Mean %0.2f", mean_run);
							text = ptstats->AddText(mean_label);
							char *rms_label = new char[12];
							Float_t rms_run =  hist_result_[0]->GetRMS();
							sprintf(rms_label," RMS %0.3f", rms_run);
							text = ptstats->AddText(rms_label);
							ptstats->SetOptStat(1111);
							ptstats->SetOptFit(0);
							ptstats->Draw();

							//T.DrawTextNDC(.5,.95,"Stacked Spill");

										if(file_resultado_analizar ==0)
										{
											canvas_file_name =  root_path + variable1 +"_"+ type_label+ "_"+ "All_energies_" + ".gif";
										}
										else if(file_resultado_analizar ==1)
										{
											canvas_file_name =  root_path + variable1 +"_kickoff_"+ type_label+ "_"+ "All_energies_" + ".gif";
										}
										else
										{
											canvas_file_name =  root_path + variable1 +"_"+ type_label+ "_"+ "All_energies_" + ".gif";
										}


										//T.DrawTextNDC(.5,.95,title_canvas);
										canvas_variable[p]->SaveAs(canvas_file_name);


		}



void TbTaTool::GetValuesHistograms(int type_tree =0 , int file_resultado_analizar=0, char* variable1="delta_time", char* restriction_var ="delta_time != 0" )
{


				//Open the file txt for becnhmarking
				//Open the root file
				char* file_name=name_file_results[file_resultado_analizar];
				TbTaToolAnalysis(0,file_name,type_tree);
			  //Limits of the histogram
			  //Creation of Histogram

				int m;
				//File with data
				char buffer [50];
				TString temp1 = "entries_excluded_cut_2.txt";
				char * myfile_name = root_path + variable1 +"_"+temp1 ;
				ofstream myfile (myfile_name, ios::out | ios::app);
				if (myfile.is_open());
				myfile <<"Values excluded by the cuts" << variable1 <<"with differents limits." << endl;


				char *condition_entries = new char[150];
				char *buffer_restriction = new char[100];

				int numero = 9;
				int k =0;
				Double_t limit_1, limit_2;

				while(numero == 9)
				{

					cout << "Insert the bottom limit: ";
					cin >> limit_1;
					cout << "Insert the upper limit: ";
					cin >> limit_2;
					sprintf(buffer_restriction,"%s && %s > %d && %s < %d",restriction_var, variable1, limit_1, variable1 ,limit_2);


					for(int n=0; n<super_limit-1;n++)
					{

						sprintf(condition_entries,"%s && %s && energyb ==%d && polarityb ==%d",variable1, buffer_restriction,aenergy[n],apolarity[n]);
						myfile << "E: " << aenergy[n]*apolarity[n] << "   ";
						myfile << fChainA->GetEntries(condition_entries) << endl;


					}

					cout <<  "Do you want to continue?, press 9: ";
					cin >> numero;
				}

				myfile <<"####"<< endl;

		}



void TbTaTool::VariableArrayInsideSubRun(char* name_file, TTree *tree, Long64_t nentries, Double_t timen, int value_number_spills, int SpillNumber=1, int r=0 )
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
									values_VariableArrayInsideSubRun[0] = Time - timen;
									//TimeBeginSpill_[y] == values_VariableArrayInsideSubRun[0] = Time - t_begin;;
									values_VariableArrayInsideSubRun[1] = 1;
									//DidTBeginWasCalculated == values_VariableArrayInsideSubRun[1]
									break ;
								}
							}
				}
				return values_VariableArrayInsideSubRun[r];
			}



void TbTaTool::GenerateDataPions()
{

		    TString labelTP ="_time_profile_spills.root";
			  char * name_results = root_path + type_label + labelTP;
			  TFile f_spill(name_results,"RECREATE");
			  TTree *tree_spill = new TTree("tree_spill","Tree Spill");

			  TBranch *b_Time_spill_1b = tree_spill->Branch("Time_spill_1b", &Time_spill_1b, "Time_spill_1b/D" );
			  TBranch *b_Time_spill_2b = tree_spill->Branch("Time_spill_2b", &Time_spill_2b, "Time_spill_2b/D" );
			  TBranch *b_Time_spill_3b = tree_spill->Branch("Time_spill_3b", &Time_spill_3b, "Time_spill_3b/D" );
			  TBranch *b_Time_spill_4b = tree_spill->Branch("Time_spill_4b", &Time_spill_4b, "Time_spill_4b/D" );
			  TBranch *b_Time_spill_5b = tree_spill->Branch("Time_spill_5b", &Time_spill_5b, "Time_spill_5b/D" );
			  TBranch *b_Time_spill_6b = tree_spill->Branch("Time_spill_6b", &Time_spill_6b, "Time_spill_6b/D" );
			  TBranch *b_Spill_numberb = tree_spill->Branch("Spill_numberb", &Spill_numberb, "Spill_numberb/I" );

			  TBranch *b_energyb = tree_spill->Branch("energyb", &energyb, "energyb/I" );
			  TBranch *b_polarityb = tree_spill->Branch("polarityb", &polarityb, "polarityb/I" );
				TBranch *b_file = tree_spill->Branch("file", &file, "file/I");

				TString labelSD ="spill_duration.root";
				char * name_file_global = root_path + type_label + labelSD;

				TFile f_global(name_file_global,"RECREATE");
				TTree *spill_global     = new TTree("spill_global","Spill Global");


				TBranch *b_duration_spill = spill_global->Branch("duration_spill", &duration_spill, "duration_spill/D" );
				TBranch *b_mi_cycle = spill_global->Branch("mi_cycle", &mi_cycle, "mi_cycle/D" );

				TBranch *b_energyb = spill_global->Branch("energyb", &energyb, "energyb/I" );
				TBranch *b_polarityb = spill_global->Branch("polarityb", &polarityb, "polarityb/I" );
				TBranch *b_file = spill_global->Branch("file", &file, "file/I");


				Double_t t_o_spill_absolute;
				Double_t temp ;


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
						file = i;

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


								cout << "."; 	t_o_spill_absolute = 0;

								code_spill_1 = - 404;				code_spill_2 = - 404;
								code_spill_3 = - 404;				code_spill_4 = - 404;
								code_spill_5 = - 404;				code_spill_6 = - 404;

							// = choose the absolute time considering the actual first spill that exist
							if( Time_begin_spill_1 != -404 ){ t_o_spill_absolute =  Time_begin_spill_1; code_spill_1 =100;  }
								else if( Time_begin_spill_2 != -404 ){ t_o_spill_absolute =  Time_begin_spill_2; code_spill_2 =100; }
								else if( Time_begin_spill_3 != -404 ){ t_o_spill_absolute =  Time_begin_spill_3; code_spill_3 =100; }
								else if( Time_begin_spill_4 != -404 ){ t_o_spill_absolute =  Time_begin_spill_4; code_spill_4 =100; }
								else if( Time_begin_spill_5 != -404 ){ t_o_spill_absolute =  Time_begin_spill_5; code_spill_5 =100; }
								else if( Time_begin_spill_6 != -404 ){ t_o_spill_absolute =  Time_begin_spill_6; code_spill_6 =100; }



							// = Loop for cutting the Spills
							if (fChain == 0) return;  Long64_t nentries = fChain->GetEntries(); Long64_t nbytes = 0, nb = 0;

						  for (Long64_t jentry=0; jentry<nentries;jentry++) // Time Profile Production
							{
						    Long64_t ientry = LoadTree(jentry);
						    //if (ientry < 0) break;
						    nb = fChain->GetEntry(jentry);   nbytes += nb;

								//Conditions for Spill has actual values

						    Time_spill_1b = -404; Time_spill_2b = -404; Time_spill_3b = -404;
						    Time_spill_4b = -404; Time_spill_5b = -404; Time_spill_6b = -404;


				      	if (In_spill > 0.5 )
								{
				          	if (Spill_number == 1 && exists_spill_1 != 0  )
										{

				                  Time_spill_1 = (Double_t) Time -t_begin[i];
				                	Time_spill_1b = (Double_t) Time  -t_o_spill_absolute - t_begin[i] ;
				                  Spill_numberb = 1;
				                  tree_spill->Fill();

				            }

				            else if (Spill_number == 2 && exists_spill_2 != 0 )
				            {

													if(code_spill_1 != -404 ){

													Time_spill_2= (Double_t) Time -t_begin[i];
				                  Time_spill_2b = (Double_t) Time - interval_between_spills*1 - t_begin[i] - t_o_spill_absolute;
													Spill_numberb = 2;
				                  tree_spill->Fill();

													}
													else{

														Time_spill_2= (Double_t) Time -t_begin[i];
					                  Time_spill_2b = (Double_t) Time - interval_between_spills*0 - t_begin[i] - t_o_spill_absolute;
					                  Spill_numberb = 2;
					                  tree_spill->Fill();
													}
				            }

				            else if (Spill_number == 3 && exists_spill_3 != 0 )
				            {
													if(code_spill_1 != -404){

														  Time_spill_3= (Double_t) Time -t_begin[i];
						                  Time_spill_3b = (Double_t) Time  - interval_between_spills*2 - t_begin[i] - t_o_spill_absolute;
						                  Spill_numberb = 3;
						                  tree_spill->Fill();
													}
													else if(code_spill_2 != -404){

														  Time_spill_3= (Double_t) Time -t_begin[i];
						                  Time_spill_3b = (Double_t) Time  - interval_between_spills*1 - t_begin[i]- t_o_spill_absolute;
															Spill_numberb = 3;
						                  tree_spill->Fill();

													}
													else{

														  Time_spill_3= (Double_t) Time -t_begin[i];
						                  Time_spill_3b = (Double_t) Time  - interval_between_spills*0 - t_begin[i]- t_o_spill_absolute;
						                  Spill_numberb = 3;
						                  tree_spill->Fill();
													}
				             }

					          else if (Spill_number == 4 && exists_spill_4 != 0 )
					          {

													 if(code_spill_1 != -404){

														    Time_spill_4= (Double_t) Time -t_begin[i];
							                  Time_spill_4b = (Double_t) Time - interval_between_spills*3 - t_begin[i] - t_o_spill_absolute;
							                  Spill_numberb = 4;
							                  tree_spill->Fill();
													 }
													 else if(code_spill_2 != -404){

														    Time_spill_4= (Double_t) Time -t_begin[i];
							                  Time_spill_4b = (Double_t) Time - interval_between_spills*2 - t_begin[i]- t_o_spill_absolute;
							                  Spill_numberb = 4;
							                  tree_spill->Fill();
													 }
													 else if(code_spill_3 != -404){

														    Time_spill_4= (Double_t) Time -t_begin[i];
							                  Time_spill_4b = (Double_t) Time - interval_between_spills*1 - t_begin[i]- t_o_spill_absolute;
							                  Spill_numberb = 4;
							                  tree_spill->Fill();
													 }
													 else{
														    Time_spill_4= (Double_t) Time -t_begin[i];
							                  Time_spill_4b = (Double_t) Time - interval_between_spills*0 - t_begin[i]- t_o_spill_absolute;
							                  Spill_numberb = 4;
							                  tree_spill->Fill();
													 }
					          	}

					          else if (Spill_number == 5 && exists_spill_5 != 0 )
					          {

													if(code_spill_1 != -404){

														  Time_spill_5= (Double_t) Time -t_begin[i];
							                Time_spill_5b = (Double_t) Time  - interval_between_spills*4 - t_begin[i]- t_o_spill_absolute;
							                Spill_numberb = 5;
							                tree_spill->Fill();
													}
													else if(code_spill_2 != -404){

														  Time_spill_5= (Double_t) Time -t_begin[i];
							                Time_spill_5b = (Double_t) Time  - interval_between_spills*3 - t_begin[i]- t_o_spill_absolute;
							                Spill_numberb = 5;
							                tree_spill->Fill();
													}
													else if(code_spill_3 != -404){
														  Time_spill_5= (Double_t) Time -t_begin[i];
							                Time_spill_5b = (Double_t) Time  - interval_between_spills*2 - t_begin[i]- t_o_spill_absolute;
							                Spill_numberb = 5;
							                tree_spill->Fill();

													}
													else if(code_spill_4 != -404){
														  Time_spill_5= (Double_t) Time -t_begin[i];
							                Time_spill_5b = (Double_t) Time  - interval_between_spills*1 - t_begin[i]- t_o_spill_absolute;
							                Spill_numberb = 5;
							                tree_spill->Fill();
													}
													else {

														  Time_spill_5= (Double_t) Time -t_begin[i];
							                Time_spill_5b = (Double_t) Time  - interval_between_spills*0 - t_begin[i]- t_o_spill_absolute;
							                Spill_numberb = 5;
							                tree_spill->Fill();
													}
					          }

		 			          else if (Spill_number == 6 && exists_spill_6 != 0 )
					          {


											 if(code_spill_1 != -404){
												 Time_spill_6= (Double_t) Time -t_begin[i];
					               Time_spill_6b = (Double_t) Time - interval_between_spills*5  - t_begin[i]- t_o_spill_absolute;
					               Spill_numberb = 6;
					               tree_spill->Fill();

											 }
											 else if(code_spill_2 != -404){
												 Time_spill_6= (Double_t) Time -t_begin[i];
					               Time_spill_6b = (Double_t) Time - interval_between_spills*4  - t_begin[i]- t_o_spill_absolute;
					               Spill_numberb = 6;
					               tree_spill->Fill();
											 }
											 else if(code_spill_3 != -404){

												 Time_spill_6= (Double_t) Time -t_begin[i];
					               Time_spill_6b = (Double_t) Time - interval_between_spills*3  - t_begin[i]- t_o_spill_absolute;
					               Spill_numberb = 6;
					               tree_spill->Fill();
											 }
											 else if(code_spill_4 != -404){

												 Time_spill_6= (Double_t) Time -t_begin[i];
					               Time_spill_6b = (Double_t) Time - interval_between_spills*2  - t_begin[i]- t_o_spill_absolute;
					               Spill_numberb = 6;
					               tree_spill->Fill();
											 }
											 else if(code_spill_5 != -404){

												 Time_spill_6= (Double_t) Time -t_begin[i];
					               Time_spill_6b = (Double_t) Time - interval_between_spills*1  - t_begin[i]- t_o_spill_absolute;
					               Spill_numberb = 6;
					               tree_spill->Fill();
											 }
											 else {

												 Time_spill_6= (Double_t) Time -t_begin[i];
					               Time_spill_6b = (Double_t) Time - interval_between_spills*0  - t_begin[i]- t_o_spill_absolute;
					               Spill_numberb = 6;
					               tree_spill->Fill();

											 }
										} //else if (Spill_number == 6 && exists_spill_6 != 0 )

								 } // end of:  if (In_spill > 0.5 )

					 	}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)




										//==================================

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
												 }
												 else if (Spill_number == 2 )
												 {
															 Time_spill_2= (Double_t) Time -t_begin[i];
															 duration_spill_2 = Time_spill_2 - Time_begin_spill_2;
												 }

												 else if (Spill_number == 3  )
												 {
															 Time_spill_3= (Double_t) Time -t_begin[i];
															 duration_spill_3 = Time_spill_3 - Time_begin_spill_3;
													}

												else if (Spill_number == 4  )
												{
															Time_spill_4= (Double_t) Time -t_begin[i];
															duration_spill_4 = Time_spill_4 - Time_begin_spill_4;
												 }

												 else if (Spill_number == 5  )
												 {
														 Time_spill_5= (Double_t) Time -t_begin[i];
														 duration_spill_5 = Time_spill_5 - Time_begin_spill_5;
												 }

												else if (Spill_number == 6  )
												{
														Time_spill_6= (Double_t) Time -t_begin[i];
														duration_spill_6 = Time_spill_6 - Time_begin_spill_6;
												}

										 } // end of:  if (In_spill > 0.5 )
										}//end of: for (Long64_t jentry=0; jentry<nentries;jentry++)


										//=================================

										// ## 1

									  duration_spill =  duration_spill_1;
									  //category = 1;
									  mi_cycle = 0;
										//myfile << mi_cycle << endl;
										//myfile4 << duration_spill << endl;
									  spill_global->Fill();

										// ## 2

										if(signal1_t_begin_spill_1 == 1 && signal1_t_begin_spill_2 == 1){

											  duration_spill =  duration_spill_2;
											  mi_cycle = t_o_spill_2 - t_o_spill_1;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}
										else {

											  duration_spill =  duration_spill_2;
											  mi_cycle = 0;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}
										// ## 3

										if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_2 == 1){

											  duration_spill =  duration_spill_3;
											  mi_cycle = t_o_spill_3 - t_o_spill_2;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}
										else {

											  duration_spill =  duration_spill_3;
											  mi_cycle = 0;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}

									  // ## 4
										if(signal1_t_begin_spill_3 == 1 && signal1_t_begin_spill_4 == 1){

											  duration_spill =  duration_spill_4;
											  mi_cycle =  t_o_spill_4 - t_o_spill_3;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}
										else {

												duration_spill =  duration_spill_4;
											  mi_cycle = 0;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}
									  // ## 5

										if(signal1_t_begin_spill_4 == 1 && signal1_t_begin_spill_5 == 1){

											  duration_spill =  duration_spill_5;
											  mi_cycle = t_o_spill_5 - t_o_spill_4;
											  //category = 1;
											  //myfile << mi_cycle << endl;
												//myfile4 << duration_spill << endl;
											  spill_global->Fill();

										}
										else {

										  duration_spill =  duration_spill_5;
										  mi_cycle = 0 ;
										  //category = 1;
										  //myfile << mi_cycle << endl;
											//myfile4 << duration_spill << endl;
										  spill_global->Fill();

										}
									  // ## 6

										if(signal1_t_begin_spill_6 == 1 && signal1_t_begin_spill_5 == 1){

										  duration_spill =  duration_spill_6;
										  mi_cycle = t_o_spill_6 - t_o_spill_5;
										  //category = 1;
										  //myfile << mi_cycle << endl;
											//myfile4 << duration_spill << endl;
										  spill_global->Fill();

										}
										else {

										  duration_spill =  duration_spill_6;
										  mi_cycle = 0;
										  //category = 1;
										  //myfile << mi_cycle << endl;
											//myfile4 << duration_spill << endl;
										  spill_global->Fill();

										}


					}  // End For the ROOT files Energy


				} // end For for all the indexes


			f_spill.Write();
			f_global.Write();


		}


void TbTaTool::Main()
{

	//1. set the  values of

	//TString root_path="/home/gsalazarq/Dropbox/min_conocimiento/e45.MINERvA/tools/final_tools/TbTaTool/ThesisVersionTool/Results_Pions/";
	//TString type_label = "PionsRun2";
	//char*  char_type_label = "Pions (Run2)";
	//const int super_limit = 12; //the numbes of entries in the arrays of energy and polarity
	//const int super_limit2 = 7; //the numbes of entries in the arrays of energy and polarity
	//const int value_number_spills = 6; //the numbes of entries in the arrays of energy and polarity
	//const Double_t ref_e39 = 1429819209.67;
	//const Double_t ref_tb = 1429820288.47;
	//const int super_limit = 12; //the numbes of entries in the arrays of energy and polarity

	//2.Set the path of the files in name_file[1000] = //Good paths for pions or electrons

	//3.Create the tbegin in order to get the interval of the e39 timestamp

	//BeginTimeForRun(aindex[0],aindex[super_limit-1],0);
	//BeginTimeForRun(aindex[0],aindex[super_limit-1],1);
	int numero = 0;
	cout << "Is the e39 data already loaded in the TbTaTool_files.h? if yes? press 1; otherwise 0." << endl;
	cin >> numero;
	if( numero == 1)
	{
			//4.Generate time interval analysis
			//GenerateMatchedTimesAnalysis(0);  //considering tbegin as the beginning of the root
			//GenerateMatchedTimesAnalysis(1);  //considering tbegin as the kickoff of the run

			//5. Plotting the Delta_time
			/*int i_bin, i_min, i_max;
			cout << "Introduce numbers of bin: ";
			cin >> i_bin;
			cout << "\n Introduce min range: ";
			cin >> i_min;
			cout << "\nIntroduce max range: ";
			cin >> i_max;*/
			/*
			int i_bin = 250;
			char restriction_var1[30];
			sprintf(restriction_var1,"delta_time != %d", i_bin);
			GetValuesHistograms(0,0,"delta_time",restriction_var1);]
			*/

			PlotOneVariableOverAllEnergies(0,0,"delta_time","delta_time != 0","Time between e39 and tbegin subrun",250,0,100,1);
			PlotOneVariableAllEnergiesStacked(0,0,"delta_time","delta_time!= 0", "Time between e39 and tbegin subrun", 250,0,100,1);
			/*int i_bin, i_min, i_max;
			cout << "Introduce numbers of bin: ";
			cin >> i_bin;
			cout << "\n Introduce min range: ";
			cin >> i_min;
			cout << "\nIntroduce max range: ";
			cin >> i_max;*/

			PlotOneVariableOverAllEnergies(0,1,"delta_time","delta_time != 0","Time between e39 and kickoff subrun",250,0,1,2);
			PlotOneVariableAllEnergiesStacked(0,1,"delta_time","delta_time != 0","Time between e39 and kickoff subrun",250,0,1,2);

			//GetValuesHistograms("delta_time","delta_time != 0",0);
			//PlotOneVariableOverAllEnergies(1,"delta_time","delta_time != 0","Time between e39 and tbegin",100,0,200);

			//Look into the txt files produced
			//TString variable1 = "tbegin_spill.txt";
			//TString variable1 = "kick_off_spill.txt";

			//4. Make the conversion for the e39times values
			//put the values in Double_t e39times[10000] considering the best option (beginning and kickoff)

			//Generate Time Profile and Spill Duration
			//GenerateDataPions()

			//

	}
	else if()
	{
		cout << "This is the end ... my friend ... the end ..." << endl;
		break;
	}

}
