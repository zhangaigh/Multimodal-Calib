#ifndef METRIC_H
#define METRIC_H

#include "common.h"
#include "Scan.h"
#include "trace.h"
#include "Kernel.h"
#include <curand.h>

//! Depth of GOM images as need both phase and magnitude
#define GOM_DEPTH 2 

//! Metric to use when comparing two scans
class Metric {
public:
	//! Evalutaes two scans A and B to give a measure of their match strength
	virtual float EvalMetric(SparseScan* A, SparseScan* B);
};

//! Evaluates scans using the MI metric
class MI: public Metric {
public:
	//! Sets up metric, note for MI due to implementation number of bins must be less then 64
	MI(size_t numBins);
	//! Evaluates MI for two scans and gives result
	float EvalMetric(SparseScan* A, SparseScan* B);
private:
	//! Number of bins to use when calculating MI
	const size_t bins_;
};

//! Evaluate scans using the GOM metric
class GOM: public Metric {
public:
	//! Basic setup
	GOM(void);
	//! Evaluates GOM for two scans and gives result
	float EvalMetric(SparseScan* A, SparseScan* B);
};

//! Evaluates two scans using the Levinson method
class LIV: public Metric {
public:
	//! Setup assumes image averaging done on matlab side
	LIV();
	//! Evaluates Levinson method for two scans and gives result
	float EvalMetric(SparseScan* A, SparseScan* B);
};

//! Evaluates scans using a new experimental metric
class TEST: public Metric {
public:
	//! Sets up metric
	TEST(void);
	//! Evaluates test metric for two scans and gives result
	float EvalMetric(SparseScan* A, SparseScan* B);
};

#endif //METRIC_H