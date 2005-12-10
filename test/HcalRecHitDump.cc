#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "FWCore/Framework/interface/Selector.h"
#include <iostream>

using namespace std;

namespace cms {

  /** \class HcalRecHitDump
      
  $Date: 2005/08/04 18:14:50 $
  $Revision: 1.1 $
  \author J. Mans - Minnesota
  */
  class HcalRecHitDump : public edm::EDAnalyzer {
  public:
    explicit HcalRecHitDump(edm::ParameterSet const& conf);
    virtual void analyze(edm::Event const& e, edm::EventSetup const& c);
  };

  HcalRecHitDump::HcalRecHitDump(edm::ParameterSet const& conf) {
  }
  
  void HcalRecHitDump::analyze(edm::Event const& e, edm::EventSetup const& c) {
    std::vector<edm::Handle<HBHERecHitCollection> > hbhe;
    std::vector<edm::Handle<HORecHitCollection> > ho;
    std::vector<edm::Handle<HFRecHitCollection> > hf;
    
    try {
      e.getManyByType(hbhe);
      std::vector<edm::Handle<HBHERecHitCollection> >::iterator i;
      for (i=hbhe.begin(); i!=hbhe.end(); i++) {
	const HBHERecHitCollection& c=*(*i);
	
	for (HBHERecHitCollection::const_iterator j=c.begin(); j!=c.end(); j++) 
	  cout << *j << std::endl;
      }
    } catch (...) {
      cout << "No HB/HE RecHits." << endl;
    }
    
    try {
      e.getManyByType(hf);
      std::vector<edm::Handle<HFRecHitCollection> >::iterator i;
      for (i=hf.begin(); i!=hf.end(); i++) {
	const HFRecHitCollection& c=*(*i);
	
	for (HFRecHitCollection::const_iterator j=c.begin(); j!=c.end(); j++) 
	  cout << *j << std::endl;
      }
    } catch (...) {
      cout << "No HF RecHits." << endl;
    }
    
    try {
      e.getManyByType(ho);
      std::vector<edm::Handle<HORecHitCollection> >::iterator i;
      for (i=ho.begin(); i!=ho.end(); i++) {
	const HORecHitCollection& c=*(*i);
	
	for (HORecHitCollection::const_iterator j=c.begin(); j!=c.end(); j++) 
	  cout << *j << std::endl;
      }
    } catch (...) {
      cout << "No HO RecHits." << endl;
    }

    cout << endl;    
  }
}

#include "PluginManager/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

using namespace cms;

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(HcalRecHitDump)
