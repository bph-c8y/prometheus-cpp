#include "prometheus/counter.h"

namespace prometheus {

void Counter::Increment() { gauge_.Increment(); }

void Counter::Increment(const double val) {
  if (val < 0.0) {
    return;
  }
  gauge_.Increment(val);
}

double Counter::Value() const { return gauge_.Value(); }

void Counter::Set(double val) { if ( val > Value()) gauge_.Set(val); }

ClientMetric Counter::Collect() const {
  ClientMetric metric;
  metric.counter.value = Value();
  return metric;
}

}  // namespace prometheus
