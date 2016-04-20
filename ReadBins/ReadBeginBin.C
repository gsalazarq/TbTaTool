
read_begin_end_bin(){


        TFile *f_spill = TFile::Open("/minerva/app/users/gsalazar/cmtuser/Minerva_v10r8p1/e45.MINERvA/tool_tb/tb2_data/8GeV_Pos_Pions/result_spill_run1514_sr2_num_spill_0-6.root");
        TTree *tree_spill=(TTree*)f_spill->Get("tree_spill");


        TH1F *hist_spill_1 = new TH1F("hist_spill_1","Spill (R:1514 S:2) ",100,0.0,370);
        float xmin=0.0,xmax=8.0;
        int nbins = 100;

        char histname="hist_spill_1";
        char histname_label="R 1513 S 2 Spill 1";
        char histname_projecting= "Time_spill_1";
        char histname_condition= "Time_spill_1 != -1";

       hist_spill_1 = new TH1F(histname,histname_label,nbins,xmin,xmax);
       tree_spill->Project(histname,histname_projecting, histname_condition);
       hist_spill_1->Draw();



/*        Float_t *bins = new Float[hist_spill.GetSize()]

        float lower_limit, upper_limit;
        lower_limit =
              tree_spill->GetBinCenter(tree_spill->FindFirstBinAbove(0,1));
        upper_limit =
              tree_spill->GetBinCenter(tree_spill->FindLastBinAbove(0,1));


          cout << "Lower limit: \n" << lower_limit << endl;
          cout << "Upper limit: \n" << upper_limit << endl;
*/

}
