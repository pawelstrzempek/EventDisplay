{

TCanvas *can = new TCanvas("c1","c1", 800,800);
TStrawMap *SS1 = new TStrawMap(16,2);
SS1->MarkStraw(8);
SS1->Draw(0.05,0.05);

TStrawMap *SS2 = new TStrawMap(16,2);
SS2->Draw(0.05,0.30);

TStrawMap *SS3 = new TStrawMap(16,2);
SS3->Draw(0.05,0.60);
}
