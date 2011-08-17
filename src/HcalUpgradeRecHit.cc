#include "DataFormats/HcalRecHit/interface/HcalUpgradeRecHit.h"


HcalUpgradeRecHit::HcalUpgradeRecHit() : CaloRecHit() {
}

HcalUpgradeRecHit::HcalUpgradeRecHit(const HcalDetId& id, float energy, float timeRising, float timeFalling) :
  CaloRecHit(id,energy,timeRising),
  timeFalling_(timeFalling) 
{
}

std::ostream& operator<<(std::ostream& s, const HcalUpgradeRecHit& hit) {
  return s << hit.id() << ": " << hit.energy() << " GeV, " << hit.time() << "-'" << hit.timeFalling() << " ns";
}

