
void AnalyzeSpill::PlotAll() //Plot the 6 spills (only is useful if the limits are 0-8)
{


  AnalyzeSpill temp;
  temp.AnalyzeSpillForRead();

        // ========================== Defining the histograms  =================//

        TCanvas *canvas_spill = new TCanvas("canvas_spill","Run 1514 SR 2",10,10,1000,800);
        canvas_spill->Divide(2,3);

        // ========================== Some features variables =================//

          // Set the X Axis title, value, etc
          Int_t ci;   // for color index setting
          ci = TColor::GetColor("#000099");

          //number of the bins
          cout << "Value of the bin?" << endl;
          Float_t nbins = temp.EnterValue();


        TH1F *hist_spill = new TH1F("hist_spill","Spill (R:1514 S:2) ",100,0.0,370);
        TH1F *hist_spill_[10];

        char *histname = new char[15];
        char *histname_label = new char[20];
        char *histname_projecting = new char[12];
        char *histname_condition = new char[16];
        char *file_name = new char[45] ;
        sprintf(file_name,"run1514_sr2_all_spills_loop_bin_%d.gif",nbins);



        int nfiles=6;
        //Limits of the histogram
        float xmin=-1.0,xmax=8.0;

        for (int i=0;i<nfiles;i++) {

          //definition
          sprintf(histname,"hist_spill_%d",i+1);
          sprintf(histname_label,"R:1JAJAJAJA514 S:2 Spill #%d",i+1);
          sprintf(histname_projecting,"Time_spill_%d",i+1);
          sprintf(histname_condition,"Time_spill_%d!=-1",i+1);
          cout << i << endl;
          // Here the Loop for Defining


          hist_spill_[i+1] = new TH1F(histname,histname_label,nbins,xmin,xmax);

          //Axis name
          hist_spill_[i+1]->GetXaxis()->SetTitle("Time (seconds)");

          //projecting the variables
          tree_spill->Project(histname,histname_projecting, histname_condition);

          //Plot
          canvas_spill->cd(i+1);
          hist_spill_[i+1]->Draw();

        }

        canvas_spill->SaveAs(file_name);

          //Printing the min and max values of the histograms

        /*  cout << "\n Min value of Spill 1" <<  hist_spill_1->GetXaxis()->GetXmin() << endl;
          cout << "\n Max value of Spill 1 \n" <<  hist_spill_1->GetXaxis()->GetXmax() << endl;

          TAxis *xaxis = hist_spill_1->GetXaxis();
          Double_t binCenter_0 = xaxis->GetBinCenter(0);
          Double_t binCenter_1 = xaxis->GetBinCenter(1);

          cout << "\n Get Bin Center bin underflow  " <<  binCenter_0 << endl;
          cout << "\n Get Bin Center bin first bin with low edge  " <<  binCenter_2 << endl;*/

}
