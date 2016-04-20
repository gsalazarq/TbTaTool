


Float_t x ;
  cout << "Please enter an integer value: ";
  cin >> x;
  cout << "The value you entered is " << x <<endl;

//FindBin
cout<< "\n Using FindBin()  "<< endl;
Float_t bin_x = hist_spill_1->GetXaxis()->FindBin(x) ;
cout<< "The bin number corresponding to the value  "<< x << " is bin n_{i} =  "<<  bin_x << endl;

cout<< "\n Using GetBin()  "<< endl;
cout<< "The global bin number corresponding to the bin "<<  bin_x  << " is = " << hist_spill_1->GetBin(x) << endl;

//GetBinContent
cout<< "\n Using GetBinContent()  "<< endl;
Float_t bin_i = hist_spill_1->FindFirstBinAbove(0,1);
cout << "First Bin Above is: " <<  bin_i  << endl;
cout << "The number of events in the bin "<<  bin_i << " is: " <<  hist_spill_1->GetBinContent(bin_i ) << endl;


//GetBinCenter
cout<< "\n Using GetBinCenter()  "<< endl;
cout << "First Bin Above is: " <<  bin_i  << endl;
Float_t x_c = hist_spill_1->GetXaxis()->GetBinCenter(bin_i);
cout << "The value that correspond to the bin " <<  bin_i  << " is x:" << x_c << endl;

//getbinlowedge

cout<< "\n Using GetBinLowEdge()  "<< endl;
cout << "The first bin above is: " <<  bin_i  << endl;
Float_t x_l= hist_spill_1->GetXaxis()->GetBinLowEdge(bin_i);
cout << "The lower value for this bin is "<<  x_l<< endl;


//getbinupedge
cout<< "\n Using GetBinUpEdge()  "<< endl;
Float_t x_u= hist_spill_1->GetXaxis()->GetBinUpEdge(bin_i);
cout << "The upper value for this bin is "<<  x_u << endl;

//GetMaximumBin
cout<< "\n Using GetMaximunBin()  "<< endl;
cout<< "The bin with the maximun values is  "<< endl;

//GetMaximumBin
cout<< "\n Using GetMinimunBin()  "<< endl;
