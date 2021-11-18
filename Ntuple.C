#include <TTree.h>
#include <TNtuple.h>
#include <random>

void Ntuple() {
    TNtuple *n = new TNtuple("n","gauss vs poisson","a:b:c");

    std::default_random_engine generator;
    std::normal_distribution<double> distribution_gau(2.0,1.0);
    std::poisson_distribution<int> distribution_poi(3.0);
    std::exponential_distribution<double> distribution_exp(3.0);

    for (int i=0; i<10000; ++i) {
        n->Fill(distribution_gau(generator), distribution_poi(generator), distribution_exp(generator));
    }
    n->Draw("a:b","c<3");
}
