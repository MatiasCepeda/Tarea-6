#include <TH1F.h>
#include <TF1.h>
#include <TMath.h>
#include <TH1.h>
#include <TRandom.h>

void histogram ()
{
    TF1 *f1 = new TF1("f1","0.3+0.2*x+0.05*pow(x,2)+TMath::Gaus(4.2,3,1.8)",0,50);
    TF1 *f2 = new TF1("f2","[0]+[1]*x+[2]*pow(x,2)+TMath::Gaus(4.2,3,1.8)",0,50);

    TH1F *h = new TH1F("h","Histograma",50,0,50);

    for (Int_t i=0;i<15000;i++) {
        double c = f1->GetRandom();
        //std::cout << "Numero random: " << c << std::endl;
        h->Fill(c);
    }

    h->Fit(f2);
    h->Draw();

    std::cout << "Chi cuadrado: " << f2->GetChisquare() << std::endl;
    std::cout << "Grados de libertad: " << f2->GetNDF() << std::endl;
}
