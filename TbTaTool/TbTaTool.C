#define TbTaTool_cxx
#include "TbTaTool.h"
#include "TbTaTool_files.h"
//#include "TbTaTool_files.h"
//#include "Aux_TbTaTool.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

const int super_limit = 12; //the numbes of entries in the arrays of energy and polarity
Double_t TbTaTool::NumberEventsInSpill(char* file_name, int value_NumberSpills=0, int r) //fully works
{

	char *condition_entry = new char[40];
	Double_t values_NumberEventsInSpill[6];

	for(int j=0; j<value_NumberSpills+1; j++){
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



void TbTaTool::PlotVariableOneEnergy(int n=0, char* variable1="delta_time", char* restriction_var ="delta_time != 0", int nbins = 100, float xmin=0, float xmax=200){

	//Open the file txt for becnhmarking
	//Open the root file
	char* file_name="/home/gsalazarq/Dropbox/min_conocimiento/e45.MINERvA/tools/final_tools/TbTaTool/ThesisVersionTool/Results_Pions/PionsRun2analysis_tbegin_and_e39.root";
	TbTaToolAnalysis(0,file_name);
  //Limits of the histogram

  //Creation of Histogram
	TH1F *hist_result1[12];

	//TCanvas


	//	for(int n=5; n<6;n++)
		//{


		//TCanvas *cs_stacked[15];
		char *label_canvas = new char[20];
		char *title_canvas = new char[12];

		sprintf(label_canvas, "canvas_result_%d",n);
		TCanvas *canvas_result = new TCanvas("canvas_result","canvas_result",10,10,600,400);
		TText T; T.SetTextFont(42); T.SetTextAlign(21);
		canvas_result->Divide(1);
		canvas_result->cd(1);

		//Project and plot. histname is the name of the histogram
		char *labelYaxis = new char[60];
		sprintf(labelYaxis,"Events/%d",nbins);


		//canvas_result[k]->Update();


		int m;
		m = aenergy[n]*apolarity[n];
		char *cond_histo1 = new char[80];
		sprintf(cond_histo1," %s && energyb ==%d && polarityb ==%d",restriction_var,aenergy[n],apolarity[n]);

		char *histname = new char[20];
		sprintf(histname,"hist_result1%d",n);
		char* label_hist_result1="Interval e39-tbegin Run2";
		hist_result1[n] = new TH1F(histname,label_hist_result1,nbins,xmin,xmax);
		//Condition
		cout << "Asi nomas joven" << endl;
		fChainA->Project(histname,variable1,cond_histo1);
		hist_result1[n]->Draw();
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
		canvas_result->SaveAs(canvas_file_name);

		//File with data
		char buffer [50];
		TString temp1 = "entries_excluded_cut.txt";
		char * myfile_name = root_path + variable1 +"_"+temp1 ;
		ofstream myfile (myfile_name, ios::out | ios::app);
		if (myfile.is_open());
		myfile <<"Values excluded by the cut in the xmax of the histogram" << endl;
		myfile <<"xmax = " << xmax << endl;


		char *condition_entries = new char[150];
		char *buffer_restriction = new char[100];
		sprintf(buffer_restriction,"%s && %s >%d",restriction_var, variable1,xmax);
		sprintf(condition_entries,"%s && %s && energyb ==%d && polarityb ==%d",variable1, buffer_restriction,aenergy[n],apolarity[n]);
		myfile << fChainA->GetEntries(condition_entries) << endl;
		myfile <<"####"<< endl;
//}

}

/*
void TbTaTool::PlotVariableAllEnergy(char* variable1="delta_time", char* restriction_var ="delta_time != 0" , char* label_hist_result1="Interval e39-tbegin", int nbins = 100, float xmin=0, float xmax=200)
{





}
*/
