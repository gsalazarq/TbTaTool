#define TbTaTool_cxx
#include "TbTaTool.h"
#include "TbTaTool_files.h"
//#include "Aux_TbTaTool.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
TString root_path="/home/chasky/Dropbox/min_conocimiento/e45.MINERvA/tools/final_tools/TbTaTool/ThesisVersionTool/";

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
	//ejemplo file_inicial debe ser el primer valor del file q vamos a trabajar
	//ejemplo file_end será el q no se tomará en cuenta
	//seguir el usual

	TFile *f[10000];
	TTree *tree[10000];
	Double_t t_begin[100000];
	Double_t value_NumberEventsInSpillForRun[10000];

	for(int i=file_inicial; i<file_end; i++)
	{
		TbTaToolRun(name_file_electrons[i],i);
		for(int k=1; k<7; k++)
			{
				cout<< i << "#entradas: "<< NumberEventsInSpill(name_file_electrons[i], 6, k)<< endl;
			}
	}

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


Double_t TbTaTool::BeginTimeOneSubRun(char* file_name ) //fully works
{
	Double_t t_begin = -404;
  Long64_t nbytes = 0, nb = 0;

	 for (Long64_t jentry=0; jentry<1;jentry++) //Loop only the first event
	 {
				Long64_t ientry = LoadTree(jentry); if (ientry < 0) break;
				nb = fChain->GetEntry(jentry);   nbytes += nb; t_begin = (Double_t) Time;
	 }

	 return t_begin;
}

void TbTaTool::BeginTimeForRun(int i_begin, int i_final) //fullyworks
{
	TString variable1 = "tbegin_spill_electrons.txt";
	char * myfile_name =root_path+ variable1 ;
	ofstream myfile (myfile_name, ios::out | ios::app);
	if (myfile.is_open());

	TFile *f[10000];
	TTree *tree[10000];
	Double_t t_begin[100000];

	myfile <<"Unixtime outside of the first event in the spill" << endl;


	for(int i=i_begin; i<i_final ; i++) //i number of files
	{
		TbTaToolRun(name_file_electrons[i],i);
		cout << i <<"." ;
		t_begin[i]=BeginTimeOneSubRun(name_file_electrons[i]);
		myfile << t_begin[i]  - 1435919900 << endl;
	}
 	myfile << "End file" << endl;

}
